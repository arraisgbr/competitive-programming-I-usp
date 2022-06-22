// http://poj.org/problem?id=2606

#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int operator * (Point other){
        int ans = this->x * other.y - this->y * other.x;
        return ans;
    }
    Point operator - (Point other){
        Point novo = Point(this->x - other.x, this->y - other.y);
        return novo;
    }
};

int main(){

    int n; cin >> n;
    Point pontos[205];

    for(int i = 0 ; i < n ; i++){
        int x, y; cin >> x >> y;
        pontos[i] = Point(x, y);
    }

    int maxAns = 0;
    for(int i = 0 ; i < n ; i++){
        Point principal;
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            principal = pontos[i] - pontos[j];
            int ans = 2;
            for(int k = 0 ; k < n ; k++){
                if(i == k || j == k) continue;
                Point secundario = pontos[i] - pontos[k];
                int cross = principal * secundario;
                if(cross == 0){
                    ans++;
                }
            }
            maxAns = max(ans, maxAns);
        }
    }
    
    cout << --maxAns << endl;
}