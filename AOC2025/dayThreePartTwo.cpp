#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <cmath>

using namespace std;

long long powerOf10(int exp) {
    long long res = 1;
    for (int k = 0; k < exp; ++k) res *= 10;
    return res;
}

map<pair<int, int>, long long> memo;

long long solve_recursive(const string& line, int idx, int digits_collected) {

    if (idx == line.length()) {

        if (digits_collected == 12) return 0;
        
        return -1e16; 
    }

    if (memo.count({idx, digits_collected})) {
        return memo[{idx, digits_collected}];
    }

    long long ans = solve_recursive(line, idx + 1, digits_collected);

    if (digits_collected < 12) {
        
        if (isdigit(line[idx])) {
            long long digitVal = line[idx] - '0';
            

            long long currentVal = digitVal * powerOf10(11 - digits_collected);
            
            long long take_it = currentVal + solve_recursive(line, idx + 1, digits_collected + 1);
            
            ans = max(ans, take_it);
        }
    }

    return memo[{idx, digits_collected}] = ans;
}

vector<string> loadInput(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    return lines;
}

int main() {

    vector<string> rawData = loadInput("input.txt");
    cout << "Processing " << rawData.size() << " rows." << endl;

    long long totalJoltage = 0;

    for (const string& row : rawData) {
        
        memo.clear();

        long long rowMax = solve_recursive(row, 0, 0);
        
        if (rowMax > 0) {
            totalJoltage += rowMax;
        }
    }

    cout << "Total Joltage: " << totalJoltage << endl;

    return 0;
}
