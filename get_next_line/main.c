#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

int main()
{
	int             fd1;
	int				fd2;
	int 			i;
	char			*line, *line2;

	i = 0;
/*
	if (!(fd = open("test.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	line = get_next_line(fd);
*/

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	/*line = get_next_line(fd1);
	printf("%s", line);
	line2 = get_next_line(fd2);
	printf("%s", line2);
*/
	while (i++ < 10000)
	{
		line = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line)
			break ;
		if (1)
			printf("%s", line);
		else
			printf("line [%02d]: %s", i, line);
		free(line);
		if (1)
			printf("%s", line2);
		else
			printf("line [%02d]: %s", i, line);
		free(line2);
	}
	

	printf("%s", line);
	printf("%s", line2);
}
