#ifndef BOXTYPE_H
#define BOXTYPE_H

#include "rectangleType.h"

class boxType : public rectangleType {
private: 
	double height;

public:
	boxType() : rectangleType(0.0, 0.0), height(0.0) {}

	boxType(double l, double width, double h) : rectangleType(l, w), height(h) {}


	// Set dimensions
	void setDimension(double l, double w, double h) {
		rectangleType::setDimension(l, w);
		height = h;
	}

	double getHeight() const {
		return height;
	}

	double area() const { return 2 * (length * width + width * height + height * length); }

	double volume() const { return length * width * height; }

	void print() const {
		rectangleType::print();
		cout << "Height = " << height
			<< ", Surface area = " << area()
			<< ", Volume = " << volume << endl;
	}

};
#endif
