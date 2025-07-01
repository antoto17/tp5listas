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

    Lista combinarOrdenado(Lista otra) {
        Lista resultado;
        Nodo* i = inicio;
        Nodo* j = otra.getInicio();
        while (i != nullptr && j != nullptr) {
            if (i->getDato() <= j->getDato()) {
                resultado.agregarFinal(new Nodo(i->getDato()));
                i = i->getSiguiente();
            } else {
                resultado.agregarFinal(new Nodo(j->getDato()));
                j = j->getSiguiente();
            }
        }
        while (i != nullptr) {
            resultado.agregarFinal(new Nodo(i->getDato()));
            i = i->getSiguiente();
        }
        while (j != nullptr) {
            resultado.agregarFinal(new Nodo(j->getDato()));
            j = j->getSiguiente();
        }
        return resultado;
    }
};

int main() {
    Lista a, b;
    a.agregarFinal(new Nodo(1));
    a.agregarFinal(new Nodo(4));
    b.agregarFinal(new Nodo(2));
    b.agregarFinal(new Nodo(3));
    Lista combinada = a.combinarOrdenado(b);
    combinada.mostrar();
    return 0;
}
