
#include <iostream>
#include <fstream>
//Create a program that takes three parameters in the following order: a filename and
//two strings, s1 and s2.
//It will open the file <filename> and copies its content into a new file
//<filename>.replace, replacing every occurrence of s1 with s2.
//
int	compare(std::string str, char c)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == c)
		{
			return (i);
		}
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
	std::ifstream input(filename.c_str());
	while (std::getline(input, teste))
	{
		int	i;
		std::cout << teste << std::endl;
		i = compare(teste, s1[0]);
		if (i > 0)
		{
			compare = teste.substr(i, ); // get the subs with the len to compare.
										 // if match we write the s2 instead them jump the i
										 // to keep going at the end looking for more matches
										 // and its done!
			std::cout << "find bruh at: " << i << std::endl;
		}
	}
	std::ofstream output("output.txt");
	std::cout << filename << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}
