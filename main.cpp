#include "parents1.h"
#include <iostream>

using namespace std;

int main()
{
    address P;
    address Prec;

    List L;

    createList(L);
    createNewElmt('Ragunan', P);
    insertFirst(L, P);
    printInfo(L);
    return 0;
}
