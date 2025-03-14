/*
ID: jianjin5
Task: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    int num = 0, product = 1;
    int num2 = 0, product2 = 1;
    fin >> a >> b
    for(int i = 0; i < a.length(); i++){
        sum = a[i] - 'A' + 1; 
        proudct *= sum;
    }
    for(int i = 0; i < b.length(); i++){
        sum2 = b[i] - 'A' +1;
        product2 *= sum2;
    }
    if(product % 47 == product2 % 47){
        fout << "GO" << endl;
    }
    else{
        fcout << "STAY" << endl;
    }
    
    return 0;
}
