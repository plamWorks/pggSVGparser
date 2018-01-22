#include"Line.h"
Line::Line()
{
	x1 = y1 = x2 = y2 = 0;
}
Line::Line(int _x1, int _y1, int _x2, int _y2, string _color) :  color(_color)
{
	if (_x1 < 0)
	{
		_x1 = -_x1;
	}
	if (_y1 < 0)
	{
		_y1 = -_y1;
	}
	if (_x2 < 0)
	{
		_x2 = -_x2;
	}
	if (_y2 < 0)
	{
		_y2 = -_y2;
	}
	x1 = _x1;
	y1 = _y1;
	x2 = _x2;
	y2 = _y2;
}

Line::Line(const Line& other)
{
	x1 = other.x1;
	y1 = other.y1;
	x2 = other.x2;
	y2 = other.y2;
	color = other.color;
}
Line& Line::operator =(const Line& other)
{
	if (this != &other)
	{
		x1 = other.x1;
		y1 = other.y1;
		x2 = other.x2;
		y2 = other.y2;
		color = other.color;
	}
	return *this;
}
Line::~Line()
{

}
int Line::GetX1(){ return x1; }
int Line::GetY1(){ return y1; }
int Line::GetX2(){ return x2; }
int Line::GetY2(){ return y2; }
string Line::GetColor(){ return color; }

void Line::SetX1(int _x1){ x1 = _x1; }
void Line::SetY1(int _y1){ y1 = _y1; }
void Line::SetX2(int _x2){ x2 = _x2; }
void Line::SetY2(int _y2){ y2 = _y2; }
void Line::SetColor(string _color){ color = _color; }

void Line::Translate(int Xmovement, int Ymovement)
{
	x1 += Xmovement;
	x2 += Xmovement;
	y1 += Ymovement;
	y2 += Ymovement;
}
bool Line::WithinCircle(int circleX, int circleY, int circleRadius)
{
	return ((circleX - x1)*(circleX - x1) + (circleY - y1)*(circleY - y1)) < circleRadius*circleRadius &&
		((circleX - x2)*(circleX - x2) + (circleY - y2)*(circleY - y2)) < circleRadius*circleRadius;
}
bool Line::WithinRectangle(int rectX, int rectY, int rectWidth, int rectHeight)
{
	return x1>rectX && x1<rectX + rectWidth && y1< rectY && y1>rectY - rectHeight &&
		x2>rectX && x2 < rectX + rectWidth && y2< rectY && y2>rectY - rectHeight;
}

void Line::saveAsSVG(ostream& streamName)
{
	streamName << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" stroke=\"" << color << "\" />"<<endl;
}
void Line::Print()
{
	cout << "line" << " " << x1 << " " << y1 << " " << x2 << " " << y2 <<" "<<color<< endl;
}