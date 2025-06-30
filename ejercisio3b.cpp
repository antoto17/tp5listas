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

    Nodo* buscarPorIndice(int pos) {
        Nodo* i = inicio;
        int actual = 0;
        while (i != nullptr) {
            if (actual == pos)
                return i;
            i = i->getSiguiente();
            actual++;
        }
        return nullptr;
    }
};

int main() {
    Lista lista;
    lista.agregarFinal(new Nodo(100));
    lista.agregarFinal(new Nodo(200));
    lista.agregarFinal(new Nodo(300));
    Nodo* encontrado = lista.buscarPorIndice(1);
    if (encontrado != nullptr)
        cout << "Dato en índice 1: " << encontrado->getDato() << endl;
    else
        cout << "No encontrado" << endl;
    return 0;
}
