#include <iostream>
#include "mobileLegends.h"

using namespace std;

int main(){
    listItem LI, LR;
    listHero LH;
    adrItem pI;
    adrHero pH;
    string heroName, itemType, itemType2;
    int i;
    string itemNames[20] = {"Blade of Despair", "Bloodlust Axe", "Endless Battle", "Berserker's Fury", "Queen's Wings",
                            "Athena's Shield", "Immortality", "Dominance Ice", "Malefic Roar", "Demon Hunter Sword",
                            "Thunder Belt", "Oracle", "Magic Shoes", "Rapid Boots", "Tough Boots",
                            "Swift Boots", "Warrior Boots", "Clock of Destiny", "Lightning Truncheon", "Glowing Wand"};
    string itemTypes[20] = {"Physical", "Physical", "Physical", "Physical", "Physical",
                            "Defense", "Defense", "Defense", "Physical", "Physical",
                            "Defense", "Magic", "Magic", "Utility", "Utility",
                            "Utility", "Utility", "Magic", "Magic", "Magic"};
    int itemPrices[20] = {3000, 1970, 2470, 2350, 2250,
                          2150, 2120, 2010, 2060, 2180,
                          2110, 2060, 720, 660, 700,
                          720, 690, 2800, 2200, 2100};
    string heroNames[10] = {"Alucard", "Layla", "Tigreal", "Miya", "Eudora",
                             "Gusion", "Lesley", "Chou", "Harley", "Johnson"};
    string heroClass1[10] = {"Fighter", "Marksman", "Tank", "Marksman", "Mage",
                              "Assassin", "Marksman", "Fighter", "Mage", "Tank"};
    string heroClass2[10] = {"-", "-", "Support", "-", "-",
                              "Mage", "-", "Tank", "Assassin", "Support"};

    createListItem(LI);
    createListHero(LH);
    createListItem(LR);
    for (i = 0; i < 20; i++) {
        pI = createItem(itemNames[i], itemTypes[i], itemPrices[i]);
        insertItem(LI, pI);
    }

    for (i = 0; i < 10; i++) {
        pH = createHero(heroNames[i], heroClass1[i], heroClass2[i]);
        insertHero(LH, pH);
    }
    cout << "Rekomendasi Item Hero Mobile Legends Berdasarkan Kelas dan Harga ver. Iteratif" << endl;
    cout << endl;
    cout << "List item :" << endl;
    printRecommendation(LI);
    cout << endl;
    menu();
    cin >> heroName;
    cout << endl;
    pH = findHero(LH, heroName);
    itemType = heroToItem(kelas1(pH));
    collectItemReccommendation(LI, LR, itemType);
    if (kelas2(pH) != "-") {
        itemType2 = heroToItem(kelas2(pH));
        collectItemReccommendation(LI, LR, itemType2);
    }
    sortReccommendation(LR);
    cout << "Rekomendasi item :" << endl;
    printRecommendation(LR);

    return 0;
}
