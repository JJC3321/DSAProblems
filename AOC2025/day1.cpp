#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int solutionPartOne(vector<string>& instructions, int currentValue){
    int answer = 0;
    
    for(int i = 0; i < instructions.size(); i ++){
        
        char direction = instructions[i][0];
        int amount = stoi(instructions[i].substr(1));
        
        if(direction == 'L'){
            currentValue = ((currentValue - amount) % 100 + 100) % 100; 
        }
        else {
            currentValue = (currentValue + amount) % 100; 

        }
        if(currentValue == 0){
            answer++;
        }
    } 
    return answer;
}

int solutionPartTwo(vector<string>& instructions, int currentValue){
    
    int answer = 0;
    
    for(int i = 0; i < instructions.size(); i ++){
        
        char direction = instructions[i][0];
        int amount = stoi(instructions[i].substr(1));
        for(int k = 0; k < amount; k++){
            if(direction == 'L'){ 
                currentValue--;
                if(currentValue < 0){
                     currentValue = 99; 
                }
            }
            else{
                currentValue++;
                if(currentValue > 99){
                    currentValue = 0;
                }     
            }
            if(currentValue == 0){
                answer++;
            }
        }
    }
    return answer; 
}



int main() {
    
    vector<string> instructions; 
    string line; 
    ifstream inputFile("input.txt");
    while(getline(inputFile, line)){
        instructions.push_back(line);
    }
    int currentValue = 50;
    
    int answer = solutionPartOne(instructions, currentValue);
    cout << answer << endl;

    answer = solutionPartTwo(instructions, currentValue);
    cout << answer;

    return 0;
}
