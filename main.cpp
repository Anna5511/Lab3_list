#include <iostream>
#include <fstream>
#include "io.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    const char* inf = "C:\\Users\\Анечка\\Documents\\3\\in.txt";
    const char* addf = "C:\\Users\\Анечка\\Documents\\3\\add.txt";
    const char* outf = "C:\\Users\\Анечка\\Documents\\3\\out.txt";

    Form A;
    InitForm(A);

    if (!ReadListFromFile(inf, A))
    {
        cout << "Не удалось открыть входной файл или он пуст" << endl;
        return 1;
    }

    Str* insertStrings = NULL;
    int insertCount = 0;
    if (!ReadInsertData(addf, insertStrings, insertCount))
    {
        cout << "Не удалось прочитать данные из входного файла" << endl;
        DeleteAll(A);
        return 1;
    }

    if (insertCount > 0)
        AddLastStr(A, insertStrings, insertCount);

    ofstream fout(outf);
    if (!fout.is_open())
    {
        cout << "Не удалось открыть выходной файл"<< endl;
        DeleteAll(A);
        if (insertStrings) delete[] insertStrings;
        return 1;
    }

    fout << "Список после вставки " << insertCount << " элементов в конец:\n";
    PrintList(fout, A);
    fout << endl;

    DeleteAll(A);
    fout << "\nСписок удалён.\n";

    for (int i = 0; i < insertCount; ++i)
        ClearString(insertStrings[i]);
    if (insertStrings) delete[] insertStrings;

    return 0;
}