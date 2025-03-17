#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    
    int countUpper = 0, countLower = 0;
    string word;
    cin >> word;
    
    for(int i  = 0; i < word.length(); i++){
        if(isupper(word[i])){
            countUpper++;
        }
        else{
            countLower++;
        }
    }
    if(countUpper > countLower){
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        cout << word << endl;
    }
    else{
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        cout << word << endl;
    }
    
    return 0;
}
