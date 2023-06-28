# HACKATHON 2 GROUP 24
## GROUP MEMBERS: 
1. ASILAH ZARIFAH BINTI ROSLI (160458)
2. SITI NAWWARAH BINTI MOHD ABD HADI (160304)
3. SITI NUR IZZAH BINTI ABDUL RAHMAN (160302)

## INTRODUCTION TO OUR TEXT-BASED GAME
## TITLE: Monster Chaos:The Final Apocalypse


### DESCRIPTION

  A text-based game, also known as a text adventure or interactive fiction, is a type of game that relies primarily on textual descriptions and user input. In a text-based game, the player interacts with the game world and progresses through the story by reading descriptive text and typing commands to perform actions.

  "Monster Chaos: The Final Apocalypse!" is an enticing role-playing game that transports players on an exciting expedition through a lively and enchanting fantasy realm. In this immersive journey, players take on the role of a brave hero, embarking on a quest to become formidable warriors by conquering the mighty Great Creature. Along the way, they encounter a diverse range of monsters, engage in strategic battles, and unravel the secrets of this magical world.

  In "Monster Chaos: The Final Apocalypse!" Players have the power to determine the outcome of their journey. By defeating the Great Creature, they demonstrate their prowess as aspiring soldiers. To achieve this feat, the player is given a role: priest, warrior, or mage that will be randomly determined by the game. Each role possesses unique abilities that contribute to their distinctive playstyle, adding depth and variety to the gameplay.

  In this game, players have the exciting opportunity to not only defeat fearsome monsters but also earn valuable rewards in the form of gold. As players engage in intense battles and emerge victorious against great enemies, they will be rewarded with gold based on their achievements. This gold serves as a currency within the game, allowing players to unlock a wide range of items to enhance their gameplay experience.

  With the gold they accumulate, players can visit the in-game marketplace and explore a vast selection of items, including powerful weapons, protective armour, and healing pills. These items can significantly bolster a player's combat abilities, increase their defence, or restore their health during challenging encounters.

  Victory in "Monster Chaos: The Final Apocalypse!" requires more than just brute strength. Players must employ cunning strategies, ensuring they manage their health effectively. If their health reaches zero, the game ends. Therefore, players must strike a balance between offensive and defensive tactics, make wise decisions to survive the encounter and emerge victorious. With engaging gameplay and a captivating storyline, "Monster Chaos: The Final Apocalypse!" promises an entertaining adventure filled with excitement, character development, and tactical challenges.







### FEATURES OF THE GAME

1. Sign up option: Allow new players to create an account.
2. Log in option: enable existing players to access their account and continue their gaming progress.
3. Main Scenario : establishing the basis for the game's main story while giving players a compelling plot to guide their actions and quests. 
4. Window status of player: print relevant informations about the player which are; name ,age,role,level,gold,strength,defense and health of player 
5. Sub Scenario (Goblin Forest, Zombie Dark City, White Dragon) :  Providing players with a variety gaming situation or encounters which include numerous type of enemy they must contend with, such as goblins, zombies, or the strong monster white Dragon.
6. Monster Status:Print name of monster at each level, the monster level and health.
7. Attack option: Allow player to engage in combat with the encountered monster, starting battle scene which the player can use the power or skill of the role to fight the opponent.
8. Use item option: Give benefits to players to win this game by utilizing the items player purchased and it will boosts player abilities such as increased their strength or enhanced magical powers to defeat the great monster. 
9. Purchase item option : Enables players to buy items from an in game marketplace using the gold they have earned by defeating the encountered monster. This option allows player to obtain powerful weapons, armour and health pill.
10. Inventory: Provides a space where player can view the items they purchased throughout their gaming journey. 
11. Retreat option:Players retreats from the battle and their health decreased but the monster health not decrease because it was regenerate
12. Exit option:Players end this game.




### HOW TO PLAY GAME

1. Please sign up before playing the game to save player’s data.
2. To start the game, player need to log in.
3. The main scenario will be print out. Please read the text to ensure you engage with the game.
4. Window player status will pop up on the screen and a role will be assigned at random. 
5. Player need to choose either to buy item , continue or exit. If player does not have sufficient amount of gold to buy necessary items, they need to choose “continue” option and proceed to level 1.
6. At level 1, players need to fight the Goblin Forest.
7. The Goblin Forest scenario will be printed out on the screen.
8. There will be three options for the player to choose (attack,use item or retreat) and these options will repeat every time the player enters a new level.
9. If players choose to attack, they need to choose their power option based on the role given to them until the monster is defeated. If players want to choose the option "use item", they need to purchase the item first. If the player chooses to retreat, the player needs to be against the goblin until it is defeated.
10. If players defeat the monster at level 1, players will go to level 2 where player need to against the second strongest monster, Zombie in the Dark City. And players are also rewarded with 1000 golds so they can buy the items to defeat this monster.
11. If players pass level 2, they will be rewarded with 1000 gold and face the strongest monster, the white dragon holy nest.
12. If the player loses to defeat the monster, they will have the option to restart the game or not.
13. If the player selects the exit option,  player will leave the game.


### HOW OBJECT-ORIENTED CONCEPTS WERE USED IN THIS GAME

In the "Monster Chaos: The Final Apocalypse!" game, several object-oriented concepts are utilised to structure the code and manage the game's functionality. Here's how these concepts are applied:
 
Classes are the essential building blocks of object-oriented programming in the game "Monster Chaos: The Final Apocalypse!" A variety of classes are used to represent game features like as objects Item, Node, Inventory, Monster,  Player, and Game For example, the Node class represents a node in a linked list and has properties such as "item" and "next," as well as a constructor method (init) to initialise node objects. The Item class is in charge of storing item names and returning them as necessary. The Monster class holds information on the name, level, and health status of a monster. Furthermore, the Player class use of composition by incorporating an instance of the Inventory class to manage player data and statuses.For the game class , it store the player status that player key in in player class and print the all scenario.

The classes Item, Node, Inventory, Monster,  Player, and Game  all have member variables and member functions declared with different access modifiers (private, public). This helps in encapsulating the internal implementation details of the class and controlling access to its members.

Objects are instances of classes, and they were created to represent specific instances of items, nodes, inventories, monsters, and players. In this game code,we create game objects to successfully run our code.
 
These object-oriented concepts help organise the code, promote reusability, and provide a clear structure to the game’s function.

### How Linked lists play a role in our game.

Linked list plays a crucial role in managing the players inventory in our coding.Here’ how it works:

Adding an item: When the player purchases a new item, the addItem function is called. This function creates a new Node object with the item's information and inserts it into the linked list. If the list is empty, the new node becomes the head of the list. Otherwise, the new node is inserted at the end of the list by traversing through the existing nodes using the next pointers.

Removing an item: When the player sells or discards an item, the removeItem function is called. This function searches for the node containing the item to be removed by traversing through the linked list. Once found, the function adjusts the next pointers of the previous and next nodes to bypass the node to be removed, effectively removing it from the list.

Retrieving an item: The getItem function allows the player to search for a specific item in the inventory. It traverses the linked list, comparing the item's information with each node's item. If a match is found, the function returns a pointer to the node containing the item. Otherwise, it returns a null pointer, indicating that the item is not present in the inventory.

Displaying the items: The displayItems function is responsible for printing the details of all the items in the inventory. It traverses through the linked list, starting from the head node, and prints the information of each item.

By using a linked list, player can dynamically add and remove items from the inventory without the need to allocate a fixed-size array. The linked list allows for efficient insertion and deletion operations, making it suitable for managing a dynamic collection of items.





### LINK TO GAME DEMO VIDEO
