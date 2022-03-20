// https://codeforces.com/problemset/problem/519/C

#include<iostream>

using namespace std;

int main(){

    int n, m; cin >> n >> m;
    int ans = 0;

    if(m > n){
        int aux = m;
        m = n;
        n = aux;
    }

    while(m > 0){
        if(n >= 2){
            n -= 2;
            m -= 1;
            ans += 1;
        }
        if(m > n){
            int aux = n;
            n = m;
            m = aux;
        }
        if(n == m && n == 1) break;
    }

    cout << ans << endl;
}