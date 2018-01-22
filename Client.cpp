#include"Client.h"

void Client::getCommand()
{
	getline(cin, command);
}
void Client::execute()
{
	string keyword;
	int starter = command.find_first_of(" ");
	keyword.assign(command, 0, starter);
	string other;
	other.assign(command, starter+1, command.size() - starter-1);
	if (keyword == "open")
	{
		executeOpen(other);
	}
	if (keyword == "save")
	{
		executeSave();
	}
	if (keyword == "saveas")
	{
		executeSaveAs(other);
	}
	if (keyword == "close")
	{
		executeClose();
	}
	if (keyword == "exit")
	{
		executeExit();
	}
	if (svg.isLoaded() && keyword!="close")
	{
		svg.takeAction(keyword,other);
	}
}
void Client::executeOpen(string path)
{
	if (!svg.isLoaded())
	{
		svg.load(path); // the string path still contains the full path
		char dash = (char)92;
		int lastDash = path.find_last_of(dash);
		path.assign(path, lastDash + 1, path.size() - lastDash - 1); // cutting the full path for output purposes
		currentFileName = path;
		if (svg.isLoaded())
			cout << "Successfully opened " << path << endl;
		else
			cout << "NO SUCH FILE" << endl;
	}
	else
	{
		cout << "FIRST CLOSE THE PREVIOUS FILE!!!" << endl;
	}
}
void Client::executeClose()
{
	if (svg.isLoaded())
	{
		svg.unload();
		cout << "Successfully closed " << currentFileName <<endl;
	}
	else
	{
		cout << "BAD COMMAND"<<endl;
	}

}
void Client::executeSave()
{
	if (svg.isLoaded())
	{
		svg.createFile(currentFileName);
		cout << "Successfully saved the changes to " << currentFileName << endl;
	}
	else
	{
		cout << "BAD COMMAND" << endl;
	}
}
void Client::executeSaveAs(string path)
{
	if (svg.isLoaded())
	{
		svg.createFile(path);
		char dash = (char)92;
		int lastDash = path.find_last_of(dash);
		path.assign(path, lastDash + 1, path.size() - lastDash - 1);
		cout << "Successfully saved " << path << endl;
	}
	else
	{
		cout << "BAD COMMAND" << endl;
	}
}
void Client::executeExit()
{
	cout << "Exiting the program...";
	exit(1);
}
