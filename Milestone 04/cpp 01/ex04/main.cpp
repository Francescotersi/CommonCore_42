#include "header.hpp"

std::string	ftReplace(std::string strToSearch, std::string strToInsert, std::string content)
{
	size_t		pos = 0;
	size_t		found = 0;
	std::string	result;

	while ((found = content.find(strToSearch, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += strToInsert;
		pos = found + strToSearch.length();
	}
	result += content.substr(pos);
	return (result);
}

bool	putInNewFile(std::string result, char **argv)
{
	std::string		outputFile;

	outputFile = std::string(argv[1]) + ".replace";
	std::ofstream	newFile(outputFile);
	if (!newFile.is_open())
		return (false);
	newFile << result;
	newFile.close();
	std::cout << "ALL REPLACED INSIDE OF = " << outputFile << std::endl;
	return (true);
}

int main(int argc, char **argv)
{
	std::fstream	file(argv[1]);
	std::string		strToSearch = argv[2];
	std::string		strToInsert = argv[3];
	std::string		line;
	std::string		content;
	std::string		result;

	if (argc != 4)
		return (std::cout <<
			"Please give 1)Filename, 2)String to search, 3)String to replace" <<
			std::endl, 1);
	std::string temp = argv[2];
	if (temp == "")
		return (std::cout << "non puoi scarso!!!!!" << std::endl, 1);
	if (!file.is_open())
		return (std::cout <<
			"Could not open the file (I AM THE ONE WHO KNOCKS!)" <<
			std::endl, 1);
	while (std::getline(file, line))
		content += line + '\n';
	file.close();
	result = ftReplace(strToSearch, strToInsert, content);
	if (!putInNewFile(result, argv))
		return (std::cout <<
			"Could not open the file (I AM THE ONE WHO KNOCKS!)" <<
			std::endl, 1);
	return (0);
}
