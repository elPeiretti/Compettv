const int INF = 1000000000;
vector<vector<pair<int, int>>> graph; // listado de aristas - pair<peso,nodoLlegada>

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
	
	for(int v=nodoFin; v!=nodoInic; v=padre[v]){
		aux.push_back(v);
	}
	aux.push_back(nodoInic);
	
	reverse(aux.begin(),aux.end());

	for(auto it : aux){
		cout<<it<<" ";
	}
	
}	
