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

    bool esPrimo(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int contarPrimos() {
        Nodo* i = inicio;
        int contador = 0;
        while (i != nullptr) {
            if (esPrimo(i->getDato())) {
                contador++;
            }
            i = i->getSiguiente();
        }
        return contador;
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
    lista.agregarFinal(new Nodo(4));
    lista.agregarFinal(new Nodo(7));
    lista.agregarFinal(new Nodo(10));
    lista.mostrar();
    cout << "Cantidad de primos: " << lista.contarPrimos() << endl;
    return 0;
}
