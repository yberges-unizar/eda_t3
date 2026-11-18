/*
* Fichero: coleccionITF.hpp
 * Descripción: interfaz y representación del TAD genérico coleccionITF.
 * Autores:
 *   Yaret Berges Calero, NIP 838561
 *   Diego Masip Sisa, NIP 959248 
 *   Sergio Iso Blasco, NIP 927177
 */

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
     


/* borrar: cadena ident, colecciónITF c -> colecciónITF
 Si en c hay algún ítem con identificador igual a ident, devuelve una colección igual a la
 resultante de borrar ese ítem de la colección c. En caso contrario, devuelve una colección igual a c.
 (Implementación: c se modifica directamente y se libera la memoria del ítem borrado.)
*/
template<typename ITF> void borrar(const string& ident, coleccionITF<ITF>& c);


/* está?: cadena ident, colecciónITF c -> booleano
 Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename ITF> bool esta(const string& ident, const coleccionITF<ITF>& c);


/* parcial obtenerITF: cadena ident, colecciónITF c -> ITF
 Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident.
 (Implementación: el ítem se devuelve en itf y error toma el valor falso. Si la operación no está
 definida, error toma el valor verdad e itf no se modifica.)
*/
template<typename ITF> void obtenerITF(const string& ident, const coleccionITF<ITF>& c, ITF& itf, bool& error);


/* obsoletos: fecha f, cadena separador, colecciónITF c -> cadena
 Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
*/
template<typename ITF> string obsoletos(const Fecha& f, const string& separador, const coleccionITF<ITF>& c);


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


/* iniciarIterador: colecciónITF c -> colecciónITF
 Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente ítem
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún ítem).
 (Implementación: c se modifica directamente.)
*/
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c);


/* existeSiguiente?: colecciónITF c -> booleano
 Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último ítem.
*/
template<typename ITF> bool existeSiguiente(const coleccionITF<ITF>& c);


/* parcial siguiente: colecciónITF c -> ITF
 Devuelve el siguiente ítem a visitar con el iterador de la colección c.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
*/
template<typename ITF> ITF siguiente(const coleccionITF<ITF>& c);


/* parcial avanza: colecciónITF c -> colecciónITF
 Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem, entendiendo por
 siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no visitados.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
 (Implementación: c se modifica directamente.)
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c);



//ColeccionITF es una coleccion de n ITF ORDENADOS por su identificador, y sin repetidos.
//Estan unidos entre si mediante punteros.
template<typename ITF> struct coleccionITF {
friend coleccionITF<ITF> crear<ITF>(coleccionITF<ITF>& c);
friend coleccionITF<ITF> anyadir<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend coleccionITF<ITF> actualizar<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend void borrar<ITF>(const string& ident, coleccionITF<ITF>& c);
friend bool esta<ITF>(const string& ident, const coleccionITF<ITF>& c);
friend void obtenerITF<ITF>(const string& ident, const coleccionITF<ITF>& c, ITF& itf, bool& error);
friend string obsoletos<ITF>(const Fecha& f, const string& separador, const coleccionITF<ITF>& c);
friend void purgar<ITF>(coleccionITF<ITF>& c, const Fecha& f);
friend bool existeTema<ITF>(coleccionITF<ITF>& c, const string& t);
friend string delTema<ITF>(coleccionITF<ITF>& c, const string& t, const string& separador);
friend coleccionITF<ITF> zanjarTema<ITF>(coleccionITF<ITF>& c, const string& t);
friend bool esVacia<ITF>(const coleccionITF<ITF>& c);
friend int tamanyo<ITF>(const coleccionITF<ITF>& c);
friend void iniciarIterador<ITF>(coleccionITF<ITF>& c);
friend bool existeSiguiente<ITF>(const coleccionITF<ITF>& c);
friend ITF siguiente<ITF>(const coleccionITF<ITF>& c);
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
     c.iter_ptr = nullptr;
     return c;
}

// Zona de implementación de las operaciones de la colección de ITF

/*Si en c no hay ningún item con identificador igual al de i,
 devuelve una colección igual a la resultante de anyadir el item i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> anyadir(coleccionITF<ITF>& c, const ITF& i){
     if(!esta(identificador(i), c)){ 
          if(esVacia(c)){
               c.inicial = new typename coleccionITF<ITF>::unITF; //creamos un ITF
               c.inicial->dato = i; //escribimos los datos 
               c.inicial->siguiente = nullptr; //ponemos el puntero a null
               
               c.cardinal++;
               return c;

          }else{
               if(identificador(i) < identificador(c.inicial->dato)){ //Coloca el nuevo elemento en la primera posicion
                    typename coleccionITF<ITF>::unITF* aux = c.inicial;
                    c.inicial = new typename coleccionITF<ITF>::unITF;
                    c.inicial->dato = i;
                    c.inicial->siguiente = aux;
                    c.cardinal++;

               }else{
                    typename coleccionITF<ITF>::unITF* iter = c.inicial;
                    while(iter->siguiente != nullptr && identificador(iter->siguiente->dato) < identificador(i)){
                         iter = iter->siguiente; //Avanzamos por la coleccion
                    }

                    typename coleccionITF<ITF>::unITF* nuevo = new typename coleccionITF<ITF>::unITF;
                    nuevo->dato = i;
                    nuevo->siguiente = iter->siguiente;
                    iter->siguiente = nuevo;
                    c.cardinal++;
               }
          }
          return c; //Devolveremos la estructura tras haber anyadido el elemento en su posicion correspondiente
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


/* borrar: cadena ident, colecciónITF c -> colecciónITF
 Si en c hay algún ítem con identificador igual a ident, devuelve una colección igual a la
 resultante de borrar ese ítem de la colección c. En caso contrario, devuelve una colección igual a c.
 (Implementación: c se modifica directamente y se libera la memoria del ítem borrado.)
*/
template<typename ITF> void borrar(const string& ident, coleccionITF<ITF>& c) {
     typename coleccionITF<ITF>::unITF* aux_ptr;
     typename coleccionITF<ITF>::unITF* prev_aux_ptr;

     prev_aux_ptr = nullptr;
     aux_ptr = c.inicial;

     while (aux_ptr != nullptr) {
          if (identificador(aux_ptr->dato) > ident) {
               return;
          }
          if (identificador(aux_ptr->dato) == ident) {
               if (prev_aux_ptr == nullptr) {
                    c.inicial = aux_ptr->siguiente;
               } else {
                    prev_aux_ptr->siguiente = aux_ptr->siguiente;
               }

               delete aux_ptr;
               --c.cardinal;
               return;
          }

          prev_aux_ptr = aux_ptr;
          aux_ptr = aux_ptr->siguiente;
     }
}


/* está?: cadena ident, colecciónITF c -> booleano
 Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident.
*/
template<typename ITF> bool esta(const string& ident, const coleccionITF<ITF>& c) {
     typename coleccionITF<ITF>::unITF* aux_ptr;

     aux_ptr = c.inicial;
     while (aux_ptr != nullptr) {
          if (identificador(aux_ptr->dato) > ident) {
               return false;
          }

          if (identificador(aux_ptr->dato) == ident) {
               return true;
          }
          aux_ptr = aux_ptr->siguiente;
     }
     return false;
}


/* parcial obtenerITF: cadena ident, colecciónITF c -> ITF
 Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident.
 (Implementación: el ítem se devuelve en itf y error toma el valor falso. Si la operación no está
 definida, error toma el valor verdad e itf no se modifica.)
*/
template<typename ITF> void obtenerITF(const string& ident, const coleccionITF<ITF>& c, ITF& itf, bool& error) {
     typename coleccionITF<ITF>::unITF* aux_ptr;

     aux_ptr = c.inicial;

     while (aux_ptr != nullptr) {
          if (identificador(aux_ptr->dato) > ident) {
               error = true;
               return;
          }
          if (identificador(aux_ptr->dato) == ident) {
               itf = aux_ptr->dato;
               error = false;
               return;
          }
          aux_ptr = aux_ptr->siguiente;
     }
     error = true;
}


/* obsoletos: fecha f, cadena separador, colecciónITF c -> cadena
 Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena separador.
*/
template<typename ITF> string obsoletos(const Fecha& f, const string& separador, const coleccionITF<ITF>& c) {
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
     typename coleccionITF<ITF>::unITF* actual = c.inicial;
     typename coleccionITF<ITF>::unITF* previo = nullptr;

     while(actual != nullptr){ //Minetras que no nos encontremos apuntando a nada
          if (tema(actual->dato) == t){
               typename coleccionITF<ITF>::unITF* eliminado = actual;
               actual = actual->siguiente; //Avanzaremos una posicion, pues vamos a eliminar el elemento en el que estabamos

               if(previo == nullptr) { //Si el elemento anterior era el primero deberemos actualizarlo
                    c.inicial = actual;
               } else {
                    previo->siguiente = actual; //Ajustamos el puntero para saltar el hueco
               }

               delete eliminado;
               c.cardinal--;

          }else{ //Avanzaremos por la coleccion
               previo = actual;
               actual = actual->siguiente;
          }
     }
     return c; //Devolvemos la coleccion actualizada
}



/* Devuelve verdad si y sólo si c no contiene ningún item
     O(1)
*/
template<typename ITF> bool esVacia(const coleccionITF<ITF>& c){
     return c.cardinal == 0; 
}


/* Devuelve el número de items que hay en la colección c 
     O(1)
*/ 
template<typename ITF> int tamanyo(const coleccionITF<ITF>& c){
     return c.cardinal; 
}


/* iniciarIterador: colecciónITF c -> colecciónITF
 Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente ítem
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún ítem).
 (Implementación: c se modifica directamente.)
*/
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c){
     c.iter_ptr = c.inicial;
}


/* existeSiguiente?: colecciónITF c -> booleano
 Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último ítem.
*/
template<typename ITF> bool existeSiguiente(const coleccionITF<ITF>& c) {
     return c.iter_ptr != nullptr;
}


/* parcial siguiente: colecciónITF c -> ITF
 Devuelve el siguiente ítem a visitar con el iterador de la colección c.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
*/
template<typename ITF> ITF siguiente(const coleccionITF<ITF>& c) {
     return c.iter_ptr->dato;
}


/* parcial avanza: colecciónITF c -> colecciónITF
 Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem, entendiendo por
 siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no visitados.
 Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c)).
 (Implementación: c se modifica directamente.)
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c) {
     c.iter_ptr = c.iter_ptr->siguiente;
}

#endif