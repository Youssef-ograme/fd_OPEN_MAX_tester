#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);

	int big = dup2(fd, 1024);      
	if (big < 0)
	{
		perror("dup2");          
		big = fd;
	}
	else
		close(fd);             

	char *res;
	while ((res = get_next_line(big)) != NULL)
	{
		printf("%s", res);
		free(res);
	}
	close(big);
	return (0);
}