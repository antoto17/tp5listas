#include <iostream>
using namespace std;

class Nodo {
private:
    int dato;
    Nodo* sig;
public:
    Nodo(int d) {
        dato = d;
        sig = nullptr;
    }
    int getDato() {
        return dato;
    }
    Nodo* getSiguiente() {
        return sig;
    }
    void setSiguiente(Nodo* s) {
        sig = s;
    }
};

class Cola {
private:
    Nodo* inicio;
    Nodo* fin;
    int contador;
public:
    Cola() {
        inicio = nullptr;
        fin = nullptr;
        contador = 0;
    }

    void encolar(Nodo* nuevo) {
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        contador++;
    }

    Nodo* desencolar() {
        if (inicio == nullptr) return nullptr;
        Nodo* borrado = inicio;
        inicio = inicio->getSiguiente();
        if (inicio == nullptr) fin = nullptr;
        borrado->setSiguiente(nullptr);
        contador--;
        return borrado;
    }

    int cantidad() {
        return contador;
    }

    void mostrar() {
        Nodo* i = inicio;
        while (i != nullptr) {
            cout << i->getDato() << endl;
            i = i->getSiguiente();
        }
    }
};

int main() {
    Cola cola;
    cola.encolar(new Nodo(1));
    cola.encolar(new Nodo(2));
    cola.encolar(new Nodo(3));
    cola.mostrar();
    cout << "Cantidad: " << cola.cantidad() << endl;
    Nodo* extraido = cola.desencolar();
    cout << "Desencolado: " << extraido->getDato() << endl;
    cola.mostrar();
    return 0;
}
