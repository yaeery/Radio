// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа DLL_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
#include"DB.h"
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

// Этот класс экспортирован из библиотеки DLL
class DLL_API CDLL {
public:
	CDLL(void);
	// TODO: добавьте сюда свои методы.
};

extern DLL_API int nDLL;

DLL_API int fnDLL(void);

extern "C"
{
	void DLL_API Create();
	BSTR DLL_API Get_Name(int index);
	BSTR DLL_API Get_Vedushi(int index);
	BSTR DLL_API Get_Reiting(int index);
	BSTR DLL_API Get_Days(int index);
	BSTR DLL_API Get_Time(int index);
	int DLL_API Get_Size();
	void DLL_API Sort_Name();
	void DLL_API Sort_Vedushi();
	void DLL_API Sort_Reiting_Rize();
	void DLL_API Sort_Reiting_Drop();
	bool DLL_API Is_Day(BSTR stroka, int i);
	BSTR DLL_API Programm_Days(BSTR Incl_Days);
	void DLL_API File(BSTR stroka);
	BSTR DLL_API Leaders();
	DLL_API LONG_PTR Memory(wchar_t**& ppNames);
	DLL_API void Delete();
}