#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll segnum;
    cin >> segnum;

    vector<ll> lsorted(segnum);
    vector<ll> rsorted(segnum);
    for(int i = 0 ;i < segnum; i++) {
        cin >> lsorted[i];
        cin >> rsorted[i]; 
    }
    sort(lsorted.begin(), lsorted.end());
    sort(rsorted.begin(), rsorted.end());
    vector<ll>points_covered(segnum + 1);

    ll lindex = 0 , rindex = 0;
    ll cursegs = 0;
    ll prev =0;

    while(rindex < segnum) {
        if(lindex < segnum && lsorted[lindex] <= rsorted[rindex]) {
            points_covered[cursegs] += lsorted[lindex] - prev;
            prev = lsorted[lindex];
            cursegs++;
            lindex++;
        }
        else {
            points_covered[cursegs] +=rsorted[rindex] - prev + 1;
            while(rindex < segnum - 1 && rsorted[rindex] == rsorted[rindex + 1]) {
                rindex++;
                cursegs--;
            }           
            prev = rsorted[rindex] + 1;
            cursegs--;
            rindex++;
        }
    }

    for(int i = 1; i <= segnum; i++){
        cout << points_covered[i] << " ";
    }

    cout << endl;


}