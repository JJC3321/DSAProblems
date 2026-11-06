#include <bits/stdc++.h>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;
    vector<int> a (n);
    vector<int> b (m);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<int> ans;

    int aPtr = 0;
    int bPtr = 0;

    while(aPtr < n or bPtr < m){
        
        if(aPtr == n){
            ans.push_back(b[bPtr]);
            bPtr++;
        }
        else if(bPtr == m){
            ans.push_back(a[aPtr]);
            aPtr++;
        }
        else if(a[aPtr] < b[bPtr]){
            ans.push_back(a[aPtr]);
            aPtr++;
        }
        else{
            ans.push_back(b[bPtr]);
            bPtr++;
        }
    }
    


    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}