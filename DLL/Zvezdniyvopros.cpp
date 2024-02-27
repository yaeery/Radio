#include "Zvezdniyvopros.h"
Zvezdniyvopros::Zvezdniyvopros()
{
	Name = "Звездный вопрос";
	Vedushi = "Дмитрий Ануфриев";
	Reiting = "4.9";
	vector<string> Days = {"Суббота","Воскресенье" };
	Rasspisanie.insert(make_pair("10:00 - 12:00", Days));
}
Zvezdniyvopros:: ~Zvezdniyvopros() {}
string Zvezdniyvopros::Get_Name()
{
	return Name;
}
string Zvezdniyvopros::Get_Vedushi()
{
	return Vedushi;
}
string Zvezdniyvopros::Get_Reiting()
{
	return Reiting;
}
string Zvezdniyvopros::Get_Days()
{
	string x;
	map<string, vector<string>> ::iterator first = Rasspisanie.begin();
	x = x + *(first->second.begin()) + " - " + *(--first->second.end());
	return x;
}
string Zvezdniyvopros::Get_Time()
{
	string x;
	map<string, vector<string>> ::iterator first = Rasspisanie.begin();
	x = first->first;
	return x;
}
Program* Zvezdniyvopros::Copy()
{
	return new Zvezdniyvopros(*this);
}
Zvezdniyvopros::Zvezdniyvopros(const Zvezdniyvopros& obj) :Program(obj)
{
	Name = obj.Name;
	Vedushi = obj.Vedushi;
	Reiting = obj.Reiting;
	Rasspisanie = obj.Rasspisanie;
}

bool Zvezdniyvopros::Is_Day(BSTR stroka)
{
	vector<int> Days_Class;
	vector<int> Days_Exe;
	vector<int> Itog;
	map<string, vector<string>>::iterator it = Rasspisanie.begin();
	for (int i = 0; i < (it->second.size()); i++)
	{
		Days_Class.push_back(i + 1);
	}
	char* s = _com_util::ConvertBSTRToString(stroka);
	string dannye = s;
	for_each(dannye.begin(), dannye.end(), [&Days_Exe](char x) {Days_Exe.push_back((x)-'0'); });
	set_intersection(Days_Class.begin(), Days_Class.end(), Days_Exe.begin(), Days_Exe.end(), inserter(Itog, Itog.begin()));
	if (Itog.size() == dannye.size())
	{
		delete s;
		return true;
	}
	else
	{
		delete s;
		return false;
	}
}
void Zvezdniyvopros::Programm_Days(vector<int>& Days_Dly_Golosovania)
{
	vector<int> Vector;
	vector<int> x;
	map<string, vector<string>>::iterator it = Rasspisanie.begin();
	for (int i = 0; i < (it->second.size()); i++)
	{
		Vector.push_back(i + 1);
	}
	set_intersection(Days_Dly_Golosovania.begin(), Days_Dly_Golosovania.end(), Vector.begin(), Vector.end(), inserter(x, x.begin()));
	Days_Dly_Golosovania.swap(x);
}
