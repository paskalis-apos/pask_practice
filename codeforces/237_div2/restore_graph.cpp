#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , k;  
    cin >> n >> k;
    vector<pair<int,int>> distances(n);
    for(int i = 0 ;i < n ;i++) {
        cin >> distances[i].first;
        distances[i].second = i + 1;
    }

    vector<pair<int,int>> edges;
    sort(distances.begin(), distances.end());
    int prevind = 0;
    int prevedges = 0;
    int curdist = 1;
    int nextind = 1;
    if(distances[1].first == 0) {
        cout << -1 << endl;
        return 0;
    }
    if(distances[0].first != 0) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1;i < n; i++) {
        if(distances[i].first == curdist) {
            if(prevedges == k) {
                prevind++;
                prevedges = 1;
                if(distances[prevind].first == curdist) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            prevedges++;
            edges.push_back({distances[i].second, distances[prevind].second});
        }
        else if(distances[i].first == curdist + 1){
            prevind = nextind;
            nextind = i;
            curdist++;
            i--;
            prevedges = 1;
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << edges.size() << endl;
    for(auto &x : edges){
        cout << x.first << " " << x.second << endl;
    }
}