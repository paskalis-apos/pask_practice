#include<bits/stdc++.h>
using namespace std;

struct ball
{
    int l , r;
    bool operator<(const ball &b) {
        if(l == b.l) {
            return r < b.r;
        }
        return l < b.l;
    }
};


void solve_case() {
    int numboxes;
    cin >> numboxes;

    vector<ball> ballranges(numboxes);
    for(auto &x : ballranges) {
        cin >> x.l >> x.r;
    }
    sort(ballranges.begin(), ballranges.end());
    multiset<int> waiting;

    int counter = 0;
    int prevl = ballranges[0].l - 1;

    while(counter < numboxes) {
        waiting.insert(ballranges[counter].r);
        if(ballranges[counter].l > prevl) {
            int nowplace = prevl + 1;
            while(!waiting.empty() && nowplace <= ballranges[counter].l) {
                if(*waiting.begin() < nowplace) {
                    cout << "NO" << endl;
                    return;
                }
                waiting.erase(waiting.begin());
                nowplace++;
            }

            prevl = ballranges[counter].l;
        }

        counter++;
    }
    int nowplace = prevl + 1;
    while(!waiting.empty()) {
        if(*waiting.begin() < nowplace) {
            cout << "NO" << endl;
            return;
        }
        waiting.erase(waiting.begin());
        nowplace++;
        
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >>t;
    for(int i = 0;i < t; i++) {
        solve_case();
    }
}