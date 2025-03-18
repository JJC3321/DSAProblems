#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;


int main()
{
    int n;
    bool status = true;
    string s;
    vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};    
    cin >> n >> s;
    if(n < 26){
        cout << "No";
        status = false;
    }
    else{
        for(int i = 0; i < 26; i++){
            if(s.find(letters[i]) == string::npos and s.find(toupper(letters[i])) == string :: npos){
                cout << "NO";
                status = false;
                break;
            }
        }
    }
    if(status == true){
        cout << "YES";
    }
    
    return 0;
}
