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

void MostrarMayorMenor(tlista lista){
    if(lista.inicio != NULL){
        int mayor = lista.inicio->dato;
        int menor = lista.inicio->dato;
        pnodo aux = lista.inicio->sig;
        while(aux != NULL){
            if(aux->dato > mayor) mayor = aux->dato;
            if(aux->dato < menor) menor = aux->dato;
            aux = aux->sig;
        }
        cout << "Mayor: " << mayor << endl;
        cout << "Menor: " << menor << endl;
    }
}

int main(){
    tlista lista;
    IniciarLista(lista);

    pnodo n1; CrearNodo(n1, 10); AgregarFinal(lista, n1);
    pnodo n2; CrearNodo(n2, 25); AgregarFinal(lista, n2);
    pnodo n3; CrearNodo(n3, 7); AgregarFinal(lista, n3);
    pnodo n4; CrearNodo(n4, 18); AgregarFinal(lista, n4);

    MostrarMayorMenor(lista);

    return 0;
}
