#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;

    vector<queue<int>>q(n);

    for(int i = 0;i < n; i++) {
        for(int j = 0; j < m; j++) {
            char value ;
            cin >> value;
            if(value == '*') {
                q[i].push(j);
            }
        }
        q[i].push(m);
    }
    int marea = 0;
    for(int i = 0 ;i < m ;i++) {   
        stack<pair<int,int>> s; 
        for(int j = 0;j < n; j++) {
            while(q[j].front()< i) {
                q[j].pop();
            }
            int ceiling = q[j].front();
            int rsize = ceiling - i;
            int seen = j;
            while(!s.empty()) {
                int lasth = s.top().first;
                int lastind = s.top().second;
                if(rsize < lasth) {
                    marea = max(marea, lasth *(j - lastind)); 
                    seen = lastind;
                }
                else {
                    break;
                }
                s.pop();
            }
            if(s.empty() || rsize != s.top().first) {
                s.push({rsize , seen});
            }
        }

        while(!s.empty()) {
            int lasth = s.top().first;
            int lastind = s.top().second;

            marea = max(marea, lasth * (n - lastind));
            s.pop();
        }
    }

    cout << marea << endl;
}