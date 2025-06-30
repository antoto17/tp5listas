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
    Nodo* fin;
    int contador;
public:
    Lista() {
        inicio = nullptr;
        fin = nullptr;
        contador = 0;
    }

    void agregarFinal(Nodo* nuevo) {
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        contador++;
    }

    void eliminarInicio() {
        if (inicio != nullptr) {
            Nodo* borrar = inicio;
            inicio = inicio->getSiguiente();
            borrar->setSiguiente(nullptr);
            delete borrar;
            contador--;
            if (inicio == nullptr)
                fin = nullptr;
        }
    }

    int cantidad() {
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
    lista.agregarFinal(new Nodo(1));
    lista.agregarFinal(new Nodo(2));
    lista.agregarFinal(new Nodo(3));
    lista.mostrar();
    lista.eliminarInicio();
    lista.mostrar();
    cout << "Cantidad: " << lista.cantidad() << endl;
    return 0;
}
