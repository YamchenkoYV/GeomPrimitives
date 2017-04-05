#ifndef GEOMBODY_HPP
#define GEOMBODY_HPP
/*
Interface for geometric bodies implementations
*/

#include <iostream>

class GeomBody {
public:
	virtual ~GeomBody(){}

	//Get the primitive volume
	virtual double GetVolume() = 0;

	//Print the primitive state
	virtual void PrintState() = 0;

	//Make the copy of itself in dynamic memory and return the pointer to 
	//this copy
	virtual GeomBody* MakeCopy() = 0;

	virtual void Setlength(double l) {
		if (l <= 0) {
			std::cout << "Error while setting the primitive parameters: values must be more than 0" << std::endl;
			return;
		}
		_length = l; 
	}
	virtual void SetWidth(double w) {
		if (w <= 0) {
			std::cout << "Error while setting the primitive parameters: values must be more than 0" << std::endl;
			return;
		}
		_width = w; 
	}
	virtual void SetHeight(double h) {
		if (h <= 0) {
			std::cout << "Error while setting the primitive parameters: values must be more than 0" << std::endl;
			return;
		}
		_height = h; 
	}

	double Getlength() { return _length; }
	double GetWidth() { return _width; }
	double GetHeight() { return _height; }

protected:
	double _length;
	double _width;
	double _height;
};

#endif// GEOMBODY_HPP
