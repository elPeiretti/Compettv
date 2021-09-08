vector<int>lista[100000]; // grafo como lista de adyacencia
vector<bool>used; // vector de nodos usados
vector<int>ans; // vector de nodos con el recorrido topologico
bool cycle; // flag para indicar si hay un ciclo
int n; // cantidad de nodos en el grafo

void dfs(int node){
	
	if(used[node]==1) //ya fue procesado
		return;
	if(used[node]==0){ // ya habia pasado por este nodo
		cycle=true;
		return;
	}
	
	used[node]=0;
	
	for(auto it: lista[node]){ // dfs
		dfs(it);
	}
		
	ans.push_back(node); 
	used[node]=1;
}

void topologicalSort(){
	used.assign(n,-1); //-1 no usado, 0 procesando, 1 ya procesado
	ans.clear();
	cycle=false;
	
	for(int i=0; i<n; i++){
		if (used[i]!=1)
			dfs(i);
		if(cycle) break; //hay un ciclo, no existe orden topologico (no es DAG)
	}
	
	reverse(ans.begin(),ans.end());
}
