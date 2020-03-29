#include "parents1.h"

bool isEmpty(List L){
    return first(L) == NULL;
}
void createList(List &L){
    first(L) = NULL;
}
void createNewElmt(infotype X, address &P){
    P = new elmList;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
}
void insertFirst(List &L, address P){
    if (!isEmpty(L)) {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        next(P) = first(L);
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;

    }
}
void deleteFirst(List &L, address &P) {
    P = first(L);
    if (next(P) == first(L)) {
        first(L) = NULL;
    } else {
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;

    }
}
void deleteAfter(address Prec, address &P) {
    P = next(Prec);

    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(P)) = P;

}
void printInfo(List &L) {
    address P = first(L);
    if(P != NULL) {
        cout<<info(P)<<", ";
        P = next(P);

        while (P != first(L)) {
            cout<<info(P)<<", ";
            P = next(P);
        }
        cout<<endl;
    } else {
        cout<<"List Kosong";
        cout<<endl;
    }

}
address cariElemen(List L, infotype X) {
    address P;

    P = first(L);
    if (info(P) == X) {
        return P;
    } else {
        P = next(P);
        while (info(P) != X && P != first(L)) {
            P = next(P);
        }
        return P;
    }

}
