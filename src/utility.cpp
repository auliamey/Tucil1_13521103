#include <string>
#include <iostream>
#include <vector>
using namespace std;

void uicards(string& k1, string& k2, string& k3, string& k4){
    string symbol[4] = {"♦", "♣", "♥", "♠"};
    string n1, n2, n3, n4;


    int randsymbols1 = rand() % 3;
    int randsymbols2 = rand() % 3;
    int randsymbols3 = rand() % 3;
    int randsymbols4 = rand() % 3;

    if (k1 != "10"){
        n1 = k1 + " ";
    } else {
        n1 = "10";
    }
    if (k2 != "10"){
        n2 = k2 + " ";
    }else {
        n2 = "10";
    }
    if (k3 != "10"){
        n3 = k3 + " ";
    }else {
        n3 = "10";
    }
    if (k4 != "10"){
        n4 = k4 + " ";
    } else {
        n4 = "10";
    }
    

    boldblue();
    cout << "\n\n                              ____________          ____________          ____________          ____________ \n";         
    cout << "                             |"; boldyellow(); cout << symbol[randsymbols1] << n1; boldblue(); cout << "         |        |"; boldyellow(); cout << symbol[randsymbols2] << n2; boldblue(); cout << "         |        |"; boldyellow(); cout<< symbol[randsymbols3] << n3; boldblue(); cout <<"         |        |"; boldyellow(); cout << symbol[randsymbols4] << n4; boldblue(); cout << "         |\n";
    cout << "                             |            |        |            |        |            |        |            |\n";
    cout << "                             |            |        |            |        |            |        |            |\n";
    cout << "                             |            |        |            |        |            |        |            |\n";
    cout << "                             |     "; boldyellow(); cout << symbol[randsymbols1] << n1; boldblue(); cout << "    |        |     "; boldyellow(); cout << symbol[randsymbols2] << n2; boldblue(); cout << "    |        |     "; boldyellow(); cout << symbol[randsymbols3] << n3;boldblue(); cout << "    |        |     "; boldyellow(); cout << symbol[randsymbols4] << n4;boldblue(); cout << "    |\n";
    cout << "                             |            |        |            |        |            |        |            |\n";
    cout << "                             |            |        |            |        |            |        |            |\n";
    cout << "                             |            |        |            |        |            |        |            |\n";

    if (k1 == "10"){
        cout << "                             |_________"; boldyellow(); cout << symbol[randsymbols1] << k1;
    } else {
        cout << "                             |__________"; boldyellow(); cout << symbol[randsymbols1] << k1;
    }
    if (k2 == "10"){
        boldblue(); cout << "|        |_________"; boldyellow(); cout << symbol[randsymbols2] << k2;
    } else {
        boldblue(); cout << "|        |__________"; boldyellow(); cout << symbol[randsymbols2] << k2;
    }
    if (k3 == "10"){
        boldblue(); cout << "|        |_________"; boldyellow(); cout << symbol[randsymbols3] << k3;
    } else {
        boldblue(); cout << "|        |__________"; boldyellow(); cout << symbol[randsymbols3] << k3;
    }
    if (k4 == "10"){
        boldblue(); cout <<"|        |_________"; boldyellow(); cout << symbol[randsymbols4] << k4;boldblue(); cout << "|\n"; defclr();
    } else{
        boldblue(); cout <<"|        |__________"; boldyellow(); cout << symbol[randsymbols4] << k4;boldblue(); cout << "|\n"; defclr();
    }

    cout << "\n\n";
    boldpurple();
    cout << "                                                                Your Cards : \n";
    boldyellow();
    cout << "                                                                  " << k1 << " " << k2 << " " << k3 << " " << k4; defclr();                                   
}

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

void wrongInput(){
    boldred(); cout << "                                                               Wrong Input!";
    cout << "\n                                                            Re-Enter a Number!";
}

void enterNumber(){
    boldpurple(); cout << "\n                                                             Enter a number : ";
}

void inputGenerate (string& k1, string& k2, string& k3, string& k4, bool& exit){
    string input;
    boldcyan();
    cout << "\n\n                                                   **************************************\n";
    cout << "                                                   ****         "; boldpurple(); cout << "    MENU             ";
    boldcyan();
    cout << "****\n                                                   **************************************\n";
    cout << "                                                   ****                              ****\n";
    cout << "                                                   ****       "; boldyellow(); cout << "1. RANDOM CARDS        ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   ****        "; boldyellow(); cout << "2. INPUT USER         ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   ****           "; boldyellow(); cout << "3. EXIT            ";
    boldcyan();
    cout << "****\n                                                   ****                              ****\n";
    cout << "                                                   **************************************\n";
    enterNumber();
    cin >> input; defclr();

    while ((input != "1") and (input != "2") and (input != "3")){
        wrongInput();
        enterNumber();
        cin >> input; defclr();
    }

    if (input == "1"){
        boldyellow();
        cout << "\n\n\n                                                   ======================================\n";
        cout << "                                                   ====         "; boldblue(); cout << "RANDOM CARDS         ";
        boldyellow();
        cout << "====\n                                                   ======================================\n";
        srand(time(NULL));
        string arrofcards[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

        int randIndex1 = rand() % 13;
        int randIndex2 = rand() % 13;
        int randIndex3 = rand() % 13;
        int randIndex4 = rand() % 13;
        k1 = arrofcards[randIndex1];
        k2 = arrofcards[randIndex2];
        k3 = arrofcards[randIndex3];
        k4 = arrofcards[randIndex4];

        uicards(k1,k2,k3,k4);
    } else if (input == "2"){
        boldpurple(); cout << "\n                                                        Enter 1st card number : ";
        cin >> k1;
        bool cek = checkInput(k1);
        while (cek == false){
            wrongInput();
            boldpurple(); cout << "\n                                                        Enter 1st card number : ";
            cin >> k1;
            cek = checkInput(k1);
        }
        boldpurple(); cout << "\n                                                        Enter 2nd card number : ";;
        cin >> k2;
        cek = checkInput(k2);
        while (cek == false){
            wrongInput();
            boldpurple(); cout << "\n                                                        Enter 2nd card number : ";
            cin >> k2;
            cek = checkInput(k2);
        }
        boldpurple(); cout << "\n                                                        Enter 3rd card number : ";
        cin >> k3;
        cek = checkInput(k3);
        while (cek == false){
            wrongInput();
            boldpurple(); cout << "\n                                                        Enter 3rd card number : ";
            cin >> k3;
            cek = checkInput(k3);
        }
        boldpurple(); cout << "\n                                                        Enter 4th card number : ";
        cin >> k4;
        cek = checkInput(k4);
        while (cek == false){
            wrongInput();
            boldpurple(); cout << "\n                                                        Enter 4th card number : ";
            cin >> k4;
            cek = checkInput(k4);
        }

        uicards(k1, k2, k3, k4);
    } else if (input == "3"){
        exit = true;
    }
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
