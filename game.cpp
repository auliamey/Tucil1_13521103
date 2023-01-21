#include <string>
#include <iostream>
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

void is24(string a, string b, string c, string d, vector<string> arrayhasil, double count){
    double num1 = strTodouble(a), num2 = strTodouble(b), num3 = strTodouble(c), num4 = strTodouble(d);
    double ab, bc, cd;
    string hasil;
    string operators[4] = {"+", "-", "*", "/"};

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            for (int k=0; k<4; k++){
                //(ab)(cd)
                //jadi (a operators[i] b) operators[j] (c operators[k] d)
                if (operations(operators[j], operations(operators[i], num1, num2),operations(operators[k], num3, num4)) == 24){
                    hasil = "(" + a + operators[i] + b + ")" + operators[j] + "(" + c + operators[k] + d + ")\n";
                    arrayhasil.push_back(hasil); 
                    count++;   
                }
                if (operations(operators[k],(operations(operators[j], operations(operators[i], num1, num2), num3)), num4) == 24){
                    //((ab)c)d
                    //((a operators[i] b) operators[j] c) operators[k] d
                    hasil = "((" + a + operators[i] + b + ")" + operators[j] + c + ")" + operators[k] + d + "\n";
                    arrayhasil.push_back(hasil);
                    count++; 
                }
                if (operations(operators[k], operations(operators[i], num1, operations(operators[j], num2, num3)), num4) == 24){
                    //(a(bc))d
                    //(a operators[i] (b operators[j] c)) operators[k] d
                    hasil = "(" + a + operators[i] + "(" + b + operators[j] + c + "))" + operators[k] + d + "\n";
                    arrayhasil.push_back(hasil);
                    count++;
                }
                if (operations(operators[i], num1, operations(operators[k], operations(operators[j], num2, num3), num4)) == 24){
                    //a((bc)d)
                    //a operators[i] ((b operators[j] c) operators[k] d)
                    hasil = a + operators[i] + "((" + b + operators[j] + c + ")" + operators[k] + d + ")\n"; 
                    arrayhasil.push_back(hasil);
                    count++;
                }
                if (operations(operators[i], num1, operations(operators[j], num2, operations(operators[k], num3, num4))) == 24){
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

    string fullcard = card1 + card2 + card3 + card4;
    string w1, w2, w3, w4;
    vector<string> arrpermute, arrayofhasil;
    permutation(fullcard, 0, arrpermute);
    double count = 0;

    for (int i=0; i<arrpermute.size(); i++){
        string temp = arrpermute.at(i);

        for (int j=0; fullcard[j]; ++j){
            if (j == 0){
                w1 = fullcard[j];
            } else if (j == 1){
                w2 = fullcard[j];
            } else if (j == 2){
                w3 = fullcard[j];
            } else if (j == 3) {
                w4 = fullcard[j];
            }
        }

        cout << "haha";

        is24(w1, w2, w3, w4, arrayofhasil, count);
    }

    cout << "Terdapat " << count << " solusi yang ditemukan.\n";

    for (int i=0; i<arrayofhasil.size(); i++){
        cout << arrayofhasil.at(i) << "\n";
    }

    // cout << w1 << "\n"<< w2 << "\n" << w3 << "\n" << w4 << "\n";

    // cout << strTodouble(card1) + strTodouble(card2) + strTodouble(card3) + strTodouble(card4) << "\n";

    return 0;
}