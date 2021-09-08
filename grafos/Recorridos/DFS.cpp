vector<int>listaAdy[1000000]; // grafo dado como lista de adyacencia
//o set tambien se puede usar
bitset<1000000>used;

void dfs(int node){
	used.set(node);
	for(auto it = listaAdy[node].begin(); it!=listaAdy[node].end(); ++it){
		if(!used[*it]){
			dfs(*it);
		}
	}
}
