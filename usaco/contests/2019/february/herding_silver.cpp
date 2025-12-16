#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int numcows;
    cin >> numcows;

    vector<int> cow_loc(numcows);
    for(auto &x : cow_loc) {
        cin >> x;
    }

    sort(cow_loc.begin(), cow_loc.end());
    int min_ans = 0;
    if(cow_loc[numcows - 2] - cow_loc[0] == numcows - 2 && cow_loc[numcows - 1] - cow_loc[numcows - 2] > 2) {
        min_ans = 2;
    }
    else if(cow_loc[numcows -1] - cow_loc[1] == numcows - 2 && cow_loc[1] - cow_loc[0] > 2) {
        min_ans = 2;
    }

    int l = 0;
    int r = 0;
    int minmoves = INT_MAX;
    while(r < numcows) {
        if(cow_loc[r] - cow_loc[l] > numcows - 1) {
            l++;
        }
        else {
            minmoves = min(minmoves, numcows - (r - l) - 1);
            r++;
        }
    }

    int maxmoves = max(cow_loc[numcows - 2] - cow_loc[0], cow_loc[numcows - 1] - cow_loc[1]) - numcows + 2;
    minmoves = max(min_ans , minmoves);
    cout << minmoves << endl << maxmoves << endl;
}