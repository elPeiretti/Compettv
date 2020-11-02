
int n; //tamaño del vector
vector<int>bit; //array con indexacion 1.


//armar arbol
// agrega 'val' al indice 'i'
void update(int i, int val){
	for(; i<=n ; i+= i&-i){
		bit[i] += val;
	}
}
	
int sum(int i){
	int ans=0;
	for(; i>0; i -= i&-i){
		ans+= bit[i];
	}
	
	return ans;
}


int main(int argc, char *argv[]) {
	
	cin>>n;
	bit.resize(n+1);
	
	for(int i=1;i<=n;i++){ //init
		int x; cin>>x;
		update(i,x);
	}
	
	// sum(X) representa la suma del rango [1...X]
	// [A;B] se obtiene como sum(B)-sum(A-1)
	
	return 0;
}







