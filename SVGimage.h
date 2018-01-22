#ifndef SVGimage_H
#define SVGimage_H
#include"Figure.h"
#include"Rectangle.h"
#include"Circle.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class SVGimage
{
private:
	vector<Figure*> figures;
	bool loaded;
public:
	SVGimage();
	void takeAction(string,string);
	bool isLoaded(){ return loaded; };
	void unload(){ loaded = false; }
	void load(string);
	void createFile(string);
	void print();
	void add(Figure*);
	void erase(int index);
	void translate(int hor, int ver);
	void translate(int index, int hor, int ver);
	void withinRect(int,int,int,int);
	void withinCircle(int, int, int);
};
#endif