#include<iostream>

using namespace std;

/*
Problem:
Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
By starting with 1 and 2, the 10 terms wil be: 
 
    1,2,3,5,8,13,21,34,55,89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
find the sum of the even-valued terms.        

Solution:
Since odd + odd = even, then using this fact we can check if either the two previous numbers
are even if so dont add the next number to sum of the even-valued terms. 
Do this intill we reach 4 million in the Fibonacci sequence. 
*/

int main()
{
   int a = 1;
   int b = 2;
   int total = 2;

   for(int i = a + b; i < 4000000; i = a+b)
   {
        if(a % 2 == 0 or b % 2 == 0)
        {
            a = b;
            b = i; 
            continue; 
        }
        total += i; 
        a = b;
        b = i; 
   }
    cout << total << endl;

}