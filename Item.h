#ifndef ITEM_H
#define ITEM_H
#include <iostream>

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


#endif
