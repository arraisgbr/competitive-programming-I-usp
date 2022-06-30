// https://www.beecrowd.com.br/judge/en/problems/view/1301?origem=1

#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345
int elements[MAXN];
int seg[4*MAXN];

void build(int pos, int pos_l, int pos_r){
    if(pos_l == pos_r){
        if(elements[pos_l] != 0)
            seg[pos] = elements[pos_l] / abs(elements[pos_l]);
        else
            seg[pos] = 0;
        return;
    }

    int m = (pos_l + pos_r) / 2;
    int left_child = pos * 2;
    int right_child = pos * 2 + 1;

    build(left_child, pos_l, m);
    build(right_child, m+1, pos_r);

    seg[pos] = seg[left_child] * seg[right_child];
}

int query(int pos, int pos_l, int pos_r, int l, int r){
    if(r < pos_l || l > pos_r) return 1;
    if(l <= pos_l && pos_r <= r) return seg[pos];

    int m = (pos_l + pos_r) / 2;
    int left_child = pos * 2;
    int right_child = pos * 2 + 1;

    return query(left_child, pos_l, m, l, r) * query(right_child, m+1, pos_r, l, r);
}

void update(int pos, int pos_l, int pos_r, int indice, int valor){
    if(indice < pos_l || indice > pos_r) return;
    if(pos_l == pos_r){
        if(valor != 0)
            seg[pos] = valor / abs(valor);
        else
            seg[pos] = valor;
        return;
    }

    int m = (pos_l + pos_r) / 2;
    int left_child = 2 * pos;
    int right_child = 2 * pos + 1;
   
    update(left_child, pos_l, m, indice, valor);
    update(right_child, m+1, pos_r, indice, valor);

    seg[pos] = seg[left_child] * seg[right_child];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while(cin >> n >> k){
        for(int i = 1 ; i <= n ; i++)
            cin >> elements[i];

        build(1, 1, n);

        for(int i = 1 ; i <= k ; i++){
            char letter;
            int aux1, aux2; 
            cin >> letter >> aux1 >> aux2;
            if(letter == 'C'){
                update(1, 1, n, aux1, aux2);
            }
            else if(letter == 'P'){
                int mult = query(1, 1, n, aux1, aux2);
                if(mult > 0) cout << "+";
                else if(mult < 0) cout << "-";
                else cout << "0";
            }
        }

        cout << "\n";
    }
}