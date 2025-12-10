#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int count_adjacent_rolls(const vector<string>& rolls, int r, int c) {
    int neighbor_count = 0;
    int R = rolls.size();
    if (R == 0) return 0;
    int C = rolls[0].length();

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) {
                continue;
            }

            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (rolls[nr][nc] == '@') {
                    neighbor_count++;
                }
            }
        }
    }
    return neighbor_count;
}

int main() {
    
    long long answer = 0;
    
    ifstream inputFile("input.txt");
    vector<string> rolls;
    string line;

    while (getline(inputFile, line)) {
        rolls.push_back(line);
    }
    
    inputFile.close();
    
    
    int R = rolls.size();
    int C = rolls[0].length(); 

    for(int r = 0; r < R; ++r){
        for(int c = 0; c < C; ++c){
            
            if(rolls[r][c] == '@'){
                
                int adjacent_rolls = count_adjacent_rolls(rolls, r, c);
                
                if(adjacent_rolls < 4){
                    answer++;
                }
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
