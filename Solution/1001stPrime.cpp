#include<iostream>
#include<vector>
#include <string.h>
using namespace std;

/*
Problem:
By listing the first six prime numbers: 2,3,5,7,11,and 13,
we can see that the 6th prime is 13.
What is the 10001st prime number? 

Solution:
Brute force: generated prime numbers with  
Sieve of Eratosthenes until we have the 10001st prime.
*/
void sieveOfEratosthenes(unsigned long int n, vector<int>& primeNumbers) {
    
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (long long int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {

            for (long long int k = i * i; k <= n; k += i)
                prime[k] = false;
        }
    }
    for (long long int i = 2; i <= n; i++)
        if (prime[i] == true)
        {
             primeNumbers.push_back(i);
        }
            
}
int main()
{
    vector<int> primeNumbers;
    long long int n = 1000000;
    sieveOfEratosthenes(n,  primeNumbers);
    cout << primeNumbers[10000];



}
