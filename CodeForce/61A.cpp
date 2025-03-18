#include <iostream>

using namespace std;

int main() {
    string n, m;
    cin >> n >> m;
    int size = n.length();
    for(int i = 0; i < size; i++){
        if(n[i] == m[i]){
            cout << 0;
        }
        else{
            cout << 1;
        }
    }
    

    return 0;
}
