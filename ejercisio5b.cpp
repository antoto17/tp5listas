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
    void setDato(int d) {
        dato = d;
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

    void ordenarSeleccion() {
        Nodo* i = inicio;
        while (i != nullptr) {
            Nodo* min = i;
            Nodo* j = i->getSiguiente();
            while (j != nullptr) {
                if (j->getDato() < min->getDato()) {
                    min = j;
                }
                j = j->getSiguiente();
            }
            int aux = i->getDato();
            i->setDato(min->getDato());
            min->setDato(aux);
            i = i->getSiguiente();
        }
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
    lista.agregarFinal(new Nodo(5));
    lista.agregarFinal(new Nodo(1));
    lista.agregarFinal(new Nodo(4));
    lista.agregarFinal(new Nodo(2));
    lista.ordenarSeleccion();
    lista.mostrar();
    return 0;
}
