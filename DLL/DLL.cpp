// DLL.cpp : Определяет экспортируемые функции для DLL.
//

#include "framework.h"
#include "DLL.h"


// Пример экспортированной переменной
DLL_API int nDLL=0;

// Пример экспортированной функции.
DLL_API int fnDLL(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
CDLL::CDLL()
{
    return;
}
DB Hranilishe;
void DLL_API Create()
{
    Hranilishe.Set_Vec();
}
BSTR DLL_API Get_Name(int index)
{
    return _com_util::ConvertStringToBSTR(Hranilishe.Get_Vec()[index]->Get_Name().c_str());
}
BSTR DLL_API Get_Vedushi(int index)
{
    return _com_util::ConvertStringToBSTR(Hranilishe.Get_Vec()[index]->Get_Vedushi().c_str());
}
BSTR DLL_API Get_Reiting(int index)
{
    return _com_util::ConvertStringToBSTR(Hranilishe.Get_Vec()[index]->Get_Reiting().c_str());
}
BSTR DLL_API Get_Days(int index)
{
    return _com_util::ConvertStringToBSTR(Hranilishe.Get_Vec()[index]->Get_Days().c_str());
}
BSTR DLL_API Get_Time(int index)
{
    return _com_util::ConvertStringToBSTR(Hranilishe.Get_Vec()[index]->Get_Time().c_str());
}
int DLL_API Get_Size()
{
    return Hranilishe.Get_Vec().size();
}
void DLL_API Sort_Name()
{
    Hranilishe.Sort_Name();
}
void DLL_API Sort_Vedushi()
{
    Hranilishe.Sort_Vedushi();
}
void DLL_API Sort_Reiting_Rize()
{
    Hranilishe.Sort_Reiting_Rize();
}
void DLL_API Sort_Reiting_Drop()
{
    Hranilishe.Sort_Reiting_Drop();
}
bool DLL_API Is_Day(BSTR stroka, int index)
{
    return  Hranilishe.Get_Vec()[index]->Is_Day(stroka);
}

BSTR DLL_API Programm_Days(BSTR Days_EXE)
{
    vector<int> Days_Classa{ 1,2,3,4,5,6,7 };
    string Vivod;
    char* s = _com_util::ConvertBSTRToString(Days_EXE);
    string stroka = s;
    for (int i = 0; i < stroka.size(); i++)
    {
        Hranilishe.Get_Vec()[stroka[i] - '0']->Programm_Days(Days_Classa);
    }
    for (int i = 0; i < Days_Classa.size(); i++)
    {
        Vivod += to_string(Days_Classa[i]);
    }
    delete s;
    return _com_util::ConvertStringToBSTR(Vivod.c_str());
}
void DLL_API File(BSTR stroka)
{
    char* s = _com_util::ConvertBSTRToString(stroka);
    string New = s;
    fstream file;
    file.open("../Расписание.txt", ios::app);
    file << "\n";
    file << New;
    file.close();
    delete s;
}
BSTR DLL_API Leaders()
    {
    vector<float> Reiting;
    string stroka;
    for (int i = 0; i < Hranilishe.Get_Vec().size(); i++)
    {
        Reiting.push_back((stof(Hranilishe.Get_Vec()[i]->Get_Reiting())));
    }
    pair<vector<float>::iterator, vector<float>::iterator> y = equal_range(Reiting.begin(), Reiting.end(), stof(Hranilishe.Get_Vec()[Hranilishe.Get_Vec().size() - 3]->Get_Reiting()));

    for (int i = 0; i < Hranilishe.Get_Vec().size(); i++)
    {
        if ((stof(Hranilishe.Get_Vec()[i]->Get_Reiting()) == *y.first)  || (stof((Hranilishe.Get_Vec()[i]->Get_Reiting())) == *y.second))
        {
            stroka += to_string(i);
        }
    }
    string dly_otpravki;
    for (int i = stroka.size() - 1; i >= 0; i--)
    {
        dly_otpravki += stroka[i];
    }
   return  _com_util::ConvertStringToBSTR(dly_otpravki.c_str());
}
DLL_API LONG_PTR Memory(wchar_t**& ppNames)

{
    HANDLE hLogFile;

    hLogFile = CreateFile(L"log.txt", GENERIC_WRITE,

        FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,

        FILE_ATTRIBUTE_NORMAL, NULL);

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);

    _CrtSetReportFile(_CRT_WARN, hLogFile);

    _CrtDumpMemoryLeaks();

    CloseHandle(hLogFile);

    vector <string> n;

    string v((std::istreambuf_iterator<char>(*(std::unique_ptr<std::ifstream>(new std::ifstream("log.txt"))).get())), std::istreambuf_iterator<char>());

    n.push_back(v);

    LONG_PTR newStringsArraySize = 0;

    {

        CoTaskMemFree(ppNames);

        ppNames = NULL;

        newStringsArraySize = n.size();

        LONG_PTR newwidth = 0;

        wchar_t** newArray = (wchar_t**)CoTaskMemAlloc(sizeof(wchar_t*) * newStringsArraySize);

        for (LONG_PTR j = 0; j < newStringsArraySize; j++)

        {

            wstring wstr1(n[j].begin(), n[j].end());

            newwidth = wstr1.size() + 1;

            newArray[j] = (wchar_t*)CoTaskMemAlloc(sizeof(wchar_t) * newwidth);

            ::ZeroMemory(newArray[j], sizeof(wchar_t) * newwidth);

            swprintf(newArray[j], newwidth, wstr1.data());

        }

        ppNames = newArray;

    }

    return 1;

}
DLL_API void Delete()
{
    Hranilishe.~DB();
}