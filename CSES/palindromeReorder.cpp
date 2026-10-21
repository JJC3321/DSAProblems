
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    unordered_map<char, int> freq;

    for(char x : s){
        freq[x]++;
    }
    
    bool status = false;

    for(auto x : freq){
        if(x.second % 2 != 0){
            if(status == false){
                status = true;
            }
            else{
                cout << "NO SOLUTION";
                return 0;
            }
        }
    } 
    
    string left = "";
    string mid = "";

    for(auto x : freq){
        left.append(x.second / 2, x.first);
        if(x.second % 2 != 0){
            mid = string(1, x.first);
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    cout << left + mid + right;


    return 0;
}
