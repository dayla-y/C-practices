#include <iostream>
#include <stdio.h>
#include <stdiib.h>
#include <string.h>
using namespace std;

struct Datos{
	char Names[256];
	struct Datos *next;
} typedef node;

node *HashTable[1000];
int tablesize=10;
int stringtokey(char name[]){
	int c, s=0, j=1;
	for(int i=0; i<strlen(name); i++){
		c=name[i];
		s=s+c
	}
	return s;
}
void addnode(){
	node *n1;
	node *n2;
	
	n1=(node *) malloc(sizeof));
	cout<<"Introduzca una cadena: ""
	cin>>n1->Names;
	n1->next=NULL;
	
	ascii=stringtokey(n1->Names);
	key=ascii%tablesize;
	cout<<"Su clave Hash es: "["<<key<<"]<<end1;
	
	if(HashTable[key]==NULL){
		HashTable[key]=n1;
		
	}else{
		for(n2=HashTable)[key];n2-next!=NULL;n2=n2->next)
		}
		
	}

	int buscar nodo (char nName[]){
			int ascii=stringtokey(nName));
		int key=ascci%tablesize;
		node *n;
		
		for (n=HasTable[key]; n!=NULL; n=n->next){
			if(strcmp(n->Names, nNames)==0){
				return key;
			}return -1;|	
		}
		}
		
	voif Imprimir Lista(node*N){
		node *n1;
		
		for(n1=n; n1!=NULL;n1=n1->next){
			cout<<"[""<<n1->	Names<<]"
		}
	}
	
	void ImprimirTabla(){
		for(int i=0; i<tablesize; i++){
			cout<<"\Tabla Hash["<<i<<"] ";
			ImprimirLista(HasTable[i];)
		}
	}
	
	void IniciarTabla()[
	for(int i=0; i<tablesize; i++){
		HashTable[i]=Null;
	}]

void menu(){
	cout<<"Busqeuqda por transformación de clave"<<end1;
	cout<<"\n\tMenu de opciones";
	cout<<"\n1. -Ingresar una cedena";
	cout<<"n2.- Buscar una cadena";
	cout<<"\n3.- Imprimir la tabla Hash";
	cout<<"?n Salir"<<end1;
}

main(){
	IniciarTabla();
	menu();
	
	int key, action=1;
	while((action==1) | (action==2)||(action==3))){
		if (action==1){
			addnode();
			
		}
		if (action==2){
			cout<<"Introduzca la cadena a buscar: "<<end1;
			cin>>nName;
			if(key==-1){
				cout<<"La cadena no se encuentra en la Tabla"<<end1;
	
			}else{
				cout<<"La cadena se encuentra en la tabla"<<end1;
				cout<<"HashTable["<<key<<"]"<<end1;
				ImprimirLista(HasTable[key]);
			}
		}
		if (action==3){
			ImprimirTabla();
		}
		cout<<"\Escoja una acción: ";
		cin>>action;
	}
	return 0;
}
