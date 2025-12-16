#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> workday;
int daysnum, maxdelay, jobnum;
vector<pair<int,int>> startjobs ;

bool valid(int mid) {
    queue<pair<int,int>> q;
    int index = 0;
    for(int i = 0 ;i <= daysnum + 1 ; i++) {
        for(int counter = 0;counter < mid && !q.empty(); counter++) {
            pair<int,int> cur = q.front();
            q.pop();
            if(i - cur.first > maxdelay + 1) {
                return false;
            }
            workday[i -1].push_back(cur.second);
        }
        while(startjobs[index].first <= i && index < jobnum){
            q.push(startjobs[index]);
            index++;
        }
    }
    if(!q.empty()) {
        return false;
    }
    return true;

}

int main() {
    cin >> daysnum >> maxdelay >> jobnum;
    workday.resize(daysnum + 2);
    startjobs.resize(jobnum);
    for(int i = 0 ;i< jobnum ;i++) {
        cin >> startjobs[i].first;
        startjobs[i].second = i + 1;
    }
    sort(startjobs.begin(), startjobs.end());

    int r = jobnum;
    int l = 1;

    while(l < r) {
        for(auto &x : workday) {
            x.clear();
        }
        int mid = (r + l) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    for(auto &x : workday) {
        x.clear();
    }
    int answer = l;
    valid(answer);
    cout << l<< endl;
    for(int i = 1 ;i <= daysnum ;i++ ) {
        for(auto &x : workday[i]) {
            cout << x <<" ";
        }
        cout << 0 << endl;

    }


}