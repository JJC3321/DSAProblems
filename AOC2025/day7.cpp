#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int solutionPartOne (vector<string> lines){
    int totalSplits = 0;
    set<int> currentBeams;
    
    for(int i = 0; i <lines[0].size(); i++){
        if(lines[0][i] == 'S'){
            currentBeams.insert(i);
            break;
        }
    }
   
    for(int row = 1; row < lines.size(); row++){
        set<int> nextBeams;
        for(int col : currentBeams){
            if(lines[row][col] == '^'){
                totalSplits++;
                if(col > 0) nextBeams.insert(col - 1);
                if(col < lines[row].size() - 1) nextBeams.insert(col + 1);
            }
            else {
                nextBeams.insert(col);
            }
        }
        currentBeams = nextBeams;
    }
   
   
    return totalSplits;
}


long long solutionPartTwo(vector<string> lines){
    int width = lines[0].size();
    vector<long long> currentPath(width, 0);
    
    for(int i = 0; i < width; i++){
        if(lines[0][i] == 'S'){
            currentPath[i] = 1;
            break;
        }
    }
    
    for(int row = 1; row < lines.size(); row++){
        vector<long long> nextPaths(width, 0);
        for(int col  = 0; col < width; col++){
            if(currentPath[col] == 0) continue;
            if(lines[row][col] == '^'){
                if (col > 0) nextPaths[col - 1] += currentPath[col];
                if (col < width - 1) nextPaths[col + 1] += currentPath[col];
            }
            else{
                nextPaths[col] += currentPath[col];
            }
        }
        currentPath = nextPaths;
    }
    
    long long totalPaths = 0; 
    for(long long count : currentPath){
        totalPaths += count;
    }
    return totalPaths;
}



int main() {
    
    vector<string> lines; 
    string line; 
    ifstream inputFile("input.txt");
    while(getline(inputFile, line)){
        lines.push_back(line);
    }
    int answer =  solutionPartOne(lines);
    cout << answer  << endl; 
    
    long long answer2 = solutionPartTwo(lines);
    cout << answer2;

    return 0;
}
