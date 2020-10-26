#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

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

int main(int argc, char *argv[]) {
//nodo            peso de hasta
	g[0].push_back({-350,{0,1}});
	g[1].push_back({-350,{0,1}});
	g[1].push_back({-180,{1,2}});
	g[2].push_back({-180,{1,2}});
	g[0].push_back({-270,{0,3}});
	g[3].push_back({-270,{0,3}});
	g[3].push_back({-200,{3,4}});
	g[4].push_back({-200,{3,4}});
	g[4].push_back({-300,{4,5}});
	g[5].push_back({-300,{4,5}});
	g[1].push_back({-190,{1,4}});
	g[4].push_back({-190,{1,4}});
	g[3].push_back({-500,{3,5}});
	g[5].push_back({-500,{3,5}});
	g[2].push_back({-400,{2,5}});
	g[5].push_back({-400,{2,5}});
	
	used.reset();
	
	prim();

	return 0;
}


