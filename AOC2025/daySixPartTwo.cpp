#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

long long integer_pow10(int p) {
    long long result = 1;
    for (int i = 0; i < p; ++i) {
        result *= 10;
    }
    return result;
}

void solve_problem_group_part2(const vector<string>& G, int R, int start_c, int cc, long long& p2_total) {
    
    char op = G[R - 1][start_c];
    if (op != '+' && op != '*') {
        for (int c = start_c; c < cc; ++c) {
            if (G[R - 1][c] == '+' || G[R - 1][c] == '*') {
                op = G[R - 1][c];
                break;
            }
        }
    }
    if (op != '+' && op != '*') return;

    long long p2_score = (op == '+') ? 0 : 1;
    
    for (int c = cc - 1; c >= start_c; --c) {
        long long n = 0;
        for (int r = 0; r < R - 1; ++r) {
            if (isdigit(G[r][c])) {
                n = n * 10 + (G[r][c] - '0');
            }
        }
        
        if (op == '+') {
            p2_score += n;
        } else {
            p2_score *= n;
        }
    }
    p2_total += p2_score;
}

void solve_worksheet_part2_only(const string& filename) {
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    vector<string> G; 
    string line;
    int max_width = 0;
    
    while (getline(input_file, line)) {
        size_t end_pos = line.find_last_not_of(" \t\r\n");
        if (end_pos != string::npos) {
            line.resize(end_pos + 1);
        } else {
            continue;
        }
        
        G.push_back(line);
        if ((int)line.length() > max_width) {
            max_width = line.length();
        }
    }
    input_file.close();

    if (G.empty()) return;

    int R = G.size();
    int C = max_width;
    
    for (auto& l : G) {
        l.resize(C, ' ');
    }

    long long p2 = 0;
    int start_c = 0;

    for (int cc = 0; cc <= C; ++cc) {
        bool is_blank = true;
        
        if (cc < C) {
            for (int r = 0; r < R; ++r) {
                if (G[r][cc] != ' ' && G[r][cc] != '\t') {
                    is_blank = false;
                    break;
                }
            }
        }
        
        if (is_blank) {
            if (cc > start_c) {
                solve_problem_group_part2(G, R, start_c, cc, p2);
            }
            start_c = cc + 1;
        }
    }

    cout << p2 << endl;
}

int main() {
    solve_worksheet_part2_only("input.txt");
    return 0;
}
