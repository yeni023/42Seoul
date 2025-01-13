#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// data.csv 유효성 검증
bool BitcoinExchange::isValidDate(std::string date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::string yearStr = date.substr(0, 4); //0번째 문자열부터 4개 year에 넣기
    std::string monthStr = date.substr(5, 2); //5번째 문자열부터 2개 month에 넣기
    std::string dayStr = date.substr(8, 2); //8번째 문자열부터 2개 day에 넣기

    // 연-월-일 숫자로 구성되어 있는지 검증
    for (int i = 0; i < 4; i++) {
        if (!std::isdigit(yearStr[i])) {
            return false;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (!std::isdigit(monthStr[i]) || !std::isdigit(dayStr[i])) {
            return false;
        }
    }

    // 윤년 처리
    std::tm inputTime = {};
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    inputTime.tm_year = year - 1900; // tm_year는 연도를 표현할 때 1900년을 시작으로해서
    inputTime.tm_mon = month - 1; // tm_mon는 0~11의 값 출력
    inputTime.tm_mday = day;

    std::time_t convertedTime = std::mktime(&inputTime);
    std::tm *outputTime = std::localtime(&convertedTime);

    return (year - 1900) == outputTime->tm_year &&
           (month - 1) == outputTime->tm_mon &&
           (day) == outputTime->tm_mday;
}

// data.csv 파일을 열어서 _exchangeRates 맵에 날짜와 환율 데이터 저장
void BitcoinExchange::loadExchangeRates(std::string data) {
    std::ifstream dataBase(data.c_str()); // ifstream : 데이터 파일을 읽기 전용으로 열기

    if (!dataBase.is_open())
        throw std::runtime_error("Error: Data file not found");
    
    std::string line;
    std::getline(dataBase, line);
    // 형식 검증
    if (line != "date,exchange_rate")
        throw std::runtime_error("Invalid file format");
    //  dateKey(날짜)-priceValue(환율)로 분리
    while (std::getline(dataBase, line)) {
        if (line.find(',') == std::string::npos)
            throw std::runtime_error("Invalid data file format");
        std::string dateKey = line.substr(0, line.find(','));
        std::string priceValue = line.substr(line.find(',') + 1);
        // 파일 데이터의 형식이 올바른지 췤 (, 2개 존재하는지)
        // npos -> 찾는 문자열이 없을 때 반환
        if (line.find(',', line.find(',') + 1) != std::string::npos)
            throw std::runtime_error("Invalid data file format");
        if (!isValidDate(dateKey))
            throw std::runtime_error("Invalid date format in data file");
        char *end = NULL; // 초기화
        float price = std::strtof(priceValue.c_str(), &end); // strtof: 문자열 -> 부동소수점 변환해서 &end에 저장
        if (*end != '\0' || errno == ERANGE) //errono == ERANGE (오버플로우 감지)
            throw std::runtime_error("Invalid price format");
        _exchangeRates.insert(std::make_pair(dateKey, price));
    }
    dataBase.close();
}

void BitcoinExchange::exchange(std::string input) {
    std::fstream inputFile(input.c_str());

    if (!inputFile.is_open()) {
        printError("could not open file.");
        return ;
    }
    std::string line;
    std::getline(inputFile, line);
    // 첫 번째 줄 헤더 확인
    if (line != "date | value") {
        printError("invalid file format");
        return ;
    }
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line); // 입력 문자열을 공백으로 구분하여 데이터 추출
        std::string data;
        int index = 0;
        std::string date;
        float value;
        // 각 줄을 공백으로 구분하여 데이터 분리
        while (std::getline(lineStream, data, ' ')) {
            if (index == 0) {
                if (!isValidDate(data)) {
                    printError("bad input => " + data);
                    break ;
                }
                date = data;
            }
            else if (index == 1) {
                if (data != "|")
                {
                    printError("wrong separator(date | value)");
                    break ;
                }
            }
            else if (index == 2) {
                if (data == "") {
                    printError("no value");
                    break ;
                }
                char *end = NULL;
                // value 변수에 문자열 데이터를 부동소수점(float) 값을 변환
                value = std::strtof(data.c_str(), &end);
                if (*end != '\0' || errno == ERANGE) {
                    printError("not a float number");
                    break ;
                }
                if (value < 0) {
                    printError("not a positive number");
                    break ;
                }
                if (value > 1000) {
                    printError("too large a number");
                    break ;
                }
                printExchange(date, value);
            }
            else {
                printError("too many arguments");
                break ;
            }
            index++;
        }
        
    }
    
}

void BitcoinExchange::printError(std::string msg) {
    std::cout << "Error: " << msg << std::endl;
}

void BitcoinExchange::printExchange(std::string date, float value) {
    std::map<std::string, float>::iterator it;
    it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) {
        std::cout << date << " => " << value << " = " << it->second *value << std::endl;
    }
    // 맵에 해당 날짜가 존재하지 않는 경우 예외 처리
    else {
        it = _exchangeRates.lower_bound(date);
        if (it == _exchangeRates.begin()) {
            printError("bad input => " + date);
        }
        // 이전 날짜 데이터 사용
        else {
            it--;
            std::cout << date << " => " << value << " = " << it->second * value << std::endl;
        }
    }
}