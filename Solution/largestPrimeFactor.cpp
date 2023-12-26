#include<iostream>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;

/*
Problem:
The prime factors of 13195 are 5,7,13, and 29.
What is the largest prime factor of the number 600851475143?

Solution:
Since 600851475143 is composite number then prime is less then
square root of the composite. Then taking the square root of the
composite and using the Sieve of Eratosthenes to gain all the
prime numbers leading up to the square root composite.
Then divide the composite number with those prime numbers to find 
the largest prime factor.
*/
void sieveOfEratosthenes(int checkPrime, vector<int>& primesNumbers)
{
    bool status[checkPrime + 1];
    memset(status,true, sizeof(status));
    for(int i = 2; i * i <= checkPrime; i++)
    {
        if(status[i] == true)
        {
            for(int k = i * i; k <= checkPrime; k += i)
            {
                status[k] = false; 
            }
        }
    }
    for(int i = 2; i <= checkPrime; i++)
    {
        if(status[i] == true)
        {
           primesNumbers.push_back(i);
        }
    }

}

int main()
{
    long long  checkNumber = 600851475143;
    int largestPrime = 0;
    int checkPrime = sqrt(checkNumber);
    vector <int> primesNumbers;
    sieveOfEratosthenes(checkPrime, primesNumbers);
    for(int i = 0; i < primesNumbers.size(); i++)
    {
        if(checkNumber % primesNumbers[i] == 0)
        {
            largestPrime = primesNumbers[i];
        }
    }
    cout << largestPrime << endl; 
}

