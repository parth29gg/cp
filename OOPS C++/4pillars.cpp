#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
    string name;
    int age;

public:
    Human(const string& name, int age) : name(name), age(age) {
        cout << "Human constructor called for " << this->name << endl;
    }

    void eat() {
        cout << name << " is eating." << endl;
    }

    void sleep() {
        cout << name << " is sleeping." << endl;
    }

    void speak() {
        cout << "Hello, my name is " << name << "." << endl;
    }
    
    string getName() const {
        return name;
    }
};


class Male : public Human {
private:
    string beardColor;

public:
    Male(const string& name, int age, const string& beardColor)
        : Human(name, age), beardColor(beardColor) {
        cout << "Male constructor called for " << this->name << endl;
    }

    void shaveBeard() {
        cout << name << " is shaving his " << beardColor << " beard." << endl;
    }

    void speak() {
        cout << "Hello, my name is " << name << " and I have a deep voice." << endl;
    }
};


int main() {
    Male person("John", 30, "brown");
    
    cout << "\n--- Testing Methods ---\n";

    person.speak();
    person.eat();
    person.sleep();
    person.shaveBeard();

    return 0;
}