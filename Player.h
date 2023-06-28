#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "Item.h"
#include "typewriterEffect.h"
#include "Monster.h"

using namespace std;

// Class for Player
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
	    void guidanceItem();
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
	    void saveProgress();
};

// Player class implementation
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

}

void Player::printWindowStatus() {
	cout << "-------------------------------------------------------------" << endl;
    cout << "\t\t\tWindow Status" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\t\tName: " << name << endl;
    cout << "\t\t\tAge: " << age << endl;
    cout << "\t\t\tRole: " << role << endl;
    cout << "\t\t\tLevel: " << level << endl;
    cout << "\t\t\tGold: " << gold << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "\t\t\tStrength: " << strength << endl;
    cout << "\t\t\tDefense: " << defense << endl;
    cout << "\t\t\tHealth: " << health << endl;
    cout << "-------------------------------------------------------------" << endl;
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
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
                break;
            case 2:
                cout << "Illusionist's Mirage!" << endl;
                cout << "You create illusions that confuse the " << monsterName << " making it difficult for them to attack." << endl;
                cout << monsterName <<"'s health decreases by 12" << endl;
                currentMonster->decreaseHealth(12);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
                break;
            case 3:
                cout << "Necrotic Hex!" << endl;
                cout << "You cast a powerful hex on the "<< monsterName <<", draining their life force." << endl;
                cout << monsterName <<"'s health decreases by 9" << endl;
                currentMonster->decreaseHealth(9);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
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
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
                break;
            case 2:
                cout << "Shield Bash!" << endl;
                cout << "You bash your shield against the " << monsterName << ", stunning them momentarily." << endl;
                cout << monsterName <<"'s health decreases by 15" << endl;
                currentMonster->decreaseHealth(15);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
                break;
            case 3:
                cout << "Warcry!" << endl;
                cout << "You let out a powerful warcry that intimidates the " << monsterName << endl;
                cout << monsterName <<"'s health decreases by 12" << endl;
                currentMonster->decreaseHealth(12);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
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
        cout << "3. Blessing of the Stars" << endl;

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
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
                break;
            case 3:
                cout << "Blessing of the Stars !" << endl;
                cout << "The " << monsterName << "'s lose its sight due to the radiance you emit." << endl;
                cout << monsterName <<"'s health decreases by 20" << endl;
                currentMonster->decreaseHealth(20);
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
                break;
            default:
                cout << "Invalid option. Attack failed." << endl;
                break;
        }
    }
    else {
        cout << "Invalid role for attacking." << endl;
    }
    
}
void Player::guidanceItem()
{
	cout << "-------------------------------------------------------------" << endl;
	cout << "\tThis a guidance to choose item in inventory" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << " 1- Venom Stick (decrease monster's health by 15)" <<endl;
	cout << " 2- Elixir of Invisibility (decrease monster's health by 17)" <<endl;
	cout << " 3- Scroll of Fireball (decrease monster's health by 16)" <<endl;
	cout << " 4- Red Pill (increase player's health by 50)" <<endl;
	cout << "-------------------------------------------------------------" << endl <<endl;
}

void Player::useItem(Monster* currentMonster) {
	string monsterName = currentMonster->getName();
    cout << "Player uses an item!" << endl;
    cout << "Choose an item from your inventory:" << endl;
    guidanceItem();
    
	
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
            currentMonster->decreaseHealth(15);
            
            // Check if the monster is defeated
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << " is defeated!" << endl;
                    levelUp();
                }
            break;
            
        case 2:
            cout << "Elixir of Invisibility!" << endl;
            cout << "The " << monsterName << " are unable to see you, allowing you to freely attack them." << endl;
            cout << monsterName <<"'s health decrease by 17"<<endl;
            currentMonster->decreaseHealth(17);
            
            // Check if the monster is defeated
                if (currentMonster->getHealth() <= 0) {
                    cout << "The "<< monsterName << "is defeated!" << endl;
                    levelUp();
                }
            break;
            
        case 3:
            cout << "Scroll of Fireball!" << endl;
            cout << "The " <<monsterName << " are burned in fire." << endl;
            cout << monsterName <<"'s health decrease by 16"<<endl;
            currentMonster->decreaseHealth(16);
            
            // Check if the monster is defeated
                if (currentMonster->getHealth() <= 0) {
                    cout << "The " << monsterName << " is defeated!" << endl;
                    levelUp();
                }
            break;
        
        case 4:
        	cout << "Red Pill!" << endl;
        	cout << "Your health increases by 50" <<endl;
                health += 50;
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
    health += 50;
    gold +=1000;
}

bool Player::checkCredentials(string username, string password) {
    return (this->username == username && this->password == password);
}

void Player::purchase()
{
	cout << "Entering the item shop..." << endl;
    	cout << "Available items:" << endl;
    	cout << "1. Venom Stick - Price: 100 gold " << endl;
    	cout << "2. Elixir of Invisibility - Price: 200 gold" << endl;
    	cout << "3. Scroll of Fireball - Price: 150 gold" << endl;
    	cout << "4. Red Pill - Price: 100 gold" << endl;
    
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
        		int itemPrice = 100;
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
                    monster = new Monster("White Dragon", 3, 180);

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
                saveProgress();
                exit(0);
            default:
                cout << "Invalid choice. Exiting the game..." << endl;
                saveProgress();
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
                        if (level == 1){
                        	cout << endl <<  "************** Zombie Scenario *****************" << endl <<endl;
    						ifstream zombieFile("Zombie.txt");
   	 						string zombieParagraph;
    						while (getline(zombieFile, zombieParagraph)) {
        					if (zombieParagraph.empty()) {
            				continue;
        					}
        					typewriterEffect(zombieParagraph);
							cout << endl;
        					cout << "Press ENTER to continue...";
        					cin.ignore();
        					cout << endl;
    					}playLevel2();
						}
						
                        else if (level == 2){
                        	cout << endl <<  "************** White Dragon Scenario *****************" << endl <<endl;
    						ifstream dragonFile("White Dragon.txt");
    						string dragonParagraph;
    						while (getline(dragonFile, dragonParagraph)) {
        					if (dragonParagraph.empty()) {
           					continue;
        					}
        					typewriterEffect(dragonParagraph);
							cout << endl;
        					cout << "Press ENTER to continue...";
        					cin.ignore();
        					cout << endl;
    					}
    					 playLevel3();
						}
                           
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
                    	health=100;
                    	playLevel1();
                } else if (decision == 'N' || decision == 'n') {
                	saveProgress();
                    exit(0);
                }
                return;
            }
        }
    }
    
void Player :: saveProgress()
{
	ofstream outputFile("player_progress.txt");	
	if (outputFile.is_open()) {
        	outputFile << "Name: " << name << endl;
            outputFile << "Age: " << age << endl;
            outputFile << "Role: " << role << endl;
			outputFile << "Level: " << level << endl;
            outputFile << "Gold: " << gold << endl;
            outputFile << "Strength: " << strength << endl;
            outputFile << "Defense: " << defense << endl;
            outputFile << "Health: " << health << endl;

            outputFile.close();
            cout << "Player progress saved successfully." <<endl;
	} else {
		cout << "Unable to open the file for saving player progress." <<endl;
	}
}


#endif
