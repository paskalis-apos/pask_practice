#include<bits/stdc++.h>
using namespace std;
set<int> locations;
multiset<int> distances;

void modify() {
    int pos;
    cin >> pos;
    locations.insert(pos);
    set<int>::iterator it = locations.find(pos);
    distances.insert(*it - *prev(it));
    distances.insert(*next(it) - *it);
    distances.erase(distances.find(*next(it) - *prev(it)));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int streetlength, tlightsnum;
    cin >> streetlength >> tlightsnum;

    locations.insert(0);
    locations.insert(streetlength);
    distances.insert(streetlength);
    for(int i = 0 ;i < tlightsnum; i++) {
        modify();
        cout << *distances.rbegin() << " ";
    }

}