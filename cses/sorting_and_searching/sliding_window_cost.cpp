#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll highsum = 0;
ll lowsum = 0;
multiset<ll> lowvals;
multiset<ll> highvals;
ll n , k;

void ins(int value) {
    if(lowvals.size() <= highvals.size()) {
        if(highvals.empty() || value > *highvals.begin()) {
            highvals.insert(value);
            highsum += value;
            value = *highvals.begin();
            highvals.erase(highvals.begin());
            highsum -= value;
        }

        lowvals.insert(value);
        lowsum += value;
    }
    else{
        if(value < *prev(lowvals.end())) {
            lowvals.insert(value);
            lowsum += value;
            value = *prev(lowvals.end());
            lowvals.erase(prev(lowvals.end()));
            lowsum -= value;
        }
        highvals.insert(value);
        highsum+= value;
    }
}

void ers(int value) {
    if(lowvals.find(value) != lowvals.end()) {
        lowvals.erase(lowvals.find(value));
        lowsum -= value;
    }
    else {
        highvals.erase(highvals.find(value));
        highsum -= value;
    }
}   
ll median() {
    return *prev(lowvals.end());
}
ll cost() {
    ll lowcost = median() * lowvals.size() - lowsum;
    ll highcost = highsum - median() * highvals.size();
    return highcost + lowcost;
}

int main(){
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    for(int i = 0 ;i < n ;i++) {
        if(i < k) {
            ins(v[i]);
            if(i == k -1) {
                cout << cost() << " ";
            }
            continue;
        }
        ers(v[i - k]);
        ins(v[i]);
        cout << cost() << " ";
    }
}