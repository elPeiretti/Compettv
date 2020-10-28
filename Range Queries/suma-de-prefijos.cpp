// O(n) inicializacion
// O(1) responder la query

vector<int> arr;
vector<int> sumArr;
	
arr.push_back(0); //para usar indexacion 1, previo a su inicializacion

//hacer vector de sumas
sumArr.push_back(0);
for(int i=1; i<arr.size(); i++){
  sumArr.push_back(arr[i] + sumArr[i-1]);
}

//la suma entre el rango [2,5] sera sumArr[5]-sumArr[2]
cout<<sumArr[5]-sumArr[2]<<endl;
