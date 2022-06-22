// https://codeforces.com/problemset/problem/227/A

#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct Point{
    ll x, y;
    Point(ll x, ll y){
        this->x = x;
        this->y = y;
    }
    ll operator *(Point other){
        ll ans = this->x * other.y - this->y * other.x;
        return ans;
    }
};

int main(){

    ll xa, ya; cin >> xa >> ya;
    ll xb, yb; cin >> xb >> yb;
    ll xc, yc; cin >> xc >> yc;

    Point AC = Point(xc - xa, yc - ya);
    Point AB = Point(xb - xa, yb - ya);
    
    ll cross = AB * AC;
    if(cross == 0) cout << "TOWARDS\n";
    else if(cross > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}