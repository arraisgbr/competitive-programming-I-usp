// https://www.spoj.com/problems/MARBLES/

#include<bits/stdc++.h>

using namespace std;

long long fato[11234567];

long long bino(long long a, long long b){
    if(b > a / 2) b = a - b;    
    long long ans = 1;
    for(long long i = 0; i < b; i++){
        ans = ans * (a - i) / (i + 1);
    }
    return ans;
}

int main(){

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        long long ans = bino(n - 1, n - k);

        cout << ans << endl;
    }

}