#include "Str.h"

void InitString(Str& s)
{
    s.data = NULL;
    s.len = 0;
}

void ClearString(Str& s)
{
    delete[] s.data;
    s.data = NULL;
    s.len = 0;
}

void CopyString(Str& dest, const Str& src)
{
    if (&dest == &src) return;
    ClearString(dest);
    dest.len = src.len;

    if (src.len > 0)
    {
        dest.data = new char[src.len];
        for (int i = 0; i < src.len; i++) dest.data[i] = src.data[i];
    }
}

bool ReadLineFromFile(ifstream& fin, Str& s)
{
    ClearString(s);

    streampos pos = fin.tellg();
    char ch;
    int len = 0;
    bool started = false;

    while (fin.get(ch))
    {
        started = true;
        if (ch == '\n') break;
        len++;
    }

    if (!started && fin.eof()) return false;

    s.len = len;
    if (len > 0) s.data = new char[len];

    fin.clear();
    fin.seekg(pos);

    int i = 0;
    while (fin.get(ch))
    {
        if (ch == '\n') break;
        if (i < len) s.data[i++] = ch;
    }

    return true;
}

void PrintOneString(ostream& out, const Str& s)
{
    out << '"';
    for (int i = 0; i < s.len; i++) out << s.data[i];
    out << '"';
}