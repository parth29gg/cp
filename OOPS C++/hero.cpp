#include <iostream>
#include <cstring> // For strcpy
using namespace std;

class Hero
{
private:
    int health;

public:
    char level;
    char *name;

    // Default Constructor
    Hero()
    {
        cout << "Hero created" << endl;
        name = new char[100];
    }

    // Parameterized Constructor
    Hero(int health, char level)
    {
        cout << "Hero created with health: " << health << " level: " << level << endl;
        name = new char[100];
        this->health = health;
        this->level = level;
    }

    // Copy Constructor (Deep Copy)
    Hero(const Hero &other)
    {
        cout << "Hero copied with health: " << other.health << " level: " << other.level << endl;
        this->health = other.health;
        this->level = other.level;
        this->name = new char[100];
        strcpy(this->name, other.name);
    }

    // ---------------- DESTRUCTOR ---------------- //
    ~Hero()
    {
        cout << "Destructor called for Hero: " << (name ? name : "Unnamed") << endl;
        delete[] name; 
    }
    // ------------------------------------------ //

    void setHealth(int h)
    {
        health = h;
    }

    int getHealth() const
    {
        return health;
    }

    void setLevel(char level)
    {
        this->level = level;
    }

    char getLevel()
    {
        return level;
    }
    void setName(const char *name)
    {
        strcpy(this->name, name);
    }

    const char *getName() const
    {
        return name;
    }

    void print()
    {
        cout << "Health: " << health << ", Level: " << level << ", Name: " << name << endl;
    }
};