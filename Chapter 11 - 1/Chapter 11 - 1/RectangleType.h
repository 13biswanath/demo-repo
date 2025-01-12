#ifndef RECTANGLETYPE_H
#define RECTANGLETYPE_H

#include <iostream>
using namespace std;

class rectangleType {
protected:
	double length;
	double width;


public:
	//de constr
	rectangleType() : length(0.0), width(0.0) {}

	//para
	rectangleType(double l, double w) : length(l), width(w) {}
	
	// Set dimensions
	void setDimension(double l, double w) {
		length = l;
		width = w;
	}
	
	
	//Accessor
	double getLength() const { return length; }
	double getWidth() const { return width;  }

	//cal
	double area() const {
		return length * width;
	}
	double perimeter() const {
		return 2 * (length + width);
	}

	void print() const {
		cout << "Rectangle: Length = " << length << ", Width = " << width << ": Area = " << area() << ", Perimeter = " << perimeter() << endl;
	}
};

#endif