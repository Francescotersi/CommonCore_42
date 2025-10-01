#include "iter.hpp"

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original int array: ";
    iter(arr, len, print<int>);
    std::cout << std::endl;

    std::cout << "Incrementing... " << std::endl;
    iter(arr, len, increment<int>);
    std::cout << "Modified int array: ";
    iter(arr, len, print<int>);
    std::cout << std::endl;

    std::string strs[] = {"Mineta", "bro", "Piero"};
    int len2 = sizeof(strs) / sizeof(strs[0]);

    std::cout << "String array: ";
    iter(strs, len2, print<std::string>);
    std::cout << std::endl;

    const int constArr[] = {10, 20, 30};
    int len3 = sizeof(constArr) / sizeof(constArr[0]);

    std::cout << "Const int array: ";
    iter(constArr, len3, print<int>);
    std::cout << std::endl;

    return 0;
}