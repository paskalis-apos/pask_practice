#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> cows;
ll cownum;

void create_pref(vector<pair<ll,ll>> &pref) {
    for(int i = 1; i <= cownum; i++) {
        pref[i].first = max(pref[i -1].first , cows[i].second);
        pref[i].second = min(pref[i - 1].second, cows[i].second);
    }
}
void create_suf(vector<pair<ll,ll>> &pref) {
    for(int i = cownum; i > 0; i--) {
        pref[i].first = max(pref[i + 1].first , cows[i].second);
        pref[i].second = min(pref[i + 1].second, cows[i].second);
    }
}

int main() {
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    cin >> cownum;
    cows.resize(cownum + 1);
    ll maxx = 0, maxy = 0, minx = INTMAX_MAX, miny = INTMAX_MAX;
    for(int i =  1;i <= cownum; i++) {
        cin >> cows[i].first >> cows[i].second;
        maxx = max(maxx, cows[i].first);
        minx = min(minx, cows[i].first);
        maxy = max(maxy, cows[i].second);
        miny = min(miny, cows[i].second);
    }

    sort(cows.begin(),cows.end());
    vector<pair<ll,ll>> xsuf(cownum + 2);
    vector<pair<ll,ll>> xpref(cownum + 2);
    vector<pair<ll,ll>> ysuf(cownum + 2);
    vector<pair<ll,ll>> ypref(cownum + 2);
    xsuf[cownum + 1].second = INTMAX_MAX;
    ysuf[cownum + 1].second = INTMAX_MAX;
    xpref[0].second = INTMAX_MAX;
    ypref[0].second = INTMAX_MAX;

    create_pref(ypref);
    create_suf(ysuf);

    ll total_area = LLONG_MAX;

    for(int i = 1; i < cownum; i++) {

        ll pref_area = (ypref[i].first - ypref[i].second) * (cows[i].first - cows[1].first);
        ll suff_area = (ysuf[i + 1].first - ysuf[i + 1].second)  * (cows[cownum].first - cows[i + 1].first );
        ll curr_area = pref_area + suff_area;
        total_area = min(curr_area , total_area);
    }

    for(auto &x: cows) {
        swap(x.first, x.second);
    }
    sort(cows.begin(),cows.end());
    create_pref(xpref);
    create_suf(xsuf);

    for(int i = 1; i < cownum; i++) {

        ll pref_area = (xpref[i].first - xpref[i].second ) * (cows[i].first - cows[1].first );
        ll suff_area = (xsuf[i + 1].first - xsuf[i + 1].second ) *(cows[cownum].first - cows[i + 1].first ) ;
        ll curr_area = pref_area + suff_area;
        total_area = min(curr_area , total_area);
    }

    ll start = (maxx - minx) * (maxy - miny );
    total_area = min(total_area , start);
    ll answer = start - total_area;
    cout << answer << endl;

    return 0;
}