#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long x, n, alex;
    cin >> n;
    alex = 0;
    vector<long long> leftover;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) {
            alex += x;
        } else {
            leftover.push_back(-x);
        }
    }
    
    sort(leftover.begin(), leftover.end());
    
    if (!alex) {
        alex -= leftover[0];
        int rem = leftover.size();
        
        if (rem > 1 && rem & 1) {
            alex -= leftover[1];
        }
        
        for (int st = 2 + (rem & 1); st < rem; st += 2) {
            alex -= leftover[st];
        }
        
        cout << alex << "\n";
    } else {
        int rem = leftover.size();
        
        for (int st = 0 + (rem & 1); st < rem; st += 2) {
            alex -= leftover[st];
        }
        
        cout << alex << "\n";
    }
    
    return 0;
}
