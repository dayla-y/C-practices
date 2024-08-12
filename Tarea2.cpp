#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void mostrarPila(stack<int> pila) {
    cout << "Contenido de la pila:" << endl;
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
}

void mostrarCola(queue<int> cola) {
    cout << "Contenido de la cola:" << endl;
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
}

int main() {
    stack<int> pila;
    queue<int> cola;

    int opcion, numero;

    do {
        cout << "1. Insertar número" << endl;
        cout << "2. Encolar/Apilar" << endl;
        cout << "3. Desencolar/Desapilar" << endl;
        cout << "4. Mostrar contenido" << endl;
        cout << "5. Vaciar estructura" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un número: ";
                cin >> numero;
                break;
            case 2:
                int opcion2;
                cout << "1. Encolar" << endl;
                cout << "2. Apilar" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcion2;
                if (opcion2 == 1)
                    cola.push(numero);
                else if (opcion2 == 2)
                    pila.push(numero);
                else
                    cout << "Opción no válida." << endl;
                break;
            case 3:
                int opcion3;
                cout << "1. Desencolar" << endl;
                cout << "2. Desapilar" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcion3;
                if (opcion3 == 1 && !cola.empty())
                    cola.pop();
                else if (opcion3 == 2 && !pila.empty())
                    pila.pop();
                else
                    cout << "La estructura está vacía." << endl;
                break;
            case 4:
                int opcion4;
                cout << "1. Mostrar pila" << endl;
                cout << "2. Mostrar cola" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcion4;
                if (opcion4 == 1)
                    mostrarPila(pila);
                else if (opcion4 == 2)
                    mostrarCola(cola);
                else
                    cout << "Opción no válida." << endl;
                break;
            case 5:
                pila = stack<int>();
                cola = queue<int>();
                cout << "Estructura vaciada." << endl;
                break;
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}

