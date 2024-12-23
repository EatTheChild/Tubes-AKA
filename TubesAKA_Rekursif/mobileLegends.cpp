#include <iostream>
#include "mobileLegends.h"

adrItem createItem(string name, string type, int price){
    adrItem p = new item;
    namaItem(p) = name;
    tipe(p) = type;
    harga(p) = price;
    nextItem(p) = NULL;

    return p;
}

adrHero createHero(string name, string role1, string role2){
    adrHero p = new hero;
    namaHero(p) = name;
    kelas1(p) = role1;
    kelas2(p) = role2;
    nextHero(p) = NULL;

    return p;
}

void insertItem(listItem &L, adrItem p){
    adrItem q;
    if (firstItem(L) == NULL) {
        firstItem(L) = p;
    } else {
        nextItem(p) = firstItem(L);
        firstItem(L) = p;
    }
}

void insertHero(listHero &L, adrHero p){
    adrHero q;
    if (firstHero(L) == NULL) {
        firstHero(L) = p;
    } else {
        nextHero(p) = firstHero(L);
        firstHero(L) = p;
    }
}

adrHero findHero(listHero L, string name){
    adrHero p;
    p = firstHero(L);
    while (p != NULL && namaHero(p) != name) {
        p = nextHero(p);
    }

    return p;
}

string heroToItem(string role){
    if (role == "Fighter" || role == "Marksman" || role == "Assassin") {
        return "Physical";
    } else if (role == "Mage") {
        return "Magic";
    } else if (role == "Tank") {
        return "Defense";
    } else if (role == "Suppport") {
        return "Utility";
    }
}

void collectItemReccommendation(listItem &LI, listItem &LR, string type){
    adrItem p, grab;
    p = firstItem(LI);
    while (p != NULL) {
        if (tipe(p) == type) {
            grab = p;
            cout << namaItem(grab) << endl;
            ambilItem(LI, grab);
            insertItem(LR, grab);
            cout << namaItem(firstItem(LR)) << endl;
            collectItemReccommendation(LI, LR, type);
            p = NULL;
        } else {
            p = nextItem(p);
        }
    }
}

void ambilItem(listItem &LI, adrItem &p){
    adrItem prec;
    if (p == firstItem(LI)) {
        firstItem(LI) = nextItem(firstItem(LI));
        nextItem(p) = NULL;
    } else {
        prec = firstItem(LI);
        while (nextItem(prec) != p) {
            prec = nextItem(prec);
        }
        if (nextItem(p) == NULL) {
            nextItem(prec) = NULL;
        } else {
            nextItem(prec) = nextItem(p);
            nextItem(p) = NULL;
        }
    }
}

void sortReccommendation(listItem &LR, adrItem &first) {
    adrItem searchMax, maxItem;
    if (first != NULL) {
        maxItem = first;
        searchMax = nextItem(first);
        while (searchMax != NULL) {
            if (harga(searchMax) > harga(maxItem)) {
                maxItem = searchMax;
            }
            searchMax = nextItem(searchMax);
        }
        if (maxItem == first) {
            first = nextItem(first);
        }
        cout << namaItem(maxItem);
        ambilItem(LR, maxItem);
        insertItem(LR, maxItem);
        sortReccommendation(LR, first);
    }
}

void menu(){
    cout << "Pilih hero:" << endl;
    cout << "- Alucard" << endl;
    cout << "- Layla" << endl;
    cout << "- Tigreal" << endl;
    cout << "- Miya" << endl;
    cout << "- Gusion" << endl;
    cout << "- Lesley" << endl;
    cout << "- Chou" << endl;
    cout << "- Harley" << endl;
    cout << "- Johnson" << endl;
}

void printRecommendation(listItem LR){
    adrItem p;
    p = firstItem(LR);
    while (p != NULL) {
        cout << namaItem(p) << " [" << tipe(p) << "]" << "(" << harga(p) << ")" << endl;
        p = nextItem(p);
    }
}