#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Player structure
struct Player {
    string name;
   	int age;
    string role;
    int level;
    int strength;
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
    string roles[] = {"Mage", "Warrior", "Priest"};
    int index = rand() % 3;
    return roles[index];
}

// Function to create a new player
Player* createPlayer(const string& name, const int &age) {
    Player* player = new Player;
    player->name = name;
    player->age = age;
    player->role = getRandomRole();
    player->level = 1;
    player->strength = 10;
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
	cout << "Age			: " << player->age << endl;
    cout << "Role			: " << player->role << endl;
    cout << "Level			: " << player->level << endl;
    cout << "Strength		: " << player->strength << endl;
    cout << "Physical		: " << player->physical << endl;
    cout << "Health			: " << player->health << endl;
    // insert coins
}

// Function to display Monster status
void displayStatistic(const Monster monster) {
	cout << "\n=========== Monster " << monster.name << " Statistic =============" << endl;
	cout << "Health 			: " << monster.health << endl;
	cout << "Attack 			: " << monster.attack << endl;
	cout << "Defense			: " << monster.defense << endl;
	cout << "Experience		: " << monster.experience << endl;
	cout << "====================================================" << endl;
}

// Function to create a new monster
Monster createMonster(int level) {
    Monster monster;

    if (level == 1) {
    	// Goblin Monster
    	ifstream file("Goblin.txt");
        if (file.is_open()) { // Check if the file was successfully opened
        string line;
        while (getline(file, line)) { // Read each line of the file
            cout << line << endl; // Output the line to the console
        }

        file.close(); // Close the file
    } else {
        cout << "Failed to open the file." << endl;
    }
        monster.name = "Goblin";
        monster.level = level;
        monster.health = 50; 
        monster.attack = 15; 
        monster.defense = 5; 
        monster.experience = 20;
        // insert file goblin scene
        

        
    } else if (level == 2) {
    	// Zombie Monster
    	 ifstream inputFile("Zombie.txt");
	
	string paragraph;
    //int paragraphCount = 0;
    
	while (getline(inputFile, paragraph)) {
        if (paragraph.empty()) {
            // Skip empty lines between paragraphs
            continue;
        }
        
        cout << paragraph << endl;

        //"Press any key to continue to the next paragraph...";
        cin.ignore();  // Ignore the user input
        cout << endl;
    }
    
    inputFile.close();

        monster.name = "Zombie";
        monster.level = level;
        monster.health = 70 ;
        monster.attack = 30 ;
        monster.defense = 7 ;
        monster.experience = 30;
        //insert file zombie scene
        
    } else {//(level == 3)
    	// White Dragon Monster
    	ifstream file("White Dragon.txt");
        if (file.is_open()) { // Check if the file was successfully opened
        string line;
        while (getline(file, line)) { // Read each line of the file
            cout << line << endl; // Output the line to the console
        }

        file.close(); // Close the file
    } else {
        cout << "Failed to open the file." << endl;
    }
        monster.name = "White Dragon";
        monster.level = level;
        monster.health = 90 ;
        monster.attack = 50 ;
        monster.defense = 10 ;
        monster.experience = 50;
        //insert file dragon scene
    }	
    
   return monster;
}


// Function to simulate a battle between player and monster
void battle(Player& player, Monster& monster) {
	int playerDamage, monsterDamage;
    while (player.health > 0 && monster.health > 0) {
        
		int playerDamage = player.strength - monster.defense; //10-5= 5 // ==0
        monster.health -= playerDamage; //50 -5 =45-5=0

        int monsterDamage = monster.attack - player.physical;//20-10=10 -
        player.health -= monsterDamage;//100-10=90-

    }
    
	cout << "\nPlayer attacks the " << monster.name << " for " << player.strength - monster.defense << " damage." << endl;
    cout << "The " << monster.name << " attacks the player for " << monster.attack - player.physical << " damage." << endl;
    cout << endl;
        
    if (player.health > 0) {//health = 90
        cout << "\nCongratulations! You defeated the " << monster.name << "." << endl;
        cout << "Now player has health only " << player.health << "." <<endl;
        player.level++;
        player.physical +=15;
        player.strength +=15; 
        cout << "\n\nContinue to next level...." ;
        cin.ignore();
    } else {
        cout << "\nYou were defeated by the " << monster.name << ". Game over!" << endl;
    }
}

//function retreat
void retreat(Player &player){
	cout << "\nYou retreat from the battle and start to training. To gain more 10 points of health, physical and strength." << endl;
	player.health =+10;
	player.physical =+10;
	player.strength =+10;
	
	cout << "\nAfter a few days you have been training, you continue the level." <<endl;
	cout << "*******************************************************************************************************************" << endl;
	cin.ignore();
}

// Function for Warrior specific skill
void useWarriorSkill(Player& player, Monster& monster) {
	
    int playerDamage = player.strength * 2 - monster.defense;

    monster.health -= playerDamage;

    cout << "Player uses Warrior's skill: Mighty Strike!" << endl;
    cout << "Player strikes the " << monster.name << " with a mighty blow for " << playerDamage << " damage." << endl;
    
    //if monster still alive after using role's skill
    if (monster.health>0){
    	int choice;
    	cout << "\n\nWARNING !! " <<endl;
    	cout << "The " << monster.name << " still have " << monster.health << " health. You need to:" <<endl;
    	cout << "1. Battle" <<endl;
    	cout << "2. Retreat" << endl;
    	cin >> choice;
    	
    	switch(choice){
			case 1: battle(player,monster);
    				break;
    		case 2: retreat(player);
					break;
			default: cout << "Invalid choice.";
					break;	
		}
			
	}
	else //monster.health <=0
	{
		cout << "\nCongratulations. You defeated the monster " << monster.name <<"."<<endl;
	}
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
    
    //if monster still alive after using role's skill
    if (monster.health>0){
    	int choice;
    	cout << "The " << monster.name << " still have " << monster.health << " health. You need to:" <<endl;
    	cout << "1. Battle" <<endl;
    	cout << "2. Retreat" << endl;
    	cin >> choice;
    	
    	switch(choice){
			case 1: battle(player,monster);
    				break;
    		case 2: retreat(player);
					break;
			default: cout << "Invalid choice.";
					break;	
		}
    		
	}
	else //monster.health <=0
	{
		cout << "Congratulations. You defeated the monster " << monster.name <<endl;
	}
}

// Function for Rogue specific skill
void usePriestSkill(Player& player, Monster& monster) {
    int playerDamage = player.strength - monster.defense;
//    if (playerDamage < 0) {
//        playerDamage = 0;
//    }
    monster.health -= playerDamage;

    int bonusDamage = rand() % 20 + 10;
    monster.health -= bonusDamage;

    cout << "Player uses Priest's skill: Holly Power!" << endl;
    cout << "Player strikes the " << monster.name << " and follows up with a sneaky backstab for a total of " << (playerDamage + bonusDamage) << " damage." << endl;
    
     //if monster still alive after using role's skill
    if (monster.health>0){
    	int choice;
    	cout << "The " << monster.name << " still have " << monster.health << " health. You need to:" <<endl;
    	cout << "1. Battle" <<endl;
    	cout << "2. Retreat" << endl;
    	cin >> choice;
    	
    	switch(choice){
			case 1: battle(player,monster);
    				break;
    		case 2: retreat(player);
					break;
			default: cout << "Invalid choice.";
					break;	
		}
    		
	}
	else //monster.health <=0
	{
		cout << "Congratulations. You defeated the monster " << monster.name <<endl;
	}
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
            } else if (player.role == "Priest") {
                usePriestSkill(player, monster);
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
            retreat(player);
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

    cout << "\nEnter your name:  ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;
//
//    cout << "Enter your gender: ";
//    cin >> gender;

    Player* player = createPlayer(name,age);

    cout << "\nWelcome, " << player->name << "! Your adventure begins...\n" << endl;
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

        //"Press any key to continue to the next paragraph...";
        cin.ignore();  // Ignore the user input
        cout << endl;
    }
    
    inputFile.close();



    // Create the first level node
    LevelNode* head = new LevelNode;
    head->player = player;
    head->next = nullptr;
    LevelNode* currentLevel = head;
	
	cout << "\nBut before that, to join the war between The Great Creature and The Strong Soldiers, everyone who wishes to participate must overcome all " <<
			" the LEVELS they will encounter.\n" <<endl;
	cin.ignore();
	
    while (player->health > 0 && player->level <=3 ) {
        cout << "=================== Level " << player->level << " ====================" << endl;
        displayStatus(player);
        
		
        Monster monster = createMonster(player->level);
		
        cout << "\nPrepare to battle a " << monster.name << " (Level " << monster.level  << ")!" << endl;
        displayStatistic(monster);

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

	if (player->level >= 3 && player->health >0) {
        cout << "Congratulations! You have reached level 3. You completed the Level!" << endl;
        // masuk last file....
        
        
    } else if (player->level >= 3 && player->health <=0){
    	cout << "You have died at the last level. Game Over!" << endl;
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
    cout << "===================== WELCOME TO MONSTER WAR GAME =====================" << endl;
    char result; 
	cout << "\nAre you sure want to play this game?(y/n): ";
    
    bool answer;
	while( answer !=true){
		cin >> result;
   
     if (result=='y' || result=='Y')
     {
     	playGame();
     	return 0;
	 }
	 
	 else if (result=='n'|| result=='N'){
	 	return 0;
	 }
	 
     else 
	 {
     	cout << "\nYou put invalid choice!"<< endl;
     	cout << "Are you sure want to play this game?(y/n): ";
    
		answer ==true;
	 }
	}
    return 0;
}
