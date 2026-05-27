#include <bits/stdc++.h>
using namespace std;

class Vehicle
{

public:
    void travel()
    {

        cout << "I travel" << endl;
    }
};

class Car : virtual public Vehicle
{
public:
    void travel()
    {
        cout << "I travel on Road" << endl;
    }
};
class Plane : virtual public Vehicle
{
public:
    void travel()
    {
        cout << "I travel in the Sky" << endl;
    }
};

class FlyingCar : public Car, public Plane
{
    public:
        void travel()
        {
            cout << "I travel in the Sky and on the Road"<<endl;
        }
};

int main()
{

    FlyingCar fc1;

    fc1.travel();

    return 0;
}