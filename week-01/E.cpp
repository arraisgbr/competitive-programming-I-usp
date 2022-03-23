// https://www.eolymp.com/en/problems/1546

#include <bits/stdc++.h>

using namespace std;

int main() {

  int t; cin >> t;

  while(t--){
    int l, n; cin >> l >> n;
    int arr[1123456];
    int ansMin = 0;
    int ansMax = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        int minLocal = min(arr[i], abs(arr[i] - l));
        ansMin = max(ansMin, minLocal);
    }

    sort(arr, arr+n);

    int esq = max(arr[0], l - arr[0]);
    int dir = max(arr[n-1], l - arr[n-1]);
    ansMax = max(esq, dir);
    cout << ansMin << " " << ansMax << endl;
  }
}
