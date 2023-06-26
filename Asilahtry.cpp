#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

// Player structure
struct Player {
    string name;
   // int age;
  //  string gender;
    string role;
    int level;
    int strength;
   int speed;
   int physical;
    int magicPower;
   int statusPoints;
    int health;
    Player* next;
};

// Monster structure
struct Monster {
	
    string name;
    int level;
    int health;
    int attack;
    int defense;
    int experience;
};

// Linked list to store player's progress at each level
struct LevelNode {
    Player* player;
    LevelNode* next;
};

// Function to generate a random role for the player
string getRandomRole() {
    string roles[] = {"Mage", "Warrior", "Rogue"};
    int index = rand() % 5;
    return roles[index];
}

// Function to create a new player
Player* createPlayer(const string& name) {
    Player* player = new Player;
    player->name = name;
   // player->age = age;
   // player->gender = gender;
    player->role = getRandomRole();
    player->level = 1;
    player->strength = 10;
    player->speed = 10;
    player->physical = 10;
   	player->magicPower = 10;
  	player->statusPoints = 0;
    player->health = 100;
    player->next = nullptr;
    return player;
}

// Function to display player's status
void displayStatus(const Player* player) {
    cout << "Name			: " << player->name << endl;
   // cout << "Age: " << player->age << endl;
    //cout << "Gender: " << player->gender << endl;
    cout << "Role			: " << player->role << endl;
    cout << "Level			: " << player->level << endl;
    cout << "Strength		: " << player->strength << endl;
   // cout << "Speed			: " << player->speed << endl;
    cout << "Physical		: " << player->physical << endl;
   // cout << "Magic Power	: " << player->magicPower << endl;
    cout << "Status Points		: " << player->statusPoints << endl;
    cout << "Health			: " << player->health << endl;
}

// Function to create a new monster
//Monster createMonster(int level) {
//    Monster monster;
//    monster.name = "Goblin";
//    monster.health = 50 + (level - 1) * 10;
//    monster.attack = 10 + (level - 1) * 2;
//    monster.defense = 5 + (level - 1) * 1;
//    monster.experience = 20;
//    return monster;
//}

Monster createMonster(int level) {
    Monster monster;

    if (level == 1) {
        monster.name = "Goblin";
        monster.level = level;
        monster.health = 50; //+ (level - 1) * 10;
        monster.attack = 10; //+ (level - 1) * 2;
        monster.defense = 5; //+ (level - 1) * 1;
        monster.experience = 20;
    } else if (level == 2) {
        monster.name = "Skeleton";
        monster.level = level;
        monster.health = 70 ;//+ (level - 1) * 10;
        monster.attack = 15 ;//+ (level - 1) * 2;
        monster.defense = 7 ;//+ (level - 1) * 1;
        monster.experience = 30;
    } else if (level == 3){
        monster.name = "Dragon";
        monster.level = level;
        monster.health = 90 ;//+ (level - 1) * 10;
        monster.attack = 20 ;//+ (level - 1) * 2;
        monster.defense = 10 ;//+ (level - 1) * 1;
        monster.experience = 50;
    }	
    else { 
	}
   return monster;
}


// Function to simulate a battle between player and monster
void battle(Player& player, Monster& monster) {
    while (player.health > 0 && monster.health > 0) {
        int playerDamage = player.strength - monster.defense;
//        if (playerDamage < 0) {
//            playerDamage = 0;
//        }
        monster.health -= playerDamage;

        int monsterDamage = monster.attack - player.physical;
//        if (monsterDamage < 0) {
//            monsterDamage = 0;
//        }
        player.health -= monsterDamage;

//        cout << "Player attacks the " << monster.name << " for " << playerDamage << " damage." << endl;
//        cout << "The " << monster.name << " attacks the player for " << monsterDamage << " damage." << endl;
    }

    if (player.health > 0) {
        cout << "Congratulations! You defeated the " << monster.name << "." << endl;
        player.level++;
        player.statusPoints += 2;
       // player.health = 100;
        player.physical +=10;
        player.strength +=10;
    } else {
        cout << "You were defeated by the " << monster.name << ". Game over!" << endl;
    }
}

// Function for Warrior specific skill
void useWarriorSkill(Player& player, Monster& monster) {
    int playerDamage = player.strength * 2 - monster.defense;
//    if (playerDamage < 0) {
//        playerDamage = 0;
//    }
    monster.health -= playerDamage;

    cout << "Player uses Warrior's skill: Mighty Strike!" << endl;
    cout << "Player strikes the " << monster.name << " with a mighty blow for " << playerDamage << " damage." << endl;
}

// Function for Mage specific skill
void useMageSkill(Player& player, Monster& monster) {
    int playerDamage = player.strength + 10 - monster.defense;
//    if (playerDamage < 0) {
//        playerDamage = 0;
//    }
    monster.health -= playerDamage;

    cout << "Player uses Mage's skill: Fireball!" << endl;
    cout << "Player hurls a fireball at the " << monster.name << " dealing " << playerDamage << " damage." << endl;
}

// Function for Rogue specific skill
void useRogueSkill(Player& player, Monster& monster) {
    int playerDamage = player.strength - monster.defense;
//    if (playerDamage < 0) {
//        playerDamage = 0;
//    }
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

    string name, gender;
    int age;

    cout << "Enter your name:  ";
    cin >> name;

//    cout << "Enter your age: ";
//    cin >> age;
//
//    cout << "Enter your gender: ";
//    cin >> gender;

    Player* player = createPlayer(name);

    cout << "Welcome, " << player->name << "! Your adventure begins...\n" << endl;
    cin.ignore();
    
    ifstream inputFile("Scenario.txt");
	
	string paragraph;
    //int paragraphCount = 0;
    
	while (getline(inputFile, paragraph)) {
        if (paragraph.empty()) {
            // Skip empty lines between paragraphs
            continue;
        }
        
        cout << paragraph << endl;

        //cout << "Press any key to continue to the next paragraph...";
        cin.ignore();  // Ignore the user input
        cout << endl;
    }
    
    inputFile.close();



    // Create the first level node
    LevelNode* head = new LevelNode;
    head->player = player;
    head->next = nullptr;
    LevelNode* currentLevel = head;

    while (player->health > 0 && player->level <=3 ) {
        cout << "=== Level " << player->level << " ===" << endl;
        displayStatus(player);

        Monster monster = createMonster(player->level);

        cout << "Prepare to battle a " << monster.name << " (Level " << monster.level  << ")!" << endl;

        cout << "Press any key to start the battle...";
        cin.ignore();
        cin.get();

        playerTurn(*player, monster);
        cout << endl;

        // Create the next level node and link it to the current level
        LevelNode* nextLevel = new LevelNode;
        nextLevel->player = player;
        nextLevel->next = nullptr;
        currentLevel->next = nextLevel;
        currentLevel = nextLevel;
    }

	if (player->level >= 3) {
        cout << "Congratulations! You have reached level 3. You completed the game!" << endl;
    } else {
        cout << "Game over!" << endl;
    }
    
    // Game over, delete the player and level nodes
    while (head != nullptr) {
        LevelNode* temp = head;
        head = head->next;
        delete temp->player;
        delete temp;
    }
}

// Main function
int main() {
    cout << "=== WELCOME TO MONSTER WAR GAME ===" << endl;
    char result; 
	cout << "Are you sure want to play this game?(y/n): ";
    cin >> result;
   
     if (result=='y')
     {
     	playGame();
	 }
	 
	 else if (result=='n'){
	 	return 0;
	 }
	 
     else 
	 {
     	cout << "You put invalid choice!";
	 }

    return 0;
}
