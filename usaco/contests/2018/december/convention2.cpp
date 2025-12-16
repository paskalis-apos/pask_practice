#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct cow {
    ll seniority, arrival, spendtime;
     
};

bool operator< (const cow 
&a, const cow &c) {
    return a.seniority < c.seniority;
}

bool comp( cow a, cow b) {
    return a.arrival < b.arrival;
}


int main() {
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    ll cownum;
    cin >> cownum;
    vector<cow> info(cownum);
    set<cow> waiting;
    for(int i = 0; i < cownum ;i++) {
        info[i].seniority = i;
        cin >> info[i].arrival >> info[i].spendtime;
    }

    sort(info.begin(), info.end(), comp);
    ll time = info[0].arrival;
    ll time_left = info[0].spendtime;
    ll maxwait = 0;
    int i = 1;
    while (i < cownum || !waiting.empty()) {
        if(i < cownum && info[i].arrival - time <= time_left) {
            time_left -= (info[i].arrival - time);
            time = info[i].arrival;
            waiting.insert(info[i]);
            i++;
            
        }
        else {
            if(waiting.empty()) {
                time_left = info[i].spendtime;
                time = info[i].arrival;
                i++;
                continue;
            }
            time += time_left;
            cow cur = *waiting.begin();
            waiting.erase(waiting.begin());
            time_left = cur.spendtime;
            maxwait = max(maxwait, time - cur.arrival);
        }
    } 

    cout << maxwait;
}