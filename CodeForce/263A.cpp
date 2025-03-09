#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 5;
    vector<vector<int>> matrix;
    for(int i = 0; i < n; i++){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        matrix.push_back({a,b,c,d,e});
    }
    if(matrix[2][2] == 1){
        cout << 0;
    }
    else{
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                if(matrix[i][k] == 1){
                    cout << abs(i-2) + abs(k-2);
                }
            }
        }
    }
    return 0;
}