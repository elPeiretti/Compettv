vector<int>listaAdy[1000000]; // grafo dado como lista de adyacencia
//o set tambien se puede usar

bitset<1000000>used; // bitset para marcar nodos ya visitados

void bfs(int nodoInic){
	
	queue<int> q;
	
	q.push(nodoInic);
	used.set(nodoInic);
	
	while(!q.empty()){
		
		int nodo=q.front();
		q.pop();
		
		for(auto it = listaAdy[node].begin(); it!=listaAdy[node].end(); ++it){
			if(!used[*it]){
				q.push(*it);
				used.set(*it);
			}
		}
	}
	
}
