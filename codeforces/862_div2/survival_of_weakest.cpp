#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define TOMODULE  (1000000000 + 7)

ll sum = 0;



void create_array(vector<ll>prevar) {
    if(prevar.size() == 1) {
        ll answer = (prevar[0] + sum)% TOMODULE;
        cout << answer;
        return;
    }
    ll firstelement = prevar[0];
    for(auto &x : prevar) {
        x -= firstelement;
    }
    for(int i = prevar.size(); i > 1; i--) {
        firstelement *= 2;
        firstelement %= TOMODULE;
    }
    sum += firstelement;
    
    map<ll,ll> indexcounter;
    multiset<pair<ll,ll>>pos_pairs;
    for(int i = 0; i < prevar.size() - 1; i++) {
        pair<ll,ll> temp = {prevar[i + 1] + prevar[i], i};
        indexcounter[i] = i + 1;
        pos_pairs.insert(temp);
    }
    vector<ll> newarray;
    while(newarray.size() < prevar.size() - 1) {
        ll smallpair = pos_pairs.begin()->first;
        ll index = pos_pairs.begin()->second;
        ll gountill = indexcounter[index];
        newarray.push_back(smallpair);
        pos_pairs.erase(pos_pairs.begin());
        if(gountill < prevar.size() - 1) {
            pos_pairs.insert({smallpair + prevar[gountill + 1] - prevar[gountill], index});
        }
        indexcounter[index]++;
    }

    indexcounter.clear();
    prevar.clear();
    pos_pairs.clear();

    create_array(newarray);
    return;
}

int main() {
    int arrlength;
    cin >> arrlength;
    vector<ll> numbers(arrlength);
    
    for(auto &x : numbers) {
        cin >> x;
    }
    sort(numbers.begin(), numbers.end());

    create_array(numbers);
}