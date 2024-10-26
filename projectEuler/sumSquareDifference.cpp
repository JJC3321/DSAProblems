#include<iostream>
#include <cmath>
using namespace std;

/*
Problem:
The sum of th squares of the first then natural numbers is,
    1^2 + 2^2 + ... + 10^2 = 385
The square of the sum o the first ten naturalnumbers is,
    (1+2+...+10)^2 = 55^2 = 3025 
Hence the difference between the sum of the squares of the 
first ten natural numbers and the square of the sum is 3025-385 =2640.
Find the difference between the sum of the squares of the first 
one hundred natural numbers and the square of the sum.

Solution:
Use for loop to add numbers for square of the sum and
sum of the squares. Then subtract the difference
*/
int main()
{
    int sumSquares = 0;
    int squareSums = 0;
    for(int i = 1; i <= 100; i++)
    {
        sumSquares += pow(i, 2); 
        squareSums += i;
    }
    squareSums = pow(squareSums,2); 
    int difference = squareSums - sumSquares;
    cout << difference; 
}