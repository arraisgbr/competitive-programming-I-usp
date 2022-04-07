// https://www.spoj.com/problems/HACKRNDM/

#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int  n, k; cin >> n >> k;
	int arr[112345];
	
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
		
	sort(arr, arr+n);
	
	int l = 0;
	int r = 0;
	int ans = 0;
	
	while(r < n){
		while(arr[r] - arr[l] < k && r < n)
			r++;
		
		if(arr[r] - arr[l] == k)
			ans++;
		
		l++;
	}
	
	cout << ans << endl;
}
