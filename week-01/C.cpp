// https://www.spoj.com/problems/MAXSUMSU.pdf

#include<iostream>

using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        
        int arr[1123456];
        int n; cin >> n;
        
        int sum = 0;
        int maxSum = 0;

        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            sum += arr[i];
            if(sum < 0)
                sum = 0;
            else
                maxSum = max(sum, maxSum);
        }

        cout << maxSum << endl;
    }
}