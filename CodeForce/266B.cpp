#include <iostream>
#include <string>


using namespace std;

int main() {

    int n, t;
    string s;
    cin >> n >> t >> s;
    for(int i = 0; i < t; i++){
        for(int k = 0; k < n - 1; k++){
            if(s[k] == 'B' and s[k+1] == 'G'){
                swap(s[k], s[k+1]);
                k++;
            }
        }
    }

    cout << s;

    return 0;
}
