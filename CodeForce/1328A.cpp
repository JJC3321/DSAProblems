#include <iostream>
using namespace std;

int main()
{
    int t, counter = 0; 
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b; 
        cin>> a >> b;
        if(a % b == 0){
            cout << 0 << endl;
        }
        else{
            cout << b - (a % b) << endl;
        }
    }
    
    return 0;
}
