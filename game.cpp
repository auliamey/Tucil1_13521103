#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

double operations (string op, double num1, double num2){
    double hasil;

    if (op == "+"){
        hasil = num1 + num2;
    } else if (op == "-"){
        hasil = num1 - num2;
    } else if (op == "*"){
        hasil = num1 * num2;
    } else if (op == "/"){
        hasil = num1 / num2;
    }

    return hasil;
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

void permutation(string& kartu, int n, vector<string>& hasil){
    double temp;
    int cardLength = kartu.length();

    if(n == cardLength){
        bool found = false;
        int i = 0;
        // in case kalo input nya ada yang sama
        while (!found and i < hasil.size()){
            if (kartu == hasil.at(i)){
                found = true;
            }
            i++;
        }
        if (!found){
            hasil.push_back(kartu);
            return;
        }
    }
    
    for (int i=n; kartu[i]; ++i){
        temp = kartu[n];
        kartu[n] = kartu[i];
        kartu[i] = temp;
        permutation(kartu, n+1, hasil);
        temp = kartu[n];
        kartu[n] = kartu[i];
        kartu[i] = temp;
    }
}

void is24(string a, string b, string c, string d, vector<string>& arrayhasil, int& count){
    double num1 = strTodouble(a), num2 = strTodouble(b), num3 = strTodouble(c), num4 = strTodouble(d);
    double ab, bc, cd;
    string hasil;
    string operators[4] = {"+", "-", "*", "/"};

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            for (int k=0; k<4; k++){
                ab = operations(operators[i], num1, num2);
                bc = operations(operators[j], num2, num3);
                cd = operations(operators[k], num3, num4);

                //(ab)(cd)
                //jadi (a operators[i] b) operators[j] (c operators[k] d)
                if (operations(operators[j], ab, cd) == 24){
                    hasil = "(" + a + operators[i] + b + ")" + operators[j] + "(" + c + operators[k] + d + ")\n";
                    arrayhasil.push_back(hasil); 
                    count++;   
                }
                if (operations(operators[k], operations(operators[j], ab, num3), num4) == 24){
                    //((ab)c)d
                    //((a operators[i] b) operators[j] c) operators[k] d
                    hasil = "((" + a + operators[i] + b + ")" + operators[j] + c + ")" + operators[k] + d + "\n";
                    arrayhasil.push_back(hasil);
                    count++; 
                }
                if (operations(operators[k], operations(operators[i], num1, bc), num4) == 24){
                    //(a(bc))d
                    //(a operators[i] (b operators[j] c)) operators[k] d
                    hasil = "(" + a + operators[i] + "(" + b + operators[j] + c + "))" + operators[k] + d + "\n";
                    arrayhasil.push_back(hasil);
                    count++;
                }
                if (operations(operators[i], num1, operations(operators[k], bc, num4)) == 24){
                    //a((bc)d)
                    //a operators[i] ((b operators[j] c) operators[k] d)
                    hasil = a + operators[i] + "((" + b + operators[j] + c + ")" + operators[k] + d + ")\n"; 
                    arrayhasil.push_back(hasil);
                    count++;
                }
                if (operations(operators[i], num1, operations(operators[j], num2, cd)) == 24){
                    //a(b(cd))
                    //a operators[i] (b operators[j] (c operators[k] d))
                    hasil = a + operators[i] + "(" + b + operators[j] + "(" + c + operators[k] + d + "))\n";
                    arrayhasil.push_back(hasil); 
                    count++;
                }
            }
        }
    }
} 


int main() {
    string card1, card2, card3, card4;
    string input;
    string w1, w2, w3, w4;
    vector<string> arrpermute, arrayofhasil;


    ofstream output("/Users/auliameydivaannandya/Documents/GitHub/24-Games/output.txt", std::ofstream::out);

    cout << "Pilihan Input : \n";
    cout << "1. Random Number \n2. Input User\n";
    cout << "Masukkan pilihan : ";
    cin >> input;

    while ((input != "1") and (input != "2")){
        cout << "\n*    INPUT SALAH!!!    * \n* Masukkan Input Ulang *\n\n";
        cout << "Masukkan pilihan : ";
        cin >> input;
    }

    if (input == "1"){
        srand(time(NULL));

        string arrofcards[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

        int randIndex1 = rand() % 13;
        int randIndex2 = rand() % 13;
        int randIndex3 = rand() % 13;
        int randIndex4 = rand() % 13;
        card1 = arrofcards[randIndex1];
        card2 = arrofcards[randIndex2];
        card3 = arrofcards[randIndex3];
        card4 = arrofcards[randIndex4];

        cout << "Kartu yang didapatkan : " << endl << card1 << " " << card2 << " " << card3 << " " << card4 << endl;
    } else if (input == "2"){
        cout << "Masukkan kartu pertama: ";
        cin >> card1;
        bool cek = checkInput(card1);
        while (cek == false){
            cout << "\n*    INPUT SALAH!!!    * \n* Masukkan Input Ulang *\n\n";
            cout << "Masukkan kartu pertama: ";
            cin >> card1;
            cek = checkInput(card1);
        }
        cout << "Masukkan kartu kedua: ";
        cin >> card2;
        cek = checkInput(card2);
        while (cek == false){
            cout << "\n*    INPUT SALAH!!!    * \n* Masukkan Input Ulang *\n\n";
            cout << "Masukkan kartu kedua: ";
            cin >> card2;
            cek = checkInput(card2);
        }
        cout << "Masukkan kartu ketiga: ";
        cin >> card3;
        cek = checkInput(card3);
        while (cek == false){
            cout << "\n*    INPUT SALAH!!!    * \n* Masukkan Input Ulang *\n\n";
            cout << "Masukkan kartu ketiga: ";
            cin >> card3;
            cek = checkInput(card3);
        }
        cout << "Masukkan kartu keempat: ";
        cin >> card4;
        cek = checkInput(card4);
        while (cek == false){
            cout << "\n*    INPUT SALAH!!!    * \n* Masukkan Input Ulang *\n\n";
            cout << "Masukkan kartu keempat: ";
            cin >> card4;
            cek = checkInput(card4);
        }
    }

    if (card1 == "10"){
        card1 = "Z";
    }
    if (card2 == "10"){
        card2 = "Z";
    }
    if (card3 == "10"){
        card3 = "Z";
    }
    if (card4 == "10"){
        card4 = "Z";
    }

    string fullcard = card1 + card2 + card3 + card4;
    permutation(fullcard, 0, arrpermute);
    int ctr = 0;

    for (int i=0; i<arrpermute.size(); i++){
        string temp = arrpermute.at(i);

        for (int j=0; temp[j]; ++j){
            if (j == 0){
                if (temp[j] == 'Z'){
                    w1 = "10";
                } else {
                    w1 = temp[j];
                }
            } else if (j == 1){
                if (temp[j] == 'Z'){
                    w2 = "10";
                } else {
                    w2 = temp[j];
                }
            } else if (j == 2){
                if (temp[j] == 'Z'){
                    w3 = "10";
                } else {
                    w3 = temp[j];
                }
            } else if (j == 3) {
                if (temp[j] == 'Z'){
                    w4 = "10";
                } else {
                    w4 = temp[j];
                }
            }
        }

        is24(w1, w2, w3, w4, arrayofhasil, ctr);
    }

    string solve, savefile;

    cout << "\nTerdapat " << ctr << " solusi yang ditemukan.\n";

    if (ctr != 0){
        cout << "Show the solve? (yes/no) : ";
        cin >> solve;

        while ((solve != "yes") and (solve != "no")){
            cout << "Input yang anda masukkan salah!\n Masukkan input ulang!\n";
            cout << "Tunjukkan hasil? (yes/no) : ";
            cin >> solve;
        }

        if (solve == "yes"){
            cout << "Menunjukkan hasil :\n";
            for (int i=0; i<arrayofhasil.size(); i++){
                cout << arrayofhasil.at(i) << "\n";
            }
        }

        cout << "\nApakah Anda ingin menyimpan di file? (yes/no) :  ";
        cin >> savefile;
        while ((savefile != "yes") and (savefile != "no")){
            cout << "Input yang anda masukkan salah!\n Masukkan input ulang!\n";
            cout << "\nApakah Anda ingin menyimpan di file? (yes/no) :  ";
            cin >> savefile;
        }

        if (savefile == "yes"){
            if (output.is_open()){
                for (int i=0; i<arrayofhasil.size(); i++){
                    output << arrayofhasil.at(i) << "\n";
                }
                output.close();
            } else {
                cout << "Terdapat masalah dalam pembukaan file\n";
            }
        }
    }
    
    return 0;
}