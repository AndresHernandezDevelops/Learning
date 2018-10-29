#include "pch.h"
#include "Child.h"


using namespace std;


Child::Child()
{
	cout << "child class default constructor called" << endl;
}


Child::~Child()
{
}

Child::Child(int x, string color) : Father(x), Mother(){
	this->skinColor = color;
	cout << "child class overloaded constructor called" << endl;
}

void Child::display() {
	cout << "height is " << height << endl;
	cout << "skin color is " << skinColor << endl;
}

void Child::override() {
	cout << "this is the Child's 'override' method" << endl;
}