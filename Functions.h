#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function prototypes
void displayWelcomeMessage();
void signUp(Player** currentPlayer);
void logIn(Player** currentPlayer);
void deletePlayer(Player* currentPlayer);

void displayWelcomeMessage() {
    cout << "Welcome to the Monster Chaos: The Final Apocalypse!" << endl;
	cout << "	          ,      ," << endl;
	cout << "	         /(.-\"\"-.)\\" << endl;
	cout << "	     |\\  \\/      \\/  /|" << endl;
	cout << "	     | \\ / =.  .= \\ / |" << endl;
	cout << "	     \\( \\   o\\/o   )/" << endl;
	cout << "	      \\_, '-/  \\-' ,_/" << endl;
	cout << "	        /   \\__/   \\" << endl;
	cout << "	        \\,___/\\___,/" << endl;

				       
	cout << "**********************************************" << endl;
    cout << "Instructions:" << endl;
    cout << "- Sign up or log in to play the game." << endl;
    cout << "- Defeat monsters to level up and earn coins." << endl;
    cout << "- Use coins to buy items from the inventory." << endl;
    cout << "- Good luck and have fun!" << endl;
    cout << "**********************************************" << endl;
}

void signUp(Player** currentPlayer) {
    string username, password;
    cout << "************ Sign Up *************************" << endl;
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
    cout << "************* Log In *************************" << endl;
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



#endif
