#include "header.h"

void slowPrint(const std::string& message, unsigned int delayMs)
{
	for (char c : message)
	{
		std::cout << B_GREEN << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
	}
	std::cout << std::endl;
}

void otacon_asks_for_index()
{
	slowPrint("-Snake, please insert the index of the contact you want to search", 10);
	slowPrint("-Remember that the index starts from 1 to 8", 10);
	slowPrint("-If you want to go back, write EXIT", 10);
}

void	otacon_calls_in()
{
	slowPrint("-Hi Snake here`s Otacon, this is your Codec phonebook", 10);
}

void	codec_instructions()
{
	slowPrint("-Write ADD to create a new contact", 10);
	slowPrint("-Write SEARCH to search a contact in your Codec", 10);
	slowPrint("-Write EXIT to close the Codec and go back to your mission", 10);
}

void	otacon_gets_angry()
{
	slowPrint("-Snake, you are not following the Codec protocol!", 5);
	slowPrint("-Please follow the instructions!", 5);
}

void	otacon_calls_out()
{
	slowPrint("-Codec closed, Snake, go back and kick Liquid`s ass", 10);
	slowPrint("-Good luck out there!", 10);
	slowPrint("-Otacon out!", 10);
}

void otacon_makes_snake_feel_bad()
{
	slowPrint("-Snake, are you dumb!?!?!", 10);
	slowPrint("-I know that you are a so called legend but", 10);
	slowPrint("-You really can`t even follow some Easy instructions", 10);
	slowPrint("-Remember Snake there cannot be EMPTY FIELDS in your contact", 10);
	slowPrint("-Otherwise it`ll get deleted", 10);
	slowPrint("-If you continue like this Liquid is going to beat you!!!!", 10);
	std::cout << std::endl;
}

void otacon_easter_egg()
{
	slowPrint("-Snake, you really are a legend!", 30);
	slowPrint("-But i don`t undertand why you want to save your brother`s number", 30);
	slowPrint("-Liquid Snake is your enemy, not your friend!", 30);
	slowPrint("-You should focus on your mission!", 30);
	slowPrint("-But I guess you are a true fan of Metal Gear Solid!", 30);
	slowPrint("-So I will let you keep this contact", 30);
	slowPrint("-Keep up the good work!", 30);
	std::cout << std::endl;
}
