#include <iostream>
using namespace std;

class Nodo {
private:
    int data;
    Nodo *link;

public:
    Nodo(int data);
    Nodo(int data, Nodo*link);
    int getData() const;
    Nodo* getLink() const;
    Nodo *siguiente = NULL;
    void setData(int dato);
    void setLink(Nodo* link);
};

Nodo::Nodo(int data) {
    this->data=data;
    this->link= 0;
}
Nodo::Nodo(int data, Nodo* link) {
    this->data=data;
    this->link= link;
}

int Nodo::getData() const {
    return this->data;
}

Nodo* Nodo::getLink() const {
    return this->link;
}

void Nodo::setData(int dato) {
    data=dato;
}


void Nodo::setLink(Nodo *link) {
    this->link=link;
}

class Lista{
private:
    Nodo* head;

public:
    Lista();
    void crearLista();
    void visualizarLista();
    void insertarAlaCabeza(int dato);
    void insertarALaCola(int dato);
};

Lista::Lista() {head= NULL;}

void Lista::crearLista() {
    int dato;
   cout << "Ingrese enteros o -1 para terminar"<<endl;
    do{
       cin>> dato;
       if (dato != -1){
           this->head=new Nodo(dato,head);
       }
    }while(dato !=-1);
}

void Lista::visualizarLista() {
    int n;
    Nodo *temp;
    if (head == nullptr) {
        cout << "La lista está vacía " << endl;
    } else {
        temp = head;
        while (temp != NULL) {
            char c;
            c = (n == 10 ? '\n' : ' ');
            n++;
            cout << temp->getData() << "|" << c;
            temp = temp->getLink();
        }
    }
}

  void Lista::insertarAlaCabeza(int dato){
    Nodo *nuevo = new Nodo(dato);
    nuevo->setLink(head);
    head= nuevo;
}

void Lista::insertarALaCola(int dato){
    Nodo *ultimo= new Nodo(dato);
    Nodo *temp ;
    while (temp->getLink() != NULL) {
        temp = temp->getLink();
    }
    temp->setLink(ultimo);
}

int main() {
    Lista lista;
    lista.crearLista();
    lista.insertarAlaCabeza(8);
    lista.insertarALaCola(9);
    lista.visualizarLista();
    return 0;
}
