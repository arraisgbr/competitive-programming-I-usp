// https://br.spoj.com/problems/LASTDIG/

#include<bits/stdc++.h>

using namespace std;

int main(){

  int t; cin >> t;

  while(t--){
    int a, b; cin >> a >> b;
    if(b == 0) cout << 1 << endl;
    else if(b%4 == 0) cout << (int)pow(a%10, (b-1)%4 + 1)%10 << endl;
    else cout << (int)pow(a%10, b%4)%10 << endl;
  }

}