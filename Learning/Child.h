#pragma once
#include "Father.h"
#include "Mother.h"
#include <iostream>
#include <string>

class Child :
	public Father, public Mother
{
public:
	Child();
	~Child();
	Child(int x, string color);
	void display();
	void override();
};

