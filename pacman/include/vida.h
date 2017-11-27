#ifndef VIDA_H
#define VIDA_H


class vida
{
    public:
        int dato;
        vida *siguiente;
        vida();

        void agregar(vida *&pila,int n){
            vida *nueva_vida=new vida();
            nueva_vida->dato=n;
            nueva_vida->siguiente=pila;
            pila=nueva_vida;}

        void secar(vida *&pila, int &n){
            vida *aux=pila;
            n=aux->dato;
            pila=aux->siguiente;
            delete aux;}
};

#endif // VIDA_H
