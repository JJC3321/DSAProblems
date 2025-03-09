#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    set<char> distChar;
    for(int i = 0; i < s.length(); i++){
        distChar.insert(s[i]);
    }
    if(distChar.size() % 2 == 0){
        cout << "CHAT WITH HER!";
    }
    else{
        cout << "IGNORE HIM!";
    }
    return 0;
}
