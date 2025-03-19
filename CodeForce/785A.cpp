#include <iostream>
using namespace std;

int main() {

    int n, ans = 0;
    cin >> n;
    string ss;
    for(int i = 0; i < n; i++){
        cin >> ss;
        if(ss == "Tetrahedron"){
            ans += 4;
        }
        else if(ss == "Cube"){
            ans += 6;
        }
        else if(ss == "Octahedron"){
            ans += 8;
        }
        else if(ss == "Dodecahedron"){
            ans += 12;
        }
        else if(ss == "Icosahedron"){
            ans += 20;
        }
    }
    
    cout << ans;
    
    return 0;
}
