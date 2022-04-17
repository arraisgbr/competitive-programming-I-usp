// https://codeforces.com/problemset/problem/676/C

#include<bits/stdc++.h>

using namespace std;

int n, k; 
string s;

int ans(char letter){
    int l, r; l = r = 0;
    int kAux = k;
    int maxT = 0;
    while(r < n){
        if(s[r] == letter){
            r++;
        }
        else{
            if(kAux > 0){
                kAux--;
                r++;
            }
            else{
                while(s[l] == letter)
                    l++;
                l++;
                kAux++;
            }
        }
        maxT = max(maxT, r - l);
    }

    return maxT;
}

int main(){

    cin >> n >> k;
    cin >> s;

    int maxTotal = max(ans('a'), ans('b'));

    cout << maxTotal << endl;
}