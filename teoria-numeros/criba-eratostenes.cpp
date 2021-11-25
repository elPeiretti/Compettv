
const int n = 10000000;
bool criba[n+1];


 // Complejidad O(N log log N)
void initCriba(){
	memset(criba,true,sizeof(criba));
	for(int j=4; j<=n ; j+=2)
		criba[j]=false;
	
	for(int i=3; i*i<=n; i+=2){
		if(criba[i]){
			for(int j=i*i; j<=n; j+=2*i){
				criba[j]=false;
			}
		}
	}
}

//Despues se puede acceder en O(1) para consultar si un numero es primo o no.
