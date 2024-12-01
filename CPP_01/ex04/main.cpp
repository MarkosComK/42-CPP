
#include <iostream>
#include <fstream>
//Create a program that takes three parameters in the following order: a filename and
//two strings, s1 and s2.
//It will open the file <filename> and copies its content into a new file
//<filename>.replace, replacing every occurrence of s1 with s2.
//
int	compare(std::string str, char c, std::ofstream& outfile)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == c)
		{
			return (i);
		}
		outfile << str[i];
		if (str[i + 1] == '\0')
			outfile << std::endl;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Invalid Parameters" << std::endl, 0);
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::string teste;
	std::string subs;
	std::ifstream input(filename.c_str());
	std::ofstream output("output.txt");
	bool flag = 1;
	while (std::getline(input, teste))
	{
		std::cout << teste << std::endl;
		for (int i = 0; teste[i]; i++)
		{
			if (teste[i] == s1[0])
			{
				subs = teste.substr(i, s1.length());
				if (subs.compare(s1) == 0)
				{
					output << s2;
					i += subs.length() - 1;
					flag = 0;
				}
			}
			if (flag)
			{
				output << teste[i];
				if (teste[i + 1] == '\0')
					output << std::endl;
			}
			flag = 1;
		}
	}
	std::cout << filename << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}
