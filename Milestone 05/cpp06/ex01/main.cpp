#include "Serializer.hpp"

void test1_BasicSerialization() 
{
	std::cout << "=== Test 1: Basic Serialization ===" << std::endl;
	
	Data* original = new Data();
	original->data = 42;
	
	std::cout << "Original: " << original << " (value: " << original->data << ")" << std::endl;
	
	uintptr_t serialized = Serializer::serialize(original);
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "Deserialized: " << deserialized << " (value: " << deserialized->data << ")" << std::endl;
	std::cout << "Result: " << (original == deserialized ? "SUCCESS" : "FAILED") << std::endl;
	
	delete original;
}

void test2_NullPointer() 
{
	std::cout << "\n=== Test 2: Null Pointer ===" << std::endl;
	
	Data* nullPtr = NULL;
	uintptr_t serialized = Serializer::serialize(nullPtr);
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "Null pointer preserved: " << (deserialized == NULL ? "SUCCESS" : "FAILED") << std::endl;
}

void test3_MultipleObjects() 
{
	std::cout << "\n=== Test 3: Multiple Objects ===" << std::endl;
	
	Data* obj1 = new Data();
	Data* obj2 = new Data();
	obj1->data = 100;
	obj2->data = 200;
	
	uintptr_t ser1 = Serializer::serialize(obj1);
	uintptr_t ser2 = Serializer::serialize(obj2);
	
	Data* deser1 = Serializer::deserialize(ser1);
	Data* deser2 = Serializer::deserialize(ser2);
	
	bool test1 = (obj1 == deser1) && (obj1->data == deser1->data);
	bool test2 = (obj2 == deser2) && (obj2->data == deser2->data);
	
	std::cout << "Object 1: " << (test1 ? "SUCCESS" : "FAILED") << std::endl;
	std::cout << "Object 2: " << (test2 ? "SUCCESS" : "FAILED") << std::endl;
	
	delete obj1;
	delete obj2;
}

void test4_DataModification() 
{
	std::cout << "\n=== Test 4: Data Modification ===" << std::endl;
	
	Data* original = new Data();
	original->data = 123;
	
	uintptr_t serialized = Serializer::serialize(original);
	original->data = 999; // Modify after serialization
	
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "Modified value preserved: " << (deserialized->data == 999 ? "SUCCESS" : "FAILED") << std::endl;
	std::cout << "Same object: " << (original == deserialized ? "SUCCESS" : "FAILED") << std::endl;
	
	delete original;
}

void test5_RoundTrip() 
{
	std::cout << "\n=== Test 5: Round Trip ===" << std::endl;
	
	Data* original = new Data();
	original->data = 777;
	
	// Serialize -> Deserialize -> Serialize -> Deserialize
	uintptr_t step1 = Serializer::serialize(original);
	Data* step2 = Serializer::deserialize(step1);
	uintptr_t step3 = Serializer::serialize(step2);
	Data* final = Serializer::deserialize(step3);
	
	bool success = (original == final) && (original->data == final->data);
	std::cout << "Round trip: " << (success ? "SUCCESS" : "FAILED") << std::endl;
	
	delete original;
}

int main() 
{
	std::cout << "SERIALIZER - 5 ESSENTIAL TESTS" << std::endl;
	std::cout << "===============================" << std::endl;
	
	test1_BasicSerialization();
	test2_NullPointer();
	test3_MultipleObjects();
	test4_DataModification();
	test5_RoundTrip();
	
	std::cout << "\n✓ All tests completed!" << std::endl;
	return 0;
}
