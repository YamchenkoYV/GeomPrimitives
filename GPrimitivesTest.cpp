/*There is a file to test my classes*/
#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <exception>
#include "GeomPrimitives.hpp"
#include "MyLists.hpp"

enum Commands { addElement,
				addMultiple,
				printList,
				quit,
				help };

enum Primitives { _Cylinder,
				  _RectBlock,
				  _Cube,
				  _Pyramid };

std::map<std::string, Primitives> prmtvNames;
std::map<std::string, Commands> cmdNames;

MyDerivedList myList;

//The support method to get the positive value
template<typename T>
T GetNumber() {
	T value = 0;
	while (! (std::cin >> value) || value <= 0) {
		std::cout << "Wrong value: Value should be real number and more than zero. Try again to input the value, please" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore();
	return value;
}

//The method to add one geometric primitive to the list
void addElem() {
	std::cout << "Input the primitive class to add, please \n\t(Cylinder, RectBlock, Cube or Pyramid)" << std::endl;
	std::string prmtvStr;
	Primitives prmtv;
	getline(std::cin, prmtvStr);

	try {
		prmtv = prmtvNames.at(prmtvStr);
	} catch(std::exception e){
		std::cout << "No primitive with such a name. Try again." << std::endl;
		return;
	}

	switch ( prmtv )
	{
	case _Cylinder: {
		double h, d;
		std::cout << "Input cylinder's height, please" << std::endl;
		h = GetNumber<double>();
		std::cout << "Input cylinder's diameter, please" << std::endl;
		d = GetNumber<double>();
		myList.push_back(new Cylinder(h, d));
		break;
	}
	case _RectBlock: {
		double l, w, h;
		std::cout << "Input rectangle block's length, please" << std::endl;
		l = GetNumber<double>();
		std::cout << "Input rectangle block's width, please" << std::endl;
		w = GetNumber<double>();
		std::cout << "Input rectangle block's height, please" << std::endl;
		h = GetNumber<double>();
		myList.push_back(new RectBlock(l, w, h));
		break; 
	}
	case _Cube: {
		double l;
		std::cout << "Input cube's edge length, please" << std::endl;
		l = GetNumber<double>();
		myList.push_back(new Cube(l));
		break;
	}
	case _Pyramid: {
		double l, w, h;
		std::cout << "Input pyramid's length, please" << std::endl;
		l = GetNumber<double>();
		std::cout << "Input pyramid's width, please" << std::endl;
		w = GetNumber<double>();
		std::cout << "Input pyramid's height, please" << std::endl;
		h = GetNumber<double>();
		myList.push_back(new Pyramid(l, w, h));
		break;
	}
	default:
		break;
	}
	std::cout << "Primitive was added" << std::endl;
}

//The method to add multiple primitives to the list
void addMultipleElem() {
	std::cout << "Input the primitive class to add, please \n\t(Cylinder, RectBlock, Cube or Pyramid)" << std::endl;
	std::string prmtvStr;
	Primitives prmtv;
	bool errFlag;
	getline(std::cin, prmtvStr);

	try {
		prmtv = prmtvNames.at(prmtvStr);
	}
	catch (std::exception e) {
		std::cout << "No primitive with such a name. Try again." << std::endl;
		return;
	}

	switch (prmtv)
	{
	case _Cylinder: {
		double h, d;
		int m;
		std::cout << "Input cylinder's height, please" << std::endl;
		h = GetNumber<double>();
		std::cout << "Input cylinder's diameter, please" << std::endl;
		d = GetNumber<double>();
		std::cout << "Input the number of elements after those the primitive copies should be added, please" << std::endl;
		m = GetNumber<int>();
		errFlag = myList.addMultiCopies(new Cylinder(h, d), m);
		break;
	}
	case _RectBlock: {
		double l, w, h;
		int m;
		std::cout << "Input rectangle block's length, please" << std::endl;
		l = GetNumber<double>();
		std::cout << "Input rectangle block's width, please" << std::endl;
		w = GetNumber<double>();
		std::cout << "Input rectangle block's height, please" << std::endl;
		h = GetNumber<double>();
		std::cout << "Input the number of elements after those the primitive copies should be added, please" << std::endl;
		m = GetNumber<int>();
		errFlag = myList.addMultiCopies(new RectBlock(l, w, h), m);
		break;
	}
	case _Cube: {
		double l;
		int m;
		std::cout << "Input cube`s edge length, please" << std::endl;
		l = GetNumber<double>();
		std::cout << "Input the number of elements after those the primitive copies should be added, please" << std::endl;
		m = GetNumber<int>();
		errFlag	= myList.addMultiCopies(new Cube(l), m);
		break;
	}
	case _Pyramid: {
		double l, w, h;
		int m;
		std::cout << "Input pyramid's length, please" << std::endl;
		l = GetNumber<double>();
		std::cout << "Input pyramid's width, please" << std::endl;
		w = GetNumber<double>();
		std::cout << "Input pyramid's height, please" << std::endl;
		h = GetNumber<double>();
		std::cout << "Input the number of elements after those the primitive copies should be added, please" << std::endl;
		m = GetNumber<int>();
		errFlag = myList.addMultiCopies(new Pyramid(l, w, h), m);
		break;
	}
	default:
		break;
	}
	if(errFlag)
		std::cout << "Primitives was added" << std::endl;
	else
		std::cout << "Primitives wasn't added" << std::endl;
}

//The initialization of the map containers
void Initialization() {

	prmtvNames = { { "Cylinder", _Cylinder },
				   { "RectBlock", _RectBlock },
				   { "Cube", _Cube },
				   { "Pyramid", _Pyramid } };

	cmdNames = { { "add", addElement },
				 { "addMultiple", addMultiple },
				 { "printList", printList },
				 { "quit", quit },
				 { "help", help} };
}

//The help information about interface
void PrintHelp() {
	std::cout << "You can use one of the commands below: \n " <<
		"add - to add one of the geometric primitives to the list \n " <<
		"addMultiple - to add copy of one of the geometric primitives to the list after every 'n' elements \n " <<
		"printList - to print objects that list contains with their states \n " <<
		"quit - to exit the program \n " <<
		"help - to call this help again" << std::endl << std::endl;
}

int main() {

	Initialization();
	PrintHelp();
	std::string cmdStr;
	bool exitFlag = true;
	Commands cmd;

	while (exitFlag)
	{
		std::cout << "\nInput the command, please:" << std::endl;
		
		getline(std::cin, cmdStr);
		
		try {
			cmd = cmdNames.at(cmdStr);
		}
		catch (std::exception e) {
			std::cout << "Unknown command. Try again, please." << std::endl;
			continue;
		}

		switch (cmd)
		{
		case addElement:
			addElem();
			break;
		case addMultiple:
			addMultipleElem();
			break;
		case printList:
			myList.PrintGBodiesStates();
			break;
		case help:
			PrintHelp();
			break;
		case quit:
			exitFlag = false;
			break;
		default:
			break;
		}
		cmdStr.clear();
	}

	return 0;
}