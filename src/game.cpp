#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include "ui.cpp"
#include "utility.cpp"
#include "bruteforce.cpp"
#include "output.cpp"
using namespace std;

int main() {
    string card1, card2, card3, card4;
    string w1, w2, w3, w4;
    string input;
    bool exit = false;

    asciiarts();
    while (exit != true){
        inputGenerate(card1, card2, card3, card4, exit);

        if (exit == false){
            int count = 0;
            int ctr = 0;
            vector<string> arrpermute, arrayofhasil;
            tenToZ(card1, card2, card3, card4, count);

            string fullcard = card1 + card2 + card3 + card4;
            clock_t start, end;

            //hitung waktu eksekusi program
            start = clock();
            
            permutation(fullcard, 0, arrpermute);
            singleString(w1, w2, w3, w4, ctr, arrpermute,arrayofhasil);

            end = clock();

            double duration_sec = double(end-start)/CLOCKS_PER_SEC;
            double duration_ms = duration_sec * 1000;
            
            boldcyan();
            if (ctr == 0){
                cout << "\n\n\n                                                            no solution found.";
            } else if (ctr == 1){
                cout << "\n\n\n                                                            " << ctr << " solution found.";
            } else {
                cout << "\n\n\n                                                            " << ctr << " solutions found.";
            }
            boldred();
            cout << "\n                                                         execution time : " << duration_ms << " ms\n"; defclr();

            if (ctr != 0){
                showSolve(arrayofhasil, count);
                saveFile(arrayofhasil, ctr);
            }
        }
    }
    return 0;
}