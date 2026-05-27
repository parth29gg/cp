#include <bits/stdc++.h>
#include "hero.cpp"
using namespace std;

int main()
{

    Hero h1; // static allocation

    Hero *h2 = new Hero(); // dynamic  allocation

    Hero *h3 = new Hero(50, 'A');
    Hero h4(100, 'B');
    
    cout << endl;

    
    h3->setName("Parth");
    Hero h5(*h3); // in built
   
    h3->print();
    h5.print();

    return 0;
}