# include <iostream>
# include <fstream>

int main(int argc, char **argv)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string readline;

	if (argc != 4)
	{
		std::cerr << "Error : invalid arguments(4개의 인자를 입력해주세요)" <<std::endl;
		return (1);
	}
	std::string file = argv[1];
	ifs.open(file);
	if(ifs.fail())
	{
		std::cerr << "Error : file open failed(파일을 열 수 없습니다)" << std::endl;
		return (1);
	}
	std::string outfile = file;
	outfile.append(".replace"); //입력 파일 이름에 추가해서 복제본 생성
	ofs.open(outfile);
	if(ofs.fail())
	{
		std::cerr << "Error : file failed" << std::endl;
		return (1);
	}
	std::string findline = argv[2];
	std::string changeline = argv[3];
	if (findline.empty())
	{
		std::cerr << "Error : Invalid s1" << std::endl;
		return (1);
	}
	while (std::getline(ifs, readline)) //File에서 한 줄씩 읽어오기
	{
		size_t pos = 0;
		while(1)
		{
			pos = readline.find(findline); // 문자열에서 s1 찾기
			if (pos == std::string::npos) // 일치하는 문자열이 없을 경우 종료
				break;
			readline.erase(pos, findline.length()); // s1 제거
			readline.insert(pos, changeline); // s1을 s2로 교체
			pos += changeline.length(); // 다음 검색 위치 설정
		}
		ofs << readline << std::endl;
	}
	return (0);
}