#include <iostream>

using namespace std;


struct estructuraNodo{
    int valor;
    struct estructuraNodo *siguiente;
};

typedef struct estructuraNodo *nodo;


void insertar(int valorInsertar,nodo &lista){
    if(lista == NULL){
        nodo nuevo = new (struct estructuraNodo);
        nuevo->valor = valorInsertar;
        nuevo->siguiente = NULL;
        lista = nuevo;
    }else{
        insertar(valorInsertar,lista->siguiente);
    }
}

void listarElementos(nodo lista){
    if(lista!=NULL){
        cout<<lista->valor<<", ";
        listarElementos(lista->siguiente);
    }
}

bool buscarRecursividad(int datoBuscar, nodo lista){
    if(lista!=NULL){
        if(lista->valor == datoBuscar){
            return true;
        }else{
            return buscarRecursividad(datoBuscar,lista->siguiente);
        }
    }
    return false;
}

bool buscarIterativo(int datoBuscar, nodo lista){
    bool existe = false;
    nodo i = lista;
    while( (i!=NULL) && (existe == false) ){
        if(i->valor == datoBuscar){
            existe = true;
        }

        i = i->siguiente;
    }
    return existe;
}

void eliminar(int datoEliminar, nodo &lista){
    nodo i = lista;
    nodo previo = NULL;

    while(i!=NULL){

        if(i->valor == datoEliminar){
            //1. es el primer elemento de la lista 
            if(previo ==NULL){
                lista = lista->siguiente;
            }else{
                previo->siguiente = i->siguiente;
            }
        }else{
            previo = i;
        }

        i = i->siguiente;
    }
}

int main(){

    cout<<"lista enlazada"<<endl;
    nodo lista = NULL;
    insertar(35,lista);
    insertar(15,lista);
    insertar(80,lista);
    insertar(10,lista);
    insertar(20,lista);
    insertar(18,lista);
    insertar(17,lista);

    eliminar(20,lista);
    listarElementos(lista);

    if(buscarIterativo(100,lista)){
        cout<<"dato encontrado"<<endl;
    }else{
        cout<<"dato NO encontrado"<<endl;
    }


    cout<<endl;	
    cout<<endl;
    cout<<"****  ****  ****** ******   **   *     *   **   *     * *****  ******      ****** ****** *     *"<<endl;
    cout<<"*   * *   * *    * *       *  *  **   **  *  *  **    * *    * *    *      *      *    * **    *"<<endl;
    cout<<"*   * *   * *    * *      *    * * * * * *    * * *   * *    * *    *      *      *    * * *   *"<<endl;
    cout<<"****  ****  *    * *  *** ****** *  *  * ****** *  *  * *    * *    *      *      *    * *  *  *"<<endl;
    cout<<"*     * *   *    * *    * *    * *     * *    * *   * * *    * *    *      *      *    * *   * *"<<endl;
    cout<<"*     *  *  *    * *    * *    * *     * *    * *    ** *    * *    *      *      *    * *    **"<<endl;
    cout<<"*     *   * ****** ****** *    * *     * *    * *     * *****  ******      ****** ****** *     *"<<endl;
    cout<<endl;
    cout<<"****    **   ****  *     ****** "<<endl;
    cout<<"*   *  *  *  *   * *     *    * "<<endl; 
    cout<<"*   * *    * *   * *     *    * "<<endl;
    cout<<"****  ****** ****  *     *    * "<<endl;
    cout<<"*     *    * *   * *     *    * "<<endl;
    cout<<"*     *    * *   * *     *    * "<<endl;
    cout<<"*     *    * ****  ***** ****** "<<endl;
        
}