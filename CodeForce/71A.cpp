
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num; 
    string word;
    cin >> num;
    vector<string> arryString;
    for(int i = 0; i < num; i++){
        cin >> word;
        int size = word.length();
        if(size > 10){
            cout << word[0] + to_string(size - 2) + word[size - 1] << endl;
        }
        else{
            cout << word << endl; 
        }
    } 
    return 0;
}
