#include<iostream>

using namespace std;

//Problem
/*
If we list all the natural numbers below 10 that are multiples of 
3 or 5, we get 3.5, 6, and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/


/*
Using the initial count of 23 for all sums multiples of 3 or 5 
we then use a for loop to add any natural numbers that are
multiples of 3 or 5 until we reach 1000. Then, get the total.
*/

int main()
{
    int total = 23;
    for(int i = 10; i < 1000; i++)
    {
        if(i % 3 == 0 or i % 5 == 0)
        {
            total += i;
        }
    }

    cout << total << endl; 
}
