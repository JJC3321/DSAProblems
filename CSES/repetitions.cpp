
#include <bits/stdc++.h>

using namespace std;

int main() {

    string DNA;
    cin >> DNA;
    long long  n = DNA.length();

    int ans = 1;
    int temp = 1;

    for(int i = 1; i < n; i++){

        if(DNA[i] == DNA[i-1]){
            temp++;
        }    
        else{
            ans = max(ans, temp);
            temp = 1;
        }
    
    }   
    ans = max(ans, temp);

    cout << ans;

    return 0;
}
