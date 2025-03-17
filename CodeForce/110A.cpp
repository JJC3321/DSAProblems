#include <iostream>
#include <string>

using namespace std;

int main() {
    
    long long n;
    cin >> n;
    int counter = 0;
    string num = to_string(n);
    for(int i = 0; i < num.length(); i++){
        if(num[i] == '7' or num[i] == '4'){
            counter++;
        }
    }
    if(counter == 4 or counter == 7){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
