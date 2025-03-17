#include <iostream>
#include <set>

using namespace std;

int main() {

    int y = 0;
    string s;
    cin >> y; 

    if(y >= 1987 and y < 2013){
        cout << 2013; 
    }
    else{
        while(true){
            y += 1;
            s = to_string(y);
            set<int> uniDigits(s.begin(), s.end());
            if(s.length() == uniDigits.size())
                break;
        }  
    }
    
    cout << s;
    
    return 0;
}
