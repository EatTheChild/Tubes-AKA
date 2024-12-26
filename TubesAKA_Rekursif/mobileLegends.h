#ifndef MOBILELEGENDS_H_INCLUDED
#define MOBILELEGENDS_H_INCLUDED

#define firstItem(LI) LI.firstItem
#define lastItem(LI) LI.lastItem
#define namaItem(pI) pI->namaItem
#define tipe(pI) pI->tipe
#define harga(pI) pI->harga
#define nextItem(pI) pI->nextItem
#define firstHero(LH) LH.firstHero
#define lastHero(LH) LH.lastHero
#define namaHero(pH) pH->namaHero
#define kelas1(pH) pH->kelas1
#define kelas2(pH) pH->kelas2
#define nextHero(pH) pH->nextHero
using namespace std;

typedef struct item *adrItem;
typedef struct hero *adrHero;

struct item {
    string namaItem;
    string tipe;
    int harga;
    adrItem nextItem;
};

struct hero {
    string namaHero;
    string kelas1;
    string kelas2;
    adrHero nextHero;
};

struct listItem {
    adrItem firstItem;
    adrItem lastItem;
};

struct listHero {
    adrHero firstHero;
    adrHero lastHero;
};

adrItem createItem(string name, string type, int price);
adrHero createHero(string name, string role1, string role2);
void createListItem(listItem &LI);
void createListHero(listHero &LH);
void insertItem(listItem &L, adrItem p);
void insertHero(listHero &L, adrHero p);
adrHero findHero(listHero L, string name);
string heroToItem(string role);
void collectItemReccommendation(listItem &LI, listItem &LR, string type);
void ambilItem(listItem &LI, adrItem &p);
void sortReccommendation(listItem &LR, adrItem &first);
void menu();
void printRecommendation(listItem LR);

#endif // MOBILELEGENDS_H_INCLUDED
