#include<bits/stdc++.h>
using namespace std;

vector<set<int>> adjF;
vector<set<int>> adjG;
vector<bool> gvisitedall;
set<int>nowgvisited;
set<int>fvisited;
vector<pair<int,int>> todelete;
int operations ;

void dfsG(int index) {
    if(gvisitedall[index]) {
        return;
    }
    gvisitedall[index] = true;
    nowgvisited.insert(index);
    for(auto &x : adjG[index]) {
        dfsG(x);
    }
}

void dfsF(int index, int previndex) {
    if(fvisited.find(index) != fvisited.end()) {
        return;
    }
    if(nowgvisited.find(index) == nowgvisited.end()) {
        todelete.push_back({index, previndex});
        return;
    }
    fvisited.insert(index);
    for(auto &x : adjF[index]) {
        dfsF(x, index);
    }
}


void solve(){
    int vertices , Fedges, Gedges;
    cin >> vertices >> Fedges >> Gedges;
    operations = 0;
    adjF.assign(vertices, {});
    adjG.assign(vertices, {});
    gvisitedall.assign(vertices, false);

    for(int i =0 ;i < Fedges; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjF[a].insert(b);
        adjF[b].insert(a);
    }
    for(int i =0 ;i < Gedges; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjG[a].insert(b);
        adjG[b].insert(a);
    }

    for(int i = 0;i < vertices; i++) {
        if(gvisitedall[i]) {
            continue;
        }
        nowgvisited.clear();
        fvisited.clear();
        dfsG(i);
        bool first = true;
        for(auto &x : nowgvisited) {
            if(fvisited.find(x) == fvisited.end()) {
                dfsF(x, -1);
                for(auto &x : todelete) {
                    adjF[x.first].erase(x.second);
                    adjF[x.second].erase(x.first);
                    operations++;
                }
                todelete.clear();
                if(first) {
                    first = false;
                    continue;
                }
                operations++;
            }
        }
    }

    cout << operations << endl;



}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++ ){
        solve();
    }
}