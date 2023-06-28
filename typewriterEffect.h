#ifndef TYPEWRITEREFFECT_H
#define TYPEWRITEREFFECT_H
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void typewriterEffect(const string& text) {
    for (char c : text) {
        cout << c;
        cout.flush();  // Ensures immediate output to the console
        this_thread::sleep_for(chrono::milliseconds(50));  // Adjust the delay duration as needed
    }
}
#endif
