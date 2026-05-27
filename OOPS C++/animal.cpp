#include <iostream>

class Animal {
public:
    // 1. A normal function (resolved at compile-time)
    void identify() {
        std::cout << "I am an Animal." << std::endl;
    }
    // 2. A virtual function (resolved at runtime)
    virtual void speak() {
        std::cout << "Animal makes a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void identify() {
        std::cout << "I am a Dog." << std::endl;
    }
    void speak() { // 'override' is good practice
        std::cout << "Woof! 🐕" << std::endl;
    }
};

int main() {
    Animal* myPet = new Dog();
    Dog myPet2;

    // --- Static Binding ---
    // The compiler sees that myPet is an Animal* pointer,
    // so it calls the Animal version of identify().
    myPet->identify(); // Output: I am an Animal.

    // --- Dynamic Binding ---
    // Because speak() is virtual, the program checks at runtime
    // what object myPet is actually pointing to (a Dog)
    // and calls the Dog's version of speak().
    myPet->speak();    // Output: Woof! 🐕

    delete myPet;
    myPet2.identify(); // Output: I am an Animal.

    // --- Dynamic Binding ---
    // Because speak() is virtual, the program checks at runtime
    // what object myPet is actually pointing to (a Dog)
    // and calls the Dog's version of speak().
    myPet2.speak(); 
    return 0;
}