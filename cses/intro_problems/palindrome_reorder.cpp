#include<bits/stdc++.h>
using namespace std;


int main() {
    string n;
    cin >> n;
    vector<int> alphabet(27);
    for(int i = 0;i <= 26 ;i++) {
        alphabet[i] = 0;
    }

    for(int i = 0 ;i < n.size(); i++) {
        char letter = n[i];
        letter -= 64;
        alphabet[letter]++;
    }

    int odd = -1 ;
    for(int i = 1; i <= 26; i++) {
        if(alphabet[i] % 2 == 1) {
            if(odd != -1) {
                cout << "NO SOLUTION";
                return 0;
            }
            odd = i;
        }
    }

    for(int i = 1;i <= 26; i++) {
        for(int j = 0; alphabet[i] / 2 > j; j++) {
            cout << char(i + 64);
        }
    }
    if (odd != -1) {
        cout << char(odd + 64);
    }

    for(int i = 26 ;i >= 1; i--) {
        for(int j = 0; alphabet[i]/ 2 > j; j++) {
            cout << char(i + 64);
        }
    }
}

