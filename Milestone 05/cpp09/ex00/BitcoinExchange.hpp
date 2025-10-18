#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <sstream>
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
		std::map<int, std::string>		MapTxt;
		std::map<int, std::string>		MapCsv;

	public:
		BitcoinExchange(char *FileTxt);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void FillMap();
		void Exchange();

		void CheckValidDate();
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