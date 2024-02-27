#include "DB.h"
DB::DB() {}
DB::~DB()
{
	for (int i = 0; i < Vector.size(); i++)
	{
		delete Vector[i];
	}
}
DB::DB(const DB& obj)
{
	for (int i = 0; i < Vector.size(); i++)
	{
		Vector.push_back(obj.Vector[i]->Copy());
	}
}
vector<Program*> DB::Get_Vec()
{
	return Vector;
}
void DB::Set_Vec()
{
	Vector.push_back(new Podimniki());
	Vector.push_back(new Novosti());
	Vector.push_back(new Kniga());
	Vector.push_back(new Music());
	Vector.push_back(new Zvezdniyvopros());
	Vector.push_back(new Classika());
	Vector.push_back(new Sport());
}
void DB::Sort_Name()
{
	sort(Vector.begin(), Vector.end(), [](Program* first, Program* second) {return first->Get_Name() < second->Get_Name(); });
}
void DB::Sort_Vedushi()
{
	sort(Vector.begin(), Vector.end(), [](Program* first, Program* second) {if (first->Get_Vedushi() == "")return first->Get_Vedushi() > second->Get_Vedushi(); if (second->Get_Vedushi() == "")return first->Get_Vedushi() > second->Get_Vedushi(); else return first->Get_Vedushi() < second->Get_Vedushi(); });
}
void DB::Sort_Reiting_Rize()
{
	sort(Vector.begin(), Vector.end(), [](Program* first, Program* second) {return first->Get_Reiting() < second->Get_Reiting(); });
}
void DB::Sort_Reiting_Drop()
{
	sort(Vector.begin(), Vector.end(), [](Program* first, Program* second) {return first->Get_Reiting() > second->Get_Reiting(); });
}
DB* DB::Copy()
{
	return new DB(*this);
}
DB DB::operator=(DB& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	for (vector<Program*> ::iterator it = Vector.begin(); it != Vector.end(); ++it)
	{
		delete (*it);
	}
	Vector.clear();
	for (vector<Program*> ::iterator it = obj.Vector.begin(); it != obj.Vector.end(); ++it)
	{
		Vector.push_back((*it)->Copy());

	}
}