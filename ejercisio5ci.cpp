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

    void agregarFinal(Nodo* nuevo) {
        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            Nodo* i = inicio;
            while (i->getSiguiente() != nullptr) {
                i = i->getSiguiente();
            }
            i->setSiguiente(nuevo);
        }
    }

    Nodo* getInicio() {
        return inicio;
    }

    void mostrar() {
        Nodo* i = inicio;
        while (i != nullptr) {
            cout << i->getDato() << " ";
            i = i->getSiguiente();
        }
        cout << endl;
    }

    void combinarSinOrden(Lista otra) {
        Nodo* j = otra.getInicio();
        while (j != nullptr) {
            agregarFinal(new Nodo(j->getDato()));
            j = j->getSiguiente();
        }
    }
};

int main() {
    Lista a, b;
    a.agregarFinal(new Nodo(1));
    a.agregarFinal(new Nodo(3));
    b.agregarFinal(new Nodo(2));
    b.agregarFinal(new Nodo(4));
    a.combinarSinOrden(b);
    a.mostrar();
    return 0;
}
