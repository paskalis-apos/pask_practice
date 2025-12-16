#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    ll cownum , storenum , farmernum;
    cin >> cownum >> storenum >> farmernum;

    vector<ll> cows(cownum);
    vector<pair<ll,ll>> buymilk(storenum);
    vector<int> rentcow(farmernum);

    for(auto &x : cows) {
        cin >> x;
    }
    for(auto & x : buymilk) {
        cin >> x.second >> x.first;
    }
    for(auto &x : rentcow) {
        cin >> x;
    }

    sort(cows.rbegin(),cows.rend());
    sort(buymilk.rbegin(), buymilk.rend());
    sort(rentcow.rbegin(), rentcow.rend());

    ll store = 0;
    ll rent = 0;
    ll cow = 0;
    ll max_money = 0;
    while(cow < cownum) {
        ll amount = cows[cow];
        ll sell = 0;
        ll currstore = store;
        ll last = 0;

        while(currstore < storenum) {
            ll tempsell = min(amount, buymilk[currstore].second);
            sell += tempsell * buymilk[currstore].first;
            amount -= tempsell;
            if(amount > 0) {
                currstore++;
            }
            else {
                last = buymilk[currstore].second - tempsell;
                break;
            }
            
        }

        if(rent >= farmernum || sell > rentcow[rent] ) {
            max_money += sell;
            store = currstore;
            if(currstore < storenum ) {
                buymilk[currstore].second = last;
            }
            cow++;
        }
        else {
            max_money += rentcow[rent];
            rent++;
            cownum--;

        }
    }

    cout << max_money << endl;
}