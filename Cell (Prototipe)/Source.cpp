#include <iostream>
#include<string>
using namespace std;

class Cell 
{
public:
    string _genom;
    Cell(string genom) : _genom(genom) {}
    virtual Cell* split() = 0;
    virtual void showGenom() = 0;
};

class SingleCellOrganism : public Cell 
{
public:
    SingleCellOrganism(string genom) :Cell(genom) {}
    Cell* split() override { return new SingleCellOrganism(_genom);}
    void showGenom() override {cout << "has genom " << _genom << endl;}
};

class Reproduction 
{
public:
    Reproduction() { reproduction(); }

private:
    void reproduction() 
    {
        Cell* organizm1 = new SingleCellOrganism("A1B2C3");
        Cell* organizm2 = organizm1->split();
        cout << "Organizm 1 "; organizm1->showGenom();
        cout << "Organizm 2 "; organizm2->showGenom();
        delete organizm1;
        delete organizm2;
    }

};

int main()
{
    Reproduction reproduction;
    system("pause");
    return 0;
}
