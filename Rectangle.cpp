#include"Rectangle.h"

Rectangle::Rectangle()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int _x, int _y, int _width, int _height, string _color)
: width(_width), height(_height), color(_color)
{
	if (_x < 0)
	{
		_x = -_x;
	}
	if (_y < 0)
	{
		_y = -_y;
	}
	x = _x;
	y = _y;
}

Rectangle::Rectangle(const Rectangle& other)
{
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
	color = other.color;
}
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		width = other.width;
		height = other.height;
		color = other.color;
	}
	return *this;
}
Rectangle::~Rectangle()
{

}

int Rectangle::GetX(){ return x; }
int Rectangle::GetY(){ return y; }
int Rectangle::GetHeight(){ return height; }
int Rectangle::GetWidth(){ return width; }
string Rectangle::GetColor(){ return color; }

void Rectangle::SetX(int _x){ x = _x; }
void Rectangle::SetY(int _y){ y = _y; }
void Rectangle::SetHeight(int _height){ height=_height; }
void Rectangle::SetWidth(int _width){ width = _width; }
void Rectangle::SetColor(string _color){ color = _color; }

void Rectangle::Translate(int Xmovement, int Ymovement)
{
	x += Xmovement;
	y += Ymovement;
}

bool Rectangle::WithinCircle(int circleX, int circleY, int circleRadius)
{
	return(((x - circleX)*(x - circleX) + (y - circleY)*(y - circleY) < circleRadius*circleRadius) &&
		((x + width - circleX)*(x + width - circleX) + (y - circleY)*(y - circleY) < circleRadius*circleRadius) &&
		((x - circleX)*(x - circleX) + (y + height - circleY)*(y + height - circleY) < circleRadius*circleRadius) &&
		((x + width - circleX)*(x + width - circleX) + (y + height - circleY)*(y + height - circleY) < circleRadius*circleRadius));
}

bool Rectangle::WithinRectangle(int otherX, int otherY, int otherWidth, int otherHeight)
{
	if (height < otherHeight && width < otherWidth)
	{
		return ((otherY - y + height < otherHeight) && (x-otherX + width < otherWidth));
	}
	return false;
}

void Rectangle::saveAsSVG(ostream& streamName)
{
	streamName << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << color << "\" />" << endl;
}

void Rectangle::Print()
{
	cout << "rectangle " << x << " " << y << " " << width << " " << height << " " << color << endl;
}