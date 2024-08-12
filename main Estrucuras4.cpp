#include <iostream>
#include <conio.h>

using namespace std;

struct empleado {
	char nombre[50];
	float salario;]
} e [100]

int main (){
	int n_empleados, i, mayor=0, posM, menor=0, posm;
	cout <<"Digite el numero de empleados: ";
	cin>>n_empleados;
	
	for(i=0; i<n; i++){
		fflusch(stdin);
		cout<< "Nombre del empleado: ";
		cin.getline(e[i].nombre, 50);
		cout<<"Salario del empleado: "";
		cin>>e[i].salario;
		
		if (e[i].salario>mayor){
			mayor=e[i].salario;
			posM=i;
		}
		if (e[i].salario>mayor){
			menor=e[i].salario;
			posm=i;
		}
	}
	
	getch();
	return =;
}
