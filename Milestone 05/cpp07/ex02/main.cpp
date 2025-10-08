#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " primo" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " secondo" << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    // return 0;

    // --------------------------------------------------
    std::cout << "------------------------------------------------------" << std::endl;

    {
        Array<int> a;
        try
        {
            (void)a[0];
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Array<int> a(3);
        a[0] = 1; a[1] = 2; a[2] = 3;
        Array<int> b(a);
        Array<int> c;
        c = a;
        b[0] = 42;
        c[1] = 43;
        std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;
        std::cout << b[0] << " " << b[1] << " " << b[2] << std::endl;
        std::cout << c[0] << " " << c[1] << " " << c[2] << std::endl;
    }

}