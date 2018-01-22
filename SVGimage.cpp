#include"SVGimage.h"
#include"Rectangle.h"
#include"Line.h"
#include"Circle.h"
#include"Figure.h"
#include<fstream>
#include<string>
SVGimage::SVGimage()
{
	loaded = false;
}
void SVGimage::load(string filename)
{
	figures.clear();
	ifstream in(filename);
	if (!in)
	{
		return;
	}
	string line;
	do{
		getline(in, line);
	} while (line!="<svg>");
	// main part of the file is reached here, we start to read figures
	getline(in, line);
	while (line != "</svg>")
	{
		while (line[0] == ' ')
		{
			line.erase(0, 1);
		}
		int starter = line.find_first_of(" ");
		string beginning;
		beginning.assign(line, 0, starter);
		line.assign(line, starter, line.size()-starter);
		figures.push_back(Figure::factory(beginning,line));
		getline(in, line);
	}
	in.close();
	loaded = true;
}

void SVGimage::createFile(string filename)
{
	ofstream out(filename);
	out << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
	out << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n";
	out << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	out << "<svg>\n";
	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->saveAsSVG(out);
	}
	out << "</svg>\n";
}

void SVGimage::print()
{		
	for (int i = 0; i < figures.size(); i++)
	{
		cout << i + 1 << ". ";
		figures[i]->Print();
	}
}

void SVGimage::add(Figure* fig)
{
	figures.push_back(fig);
}
void SVGimage::erase(int index)
{

	figures.erase(figures.begin() + index);

}
void SVGimage::translate(int hor, int ver)
{
	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->Translate(hor, ver);
	}
}
void SVGimage::translate(int index,int hor, int ver)
{

	figures[index]->Translate(hor, ver);
}
void SVGimage::withinRect(int borderX,int borderY,int borderW,int borderH)
{
	bool isThereAny = false;
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->WithinRectangle(borderX, borderY, borderW, borderH))
		{
			isThereAny = true;
			cout << i + 1 << ". ";
			figures[i]->Print();
		}
	}
	if (!isThereAny)
	{
		cout << "No figures are located in rectangle " << borderX << " " << borderY << " " << borderW << " " << borderH << endl;
	}
}
void SVGimage::withinCircle(int bordercX,int bordercY,int borderCradius)
{
	bool isThereAny = false;
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->WithinCircle(bordercX, bordercY, borderCradius))
		{
			isThereAny = true;
			cout << i + 1<<". ";
			figures[i]->Print();
		}
	}
	if (!isThereAny)
	{
		cout << "No figures are located in circle " << bordercX << " " << bordercY << " " << borderCradius << endl;
	}
}
void SVGimage::takeAction(string keyword, string other)
{
	if (keyword == "print")
	{
		print();
	}
	if (keyword == "create")
	{
		figures.push_back(Figure::factory(other));
	}
	if (keyword == "erase")
	{
		int index = stoi(other);
		if (index<1 || index>figures.size() + 1)
		{
			cout << "There is no figure number " << index << endl;
		}
		else
		{
			string type = figures[index - 1]->getType();
			erase(index - 1);
			cout << "Erased a " << type << " (" << index << ")" << endl;
		}
	}
	if (keyword == "translate")
	{
		int horizontal=0;
		int vertical=0;
		int starter = other.find_first_of(" ");
		string beginning;
		beginning.assign(other, 0, starter);
		other.assign(other, starter, other.size() - starter);
		if (beginning.size() == 1)     // Translates just one figure
		{
			int index = stoi(beginning);

			int equalSignPos, spacePos;
			string temp;
			
			equalSignPos = other.find_first_of('=');
			spacePos = other.find_first_of(' ');
			temp.assign(other, equalSignPos + 1, spacePos-equalSignPos-1);
			vertical = stoi(temp);


			other.assign(other, equalSignPos + 1, other.size() - equalSignPos - 1);

			equalSignPos = other.find_first_of('=');
			spacePos = other.find_first_of(' ');
			temp.assign(other, equalSignPos + 1, spacePos - equalSignPos - 1);
			horizontal = stoi(temp);
			
			translate(index - 1, horizontal, vertical);
			cout << "Translated " <<"("<<index<<")"<< endl;
		}
		else    // Translates all figures
		{
			int equalSignPos;
			string temp;
			equalSignPos = beginning.find_first_of('=');
			temp.assign(beginning, equalSignPos + 1, beginning.size() - equalSignPos - 1);
			vertical = stoi(temp);

			equalSignPos = other.find_first_of('=');
			temp.assign(other, equalSignPos + 1, other.size() - equalSignPos - 1);
			horizontal = stoi(temp);
			translate(horizontal, vertical);
			cout << "Translated all figures!" << endl;
		}
	}
	if (keyword == "within")
	{
		int starter = other.find_first_of(" ");
		string beginning;
		beginning.assign(other, 0, starter);
		other.assign(other, starter, other.size() - starter);
		if (beginning == "rectangle")
		{
			int borderRecX, borderRecY, borderRecW, borderRecH;
			string temp;
			int spacePositions[5];
			int spaceCounter = 0;
			for (int i = 0; i < other.size(); i++)
			{
				if (other[i] == ' ')
				{
					spacePositions[spaceCounter] = i;
					spaceCounter++;
				}
			}
			temp.assign(other, spacePositions[0] + 1, spacePositions[1] - spacePositions[0 - 1]);
			borderRecX = stoi(temp);
			temp.assign(other, spacePositions[1] + 1, spacePositions[2] - spacePositions[1] - 1);
			borderRecY = stoi(temp);
			temp.assign(other, spacePositions[2] + 1, spacePositions[3] - spacePositions[2] - 1);
			borderRecW = stoi(temp);
			temp.assign(other, spacePositions[3] + 1, spacePositions[4] - spacePositions[3] - 1);
			borderRecH = stoi(temp);
			withinRect(borderRecX, borderRecY, borderRecW, borderRecH);

		}
		if (beginning == "circle")
		{
			int borderCircleX, borderCircleY, borderCircleRadius;
			string temp;
			int spacePositions[4];
			int spaceCounter = 0;
			for (int i = 0; i < other.size(); i++)
			{
				if (other[i] == ' ')
				{
					spacePositions[spaceCounter] = i;
					spaceCounter++;
				}
			}
			temp.assign(other, spacePositions[0] + 1, spacePositions[1] - spacePositions[0 - 1]);
			borderCircleX = stoi(temp);
			temp.assign(other, spacePositions[1] + 1, spacePositions[2] - spacePositions[1] - 1);
			borderCircleY = stoi(temp);
			temp.assign(other, spacePositions[2] + 1, spacePositions[3] - spacePositions[2] - 1);
			borderCircleRadius = stoi(temp);
			withinCircle(borderCircleX, borderCircleY, borderCircleRadius);
		}
	}
}