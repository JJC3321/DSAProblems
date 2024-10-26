#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
Problem:
A palindormic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
Find the largest palindrome made from the product of two 3-digit numbers.

Solution:
Started with two integers with value of 999. 
Mutliple them and check if they are paildrome if so add it to the vector.
Then subtract 1 from 999 from one integer until it less then 3-digits and repat previous step.
Afterward reset the intger to 999 and subtract 1 from the other intger.
Do this intill both integer at less then 3-digit.  
Sort the vector from descending order. 
Then get the first value. 
*/
int main()
{
    int a = 999; 
    int b = 999;
    string number;
    bool status = true; 
    vector <int> palindrome; 

    while(a != 99)
    {
        number = to_string(a * b);
        int size = number.length() / 2;
        int temp = 1;
        for(int i = 0; i < size; i++)
        {
            if(number[i] != number[(size * 2) - temp])
            {
                status = true; 
                break;
            }
            temp++;
            status = false; 
        }
        if(status == false)
        {
            palindrome.push_back(stoi(number));
        }
        if(b - 1 == 99)
        {
            b = 999;
            a--;
        }
        else
        {
            b--; 
        }
    }
    sort(palindrome.rbegin(), palindrome.rend());
    cout << palindrome[0];


    
}