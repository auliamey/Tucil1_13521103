#include <string>
#include <iostream>
#include <vector>

double operations (string op, double num1, double num2){
    //operasi matematika
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

void tenToZ(string& k1, string& k2, string& k3, string& k4, int& count){
    //Mengubah string 10 yang berupa dua digit menjadi string 1 huruf untuk di permutasi
    if (k1 == "10"){
        k1 = "Z";
        count++;
    }
    if (k2 == "10"){
        k2 = "Z";
        count++;
    }
    if (k3 == "10"){
        k3 = "Z";
        count++;
    }
    if (k4 == "10"){
        k4 = "Z";
        count++;
    }
}

void permutation(string& kartu, int n, vector<string>& hasil){
    double temp;
    int cardLength = kartu.length();

    if(n == cardLength){
        bool found = false;
        int i = 0;
        // cek in case kalo input nya ada yang sama
        while (!found && i < hasil.size()){
            if (kartu == hasil.at(i)){
                found = true;
            }
            i++;
        }
        //kalau berbeda, di pushback ke vector hasil
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
    //Menghitung dengan operasi matematika dan kemungkinan kurung
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
                    hasil = "(" + a + operators[i] + b + ")" + operators[j] + "(" + c + operators[k] + d + ")";
                    arrayhasil.push_back(hasil); 
                    count++;   
                }
                if (operations(operators[k], operations(operators[j], ab, num3), num4) == 24){
                    //((ab)c)d
                    //((a operators[i] b) operators[j] c) operators[k] d
                    hasil = "((" + a + operators[i] + b + ")" + operators[j] + c + ")" + operators[k] + d;
                    arrayhasil.push_back(hasil);
                    count++; 
                }
                if (operations(operators[k], operations(operators[i], num1, bc), num4) == 24){
                    //(a(bc))d
                    //(a operators[i] (b operators[j] c)) operators[k] d
                    hasil = "(" + a + operators[i] + "(" + b + operators[j] + c + "))" + operators[k] + d;
                    arrayhasil.push_back(hasil);
                    count++;
                }
                if (operations(operators[i], num1, operations(operators[k], bc, num4)) == 24){
                    //a((bc)d)
                    //a operators[i] ((b operators[j] c) operators[k] d)
                    hasil = a + operators[i] + "((" + b + operators[j] + c + ")" + operators[k] + d + ")"; 
                    arrayhasil.push_back(hasil);
                    count++;
                }
                if (operations(operators[i], num1, operations(operators[j], num2, cd)) == 24){
                    //a(b(cd))
                    //a operators[i] (b operators[j] (c operators[k] d))
                    hasil = a + operators[i] + "(" + b + operators[j] + "(" + c + operators[k] + d + "))";
                    arrayhasil.push_back(hasil); 
                    count++;
                }
            }
        }
    }
} 

void singleString(string& k1, string& k2, string& k3, string& k4, int& count, vector<string>& hasilpermutasi, vector<string>& hasil){
    //Memisahkan hasil permutasi menjadi perdigit
    for (int i=0; i<hasilpermutasi.size(); i++){
        string temp = hasilpermutasi.at(i);
        for (int j=0; temp[j]; ++j){
            //string permutasi dipisah satu satu misal "ABCD" jadi{"A", "B", "C", "D"}
            if (j == 0){
                if (temp[j] == 'Z'){
                    k1 = "10";
                } else {
                    k1 = temp[j];
                }
            } else if (j == 1){
                if (temp[j] == 'Z'){
                    k2 = "10";
                } else {
                    k2 = temp[j];
                }
            } else if (j == 2){
                if (temp[j] == 'Z'){
                    k3 = "10";
                } else {
                    k3 = temp[j];
                }
            } else if (j == 3) {
                if (temp[j] == 'Z'){
                    k4 = "10";
                } else {
                    k4 = temp[j];
                }
            }
        }
        is24(k1, k2, k3, k4, hasil, count);
    }
}