#include "Novosti.h"
Novosti::Novosti()
{
	Name = "Новости";
	Vedushi = "Лора Стаднитская";
	Reiting = "4.8";
	vector<string> Days = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница","Суббота","Воскресенье"};
	Rasspisanie.insert(make_pair("9:00 - 9:30", Days));
}
Novosti:: ~Novosti() {}
string Novosti::Get_Name()
{
	return Name;
}
string Novosti::Get_Vedushi()
{
	return Vedushi;
}
string Novosti::Get_Reiting()
{
	return Reiting;
}
string Novosti::Get_Days()
{
	string x;
	map<string, vector<string>> ::iterator first = Rasspisanie.begin();
	x = x + *(first->second.begin()) + " - " + *(--first->second.end());
	return x;
}
string Novosti::Get_Time()
{
	string x;
	map<string, vector<string>> ::iterator first = Rasspisanie.begin();
	x = first->first;
	return x;
}
Program* Novosti::Copy()
{
	return new Novosti(*this);
}
Novosti::Novosti(const Novosti& obj):Program(obj)
{
	Name = obj.Name;
	Vedushi = obj.Vedushi;
	Reiting = obj.Reiting;
	Rasspisanie = obj.Rasspisanie;
}

bool Novosti::Is_Day(BSTR stroka)
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
void Novosti::Programm_Days(vector<int>& Days_Dly_Golosovania)
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
