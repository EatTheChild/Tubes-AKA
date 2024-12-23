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
    if (firstItem(L) == NULL) {
        firstItem(L) = p;
    } else {
        nextItem(p) = firstItem(L);
        firstItem(L) = p;
    }
}

void insertHero(listHero &L, adrHero p){
    if (firstHero(L) == NULL) {
        firstHero(L) = p;
    } else {
        nextHero(p) = firstHero(L);
        firstHero(L) = p;
    }
}

adrHero findHero(listHero L, string name){
    adrHero p = firstHero(L);
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
    } else if (role == "Support") {
        return "Utility";
    }
    return "";
}

void collectItemRecommendationIterative(listItem &LI, listItem &LR, string type){
    adrItem p = firstItem(LI);
    adrItem grab;
    while (p != NULL) {
        if (tipe(p) == type) {
            grab = p;
            ambilItem(LI, grab);
            insertItem(LR, grab);
            p = firstItem(LI); // Restart loop to handle updated list
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
        nextItem(prec) = nextItem(p);
        nextItem(p) = NULL;
    }
}

void sortRecommendationIterative(listItem &LR) {
    listItem sortedList;
    firstItem(sortedList) = NULL;

    while (firstItem(LR) != NULL) {
        adrItem p = firstItem(LR);
        adrItem maxItem = p;
        adrItem prec = NULL;
        adrItem precMax = NULL;

        while (p != NULL) {
            if (harga(p) > harga(maxItem)) {
                maxItem = p;
                precMax = prec;
            }
            prec = p;
            p = nextItem(p);
        }

        if (precMax == NULL) {
            firstItem(LR) = nextItem(maxItem);
        } else {
            nextItem(precMax) = nextItem(maxItem);
        }

        nextItem(maxItem) = NULL;
        insertItem(sortedList, maxItem);
    }

    firstItem(LR) = firstItem(sortedList);
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
    adrItem p = firstItem(LR);
    while (p != NULL) {
        cout << namaItem(p) << " [" << tipe(p) << "] (" << harga(p) << ")" << endl;
        p = nextItem(p);
    }
}
