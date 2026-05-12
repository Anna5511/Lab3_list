#include "list.h"

void InitForm(Form& A)
{
    A.head = NULL;
}

Node* CreateNode(const Str& s)
{
    Node* p = new Node;
    InitString(p->info);
    CopyString(p->info, s);
    p->next = NULL;
    return p;
}

void AddLast(Form& A, const Str& s)
{
    Node* p = CreateNode(s);
    if (A.head == NULL)
    {
        A.head = p;
        return;
    }

    Node* cur = A.head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = p;
}

void DeleteBeg(Form& A)
{
    if (A.head == NULL) return;

    Node* tmp = A.head;
    A.head = A.head->next;
    ClearString(tmp->info);
    delete tmp;
}

void DeleteAll(Form& A)
{
    while (A.head != NULL) DeleteBeg(A);
}

void AddLastStr(Form& A, const Str* strings, int count)
{
    for (int i = 0; i < count; ++i)
        AddLast(A, strings[i]);
}