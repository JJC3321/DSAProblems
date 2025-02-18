#include <iostream>

using namespace std;

int main()
{
    long long  n, m,a;
    cin >> n >> m >> a;
    int theatreSquare = n * m;
    long long na = n/a;
    long long ma = m/a;
    if(n % a != 0){
        na++;
    }
    if(m % a != 0){
        ma++;
    }
    cout << na * ma;
    
}
