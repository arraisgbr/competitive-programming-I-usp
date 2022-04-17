// https://codeforces.com/problemset/problem/295/A

#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll queries[112345];
ll queriesRes[112345];
ll queriesResAc[112345];

int main(){

    int n, m, k; cin >> n >> m >> k;
    ll arr[112345];
    vector<pair<pair<ll, ll>, ll> > ops;

    for(int i = 1 ; i <= n ; i++)
        cin >> arr[i];

    ops.push_back(make_pair(make_pair(0, 0), 0));
    for(int i = 1 ; i <= m ; i++){
        int l, r, d; cin >> l >> r >> d;
        ops.push_back(make_pair(make_pair(l, r), d));
    }

    for(int i = 1 ; i <= k ; i++){
        int x, y; cin >> x >> y;
        queries[x]++;
        queries[y+1]--;
    }

    ll sumQ[112345];
    sumQ[0] = 0;
    for(int i = 1; i <= m ; i++)
        sumQ[i] = sumQ[i-1] + queries[i];

    for(int i = 1 ; i <= m ; i++){
        ll mult = sumQ[i];
        ll valor = ops[i].second;
        ll ini = ops[i].first.first;
        ll fim = ops[i].first.second;
        queriesRes[ini] += valor * mult;
        queriesRes[fim+1] -= valor * mult;
    }

    queriesResAc[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        queriesResAc[i] = queriesResAc[i-1] + queriesRes[i];
    
    for(int i = 1 ; i <= n ; i++){
        arr[i] += queriesResAc[i];
    }

    for(int i = 1 ; i <= n ; i++)
        cout << arr[i] << " ";
        
    cout << endl;
}