vector<int>listaAdy[1000000];
//o set tambien se puede usar

bitset<1000000>used;

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
