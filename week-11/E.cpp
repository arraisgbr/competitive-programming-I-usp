// https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%204/359_English.htm

#include<bits/stdc++.h>

using namespace std;

int main(){

    double r, cx, cy, x1, y1, x2, y2;
    cin >> r >> cx >> cy >> x1 >> y1 >> x2 >> y2;
    
    // y - y1 = m(x - x1)
    double m = abs(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    double a = y2 - y1;
    double b = -x2 + x1;
    double c = x2 * y1 - x1 * y2;

    double d = abs(a * cx + b * cy + c)/sqrt(a*a + b*b);

    if(d > r) cout << -1 << endl;
    else if (d == r) cout << 0 << endl;
    else{
        double ans = 2 * sqrt(r*r - d*d);
        cout << setprecision(5) << fixed;
        cout << ans << endl;
    }    
}