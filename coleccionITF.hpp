#include <string>
#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP



template<typename ELEM> struct coleccionITF;


// Crea una coleccion vacia, es decir sin elementos
template<typename ELEM> void crear(coleccionITF<ELEM>& c);


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a la resultante de añadir el ítem i a la colección c.
 En caso contrario, devuelve una colección igual a c.
*/
template<typename ELEM> void añadir(coleccionITF<ELEM>& c, const ELEM& i);


/*Si en c no hay ningún ítem con identificador igual al de i,
 devuelve una colección igual a c. En caso contrario, devuelve una colección igual
 a la resultante de sustituir en c el ítem que tenía identificador igual al de i, por el ítem i.
*/
template<typename ELEM> void actualizar(coleccionITF<ELEM>& c, const ELEM& i);


/*Si en c hay algún ítem con identificador igual a ident,
 devuelve una colección igual a la resultante de borrar ese el ítem de la colección c.
  En caso contrario, devuelve una colección igual a c.
*/
template<typename ELEM> void borrar(coleccionITF<ELEM>& c, const ELEM& ident);


/* Devuelve verdad si y sólo si en c hay algún ítem con identificador igual a ident
 Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident
*/
template<typename ELEM> bool esta(coleccionITF<ELEM>& c, const std::string& ident);


/* Si en c hay algún ítem con identificador igual a ident, devuelve dicho ítem.
     Parcial: operación no definida si en c no hay ningún ítem con identificador igual a ident
*/
template<typename ELEM> void obtenerITF(coleccionITF<ELEM>& c, const std::string& ident); // falta definir el puntero


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena separador
*/
template<typename ELEM> std::string obsoletos(coleccionITF<ELEM>& c, const std::string& separador, const int& f);


/* Devuelve una colección igual a la resultante de eliminar de c
 todos los ítems con fecha estrictamente anterior a f
*/
template<typename ELEM> void purgar(coleccionITF<ELEM>& c, const int& f);


/* Devuelve verdad si y sólo si en c hay algún ítem i con tema igual a t
*/
template<typename ELEM> bool existeTema(coleccionITF<ELEM>& c, const std::string& t);


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
   con tema igual a t, y separados entre sí por la cadena separador
*/
template<typename ELEM> std::string delTema(coleccionITF<ELEM>& c, const std::string& t, const std::string& separador);


/* Devuelve una colección igual a la resultante de eliminar de c todos los ítems i cuyo tema es igual a t
*/
template<typename ELEM> void zanjarTema(coleccionITF<ELEM>& c, const std::string& t);


/* Devuelve verdad si y sólo si c no contiene ningún ítem
*/
template<typename ELEM> bool esVacía(coleccionITF<ELEM>& c);


/* Devuelve el número de ítems que hay en la colección c
*/
template<typename ELEM> int tamaño(coleccionITF<ELEM>& c);


/* Inicializa el iterador para recorrer los ítems de la colección c, de forma que el siguiente ítem 
 a visitar sea el que tiene el identificador (lexicográficamente) menor (situación de no haber visitado ningún ítem).
*/
template<typename ELEM> void iniciarIterador(coleccionITF<ELEM>& c);


/* Devuelve verdad si queda algún ítem por visitar con el iterador de la colección c,
 devuelve falso si ya se ha visitado el último ítem
*/
template<typename ELEM> bool existeSiguiente(coleccionITF<ELEM>& c);


/* Devuelve el siguiente ítem a visitar con el iterador de la colección c.
     Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ELEM> void siguiente(coleccionITF<ELEM>& c); //falta definir el puntero


/* Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem,
 entendiendo por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no visitados.
      Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ELEM> void avanza(coleccionITF<ELEM>& c);


#endif 