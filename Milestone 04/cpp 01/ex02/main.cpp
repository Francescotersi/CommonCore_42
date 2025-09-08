#include <iostream> 

// reference are more secure cause can't be inizialized to NULL
// while with pointer can be initialized to NULL
int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *pointer = &brain;
    std::string &reference = brain;

    std::cout << "Memory addr of the string var = "<< &brain << std::endl;
    std::cout << "Memory addr of the pointer to the string = " << pointer << std::endl;
    std::cout << "Memory addr of the reference of the string = " << &reference << std::endl;

    std::cout << "Value of the string var = " << brain << std::endl;
    std::cout << "Value of the pointer to the string = " << *pointer << std::endl;
    std::cout << "Value of the reference of the string = " << reference << std::endl;
    return (0);
}
