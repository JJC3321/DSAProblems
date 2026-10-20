
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long  n;
    cin >> n;
    vector<long long> nums;
    long long total = 0;

    for(long long i = 1; i <= n; i++){
        nums.push_back(i);
        total += i;
    }

    if(total % 2 != 0 && n % 4 != 0){
        cout << "NO";
    }else{
        cout << "YES" << endl;
        long long target = total / 2;
        vector<long long> set1, set2;
        
        for (long long i = n; i >= 1; --i) {
            if (i <= target) {
                set1.push_back(i);
                target -= i;
            } else {
                set2.push_back(i);
            }
        }
        cout << set1.size() << endl;
        for(long long x : set1){
            cout << x <<  " ";
        }
        cout << endl;
        cout << set2.size() << endl;
        for(long long x : set2){
            cout << x << " ";
        }

    }


    return 0;
}
