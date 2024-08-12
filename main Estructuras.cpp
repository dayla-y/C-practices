#include <iostream>
#include <conio.h>

using namespace std;

//declaración de struct alumno

struct Alumno{
	char nombre[50];
	int edad;
	float promedio;
} alumno;

int main{
	int i, mayor, pos;
	//Pedir daots de alumnos
	for(i=0; i<3; i++){
		cout<<"Nombre: "; cin.getline(a[i]. nombre, 50);
		cout<<"Edad: "; cin>> a[i].edad;
		cout<< "Promedio: ; cin>>a[i]. promedio;
		//comparar el de mayor promedio
			if(a[i].promedio>0){
				mayor= a[i].promedio;
				pos=i;
			}
		
	}
	
	cout<<"\t\Alumno con el mejor promedio \n";
	cout<<"Nombre: "<<a.[pos].nombre<<
	cout<<"Nombre: "<<a.[pos].edad<<
	cout<<"Nombre: "<<a.[pos].promedio<<
	

	gettch();
	return 0;
}
