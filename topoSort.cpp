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

vector<int>lista[100000];
vector<bool>used;
vector<int>ans;
bool cycle;

void dfs(int node){
	
	if(used[node]==1) //ya fue procesado
		return;
	if(used[node]==0){ // ya habia pasado por este nodo
		cycle=true;
		return;
	}
	
	used[node]=0;
	
	forall(it,lista[node]){ // dfs
		dfs(*it);
	}
		
	ans.push_back(node); 
	used[node]=1;
}

void topologicalSort(){
	used.assingn(n,-1); //-1 no usado, 0 procesando, 1 ya procesado
	ans.clear;
	cycle=false;
	
	forn(i,n){
		if (used[i]!=1)
			dfs(i);
		if(cycle) break; //hay un ciclo, no existe orden topologico (no es DAG)
	}
	
	reverse(ans.begin(),ans.end());
}

int main(int argc, char *argv[]) {
	//ofstream arch;
	//arch.open("mila.txt");
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	return 0;
}





