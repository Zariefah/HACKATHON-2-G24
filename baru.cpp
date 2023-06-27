#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Define the Item class
class Item {
	public:
		string name;
    	Item(string name) {
        	this->name = name;
    	}
    	
    	string getName() {
        	return name;
    	}
};

// Define the Node class for the linked list
class Node {
	public:
    	Item* item;
    	Node* next;

    	Node(Item* item) {
        	this->item = item;
        	this->next = nullptr;
    	}
};

// Define the Inventory class to manage the player's purchased items
class Inventory {
	private:
	    Node* head;
	
	public:
	    Inventory() {
	        head = nullptr;
	    }
	
	    void addItem(Item* item) {
	        Node* newNode = new Node(item);
	
	        if (head == nullptr) {
	            head = newNode;
	        } else {
	            Node* current = head;
	            while (current->next != nullptr) {
	                current = current->next;
	            }
	            current->next = newNode;
	        }
	    }
	
	    void removeItem(int itemIndex) {
	    if (head == nullptr) {
	        cout << "Inventory is empty." << endl;
	        cout << "Press any key to continue" << endl;
	        return;
	    }
	
	    if (itemIndex < 1) {
	        cout << "Invalid item index." << endl;
	        return;
	    }
	
	    if (itemIndex == 1) {
	        Node* removedNode = head;
	        head = head->next;
	        delete removedNode->item;
	        delete removedNode;
	        cout << "Item removed successfully." << endl;
	        return;
	    }
	
	    Node* currentNode = head;
	    Node* previousNode = nullptr;
	    int currentIndex = 1;
	
	    while (currentNode != nullptr && currentIndex < itemIndex) {
	        previousNode = currentNode;
	        currentNode = currentNode->next;
	        currentIndex++;
	    }
	
	    if (currentNode == nullptr) {
	        cout << "Invalid item index." << endl;
	        return;
	    }
	
	    previousNode->next = currentNode->next;
	    delete currentNode->item;
	    delete currentNode;
	    cout << "Item removed successfully." << endl;
	}
	
	
	    Item* getItem(int itemIndex) {
	        if (head == nullptr) {
	            cout << "Inventory is empty." << endl;
	            return nullptr;
	        }
	
	        if (itemIndex < 1) {
	            cout << "Invalid item index." << endl;
	            return nullptr;
	        }
	
	        Node* current = head;
	        int currentIndex = 1;
	
	        while (current != nullptr && currentIndex < itemIndex) {
	            current = current->next;
	            currentIndex++;
	        }
	
	        if (current == nullptr) {
	            cout << "Invalid item index." << endl;
	            return nullptr;
	        }
	
	        return current->item;
	    }
	
	    void displayItems() {
	        Node* current = head;
	        int itemIndex = 1;
	
	        if (current == nullptr) {
	            cout << "Inventory is empty." << endl;
	            return;
	        }
	
	        cout << "Inventory:" << endl;
	        while (current != nullptr) {
	            cout << itemIndex << ". " << current->item->name << endl;
	            current = current->next;
	            itemIndex++;
	        }
	    }
};


// Class for monster
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

// Class for player
class Player {
	private:
	   Inventory inventory;
	    string password;
	    string name;
	    int age;
	    string role;
	    int level;
	    int gold;
	    int strength;
	    int defense;
	    int health;
	
	
	   
	public:
		string username;  
		Player(string username, string password);
		void createPlayer();
	    void printWindowStatus();
	    void attackMonster(Monster* monster);
	    void useItem(Monster* monster);
	    void retreat();
	    void levelUp();
	    bool checkCredentials(string username, string password);
	    void purchase();
	    void playLevel1();
	    void playLevel2();
	    void playLevel3();
	    void playOption(int);
	    void playerAction(Monster*, int);
};

class Game{
	public:
		void run(Player* currentPlayer){
			enterGame(currentPlayer);
		}
		
	private:
		void enterGame(Player* currentPlayer) {
    cout << "************** Game **************" << endl;
    cout << "Welcome to the game, " << currentPlayer->username << "!" << endl;
    cout << endl << "************** Main Scenario **************" << endl;
    // Scenario
    ifstream scenarioFile("Scenario.txt");
    string scenarioParagraph;
    while (getline(scenarioFile, scenarioParagraph)) {
        if (scenarioParagraph.empty()) {
            continue;
        }
        cout << scenarioParagraph << endl;
        cout << "Press any key to continue to the next paragraph...";
        cin.ignore();
        cout << endl;
    }
    
    currentPlayer->printWindowStatus();
    
    // Level 1: Goblin
    ifstream goblinFile("Goblin.txt");
    string goblinParagraph;
    while (getline(goblinFile, goblinParagraph)) {
        if (goblinParagraph.empty()) {
            continue;
        }
        cout << goblinParagraph << endl;
        cout << "Press ENTER to continue to the next paragraph...";
        cin.ignore();
        cout << endl;
    }
    
    currentPlayer->playLevel1();
    
    // Level 2: Zombie
    ifstream zombieFile("Zombie.txt");
    string zombieParagraph;
    while (getline(zombieFile, zombieParagraph)) {
        if (zombieParagraph.empty()) {
            continue;
        }
        cout << zombieParagraph << endl;
        cout << "Press ENTER to continue to the next paragraph...";
        cin.ignore();
        cout << endl;
    }
    
    currentPlayer->playLevel2();
    
    // Level 3: White Dragon
    ifstream dragonFile("White Dragon.txt");
    string dragonParagraph;
    while (getline(dragonFile, dragonParagraph)) {
        if (dragonParagraph.empty()) {
            continue;
        }
        cout << dragonParagraph << endl;
        cout << "Press ENTER to continue to the next paragraph...";
        cin.ignore();
        cout << endl;
    }
    
    currentPlayer->playLevel3();
}
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
	cout << endl << "----------------------------------------" << endl;
    cout << "\t\tMonster Status" << endl;
    cout << endl << "----------------------------------------" << endl;
    cout << "\t\tName: " << name << endl;
    cout << "\t\tLevel: " << level << endl;
    cout << "\t\tHealth: " << health << endl;
    	cout << endl << "----------------------------------------" << endl;
}

void Monster::decreaseHealth(int amount) {
    health -= amount;
}

int Monster::getHealth() {
    return health;
}

// Player class
Player::Player(string username, string password) {
    this->username = username;
    this->password = password;
}

void Player::createPlayer() {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;


    // Randomly assign a role
    string roles[] = { "Mage", "Warrior", "Priest" };
    int randomIndex = rand() % 3;
    role = roles[randomIndex];

    level = 1;
    gold = 0;
    strength = 10;
    defense = 5;
    health = 100;
    //monsterDefeated = 0;
}

void Player::printWindowStatus() {
	cout << "----------------------------------------" << endl;
    cout << "\t\tWindow Status" << endl;
    cout << "----------------------------------------" << endl;
    cout << "\t\tName: " << name << endl;
    cout << "\t\tAge: " << age << endl;
    cout << "\t\tRole: " << role << endl;
    cout << "\t\tLevel: " << level << endl;
    cout << "\t\tCoins: " << gold << endl;
    cout << "----------------------------------------" << endl;
    cout << "\t\tStrength: " << strength << endl;
    cout << "\t\tDefense: " << defense << endl;
    cout << "\t\tHealth: " << health << endl;
    cout << "----------------------------------------" << endl;
}

void Player::attackMonster(Monster* currentMonster) {
	string monsterName = currentMonster->getName();
	cout << "Player attacks the "<< monsterName << endl;

    int powerOption;

    if (role == "Mage") {
        cout << "Choose your power:" << endl;
        cout << "1. Black Magic" << endl;
        cout << "2. Illusionist's Mirage" << endl;
        cout << "3. Necrotic Hex" << endl;

        cin >> powerOption;

        switch (powerOption) {
            case 1:
                cout << "Black Magic!" << endl;
                cout << "You unleash dark magical forces that instill fear in the " << monsterName << endl;
                cout << monsterName <<"'s health decreases by 10" << endl;
                currentMonster->decreaseHealth(10);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
                break;
            case 2:
                cout << "Illusionist's Mirage!" << endl;
                cout << "You create illusions that confuse the " << monsterName << " making it difficult for them to attack." << endl;
                cout << monsterName <<"'s health decreases by 12" << endl;
                currentMonster->decreaseHealth(12);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
                break;
            case 3:
                cout << "Necrotic Hex!" << endl;
                cout << "You cast a powerful hex on the "<< monsterName <<", draining their life force." << endl;
                cout << monsterName <<"'s health decreases by 9" << endl;
                currentMonster->decreaseHealth(9);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
                break;
            default:
                cout << "Invalid option. Attack failed." << endl;
                break;
        }
    }
    else if (role == "Warrior") {
        cout << "Choose your attack style:" << endl;
        cout << "1. Sword Slash" << endl;
        cout << "2. Shield Bash" << endl;
        cout << "3. Warcry" << endl;

        cin >> powerOption;

        switch (powerOption) {
            case 1:
                cout << "Sword Slash!" << endl;
                cout << "You swing your sword with immense strength, slicing through the " << monsterName << endl;
                cout << monsterName <<"'s health decreases by 10" << endl;
                currentMonster->decreaseHealth(10);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
                break;
            case 2:
                cout << "Shield Bash!" << endl;
                cout << "You bash your shield against the " << monsterName << ", stunning them momentarily." << endl;
                cout << monsterName <<"'s health decreases by 15" << endl;
                currentMonster->decreaseHealth(15);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
                break;
            case 3:
                cout << "Warcry!" << endl;
                cout << "You let out a powerful warcry that intimidates the " << monsterName << endl;
                cout << monsterName <<"'s health decreases by 12" << endl;
                currentMonster->decreaseHealth(12);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
                break;
            default:
                cout << "Invalid option. Attack failed." << endl;
                break;
        }
    }
    else if (role == "Priest") {
        cout << "Choose your divine power:" << endl;
        cout << "1. Healing Touch" << endl;
        cout << "2. Divine Smite" << endl;
        cout << "3. Holy Shield" << endl;

        cin >> powerOption;

        switch (powerOption) {
            case 1:
                cout << "Healing Touch!" << endl;
                cout << "You channel divine energy to heal yourself, restoring health." << endl;
                cout << "Your health increases by 10" << endl;
                health += 10;
                break;
            case 2:
                cout << "Divine Smite!" << endl;
                cout << "You call upon the divine forces to smite the " << monsterName << " with holy power." << endl;
                cout << monsterName <<"'s health decreases by 15" << endl;
                currentMonster->decreaseHealth(15);
                break;
            case 3:
                cout << "Blessing of the Stars !" << endl;
                cout << "The" << monsterName << "'s' lose its sight due to the radiance you emit." << endl;
                cout << monsterName <<"'s health decreases by 20" << endl;
                currentMonster->decreaseHealth(15);
                break;
            default:
                cout << "Invalid option. Attack failed." << endl;
                break;
        }
    }
    else {
        cout << "Invalid role for attacking." << endl;
    }
    
    //cout<<"Monster defeated: "<< monsterDefeated << endl;
}

void Player::useItem(Monster* currentMonster) {
	string monsterName = currentMonster->getName();
    cout << "Player uses an item!" << endl;
    cout << "Choose an item from your inventory:" << endl;
	
	// Displaying purchased items
    inventory.displayItems();
    
    int itemOption;
    cin >> itemOption;
    Item* selectedItem = inventory.getItem(itemOption);

if (selectedItem != nullptr) {
    string itemName = selectedItem->getName();

    // Perform actions based on the selected item
    switch (itemOption) {
        case 1:
            cout << "Venom Stick!" << endl;
            cout << "The " << monsterName << " feel sickened by the venomous substance." << endl;
            cout << monsterName <<"'s health decrease by 15"<<endl;
            // Decrease the monster's health
            currentMonster->decreaseHealth(15);
            
            // Check if the monster is defeated
                if (currentMonster->getHealth() <= 0) {
                    cout << "The monster is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
            break;
            
        case 2:
            cout << "Elixir of Invisibility!" << endl;
            cout << "The " << monsterName << " are unable to see you, allowing you to freely attack them." << endl;
            cout << monsterName <<"'s health decrease by 17"<<endl;
            // Decrease the monster's health
            currentMonster->decreaseHealth(17);
            
            // Check if the monster is defeated
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
            break;
            
        case 3:
            cout << "Scroll of Fireball!" << endl;
            cout << "The " <<monsterName << " are burned in fire." << endl;
            cout << monsterName <<"'s health decrease by 16"<<endl;
            // Decrease the monster's health
            currentMonster->decreaseHealth(16);
            
            // Check if the monster is defeated
                if (currentMonster->getHealth() <= 0) {
                    cout << "The " << monsterName << " is defeated!" << endl;
                    // Update player and monster stats accordingly
                    //monsterDefeated++;
                    levelUp();
                }
            break;
        
        case 4:
        	cout << "Red Pill!" << endl;
        	cout << "Your health increases by 20" <<endl;
                health += 20;
        default:
            cout << "Invalid item option." << endl;
            break;
    }
     // Remove the used item from the inventory
        inventory.removeItem(itemOption);
        selectedItem = nullptr;
        } else {
        cout << "Invalid item option." << endl;
	
	} 
}

void Player::retreat() {
    cout << "Player retreats from the battle!" << endl;
    cout << "You escaped from the battle. No rewards gained." << endl;
    switch (level) {
        case 1:
            playLevel1();
            break;
        case 2:
            playLevel2();
            break;
        case 3:
            playLevel3();
            break;
        default:
            cout << "Invalid current level." << endl;
            break;
    }
}

void Player::levelUp() {
    level++;
    strength += 50;
    defense += 15;
    health += 20;
    gold +=1000;
}

bool Player::checkCredentials(string username, string password) {
    return (this->username == username && this->password == password);
}

void Player::purchase()
{
	cout << "Entering the item shop..." << endl;
    	cout << "Available items:" << endl;
    	cout << "1. Venom Stick - Price: 100 gold" << endl;
    	cout << "2. Elixir of Invisibility - Price: 200 gold" << endl;
    	cout << "3. Scroll of Fireball - Price: 150 gold" << endl;
    	cout << "4. Red Pill - Price: 20 gold" << endl;
    
    	cout << endl << "Available gold: " << gold <<endl;


    	int itemOption;
    	cin >> itemOption;

    	switch (itemOption) {
        	case 1: {
            	int itemPrice = 100;
            	if (gold >= itemPrice) {
                	Item* purchasedItem = new Item("Venom Stick"); // Replace with actual item creation
                	inventory.addItem(purchasedItem);
                	gold -= itemPrice;
                	cout << "Venom Stick purchased and added to inventory." << endl;
            	} else {
                	cout << "Insufficient funds to purchase Venom Stick." << endl;
            	}
            	break;
        	}
        	case 2: {
            	int itemPrice = 200;
            	if (gold >= itemPrice) {
                	Item* purchasedItem = new Item("Elixir of Invisibility"); // Replace with actual item creation
                	inventory.addItem(purchasedItem);
                	gold -= itemPrice;
                	cout << "Elixir of Invisibility purchased and added to inventory." << endl;
            	} else {
                	cout << "Insufficient funds to purchase Elixir of Invisibility." << endl;
            	}
            	break;
        	}
        	case 3: {
            	int itemPrice = 150;
            	if (gold >= itemPrice) {
                	Item* purchasedItem = new Item("Scroll of Fireball"); // Replace with actual item creation
                	inventory.addItem(purchasedItem);
                	gold -= itemPrice;
                	cout << "Scroll of Fireball purchased and added to inventory." << endl;
            	} else {
                	cout << "Insufficient funds to purchase Scroll of Fireball." << endl;
            	}
            	break;
        	}
        	case 4: {
        		int itemPrice = 20;
            	if (gold >= itemPrice) {
                	Item* purchasedItem = new Item("Red Pill"); // Replace with actual item creation
                	inventory.addItem(purchasedItem);
                	gold -= itemPrice;
                	cout << "Red Pill purchased and added to inventory." << endl;
            	} else {
                	cout << "Insufficient funds to purchase Red Pill." << endl;
            	}
				break;
			}
        	// Add more cases for other item options if needed
        	default:
            	cout << "Invalid item option." << endl;
            	break;
    	}
}

void Player :: playLevel1() {
        // Display level information
        cout << "You have entered Level 1: Goblin Forest" << endl;

        // Continue playing options
        playOption(1);
    }

void Player :: playLevel2() {
        // Display level information
        cout << "You have entered Level 2: Zombie Dark City" << endl;

        // Continue playing options
        playOption(2);
    }

void Player :: playLevel3() {
        // Display level information
        cout << "You have entered Level 3: White Dragon Holy Nest" << endl;

        // Continue playing options
        playOption(3);
    }

void Player :: playOption(int level) {
        cout << "Select your option:" << endl;
        cout << "1. Continue" << endl;
        cout << "2. Purchase items" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Continuing to the game..." << endl;
                Monster* monster;
                if (level == 1)
                    monster = new Monster("Goblin", 1, 70);
                else if (level == 2)
                    monster = new Monster("Zombie", 2, 150);
                else if (level == 3)
                    monster = new Monster("White Dragon", 3, 200);

                playerAction(monster, level);

                break;
            }
            case 2:
                purchase();
                if (level == 1)
                    playLevel1();
                else if (level == 2)
                    playLevel2();
                else if (level == 3)
                    playLevel3();
                break;
            case 3:
                cout << "Exiting the game..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Exiting the game..." << endl;
                exit(0);
        }
    }

void Player :: playerAction(Monster* monster, int level) {
        while (true) {
            printWindowStatus();
            monster->printMonsterStats();

            int choice;
            cout << "Choose an action:" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use Item" << endl;
            cout << "3. Retreat" << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    attackMonster(monster);
                    if (monster->getHealth() <= 0) {
                        cout << "You defeated the monster! Level up!" << endl;
                        cout << "You are rewarded with 1000 gold" << endl;
                        if (level == 1)
                            playLevel2();
                        else if (level == 2)
                            playLevel3();
                        levelUp();
                        return;
                    }
                    break;
                case 2:
                    useItem(monster);
                    break;
                case 3:
                    retreat();
                    return;
                default:
                    cout << "Invalid option. Please choose again." << endl;
                    break;
            }

            // Monster attacks player
            int monsterDamage = rand() % 10 + 1;
            int playerDamageTaken = max(monsterDamage - defense, 5);
            health -= playerDamageTaken;
            cout << "The monster attacks you! You take " << playerDamageTaken << " damage." << endl;

            if (health <= 0) {
                cout << "Game Over! You were defeated by the monster." << endl;
                cout << "Do you want to start over? (Y/N)" << endl;
                char decision;
                cin >> decision;
                if (decision == 'Y' || decision == 'y') {
                    if (level == 1)
                        playLevel1();
                    else if (level == 2)
                        playLevel2();
                    else if (level == 3)
                        playLevel3();
                } else if (decision == 'N' || decision == 'n') {
                    exit(0);
                }
                return;
            }
        }
    }

// Function prototypes
void displayWelcomeMessage();
void signUp(Player** currentPlayer);
void logIn(Player** currentPlayer);
//void enterGame(Player* currentPlayer);
void deletePlayer(Player* currentPlayer);

void displayWelcomeMessage() {
    cout << "Welcome to the Player vs. Monster game!" << endl;
    cout << "**************************************" << endl;
    cout << "Instructions:" << endl;
    cout << "- Sign up or log in to play the game." << endl;
    cout << "- Defeat monsters to level up and earn coins." << endl;
    cout << "- Use coins to buy items from the inventory." << endl;
    cout << "- Good luck and have fun!" << endl;
    cout << "**************************************" << endl;
}

void signUp(Player** currentPlayer) {
    string username, password;
    cout << "************ Sign Up ************" << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    *currentPlayer = new Player(username, password);
    (*currentPlayer)->createPlayer();
    cout << "Account created successfully!" << endl;
}

void logIn(Player** currentPlayer) {
    string username, password;
    cout << "************* Log In *************" << endl;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Check if the player with the given credentials exists
    if ((*currentPlayer)->checkCredentials(username, password)) {
        cout << "Welcome back, " << username << "!" << endl;
    }
    else {
        cout << "Invalid username or password. Please try again." << endl;
        logIn(currentPlayer);
    }
}
                                
void deletePlayer(Player* currentPlayer) {
    delete currentPlayer;
}

int main() {

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    displayWelcomeMessage();
    Player* currentPlayer = nullptr;
    signUp(&currentPlayer);
    logIn(&currentPlayer);
    //enterGame(currentPlayer);
    Game game;
    game.run(currentPlayer);
    
    deletePlayer(currentPlayer);
    return 0;
}