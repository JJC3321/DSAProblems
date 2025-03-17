#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    string t, s;
    cin >> s >> t;
    
    reverse(t.begin(), t.end());
    if(t == s){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    
    
    return 0;
}
