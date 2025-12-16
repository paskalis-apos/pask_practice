#include<bits/stdc++.h>
using namespace std;

struct lg{
    int l, r, num;
};

struct oc {
    int c , num;
};

bool comp1(lg a, lg b) {
    return a.l < b.l;
}
bool comp2(lg a , lg b) {
    return a.r < b.r;
}
int main() {
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);   
    int n;
    cin >> n;

    vector<lg> times(n);

    for(int i = 0; i < n ;i++) {
        cin >> times[i].l >> times[i].r;
        times[i].num = i;
    }
    vector<oc> starts(n);
    vector<oc> ends(n);

    sort(times.begin(),times.end(), comp1);
    for(int i = 0 ;i < n ;i++) {
        starts[i].c = times[i].l;
        starts[i].num = times[i].num;
    }
    sort(times.begin(),times.end(),comp2);
    for(int i = 0 ;i < n ;i++) {
        ends[i].c = times[i].r;
        ends[i].num = times[i].num;
    }
    vector<int>timealone(n);
    
    set<int> working;
    int i = 0 ;
    int j = 0;
    int prev = 0;
    int total_time = 0;
    while(j < n) {
        int reach;
        int onlyone = -1;
        bool atleastone = false;
        if(working.size() == 1) {
            onlyone = *working.begin();
        }
        if(working.size() >= 1) {
            atleastone = true;
        }

        if(i < n && starts[i].c <= ends[j].c) {
            working.insert(starts[i].num);
            reach = starts[i].c;
            i++;
        }
        else {
            working.erase(ends[j].num);
            reach = ends[j].c;
            j++;
        }
        if(onlyone != -1) {
            timealone[onlyone] += reach - prev;
        }
        if(atleastone) {
            total_time += reach - prev;
        }

        prev = reach;
    }

    int min_time = INT_MAX;
    for(auto &x: timealone) {
        min_time = min(min_time, x);
    }

    int answer = total_time - min_time;
    cout << answer << endl;
}
