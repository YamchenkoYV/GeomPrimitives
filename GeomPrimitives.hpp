#ifndef GEOMPRIMITIVES_HPP
#define GEOMPRIMITIVES_HPP

/*The all geometric primitives classes*/

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "GeomBody.hpp"


	/*Cylinder primitive*/
class Cylinder : public GeomBody {
public:
	/*
	* Cylinder constructor
	* diam - cylinder diameter
	* h - cylinder height
	*/
	Cylinder(double h, double diam) {
		if (h <= 0 || diam <= 0) {
			std::cout << "Error while primitive creating: values must be more than 0" << std::endl;
			return;
		}
		Setlength(diam);
		_height = h;
	}

	double GetVolume() {
		return M_PI * radius * radius * _height;
	}

	void Setlength(double l) {
		if (l <= 0) {
			std::cout << "Error while setting the primitive parameters: values must be more than 0" << std::endl;
			return;
		}
		_length = l;
		_width = l;
		radius = l / 2.0;
	}

	void SetWidth(double w) {
		Setlength(w);
	}

	void PrintState() {
		std::cout << "Cylinder:\n " <<
			"\tRadius: " << radius <<
			"\tHeight: " << _height <<
			"\tVolume: " << GetVolume() << std::endl;
	}

	GeomBody* MakeCopy() {
		return new Cylinder(_height, _width);
	}

private:
	double radius;
};

	/*Parallelepiped primitive*/
class RectBlock : public GeomBody {
public:
	/*
	* Parallelepiped constructor
	* l - parallelepiped length
	* w - parallelepiped width
	* height - parallelepiped height
	*/
	RectBlock(double l, double w, double h) {
		if (l <= 0 || w <= 0 || h <= 0) {
			std::cout << "Error while primitive creating: values must be more than 0" << std::endl;
			return;
		}
		_length = l;
		_width = w;
		_height = h;
	}

	double GetVolume() {
		return 	_length * _width * _height;
	}

	void PrintState() {
		std::cout << "Rectangle block:\n " <<
			"\tlength: " << Getlength() <<
			"\tWidth: " << GetWidth() <<
			"\tHeight: " << GetHeight() <<
			"\tVolume: " << GetVolume() << std::endl;
	}

	GeomBody* MakeCopy() {
		return new RectBlock(_length, _width, _height);
	}
};

	/*Cube primitive*/
class Cube : public RectBlock {
public:
	/*
	* Cube constructor
	* l - cube edges length
	*/
	Cube(double l) : RectBlock(l, l, l) {}

	void Setlength(double l) {
		if (l <= 0) {
			std::cout << "Error while setting the primitive parameters: values must be more than 0" << std::endl;
			return;
		}
		_length = l;
		_width = l;
		_height = l;
	}

	void SetWidth(double w) {
		Setlength(w);
	}

	void SetHeight(double h) {
		Setlength(h);
	}

	void PrintState() {
		std::cout << "Cube:\n " <<
			"\tlength: " << Getlength() <<
			"\tWidth: " << GetWidth() <<
			"\tHeight: " << GetHeight() <<
			"\tVolume: " << GetVolume() << std::endl;
	}

	GeomBody* MakeCopy() {
		return new Cube(_length);
	}
};

	/*Pyramid primitive*/
class Pyramid : public GeomBody {
	public: 
	/*
	* Pyramid constructor
	* l - pyramid length
	* w - pyramid width
	* height - pyramid height
	*/
	Pyramid(double l, double w, double h) {
		if (l <= 0 || w <= 0 || h <= 0) {
			std::cout << "Error while primitive creating: values must be more than 0" << std::endl;
			return;
		}
		_length = l;
		_width = w;
		_height = h;
	}

	double GetVolume() {
		return 	(1.0 / 3.0) *_length * _width * _height;
	}

	void PrintState() {
		std::cout << "Pyramid:\n " <<
			"\tlength: " << Getlength() <<
			"\tWidth: " << GetWidth() <<
			"\tHeight: " << GetHeight() <<
			"\tVolume: " << GetVolume() << std::endl;
	}

	GeomBody* MakeCopy() {
		return new Pyramid(_length, _width, _height);
	}
};

#endif// GEOMPRIMITIVES_HPP