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

    ofstream fout(outf);
    if (!fout.is_open()) { cout << "Не удалось открыть выходной файл" << endl; return 1; }

    fout << "Содержимое файла in.txt:" << endl;
    ifstream fin(inf);
    if (!fin.is_open()) { cout << "Не удалось открыть входной файл" << endl; return 1; }
    char ch;
    while (fin.get(ch)) fout << ch;
    fin.close();
    fout << endl << endl;

    Form A; InitForm(A);
    if (!ReadListFromFile(inf, A)) { cout << "Не удалось прочитать список" << endl; return 1; }

    fout << "Содержимое файла add.txt:" << endl;
    fin.open(addf);
    if (!fin.is_open()) { cout << "Не удалось открыть файл add.txt" << endl; return 1; }
    while (fin.get(ch)) fout << ch;
    fin.close();
    fout << endl << endl;

    Str* insertStrings = NULL;
    int insertCount = 0;
    if (!ReadInsertData(addf, insertStrings, insertCount))
    {
        cout << "Не удалось прочитать данные из add.txt" << endl;
        DeleteAll(A);
        return 1;
    }

    if (insertCount > 0)
        AddLastStr(A, insertStrings, insertCount);

    fout << "Список после вставки " << insertCount << " элементов в конец:" << endl;
    PrintList(fout, A);
    fout << endl;

    DeleteAll(A);
    for (int i = 0; i < insertCount; ++i) ClearString(insertStrings[i]);
    if (insertStrings) delete[] insertStrings;

    return 0;
}