#include <iostream>
using namespace std;


int main() {
    
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 4 != 0){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    
    return 0;
}
