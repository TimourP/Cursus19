#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int i = open("test.txt", O_RDONLY);
	int j = -1;
	int value;
	char *line;

	line = NULL;

	while (++j < 20)
	{
		value = get_next_line(i, &line);
		printf("%d :\t()%d %s\n", j, value, line);
		if (line)
			free(line);
	}
	
	while (1)
	{
		/* code */
	}
	

}