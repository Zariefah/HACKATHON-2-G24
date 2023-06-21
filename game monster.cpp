#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Monster structure
struct Monster {
    string name;
    int health;
    int attack;
    int defense;
    int experience;
};

// Player structure
struct Player {
    string name;
    string role;
    int level;
    int health;
    int attack;
    int defense;
    int experience;
};

// Function to simulate a battle between player and monster
void battle(Player& player, Monster& monster) {
    while (player.health > 0 && monster.health > 0) {
        int playerDamage = player.attack - monster.defense;
        if (playerDamage < 0) {
            playerDamage = 0;
        }
        monster.health -= playerDamage;

        int monsterDamage = monster.attack - player.defense;
        if (monsterDamage < 0) {
            monsterDamage = 0;
        }
        player.health -= monsterDamage;

        cout << "Player attacks the " << monster.name << " for " << playerDamage << " damage." << endl;
        cout << "The " << monster.name << " attacks the player for " << monsterDamage << " damage." << endl;
    }

    if (player.health > 0) {
        cout << "Congratulations! You defeated the " << monster.name << "." << endl;
        player.experience += monster.experience;
        if (player.experience >= 100) {
            player.level++;
            player.experience -= 100;
            cout << "Level up! You are now at level " << player.level << "." << endl;
        }
    } else {
        cout << "You were defeated by the " << monster.name << ". Game over!" << endl;
    }
}

// Function for Warrior specific skill
void useWarriorSkill(Player& player, Monster& monster) {
    int playerDamage = player.attack * 2 - monster.defense;
    if (playerDamage < 0) {
        playerDamage = 0;
    }
    monster.health -= playerDamage;

    cout << "Player uses Warrior's skill: Mighty Strike!" << endl;
    cout << "Player strikes the " << monster.name << " with a mighty blow for " << playerDamage << " damage." << endl;
}

// Function for Mage specific skill
void useMageSkill(Player& player, Monster& monster) {
    int playerDamage = player.attack + 10 - monster.defense;
    if (playerDamage < 0) {
        playerDamage = 0;
    }
    monster.health -= playerDamage;

    cout << "Player uses Mage's skill: Fireball!" << endl;
    cout << "Player hurls a fireball at the " << monster.name << " dealing " << playerDamage << " damage." << endl;
}

// Function for Rogue specific skill
void useRogueSkill(Player& player, Monster& monster) {
    int playerDamage = player.attack - monster.defense;
    if (playerDamage < 0) {
        playerDamage = 0;
    }
    monster.health -= playerDamage;

    int bonusDamage = rand() % 20 + 10;
    monster.health -= bonusDamage;

    cout << "Player uses Rogue's skill: Backstab!" << endl;
    cout << "Player strikes the " << monster.name << " and follows up with a sneaky backstab for a total of " << (playerDamage + bonusDamage) << " damage." << endl;
}

// Function for the player's turn
void playerTurn(Player& player, Monster& monster) {
    cout << "Choose your action:" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Skill" << endl;
    cout << "3. Relax" << endl;
    cout << "4. Retreat" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            battle(player, monster);
            break;
        case 2:
            if (player.role == "Warrior") {
                useWarriorSkill(player, monster);
            } else if (player.role == "Mage") {
                useMageSkill(player, monster);
            } else if (player.role == "Rogue") {
                useRogueSkill(player, monster);
            } else {
                cout << "Invalid choice. Try again." << endl;
                playerTurn(player, monster);
            }
            break;
        case 3:
            player.health += 20;
            cout << "You relax and restore 20 health points." << endl;
            break;
        case 4:
            cout << "You retreat from the battle. Game over!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            playerTurn(player, monster);
    }
}

// Function to play the game
void playGame() {
    // Initialize random seed
    srand(time(0));

    Player player;
    cout << "Enter your name: ";
    cin >> player.name;

    // Randomly assign a role to the player
    int roleIndex = rand() % 3;
    switch (roleIndex) {
        case 0:
            player.role = "Warrior";
            player.health = 120;
            player.attack = 25;
            player.defense = 15;
            break;
        case 1:
            player.role = "Mage";
            player.health = 80;
            player.attack = 30;
            player.defense = 10;
            break;
        case 2:
            player.role = "Rogue";
            player.health = 100;
            player.attack = 20;
            player.defense = 12;
            break;
    }

    player.level = 1;
    player.experience = 0;

    Monster monster = {"Goblin", 50, 10, 5, 20};

    cout << "Welcome, " << player.name << "! You have chosen the role of a " << player.role << "." << endl;
    cout << "Your adventure begins..." << endl;

    while (player.health > 0 && monster.health > 0) {
        cout << "Player: " << player.name << " | Role: " << player.role << " | Level: " << player.level << endl;
        cout << "Monster: " << monster.name << " | Health: " << monster.health << endl;

        playerTurn(player, monster);
        cout << endl;
    }
}

// Main function
int main() {
    cout << "=== Text-based Adventure Game ===" << endl;

    playGame();

    return 0;
}
