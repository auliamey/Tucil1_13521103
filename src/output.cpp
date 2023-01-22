#include <fstream>
#include <string>
#include <iostream>
#include <vector>

void showSolve(vector<string>& hasil, int count){
    string solve;
    string space1 = " ", space2 = "  ";
    string awal = "                                                   ****        ", akhir = "       ";
    boldcyan();
    cout << "\n\n                                                   **************************************\n";
    cout << "                                                   ****      "; boldpurple(); cout << "SHOW THE SOLUTIONS?     ";
    boldcyan();
    cout << "****\n                                                   **************************************\n";
    cout << "                                                   ****                              ****\n";
    cout << "                                                   ****       "; boldyellow(); cout << "     1. YES            ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   ****        "; boldyellow(); cout << "    2. NO             ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   **************************************\n";
    enterNumber();
    cin >> solve; defclr();

    while ((solve != "1") and (solve != "2")){
        wrongInput();
        enterNumber();
        cin >> solve; defclr();
    }
    if (solve == "1"){
        boldcyan();
        cout << "\n\n                                                   **************************************\n";
        cout << "                                                   ****         "; boldpurple(); cout << "THE SOLUTIONS        ";
        boldcyan();
        cout << "****\n                                                   **************************************\n";
        cout << "                                                   ****                              ****\n";
        for (int i=0; i<hasil.size(); i++){
            if (count == 4){
                cout << awal; boldyellow(); cout<< hasil.at(i) << akhir;
            } else if (count == 3){
                cout << awal << space1; boldyellow(); cout<< hasil.at(i) << akhir;
            } else if (count == 2){
                cout << awal << space1; boldyellow(); cout<< hasil.at(i) << akhir << space1;
            } else if (count == 1){
                cout << awal << space2; boldyellow(); cout<< hasil.at(i) << akhir << space1;
            } else if (count == 0){
                cout << awal << space2; boldyellow(); cout<< hasil.at(i) << akhir << space2;
            }
            boldcyan();
            cout << "****\n                                                   ****                              ****\n";
        }
        cout << "                                                   **************************************\n";
    }
}

void saveFile(vector<string>& hasil, int ctr){
    string savefile;
    boldcyan();
    cout << "\n\n                                                   **************************************\n";
    cout << "                                                   ****        "; boldpurple(); cout << " SAVE TO FILE?        ";
    boldcyan();
    cout << "****\n                                                   **************************************\n";
    cout << "                                                   ****                              ****\n";
    cout << "                                                   ****       "; boldyellow(); cout << "     1. YES            ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   ****        "; boldyellow(); cout << "    2. NO             ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   **************************************\n";
    enterNumber();
    cin >> savefile; defclr();
    while ((savefile != "1") and (savefile != "2")){
        wrongInput();
        enterNumber();
        cin >> savefile; defclr();
    }

    if (savefile == "1"){
        string name;
        boldpurple(); cout << "                                                           Input file name  : ";
        cin >> name; defclr();

        string filename = name + ".txt";
        ofstream output("test/" + filename);

        if (output.is_open()){
            if (ctr == 0){
                output << "no solution found.\n";
            } else if (ctr == 1){
                output << ctr << " solution found\n";
            } else {
                output << ctr << " solutions found\n";
            }

            for (int i=0; i<hasil.size(); i++){
                output << hasil.at(i) << "\n";
            }
            output.close();
            boldblue();
            cout << "                                                              saved in " + filename + "\n";
        } else {
            boldred();
            cout << "                                                 There was a problem while opening the file\n";
        }
        defclr();
    }
}