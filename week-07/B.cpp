// https://codeforces.com/problemset/status?my=on

#include<bits/stdc++.h>

using namespace std;

int n, m; 
vector<int> adj[102];
bool visited[102];

void dfs(int v){
    visited[v] = true; 
    for(auto it : adj[v]){
        if(!visited[it]){
            dfs(it);
        }
    }
}

bool conexo(){
    dfs(1);

    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]) return false;
    }

    return true;
}

int main(){

    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(!conexo()){
        cout << "NO\n";
        return 0;
    }

    if(n != m){
        cout << "NO\n";
        return 0;
    }

    cout << "FHTAGN!" << endl;
}