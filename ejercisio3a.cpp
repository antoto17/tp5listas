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

    int buscarIndice(int valor) {
        Nodo* i = inicio;
        int pos = 0;
        while (i != nullptr) {
            if (i->getDato() == valor) {
                return pos;
            }
            i = i->getSiguiente();
            pos++;
        }
        return -1;
    }
};

int main() {
    Lista lista;
    lista.agregarFinal(new Nodo(10));
    lista.agregarFinal(new Nodo(20));
    lista.agregarFinal(new Nodo(30));
    cout << "Indice de 20: " << lista.buscarIndice(20) << endl;
    cout << "Indice de 50: " << lista.buscarIndice(50) << endl;
    return 0;
}
