#pragma once
#include <iostream>
using namespace std;

#ifndef Rectangle_H
#define Rectangle_H

class Rectangle
{
private:
	int length;
	int width;

public:
	Rectangle();
	Rectangle(int length, int width);
	~Rectangle();

	void set_width(int width);
	void set_length(int height);
	int get_width();
	int get_length();
	int calc_area();
	int calc_perimeter();
};

#endif