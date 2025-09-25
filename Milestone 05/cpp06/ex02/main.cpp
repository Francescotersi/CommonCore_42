#include "Base.hpp"

int main()
{
	std::cout << "DYNAMIC CAST TESTS" << std::endl;
	std::cout << "==================" << std::endl;

	std::cout << "=== Test 1: Basic Generation ===" << std::endl;
	Base* obj = generate();
	std::cout << "Generated object type: ";
	identify(obj);
	delete obj;

	std::cout << "\n=== Test 2: Pointer vs Reference ===" << std::endl;
	Base* ptr = generate();
	Base& ref = *ptr;
	std::cout << "Via pointer: ";
	identify(ptr);
	std::cout << "Via reference: ";
	identify(ref);
	delete ptr;

	std::cout << "\n=== Test 3: Multiple Objects ===" << std::endl;
	for (int i = 0; i < 5; i++) {
		Base* obj = generate();
		std::cout << "Object " << i + 1 << ": ";
		identify(obj);
		delete obj;
	}

	std::cout << "\n=== Test 4: Known Types ===" << std::endl;
	A* objA = new A();
	B* objB = new B();
	C* objC = new C();
	std::cout << "Direct A: ";
	identify(objA);
	std::cout << "Direct B: ";
	identify(objB);
	std::cout << "Direct C: ";
	identify(objC);
	delete objA;
	delete objB;
	delete objC;

	std::cout << "\n=== Test 5: Null Pointer ===" << std::endl;
	Base* nullPtr = NULL;
	std::cout << "Null pointer: ";
	identify(nullPtr);
	
	std::cout << "\n✓ All tests completed!" << std::endl;
	return 0;
}
