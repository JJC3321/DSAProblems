#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    int a, d;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            a++;
        }
        else if(s[i] == 'D'){
            d++;
        }
    }
    if(a == d){
        cout << "Friendship";
    }
    else if(a > d){
        cout << "Anton";
    }
    else if(a < d){
        cout << "Danik";
    }
    
    return 0;
}
