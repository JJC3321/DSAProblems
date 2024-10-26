#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int main(){
    int size;
    cin >> size;
    vector<int> answer;
    vector<string> nums;
    for(int i = 0 ; i < size; i++){
        int temp; 
        cin >> temp;
        nums.push_back(to_string(temp));
    }
    for(int i = 0; i< size; i++){
        string s = nums[i];
        char a  = s[0];
        char b = s[1];
        int temp = int(a - '0') + int(b- '0');
        answer.push_back(temp);
    }
    for(int i = 0; i < size; i++){
        cout << answer[i] << endl;
    }
}