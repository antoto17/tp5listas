#include <iostream>
using namespace std;

class Nodo {
private:
    char dato;
    Nodo* sig;
public:
    Nodo(char d) {
        dato = d;
        sig = nullptr;
    }
    char getDato() {
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

    void contarMayusculasMinusculas(int& may, int& min) {
        Nodo* i = inicio;
        may = 0;
        min = 0;
        while (i != nullptr) {
            if (i->getDato() >= 'A' && i->getDato() <= 'Z') {
                may++;
            } else if (i->getDato() >= 'a' && i->getDato() <= 'z') {
                min++;
            }
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
    lista.agregarFinal(new Nodo('A'));
    lista.agregarFinal(new Nodo('b'));
    lista.agregarFinal(new Nodo('C'));
    lista.agregarFinal(new Nodo('d'));
    lista.mostrar();
    int may, min;
    lista.contarMayusculasMinusculas(may, min);
    cout << "Mayusculas: " << may << endl;
    cout << "Minusculas: " << min << endl;
    return 0;
}
