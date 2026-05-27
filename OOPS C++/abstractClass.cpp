#include <iostream>
using namespace std;

// Base abstract class
class Shape {
// public: 
    virtual int area() = 0; 

    // void print(){
    //     cout<<"Space Created"<<endl;
    // }
};

// Derived class
class Rectangle : public Shape {
private: 
    int length;
    int breadth;

public:
    Rectangle(int len, int br) {
        this->length = len;
        this->breadth = br;
    }

    int perimeter() { 
        return 2 * (length + breadth);
    }

    int area() override {
        return length * breadth;
    }
};

int main() {
    Rectangle r(5, 2);

    cout << r.area() << endl;
    //r.print();
    return 0;
}