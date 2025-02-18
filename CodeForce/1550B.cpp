#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int t, a, b, n, ans;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> a >> b;
        cin >> s;
        ans = a*n;
        if(b>0){
            ans +=n*b;
        }
        else{
            int z = 0, o =0;
            char last = 'a';
            for(char c: s){
                if(c == last){
                    continue;
                }
                else{
                    last = c;
                }
                if(c == '0'){
                    z++;
                }
                else{
                    o++;
                }
            }
            ans+=min(1+z,1+o)*b;
        }
        cout << ans << endl;   
    }
} 
