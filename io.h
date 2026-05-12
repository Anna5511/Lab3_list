#ifndef IO_H
#define IO_H

#include "list.h"

bool ReadListFromFile(const char* filename, Form& A);
bool ReadInsertData(const char* filename, Str*& strings, int& count);
void PrintList(ostream& out, const Form& A);

#endif