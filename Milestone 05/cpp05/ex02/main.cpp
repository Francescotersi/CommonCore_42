#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << "=== Testing Form and Bureaucrat ===" << std::endl;
	
	try 
	{
		std::cout << "\n--- Test 1: Valid creations ---" << std::endl;
		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 10);
		Form taxForm("Tax Form", 45, 30);
		Form importantForm("Important Form", 5, 1);
		
		std::cout << john << std::endl;
		std::cout << alice << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << importantForm << std::endl;

		std::cout << "\n--- Test 2: Successful signing ---" << std::endl;
		john.signForm(taxForm);
		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;
		
		alice.signForm(importantForm);
		std::cout << importantForm << std::endl;

		std::cout << "\n--- Test 3: Failed signing ---" << std::endl;
		Form vipForm("VIP Form", 1, 1);
		john.signForm(vipForm);
		
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try 
	{
		std::cout << "\n--- Test 4: Invalid form creation (grade too high) ---" << std::endl;
		Form invalidForm("Invalid Form", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try 
	{
		std::cout << "\n--- Test 5: Invalid form creation (grade too low) ---" << std::endl;
		Form invalidForm2("Invalid Form 2", 151, 50);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try 
	{
		std::cout << "\n--- Test 6: Invalid bureaucrat creation ---" << std::endl;
		Bureaucrat invalidBureaucrat("Invalid", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try 
	{
		std::cout << "\n--- Test 7: Grade increment/decrement ---" << std::endl;
		Bureaucrat bob("Bob", 149);
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
		bob.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}