// 실행할 때  bonus 부분 빼고 컴파일 하기 (중복 코드 오류)
// 기본 파일 + test.c => test에 있는 txt 파일 명 동일한 지 확인하기

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *str;
	char *str2;
	int fd = open("test2.txt", O_RDONLY);
	int fd2 = open("test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			return (0);
        free(str);
		printf("%s", str);
		str2 = get_next_line(fd2);
		if (!str2)
			return (0);
		printf("%s", str2);
        free(str2);
        system("leaks a.out");
	}
}