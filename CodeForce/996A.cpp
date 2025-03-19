#include <iostream>
using namespace std;

int main() {
    
    int n,a=0;
    cin >> n;
    while(n >= 100){
        n -= 100;
        a++;
    }
    while(n >= 20){
        n -= 20;
        a++;
    }
    while(n >= 10){
        n-= 10;
        a++;
    }
    while(n >= 5){
        n-=5;
        a++;
    }
    if(n != 0){
        a += n;
    }
    cout << a;

    return 0;
}
