#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
    pnodo ant;
};

typedef struct tlista{
    pnodo inicio;
    pnodo fin;
};

void IniciarLista(tlista &lista){
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void MostrarLista(tlista lista){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        cout << aux->dato;
        aux = aux->sig;
    }
    cout << endl;
}

void DecimalABinario(tlista &lista, int numero){
    while(numero > 0){
        pnodo nuevo;
        CrearNodo(nuevo, numero % 2);
        AgregarInicio(lista, nuevo);
        numero = numero / 2;
    }
}

int main(){
    tlista lista;
    IniciarLista(lista);

    int numero = 25;
    DecimalABinario(lista, numero);
    MostrarLista(lista);

    return 0;
}
