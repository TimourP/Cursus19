#include <stdio.h>
#include <string.h>
#include <ctype.h>
void to_u(char *str)
{
	int i;

	i = -1;
	while (++i)
		str[i] = toupper(str[i]);
}

int main(int argc, char** argv)
{
	char test[] = "hello";
	toupper(test);
	printf("%s", test);
    return 0;
}