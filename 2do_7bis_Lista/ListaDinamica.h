#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#include <iostream>

template <class T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
};

template <class T>
class ILista {
public:
    virtual void insertar(T valor) = 0;
    virtual void eliminar() = 0;
    virtual void mostrar() const = 0;
    virtual ~ILista() {}
};

template <class T>
class ListaDinamica : public ILista<T> {
private:
    Nodo<T>* cabeza;

    void insertarNodo(Nodo<T>*& cab, T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>();
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = nullptr;

        if (cab == nullptr) {
            cab = nuevoNodo;
        } else {
            Nodo<T>* aux = cab;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevoNodo;
        }
    }

    void eliminarNodo(Nodo<T>*& cab) {
        if (cab != nullptr) {
            Nodo<T>* aux = cab;
            cab = cab->siguiente;
            delete aux;
        }
    }

public:
    ListaDinamica() {
        cabeza = nullptr;
    }
    
    ~ListaDinamica() {
        while (cabeza != nullptr) {
            eliminarNodo(cabeza);
        }
    }

    void insertar(T valor) override {
        insertarNodo(cabeza, valor);
        std::cout << "[Exito] Elemento " << valor << " insertado en la lista.\n";
    }

    void eliminar() override {
        if (cabeza == nullptr) {
            std::cout << "[Error] La lista esta vacia, no hay elementos para eliminar.\n";
        } else {
            std::cout << "[Exito] Elemento " << cabeza->dato << " eliminado de la lista.\n";
            eliminarNodo(cabeza);
        }
    }

    void mostrar() const override {
        if (cabeza == nullptr) {
            std::cout << "Lista vacia.\n";
            return;
        }
        
        Nodo<T>* aux = cabeza;
        std::cout << "Contenido de la Lista: ";
        while (aux != nullptr) {
            std::cout << "[" << aux->dato << "] -> ";
            aux = aux->siguiente;
        }
        std::cout << "NULL\n";
    }

    std::string snapshot() const {
        if (cabeza == nullptr) return "Lista vacia";
        std::string s = "";
        Nodo<T>* aux = cabeza;
        while (aux != nullptr) {
            s += "[" + std::to_string(aux->dato) + "] -> ";
            aux = aux->siguiente;
        }
        s += "NULL";
        return s;
    }
};

#endif
