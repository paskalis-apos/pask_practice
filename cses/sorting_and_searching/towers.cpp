#include<bits/stdc++.h>
using namespace std;

int main() {
    int cubesnum;
    cin >> cubesnum;
    vector<int> cubes(cubesnum);
    multiset<int> sizes;
    int answer =0;
    for(auto &x : cubes) {
        cin >> x;
        if(sizes.upper_bound(x) == sizes.end()) {
            answer++;
        }
        else{
            sizes.erase(sizes.upper_bound(x));
        }
        sizes.insert(x);
    }

    cout << answer;

}