#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll grassnum, nhcownum , johncownum;
    cin >> grassnum >> nhcownum >> johncownum;

    vector<pair<ll,ll>> grasspatches(grassnum);
    vector<ll> nhcows(nhcownum);
    for(auto &x : grasspatches) {
        cin >> x.first >> x.second;
    }
    for(auto &x : nhcows) {
        cin >> x;
    }

    priority_queue<int> canwin;

    sort(grasspatches.begin(), grasspatches.end());
    sort(nhcows.begin(),nhcows.end());

    ll counternh = 0;
    ll countergrass = 0;

    while(counternh < nhcownum) {
        ll l = nhcows[counternh];
        if(counternh == 0) {
            ll toinsert = 0;
            while(countergrass < grassnum && grasspatches[countergrass].first < l) {
                toinsert += grasspatches[countergrass].second;
                countergrass++;
            }
            canwin.push(toinsert);
        }
        if(counternh == nhcownum - 1) {
            ll toinsert = 0;
            while(countergrass < grassnum) {
                if(grasspatches[countergrass].first > l) {
                    toinsert += grasspatches[countergrass].second;
                }
                countergrass++;
            }
            canwin.push(toinsert);
            counternh++;
            continue;
        }

        ll r = nhcows[counternh + 1];
        ll totalsum = 0;
        ll onesum = 0;
        ll tempsum = 0;
        queue<pair<int,int>> oneget;
        while(countergrass < grassnum && grasspatches[countergrass].first < r ) {
            if(grasspatches[countergrass].first == l) {
                countergrass++;
                continue;
            }
            totalsum += grasspatches[countergrass].second;
            ll loc = max(l + 1,grasspatches[countergrass].first + (r - grasspatches[countergrass].first));

            oneget.push(grasspatches[countergrass]);
            tempsum += grasspatches[countergrass].second;
            while(!oneget.empty() && loc - oneget.front().first >= oneget.front().first - l) {
                ll out = oneget.front().second;
                oneget.pop();
                tempsum -= out;
            }
            onesum = max(tempsum , onesum);

            countergrass++;

        }
        canwin.push(onesum);
        canwin.push(totalsum - onesum);
        counternh++;
    }  

    ll answer = 0 ;
    for(int i = 0 ;!canwin.empty() && i < johncownum; i++) {
        answer += canwin.top();
        canwin.pop();
    }


    cout << answer;
}