#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("backin.txt","r",stdin);
    freopen("backout.txt","w",stdout);

    ll townsnum, backfit;
    cin >> townsnum >> backfit;
 
    vector<ll> location(townsnum);
    location[0] = 0;

    //create a prefix sum that stores the days it will take to reach any town starting from the first one
    for(int i = 1;i < townsnum; i++) {
        ll distance;
        cin >> distance;
        location[i] = location[i - 1] + distance;
    }

    map<ll,ll> nextsmall;
    stack<pair<ll,ll>> stillsmall;
    vector<ll> costs(townsnum);

    for(int i = 0;i < townsnum; i++) {
        ll temp;
        cin >> temp;
        costs[i] = temp;

        //the maps value is the index of the nearest town that sells cheaper cans and is more right than the town whose index is the maps key
        while(!stillsmall.empty() && stillsmall.top().first > temp) {
            nextsmall[stillsmall.top().second] = i;
            stillsmall.pop();
        }
        stillsmall.push({temp,i});
    }
    ll k = 0;
    ll totalcoins = 0;
    for(int i = 0 ;i < townsnum - 1; i++) {
        ll kprev = k;
        //try to have exactly enough cans to reach the cheaper town
        if(nextsmall[i]) {
            ll toreach = nextsmall[i];
            ll curdist = location[toreach] - location[i];
            if(k < curdist) {
                k = min(backfit, curdist);
            }
        }
        //there isn't any cheaper town so we buy as much as we can as long as it not more than what we need to reach the final town
        else {
            k = min(location[townsnum - 1] - location[i], backfit);
        }
        totalcoins += (k - kprev) * costs[i];

        k -= location[i + 1] - location[i];
    }

    cout << totalcoins << endl;

}