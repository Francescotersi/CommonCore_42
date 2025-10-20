#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *FileTxt) : CsvFilename("data.csv") , TxtFilename(FileTxt)
{
	this->value = 0;
	this->DataCsv.open(CsvFilename.c_str());
	this->DataTxt.open(TxtFilename.c_str());
	if (!this->DataCsv.is_open() || ! this->DataTxt.is_open())
		throw ErrorMessage("Error : cannot open a file");

	FillMap();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->value = other.value;
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
		this->value = other.value;
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

void BitcoinExchange::setValue(float num)
{
	this->value = num;
}

float BitcoinExchange::getValue()
{
	return this->value;
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

	size_t mapIndex = 0; 
	while (std::getline(ss, str))
	{
		std:: cout << str << std::endl;
		std::string year = str.substr(0, 4);
		std::string month = str.substr(5, 2);
		std::string day = str.substr(8, 2);
		std::string rawValue;
		int		check = FALSE;

		if (year > "9999" || year < "2009")
			check = TRUE;

		if (month > "12" || month < "01")
			check = TRUE;

		if (day > "31" || day < "01")
			check = TRUE;

		std::size_t sep = str.find('|');
		if (sep != std::string::npos)
		{
			for (std::size_t k = sep + 1; k < str.size(); k++)
			{
				unsigned char c = static_cast<unsigned char>(str[k]);
				if (std::isdigit(c) || c == '.' || c == '-')
					rawValue.push_back(str[k]);
				else if (!rawValue.empty())
					break;
			}
		}
		if (!rawValue.empty())
			setValue(std::atof(rawValue.c_str()));
		if (getValue() < 0)
			check = NEGATIVE;
		if (getValue() > 1000)
			check = TOOBIG;
		
		switch (check)
		{
			case TRUE:
				setValue(0);
				std::cout << "Error : bad input => " << str << std::endl;
				break;
			case NEGATIVE:
				setValue(0);
				std::cout << "Error : not a positive number" << std::endl;
				break;
			case TOOBIG:
				setValue(0);
				std::cout << "Error : too large a number" << std::endl;
				break;
			case FALSE:
				Exchange(mapIndex, str);
				setValue(0);
				break;
		}
		mapIndex++;
	}
}

// nella mappa mapCsv arriva nel punto in cui si arriva alla data uguale a str
// oppure nella data precedente

// usa       std::lower_bound(container.begin(), container.end());

// output    data_da_csv => value = prodotto_moltiplicazione
void BitcoinExchange::Exchange(size_t mapIndex, std::string str)
{
	(void)mapIndex;
	std::stringstream ss;
	std::string buffer;
	std::map<int, std::string>::const_iterator it = MapCsv.begin();

	for (it = MapCsv.begin(); it != MapCsv.end(); ++it)
	{
		ss << it->second << "\n";
	}

	std::string csvDate;
	std::string txtDate = str.substr(0, 10);
	while (std::getline(ss, buffer))
	{
		csvDate = buffer.substr(0, 10);

		if (csvDate == txtDate)
			Calculate(buffer, txtDate);
	}
	// CalculateLowerBound();
	// std::lower_bound(MapCsv.begin(), MapCsv.end(), txtDate);

	// FARE LOWER_BOUND ultima cosa rimanente da fare poi hai finito
}

void BitcoinExchange::Calculate(std::string buffer, std::string txtDate)
{
	std::size_t sep = buffer.find(',');
	std::string multiplier;

	if (sep != std::string::npos)
	{
		for (std::size_t k = sep + 1; k < buffer.size(); k++)
		{
			multiplier.push_back(buffer[k]);
		}
	}
	std::cout << txtDate << " => " << getValue() << " = " << getValue() * std::atof(multiplier.c_str()) << std::endl;
}



