#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

bool isRepeatedSequence(long long n) {
    string s = to_string(n);
    int len = s.length();

    if (len % 2 != 0) {
        return false;
    }
    
    int mid = len / 2;
    string firstHalf = s.substr(0, mid);
    string secondHalf = s.substr(mid);
    
    return firstHalf == secondHalf;
};

bool isRepeatedSequencePartTwo(long long n) {
    string s = to_string(n);
    int len = s.length();

    for (int subLen = 1; subLen <= len / 2; subLen++) {
        
        if (len % subLen == 0) {
            
            bool match = true;
            
            for (int i = subLen; i < len; i++) {
                if (s[i] != s[i - subLen]) {
                    match = false;
                    break;
                }
            }
            
            if (match) return true;
        }
    }

    return false;
}

long long solutionPartOne(vector<pair<long long, long long>>& id){
    long long answer = 0;
    
    for(int i = 0; i < id.size(); i++){
        long long start = id[i].first; 
        long long end = id[i].second; 
        for(long long k = start; k < end; k++){
            if(isRepeatedSequence(k)){
                answer += k;
            }
        }
    }
    return answer;
}

long long solutionPartTwo(vector<pair<long long, long long>>& id){
    long long answer = 0;
    
    for(int i = 0; i < id.size(); i++){
        long long start = id[i].first; 
        long long end = id[i].second; 
        for(long long k = start; k <= end; k++){
            if(isRepeatedSequencePartTwo(k)){
                answer += k;
            }
        }
        
    }
    
    return answer; 
}

int main() {
    
    vector<pair<long long, long long>> id; 
    string content;
    ifstream inputFile("input.txt");
    getline(inputFile, content);
    inputFile.close();
    stringstream ss(content);
    string segment;
    
    while (getline(ss, segment, ',')) {
        size_t dashPos = segment.find('-');
        if (dashPos != string::npos) {
            long long start = stoll(segment.substr(0, dashPos));
            long long end = stoll(segment.substr(dashPos + 1));
            id.push_back({start, end});
        }
    }
 
    long long answer1 = solutionPartOne(id);
    cout << answer1 << endl;
    long long answer2 = solutionPartTwo(id);
    cout << answer2;
    
    
    return 0;
}
