// https://codeforces.com/problemset/problem/1644/A

#include<iostream>

using namespace std;

int main(){

    int t; cin >> t;

    while(t--){
        string map; cin >> map;
        bool r, g, b;
        r = g = b = false;
        bool isOkay = true;
        for(int i = 0 ; i < map.size() ; i++){
            if(map[i] == 'R'){
                if(r) continue;
                else{
                    isOkay = false;
                    break;
                }
            }
            else if(map[i] == 'G'){
                if(g) continue;
                else{
                    isOkay = false;
                    break;
                }
            }
            else if(map[i] == 'B'){
                if(b) continue;
                else{
                    isOkay = false;
                    break;
                }
            }
            else if(map[i] == 'r') r = true;
            else if(map[i] == 'g') g = true;
            else if(map[i] == 'b') b = true;
        }

        if(isOkay) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}