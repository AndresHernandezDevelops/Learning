// Learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include "Rectangle.h"
#include "Child.h"

using namespace std;

void casting() {
	float number = float(10) / 3;
	cout << number << endl;
}

/*
char* is a pointer that points to a location containing a value of type char that can also be changed. The pointer's value can be changed, i.e. the pointer can be modified to point to different locations.
const char* is a pointer, who's value can be also changed, that points to a location containing a value of type char that cannot be changed.

or in other words...
const char * means "pointer to an unmodifiable character." It's usually used for strings of characters that shouldn't be modified.
*/
void characterArrays() {
	char n = 'g';
	const char * name = "Duncan";
	char name2[7] = "jordan";
	cout << name << ", " << name2 << endl;
}

void randomNumbers() {
	srand(time(NULL));
	int random = rand() % 100; //generates a random number between 0 or 1 and 100, the seed fed to it is the time in seconds.
	cout << random << endl;
}

int quadratic(int a, int b, int c, int multi) {
	int result;
	result = (-b + multi * sqrt(b*b - 4 * c*a)) / (2 * a);
	return result;
}

void functions() {
	int a = 10, b, c;
	cout << "enter a: ";
	cin >> a;
	cout << "enter b: ";
	cin >> b;
	cout << "enter c: ";
	cin >> c;

	int pZero = quadratic(a, b, c, 1), nZero = quadratic(a, b, c, -1);

	cout << "your two zeroes are: " << pZero << " and " << nZero << endl;
}

void times_ten_pointer(int* a) {
	*a *= 10;
}

void times_ten_reference(int& a) {
	a *= 10;
}


/*
References are often confused with pointers but three major differences between references and pointers are −

- You cannot have NULL references. You must always be able to assume that a reference is connected to a legitimate piece of storage.
- Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.
- A reference must be initialized when it is created. Pointers can be initialized at any time.
*/
void pointersVsReference() {
	int a = 10;
	int *p = &a, &ra = a; //p is a pointer to p, ra is a reference to a, neither serves a purpose in this method.
	cout << "a before pointer mult: " << a << endl;

	//times_ten_pointer(&a);	// alternative
	times_ten_pointer(p);
	cout << "a after pointer mult, before reference mult: " << a << endl;

	//times_ten_reference(a);	//alternative
	times_ten_reference(ra);
	cout << "a after reference mult: " << a << endl;
}

void pointerArithmetic() {
	int numbers[] = { 1,10,100 };
	cout << &(numbers[0]) << " -> " << *(&(numbers[0])) << endl;
	cout << &(numbers[0]) + 1 << " -> " << *(numbers + 1) << endl;
	cout << &(numbers[1]) + 1 << " -> " << *(numbers + 2) << endl;
}

void dynamicMemory() {
	int *p;
	p = new int;

	*p = 10;
	*p += 50;
	cout << *p << endl;
	delete p;	//deallocating this dynamically allocated memory is very important to avoid memory leaks.

	//----------------------------------

	int size;
	cout << "please enter the size for your array -> ";
	cin >> size;
	int *numbers = new int[size];

	cout << "multiples of 7: " << endl;
	for (int i = 0; i < size; i++) {
		numbers[i] = (i + 1) * 7;
		cout << "element " << i << " -> " << numbers[i] << endl;
	}

	delete[]numbers;

	// ----------------------------------

	char *name = new char[6];
	name[0] = 'L';
	name[1] = 'e';
	name[2] = 'w';
	name[3] = 'i';
	name[4] = 's';
	name[5] = '\0';

	cout << "your name is " << name << endl;

	delete []name;

	name = new char[5];
	name[0] = 'L';
	name[1] = 'u';
	name[2] = 'i';
	name[3] = 's';
	name[4] = '\0';

	cout << "your new name is " << name << endl;

	delete[]name;

}

void classes() {
	Rectangle r(14, 15);
	int length, width;
	cout << "enter width - > ";
	cin >> width;
	cout << "enter length -> ";
	cin >> length;
	r.set_length(length);
	r.set_width(width);
	cout << "the area of the rectangle is " << r.calc_area() << " and the perimeter of your rectangle is: " << r.calc_perimeter() << endl;
}

void operatorInt() {
	Rectangle r(14, 15);
	int n = r;
	cout << "operator int returns: " << n << "." << endl;
}

void operatorOverloading(){
	Rectangle r(10, 15);
	Rectangle r2(20, 30);
	r = r + r2;
	cout << "new length -> " << r.get_length() << ", width -> " << r.get_width() << endl;

	r = r * r2;
	cout << "new length -> " << r.get_length() << ", width -> " << r.get_width() << endl;

	r = r / r2;
	cout << "new length -> " << r.get_length() << ", width -> " << r.get_width() << endl;
}

void inheritance() {
	Child number(24, "black");
	number.display();
	number.override();
}

class enemy {
protected:
	int hp = 100;
public:
	virtual void attack() {
		cout << "the enemy attacks!!" << endl;
		hp -= 20;
	}	

	virtual void requestHp() = 0;
};

class zombie : public enemy{
public:
	/*void attack() {
		cout << "the monster attacks!!" << endl;
		hp -= 30;
	}*/

	void requestHp() {
		cout << "the hp is " << hp << endl;;
	}
};

class witch : public enemy {
public:
	void attack() {
		cout << "the witch attacks!!" << endl;
		hp -= 20;
	}

	void requestHp() override{
		cout << "the hp is " << hp << endl;
	}
};

void polymorphism() {
	witch w;
	zombie z;
	enemy *wp = &w;
	enemy *zp = &z;
	wp->attack();
	wp->requestHp();
	zp->attack();
	zp->requestHp();
}

//each function call represents a new tool i've learned about the language
int main()
{
	//casting();
	//characterArrays();
	//randomNumbers();
	//functions();
	//pointersVsReference();
	//pointerArithmetic();
	//dynamicMemory();
	//classes();	
	//operatorInt();
	//operatorOverloading();
	//inheritance();
	polymorphism();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
