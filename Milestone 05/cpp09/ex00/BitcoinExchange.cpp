#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *FileTxt) : CsvFilename("data.csv") , TxtFilename(FileTxt)
{
	this->DataCsv.open(CsvFilename.c_str());
	this->DataTxt.open(TxtFilename.c_str());
	if (!this->DataCsv.is_open() || ! this->DataTxt.is_open())
		throw ErrorMessage("Error : cannot open a file");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
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
