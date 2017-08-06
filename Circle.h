#ifndef Circle_H
#define Circle_H
#include<iostream>
#include<string>
#include<algorithm>
#include"Figure.h"
using namespace std;
class Circle: public Figure
{
private:
	int cX;
	int cY;
	int radius;
	string color;
public:
	Circle();
	//Default constructor
	
	Circle(int, int, int, string);
	//Overload constructor

	Circle(const Circle&);
	//Copy constructor

	Circle& operator =(const Circle&);
	// Operator = for objects of type circle

	~Circle();
	//Destructor

	int GetcX();
	//GetcX - returns the X coordinate of the center

	int GetcY();
	//GetcY - returns the Y coordinate of the center

	int GetRadius();
	//GetRaius - returns the radius of the circle
	
	string GetColor();
	//GetColor - returns the color of the circle

	string getType(){ return "circle"; }
	//getType - returns a string containing the type 

	void SetcX(int);
	//SetcX -  sets the X coordinate of the center
	//@param int - new X coordinate of the center

	void SetcY(int);
	//SetcX -  sets the Y coordinate of the center
	//@param int - new Y coordinate of the center

	void SetRadius(int);
	//SetRadius -  sets the radius of the circle
	//@param int - new radius of the circle

	void SetColor(string);
	//SecColor - sets the color of the circle
	//@param string - new color of the circle
	
	void Translate(int Xmovement, int Ymovement);
	//Translate - translates the circle horizontally and vertically
	//@param Xmovement - horizontal offset
	//@param Ymovement - vertical offset

	bool WithinCircle(int otherCX, int otherCY, int otherRadius);
	//WithinCircle - Returns 1 if the cirle is inside another circle and 0 if it isnt.
	//The data for the second cirle is passed as parameters
	//@param otherCX - The X coordinate of the center for 2nd circle
	//@param otherCY - The Y coordinate of the center for 2nd circle
	//@param otherRadius - The radius of the  2nd circle
	bool WithinRectangle(int rectX, int rectY, int rectWidth, int rectHeight);
	//WithinRectangle - Returns 1 if the circle is inside a rectangle and 0 if it isnt.
	//The data for the rectangle is passed as parameters
	//@param rectX - X coordinate of the bottom left corner of the rectangle
	//@param rectY - Y coordinate of the bottom left corner of the rectangle
	//@param rectWidth - width of the rectangle
	//@param rectHeight - height of the rectangle

	void saveAsSVG(ostream& streamName);
	//saveAsSVG - Saves the circle as SVG code in a SVG file
	//@param streamName - the stream for the file

	void Print();
	//Print - Prints the elements of a circle

};
#endif