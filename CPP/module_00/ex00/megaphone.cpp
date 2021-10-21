

#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
	int i;
	int j;
	
	j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++j < argc)
	{
		i = -1;
		while (argv[j][++i])
		{
			std::cout << (char)toupper(argv[j][i]);
		}
	}
	std::cout << std::endl;
	
}