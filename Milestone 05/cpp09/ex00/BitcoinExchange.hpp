#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::ifstream	DataCsv;
		std::ifstream	DataTxt;
		std::string		CsvFilename;
		std::string		TxtFilename;
		

	public:
		BitcoinExchange(char *FileTxt);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		class ErrorMessage : public std::exception
		{
			private:
				const char *message;
			public:
				ErrorMessage(const char* str) : message(str){}
				virtual const char* what() const throw()
				{
					return message;
				}
		};

};


#endif