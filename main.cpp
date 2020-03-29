#include "vacation.h"

int main()
{
    addressPT P;
    addressPT Prec;
    addressPT T1;
    addressPT T2;
    addressR R;

    ListPT Tempat;

    createListPT(Tempat);
    createNewElmPT("Ragunan", T1);
    insertFirstPT(Tempat, T1);
    printInfoPT(Tempat);
    createNewElmPT("Dago Pakar", T2);
    insertFirstPT(Tempat, T2);
    printInfoPT(Tempat);

    ListPT Pengunjung;

    createListPT(Pengunjung);
    createNewElmPT("Dindin", Prec);
    insertFirstPT(Pengunjung, Prec);
    printInfoPT(Pengunjung);
    createNewElmPT("Putri", P);
    insertLastPT(Pengunjung, P);
    printInfoPT(Pengunjung);

    createNewElmPT("Elsa", P);
    insertAfterPT(Prec, P);
    printInfoPT(Pengunjung);

    ListR Relasi;
    infoR Relasi1;

    createListR(Relasi);

    //Elsa mengunjungi Dago Pakar,
    Relasi1.Pengunjung = P;
    Relasi1.Tempat = T2;

    createNewElmR(Relasi1, R);
    insertFirstR(Relasi, R);
    printInfoR(Relasi);

    //Dindin mengunjungi Ragunan,
    Relasi1.Pengunjung = Prec;
    Relasi1.Tempat = T1;

    createNewElmR(Relasi1, R);
    insertFirstR(Relasi, R);
    printInfoR(Relasi);
    return 0;
}
