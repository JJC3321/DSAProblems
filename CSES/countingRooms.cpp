#include <bits/stdc++.h>
#include <vector>

using namespace std;

void bfs(vector<vector<char>>& grid, int x, int y, int n, int m){


    if(grid[x][y] == '#') return;
    grid[x][y] = '#';  

    vector<vector<int>> dir = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};

    for(int i = 0; i < dir.size(); i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < n && ny < m && nx >= 0 && ny >= 0){
            if(grid[nx][ny] == '.') bfs(grid, nx, ny, n, m);
        }
    }


}



int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid;

    for(int k = 0; k < n; k++){
        vector<char> x;         
        for(int i = 0; i < m; i++){
            char a;
            cin >> a;
            x.push_back(a);
        }
        grid.push_back(x);
    }


    int ans = 0;
    int x = 0;
    int y = 0;

    while(x < n){
        if(grid[x][y] == '.'){
            bfs(grid, x, y, n, m);
            ans++;
        }
        y++;
        if(y == m){
            x++;
            y = 0; 
        }
    }

    cout << ans;


    return 0;
}