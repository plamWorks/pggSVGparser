#include"Circle.h"
#include"Rectangle.h"
Circle::Circle()
{
	cX = 0;
	cY = 0;
	radius = 0;
}

Circle::Circle(int _cX, int _cY, int _radius, string _color) :radius(_radius),color(_color)
{
	if (_cX < 0)
	{
		_cX = -_cX;
	}
	if (_cY < 0)
	{
		_cY = -_cY;
	}
	cX = _cX;
	cY = _cY;
}

Circle::Circle(const Circle& other)
{
	cX = other.cX;
	cY = other.cY;
	radius = other.radius;
	color = other.color;
}
Circle& Circle::operator=(const Circle& other)
{
	if (this != &other)
	{
		cX = other.cX;
		cY = other.cY;
		radius = other.radius;
		color = other.color;
	}
	return *this;
}
Circle::~Circle()
{

}

int Circle::GetcX(){ return cX; }
int Circle::GetcY(){ return cY; }
int Circle::GetRadius(){ return radius; }
string Circle::GetColor(){ return color; }

void Circle::SetcX(int _cX){ cX = _cX; }
void Circle::SetcY(int _cY){ cY = _cY; }
void Circle::SetRadius(int _radius){ radius= _radius; }
void Circle::SetColor(string _color){ color = _color; }

void Circle::Translate(int Xmovement, int Ymovement)
{
	cX += Xmovement;
	cY += Ymovement;
}

bool Circle::WithinCircle(int otherCX, int otherCY, int otherRadius)
{
	double distanceBetweenCenters = sqrt((cX - otherCX)*(cX - otherCX) + (cY - otherCY)*(cY - otherCY));
	return (otherRadius > distanceBetweenCenters + radius);
}

bool Circle::WithinRectangle(int rectX, int rectY, int rectWidth, int rectHeight)
{
	Rectangle circRec(max(cX - radius,0), cY + radius, 2 * radius, 2 * radius, "red"); // a square, made by the circle
	return circRec.WithinRectangle(rectX, rectY, rectWidth, rectHeight);
}

void Circle::saveAsSVG(ostream& streamName)
{
	streamName << "<circle cx=\"" << cX << "\" cy=\"" << cY << "\" r=\"" << radius << "\" fill=\"" << color << "\" />" << endl;
}

void Circle::Print()
{
	cout << "circle" << " " << cX << " " << cY << " " << radius << " " << color << endl;
}