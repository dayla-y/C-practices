/*
Instrucciones de uso:

1. INSERTAR: Permite al usuario ingresar un número al arreglo.
2. BUSCAR: Busca un número en el arreglo y lo muestra si se encuentra.
3. MODIFICAR: Modifica un número existente en el arreglo.
4. ELIMINAR: Elimina un número del arreglo.
5. MOSTRAR P.U: Muestra los elementos del arreglo en el orden en que se ingresaron.
6. MOSTRAR U.P: Muestra los elementos del arreglo en orden inverso.
7. ORDENAR ARREGLO: Permite al usuario elegir entre ordenar el arreglo por el método de burbuja o inserción.
8. SALIR: Finaliza el programa.

Funcionamiento:

- Al iniciar, el programa muestra un menú con las opciones disponibles.
- El usuario puede seleccionar una opción ingresando el número correspondiente.
- Las opciones de insertar, buscar, modificar y eliminar actúan sobre el arreglo actual.
- Las opciones de mostrar muestran los elementos del arreglo sin alterar su orden.
- La opción de ordenar permite al usuario elegir un método de ordenamiento y muestra el arreglo original seguido del arreglo ordenado.

Posibles problemas:

- Si se intenta buscar, modificar o eliminar en un arreglo vacío, se mostrará "Lista vacía".
- Si se intenta modificar o eliminar un elemento que no existe en el arreglo, se mostrará "El elemento no está en la lista".
- Si se ingresa una opción inválida en el menú, se mostrará "Opción no válida".
*/


#include<iostream>
using namespace std;

struct nodo{
    int dato;
    nodo* siguiente;
    nodo* atras;
}*primero, *ultimo;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void mostrarListaPU();
void mostrarListaUP();
void menu();
void ordenamientoBurbuja();
void ordenamientoInsercion();

int arr[100]; // Arreglo global para almacenar los elementos ingresados por el usuario
int size = 0; // Tamaño actual del arreglo

int main()
{
    system("color 1f");
    int op;
    do{
        menu();
        cin>>op;
        switch(op){
            case 1:
                cout<<"\n\n INSERTAR DATO EN LA LISTA \n\n";
                insertarNodo();
                break;
            case 2:
                cout<<"\n\n BUSCAR DATO EN LA LISTA \n\n";
                buscarNodo();
                break;
            case 3:
                cout<<"\n\n MODIFICAR DATO EN LA LISTA \n\n";
                modificarNodo();
                break;
            case 4:
                cout<<"\n\n ELIMINAR DATO EN LA LISTA \n\n";
                eliminarNodo();
                break;
            case 5:
                cout<<"\n\n MOSTRAR DATOS DE LA LISTA P.U \n\n";
                mostrarListaPU();
                break;
            case 6:
                cout<<"\n\n MOSTRAR DATOS DE LA LISTA U.P \n\n";
                mostrarListaUP();
                break;
            case 7:
                cout<<"\n\n ORDENAR ARREGLO \n\n";
                cout<<"1. Burbuja\n";
                cout<<"2. Insercion\n";
                int metodo;
                cin>>metodo;
                switch(metodo){
                    case 1:
                        ordenamientoBurbuja();
                        cout<<"\nArreglo ordenado por Burbuja:\n";
                        mostrarListaPU();
                        break;
                    case 2:
                        ordenamientoInsercion();
                        cout<<"\nArreglo ordenado por Insercion:\n";
                        mostrarListaPU();
                        break;
                    default:
                        cout<<"Opcion no valida";
                }
                cout<<"\n\n";
                break;
            case 8 :
                cout<<"\n\n SALIR DEL PROGRAMA .... \n\n";
                break;
            default:
                cout<<"Opcion no valida...";
        }
        cout<<endl<<endl;
        system("pause");  system("cls");
    }while(op!=8);
    return 0;
}

void insertarNodo(){
    cout<<"Ingrese el dato: ";
    cin>>arr[size];
    size++;
    cout<<"\nElemento ingresado\n\n";
}

void buscarNodo(){
    int nodoBuscado = 0;
    bool encontrado = false;

    if(size > 0){
        cout<<"Ingrese el dato a buscar: ";
        cin>>nodoBuscado;
        for(int i = 0; i < size; i++){
            if(arr[i] == nodoBuscado){
                cout<<"\n El elemento "<<nodoBuscado<<" Encontrado...!!\n";
                cout<<"Elemento encontrado: "<<nodoBuscado<<"\n\n";
                encontrado=true;
                break;
            }
        }
        if(!encontrado){
            cout<<"El elemento "<<nodoBuscado<<" no esta en la Lista\n";
        }
    }else{
        cout<<"Lista vacia";
    }
}


void modificarNodo(){
    int nodoBuscado = 0;
    bool encontrado = false;

    if(size > 0){
        cout<<"Ingrese el dato a modificar: ";
        cin>>nodoBuscado;
        for(int i = 0; i < size; i++){
            if(arr[i] == nodoBuscado){
                cout<<"\n El elemento "<<nodoBuscado<<" Encontrado...!!\n";
                cout<<"\n Ingrese el nuevo dato: ";
                cin>>arr[i];
                cout<<"Elemento modificado\n\n";
                encontrado=true;
                break;
            }
        }
        if(!encontrado){
            cout<<"El elemento no esta en la Lista";
        }
    }else{
        cout<<"Lista vacia";
    }
}

void eliminarNodo(){
    int nodoBuscado = 0;
    bool encontrado = false;

    if(size > 0){
        cout<<"Ingrese el dato a eliminar: ";
        cin>>nodoBuscado;
        for(int i = 0; i < size; i++){
            if(arr[i] == nodoBuscado){
                for(int j = i; j < size - 1; j++){
                    arr[j] = arr[j+1];
                }
                size--;
                cout<<"\nElemento eliminado\n\n";
                encontrado=true;
                break;
            }
        }
        if(!encontrado){
            cout<<"El elemento no esta en la Lista";
        }
    }else{
        cout<<"Lista vacia";
    }
}

void mostrarListaPU(){
    if(size > 0){
        cout<<"Elementos del arreglo:\n";
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
    }else{
        cout<<"Lista vacia";
    }
}

void mostrarListaUP(){
    if(size > 0){
        cout<<"Elementos del arreglo al reves:\n";
        for(int i = size-1; i >= 0; i--){
            cout<<arr[i]<<" ";
        }
    }else{
        cout<<"Lista vacia";
    }
}

void menu(){
    cout<<" \t|-------------------------------------------|\n";
    cout<<" \t|     IMPLEMENTACION DE UNA LISTA           |\n";
    cout<<" \t|-------------------------------------------|\n";
    cout<<" \t|                                           |\n";
    cout<<" \t|  1. INSERTAR                              |\n";
    cout<<" \t|  2. BUSCAR                                |\n";
    cout<<" \t|  3. MODIFICAR                             |\n";
    cout<<" \t|  4. ELIMINAR                              |\n";
    cout<<" \t|  5. MOSTRAR  P.U                          |\n";
    cout<<" \t|  6. MOSTRAR  U.P                          |\n";
    cout<<" \t|  7. ORDENAR ARREGLO                       |\n";
    cout<<" \t|  8. SALIR                                 |\n";
    cout<<" \t|                                           |\n";
    cout<<" \t|-------------------------------------------|\n";
    cout<<"\n\t Ingrese opcion: ";
}

void ordenamientoBurbuja(){
    cout << "Arreglo original:\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Arreglo ordenado por Burbuja:\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ordenamientoInsercion(){
    cout << "Arreglo original:\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int i, key, j;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "Arreglo ordenado por Insercion:\n";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


