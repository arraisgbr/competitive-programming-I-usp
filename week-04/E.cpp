// https://www.codechef.com/problems/CHEFPRMS

#include<bits/stdc++.h>

using namespace std;

bool sieveArr[152];
vector<int> primes;

void sieve(){
    for(int i = 2 ; i <= 150 ; i++){
        if(!sieveArr[i]) primes.push_back(i);
        for(int j = i * 2 ; j <= 150 ; j += i) sieveArr[j] = true;
    }
}

int main(){

    int t; cin >> t;
    
    sieve();
    
    vector<int> semiprimes;
    for(int i = 0 ; i < primes.size() ; i++){
        for(int j = i+1 ; j < primes.size() ; j++){
            semiprimes.push_back(primes[i]*primes[j]);
        }
    }
    sort(semiprimes.begin(), semiprimes.end());

    while(t--){
        int n; cin >> n;
        bool ok = false;
        int i = 0; int j = semiprimes.size() - 1;
        while(i <= j){
            int res = semiprimes[i] + semiprimes[j];
            if(res == n){
                cout << "YES\n";
                ok = true;
                break;
            }
            else if(res > n) j--;
            else i++;
        }
        if(!ok) cout << "NO\n";
    }

}