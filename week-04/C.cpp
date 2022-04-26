/**
The GCD of two positive integers is the largest integer that divides both the integers without any
remainder. The LCM of two positive integers is the smallest positive integer that is divisible by both
the integers. A positive integer can be the GCD of many pairs of numbers. Similarly, it can be the
LCM of many pairs of numbers. In this problem, you will be given two positive integers. You have to
output a pair of numbers whose GCD is the first number and LCM is the second number.
Input
The first line of input will consist of a positive integer T. T denotes the number of cases. Each of the
next T lines will contain two positive integer, G and L.
Output
For each case of input, there will be one line of output. It will contain two positive integers a and
b, a ≤ b, which has a GCD of G and LCM of L. In case there is more than one pair satisfying the
condition, output the pair for which a is minimized. In case there is no such pair, output ‘-1’.
Constraints
• T ≤ 100
• Both G and L will be less than 231
Sample Input
2
1 2
3 4
Sample Output
1 2
-1
**/

#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int t; cin >> t;
    
    while(t--){
        int gcd, lcm; cin >> gcd >> lcm;
        if(lcm % gcd == 0) cout << gcd << " " << lcm << endl;
        else cout << -1 << endl;
    }
}