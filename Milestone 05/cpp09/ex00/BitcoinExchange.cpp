#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *FileTxt) : CsvFilename("data.csv") , TxtFilename(FileTxt)
{
	this->DataCsv.open(CsvFilename.c_str());
	this->DataTxt.open(TxtFilename.c_str());
	if (!this->DataCsv.is_open() || ! this->DataTxt.is_open())
		throw ErrorMessage("Error : cannot open a file");

	FillMap();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->MapTxt = other.MapTxt;
	this->MapCsv = other.MapCsv;
	this->CsvFilename = other.CsvFilename;
	this->TxtFilename = other.TxtFilename;
	this->DataCsv.open(CsvFilename.c_str());
	this->DataTxt.open(TxtFilename.c_str());
	if (!this->DataCsv.is_open() || ! this->DataTxt.is_open())
		throw ErrorMessage("Error : cannot open a file");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->MapTxt = other.MapTxt;
		this->MapCsv = other.MapCsv;
		this->CsvFilename = other.CsvFilename;
		this->TxtFilename = other.TxtFilename;
		this->DataCsv.open(CsvFilename.c_str());
		this->DataTxt.open(TxtFilename.c_str());
		if (!this->DataCsv.is_open() || ! this->DataTxt.is_open())
			throw ErrorMessage("Error : cannot open a file");
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::FillMap() // fills the two maps with something
{
	int KeyCount = 0;
	std::string str;

	std::getline(this->DataCsv, str);
	while (std::getline(this->DataCsv, str))
	{
		MapCsv.insert(std::pair<int , std::string>(KeyCount, str));
		KeyCount++;
	}

	KeyCount = 0;
	std::getline(this->DataTxt, str);
	while (std::getline(this->DataTxt, str))
	{
		MapTxt.insert(std::pair<int , std::string>(KeyCount, str));
		KeyCount++;
	}

	// for (std::map<int, std::string>::iterator it = MapCsv.begin(); it != MapCsv.end(); it++)
	// 	std::cout << "key = " << it->first << " value = " << it->second << std::endl;
	
	// for (std::map<int, std::string>::iterator it = MapTxt.begin(); it != MapTxt.end(); it++)
	// 	std::cout << "key = " << it->first << " value = " << it->second << std::endl;
}

// controlla se la formattazione del file input.txt sia valida
void BitcoinExchange::CheckValidDate()
{
	std::stringstream ss;
	std::string str;
	std::map<int, std::string>::const_iterator it;

	for (it = MapTxt.begin(); it != MapTxt.end(); ++it)
	{
		ss << it->second << "\n";
	}

	while (std::getline(ss, str))
	{
		std::string year;
		std::string month;
		std::string day;
		int			i = 0;
		bool		check = false;

		for (int i; str[i] && str[i] != '-'; i++)
			year[i] = str[i];
		i++;
		if (year > "9999" || year < "2009")
			check = true;

		for (int i; str[i] && str[i] != '-'; i++)
			month[i] = str[i];
		i++;
		if (month > "12" || month < "01")
			check = true;

		for (int i; str[i] && str[i] != '-'; i++)   // da rincontrollare
			day[i] = str[i];
		i++;
		if (day > "12" || day < "01")
			check = true;
	}
}

// 2009-01-02,

void BitcoinExchange::Exchange()
{
	CheckValidDate();
}



