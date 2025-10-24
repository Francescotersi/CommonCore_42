#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

enum BOOL{
	FALSE,
	TRUE,
	NEGATIVE,
	TOOBIG,
	NOPIPE
};

class BitcoinExchange
{
	private:
		std::ifstream	DataCsv;
		std::ifstream	DataTxt;
		std::string		CsvFilename;
		std::string		TxtFilename;
		std::map<int, std::string>		MapTxt;
		std::map<int, std::string>		MapCsv;

		float				value;

	public:
		BitcoinExchange(char *FileTxt);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void setValue(float num);
		float getValue();

		void FillMap();
		void Exchange(size_t mapIndex, std::string str);
		void Calculate(std::string buffer, std::string txtDate);
		void CalculateLowerBound(std::string txtDate);

		void CheckValidDate();
		int checkDayBetter(std::string day, std::string month);
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