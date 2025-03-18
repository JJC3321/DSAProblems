#include <iostream>

using namespace std;

int main() {

    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 1){
            cout << "HARD";
            break;
        }
        else if(i + 1 == n){
            cout << "EASY"; 
        }
    }
    

    
    return 0;
}
