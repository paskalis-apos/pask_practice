#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double n;
set<double> haybales;

bool checkright(double num , double loc) {
    set<double>::iterator it = haybales.lower_bound(loc);
    double curvel = num;
    double newloc = loc;
    bool hitone = false;
    while(it != haybales.end()) {
        if(loc + curvel >= *it) {
            newloc = *it;
            hitone = true;
            it++;
        } 
        else {
            if(hitone) {
                loc = newloc;
                curvel--;
                hitone = false;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

bool checkleft(double num , double loc) {
    set<double>::iterator it = haybales.upper_bound(loc);
    it--;
    double curvel = num;
    double newloc = loc;
    bool hitone = false;
    while(it != haybales.begin()) {
        if(loc - curvel <= *it) {
            newloc = *it;
            hitone = true;
            it--;
        } 
        else {
            if(hitone) {
                loc = newloc;
                curvel--;
                hitone = false;
            }
            else {
                return false;
            }
        }
    }

    return true;
}


bool valid(double num) {
    double l = 0;
    double r = 1e9;
    while(l < r - 1e-2) {
        double mid = (l + r) / 2;
        if(checkleft(num , mid) && checkright(num , mid)) {
            return true;
        }
        else if(checkleft(num, mid)) {
            l = mid;
        }
        else if(checkright(num,mid)) {
            r = mid;
        }
        else {
            return false;
        }
    }

    return false;
}

int main() {
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n;
    haybales.insert(-1);
    for(int i = 0 ;i < n; i++) {
        double temp;
        cin >> temp;
        haybales.insert(temp);
    }

    double l = 0, r = 1e9;
    while(l < r - 1e-2) {
        double mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    double answer = l;
    printf("%.1f\n", answer);
}