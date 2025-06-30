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

class Lista {
private:
    Nodo* inicio;
public:
    Lista() {
        inicio = nullptr;
    }

    void agregarInicio(Nodo* nuevo) {
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
    }

    int minimo() {
        if (inicio == nullptr) return -1;
        int min = inicio->getDato();
        Nodo* i = inicio->getSiguiente();
        while (i != nullptr) {
            if (i->getDato() < min)
                min = i->getDato();
            i = i->getSiguiente();
        }
        return min;
    }

    void mostrar() {
        Nodo* i = inicio;
        while (i != nullptr) {
            cout << i->getDato() << " ";
            i = i->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Lista lista;
    lista.agregarInicio(new Nodo(8));
    lista.agregarInicio(new Nodo(4));
    lista.agregarInicio(new Nodo(9));
    lista.mostrar();
    cout << "Minimo: " << lista.minimo() << endl;
    return 0;
}