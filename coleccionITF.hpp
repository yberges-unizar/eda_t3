#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP

#include <string>
#include "fecha.hpp"

using namespace std;



template<typename ITF> struct coleccionITF;

// Zona de decalracion de las operaciones de la colección de ITF

// Crea una coleccion vacia, es decir sin elementos
template<typename ITF> coleccionITF<ITF> crear(coleccionITF<ITF>& c);


/*Si en c no hay ningún item con identificador igual al de i,
 devuelve una colección igual a la resultante de anyadir el item i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> anyadir(coleccionITF<ITF>& c, const ITF& i);


/*Si en c no hay ningún item con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el item que tenia identificador igual al de i, por el item i.
*/
template<typename ITF> coleccionITF<ITF> actualizar(coleccionITF<ITF>& c, const ITF& i);
     


/*Si en c hay algún item con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el item de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> borrar(coleccionITF<ITF>& c, const ITF& ident);


/* Devuelve verdad si y sólo si en c hay algún item con identificador igual a ident
 Parcial: operación no definida si en c no hay ningún item con identificador igual a ident
*/
template<typename ITF> bool esta(const coleccionITF<ITF>& c, const string& ident);


/* Si en c hay algún item con identificador igual a ident, devuelve dicho item.
   Parcial: operación no definida si en c no hay ningún item con identificador igual a ident. Devuelve error TRUE.
            En ese caso no modifica el item pasado por referencia.
*/
template<typename ITF> void obtenerITF(const coleccionITF<ITF>& c, const string& ident, ITF& itf, bool& error);


/* Devuelve la cadena resultante de concatenar los identificadores de todos los items que hay en c
 con fecha estrictamente anterior a f, y separados entre si por la cadena separador
*/
template<typename ITF> string obsoletos(coleccionITF<ITF>& c, const string& separador, const Fecha& f);


/* Devuelve una colección igual a la resultante de eliminar de c
 todos los items con fecha estrictamente anterior a f
*/
template<typename ITF> void purgar(coleccionITF<ITF>& c, const Fecha& f);


/* Devuelve verdad si y sólo si en c hay algún item i con tema igual a t
*/
template<typename ITF> bool existeTema(coleccionITF<ITF>& c, const string& t);


/* Devuelve la cadena resultante de concatenar los identificadores de todos los items que hay en c
   con tema igual a t, y separados entre si por la cadena separador
*/
template<typename ITF> string delTema(coleccionITF<ITF>& c, const string& t, const string& separador);


/* Devuelve una colección igual a la resultante de eliminar de c todos los items i cuyo tema es igual a t
*/
template<typename ITF> coleccionITF<ITF> zanjarTema(coleccionITF<ITF>& c, const string& t);


/* Devuelve verdad si y sólo si c no contiene ningún item
*/
template<typename ITF> bool esVacia(const coleccionITF<ITF>& c);


/* Devuelve el número de items que hay en la colección c
*/
template<typename ITF> int tamanyo(const coleccionITF<ITF>& c);


/* Inicializa el iterador para recorrer los items de la colección c, de forma que el siguiente item 
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún item).
*/
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c);


/* Devuelve verdad si queda algún item por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último item
*/
template<typename ITF> bool existeSiguiente(coleccionITF<ITF>& c);


/* Devuelve el siguiente item a visitar con el iterador de la colección c.
     Parcial: la operación no está definida si no quedan items por visitar (no existeSiguiente?(c))
*/
template<typename ITF> ITF siguiente(coleccionITF<ITF>& c); 


/* Prepara el iterador de la colección c para que se pueda visitar el siguiente item,
 entendiendo por siguiente aquel item con (lexicográficamente) menor identificador de los todavia no visitados.
      Parcial: la operación no está definida si no quedan items por visitar (no existeSiguiente?(c))
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c);



//ColeccionITF es una coleccion de n ITF ORDENADOS por su identificador, y sin repetidos.
//Estan unidos entre si mediante punteros.
template<typename ITF> struct coleccionITF {
friend coleccionITF<ITF> crear<ITF>(coleccionITF<ITF>& c);
friend coleccionITF<ITF> anyadir<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend coleccionITF<ITF> actualizar<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend coleccionITF<ITF> borrar<ITF>(coleccionITF<ITF>& c, const ITF& ident);
friend bool esta<ITF>(const coleccionITF<ITF>& c, const string& ident);
friend void obtenerITF<ITF>(const coleccionITF<ITF>& c, const string& ident, ITF& itf, bool& error);
friend string obsoletos<ITF>(coleccionITF<ITF>& c, const string& separador, const Fecha& f);
friend void purgar<ITF>(coleccionITF<ITF>& c, const Fecha& f);
friend bool existeTema<ITF>(coleccionITF<ITF>& c, const string& t);
friend string delTema<ITF>(coleccionITF<ITF>& c, const string& t, const string& separador);
friend coleccionITF<ITF> zanjarTema<ITF>(coleccionITF<ITF>& c, const string& t);
friend bool esVacia<ITF>(const coleccionITF<ITF>& c);
friend int tamanyo<ITF>(const coleccionITF<ITF>& c);
friend void iniciarIterador<ITF>(coleccionITF<ITF>& c);
friend bool existeSiguiente<ITF>(coleccionITF<ITF>& c);
friend ITF siguiente<ITF>(coleccionITF<ITF>& c); //Siguiente y avanza nos han dicho que se pueden combinar
friend void avanza<ITF>(coleccionITF<ITF>& c);
private:
     struct unITF{
          ITF dato;
          unITF* siguiente;
     };
     
     int cardinal;
     unITF* inicial;

     // Parametros iterador

     unITF* iter_ptr;

};

// Crea una coleccion vacia, es decir sin ITF O(1)
template<typename ITF> coleccionITF<ITF> crear(coleccionITF<ITF>& c){
     c.cardinal = 0;
     c.inicial = nullptr;
}

// Zona de implementación de las operaciones de la colección de ITF

/*Si en c no hay ningún item con identificador igual al de i,
 devuelve una colección igual a la resultante de anyadir el item i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> anyadir(coleccionITF<ITF>& c, const ITF& i){
     if(!esta(c, identificador(i->dato))){ 
          if(esVacia(c)){
               c.inicial = new typename coleccionITF<ITF>::unITF; //creamos un ITF
               c.inicial->dato = i; //escribimos los datos 
               c.inicial->siguiente = nullptr; //ponemos el puntero a null
               
               return c;

          }else{
               if(c.cardinal == 1 || identificador(i->dato) < c.inicial){ //En caso de que solo exista un elemento y sea mayor que i
                    typename coleccionITF<ITF>::unITF* aux = c.inicial;
                    c.inicial = new typename coleccionITF<ITF>::unITF*; //creamos un ITF
                    c.inicial->dato = i; //escribimos los datos 
                    c.inicial->siguiente = aux; //ponemos el puntero a null

                    c.cardinal++;
                    
               }else{ //Si no es menor, i sera mayor, podemos seguir hasta encontrar un id mayor o el final
                    
                    typename coleccionITF<ITF>::unITF* iter = c.inicial;
                    while(iter->siguiente != nullptr || identificador(iter->dato) < identificador(i->dato)){
                         iter = iter->siguiente;

                    }
                    //Si llegamos a este punto es que o se ha acabado la lista, o estamos en el hueco

                    typename coleccionITF<ITF>::unITF* nuevo;
                    typename coleccionITF<ITF>::unITF* aux = iter;
                    iter->siguiente = nuevo;
                    nuevo->siguiente = aux->siguiente; 

                    nuevo->dato = i;
                    c.cardinal++;
               }

               return c;
          }

     }else{
          return c; //Devolveremos la estructura original al no haber tenido exito
     }
}


/*Si en c no hay ningún item con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el item que tenia identificador igual al de i, por el item i.
*/
template<typename ITF> coleccionITF<ITF> actualizar(coleccionITF<ITF>& c, const ITF& i){
    typename coleccionITF<ITF>::unITF* actual = c.inicial;
    while (actual != nullptr && identificador(actual->dato) != identificador(i)) {
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        actual->dato = i;
    }

    return c;
}


/*Si en c hay algún item con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el item de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> borrar(coleccionITF<ITF>& c, const ITF& ident){}


/* Devuelve verdad si y sólo si en c hay algún item con identificador igual a ident
*/
template<typename ITF> bool esta(const coleccionITF<ITF>& c, const string& ident) {
     typename coleccionITF<ITF>::unITF* aux_ptr;

     aux_ptr = c.inicial;
     while (aux_ptr != nullptr) {
          if (identificador(aux_ptr->dato) == ident) {
               return true;
          }
          aux_ptr = aux_ptr->siguiente;
     }
     return false;
}


/* Si en c hay algún item con identificador igual a ident, devuelve dicho item.
   Parcial: operación no definida si en c no hay ningún item con identificador igual a ident. Devuelve error TRUE.
            En ese caso no modifica el item pasado por referencia.
*/
template<typename ITF> void obtenerITF(const coleccionITF<ITF>& c, const string& ident, ITF& itf, bool& error) {
     typename coleccionITF<ITF>::unITF* aux_ptr;

     aux_ptr = c.inicial;

     while (aux_ptr != nullptr) {
          if (identificador(aux_ptr->dato) == ident) {
               itf = aux_ptr->dato;
               error = false;
               return;
          }
          aux_ptr = aux_ptr->siguiente;
     }
     error = true;
}


/* Devuelve la cadena resultante de concatenar los identificadores de todos los items que hay en c
 con fecha estrictamente anterior a f, y separados entre si por la cadena separador
*/
template<typename ITF> string obsoletos(coleccionITF<ITF>& c, const string& separador, const Fecha& f) {
     typename coleccionITF<ITF>::unITF* aux_ptr;
     bool primero = true;
     string resultado;

     aux_ptr = c.inicial;

     while (aux_ptr != nullptr) {
          if (anterior(fecha(aux_ptr->dato), f)) {
               if (primero) {
                    resultado += identificador(aux_ptr->dato);
                    primero = false;
               } else {
                    resultado += separador + identificador(aux_ptr->dato);
               }

          }
          aux_ptr = aux_ptr->siguiente;
     }
     return resultado;
}


/* Devuelve una colección igual a la resultante de eliminar de c
 todos los items con fecha estrictamente anterior a f
*/
template<typename ITF> void purgar(coleccionITF<ITF>& c, const Fecha& f){
     typename coleccionITF<ITF>::unITF* actual = c.inicial;
     typename coleccionITF<ITF>::unITF* previo = nullptr;

     while (actual != nullptr) {
          if (anterior(fecha(actual->dato), f)) {
               typename coleccionITF<ITF>::unITF* eliminado = actual;
               actual = actual->siguiente;

               if (previo == nullptr) {
                    c.inicial = actual;
               } else {
                    previo->siguiente = actual;
               }

               delete eliminado;
               --c.cardinal;
          } else {
               previo = actual;
               actual = actual->siguiente;
          }
     }
}


/* Devuelve verdad si y sólo si en c hay algún item i con tema igual a t
*/
template<typename ITF> bool existeTema(coleccionITF<ITF>& c, const std::string& t){
    typename coleccionITF<ITF>::unITF* actual = c.inicial;
    while (actual != nullptr) {
        if (tema(actual->dato) == t) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

/* Devuelve la cadena resultante de concatenar los identificadores de todos los items que hay en c
   con tema igual a t, y separados entre si por la cadena separador
*/
template<typename ITF> std::string delTema(coleccionITF<ITF>& c, const std::string& t, const std::string& separador){
     std::string resultado;
     typename coleccionITF<ITF>::unITF* actual = c.inicial;
     bool primero = true;

     while (actual != nullptr) {
          if (tema(actual->dato) == t) {
               if (!primero) {
                    resultado += separador;
               }
               resultado += identificador(actual->dato);
               primero = false;
          }
          actual = actual->siguiente;
     }

     return resultado;
}


/* Devuelve una colección igual a la resultante de eliminar de c todos los items i cuyo tema es igual a t
*/
template<typename ITF> coleccionITF<ITF> zanjarTema(coleccionITF<ITF>& c, const string& t){
     if(!esVacia(c)){
          typename coleccionITF<ITF>::unITF* aux = c.inicial;
          if(tema(aux->dato) == t){
               c.inicial = c.inicial->siguiente;
               c.cardinal--;
          }

          while(aux->siguiente != nullptr){ //hasta que no alcancemos el final de la coleccion no pararemos
               if(tema(aux->dato) == t){
                    typename coleccionITF<ITF>::unITF* borrador = aux; 
                    aux = aux->siguiente;
                    c.cardinal--;

               }else{
                    aux= aux->siguiente;
               }
          }

          return c;
     }else{
          return c; //la coleccion estaba vacia
     }
}



/* Devuelve verdad si y sólo si c no contiene ningún item
     O(1)
*/
template<typename ITF> bool esVacia(const coleccionITF<ITF>& c){
     return c.cardinal == 0; 
}


/* Devuelve el número de items que hay en la colección c 
     O(n)
*/ 
template<typename ITF> int tamanyo(const coleccionITF<ITF>& c){
     return c.cardinal; 
}


/* Inicializa el iterador para recorrer los items de la colección c, de forma que el sigutamanyoiente item
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún item).
*/
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c){
     c.iter_ptr = c.inicial;
}


/* Devuelve verdad si queda algún item por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último item
*/
template<typename ITF> bool existeSiguiente(coleccionITF<ITF>& c) {
     return c.iter_ptr != nullptr;
}


/* Devuelve el siguiente item a visitar con el iterador de la colección c.
     Parcial: la operación no está definida si no quedan items por visitar (no existeSiguiente?(c))
*/
template<typename ITF> ITF siguiente(coleccionITF<ITF>& c) {
     return c.iter_ptr->dato;
}


/* Prepara el iterador de la colección c para que se pueda visitar el siguiente item,
 entendiendo por siguiente aquel item con (lexicográficamente) menor identificador de los todavia no visitados.
      Parcial: la operación no está definida si no quedan items por visitar (no existeSiguiente?(c))
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c) {
     c.iter_ptr = c.iter_ptr->siguiente;
}

#endif