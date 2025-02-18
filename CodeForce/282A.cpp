#include <iostream>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s.find("+") != -1){
            ans++;
        }
        else{
            ans--;
        }
    }   
    cout << ans;
    
}   
