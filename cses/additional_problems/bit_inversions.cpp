#include<bits/stdc++.h>
using namespace std;
string bset;
set<int> diffs;
multiset<int> ret;
 
void modify(int cord) {
 
    if(cord == 0 || cord == bset.size())  {
        return;
    }
 
    set<int>::iterator it = diffs.find(cord);
    if(it != diffs.end()) {
        int l = *prev(it);
        int r = *next(it);
        ret.erase(ret.find(*it - l));
        ret.erase(ret.find(r - *it));
        ret.insert(r - l);
        diffs.erase(it);
    }
    else {
        diffs.insert(cord);
        it = diffs.find(cord);
        int l = *prev(it);
        int r = *next(it);
        ret.erase(ret.find(r - l));
        ret.insert(r - *it);
        ret.insert(*it - l);
    }
 
 
}
 
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int changesnum;
    cin >> bset;
    cin >> changesnum;
 
 
    diffs.insert(0);
    diffs.insert(bset.size());
    for(int i = 1; i < bset.size(); i++) {
        if(bset[i] != bset[i - 1]) {
            diffs.insert(i);
        }
    }
    for(set<int>::iterator it = diffs.begin(); next(it) != diffs.end(); it++) {
        ret.insert(*next(it) - *it);
    }
 
    for(int i = 0; i < changesnum ; i++) {
        int cord;
        cin >> cord;
        modify(cord - 1);
        modify(cord);
        cout << *ret.rbegin() << " ";
    }
 
}