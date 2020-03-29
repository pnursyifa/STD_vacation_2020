#include "vacation.h"

//Pengunjung & Tempat
bool isEmptyPT(ListPT L) {
	return first(L) == NULL;
}

void createListPT(ListPT &L) {
	first(L) = NULL;
}

void createNewElmPT(infoPT X, addressPT &P) {
	P = new elmPT;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
}

void insertFirstPT(ListPT &L, addressPT P) {
	//KHUSUS TEMPAT + UPDATE DATA KUNJUNGAN (RELASI)
	if (!isEmptyPT(L)) {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
}

void insertLastPT(ListPT &L, addressPT P) {
    //KHUSUS SIGN UP PENGUNJUNG
    if (!isEmptyPT(L)) {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
}

void insertAfterPT(addressPT Prec, addressPT P) {
    //KHUSUS SIGN UP PENGUNJUNG
    prev(P) = Prec;
    next(P) = next(Prec);
    prev(next(P)) = P;
    next(Prec) = P;
}

void deleteFirstPT(ListPT &L, addressPT &P) {
	P = first(L);
    if (next(P) == first(L)) {
        first(L) = NULL;
    } else {
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
        first(L) = next(P);
    }
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteAfterPT(addressPT Prec, addressPT &P) {
	P = next(Prec);
	if (P != Prec) {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
	}
    //PERHATIAN: kalo next(prec) == first(L), listnya(firstnya) bakal ilang. kalo itemnya cuma satu, gakkan diapus
}

addressPT cariElemenPT(ListPT L, infoPT X) {
	addressPT P;

    P = first(L);
    if (info(P) == X) {
        return P;
    } else {
        P = next(P);
        while (info(P) != X && P != first(L)) {
            P = next(P);
        }
        if (info(P) != X) {
            P = NULL;
        }
        return P;
    }
}

//Relasi
bool isEmptyR(ListR L) {
	return first(L) == NULL;
}

void createListR(ListR &L) {
	first(L) = NULL;
	last(L) = NULL;
}

void createNewElmR(infoR X, addressR &P) {
	P = new elmR;
    info(P) = X;
    next(P) = NULL;
}

void insertFirstR(ListR &L, addressR P) {
	if (!isEmptyR(L)) {
        next(P) = first(L);
        first(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void deleteFirstR(ListR &L, addressR &P) {
	if (first(L) == last(L)) {
		first(L) == NULL;
		last(L) == NULL;
	} else {
		P = first(L);
		first(L) = next(P);
		next(P) = NULL;
	}
}

void deleteAfterR(addressR Prec, addressR &P) {
	P = next(Prec);
	if (P != NULL) {
		next(Prec) = next(P);
		next(P) = NULL;
	}
}

//temp proc/func
void printInfoPT(ListPT L) {
    addressPT P = first(L);
    if(P != NULL) {
        cout << info(P) <<", ";
        P = next(P);

        while (P != first(L)) {
            cout<<info(P)<<", ";
            P = next(P);
        }
        cout << endl;
    } else {
        cout << "List Kosong" << endl;
    }

}

void printInfoR(ListR L) {
	addressR P = first(L);
	while (P!= NULL) {
		cout << info(info(P).Pengunjung) << " " << info(info(P).Tempat)<< ", ";
		P = next(P);
	}
	if (isEmptyR(L)) {
		cout << "list kosong";
	}
	cout << endl;
}

