// https://www.spoj.com/problems/FOXLINGS/

#include<bits/stdc++.h>

using namespace std;

map<int, int> pai;

int find(int a){
    map<int, int>::iterator it = pai.find(a);
    if(it == pai.end()) return a;
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
    int count = 0;

    for(int i = 0 ; i < m ; i++){
        int a, b; cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a == b) continue;
        join(a, b);
        count++;
    }

    cout << n - count << endl;
}