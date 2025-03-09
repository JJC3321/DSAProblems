#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> 

using namespace std;

int main() {
    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;

    size_t minLength = min(s1.size(), s2.size());

    for (size_t i = 0; i < minLength; i++) {
        char lowerS1 = tolower(s1[i]);
        char lowerS2 = tolower(s2[i]);

        if (lowerS1 > lowerS2) {
            ans = 1;
            break;
        } else if (lowerS1 < lowerS2) {
            ans = -1;
            break;
        }
    }


    cout << ans << endl;
    return 0;
}
