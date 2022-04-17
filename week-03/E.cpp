// https://www.spoj.com/problems/STPAR/

#include<bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        queue<int> street;
        stack<int> sideStreet;
        int atual = 1;
        sideStreet.push(0);
        bool ans = true;
        int n; cin >> n;
        for(int i = 0 ; i < n ; i++){
            int number; cin >> number;
            if(number == atual){
                street.push(number);
                atual++;
                while(sideStreet.top() == atual){
                    sideStreet.pop();
                    street.push(atual);
                    atual++;
                }
            }
            else{
                if(sideStreet.top() == 0 || number < sideStreet.top())
                    sideStreet.push(number);
                else
                    ans = false;
            }
        }
        if(ans) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}