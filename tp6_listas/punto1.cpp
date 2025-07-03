#include <iostream>
using namespace std;

class Nodo {
private:
    int dato;
    Nodo* sig;
    Nodo* ant;
public:
    Nodo(int valor) {
        dato = valor;
        sig = nullptr;
        ant = nullptr;
    }

    int getDato() {
        return dato;
    }

    void setDato(int valor) {
        dato = valor;
    }

    Nodo* getSiguiente() {
        return sig;
    }

    Nodo* getAnterior() {
        return ant;
    }

    void setSiguiente(Nodo* nodo) {
        sig = nodo;
    }

    void setAnterior(Nodo* nodo) {
        ant = nodo;
    }
};

class ListaDoble {
private:
    Nodo* inicio;
    Nodo* fin;
public:
    ListaDoble() {
        inicio = nullptr;
        fin = nullptr;
    }

    bool estaVacia() {
        return inicio == nullptr;
    }

    void agregarInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            nuevo->setSiguiente(inicio);
            inicio->setAnterior(nuevo);
            inicio = nuevo;
        }
    }

    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            inicio = nuevo;
            fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            nuevo->setAnterior(fin);
            fin = nuevo;
        }
    }

    void agregarOrdenado(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            inicio = nuevo;
            fin = nuevo;
        } else if (valor < inicio->getDato()) {
            agregarInicio(valor);
        } else if (valor > fin->getDato()) {
            agregarFinal(valor);
        } else {
            Nodo* actual = inicio;
            while (actual != nullptr && actual->getDato() < valor) {
                actual = actual->getSiguiente();
            }
            Nodo* anterior = actual->getAnterior();
            anterior->setSiguiente(nuevo);
            nuevo->setAnterior(anterior);
            nuevo->setSiguiente(actual);
            actual->setAnterior(nuevo);
        }
    }

    void quitarInicio() {
        if (!estaVacia()) {
            Nodo* borrado = inicio;
            if (inicio == fin) {
                inicio = nullptr;
                fin = nullptr;
            } else {
                inicio = inicio->getSiguiente();
                inicio->setAnterior(nullptr);
            }
            delete borrado;
        }
    }

    void quitarFinal() {
        if (!estaVacia()) {
            Nodo* borrado = fin;
            if (inicio == fin) {
                inicio = nullptr;
                fin = nullptr;
            } else {
                fin = fin->getAnterior();
                fin->setSiguiente(nullptr);
            }
            delete borrado;
        }
    }

    void quitarEspecifico(int valor) {
        if (!estaVacia()) {
            Nodo* actual = inicio;
            while (actual != nullptr && actual->getDato() != valor) {
                actual = actual->getSiguiente();
            }
            if (actual != nullptr) {
                if (actual == inicio) {
                    quitarInicio();
                } else if (actual == fin) {
                    quitarFinal();
                } else {
                    Nodo* anterior = actual->getAnterior();
                    Nodo* siguiente = actual->getSiguiente();
                    anterior->setSiguiente(siguiente);
                    siguiente->setAnterior(anterior);
                    delete actual;
                }
            }
        }
    }

    Nodo* buscar(int valor) {
        Nodo* actual = inicio;
        while (actual != nullptr) {
            if (actual->getDato() == valor) {
                return actual;
            }
            actual = actual->getSiguiente();
        }
        return nullptr;
    }

    void mostrarLista() {
        Nodo* actual = inicio;
        while (actual != nullptr) {
            cout << actual->getDato() << " ";
            actual = actual->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    ListaDoble lista;
    lista.agregarOrdenado(5);
    lista.agregarOrdenado(3);
    lista.agregarOrdenado(8);
    lista.agregarOrdenado(1);
    lista.mostrarLista();
    lista.quitarEspecifico(3);
    lista.mostrarLista();
    return 0;
}