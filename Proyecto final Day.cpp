#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Heladero{
    string nombre;
    int edad;
    string turno;
} heladeros[100]; // Aumentado el tamaño del array para permitir más heladeros

struct nodo{
    string nro;
    struct nodo *sgte;
    struct nodo *Puntero;
};
typedef struct nodo *Puntero;

class Cola{
public:
    Cola(void);
    void Encolar(string );
    string Desencolar(void );
    bool ColaVacia(void);
    void MostrarCola(void);
    void VaciarCola(void);

private:
    Puntero delante;
    Puntero atras;

};

Cola::Cola(void){
    delante=NULL;
    atras=NULL;
}

bool Cola::ColaVacia(){
    return delante == NULL;
}

void Cola::Encolar(string nombre ){

    Puntero p_aux;

    p_aux=new(struct nodo);
    p_aux->nro=nombre;
    p_aux->sgte=NULL;

    if(delante==NULL)
        delante=p_aux;
    else atras->sgte=p_aux;

    atras=p_aux;
}

string Cola::Desencolar(void){
    string n;
    Puntero p_aux;

    p_aux=delante;
    n=p_aux->nro;
    delante=(delante)->sgte;
    delete(p_aux);
    return n;
}

void Cola::MostrarCola(void){
    Puntero p_aux = delante;
    while(p_aux != NULL){
        cout << "\n\n\t" << p_aux->nro;
        p_aux = p_aux->sgte;
    }
}

void Cola::VaciarCola(void){
    Puntero p_aux, r_aux;
    p_aux = delante;
    while(p_aux != NULL){
        r_aux = p_aux;
        p_aux = p_aux->sgte;
        delete(r_aux);
    }
    delante = NULL;
    atras = NULL;
}

typedef struct Producto{
    char nombre[25];
    int codigo;
    float precio;
}Producto;

int pedirCantidad();
Producto Agregar_productos();
void mostrarProductos(Producto *productos, int numProductos);
void mostrarProducto(Producto *productos, int posicion);
int Busqueda(Producto *productos, int codigo, int contador);
void comprarProducto(Producto *productos);
void ordenarProductos(Producto productos[], int cont);
void ordenarProductosS(Producto productos[], int cont);
int q=0;
int A[100];
void mostrarOrden(int [100], int);
void ordenarBurbuja(Heladero heladeros[], int n);
void ordenarInsercion(Heladero heladeros[], int n);
void ordenarSeleccion(Heladero heladeros[], int n);
void quickSort(Heladero heladeros[], int izquierda, int derecha);
int particion(Heladero heladeros[], int izquierda, int derecha);
int arr[100];
int size = 0;
void mostrarHeladeros(Heladero heladeros[], int n);
void busquedaSecuencial(Heladero heladeros[], int n);
void busquedaBinaria(Heladero heladeros[], int n);
void busquedaHashing(Heladero heladeros[], int n);

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

Nodo *crearNodo(int,Nodo *);
void insertarNodoA(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
Nodo *arbol=NULL;
int dato;

// Contador global para el número total de heladeros ingresados
int totalHeladeros = 0;

int main(){
    int op;
    string aux1;
    int cant = 0;
    int numProductos,x=0,cont=0;
    numProductos=pedirCantidad();
    Producto productos[numProductos];
    int contador=0;
    do{
        cout << "\n===============================\n";
        cout << "         MENU PRINCIPAL        \n";
        cout << "===============================\n";
        cout << "1. Ingresar Heladeros\n";
        cout << "2. Buscar Heladero\n";
        cout << "3. Gestionar Clientes\n";
        cout << "4. Ingresar Productos\n";
        cout << "5. Mostrar Productos\n";
        cout << "6. Comprar Productos\n";
        cout << "7. Ordenar Productos (Precio)\n";
        cout << "8. Ordenar Productos (Codigo)\n";
        cout << "9. Ordenar Heladeros (Edad)\n";
        cout << "10. Mostrar Arbol de Ventas\n";
        cout << "11. Salir\n";
        cout << "===============================\n";
        cout << "Seleccione una opcion: ";
        cin >> op;
        switch(op){
            case 1:
                {
                    cout << "Cuantos heladeros desea ingresar: ";
                    cin >> cant;
                    for (int i = totalHeladeros; i < totalHeladeros + cant; i++) {
                        cout << "Ingresa el nombre: ";
                        cin >> heladeros[i].nombre;
                        cout << "Ingresa la edad: ";
                        cin >> heladeros[i].edad;
                        cout << "Ingresa turno: ";
                        cin >> heladeros[i].turno;
                    }
                    totalHeladeros += cant; // Actualizar el contador global
                break;
                }

            case 2:
                {
                    int metodoBusqueda;
                    cout << "\n\n BUSCAR HELADERO \n\n";
                    cout << "1. Secuencial\n";
                    cout << "2. Binaria\n";
                    cout << "Seleccione metodo de busqueda: ";
                    cin >> metodoBusqueda;
                    switch(metodoBusqueda){
                        case 1:
                            busquedaSecuencial(heladeros, totalHeladeros);
                            break;
                        case 2:
                            busquedaBinaria(heladeros, totalHeladeros);
                            break;
                        default:
                            cout << "Opcion no valida\n";
                            break;
                    }
                break;
                }

            case 3:
                {
                    int o;
                    Cola cola;
                    string nombre;
                    do{
                        cout << "\nOpciones de Clientes\n";
                        cout << "1. Encolar\n";
                        cout << "2. Desencolar\n";
                        cout << "3. Mostrar Cola\n";
                        cout << "4. Salir\n";
                        cout << "Seleccione una opcion: ";
                        cin >> o;
                        switch(o){
                            case 1: 
                                cout << "Ingrese el nombre del cliente: "; 
                                cin >> nombre;
                                cola.Encolar(nombre);
                                cout << "Cliente: " << nombre << " en espera\n";
                                break;
                            case 2:
                                if(cola.ColaVacia() == true)
                                    cout << "Cola Vacia\n";
                                else{
                                    nombre = cola.Desencolar();
                                    cout << "Cliente: " << nombre << " desencolado\n";
                                }
                                break;
                            case 3:
                                cout << "MOSTRANDO COLA\n";
                                if(cola.ColaVacia() != true)
                                    cola.MostrarCola();
                                else
                                    cout << "Cola vacia!\n";
                                break;
                        }
                    } while(o != 4);
                }
                break;
            case 4:
                {
                    if(cont == numProductos)
                        cout << "No es posible agregar más productos\n";
                    else{
                        productos[cont] = Agregar_productos();
                        cont++;
                    }
                }
                break;
            case 5: 
                mostrarProductos(productos, cont);
                break;
            case 6:
                comprarProducto(productos);
                break;
            case 7:
                ordenarProductos(productos, cont);
                mostrarProductos(productos, cont);
                break;
            case 8:
                ordenarProductosS(productos, cont);
                mostrarProductos(productos, cont);
                break;
            case 9:
                {
                    int opcionOrdenamiento;
                    bool salir = false;

                    while (!salir) {
                        cout << "Seleccione el método de ordenamiento para los heladeros:\n";
                        cout << "1. Ordenamiento por burbuja\n";
                        cout << "2. Ordenamiento por inserción\n";
                        cout << "3. Ordenamiento por selección\n";
                        cout << "4. Ordenamiento por quicksort\n";
                        cout << "5. Mostrar heladeros ordenados\n";
                        cout << "6. Salir\n";
                        cout << "Seleccione una opción: ";
                        cin >> opcionOrdenamiento;

                        switch (opcionOrdenamiento) {
                            case 1:
                                ordenarBurbuja(heladeros, totalHeladeros);
                                break;
                            case 2:
                                ordenarInsercion(heladeros, totalHeladeros);
                                break;
                            case 3:
                                ordenarSeleccion(heladeros, totalHeladeros);
                                break;
                            case 4:
                                quickSort(heladeros, 0, totalHeladeros - 1);
                                break;
                            case 5:
                                mostrarHeladeros(heladeros, totalHeladeros);
                                break;
                            case 6:
                                salir = true;
                                break;
                            default:
                                cout << "Opción no válida. Intente de nuevo.\n";
                                break;
                        }
                    }
                }
                break;
            case 10:
                mostrarArbol(arbol,0);
                break;
            case 11:
                exit(0);
            default:
                cout << "Opcion no valida\n";
                break;
        }
    } while(op != 11);

    return 0;
}

int pedirCantidad(){
    int cantidad;
    cout << "Ingrese la cantidad de productos que desea ingresar: ";
    cin >> cantidad;
    return cantidad;
}

Producto Agregar_productos(){
    Producto helado;
    cout << "Nombre del helado: ";
    cin >> helado.nombre;
    cout << "Precio: ";
    cin >> helado.precio;
    cout << "Codigo: ";
    cin >> helado.codigo;
    return helado;
}

void mostrarProductos(Producto *productos, int numProductos){
    for(int i = 0; i < numProductos; i++){
        cout << "\nNombre: " << productos[i].nombre;
        cout << "\nPrecio: " << productos[i].precio;
        cout << "\nCodigo: " << productos[i].codigo;
        cout << "\n";
    }
}

void mostrarProducto(Producto *productos, int posicion){
    cout << "\nNombre: " << productos[posicion].nombre;
    cout << "\nPrecio: " << productos[posicion].precio;
    cout << "\nCodigo: " << productos[posicion].codigo;
    cout << "\n";
}


int Busqueda(Producto *productos, int codigo, int contador){
    for(int i = 0; i < contador; i++){
        if(productos[i].codigo == codigo){
            return i;
        }
    }
    return -1;
}

Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo; 
}

void insertarNodoA(Nodo *&arbol, int n, Nodo *padre){
    if(arbol == NULL){
        Nodo *nuevo_nodo = crearNodo(n, padre);
        arbol = nuevo_nodo;
    }
    else{
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarNodoA(arbol->izq, n, arbol);
        }
        else{
            insertarNodoA(arbol->der, n, arbol);
        }
    }
}

void comprarProducto(Producto *productos){
    int comprar, total = 0, op;
    do{
        int buscado, codigo, cantidad;
        cout << "Digite el codigo para encontrar el helado: ";
        cin >> codigo;
        buscado = Busqueda(productos, codigo, cantidad);
        mostrarProducto(productos, buscado);
        cout << "Cantidad de productos a adquirir: ";
        cin >> comprar;
        total = total + productos[buscado].precio * comprar;
        cout << "Digite 0 si desea seguir comprando y 1 si quiere finalizar compra: ";
        cin >> op;
    } while(op != 1);
    if(op == 1){
        cout << "Total a pagar: " << total << "\n";
        A[q] = total;
        q++;
        dato = total;
        insertarNodoA(arbol, dato, NULL);
    }
}

void ordenarProductos(Producto productos[], int cont){
    for(int i = 0; i < cont - 1; i++){
        for(int j = 0; j < cont - i - 1; j++){
            if(productos[j].precio > productos[j + 1].precio){
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

void ordenarProductosS(Producto productos[], int cont){
    for(int i = 0; i < cont - 1; i++){
        for(int j = 0; j < cont - i - 1; j++){
            if(productos[j].codigo > productos[j + 1].codigo){
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

void mostrarOrden(int A[100], int n){
    for(int i = 0; i < n; i++)
        cout << " " << A[i] << endl;
}


void ordenarBurbuja(Heladero heladeros[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(heladeros[j].edad > heladeros[j + 1].edad){
                Heladero temp = heladeros[j];
                heladeros[j] = heladeros[j + 1];
                heladeros[j + 1] = temp;
            }
        }
    }
}

void ordenarInsercion(Heladero heladeros[], int n){
    for(int i = 1; i < n; i++){
        Heladero temp = heladeros[i];
        int j = i - 1;
        while(j >= 0 && heladeros[j].edad > temp.edad){
            heladeros[j + 1] = heladeros[j];
            j--;
        }
        heladeros[j + 1] = temp;
    }
}

void ordenarSeleccion(Heladero heladeros[], int n){
    for(int i = 0; i < n - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(heladeros[j].edad < heladeros[min_idx].edad){
                min_idx = j;
            }
        }
        Heladero temp = heladeros[min_idx];
        heladeros[min_idx] = heladeros[i];
        heladeros[i] = temp;
    }
}

void quickSort(Heladero heladeros[], int izquierda, int derecha){
    if(izquierda < derecha){
        int indice = particion(heladeros, izquierda, derecha);
        quickSort(heladeros, izquierda, indice - 1);
        quickSort(heladeros, indice + 1, derecha);
    }
}

int particion(Heladero heladeros[], int izquierda, int derecha){
    int pivote = heladeros[derecha].edad;
    int i = (izquierda - 1);
    for(int j = izquierda; j <= derecha - 1; j++){
        if(heladeros[j].edad <= pivote){
            i++;
            Heladero temp = heladeros[i];
            heladeros[i] = heladeros[j];
            heladeros[j] = temp;
        }
    }
    Heladero temp = heladeros[i + 1];
    heladeros[i + 1] = heladeros[derecha];
    heladeros[derecha] = temp;
    return (i + 1);
}

void mostrarHeladeros(Heladero heladeros[], int n){
    for(int i = 0; i < n; i++){
        cout << "Nombre: " << heladeros[i].nombre << "\n";
        cout << "Edad: " << heladeros[i].edad << "\n";
        cout << "Turno: " << heladeros[i].turno << "\n";
    }
}

void busquedaSecuencial(Heladero heladeros[], int n){
    string nombreBuscado;
    cout << "Ingrese el nombre del heladero a buscar: ";
    cin >> nombreBuscado;
    bool encontrado = false;
    for(int i = 0; i < n; i++){
        if(heladeros[i].nombre == nombreBuscado){
            cout << "Heladero encontrado:\n";
            cout << "Nombre: " << heladeros[i].nombre << "\n";
            cout << "Edad: " << heladeros[i].edad << "\n";
            cout << "Turno: " << heladeros[i].turno << "\n";
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout << "Heladero no encontrado.\n";
    }
}

void busquedaBinaria(Heladero heladeros[], int n){
    ordenarInsercion(heladeros, n);
    string nombreBuscado;
    cout << "Ingrese el nombre del heladero a buscar: ";
    cin >> nombreBuscado;
    int izquierda = 0;
    int derecha = n - 1;
    bool encontrado = false;
    while(izquierda <= derecha){
        int medio = izquierda + (derecha - izquierda) / 2;
        if(heladeros[medio].nombre == nombreBuscado){
            cout << "Heladero encontrado:\n";
            cout << "Nombre: " << heladeros[medio].nombre << "\n";
            cout << "Edad: " << heladeros[medio].edad << "\n";
            cout << "Turno: " << heladeros[medio].turno << "\n";
            encontrado = true;
            break;
        }
        if(heladeros[medio].nombre < nombreBuscado)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    if(!encontrado){
        cout << "Heladero no encontrado.\n";
    }
}

void mostrarArbol(Nodo *arbol, int cont){
    if(arbol == NULL){
        return;
    }
    else{
        mostrarArbol(arbol->der, cont + 1);
        for(int i = 0; i < cont; i++){
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}

