// https://www.spoj.com/problems/FCTRL/cstart=10

#include<bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        while(n > 0){
            n /= 5;
            ans += n;
        }
        cout << ans << endl;
    }
}