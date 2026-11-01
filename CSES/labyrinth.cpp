#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

    int n, m, startX, startY; 
    cin >> n >> m;
    vector<vector<char>> grid;

    for(int k = 0; k < n; k++){
        vector<char> row;         
        for(int i = 0; i < m; i++){
            char a;
            cin >> a;
            if(a == 'A'){
                startX = k;
                startY = i;
            }
            row.push_back(a);
        }
        grid.push_back(row);
    }

    queue<pair<int, int>>q; 
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<char> path;
    q.push({startX, startY});
    bool reach = false;
    int endX, endY;
    
    while(!q.empty()){
        
        pair<int, int> coord = q.front();
        q.pop();
        int x = coord.first;
        int y = coord.second; 
        visited[x][y] = true;

        if(grid[x][y] == 'B'){
            endX = x;
            endY = y;
            reach = true;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nX = x +  dir[i][0];
            int nY = y + dir[i][1];

            if(nX < n  && nY < m && nX >= 0 && nY >= 0){
                if(grid[nX][nY] != '#' && visited[nX][nY] == false){
                    q.push({nX, nY});
                    visited[nX][nY] = true;
                    parent[nX][nY] = {x, y};
                }
            }
        }
    }

    if(reach){
        pair<int, int> curr = {endX,endY};
        while(curr.first != startX || curr.second != startY){
            pair<int, int> p = parent[curr.first][curr.second];
            int dr = curr.first - p.first;
            int dc = curr.second - p.second;

            if(dr == -1 && dc == 0) path.push_back('U');
            else if(dr == 1 && dc == 0) path.push_back('D');
            else if(dr == 0 && dc == -1) path.push_back('L');
            else if(dr == 0 && dc == 1) path.push_back('R');

            curr = p;

        }
        reverse(path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.size() << endl;
        for(char c : path){
            cout << c;
        }
    }
    else{
        cout << "NO";
    }

    return 0;
}