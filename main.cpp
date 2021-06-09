#include <iostream>
using namespace std;

class Nodo{
    private:
        int elemento;
        Nodo *siguiente;
    public:
        friend class ListaEnlazada;
};

class ListaEnlazada{
    private:
        int tamanio;
        Nodo *cabeza;

    public:
        ListaEnlazada();
        ~ListaEnlazada();
        void agregarInicio(int inicio);
        void eliminarInicio();
        void print()const ;
        void buscar(int num);
        
};

ListaEnlazada::ListaEnlazada(){ //nuestra lista esta vacia
    cabeza=nullptr;
}
void ListaEnlazada::agregarInicio(int inicio){
    Nodo *ptr = new Nodo; //asignamos memoria dinamica
    ptr->elemento=inicio; //le asignamos el elento al nuevo nodo
    ptr->siguiente=cabeza;
    cabeza=ptr;            //actualizamos el nuevo nodo
}

void ListaEnlazada::eliminarInicio(){
    Nodo *ptr= cabeza->siguiente; //guardamos el nodo siguiente de la cabeza
    delete cabeza;
    cabeza=ptr;
}
ListaEnlazada::~ListaEnlazada(){
    while(cabeza != nullptr)
        eliminarInicio();
}
void ListaEnlazada::buscar(int num){
    Nodo *ptr=cabeza;
    bool existe=false;
    while(ptr != nullptr){
        if(ptr->elemento == num){
            existe=true;
        }
        ptr=ptr->siguiente;
    }
    if(existe==true){
        cout<<"El elemento "<<num<<" SI existe ";
    }
    else
        cout<<"El elemento "<<num<<" NO existe ";
}
void ListaEnlazada::print()const {
    Nodo *ptr=cabeza;
    while(ptr != nullptr){
        cout<<ptr->elemento<<" ";
        ptr= ptr->siguiente;        //paso al siguiente nodo
    }

}
int main(){
    ListaEnlazada lista;
    lista.agregarInicio(4);
    lista.agregarInicio(7);
    lista.agregarInicio(2);
    lista.agregarInicio(8);
    lista.agregarInicio(10);
    lista.agregarInicio(13);
    lista.print();
    cout<<endl;
    lista.eliminarInicio();
    lista.print();
    cout<<endl;
    lista.buscar(9);
    return 0;
}