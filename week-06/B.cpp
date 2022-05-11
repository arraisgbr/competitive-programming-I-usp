// https://www.spoj.com/problems/GOODB/

#include<bits/stdc++.h>

#define MOD 1000000007
#define ll long long

using namespace std;

long long fastxp(long long base, long long e){
    if(e == 0) return 1;
    long long ans = fastxp(base, e/2);
    ans = ans * ans % MOD;
    if(e % 2 == 1)
        ans = ans * base % MOD;
    return ans;
}

ll fato[305];

int main(){

    fato[0] = 1;
    int n, w, t, r; cin >> n >> w >> t >> r;
    for(int i = 1 ; i <= 300 ; i++)
        fato[i] = (i * fato[i-1]) % MOD;

    if(w == 0) fato[w] = 1;
    if(r == 0) fato[r] = 1;
    if(t == 0) fato[t] = 1;
    long long ans = fato[n] * fastxp(fato[w], MOD - 2) % MOD;
    ans = ans * fastxp(fato[r], MOD - 2) % MOD;
    ans = ans * fastxp(fato[t], MOD - 2) % MOD;

    cout << ans << endl;
}