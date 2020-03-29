#ifndef VACATION_H_INCLUDED
#define VACATION_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

//ADT Pengunjung & Tempat
typedef string infoPT;
typedef struct elmPT *addressPT;
struct elmPT {
	infoPT info;
	addressPT next;
	addressPT prev;
};

struct ListPT {
	addressPT first;
};

bool isEmptyPT(ListPT L);
void createListPT(ListPT &L);
void createNewElmPT(infoPT X, addressPT &P);
void insertFirstPT(ListPT &L, addressPT P); //khusus daftar tempat
void insertLastPT(ListPT &L, addressPT P); //khusus sign up pengunjung
void insertAfterPT(addressPT Prec, addressPT P); //khusus sign up pengunjung
void deleteFirstPT(ListPT &L, addressPT &P);
void deleteAfterPT(addressPT Prec, addressPT &P);
addressPT cariElemenPT(ListPT L, infoPT X);

//ADT Relasi
typedef struct elmR *addressR;

struct infoR {
	addressPT Pengunjung;
	addressPT Tempat;
	//waktu?
};

struct elmR {
	infoR info;
	addressR next;
};

struct ListR {
	addressR first;
	addressR last;
};

bool isEmptyR(ListR L);
void createListR(ListR &L);
void createNewElmR(infoR X, addressR &P);
void insertFirstR(ListR &L, addressR P);
void deleteFirstR(ListR &L, addressR &P);
void deleteAfterR(addressR Prec, addressR &P);

//temp proc/func
void printInfoPT(ListPT L);
void printInfoR(ListR L);

#endif // VACATION_H_INCLUDED
