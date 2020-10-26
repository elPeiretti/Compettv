typedef pair<int,pair<int,int>> arista;

vector <vector<arista>> g(100);
bitset <100> used;

void prim(){
	
	priority_queue <arista> pq;
	
	for(auto a: g[1]){
		pq.push(a);
	}
	used[1]=1;
	
	
	while(!pq.empty()){
		
		arista a = pq.top();
		pq.pop();
		if((used[a.second.second]==1) xor (used[a.second.first]==1)){
			cout<<"de "<<a.second.first<<" a "<<a.second.second<<" peso:"<<a.first*-1<<endl;
			
			int n;
			if(used[a.second.second]==0) n = a.second.second;
			else n = a.second.first;
		
			for(auto a: g[n]){
				pq.push(a);
			}
			used[n] = 1;
		}
	}
	
}
