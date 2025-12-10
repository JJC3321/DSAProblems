#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;

struct FreshRange {
    long long start;
    long long end;
};

bool compareRanges(const FreshRange& a, const FreshRange& b) {
    return a.start < b.start;
}

FreshRange parse_range(const string& range_str) {
    FreshRange range;
    size_t dash_pos = range_str.find('-');
    
    if (dash_pos == string::npos) {
        throw std::invalid_argument("Invalid range format: " + range_str);
    }
    
    range.start = stoll(range_str.substr(0, dash_pos));
    range.end = stoll(range_str.substr(dash_pos + 1));
    
    return range;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}


int main() {
    
    vector<FreshRange> freshRanges;
    
    ifstream inputFile("input.txt");
    string line;
    bool reading_ranges = true; 

    while (getline(inputFile, line)) {
        
        string trimmed_line = trim(line); 
        
        if (trimmed_line.empty()) {
            reading_ranges = false;
            continue; 
        }
        
        if (reading_ranges) {
            freshRanges.push_back(parse_range(trimmed_line));
        }
    }
    inputFile.close();
    
    if (freshRanges.empty()) {
        cout << 0 << endl;
        return 0;
    }

    sort(freshRanges.begin(), freshRanges.end(), compareRanges);

    long long total_fresh_count = 0;
    
    long long current_start = freshRanges[0].start;
    long long current_end = freshRanges[0].end;

    for (size_t i = 1; i < freshRanges.size(); ++i) {
        long long next_start = freshRanges[i].start;
        long long next_end = freshRanges[i].end;

        if (next_start <= current_end + 1) {
            current_end = max(current_end, next_end);
        } else {
            total_fresh_count += (current_end - current_start + 1);
            current_start = next_start;
            current_end = next_end;
        }
    }
    
    total_fresh_count += (current_end - current_start + 1);
    
    cout << total_fresh_count << endl;
    
    return 0;
}
