#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "Monster.h"
#include "Player.h"
#include "typewriterEffect.h"
#include "Functions.h"

using namespace std;

// Forward declarations
class Monster;
class Player;

class Game{
	public:
		void run(Player* currentPlayer){
			enterGame(currentPlayer);
		}
		
	private:
	void enterGame(Player* currentPlayer) {
    cout << "************** Game **************************" << endl;
    cout << "Welcome to the game, " << currentPlayer->username << "!" << endl;
    cout << endl << "************** Main Scenario *****************" << endl;
    
	// Main Scenario
    ifstream scenarioFile("Scenario.txt");
    string scenarioParagraph;
    while (getline(scenarioFile, scenarioParagraph)) {
        if (scenarioParagraph.empty()) {
            continue;
        }
        typewriterEffect(scenarioParagraph);
		cout << endl;
        cout << "Press ENTER to continue...";
        cin.ignore();
        cout << endl;
    }
    currentPlayer->printWindowStatus();
    
    cout << endl << "Let's continue your journey in this game!" << endl;
    
	// Level 1: Goblin
    cout << endl <<  "************** Goblin Scenario *****************" << endl <<endl;
    ifstream goblinFile("Goblin.txt");
    string goblinParagraph;
    while (getline(goblinFile, goblinParagraph)) {
        if (goblinParagraph.empty()) {
            continue;
        }
        typewriterEffect(goblinParagraph);
		cout << endl;
        cout << "Press ENTER to continue...";
        cin.ignore();
        cout << endl;
    }
    
    currentPlayer->playLevel1();    
    cout << "*************************************************************" << endl;
    cout << "Congratulations, you have defeat all monsters." <<endl;
	cout << "Let's meet again in Monster Chaos: The Final Apocalypse 2.0" <<endl;
    cout << "*************************************************************" << endl;
}
};


#endif
 
