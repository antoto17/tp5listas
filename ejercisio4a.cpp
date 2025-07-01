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

class Pila {
private:
    Nodo* tope;
public:
    Pila() {
        tope = nullptr;
    }

    void push(Nodo* nuevo) {
        nuevo->setSiguiente(tope);
        tope = nuevo;
    }

    Nodo* pop() {
        if (tope == nullptr) return nullptr;
        Nodo* borrado = tope;
        tope = tope->getSiguiente();
        borrado->setSiguiente(nullptr);
        return borrado;
    }

    void mostrar() {
        Nodo* i = tope;
        while (i != nullptr) {
            cout << i->getDato() << endl;
            i = i->getSiguiente();
        }
    }
};

int main() {
    Pila pila;
    pila.push(new Nodo(10));
    pila.push(new Nodo(20));
    pila.push(new Nodo(30));
    pila.mostrar();
    Nodo* extraido = pila.pop();
    cout << "Extraido: " << extraido->getDato() << endl;
    pila.mostrar();
    return 0;
}
