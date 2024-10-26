#include<iostream>
using namespace std;

/*
Problem:
2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all
of the numbers from to 1 to 20? 

Solution:
Since 2520 is smallest evenely divisble number for all numbersd between 1-10.
Then 2520 can be use as starting number for 1 to 20 as previous numbers would fail the 1-20.
From there, check if the number evenly divisable from 1-20.
If not move to next number and repeat intill it is.
*/
int main()
{
    bool status = true;
    int number = 2520; 
    while(status == true)
    {
        for(int i = 1; i <= 20; i++)
        {
            if(number % i != 0)
            {
                number += 1; 
                break; 
            }
            if(i + 1 == 21) 
            {
                status = false; 
            }
        }
    }
    cout << number << endl; 
}