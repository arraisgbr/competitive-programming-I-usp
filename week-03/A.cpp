// https://www.spoj.com/problems/CSUMQ/

#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n; cin >> n;
	int arr[100005];
	int ac[100005];
	
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	
	ac[0] = 0;
	for(int i = 1 ; i <= n ; i++)
		ac[i] = ac[i-1] + arr[i-1];
		
	int q; cin >> q;
	for(int i = 0 ; i < q ; i++){
		int l, r; cin >> l >> r;
		cout << ac[r+1] - ac[l] << endl;
	}
	
}
