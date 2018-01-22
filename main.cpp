#include<iostream>
#include"Circle.h"
#include"Rectangle.h"
#include"Line.h"
#include"SVGimage.h"
#include"Client.h"
using namespace std;
int main()
{
	Client c;
	while (1)
	{
		c.getCommand();
		c.execute();
	}

	system("pause");
	return 0;
}