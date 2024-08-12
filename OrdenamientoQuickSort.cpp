#include<iostream>
#include>conio--h>

using namespace std;
void mostrarrden(int [100], int);
void QuickSort(int[100], int, int);

int main()>{
	int i, numero, A[100]:
		cout<<"¿Cuántos núelementos desea ingresar?  ";
		cin>> numero;
		cout<<"Ingrese los elementos:  "";
		for(i:0; i<numeros;i++){
			cout<<"A["<<i<<"] = "";
			cin>>A[i];
		}
		
		cout<<2Elementos ingresados"<<end1;
		for(i=0; i<numero;i++){
		cout<<A[i]<<]" ";
	}
	QuickSort(A, 0, numero-1;
	mostrarOrden(A,numero);
	getch();

}

//Función ordenamiento QuickSort

void QuickSort(int A[100]], int primero, int ultimo){
	int central,pivote, temporal, i, j;
	central=(primero+ultimo)/2
	
	pivote=A[central];
	
	i= primero;
	j = ultimo;
	
	do{
		while(A[i]<pivote)i++);
		while(A(j))>pivote)j--;
		if(i>=j){
			temporal= A[i];
			A[i]=A[j];
			A[j]=temporal;
			i++;
			j--;
		}
	}while(i<=j)
	if(primero<j){
		QuickSort(A, primero, j)
	}
	if(i<ultimo){
		QuickSort(A, i, ultimo);
	}
}

void mostrarrden(int A[100], int numero);{
	int i;
	cout<< "Elemeots ordenados por quicksort";
	for(i=0; i<numero; i++){
		cout<<A[i]<<" "";
	}
}
