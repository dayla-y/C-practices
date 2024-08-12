#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	char cadena[30];
	cout<<"Inserte una frase: ";
	cin.getline(cadena, 30);
	int i;
	while(cadena[i]!='\0'){
		cout<<cadena[i];
		i++
	}
getch();
return 0;
	
}
