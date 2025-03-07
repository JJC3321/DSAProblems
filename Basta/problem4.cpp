#include <iostream>
#include <string>

using namespace std;

//Given a string find the first occurence of char that is 
//not repeating. 


int main()
{
    string s = "bannana";
    char ans = '\0'; 
    if(s.length()  == 0){
        cout << " " << endl;
    }
    else if(s.length() == 1){
        cout << s << endl;
    }
    for(int i = 0; i < s.size(); i++){
        ans = s[i];
        for(int k = i+1; k < s.size(); k++){
            if(ans == s[k]){
                ans = '\0'; 
                break;
            }
        }
        if (ans != '\0') { 
            break; 
        }
    }
    cout << ans;
    
    return 0;
}
