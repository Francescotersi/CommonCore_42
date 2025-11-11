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
	std::map<int, std::string>::iterator it;

	for (it = MapTxt.begin(); it != MapTxt.end(); ++it)
	{
		ss << it->second << "\n";
	}

	size_t mapIndex = 0; 
	while (std::getline(ss, str))
	{
		std::string date = str.substr(0, 10);
		std::string year = str.substr(0, 4);
		std::string month = str.substr(5, 2);
		std::string day = str.substr(8, 2);
		std::string rawValue;
		int		check = FALSE;

		for (int i = 0; date[i]; i++)
		{
			if (date[i] != '-' && !std::isdigit(date[i]))
			{
				check = TRUE;
				break ;
			}
		}
		std::string dateFull = year + "-" + month + "-" + day;
		if (dateFull < "2009-01-02")
			check = EARLYDATE;

		if (year > "9999" || year < "2009")
			check = TRUE;

		if (month > "12" || month < "01")
			check = TRUE;

		if (checkDayBetter(day, month) == TRUE)
			check = TRUE;

		std::size_t sep = str.find('|');
		if (sep != std::string::npos)
		{
			for (std::size_t k = sep + 2; k < str.size(); k++)
			{
				unsigned char c = static_cast<unsigned char>(str[k]);
				if (std::isdigit(c) || c == '.' || c == '-')
					rawValue.push_back(c);
				else
					check = TRUE;
			}
			for (std::size_t k = 0; k < rawValue.size(); k++)
			{
				if (rawValue[k] == '-' || rawValue[k] == ' ')
					check = TRUE;
			}
		}
		else
			check = NOPIPE;
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
			case NOPIPE:
				setValue(0);
				std::cout << "Error : no pipe found" << std::endl;
				break;
			case EARLYDATE:
				setValue(0);
				std::cout << "Error : bitcoin was not yet created" << std::endl;
				break;
		}
		mapIndex++;
	}
}

void BitcoinExchange::Exchange(size_t mapIndex, std::string str)
{
	(void)mapIndex;
	std::stringstream ss;
	std::string buffer;
	std::map<int, std::string>::iterator it = MapCsv.begin();

	for (it = MapCsv.begin(); it != MapCsv.end(); ++it)
	{
		ss << it->second << "\n";
	}

	std::string csvDate;
	std::string txtDate = str.substr(0, 10);
	int	found = FALSE;
	while (std::getline(ss, buffer))
	{
		csvDate = buffer.substr(0, 10);

		if (csvDate == txtDate)
		{
			Calculate(buffer, txtDate);
			found = TRUE;
			return ;
		}
		else if (csvDate > txtDate)
		{
			CalculateLowerBound(txtDate);
			return ;
		}
		
	}
	CalculateTxtOver(txtDate);
	return ;
}

void BitcoinExchange::CalculateTxtOver(std::string txtDate)
{
	std::string multiplier;

	std::map<int, std::string>::reverse_iterator rit = MapCsv.rbegin();
	std::size_t sep = rit->second.find(',');
	if (sep != std::string::npos)
		for (std::size_t k = sep + 1; k < rit->second.size(); k++)
			multiplier.push_back(rit->second[k]);
	// std::cout << "multi = " << multiplier << std::endl;
	std::cout << txtDate << " => " << getValue() << " = " << getValue() * std::atof(multiplier.c_str()) << std::endl;
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

void BitcoinExchange::CalculateLowerBound(std::string txtDate)
{
	std::string multiplier;

	for (std::map<int, std::string>::iterator it = MapCsv.begin(); it != MapCsv.end(); it++)
	{
		if (it->second.substr(0, 10) > txtDate)
		{
			it--;
			std::size_t sep = it->second.find(',');
			if (sep != std::string::npos)
				for (std::size_t k = sep + 1; k < it->second.size(); k++)
					multiplier.push_back(it->second[k]);
			break;
		}
	}
	std::cout << txtDate << " => " << getValue() << " = " << getValue() * std::atof(multiplier.c_str()) << std::endl;
}

int BitcoinExchange::checkDayBetter(std::string day, std::string month) // controlli sui mesi no bisestili
{
	if ((month == "04" || month == "06" || month == "09" || month == "11") && (day >= "01" && day <= "30"))
		return FALSE;
	if ((month == "02") && (day >= "01" && day <= "28"))
		return FALSE;
	if (day >= "01" && day <= "31" && month != "02")
		return FALSE;
	return TRUE;
}
