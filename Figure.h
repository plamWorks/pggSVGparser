#ifndef Figure_H
#define Figure_H

#include<iostream>
#include<string>
using namespace std;
class Figure{
public:
	static Figure* factory(string name,string line); // THIS FACTORY IS USED TO READ OBJECTS FROM SVG FILE
	//Returns a  pointer to a new figure of the type requested by the parameter 
	//@param name - specifies the type of the figure(e.g. rectangle)
	//@param line - a line of text containing the characteristics of the figure (e.g color)

	static Figure* factory(string line); // THIS FACTORY IS USED TO READ OBJECTS FROM THE CONSOLE
	//Returns a  pointer to a new figure of the type requested by the parameter 
	//@param name - specifies the type of the figure(e.g. rectangle)

	virtual void Translate(int, int) = 0;
	// moves the figure vertically and horizontally

	virtual bool WithinCircle(int, int, int) = 0;
	// Returns 1 if the figure  is inside a circle and 0 if it isnt.

	virtual bool WithinRectangle(int, int, int, int) = 0;
	// Returns 1 if the figure  is inside a rectangle and 0 if it isnt.

	virtual void Print() = 0;
	// Prints the elements of the figure
	virtual void saveAsSVG(ostream&) = 0;
	// Saves a figure as SVG code in a SVG file

	virtual string getType()=0;
	// returns the type of the figure pointed
};
#endif