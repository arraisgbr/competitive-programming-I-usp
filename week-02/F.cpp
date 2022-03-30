// https://www.codechef.com/problems/TRICOIN

#include<bits/stdc++.h>

using namespace std;

int soma(int fim){
    int ans = 0;
    for(int i = 1 ; i <= fim ; i++)
        ans += i;
    return ans;
}

int busca(int N){
    int l = 1;
    int r = 100000;
    int ans;
    while(l <= r){
        int meio = (l + r) / 2;
        long long eq = soma(meio);
        if(eq <= N){
            l = meio+1;
            ans = meio;
        }
        else r = meio-1;
    }
    return ans;
}

int main(){
    
    int t; cin >> t;

    while(t--){
        int N; cin >> N;
        long long ans = busca(N);
        cout << ans << endl;
    }
}