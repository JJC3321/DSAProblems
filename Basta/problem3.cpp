#include <iostream>
#include <string>

using namespace std;

//Given two string, string a and string b determine whether an anagram
//of string-b occurs in string

bool isSubAnagram(string a, string b){
    int lengthB = b.length();
    int lengthA = a.length();
    bool status = false;
    if(lengthA < lengthB){
        return false;
    }
    else if(lengthA == 0 or lengthB == 0){
        return false;
    }
    for(int i = 0; i < lengthA; i++){
        for(int k = i; k < lengthB; k++){
            if(b[k] == a[k]){
                status = true;
            }
            else{
                status = false;
                break;
            }
        }        
        
    }
    return status;
}   


int main()
{
    string a = "tabular";
    string b = "bat";
    cout << isSubAnagram(a,b) << endl;
}
