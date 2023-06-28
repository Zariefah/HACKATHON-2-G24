#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Game.h"
#include "Functions.h"

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    displayWelcomeMessage();
    Player* currentPlayer = nullptr;
    signUp(&currentPlayer);
    logIn(&currentPlayer);
    Game game;
    game.run(currentPlayer);
    deletePlayer(currentPlayer);
    return 0;
}
