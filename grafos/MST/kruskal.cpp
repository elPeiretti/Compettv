vector<long long>padre, peso;

bool comp(pair<int,par> a, pair<int,par> b){
	return a.first<b.first;
}

//                   UNION - FIND
// ===================================================

void makeSet(int v){
	padre[v]=v;
	peso[v]=1;
}
	
ll findSet(ll nodo){
	if (nodo == padre[nodo]) return nodo;
	return padre[nodo] = findSet(padre[nodo]);
}

void uniteSet(ll a, ll b){
	a=findSet(a);
	b=findSet(b);
	if(a!=b){
		if(peso[a] < peso[b]) {swap(a,b);}
		
		padre[b] = a;
		peso[a] += peso[b];
	}
}
	
// ===================================================

bool formaCiclo(pair<int,par> e){
	
	return findSet(e.second.first) == findSet(e.second.second);
	
}

ll kruskal(int v, int e, vector<pair<int,pair<int,int>>> edges, vector<pair<int,par>> &MST){
	
	ll ans=0;
	
	padre.resize(v); peso.resize(v);
	forn(i,v) {makeSet(i);}
	
	forn(i,edges.size()){
		
		if(!formaCiclo(edges[i])){
			
			uniteSet(edges[i].second.first,edges[i].second.second);
			MST.push_back(edges[i]);
			
			ans+=edges[i].first;
			
		}
		
	}
	
	return ans;
}
