// https://www.spoj.com/problems/RPLN/cstart=40

#include <stdio.h>
#include <algorithm>

using namespace std;
#define MAXELEM 1123456789
#define MAXN 100100
int evaluations[MAXN];
int seg[4*MAXN];

void build(int pos, int pos_l, int pos_r){
    if(pos_l == pos_r){
        seg[pos] = evaluations[pos_l];
        return;
    }

    int m = (pos_l + pos_r) / 2;
    int left_child = pos * 2;
    int right_child = pos * 2 + 1;

    build(left_child, pos_l, m);
    build(right_child, m+1, pos_r);

    seg[pos] = min(seg[left_child], seg[right_child]);
}

int query(int pos, int pos_l, int pos_r, int l, int r){
    if(r < pos_l || l > pos_r) return MAXELEM;
    if(l <= pos_l && pos_r <= r) return seg[pos];

    int m = (pos_l + pos_r) / 2;
    int left_child = pos * 2;
    int right_child = pos * 2 + 1;

    return min(query(left_child, pos_l, m, l, r), query(right_child, m+1, pos_r, l, r));
}

int main(){

    int t; scanf("%d", &t);

    for(int i = 1 ; i <= t ; i++){
        int n, q; scanf("%d %d", &n, &q);
        
        for(int j = 1 ; j <= n ; j++)
            scanf("%d", &evaluations[j]);

        build(1, 1, n);

        printf("Scenario #%d: \n", i);
        for(int j = 0 ; j < q ; j++){
            int a, b; scanf("%d %d", &a, &b);
            printf("%d\n", query(1, 1, n, a, b));
        }
    }
}