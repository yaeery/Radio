#include "Program.h"
Program::Program()
{

}
Program:: ~Program() {}
string Program::Get_Name()
{
	return Name;
}
string Program::Get_Vedushi()
{
	return Vedushi;
}
string Program::Get_Reiting()
{
	return Reiting;
}
string Program::Get_Days()
{
	string x="";
	return x;
}
string Program::Get_Time()
{
	string x="";
	return x;
}
Program* Program::Copy()
{
	return new Program(*this);
}
Program::Program(const Program& obj)
{
	Name = obj.Name;
	Vedushi = obj.Vedushi;
	Reiting = obj.Reiting;
	Rasspisanie = obj.Rasspisanie;
}
bool Program::Is_Day(BSTR stroka)
{
	return false;
}
void Program::Programm_Days(vector<int>& Days_Dly_Golosovania)
{

}