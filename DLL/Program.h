#pragma once
#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<wtypes.h>
#include<oleauto.h>
#include<algorithm>
#include<string>
#include<comdef.h>
#include<comutil.h>
#include<fstream>
using namespace std;

#define DLL_API __declspec(dllexport)
class DLL_API Program
{
	string Name;
	string Vedushi;
	string Reiting;
	map < string, vector<string> > Rasspisanie;
public:
	Program();
	Program(const Program& obj);
	virtual ~Program();
	virtual string Get_Name();
	virtual string Get_Vedushi();
	virtual string Get_Reiting();
	virtual string Get_Days();
	virtual string Get_Time();
	virtual  Program* Copy();
	virtual bool Is_Day(BSTR stroka);
	virtual void Programm_Days(vector<int>& Days_Dly_Golosovania);

};

