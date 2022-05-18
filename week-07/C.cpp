// https://www.eolymp.com/en/problems/1104

#include<bits/stdc++.h>

using namespace std;

vector<int> adj[10005];
bool visited[10005];

void dfs(int v){
    visited[v] = true;
    for(auto it : adj[v]){
        if(!visited[it]) dfs(it);
    }
}

int main(){

    int t; cin >> t;

    while(t--){
        int n, m, l; cin >> n >> m >> l;
        
        memset(visited, false, sizeof(visited));
        
        for(int i = 0 ; i < m ; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }

        for(int i = 0 ; i < l ; i++){
            int z; cin >> z;
            dfs(z);
        }

        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(visited[i]) ans++;
        }

        cout << ans << endl;

        for(int i = 0 ; i <= n ; i++)
            adj[i].clear();
    }
}