#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void Harl::debug()
{
	std::cout <<
	"[DEBUG]" << 
	std::endl << 
	"I love doing some DEBUG on my minishell (I hate you master!)" <<
	std::endl;
}

void Harl::info()
{
	std::cout <<
	"[INFO]" <<
	std::endl <<
	"Why are you asking me for INFOs, i know less than you do" <<
	std::endl;
}

void Harl::warning()
{
	std::cout <<
	"[WARNING]" <<
	std::endl <<
	"I`m going to give you a WARNING this time don`t try to speed again!" <<
	std::endl;
}

void Harl::error()
{
	std::cout <<
	"[ERROR]" <<
	std::endl <<
	"You are the one making ERRORs this time, not me" <<
	std::endl;
}

// CORRETTO - Array di puntatori a funzioni membro
// void (Harl::*complainFunction[])(void)
// SBAGLIATO - Funzione che restituisce un array di puntatori  
// void Harl::*complainFunction[](void)
void	Harl::complain(std::string level)
{
	// arrey di puntatori a funzioni membro
	void (Harl::*complainFunction[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	// arrey di stringhe corrispondenti ai puntatori tramite stesso index
	std::string	levelOfComplain[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levelOfComplain[i])
		{
			(this->*complainFunction[i])();
			break ;
		}
	}
}
