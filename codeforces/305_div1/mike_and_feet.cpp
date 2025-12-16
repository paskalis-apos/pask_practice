#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    map<int,int> range;
    stack<pair<int,int>> s;
    for(int i = 0 ;i < n; i++) {
        int val;
        cin >> val;
        int lastind = -1;
        while(!s.empty()) {
            if(val < s.top().first) {
                int curval = s.top().first;
                lastind = s.top().second;
                range[curval] = max(range[curval], i - lastind);
                s.pop();
            }
            else {
                break;
            }
        }
        if(lastind != -1 && (s.empty() || s.top().first < val)) {
            s.push({val, lastind});
        }
        else {
            s.push({val, i});
        }
    }
    while(!s.empty()) {
        int curval = s.top().first;
        int prevind = s.top().second;
        range[curval] = max(range[curval], n  - prevind);
        s.pop();
    }
    map<int,int>::iterator i = prev(range.end());
    int counter = 1;
    while(counter <= n) {
        while(counter <= n && i->second >= counter) {
            cout << i->first << " ";
            counter++;
        }
        if(i != range.begin()) i--;
    }

}