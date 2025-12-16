#include<bits/stdc++.h> 
using namespace std;

int main() {
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    int n;
    cin >> n;

    vector<int> info(n);
    for(auto &x : info) {
        cin >> x;
    }

    for(int i = n - 1; i >= 0; i--) {
        int cur = info[i] - 1;
        while(cur > -1 && i > 0) {
            i--;
            if(info[i] != -1 && info[i] != cur) {
                cout << -1;
                return 0;
            }
            info[i] = cur;
            cur--;
            
        }
    }

    int min_events, max_events;
    min_events = 0;
    max_events = 0;

    if(info[0] != -1 && info[0] != 0) {
        cout << -1 << endl;
        return 0;
    }
    info[0] = 0;

    for(auto &x : info) {
        if(x == 0) {
            min_events++;
            max_events++;
        }
        else if(x == -1) {
            max_events++;
        }
    }

    cout << min_events << " " << max_events << endl;

}