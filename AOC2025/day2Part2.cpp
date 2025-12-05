#include <iostream>
#include <vector>
#include <utility> 
#include <string>

using namespace std; 


bool isRepeatedSequence(long long n) {
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

int main()
{
    long long answer = 0;
    
    vector<pair<long long, long long>> id = {
        {749639, 858415},
        {65630137, 65704528},
        {10662, 29791},
        {1, 17},
        {9897536, 10087630},
        {1239, 2285},
        {1380136, 1595466},
        {8238934, 8372812},
        {211440, 256482},
        {623, 1205},
        {102561, 122442},
        {91871983, 91968838},
        {62364163, 62554867},
        {3737324037, 3737408513},
        {9494926669, 9494965937},
        {9939271919, 9939349036},
        {83764103, 83929201},
        {24784655, 24849904},
        {166, 605},
        {991665, 1015125},
        {262373, 399735},
        {557161, 618450},
        {937905586, 937994967},
        {71647091, 71771804},
        {8882706, 9059390},
        {2546, 10476},
        {4955694516, 4955781763},
        {47437, 99032},
        {645402, 707561},
        {27, 86},
        {97, 157},
        {894084, 989884},
        {421072, 462151}
    };
    
    for(int i = 0; i < id.size(); i++){
        long long start = id[i].first; 
        long long end = id[i].second; 
        for(long long k = start; k <= end; k++){
            if(isRepeatedSequence(k)){
                answer += k;
            }
        }
        
    }
    
    
    
    cout << answer << endl; 

    return 0;
}
