#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std; 

int main(){
    int a, b;
    vector<int> array; 
    cin >> a >> b; 
    array.push_back(a);
    array.push_back(b);
    if(count(array.begin(), array.end(), 1) == false){
        cout << 1; 
    }
    else if(count(array.begin(), array.end(), 2) == false){
        cout << 2;
    }
    else{
        cout << 3;
    }
}