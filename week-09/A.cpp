// https://br.spoj.com/SPOJ/problems/MST/cstart=60

#include<bits/stdc++.h>

using namespace std;

int pai[11234];
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > adj;

int find(int a){
    if(pai[a] == a) return a;
    return pai[a] = find(pai[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    pai[a] = b;
}

int main(){

    int n, m; cin >> n >> m;

    for(int i = 1 ; i <= n ; i++)
        pai[i] = i;

    for(int z = 0 ; z < m ; z++){
        int i, j, k; cin >> i >> j >> k;
        adj.push(make_pair(k, make_pair(i, j)));
    }

    int ans = 0;
    while(!adj.empty()){
        pair<int, pair<int, int> > v = adj.top();
        adj.pop();
        int a = find(v.second.first);
        int b = find(v.second.second);

        if(a == b) continue;
        else{
            ans += v.first;
            join(a, b);
        }

    }
    cout << ans << endl;
}