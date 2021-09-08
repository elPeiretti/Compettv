#define MAXN 10000
int bit[MAXN][MAXN];

void update(int x, int y, int val){
	for(;x<MAXN; x+= x&-x){
		for(int j=y ; j<MAXN; j+= j&-j){
		      bit[x][j] += val;
		}
	}
}

int getaux(int x, int y){
	int ans=0;

	for(; x; x-=x&-x){
		for(int j=y; j; j-=j&-j){
		  ans+=bit[x][j];
		}
	}
	return ans;
}

int get(int x1, int y1, int x2, int y2){
	return getaux(x2,y2)- getaux(x1-1,y2) - getaux(x2,y1-1) + getaux(x1-1,y1-1);
}
	
	
	
int main(int argc, char *argv[]) {

	int filas, columnas;
  	
	for(int i=1; i<filas+1; i++){ //inicializa la matriz
		for(int j=1; i<columnas+1; i++){
			int x; cin>>x;
			update(i,j,x);
		}
	}
		
	cout<<get(1,1,5,5);
		
	return 0;
}
