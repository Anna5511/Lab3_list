#include "io.h"
#include <fstream>

bool ReadListFromFile(const char* filename, Form& A)
{
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    Str temp;
    InitString(temp);

    while (ReadLineFromFile(fin, temp))
        AddLast(A, temp);

    ClearString(temp);
    return true;
}

bool ReadInsertData(const char* filename, Str*& strings, int& count)
{
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    // читаем количество вставляемых элементов
    fin >> count;
    fin.ignore();

    if (count <= 0) return true;

    strings = new Str[count];
    for (int i = 0; i < count; ++i)
        InitString(strings[i]);

    for (int i = 0; i < count; ++i)
    {
        if (!ReadLineFromFile(fin, strings[i]))
        {
            // если чтение не удалось, очищаем уже прочитанные строки
            for (int j = 0; j < i; ++j)
                ClearString(strings[j]);
            delete[] strings;
            strings = NULL;
            return false;
        }
    }
    return true;
}

void PrintList(ostream& out, const Form& A)
{
    Node* cur = A.head;
    if (cur == NULL) { out << "NULL"; return; }

    while (cur != NULL)
    {
        PrintOneString(out, cur->info);
        out << "\n|\nv\n";
        cur = cur->next;
    }
    out << "NULL";
}