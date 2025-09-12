#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


// GUARDATI DIPENDENZE CIRCOLARI, FORWARD DECLARATIONS
// TESTA DI CAZZO RICORDTELO


int main()
{
    std::cout << "=== MATERIA SYSTEM TESTS ===" << std::endl;

    // Test 1: Creating MateriaSource and learning materias
    std::cout << "\n--- Test 1: MateriaSource ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Test 2: Creating characters
    std::cout << "\n--- Test 2: Creating Characters ---" << std::endl;
    ICharacter* wizard = new Character("Gandalf");
    ICharacter* target = new Character("Orc");

    // Test 3: Creating and equipping materias
    std::cout << "\n--- Test 3: Creating and Equipping Materias ---" << std::endl;
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    wizard->equip(tmp);
    
    tmp = src->createMateria("cure");
    wizard->equip(tmp);
    
    tmp = src->createMateria("ice");
    wizard->equip(tmp);
    
    // Test creating unknown materia
    tmp = src->createMateria("fire"); // Should return NULL
    wizard->equip(tmp); // Should handle NULL gracefully

    // Test 4: Using materias
    std::cout << "\n--- Test 4: Using Materias ---" << std::endl;
    wizard->use(0, *target); // ice
    wizard->use(1, *target); // cure
    wizard->use(2, *target); // ice
    wizard->use(3, *target); // empty slot
    wizard->use(10, *target); // invalid index

    // Test 5: Unequipping materias
    std::cout << "\n--- Test 5: Unequipping Materias ---" << std::endl;
    wizard->unequip(1); // Should unequip cure
    wizard->unequip(1); // Should say nothing equipped
    wizard->unequip(-1); // Invalid index
    wizard->unequip(10); // Invalid index

    // Test 6: Equipping after unequip
    std::cout << "\n--- Test 6: Re-equipping ---" << std::endl;
    tmp = src->createMateria("cure");
    wizard->equip(tmp);
    wizard->use(1, *target); // Should work now

    // Test 7: Filling all slots
    std::cout << "\n--- Test 7: Filling All Slots ---" << std::endl;
    tmp = src->createMateria("ice");
    wizard->equip(tmp); // Slot 3
    
    tmp = src->createMateria("cure");
    wizard->equip(tmp); // Should not equip (inventory full)

    // Test 8: Character copy (testing deep copy)
    std::cout << "\n--- Test 8: Character Copy Test ---" << std::endl;
    {
        Character original("Original");
        AMateria* ice = src->createMateria("ice");
        AMateria* cure = src->createMateria("cure");
        
        original.equip(ice);
        original.equip(cure);
        
        std::cout << "Original using materia:" << std::endl;
        original.use(0, *target);
        
        Character copy(original);
        std::cout << "Copy using materia:" << std::endl;
        copy.use(0, *target);
        
        // Both should work independently
    } // original and copy destroyed here

    // Test 9: Assignment operator
    std::cout << "\n--- Test 9: Assignment Operator ---" << std::endl;
    {
        Character char1("Char1");
        Character char2("Char2");
        
        char1.equip(src->createMateria("ice"));
        char1.equip(src->createMateria("cure"));
        
        char2 = char1; // Assignment
        
        std::cout << "Char1 (" << char1.getName() << ") using materia:" << std::endl;
        char1.use(0, *target);
        
        std::cout << "Char2 (" << char2.getName() << ") using materia:" << std::endl;
        char2.use(0, *target);
    }

    // Test 10: MateriaSource limits
    std::cout << "\n--- Test 10: MateriaSource Limits ---" << std::endl;
    IMateriaSource* fullSource = new MateriaSource();
    fullSource->learnMateria(new Ice());
    fullSource->learnMateria(new Cure());
    fullSource->learnMateria(new Ice());
    fullSource->learnMateria(new Cure());
    fullSource->learnMateria(new Ice()); // Should not learn (full)

    // Cleanup
    std::cout << "\n--- Cleanup ---" << std::endl;
    delete wizard;
    delete target;
    delete src;
    delete fullSource;

    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}
