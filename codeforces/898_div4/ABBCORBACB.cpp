#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_case() {
    string s;
    cin >> s;

    vector<int> input;
    bool loose = false;
    ll answer = 0;
    int min_num = INT_MAX;
    for(int i = 0; i < s.size();) {
        if(s[i] == 'B') {
            int temp = 0;
            while(s[i] == 'B' && i < s.size()) {
                i++;
                temp++;
            }
            if(temp > 1) {
                    loose = true;
            }
            input.push_back(0);
        }
        int counter = 0;
        if(s[i] == 'A') {
            while(s[i] == 'A' && i < s.size()) {
                i++;
                counter++;
            }
            input.push_back(counter);
        }
        min_num = min(min_num, input.back());
    }

    for(auto &x :input) {
            answer += x;
    }
    if(input.front() != 0 && input.back() != 0 && !loose) {
        answer -= min_num;
    }

    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve_case();
    }
}