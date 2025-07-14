#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <thread>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define B_GREEN "\e[0;32m"

// otacon.cpp
void	otacon_calls_in();
void	otacon_gets_angry();
void	otacon_calls_out();
void	codec_instructions();
void	otacon_asks_for_index();
void	otacon_easter_egg();
void	otacon_makes_snake_feel_bad();
void	slowPrint(const std::string &message, unsigned int delayMs);

#endif