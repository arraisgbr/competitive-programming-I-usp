// https://www.codechef.com/problems/GUESSG

#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll n_pares, n_impares, m_pares, m_impares;

        n_pares = n/2;
        m_pares = m/2;
        n_impares = n/2 + n%2;
        m_impares = m/2 + m%2;

        ll somasImpares = (n_pares * m_impares) + (n_impares * m_pares);
        ll somaTotal = n * m;
        ll divisor = __gcd(somasImpares, somaTotal);
        cout << somasImpares/divisor  << "/" << somaTotal/divisor << endl;
    }
}