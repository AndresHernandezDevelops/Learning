#include "pch.h"
#include "Rectangle.h"

/*instead of writing the code blocks for these functions inside the class itself, we can use the Rectangle
namespace to indicate the scope for which the following code belongs to
*/
Rectangle::Rectangle() {
	length = 10;
	width = 15;
}

Rectangle::Rectangle(int length, int width) {
	this->length = length;
	this->width = width;
}

Rectangle::~Rectangle() {
	cout << "destructing the object..." << endl;
}

void Rectangle::set_width(int width) {
	this->width = width;
}

void Rectangle::set_length(int length) {
	this->length = length;
}

int Rectangle::get_length() {
	return this->length;
}

int Rectangle::get_width() {
	return this->width;
}

int Rectangle::calc_area() {
	return length * width;
}

int Rectangle::calc_perimeter() {
	return (length * 2) + (width * 2);
}

Rectangle::operator int() {
	return 7;
}

Rectangle Rectangle::operator *(Rectangle r) {
	this->set_length(this->get_length() * r.get_length());
	this->set_width(this->get_width() * r.get_width());
	return *this;
}

Rectangle Rectangle::operator /(Rectangle r) {
	this->set_length(this->get_length() / r.get_length());
	this->set_width(this->get_width() / r.get_width());
	return *this;
}

Rectangle Rectangle::operator +(Rectangle r) {
	this->set_length(this->get_length() + r.get_length());
	this->set_width(this->get_width() + r.get_width());
	return *this;
}


