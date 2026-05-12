#ifndef STR_H
#define STR_H

#include <iostream>
#include <fstream>

using namespace std;

struct Str
{
    char* data;
    int len;
};

void InitString(Str& s);
void ClearString(Str& s);
void CopyString(Str& dest, const Str& src);
bool ReadLineFromFile(ifstream& fin, Str& s);
void PrintOneString(ostream& out, const Str& s);

#endif