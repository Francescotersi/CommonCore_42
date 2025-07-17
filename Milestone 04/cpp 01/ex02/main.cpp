#include <iostream> 

// reference are more secure cause you cant go out of memory
// while with pointer you can go out of memory cause you can change the their value
int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *pointer = &brain;
    std::string &reference = brain;

    std::cout << "Memory addr of the string var = "<< &brain << std::endl;
    std::cout << "Memory addr of the pointer to the string = " << &pointer << std::endl;
    std::cout << "Memory addr of the reference of the string = " << &reference << std::endl;

    std::cout << "Value of the string var = " << brain << std::endl;
    std::cout << "Value of the pointer to the string = " << *pointer << std::endl;
    std::cout << "Value of the reference of the string = " << reference << std::endl;
    return (0);
}
