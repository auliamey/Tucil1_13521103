#include <iostream>
#include <stdio.h>
using namespace std;

void defclr(){
    cout << "\033[0m";
}

void purple(){
    cout << "\033[0;35m";
}

void cyan(){
    cout << "\033[0;36m";
}

void green(){
    cout << "\033[0;32m";
}

void red(){
    cout << "\033[0;31m";
}

void yellow(){
    cout << "\033[0;33m";
}

void blue(){
    cout << "\033[0;34m";
}

void boldblue(){
    cout << "\033[1;34m";
}

void boldgreen(){
    cout << "\033[1;32m";
}

void boldcyan(){
    cout << "\033[1;36m";
}

void boldred(){
    cout << "\033[1;31m";
}

void boldpurple(){
    cout << "\033[1;35m";;
}

void boldyellow(){
    cout << "\033[1;33m";
}

void asciiarts() {
    boldcyan();
    cout << "\n\n              ******************************************************************************************************************\n";
    cout << "              ******************************************************************************************************************\n";
    cout << "              *****";
    boldpurple(); cout << "              ___    _  _              _______      ___      .___  ___.  _______      _______.";
    boldcyan(); cout << "          *****\n              *****";           
    boldpurple(); cout << "             |__ \\  | || |            /  _____|    /   \\     |   \\/   | |   ____|    /       |";
    boldcyan();cout << "          *****\n              *****";         
    boldpurple(); cout << "                ) | | || |_   ______ |  |  __     /  ^  \\    |  \\  /  | |  |__      |   (----`";
    boldcyan();cout << "          *****\n              *****";        
    boldpurple(); cout << "               / /  |__   _| |______||  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|      \\   \\";
    boldcyan();cout << "              *****\n              *****";        
    boldpurple(); cout << "              / /_     | |           |  |__| |  /  _____  \\  |  |  |  | |  |____ .----)   |";
    boldcyan();cout << "             *****\n              *****";       
    boldpurple(); cout << "             |____|    |_|            \\______| /__/     \\__\\ |__|  |__| |_______||_______/";
    boldcyan();cout << "              *****\n              *****";       
    boldcyan();cout << "                                                                                                        *****\n              *****";       
    boldyellow(); cout << "                      .______   ____    ____           __    ______    __       __ ";
    boldcyan();cout << "                     *****\n              *****";      
    boldyellow();cout << "                      |   _  \\  \\   \\  /   /          |  |  /  __  \\  |  |     |  |";
    boldcyan();cout << "                     *****\n              *****";    
    boldyellow();cout << "                      |  |_)  |  \\   \\/   /           |  | |  |  |  | |  |     |  |";
    boldcyan();cout << "                     *****\n              *****";    
    boldyellow();cout << "                      |   _  <    \\_    _/      .--.  |  | |  |  |  | |  |     |  |";
    boldcyan();cout << "                     *****\n              *****";
    boldyellow();cout << "                      |  |_)  |     |  |        |  `--'  | |  `--'  | |  `----.|  |";
    boldcyan();cout << "                     *****\n              *****";
    boldyellow();cout << "                      |______/      |__|         \\______/   \\______/  |_______||__|";
    boldcyan();cout << "                     *****\n              *****";
    cout << "                                                                                                        *****\n";
    cout << "              ******************************************************************************************************************\n";
    cout << "              ******************************************************************************************************************\n\n\n"; defclr();
}