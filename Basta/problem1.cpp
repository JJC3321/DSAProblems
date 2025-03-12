//LC 767

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;



//You given a list of of letters you need to arrange them 
//so that no letter stay on two adjeacent places. 


// unordered_map 
// {a : 3 , b : 3, c: 3}


//Form a string where no same char is adjeacent. 
// exmaple "abcabcabcabc"

string uniquenNoAdjeacent(vector<char> listChar){
    
    string ans = " ";
    
    //Check if list is empty
    if(listChar.empty()){
        return ans;
    }
    
    
    //Count number times a letter appear in hashmap
    unordered_map<char, int> numChar;
    for(int i = 0; i < listChar.size(); i++){
        numChar[listChar[i]]++;
    }
    
    //Check if there inbalance of frequnet letter then total letter 
    char freqChar;
    int count = 0;
    for(auto x : numChar){
        
        char l = x.first;
        int num = x.second;
        if(num > count){
            count = num;
            freqChar = l;
        }
    }
    if(count != numChar.size() - count +1){
        return ans; 
    }
    
    //Group chars with same frequency in a set
    
    
    

    return ans;
    
};


int main()
{
    vector<char> listChar = { 'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'}; 
    //vector<char> listChar = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b'};
    cout << uniquenNoAdjeacent(listChar);
}
