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

const int INF = 1000000000;
vector<vector<pair<int, int>>> graph; //par<peso,nodoLlegada>

//solo sirve para calc la dist de un nodo S a todos los otros.
//dist[k] es la distancia de S a K. dist[s]=0, dist[k]=INF

void dijkstra(int s, vector<int> &dist, vector<int> &padre) {
	int n = graph.size();
	vector<bool> used(n, false);
	
	padre.assign(n, -1);
	
	dist.assign(n, INF); 
	dist[s] = 0;


	for (int i = 0; i < n; i++){
		
		int v = -1;
		
		for (int j = 0; j < n; j++) { //agarro el nodo con menor distancia
			if (!used[j] and (v == -1 or dist[j] < dist[v]))
				v = j;
		}
		
		if (dist[v] == INF) //no se puede llegar de S a V
			break;
		
		used[v] = true;
		
		for (auto edge : graph[v]) { //relajaciones, para cada arista q sale de V
			int nodoLlegada = edge.second;
			int peso = edge.first;

			if (dist[v] + peso < dist[nodoLlegada]) { //relajar nodo
				dist[nodoLlegada] = dist[v] + peso;
				padre[nodoLlegada] = v; // para despues obtener el camino
			}
		}
		
	}
}


void mostrarCaminoMinimo(int nodoInic, int nodoFin, vector<int>padre){
	
	vector<int>aux;
	
	for(int v=nodoFin; v!=nodoInic; v=p[v]){
		aux.push_back(v);
	}
	aux.push_back(nodoInic);
	
	reverse(aux.begin(),aux.end());

	forall(it,aux){
		cout<<*it<<" ";
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





