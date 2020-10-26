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




