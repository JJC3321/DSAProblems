#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 

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
    
    ifstream inputFile("input.txt");
    vector<string> rolls;
    string line;

    while (getline(inputFile, line)) {
        rolls.push_back(line);
    }
    inputFile.close();
    

    if (rolls.empty()) {
        cout << 0 << endl;
        return 0;
    }
    
    int R = rolls.size();
    int C = rolls[0].length();
    
    long long total_removed = 0;
    bool rolls_removed_in_this_pass = true;

    while (rolls_removed_in_this_pass) {
        rolls_removed_in_this_pass = false; 
        
        vector<pair<int, int>> accessible_rolls;

        for(int r = 0; r < R; ++r){
            for(int c = 0; c < C; ++c){
                
                if(rolls[r][c] == '@'){
                    int adjacent_rolls = count_adjacent_rolls(rolls, r, c);
                    

                    if(adjacent_rolls < 4){

                        accessible_rolls.push_back({r, c}); 
                    }
                }
            }
        }

        if (!accessible_rolls.empty()) {
            rolls_removed_in_this_pass = true; 
            total_removed += accessible_rolls.size();
            
            for (const auto& coord : accessible_rolls) {
                int r = coord.first;
                int c = coord.second;
                rolls[r][c] = '.'; 
            }
        }
    }
    
    cout << total_removed << endl;
    
    return 0;
}
