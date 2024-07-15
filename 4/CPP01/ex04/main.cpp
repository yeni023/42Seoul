// a 입력하고 개행 입력하면 개행으로 바꿔주는지 이 부분에 대한 처리 필요 -> getline() 함수 쓴 경우 처리 안 되는 경우 많음
# include <iostream>
# include <fstream>

int main(int ac, char **av)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string readline;

	if (ac != 4)
	{
		std::cerr << "Error : invalid arguments(4개의 인자를 입력해주세요)" <<std::endl;
		return (1);
	}

	std::string file = av[1];
	ifs.open(file);
	if(ifs.fail())
	{
		std::cerr << "Error : file open failed(파일을 열 수 없습니다)" << std::endl;
		return (1);
	}
	std::string outfile = file;
	outfile.append(".replace");
	ofs.open(outfile);

	if(ofs.fail())
	{
		std::cerr << "Error : file failed" << std::endl;
		return (1);
	}

	std::string findline = av[2];
	std::string changeline = av[3];

	if (findline.empty())
	{
		std::cerr << "Error : Invalid FindLine" << std::endl;
		return (1);
	}

	while (std::getline(ifs, readline))
	{
		size_t pos = 0;
		while(1)
		{
			pos = readline.find(findline);
			if (pos == std::string::npos) // 일치하는 문자열이 없을 경우 종료(npos: 가장 큰 값)
				break;
			readline.erase(pos, findline.length()); // s1 제거
			readline.insert(pos, changeline); // s1을 s2로 교체
			pos += changeline.length(); // 다음 검색 위치 설정
		}
		ofs << readline << std::endl;
	}
	return (0);
}