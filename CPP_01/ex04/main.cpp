#include <iostream>
#include <fstream>
//Create a program that takes three parameters in the following order: a filename and
//two strings, s1 and s2.
//It will open the file <filename> and copies its content into a new file
//<filename>.replace, replacing every occurrence of s1 with s2.
//

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Invalid Parameters" << std::endl, 1);

	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	std::ifstream	input(filename.c_str());
	if (!input.is_open())
		return (std::cout << "Error: Cannot open input file" << std::endl, 1);

	std::string		outfile = filename + ".replace";
	std::ofstream	output(outfile.c_str());
	if (!output.is_open())
		return (std::cout << "Error: Cannot create output file" << std::endl, 1);

	std::string		line;
	size_t			pos;

	while (std::getline(input, line)) {
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		output << line;
		if (!input.eof())
			output << std::endl;
	}
	input.close();
	output.close();
	return (0);
}
