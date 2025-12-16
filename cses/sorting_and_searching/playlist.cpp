#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    map<int, bool> seen;
    int mseq = 0;

    for(int i = 0 ;i < n ;i++) {
        int value;

        cin >> value;
        q.push(value);
        if(seen[value]) {
            while(q.front() != value) {
                seen[q.front()] = false;
                q.pop();
            }
            q.pop();
        }
        seen[value] = true;
        mseq = max(mseq, int(q.size()));
    }

    cout << mseq << endl;

}