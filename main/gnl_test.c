#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *str;
	int fd = open("test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			return (0);
		printf("%s", str);
	}
}