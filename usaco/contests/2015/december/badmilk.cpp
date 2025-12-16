#include<bits/stdc++.h>
using namespace std;


struct event {
    int m = - 1;
    int t;
    int p;

    bool operator<(const event &c ){
        if(t == c.t) {
            return m < c.m;
        }
        return t < c.t;

    }
};

int main() {

    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);

    int people, milks, ed, es;
    cin >> people >> milks >> ed >> es;

    int evnum = ed + es;
    vector<event> v_events(evnum );
    for(int i = 0; i< evnum ;i++) {
        int person;
        int milk;
        int time;
        if (i < ed) {
            cin >> person >> milk >> time;
            v_events[i].m = milk;
            v_events[i].p = person;
            v_events[i].t = time;
        
        }
        else {
            cin >> person >> time;
            v_events[i].p = person;
            v_events[i].t = time;
        }
    }

    sort(v_events.begin(), v_events.end());

    int max_meds =0;

    for(int i = 1; i <= milks; i++) {
        int meds = 0;
        vector<bool> can_be_sick(people + 1);
        bool possible = true;

        for(auto &x : v_events) {
            if(x.m == -1) {
                if(!can_be_sick[x.p]) {
                    possible = false;
                    break;
                } 
            }
            else if(x.m == i) {
                if(!can_be_sick[x.p]) {
                    meds++;
                }
                can_be_sick[x.p] =true;
                
            }
        }


        if(possible) {
            max_meds = max(meds, max_meds);
        }

    }

    cout << max_meds;
}