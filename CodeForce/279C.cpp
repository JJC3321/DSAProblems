#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> up(n);
    up[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1]) {
            up[i] = up[i + 1];
        } else {
            up[i] = i;
        }
    }

    vector<int> down(n);
    down[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1]) {
            down[i] = down[i + 1];
        } else {
            down[i] = i;
        }
    }

    vector<int> ladder_end(n);
    for (int i = 0; i < n; i++) {
        ladder_end[i] = down[up[i]];
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--; 
        if (ladder_end[l] >= r) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
