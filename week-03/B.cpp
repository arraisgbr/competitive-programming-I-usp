// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=425

#include<bits/stdc++.h>

using namespace std;

int main(){

  int aux;
  map<int, int> numeros;
  queue<int> fila;

  while(cin >> aux){
    auto it = numeros.find(aux);
    
    if(it == numeros.end())
      fila.push(aux);
  
    numeros[aux]++;
  }

  while(!fila.empty()){
    int aux = fila.front();
    cout << aux << " " << numeros[aux] << endl;
    fila.pop();
  }
}
