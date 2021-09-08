
int v,e; //cant de nodos y aristas
// grafo dado como una lista de aristas <peso, <nodoSalida, nodoLlegada>>
vector<pair<int,pair<int,int>>> edges; //hay que sortear el vector en funcion del peso antes de llamar a kruskal()
vector<pair<int,pair<int,int>>> MST; // Arbol de cobertura minimo (dado como una lista de aristas)
vector<long long>padre, peso;

//                   UNION - FIND
// ===================================================

void makeSet(int v){
	padre[v]=v;
	peso[v]=1;
}
	
long long findSet(long long nodo){
	if (nodo == padre[nodo]) return nodo;
	return padre[nodo] = findSet(padre[nodo]);
}

void uniteSet(long long a, long long b){
	a=findSet(a);
	b=findSet(b);
	if(a!=b){
		if(peso[a] < peso[b]) {swap(a,b);}
		
		padre[b] = a;
		peso[a] += peso[b];
	}
}
	
// ===================================================

bool formaCiclo(pair<int,pair<int,int>> e){
	
	return findSet(e.second.first) == findSet(e.second.second);
	
}

long long kruskal(int v, int e){
	
	long long ans=0;
	
	padre.resize(v); peso.resize(v);
	for(int i=0; i<v; i++) makeSet(i);
	
	for(int i=0; i<edges.size(); i++){
		
		if(!formaCiclo(edges[i])){
			
			uniteSet(edges[i].second.first,edges[i].second.second);
			MST.push_back(edges[i]);
			ans+=edges[i].first;
		}
	}
	
	return ans;
}
