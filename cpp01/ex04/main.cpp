#include <iostream>
#include <string>
#include <fstream>


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream input_file(filename);
	std::ofstream output_file("filename.replace");

	if (input_file.is_open() && output_file.is_open())	{
		std::string line;
		size_t	pos = 0;
		while (getline(input_file, line))
		{
			pos = line.find(s1);
			if (pos != std::string::npos) {
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
		output_file << line << std::endl;
		}
		std::cout << "File copied successfully" << std::endl;
		input_file.close();
		output_file.close();
	}	
	else {
		std::cout << "Error opening files" << std::endl;
		return 1;
	}
	return (0);
}
