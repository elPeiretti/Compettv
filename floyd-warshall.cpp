#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define forall(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()
#define DBG(x) cout << #x << " = " << (x) << endl
#define RAYA arch << "===============================" << endl
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> par;

vector<vector<int>>dist;
//se fija todos los caminos posibles entre i y j, viendo si
//el camino con el nodo intermedio K es mas corto o no.
//los cilos de i-i van con 0
void floydW(int n){
	
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] < INF and dist[k][j] < INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
			}
		}
	}
}

int main(int argc, char *argv[]) {
	//ofstream arch;
	//arch.open("mila.txt");
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	return 0;
}





