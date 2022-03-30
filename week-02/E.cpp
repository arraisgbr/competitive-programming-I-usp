// https://codeforces.com/problemset/problem/492/B

#include<bits/stdc++.h>

using namespace std;

int main(){

    int  n, l; cin >> n >> l;
    int street[1123];

    for(int i = 0 ; i < n ; i++)
        cin >> street[i];

    sort(street, street+n);

    int ansEsq = street[0];
    
    int ans = 0;
    for(int i = 1 ; i < n ; i++){
        ans = max((street[i] - street[i-1]), ans);
    }
    
    int ansDir = l - street[n-1];

    ans = max(ans, ansEsq*2);
    ans = max(ans, ansDir*2);

    cout << setprecision(8) << fixed;
    cout << ans / 2. << endl;
}