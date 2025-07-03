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

void EliminarMultiplosDe3(tlista &lista){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        if(aux->dato % 3 == 0){
            pnodo borrar = aux;
            if(borrar == lista.inicio && borrar == lista.fin){
                lista.inicio = NULL;
                lista.fin = NULL;
            }else if(borrar == lista.inicio){
                lista.inicio = borrar->sig;
                lista.inicio->ant = NULL;
            }else if(borrar == lista.fin){
                lista.fin = borrar->ant;
                lista.fin->sig = NULL;
            }else{
                borrar->ant->sig = borrar->sig;
                borrar->sig->ant = borrar->ant;
            }
            aux = aux->sig;
            delete borrar;
        }else{
            aux = aux->sig;
        }
    }
}

void MostrarLista(tlista lista){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

int main(){
    tlista lista;
    IniciarLista(lista);

    pnodo n1; CrearNodo(n1, 10); AgregarFinal(lista, n1);
    pnodo n2; CrearNodo(n2, 15); AgregarFinal(lista, n2);
    pnodo n3; CrearNodo(n3, 7); AgregarFinal(lista, n3);
    pnodo n4; CrearNodo(n4, 18); AgregarFinal(lista, n4);

    EliminarMultiplosDe3(lista);
    MostrarLista(lista);

    return 0;
}
