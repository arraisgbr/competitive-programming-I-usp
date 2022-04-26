// https://codeforces.com/problemset/problem/230/B

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n;
    long long arr[112345];

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 1){
            cout << "NO\n";
            continue;
        }
        long long square = (long long)sqrt(arr[i]);
        long long aux = square * square;
        if(aux == arr[i]){
            bool ok = true;
            for(int j = 2 ; j * j <= square ; j++){
                if(arr[i] % j == 0){
                    cout << "NO\n";
                    ok = false;
                    break;
                }
            }
            if(ok) cout << "YES\n";
        }
        else cout << "NO\n";
    }
}