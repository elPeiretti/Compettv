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




