#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, p, q, a;
    set<int> nums;
    cin >> n;
    cin >> p;
    for(int i = 0; i < p; i++){
        cin >> a;
        nums.insert(a);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a;
        nums.insert(a);
    }
    if(nums.size() == n){
        cout << "I become the guy.";
    }
    else{
        cout << "Oh, my keyboard!";
    }
    
    return 0;
}
