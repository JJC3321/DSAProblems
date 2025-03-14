/*
ID: jianjin5
PROB: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n, moneyToGiveOut, numberOfPeople;
    string name;
    map <string, int> money;
    fin >> n; 
    vector<string> names(n);
    for(int i = 0; i < n; i++)
    {
        fin >> name;
        money[name] = 0;
        names[i] = name;
    }
    for(int i = 0; i < n; i++){
        fin >> name >> moneyToGiveOut >> numberOfPeople;
        if (numberOfPeople != 0)
            money[name] -=  ( moneyToGiveOut / numberOfPeople) * numberOfPeople;
            for(int k = 0; k < numberOfPeople; k++){
                fin >> name;
                money[name] += moneyToGiveOut / numberOfPeople; 
            }
    }
    for (int i = 0; i < n; i++){
        fout << names[i] << " " << money[names[i]] << endl;
    }    
    
    return 0;
}
