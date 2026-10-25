
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> chessBoard;


int solved(int x, const vector<vector<bool>>& chessBoard, bool col[], bool diag1[], bool diag2[]) {
    if (x == 8) {
        return 1;
    }
    int count = 0;
    for (int c = 0; c < 8; c++) {
        if (chessBoard[x][c] && !col[c] && !diag1[x - c + 7] && !diag2[x + c]) {
            col[c] = true;
            diag1[x - c + 7] = true;
            diag2[x + c] = true;

            count += solved(x + 1, chessBoard, col, diag1, diag2);

            col[c] = false;
            diag1[x - c + 7] = false;
            diag2[x + c] = false;
        }
    }
    return count;
}


int main() {

    int n = 8;

    while(n--){
        vector<bool> row = {};   
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '.'){
                row.push_back(true);
            }
            else{
                row.push_back(false);
            }
        }
        chessBoard.push_back(row);
    } 

    int x = 0;
    bool col[8] = {false};
    bool diag1[15] = {false}; 
    bool diag2[15] = {false};
    
    cout << solved(x, chessBoard, col, diag1, diag2);

    return 0;
}

