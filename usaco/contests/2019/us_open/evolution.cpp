#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);
    int populations;   
    cin >> populations;
    vector<set<string>> characteristics(populations);
    set<string> allstringsset;

    for(int i = 0;i < populations; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            string temp;
            cin >> temp;
            characteristics[i].insert(temp);
            allstringsset.insert(temp);
        }
    }

    vector<string> allstring(allstringsset.begin(),allstringsset.end());

    for(int i = 0 ;i < allstring.size(); i++) {
        for(int j = i + 1; j < allstring.size(); j++) {
            bool only_a = false, only_b = false, both = false;

            for(auto &x : characteristics) {
                bool has_a = x.count(allstring[i]);
                bool has_b = x.count(allstring[j]);

                if(has_a && has_b) {
                    both = true;
                }
                else if(has_a) {
                    only_a = true;
                }
                else if(has_b) {
                    only_b = true;
                }
            }

            if(only_a && only_b && both) {
                cout << "no" << endl;
                return 0;
            }
        }
    }

    cout << "yes" << endl;


}