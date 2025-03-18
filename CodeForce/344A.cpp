#include <iostream>
#include <vector> 
using namespace std;

int main() {

    int n, count = 1;
    vector<int> m; 
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m.push_back(a);
    }
    for(int i = 0; i < n- 1; i++){
        if( m[i] != m[i+1]){
            count++;
        }
    }
    cout << count; 
    return 0;
}
