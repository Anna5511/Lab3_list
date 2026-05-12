#ifndef LIST_H
#define LIST_H

#include "Form.h"

void InitForm(Form& A);
Node* CreateNode(const Str& s);
void AddLast(Form& A, const Str& s);
void DeleteBeg(Form& A);
void DeleteAll(Form& A);
void AddLastStr(Form& A, const Str* strings, int count);

#endif