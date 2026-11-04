#include <string>
#include "fecha.hpp"

using namespace std;



template<typename ITF> struct coleccionITF;

// Zona de decalracion de las operaciones de la colección de ITF

// Crea una coleccion vacia, es decir sin ITF
template<typename ITF> void crear(coleccionITF<ITF>& c);


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a la resultante de añadir el ítem i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> void añadir(coleccionITF<ITF>& c, const ITF& i);


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el ítem que tenía identificador igual al de i, por el ítem i.
*/
template<typename ITF> void actualizar(coleccionITF<ITF>& c, const ITF& i);


/*Si en c hay algún ítem con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el ítem de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> void borrar(coleccionITF<ITF>& c, const ITF& ident);


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



template <typename ITF>
//ColeccionITF es una coleccion de n ITF ORDENADOS por su identificador, y sin repetidos.
//Estan unidos entre si mediante punteros.
struct coleccionITF {
friend void crear<ITF>(coleccionITF<ITF>& c);
friend void añadir<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend void actualizar<ITF>(coleccionITF<ITF>& c, const ITF& i);
friend void borrar<ITF>(coleccionITF<ITF>& c, const ITF& ident);
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
     struct ITF{
          std::string id;     //Esta implementacion de TAD esta mal.
          std::string titulo; //creo que esto esta mal, lo pienso revisar e eliminar este comentario
          Fecha fecha;
     };
 
};

// Crea una coleccion vacia, es decir sin ITF O(1)
template<typename ITF> void crear(coleccionITF<ITF>& c){
     coleccionITF coleccion;
}

// Zona de implementación de las operaciones de la colección de ITF

/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a la resultante de añadir el ítem i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> void añadir(coleccionITF<ITF>& c, const ITF& i){

}


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el ítem que tenía identificador igual al de i, por el ítem i.
*/
template<typename ITF> void actualizar(coleccionITF<ITF>& c, const ITF& i){}


/*Si en c hay algún ítem con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el ítem de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ITF> void borrar(coleccionITF<ITF>& c, const ITF& ident){}


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
template<typename ITF> void purgar(coleccionITF<ITF>& c, const Fecha& f){}


/* Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t
*/
template<typename ITF> bool existeTema(coleccionITF<ITF>& c, const std::string& t){}


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
   con tema igual a t, y separados entre sí por la cadena separador
*/
template<typename ITF> std::string delTema(coleccionITF<ITF>& c, const std::string& t, const std::string& separador){}


/* Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t
*/
template<typename ITF> void zanjarTema(coleccionITF<ITF>& c, const std::string& t){}



/* Devuelve verdad si y sólo si c no contiene ningún ítem
     O(1)
*/
template<typename ITF> bool esVacía(const coleccionITF<ITF>& c){
     return c.siguiente == nullptr; //La funcion tamaño es MUCHO menos eficiente
}


/* Devuelve el número de ítems que hay en la colección c 
     O(n)
*/ 
template<typename ITF> int tamaño(const coleccionITF<ITF>& c){
     if(c.siguiente == nullptr){
          return 0;
     }else{
          return tamaño(c.siguiente) +1;
     }
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

