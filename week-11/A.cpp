// https://www.eolymp.com/en/contests/13978/problems/137776

#include<bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    double norma(){
        return sqrt(this->x * this->x + this->y * this->y);
    }
    Point operator-(Point other){
        Point resultado = Point(this->x - other.x, this->y - other.y);
        return resultado;
    }
    double operator*(Point other){
        double ans = this->x * other.y - this->y * other.x;
        return ans;
    }
};

int main(){

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point v = Point(x1 - x2, y1 - y2);
    Point u = Point(x1 - x3, y1 - y3);
    Point w = Point(x2 - x3, y2 - y3);

    double perimetro = v.norma() + u.norma() + w.norma();

    double areaParalelogramo = v * u;

    double altura = areaParalelogramo / u.norma();

    double areaTriangulo = (u.norma() * altura) / 2;

    cout << setprecision(4) << fixed;

    cout << perimetro << " " << abs(areaTriangulo) << endl;

}