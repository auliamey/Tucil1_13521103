#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool checkInput(string Input){
    bool found = false;
    string input[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (int i=0; i<14; i++){
        if (Input == input[i]){
            found = true;
        }
    }
    
    return found;
}

double strTodouble (string X){
    string input[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    vector<int> inputsystem;

    for(int i=0; i<13; i++){
        inputsystem.push_back(i+1);
    }

    bool found = false;
    int it = 0;
    double val;

    while (!found){
        if (X == input[it]){
            found = true;
            val = inputsystem.at(it);
        }
        it++;
    }

    return val;
}