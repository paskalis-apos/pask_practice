#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x: v) {
        cin >> x;
    }
    stack<pair<int,int>> s;
    for(int i = 0 ;i < n ;i++) {
        int answer = 0;
        while(!s.empty()) {
            if(s.top().first < v[i]) {
                answer = s.top().second;
                break;
            }
            else {
                s.pop();
            }
        }
        cout << answer << " ";
        s.push({v[i] , i + 1});
    }
}