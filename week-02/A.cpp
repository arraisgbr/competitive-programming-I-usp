// https://codeforces.com/problemset/problem/1006/C

#include<bits/stdc++.h>

using namespace std;

int n;
long long somaPre[212345];
long long somaSuf[212345];
int d[212345];

long long busca(int ini, long long valor){
    int l = ini;
    int r = n;

    while(l <= r){
        int meio = (l + r) / 2;
        if(somaSuf[meio] == valor) return valor;
        if(somaSuf[meio] > valor) l = meio+1;
        else r = meio-1;
    } 
    return -1;
}

int main(){

    cin >> n;

    for(int i = 0 ; i < n ; i++)
        cin >> d[i];
    
    somaPre[0] = d[0];
    for(int i = 1 ; i < n ; i++)
        somaPre[i] = somaPre[i-1] + d[i];

    somaSuf[n-1] = d[n-1];
    for(int i = n-2 ; i >= 0 ; i--)
        somaSuf[i] = somaSuf[i+1] + d[i];

    long long maximo = 0;
    for(int i = 0 ; i < n ; i++){
        maximo = max(maximo, busca(i+1, somaPre[i]));
    }

    cout << maximo << endl;

}