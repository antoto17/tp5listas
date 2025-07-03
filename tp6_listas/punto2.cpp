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

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void QuitarInicio(tlista &lista){
    pnodo borrado;
    if(lista.inicio != NULL){
        borrado = lista.inicio;
        if(lista.inicio == lista.fin){
            lista.inicio = NULL;
            lista.fin = NULL;
        }else{
            lista.inicio = lista.inicio->sig;
            lista.inicio->ant = NULL;
        }
        delete borrado;
    }
}

void QuitarFinal(tlista &lista){
    pnodo borrado;
    if(lista.fin != NULL){
        borrado = lista.fin;
        if(lista.inicio == lista.fin){
            lista.inicio = NULL;
            lista.fin = NULL;
        }else{
            lista.fin = lista.fin->ant;
            lista.fin->sig = NULL;
        }
        delete borrado;
    }
}

int main(){
    tlista lista;
    IniciarLista(lista);

    pnodo n1; CrearNodo(n1, 10); AgregarInicio(lista, n1);
    pnodo n2; CrearNodo(n2, 20); AgregarFinal(lista, n2);
    pnodo n3; CrearNodo(n3, 5); AgregarInicio(lista, n3);

    QuitarInicio(lista);
    QuitarFinal(lista);

    return 0;
}