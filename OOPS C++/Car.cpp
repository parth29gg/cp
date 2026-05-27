#include <iostream>
#include <memory>

// ===================================================================
// ## Base Class Definition
// ===================================================================
// This is the base class we'll inherit from.
// The 'move' method is 'virtual' to allow for polymorphism.
class Vehicle {
public:
    virtual void move() const {
        std::cout << "Vehicle is moving.\n";
    }
    // A virtual destructor is essential for any class with virtual methods
    // to ensure correct cleanup when deleting through a base pointer.
    virtual ~Vehicle() = default;
};

// ===================================================================
// ## Test Cases for Each 'Car' Variation
// ===================================================================

// Test Case 1: public Inheritance, public Method
// The most common and flexible form of inheritance.
class Car1 : public Vehicle {
public:
    void move() const override {
        std::cout << "Car1 (public/public) is driving on the road.\n";
    }
};

// ---

// Test Case 2: private Inheritance, public Method
// "is-implemented-in-terms-of" relationship. Polymorphism is broken.
class Car2 : private Vehicle {
public:
    void move() const override {
        std::cout << "Car2 (private/public) is driving on the road.\n";
    }
};

// ---

// Test Case 3: private Inheritance, private Method
// The most restrictive form. All functionality is hidden.
class Car3 : private Vehicle {
private:
    void move() const override {
        std::cout << "Car3 (private/private) is driving on the road.\n";
    }
    // Public method to demonstrate that 'move' can be called from within the class
public:
    void useMove() const {
        std::cout << "Car3 is calling its own private move method...\n";
        move();
    }
};

// ---

// Test Case 4 & 5: public Inheritance, private Method
// Allows polymorphism but prevents direct calls on the object.
// Car5 is identical to Car4 because 'private' is the default for a class.
class Car4 : public Vehicle {
private:
    void move() const override {
        std::cout << "Car4 (public/private) is driving on the road.\n";
    }
};

class Car5 : public Vehicle {
    // No access specifier here means 'move' is private by default.
    void move() const override {
        std::cout << "Car5 (public/private-default) is driving on the road.\n";
    }
};


// ===================================================================
// ## Main Function to Run the Tests
// ===================================================================
int main() {
    std::cout << "## 1. Testing Car1 (public Inheritance, public Method)\n";
    Car1 car1;
    car1.move(); // OK ✔️: Direct call is public.

    std::unique_ptr<Vehicle> v1 = std::make_unique<Car1>();
    v1->move();  // OK ✔️: Polymorphic call works.
    std::cout << "--------------------------------------------------\n\n";

    // ---

    std::cout << "## 2. Testing Car2 (private Inheritance, public Method)\n";
    Car2 car2;
    car2.move(); // OK ✔️: Direct call is public.

    // std::unique_ptr<Vehicle> v2 = std::make_unique<Car2>(); // COMPILE ERROR ❌
    // v2->move();
    std::cout << "Polymorphic call fails: 'Vehicle' is an inaccessible base of 'Car2'.\n";
    std::cout << "--------------------------------------------------\n\n";

    // ---

    std::cout << "## 3. Testing Car3 (private Inheritance, private Method)\n";
    Car3 car3;
    // car3.move(); // COMPILE ERROR ❌: 'move' is a private member of 'Car3'.
    std::cout << "Direct call fails: 'move' is a private member of 'Car3'.\n";
    car3.useMove(); // OK ✔️: A public method can call a private one.

    // std::unique_ptr<Vehicle> v3 = std::make_unique<Car3>(); // COMPILE ERROR ❌
    // v3->move();
    std::cout << "Polymorphic call fails: 'Vehicle' is an inaccessible base of 'Car3'.\n";
    std::cout << "--------------------------------------------------\n\n";

    // ---

    std::cout << "## 4. Testing Car4 (public Inheritance, private Method)\n";
    Car4 car4;
    // car4.move(); // COMPILE ERROR ❌: 'move' is a private member of 'Car4'.
    std::cout << "Direct call fails: 'move' is a private member of 'Car4'.\n";
    
    std::unique_ptr<Vehicle> v4 = std::make_unique<Car4>();
    v4->move();  // OK ✔️: Polymorphic call works! Access is checked against the
                 // public 'Vehicle::move', then the virtual call dispatches to the
                 // private 'Car4::move' at runtime.
    std::cout << "--------------------------------------------------\n\n";

    // ---
    
    std::cout << "## 5. Testing Car5 (public Inheritance, private-by-default Method)\n";
    Car5 car5;
    // car5.move(); // COMPILE ERROR ❌: 'move' is a private member of 'Car5'.
    std::cout << "Direct call fails: 'move' is a private member of 'Car5'.\n";
    
    std::unique_ptr<Vehicle> v5 = std::make_unique<Car5>();
    v5->move();  // OK ✔️: Same behavior as Car4.
    std::cout << "--------------------------------------------------\n\n";

    return 0;
}