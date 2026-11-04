#include <string>
#ifndef COLECCIONITF_HPP
#define COLECCIONITF_HPP



template<typename ITF> struct coleccionITF;


// Crea una coleccion vacia, es decir sin elementos
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
template<typename ITF> ITF obtenerITF(coleccionITF<ITF>& c, const std::string& ident); // falta definir el puntero


/* Devuelve la cadena resultante de concatenar los identificadores de todos los ítems que hay en c
 con fecha estrictamente anterior a f, y separados entre sí por la cadena separador
*/
template<typename ITF> std::string obsoletos(coleccionITF<ITF>& c, const std::string& separador, const int& f);


/* Devuelve una colección igual a la resultante de eliminar de c
 todos los ítems con fecha estrictamente anterior a f
*/
template<typename ITF> void purgar(coleccionITF<ITF>& c, const int& f);


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
template<typename ITF> bool esVacía(coleccionITF<ITF>& c);


/* Devuelve el número de ítems que hay en la colección c
*/
template<typename ITF> int tamaño(coleccionITF<ITF>& c);


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
template<typename ITF> ITF siguiente(coleccionITF<ITF>& c); //falta definir el puntero


/* Prepara el iterador de la colección c para que se pueda visitar el siguiente ítem,
 entendiendo por siguiente aquel ítem con (lexicográficamente) menor identificador de los todavía no visitados.
      Parcial: la operación no está definida si no quedan ítems por visitar (no existeSiguiente?(c))
*/
template<typename ITF> void avanza(coleccionITF<ITF>& c);


/* 
 * Definición de los struct para el TAD genérico colecciónITF
 */

template <typename ITF>
struct nodo {
    ITF dato;           // Elemento genérico almacenado
    nodo<ITF>* sig;     // Puntero al siguiente nodo de la lista enlazada
};

template <typename ITF>
struct coleccionITF {
    nodo<ITF>* primero; // Puntero al primer nodo de la lista ordenada
    int tamaño;         // Número total de elementos en la colección
    nodo<ITF>* cursor;  // Cursor auxiliar para implementar el iterador
};

// -----------------------------------------------------------------------------
// Pre: -
// Post: Devuelve verdad si y sólo si en c hay algún item con tema igual a t.
// -----------------------------------------------------------------------------
template <typename ITF>
bool existeTema(const std::string& t, const coleccionITF<ITF>& c) {
    bool encontrado = false;
    nodo<ITF>* aux = c.primero;
    while (aux != nullptr && !encontrado) {
        if (tema(aux->dato) == t) {
            encontrado = true;
        }
        aux = aux->sig;
    }
    return encontrado;
}

// -----------------------------------------------------------------------------
// Pre: -
// Post: Devuelve la cadena resultante de concatenar los identificadores de todos 
//       los items que hay en c con tema igual a t, separados por separador.
// -----------------------------------------------------------------------------
template <typename ITF>
std::string delTema(const std::string& t, const std::string& separador, const coleccionITF<ITF>& c) {
    std::string resultado = "";
    nodo<ITF>* aux = c.primero;
    bool primero = true;
    
    while (aux != nullptr) {
        if (tema(aux->dato) == t) {
            if (!primero) {
                resultado += separador;
            }
            resultado += identificador(aux->dato);
            primero = false;
        }
        aux = aux->sig;
    }
    return resultado;
}




#endif 