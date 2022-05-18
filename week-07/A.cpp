// https://www.spoj.com/problems/LABYR1/cstart=30

#include<bits/stdc++.h>

using namespace std;

int c, r;
char lab[1002][1002];
int dist[1005][1005];
int moveX[] = {-1, 0, 1, 0};
int moveY[] = {0, 1, 0, -1};

bool isOk(int x, int y){
    if(x >= r || x < 0 || y >= c || y < 0 || dist[x][y] != 0 || lab[x][y] == '#')
        return false;
    return true;
}

void dfs(pair<int, int> v){
    for(int i = 0 ; i < 4 ; i++){
        int x = v.first + moveX[i];
        int y = v.second + moveY[i];
        if(isOk(x, y)){
            dist[x][y] = dist[v.first][v.second] + 1;
            dfs(make_pair(x, y));
        }
    }
}

int main(){

    int t; cin >> t;

    while(t--){
        cin >> c >> r;
        pair<int, int> free;
        memset(dist, 0, sizeof(dist));

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                cin >> lab[i][j];
                if(lab[i][j] == '.'){
                    free.first = i;
                    free.second = j;
                }
            }
        }

        dfs(free);

        pair<int, int> ponta;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(dist[i][j] > dist[ponta.first][ponta.second]){
                    ponta.first = i;
                    ponta.second = j;
                }
            }
        }

        memset(dist, 0, sizeof(dist));
        dfs(ponta);

        int ans = 0;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++)
                ans = max(ans, dist[i][j]);
        }

        cout << "Maximum rope length is " << ans << "." << endl;
    }
}