#include<iostream>
using namespace std;

int arr[100];
int size = 0;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void mostrarListaPU();
void mostrarListaUP();
void menu();
void ordenamientoBurbuja();
void ordenamientoInsercion();
void ordenamientoSeleccion();
void ordenamientoQuickSort();
void mostrarArregloOriginal();
void mostrarArregloOrdenado();

int main()
{
    system("color 1f");
    int op;
    do{
        menu();
        cin>>op;
        switch(op){
            case 1:
                cout<<"\n\n INSERTAR DATO EN EL ARREGLO \n\n";
                insertarNodo();
                break;
            case 2:
                cout<<"\n\n BUSCAR DATO EN EL ARREGLO \n\n";
                buscarNodo();
                break;
            case 3:
                cout<<"\n\n MODIFICAR DATO EN EL ARREGLO \n\n";
                modificarNodo();
                break;
            case 4:
                cout<<"\n\n ELIMINAR DATO EN EL ARREGLO \n\n";
                eliminarNodo();
                break;
            case 5:
                cout<<"\n\n MOSTRAR ARREGLO ORIGINAL \n\n";
                mostrarArregloOriginal();
                break;
            case 6:
                cout<<"\n\n MOSTRAR ARREGLO ORDENADO \n\n";
                mostrarArregloOrdenado();
                break;
            case 7:
                cout<<"\n\n ORDENAR ARREGLO \n\n";
                cout<<"1. Burbuja\n";
                cout<<"2. Insercion\n";
                cout<<"3. Seleccion\n";
                cout<<"4. QuickSort\n";
                int metodo;
                cin>>metodo;
                switch(metodo){
                    case 1:
                        ordenamientoBurbuja();
                        break;
                    case 2:
                        ordenamientoInsercion();
                        break;
                    case 3:
                        ordenamientoSeleccion();
                        break;
                    case 4:
                        ordenamientoQuickSort();
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
            cout<<"El elemento "<<nodoBuscado<<" no esta en la Lista\n";
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
            cout<<"El elemento "<<nodoBuscado<<" no esta en la Lista\n";
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
    cout<<" \t|     IMPLEMENTACION DE UN ARREGLO          |\n";
    cout<<" \t|-------------------------------------------|\n";
    cout<<" \t|                                           |\n";
    cout<<" \t|  1. INSERTAR                              |\n";
    cout<<" \t|  2. BUSCAR                                |\n";
    cout<<" \t|  3. MODIFICAR                             |\n";
    cout<<" \t|  4. ELIMINAR                              |\n";
    cout<<" \t|  5. MOSTRAR ARREGLO ORIGINAL              |\n";
    cout<<" \t|  6. MOSTRAR ARREGLO ORDENADO              |\n";
    cout<<" \t|  7. ORDENAR ARREGLO                       |\n";
    cout<<" \t|  8. SALIR                                 |\n";
    cout<<" \t|                                           |\n";
    cout<<" \t|-------------------------------------------|\n";
    cout<<"\n\t Ingrese opcion: ";
}

void ordenamientoBurbuja(){
    cout << "Arreglo original:\n";
    mostrarListaPU();

    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "\n\nArreglo ordenado por Burbuja:\n";
    mostrarListaPU();
}

void ordenamientoInsercion(){
    cout << "Arreglo original:\n";
    mostrarListaPU();

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

    cout << "\n\nArreglo ordenado por Insercion:\n";
    mostrarListaPU();
}

void ordenamientoSeleccion(){
    cout << "Arreglo original:\n";
    mostrarListaPU();

    for(int i = 0; i < size-1; i++){
        int minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "\n\nArreglo ordenado por Seleccion:\n";
    mostrarListaPU();
}

void quickSort(int low, int high){
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j)
        quickSort(low, j);
    if (i < high)
        quickSort(i, high);
}

void ordenamientoQuickSort(){
    cout << "Arreglo original:\n";
    mostrarListaPU();

    quickSort(0, size-1);

    cout << "\n\nArreglo ordenado por QuickSort:\n";
    mostrarListaPU();
}

void mostrarArregloOriginal(){
    cout << "Arreglo original:\n";
    mostrarListaPU();
}

void mostrarArregloOrdenado(){
    cout << "Arreglo ordenado:\n";
    mostrarListaPU();
}

