// https://www.codechef.com/problems/RIGHTRI

#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int operator *(Point other){
        return this->x * other.x + this->y * other.y;
    }
};

int main(){

    int n; cin >> n;
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        Point u = Point(x1 - x2, y1 - y2);
        Point v = Point(x1 - x3, y1 - y3);
        Point w = Point(x2 - x3, y2 - y3);

        if(u * v == 0 || u * w == 0 || v * w == 0) ans++;
    }
    
    cout << ans << endl;
}