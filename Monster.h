#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>

using namespace std;

// Class for Monster
class Monster {
	private:
	    string name;
	    int level;
	    int health;
	public:
	    Monster(string name, int level, int health);
	    string getName();
	    void printMonsterStats();
	    void decreaseHealth(int amount);
	    int getHealth();
};

// Monster class implementation
Monster::Monster(string name, int level, int health) {
    this->name = name;
    this->level = level;
    this->health = health;
}

string Monster::getName() {
    return name;
}

void Monster::printMonsterStats() {
	cout << endl << "-------------------------------------------------------------" << endl;
    cout << "\t\t\tMonster Status" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\t\tName: " << name << endl;
    cout << "\t\t\tLevel: " << level << endl;
    cout << "\t\t\tHealth: " << health << endl;
    cout << "-------------------------------------------------------------" << endl;
}

void Monster::decreaseHealth(int amount) {
    health -= amount;
}

int Monster::getHealth() {
    return health;
}

#endif
