#include <iostream>
#include <cstring>

enum class Division {
    ASSASSIN,
    MEDIC,
    MAGE,
    TANK
};

enum class Combat {
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero {
    char* name;
    Division division;
    Combat combat;
};


void initializeHero(Hero* hero, const char* name, Division division, Combat combat) {
    hero->name = new char[strlen(name) + 1];
    strcpy(hero->name, name);
    hero->division = division;
    hero->combat = combat;
}

void printHero(const Hero* hero) {
    std::cout << "Hero Name: " << hero->name << "\n";
    
    std::cout << "Division: ";
    switch (hero->division) {
        case Division::ASSASSIN: std::cout << "ASSASSIN"; break;
        case Division::MEDIC: std::cout << "MEDIC"; break;
        case Division::MAGE: std::cout << "MAGE"; break;
        case Division::TANK: std::cout << "TANK"; break;
    }
    std::cout << "\n";

    std::cout << "Combat: ";
    switch (hero->combat) {
        case Combat::UNKNOWN: std::cout << "UNKNOWN"; break;
        case Combat::RANGE: std::cout << "RANGE"; break;
        case Combat::MELEE: std::cout << "MELEE"; break;
        case Combat::BOTH: std::cout << "BOTH"; break;
    }
    std::cout << "\n";
}

void freeHero(Hero* hero) {
    delete[] hero->name;
    hero->name = nullptr;
}

int main() {
    Hero hero;
    initializeHero(&hero, "Shadow", Division::ASSASSIN, Combat::MELEE);
    printHero(&hero);
    freeHero(&hero);
    return 0;
}