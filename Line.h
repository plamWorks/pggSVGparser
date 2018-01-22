#ifndef Line_H
#define Line_H
#include<iostream>
#include<string>
#include"Figure.h"
using namespace std;
class Line : public Figure
{
private:
	int x1;
	int y1;
	int x2;
	int y2;
	string color; 
public:
	Line();
	//Default constructor
	Line(int, int, int, int, string);
	//Overload constructor
	Line(const Line& other);
	//Copy constructor
	Line& operator = (const Line& other);
	// Operator = for objects of type Line
	int GetX1();
	//GetX1 - returns the X coordinate of the start of the line
	int GetY1();
	//GetY1 - returns the Y coordinate of the start of the line
	int GetX2();
	//GetX2 - returns the X coordinate of the end of the line
	int GetY2();
	//GetY2 - returns the Y coordinate of the end of the line
	string GetColor();
	//GetColor - returns a string containing the color of the line

	string getType(){ return "line"; }
	//getType - returns a string containing the type 

	void SetX1(int);
	//SetX1 -  sets the X coordinate of the start
	//@param int - new X coordinate of the start
	void SetY1(int);
	//SetY1 -  sets the Y coordinate of the start
	//@param int - new Y coordinate of the start
	void SetX2(int);
	//SetX2 -  sets the X coordinate of the end
	//@param int - new X coordinate of the end
	void SetY2(int);
	//SetY2 -  sets the Y coordinate of the end
	//@param int - new Y coordinate of the end
	void SetColor(string);
	//SetColor - sets the color of the line
	//@param string - new color for the line
	void Translate(int Xmovement, int Ymovement);
	//Translate - translates the line horizontally and vertically
	//@param Xmovement - horizontal offset
	//@param Ymovement - vertical offset
	bool WithinCircle(int circleX, int circleY, int circleRadius);
	//WithinCircle - Returns 1 if the line is inside a circle and 0 if it isnt.
	//The data for the circle is passed as parameters
	//@param circleX - X coordinate of the circle center
	//@param circleY - Y coordinate of the circle center
	//@param circleRadius - radius of the circle
	bool WithinRectangle(int rectX, int rectY, int rectWidth, int rectHeight);
	//WithinRectangle - Returns 1 if the line is inside a rectangle and 0 if it isnt.
	//The data for the rectangle is passed as parameters
	//@param rectX - X coordinate of the bottom left corner of the rectangle
	//@param rectY - Y coordinate of the bottom left corner of the rectangle
	//@param rectWidth - width of the rectangle
	//@param rectHeight - height of the rectangle

	void saveAsSVG(ostream& streamName);
	//saveAsSVG - Saves the line as SVG code in a SVG file
	//@param streamName - the stream for the file

	void Print();
	//Prints the elements of a line
	~Line();
	// Destructor
};
#endif