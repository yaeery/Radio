#pragma once
#include"Program.h"
class DLL_API Zvezdniyvopros : public Program
{
	string Name;
	string Vedushi;
	string Reiting;
	map < string, vector<string> > Rasspisanie;
public:
	Zvezdniyvopros();
	Zvezdniyvopros(const Zvezdniyvopros& obj);
	~Zvezdniyvopros();
	string Get_Name();
	string Get_Vedushi();
	string Get_Reiting();
	string Get_Days();
	string Get_Time();
	Program* Copy();
	bool Is_Day(BSTR stroka);
	void Programm_Days(vector<int>& Days_Dly_Golosovania);
};

