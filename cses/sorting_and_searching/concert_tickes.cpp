#include<bits/stdc++.h>
using namespace std;

int main() {
    int ticknum , custnum;
    cin >> ticknum >> custnum ;

    multiset<int> ticketprices;
    for(int i = 0 ;i < ticknum ; i++) {
        int temp;
        cin >> temp;
        ticketprices.insert(temp);
    }
    for(int i = 0 ;i < custnum ; i++ ) {
        int customerbudget;
        cin >> customerbudget;

        multiset<int>::iterator shouldpay = ticketprices.upper_bound(customerbudget);
        if(shouldpay != ticketprices.begin()) {
            shouldpay--;
        }

        if(!ticketprices.empty() && *shouldpay <= customerbudget) {
            cout << *shouldpay << endl;
            ticketprices.erase(ticketprices.find(*shouldpay));
            continue;
        }

        cout << -1 << endl;

    }

    


}