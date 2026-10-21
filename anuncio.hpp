/* Yaret Berges Calero; 838561
*/

#include<iostream>
#include<string>
#include "fecha.hpp"

using namespace std;

// PREDECLARACION DEL TAD anuncio (inicio INTERFAZ)

/*
 Los valores del TAD anuncio representarán tuplas formadas como:
 (identificador, título, descripción, categoría, publicación, finalización), siendo publicación y
 finalización sendas fechas (válidas según el calendario gregoriano), y el resto sendas cadenas.
 */
struct Anuncio;

/*
 Devuelve un anuncio compuesto con identificador ID, título t, descripción descrip, categoría
 categ, y con fecha de publicación publi y fecha de finalización fi
 */
Anuncio crearAnuncio(string id, string t, string descrip, string categ, Fecha publi, Fecha fi);

/*
 Dado un anuncio e formado como (I,T,D,C,P,F) devuelve I, i.e. el identificador del anuncio e
 */
string suIdentificador(Anuncio e);

/*
 Dado un anuncio e formado como (I,T,D,C,P,F) devuelve T, i.e. el título del anuncio e
 */
string suTitulo(Anuncio e);

/*
Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
compuesto como (I,n,D,C,P,F)
 */
Anuncio cambiarTítulo(Anuncio e, string n);

/*
 * Dado un anuncio e formado como (I,T,D,C,P,F) devuelve D, i.e. la descripción del anuncio e
 */
string suDescripción(Anuncio e);

/*
 Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
 compuesto como (I,T,n,C,P,F)
 */
Anuncio cambiarDescripción(Anuncio e, string n);

/*
 * Dado un anuncio e formado como (I,T,D,C,P,F) devuelve C, i.e. la categoría del anuncio e
 */
string suCategoria(Anuncio e);

/*
 Dado un anuncio e formado como (I,T,D,C,P,F) y una cadena n, devuelve un anuncio igual al
 compuesto como (I,T,D,n,P,F)
 */
Anuncio cambiarCategoria(Anuncio e, string n);

/*
 * Dado un anuncio e formado como (I,T,D,C,P,F) devuelve P, i.e. la fecha de publicación de e
 */
Fecha suPublicación(Anuncio e);

/*
 * Dado un anuncio e formado como (I,T,D,C,P,F) devuelve F, i.e. la fecha de finalización de e
 */
Fecha suFinalización(Anuncio e);

// FIN de la PREDECLARACION DEL TAD anuncio (fin INTERFAZ)

// DECLARACION DEL TAD anuncio


struct Anuncio {
    friend void crearAnuncio(string id, string t, string descrip, string categ, Fecha publi, Fecha fi);

    private:
        string id;
        string titulo;
        string descripcion;
        string categoria;
        Fecha publicacion;
        Fecha finalizacion;

};
