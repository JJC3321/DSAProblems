#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        cout << int(ceil(sqrt(a))) << endl;
    }

} 
