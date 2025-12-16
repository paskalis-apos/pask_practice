#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    int tilesnum , bootsnum;
    cin >> tilesnum >> bootsnum;

    vector<int>snowdepth(tilesnum);
    for(auto &x : snowdepth) {
        cin >> x;
    }

    map<int,int>pref_depthstreak;
    map<int,int> first_appearance;
    
    for(int i = 0 ; i < tilesnum ;i++) {
        if(first_appearance.count(snowdepth[i]) == 0) {
            first_appearance[snowdepth[i]] = i;
        }
        while(first_appearance.size() > 0) {
            int value = prev(first_appearance.end())->first;
            int start = prev(first_appearance.end())->second;
            if (value > snowdepth[i]) {   
                pref_depthstreak[value] = max(pref_depthstreak[value], i - start);
                first_appearance.erase(value);
                first_appearance[snowdepth[i]] = min(first_appearance[snowdepth[i]], start);
            }
            else {
                break;
            }
        }
    }
    if(!pref_depthstreak.empty()) {
        for(map<int,int>::iterator it = prev(pref_depthstreak.end()); it != pref_depthstreak.begin(); it--) {
            prev(it)->second = max(prev(it)->second, it-> second); 
        }
    }


    for(int i = 0 ;i < bootsnum; i++) {
        int maxdepth , maxstep;
        cin >> maxdepth >> maxstep;

        if(pref_depthstreak.upper_bound(maxdepth) == pref_depthstreak.end()) {
            cout << 1 << endl;
            continue;
        }
        else if(pref_depthstreak.upper_bound(maxdepth)->second < maxstep) {
            cout << 1 << endl;
            continue;
        }

        cout << 0 << endl;
    }
    
}