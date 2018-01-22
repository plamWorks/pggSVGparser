#ifndef Rectangle_H
#define Rectangle_H

#include<iostream>
#include<string>
#include"Figure.h"
using namespace std;
class Rectangle : public Figure
{
private:
	int x;
	int y;
	int width;
	int height;
	string color;
public:
	Rectangle();
	//Default constructor

	Rectangle(int, int, int, int, string);
	//Overload constructor

	Rectangle(const Rectangle&);
	//Copy constructor

	Rectangle& operator =(const Rectangle&);
	//Operator = for objects of type rectangle

	~Rectangle();
	//Destructor

	int GetX();
	//Returns the X coordinate of the bottom left corner

	int GetY();
	//Returns the Y coordinate of the bottom left corner

	int GetHeight();
	//Returns the height of the rectangle

	int GetWidth();
	//Returns the width of the rectangle

	string GetColor();
	//Returns the color of the rectangle

	string getType(){ return "rectangle"; }
	//getType - returns a string containing the type 

	void SetX(int);
	//SetX - sets the X coordinate of the bottom left corner
	//@param int - new X coordinate

	void SetY(int);
	//SetX - sets the Y coordinate of the bottom left corner
	//@param int - new Y coordinate

	void SetHeight(int);
	//SetHeight - sets the height of the rectangle
	//@param int - new height

	void SetWidth(int);
	//SetHeight - sets the width of the rectangle
	//@param int - new width
	
	void SetColor(string);
	//SetColor - sets the color of the rectangle
	//@param string - new color

	void Translate(int Xmovement, int Ymovement);
	//Translate - moves the rectangle vertically and horizontally
	//@param Xmovement - horizontal offset
	//@param Ymovement - vertical offset

	bool WithinCircle(int circleX, int circleY, int circleRadius);
	//WithinCircle - Returns 1 if the rectangle  is inside a circle and 0 if it isnt.
	//The data for the circle is passed as parameters
	//@param circleX - X coordinate of the circle center
	//@param circleY - Y coordinate of the circle center
	//@param circleRadius - radius of the circle

	bool WithinRectangle(int otherX, int otherY, int otherWidth, int otherHeight);
	//WithinRectangle - Returns 1 if the rectangle  is inside another rectangle and 0 if it isnt.
	//The data for the second rectangle is passed as parameters
	//@param otherX - X coordinate of the bottom left corner of the second rectangle
	//@param otherY - Y coordinate of the bottom left corner of the second rectangle
	//@param otherWidth - width of the second rectangle
	//@param otherHeight - height of the secondrectangle
	
	void saveAsSVG(ostream& streamName);
	//saveAsSVG - Saves the rectangle as SVG code in a SVG file
	//@param streamName - the stream for the file 

	void Print();
	// Prints the elements of the rectangle
};
#endif