#include "pch.h"
#include "Father.h"
#include <iostream>
using namespace std;

Father::Father()
{
	cout << "the default father constructor was called" << endl;
	this->height = 0;
}


Father::~Father()
{
}

Father::Father(int height) {
	cout << "overloaded constructor of father is called" << endl;
	this->height = height;
}
