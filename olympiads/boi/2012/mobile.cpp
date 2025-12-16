#include<bits/stdc++.h>
using namespace std;
using dd = double;

struct trans {
    dd x , y;
    dd change;
};

dd change(dd x1, dd y1, dd x2, dd y2) {
    dd up = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
    dd down = 2 * (x2 - x1);
    return dd(up / down);
}

int main() {
    int n;
    dd l;
    cin >> n >> l;

    stack<trans>s;
    dd x ,y;
    cin >> x >> y;
    dd maxdist = 0;
    s.push({x , y , 0});


    for(int i = 1 ;i < n ;i++) {
        cin >> x >> y;
        if(fabs(x - s.top().x) < 1e-8) {
            if(fabs(y) < fabs(s.top().y)) {
                s.pop();
            }
            else {
                continue;
            }
        }
        dd xchange = 0;
        while(!s.empty()) {
            dd x2 = s.top().x;
            dd y2 = s.top().y;
            xchange = change(x , y , x2 ,y2);

            if(xchange < s.top().change) {
                s.pop();
            }    
            else {
                break;
            }
        }
        s.push({x , y , xchange});
    }

    while(s.top().change > l) {
        s.pop();
    }
    x = s.top().x;
    y = s.top().y;
    maxdist = max(maxdist, sqrt((x - l) * (x - l) + y * y));
    while(s.top().change > 0) {
        x = s.top().x;
        y = s.top().y;
        dd xchange = s.top().change;
        maxdist = max(maxdist,sqrt((x - xchange) * (x - xchange) + (y * y)));
        s.pop();
    }
    x = s.top().x;
    y = s.top().y;
    maxdist = max(maxdist, sqrt(x * x + y * y));

    printf("%.6f\n", maxdist);

}