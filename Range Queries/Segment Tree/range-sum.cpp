vector<int> tree;
vector<int> arr;
int n; //tamaño de arr

void build(int node, int izq, int der) { // complejidad O(N)
	
	if (izq == der) {
		tree[node] = arr[izq];
	} else {
		int mid = (izq + der)/2;
		build(node*2, izq, mid);
		build(node*2+1, mid+1, der);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
	
}

void update(int node, int izq, int der, int pos, int val) { // O(log N)
	
	if (izq == der) { //hoja
		tree[node] = val;
	} 
	else {
		int mid = (izq + der)/2;
		
		if (pos <= mid){ //si pos esta en el hijo izquierdo
			update(node*2, izq, mid, pos, val);
		}
		else{
			update(node*2+1, mid+1, der, pos, val);
		}
		
		tree[node] = tree[node*2] + tree[node*2+1]; // node va a tener la suma de sus hijos
	}
}

int sum(int node, int izq, int der, int l, int r){ // O(log N)
	
	if (r < izq or l > der) //fuera de rango
		return 0;
	
	if (l <= izq and r >= der) //rango completamente representado por un nodo
		return tree[node];
	
	//rango parcialmente representado por un nodo esta parcialmente dentro y parcialmente fuera del rango dado
	int mid = (izq + der) / 2;
	int p1 = sum(node*2, izq, mid, l, min(r, mid));
	int p2 = sum(node*2+1, mid+1, der, max(l, mid+1), r);
	
	return (p1+p2);
	
}


int main(int argc, char *argv[]) {
	
	cin>>n;
	tree.resize(2*n,0);
	build(1,0,n-1);
	//los primeros 3 argumentos siempre seran los mismos
	update(1,0,n-1,posicionVector,valor);
	cout<<sum(1,0,n-1,rangoIzq,rangoDer)<<endl; 
	
	return 0;
}

