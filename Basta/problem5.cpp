#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Given a string find the min amount of chars needed to make 
//it a palindrome.

int main()
{
    string  s = "abcd";
    string sb = s;
    reverse(sb.begin(), sb.end());
    if(s == sb){
        cout << 0;
    }
    
    
    
    return 0;
}
