#ifndef PARENTS1_H_INCLUDED
#define PARENTS1_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef string infotype;
typedef struct elmList *address;
struct elmList {
    infotype info;
    address next;
    address prev;
};
struct List {
    address first;
};

bool isEmpty(List L);
void createList(List &L);
void createNewElmt(infotype X, address &P);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(address Prec, address &P);
void printInfo(List &L);
address cariElemen(List L, infotype X);




#endif // PARENTS1_H_INCLUDED
