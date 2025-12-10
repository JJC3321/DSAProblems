#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;


struct FreshRange {
    long long start;
    long long end;
};

FreshRange parse_range(const string& range_str) {
    FreshRange range;
    size_t dash_pos = range_str.find('-');
    
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
    vector<long long> availableIDs;
    
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
 
            freshRanges.push_back(parse_range(line));
        } else {

            availableIDs.push_back(stoll(line));
        }
    }
    inputFile.close();
    
    long long fresh_count = 0;
    
    for (long long id : availableIDs) {
        bool is_fresh = false;
        
        for (const auto& range : freshRanges) {
            if (id >= range.start && id <= range.end) {
                is_fresh = true;
                break;
            }
        }
        
        if (is_fresh) {
            fresh_count++;
        }
    }
    
    cout << fresh_count << endl;
    
    return 0;
}
