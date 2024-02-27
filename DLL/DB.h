#pragma once
#include"Program.h"
#include"Podimniki.h"
#include"Classika.h"
#include"Kniga.h"
#include"Music.h"
#include"Novosti.h"
#include"Sport.h"
#include"Zvezdniyvopros.h"
class DLL_API DB
{
	vector<Program*> Vector;
public:
	vector<Program*> Get_Vec();
	void Set_Vec();
	DB();
	~DB();
	void Sort_Name();
	void Sort_Vedushi();
	void Sort_Reiting_Rize();
	void Sort_Reiting_Drop();
	DB(const DB& obj);
	DB* Copy();
	DB operator=(DB& obj);
};

