#include<bits/stdc++.h>
using namespace std;

void check_case() {
    string s;
    cin >> s;

    int q;
    cin >> q;
    set<int> win_starts;
    for(int i = 0 ;i < s.size() - 3; i++) {
        string sub = s.substr(i , 4);
        if(sub == "1100") {
            win_starts.insert(i);
        }
    } 
    for(int i = 0 ;i < q; i++) {
        int index , to_make;
        cin >> index >> to_make;
        char c = to_make + '0';
        index--;
    
        s[index] = c;
        int j = 0;
        if(index >= 3) {
            j = index - 3;
        }
        while(j <= index && j < s.size() - 3) {
                win_starts.erase(j);
                string sub = s.substr(j,4);
                if (sub == "1100") {
                    win_starts.insert(j);
                }
                j++;
            }
        if(win_starts.size() >= 1) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
        
    }


}

int main() {
    int t;
    cin >> t;
    for(int i =0 ;i < t; i++) {
        check_case();
    }
}