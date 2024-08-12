#include <iostream>
#include >conio>

using namespace std;

int main(){
	int numeros []={3,2,1,5,4}, i, j, min, aux;
	
	for(i=0; i<5; i++){
		min = i;
		for(jj=i+1; j<5;j++){
			if(nmeros[j]<numeros[min]){
				min=j;
			}
		}
		aux=numeros[i];
		numeros[i]=numeros[min];
		numeros[min]=aux;
		
	}
	cout<<"Ordenamiento por selacción ascendente"
	for(i=0; i<5; i++){
		cout<<numeros[i]<<"";
	}
	
	cout<<"Ordenamiento por selacción descendente"
	for(i=0; i<5; i--){
		cout<<numeros[i]<<"";
	}
	
	
	
	getch();
	return 0;
}
