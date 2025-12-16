#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie();

    int sticksnum;
    cin >> sticksnum;
    vector<int> sticks(sticksnum);

    for(auto &x : sticks) {
        cin >> x;
    }
    sort(sticks.begin(), sticks.end());
    int median = sticks[sticksnum / 2];
    ll answer = 0;
    for(auto &x : sticks) {
        answer += abs(median - x);
    } 
    cout << answer << endl;

}