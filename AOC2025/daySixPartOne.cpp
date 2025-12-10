#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve_problem(const vector<string>& lines, int j_start, int j_end) {
    long long problem_result = 0;
    char operation = ' ';
    vector<long long> numbers;
    
    const string& op_line = lines.back();
    
    for (int j = j_start; j <= j_end; ++j) {
        if (j < op_line.length()) {
            if (op_line[j] == '+') {
                operation = '+';
                break;
            } else if (op_line[j] == '*') {
                operation = '*';
                break;
            }
        }
    }
    
    if (operation == ' ') {
        cerr << "Error: Could not find operation for problem starting at col " << j_start << endl;
        return 0;
    }

    for (size_t i = 0; i < lines.size() - 1; ++i) {
        string num_str;
        
        if (lines[i].length() > j_start) {
            num_str = lines[i].substr(j_start, j_end - j_start + 1);
        } else {
            continue;
        }
        
        size_t first = num_str.find_first_not_of(' ');
        if (first == string::npos) {
            continue;
        }
        size_t last = num_str.find_last_not_of(' ');
        num_str = num_str.substr(first, (last - first + 1));
        
        try {
            numbers.push_back(stoll(num_str));
        } catch (const std::exception& e) {
            cerr << "Error converting number string: " << num_str << endl;
        }
    }
    
    if (operation == '+') {
        problem_result = 0;
        for (long long num : numbers) {
            problem_result += num;
        }
    } else if (operation == '*') {
        problem_result = 1;
        for (long long num : numbers) {
            problem_result *= num;
        }
    }

    return problem_result;
}

void solve_worksheet(const string& filename) {
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    vector<string> lines;
    string line;
    int max_width = 0;
    
    while (getline(input_file, line)) {
        lines.push_back(line);
        if ((int)line.length() > max_width) {
            max_width = line.length();
        }
    }
    input_file.close();

    if (lines.empty()) {
        cout << "Input file is empty." << endl;
        return;
    }
    
    for (auto& l : lines) {
        l.resize(max_width, ' ');
    }
    
    long long grand_total = 0;
    bool in_problem = false;
    int current_start = -1;

    for (int j = 0; j < max_width; ++j) {
        bool is_separator_column = true;
        for (const auto& l : lines) {
            if (l[j] != ' ') {
                is_separator_column = false;
                break;
            }
        }

        if (!in_problem && !is_separator_column) {
            in_problem = true;
            current_start = j;
        } else if (in_problem && is_separator_column) {
            grand_total += solve_problem(lines, current_start, j - 1);
            in_problem = false;
        }
    }
    
    if (in_problem) {
        grand_total += solve_problem(lines, current_start, max_width - 1);
    }

    cout << grand_total << endl;
}

int main() {
    solve_worksheet("input.txt");
    return 0;
}
