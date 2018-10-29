#include "pch.h"
#include "Mother.h"
#include <iostream>

using namespace std;

Mother::Mother() {
	cout << "called the mother constructor" << endl;
}

Mother::~Mother()
{
}

void Mother::override(){
	cout << "this is the mother's 'override' method" << endl;
}


