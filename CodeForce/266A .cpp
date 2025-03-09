#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int size;
    int ans = 0;
    cin >> size;
    cin >> s;
    for(int i = 1; i < size; i++){
        if(s[i-1] == s[i]){
            ans++;
        }
    }
    cout << ans;
}
