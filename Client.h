#ifndef Client_H
#define Client_H
#include"SVGimage.h"
#include<iostream>
#include<string>
using namespace std;
class Client{
private:
	string currentFileName;
	string command;
	SVGimage svg;
	void executeOpen(string);
	void executeClose();
	void executeSave();
	void executeSaveAs(string);
	void executeExit();
public:
	void setCommand(string _c){ command = _c; };
	void getCommand();
	void execute();
	
};
#endif