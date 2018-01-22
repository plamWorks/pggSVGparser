#include"Figure.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Line.h"
Figure* Figure::factory(string name,string line)
{
	if (name == "<rect")
	{
		int RecX, RecY, RecW, RecH;
		string RecColor;
		int position = 0;
		int counter = 0;
		int quotesPositions[20];
		int quotesCounter = 0;
		while (position<line.size())
		{
			if (line[position] == '"')
			{
				quotesPositions[quotesCounter] = position;
				quotesCounter++;
			}
			position++;
		}
		string temp;
		temp.assign(line, quotesPositions[0] + 1, quotesPositions[1] - quotesPositions[0] - 1);
		RecX = stoi(temp);
		temp.assign(line, quotesPositions[2] + 1, quotesPositions[3] - quotesPositions[2] - 1);
		RecY = stoi(temp);
		temp.assign(line, quotesPositions[4] + 1, quotesPositions[5] - quotesPositions[4] - 1);
		RecW = stoi(temp);
		temp.assign(line, quotesPositions[6] + 1, quotesPositions[7] - quotesPositions[6] - 1);
		RecH = stoi(temp);
		RecColor.assign(line, quotesPositions[8] + 1, quotesPositions[9] - quotesPositions[8] - 1);
		return new Rectangle(RecX, RecY, RecW, RecH, RecColor);
	}	
	if (name == "<circle")
	{
		int CircleX, CircleY, CircleRadius;
		string CircleColor;
		int position = 0;
		int counter = 0;
		int quotesPositions[20];
		int quotesCounter = 0;
		while (position<line.size())
		{
			if (line[position] == '"')
			{
				quotesPositions[quotesCounter] = position;
				quotesCounter++;
			}
			position++;
		}
		string temp;
		temp.assign(line, quotesPositions[0] + 1, quotesPositions[1] - quotesPositions[0] - 1);
		CircleX = stoi(temp);
		temp.assign(line, quotesPositions[2] + 1, quotesPositions[3] - quotesPositions[2] - 1);
		CircleY = stoi(temp);
		temp.assign(line, quotesPositions[4] + 1, quotesPositions[5] - quotesPositions[4] - 1);
		CircleRadius = stoi(temp);
		CircleColor.assign(line, quotesPositions[6] + 1, quotesPositions[7] - quotesPositions[6] - 1);
		return new Circle(CircleX, CircleY, CircleRadius, CircleColor);
	}
		
	if (name == "<line")
	{
		int X1, Y1, X2, Y2;
		string LineColor;
		int position = 0;
		int counter = 0;
		int quotesPositions[20];
		int quotesCounter = 0;
		while (position<line.size())
		{
			if (line[position] == '"')
			{
				quotesPositions[quotesCounter] = position;
				quotesCounter++;
			}
			position++;
		}
		string temp;
		temp.assign(line, quotesPositions[0] + 1, quotesPositions[1] - quotesPositions[0] - 1);
		X1 = stoi(temp);
		temp.assign(line, quotesPositions[2] + 1, quotesPositions[3] - quotesPositions[2] - 1);
		Y1 = stoi(temp);
		temp.assign(line, quotesPositions[4] + 1, quotesPositions[5] - quotesPositions[4] - 1);
		X2 = stoi(temp);
		temp.assign(line, quotesPositions[6] + 1, quotesPositions[7] - quotesPositions[6] - 1);
		Y2 = stoi(temp);
		LineColor.assign(line, quotesPositions[8] + 1, quotesPositions[9] - quotesPositions[8] - 1);
		return new Line(X1, Y1, X2, Y2, LineColor);
	}
	else
	{
		cout << "Unable to create figure of the requested type!"<<endl;
	}
}
Figure* Figure::factory(string line)
{
	int starter = line.find_first_of(" ");
	string beginning;
	beginning.assign(line, 0, starter);
	line.assign(line, starter, line.size() - starter);
	if (beginning == "rectangle")
	{
		int RecX, RecY, RecW, RecH;
		string RecColor;
		string temp;
		int spacePositions[6];
		int spaceCounter = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
			{
				spacePositions[spaceCounter] = i;
				spaceCounter++;
			}
		}
		temp.assign(line, spacePositions[0] + 1, spacePositions[1] - spacePositions[0 - 1]);
		RecX = stoi(temp);
		temp.assign(line, spacePositions[1] + 1, spacePositions[2] - spacePositions[1] - 1);
		RecY = stoi(temp);
		temp.assign(line, spacePositions[2] + 1, spacePositions[3] - spacePositions[2] - 1);
		RecW = stoi(temp);
		temp.assign(line, spacePositions[3] + 1, spacePositions[4] - spacePositions[3] - 1);
		RecH = stoi(temp);
		RecColor.assign(line, spacePositions[4] + 1, spacePositions[5] - spacePositions[4] - 1);
		cout << "Successfuly created " << beginning<<endl;
		return new Rectangle(RecX, RecY, RecW, RecH, RecColor);
	}
	if (beginning == "line")
	{
		int X1, Y1, X2, Y2;
		string LineColor;

		string temp;
		int spacePositions[6];
		int spaceCounter = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
			{
				spacePositions[spaceCounter] = i;
				spaceCounter++;
			}
		}
		temp.assign(line, spacePositions[0]+1, spacePositions[1] - spacePositions[0-1]);
		X1 = stoi(temp);
		temp.assign(line, spacePositions[1]+1, spacePositions[2] - spacePositions[1]-1);
		Y1 = stoi(temp);
		temp.assign(line, spacePositions[2]+1, spacePositions[3] - spacePositions[2]-1);
		X2 = stoi(temp);
		temp.assign(line, spacePositions[3]+1, spacePositions[4] - spacePositions[3]-1);
		Y2 = stoi(temp);
		LineColor.assign(line, spacePositions[4] + 1, spacePositions[5] - spacePositions[4] - 1);
		cout << "Successfuly created " << beginning << endl;
		return new Line(X1, Y1, X2, Y2, LineColor);
	}
	if (beginning == "circle")
	{
		int CircleX, CircleY, CircleRadius;
		string CircleColor;
		
		string temp;
		int spacePositions[5];
		int spaceCounter = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
			{
				spacePositions[spaceCounter] = i;
				spaceCounter++;
			}
		}
		temp.assign(line, spacePositions[0] + 1, spacePositions[1] - spacePositions[0 - 1]);
		CircleX = stoi(temp);
		temp.assign(line, spacePositions[1] + 1, spacePositions[2] - spacePositions[1] - 1);
		CircleY = stoi(temp);
		temp.assign(line, spacePositions[2] + 1, spacePositions[3] - spacePositions[2] - 1);
		CircleRadius = stoi(temp);
		CircleColor.assign(line, spacePositions[3] + 1, spacePositions[4] - spacePositions[3] - 1);
		cout << "Successfuly created " << beginning << endl;
		return new Circle(CircleX, CircleY, CircleRadius, CircleColor);
	}
	else
	{
		cout << "Unable to create figure of the requested type!" << endl;
	}
}
