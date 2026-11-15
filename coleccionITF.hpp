#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP

#include <string>
#include "fecha.hpp"

using namespace std;



template<typename ITF> struct coleccionITF;

// Zona de decalracion de las operaciones de la colección de ITF

// Crea una coleccion vacia, es decir sin elementos
template<typename ITF> coleccionITF<ITF> crear(coleccionITF<ITF>& c);


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a la resultante de añadir el ítem i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> añadir(coleccionITF<ITF>& c, const ITF& i);


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el ítem que tenía identificador igual al de i, por el ítem i.
*/
template<typename ITF> coleccionITF<ITF> actualizar(coleccionITF<ITF>& c, const ITF& i);
     


/*Si en c hay algún ítem con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el ítem de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> borrar(coleccionITF<ITF>& c, const ITF& ident);


/* Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident
*/
template<typename ITF> bool esta(coleccionITF<ITF>& c, const std::string& ident);


/* Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
     Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident
*/
template<typename ITF> ITF obtenerITF(coleccionITF<ITF>& c, const std::string& ident);


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena separador
*/
template<typename ITF> std::string obsoletos(coleccionITF<ITF>& c, const std::string& separador, const Fecha& f);


/* Devuelve una colección igual a la resultante de eliminar de c
 todos los ítems con fecha estrictamente anterior a f
*/
template<typename ITF> void purgar(coleccionITF<ITF>& c, const Fecha& f);


/* Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t
*/
template<typename ITF> bool existeTema(coleccionITF<ITF>& c, const std::string& t);


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
   con tema igual a t, y separados entre sí por la cadena separador
*/
template<typename ITF> std::string delTema(coleccionITF<ITF>& c, const std::string& t, const std::string& separador);


/* Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t
*/
template<typename ITF> void zanjarTema(coleccionITF<ITF>& c, const std::string& t);


/* Devuelve verdad si y sólo si c no contiene ningún ítem
*/
template<typename ITF> bool esVacía(const coleccionITF<ITF>& c);


/* Devuelve el número de ítems que hay en la colección c
*/
template<typename ITF> int tamaño(const coleccionITF<ITF>& c);


/* Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente ítem 
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún ítem).
*/
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c);


/* Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último ítem
*/
template<typename ITF> bool existeSiguiente(coleccionITF<ITF>& c);


/* Devuelve el siguiente ítem a visitar con el iterador de la colección c.
     Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ITF> ITF siguiente(coleccionITF<ITF>& c); 


/* Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem,
 entendiendo por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no visitados.
      Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c);



//ColeccionITF es una coleccion de n ITF ORDENADOS por su identificador, y sin repetidos.
//Estan unidos entre si mediante punteros.
template<typename ITF> struct coleccionITF {
friend coleccionITF<ITF> crear<ITF>(coleccionITF<ITF>& c);
friend coleccionITF<ITF> añadir<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend coleccionITF<ITF> actualizar<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend coleccionITF<ITF> borrar<ITF>(coleccionITF<ITF>& c, const ITF& ident);
friend bool esta<ITF>(coleccionITF<ITF>& c, const std::string& ident);
friend ITF obtenerITF<ITF>(coleccionITF<ITF>& c, const std::string& ident);
friend std::string obsoletos<ITF>(coleccionITF<ITF>& c, const std::string& separador, const Fecha& f);
friend void purgar<ITF>(coleccionITF<ITF>& c, const Fecha& f);
friend bool existeTema<ITF>(coleccionITF<ITF>& c, const std::string& t);
friend std::string delTema<ITF>(coleccionITF<ITF>& c, const std::string& t, const std::string& separador);
friend void zanjarTema<ITF>(coleccionITF<ITF>& c, const std::string& t);
friend bool esVacía<ITF>(const coleccionITF<ITF>& c);
friend int tamaño<ITF>(const coleccionITF<ITF>& c);
friend void iniciarIterador<ITF>(coleccionITF<ITF>& c);
friend bool existeSiguiente<ITF>(coleccionITF<ITF>& c);
friend ITF siguiente<ITF>(coleccionITF<ITF>& c); //Siguiente y avanza nos han dicho que se pueden combinar
friend void avanza<ITF>(coleccionITF<ITF>& c);
private:

     //estos seran los datos del diccionario 
     struct unITF{
          ITF dato; //El dato de la colección
          unITF* siguiente; //Puntero al siguiente elemento de la lista, o nullptr si es el último          
     };
     
     int cardinal; //Número de elementos de la colección
     unITF* inicial; //Puntero al primer elemento de la lista

     /* El tipo ITF debera tener estas operaciones:
     identificador(ITF i) = std::string id;     
     tema(ITF i) = std::string titulo; 
     fecha(ITF i) = Fecha fecha;
     */
 
};

// Crea una coleccion vacia, es decir sin ITF O(1)
template<typename ITF> coleccionITF<ITF> crear(coleccionITF<ITF>& c){
     c.cardinal = 0;
     c.inicial = nullptr;
}

// Zona de implementación de las operaciones de la colección de ITF

/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a la resultante de añadir el ítem i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> añadir(coleccionITF<ITF>& c, const ITF& i){
     if(!esta(c, identificador(i))){ 
          if(esVacía(c)){
               c.inicial = new typename coleccionITF<ITF>::unITF; //creamos un ITF
               c.inicial->dato = i; //escribimos los datos 
               c.inicial->siguiente = nullptr; //ponemos el puntero a null
               
               return c;

          }else{
               if(cardinal == 1 || identificador(i) < c.inicial){ //En caso de que solo exista un elemento y sea mayor que i
                    typename coleccion<ITF>::unITF aux = c.inicial;
                    c.inicial = new typename coleccionITF<ITF>::unITF; //creamos un ITF
                    c.inicial->dato = i; //escribimos los datos 
                    c.inicial->siguiente = aux; //ponemos el puntero a null

                    c.cardinal++;
                    
               }else{ //Si no es menor, i sera mayor, podemos seguir hasta encontrar un id mayor o el final
                    
                    typename coleccion<ITF>::unITF iter = c.inicial;
                    while(iter->siguiente != nullptr || identificador(iter->siguiente->dato) < identificador(i)){
                         iter = iter->siguiente;

                    }
                    //Si llegamos a este punto es que o se ha acabado la lista, o estamos en el hueco

                    typename coleccion<ITF>::unITF nuevo;
                    typename coleccion<ITF>::unITF aux = iter;
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


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el ítem que tenía identificador igual al de i, por el ítem i.
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


/*Si en c hay algún ítem con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el ítem de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> coleccionITF<ITF> borrar(coleccionITF<ITF>& c, const ITF& ident){}


/* Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident
*/
template<typename ITF> bool esta(coleccionITF<ITF>& c, const std::string& ident){}


/* Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
     Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident
*/
template<typename ITF> ITF obtenerITF(coleccionITF<ITF>& c, const std::string& ident){} 


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena separador
*/
template<typename ITF> std::string obsoletos(coleccionITF<ITF>& c, const std::string& separador, const Fecha& f){}


/* Devuelve una colección igual a la resultante de eliminar de c
 todos los ítems con fecha estrictamente anterior a f
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


/* Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t
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

/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
   con tema igual a t, y separados entre sí por la cadena separador
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


/* Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t
*/
template<typename ITF> void zanjarTema(coleccionITF<ITF>& c, const std::string& t){
     if(!esVacía(c)){
          new typename coleccionITF<ITF>::unITF aux = c.inicial; 
          if(tema(aux->dato) == t){
               c.inicial = c.inicial->siguiente
               delete aux;   //Borramos donde apuntaba originalemnte el puntero inicial
               cardinal--;
          }

          while(aux->siguiente != nullptr){ //hasta que no alcancemos el final de la coleccion no pararemos
               if(tema(axu->dato) == t){
                    new typename coleccionITF<ITF>::unITF borrador = aux; 
                    aux = aux->siguiente;
                    delete borrador; //Borramos donde apuntaba el puntero original
                    cardinal--;

               }else{
                    aux= aux->siguiente;
               }
          }

          return c;
     }else{
          return c; //la coleccion estaba vacia
     }
}



/* Devuelve verdad si y sólo si c no contiene ningún ítem
     O(1)
*/
template<typename ITF> bool esVacía(const coleccionITF<ITF>& c){
     return c.cardinal == 0; 
}


/* Devuelve el número de ítems que hay en la colección c 
     O(n)
*/ 
template<typename ITF> int tamaño(const coleccionITF<ITF>& c){
     return cardinal; 
}


/* Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente ítem 
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún ítem).
*/
template<typename ITF> void iniciarIterador(coleccionITF<ITF>& c){}


/* Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último ítem
*/
template<typename ITF> bool existeSiguiente(coleccionITF<ITF>& c){}


/* Devuelve el siguiente ítem a visitar con el iterador de la colección c.
     Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ITF> ITF siguiente(coleccionITF<ITF>& c){}


/* Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem,
 entendiendo por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no visitados.
      Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c){}

#endif