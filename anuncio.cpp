//
// Created by yaret on 21/10/26.
//

#include "anuncio.hpp"


Anuncio crearAnuncio(string id, string t, string descrip, string categ, Fecha publi, Fecha fi) {
    Anuncio anuncio = {id, t, descrip, categ, publi, fi};
    return anuncio;
}

string suIdentificador(Anuncio e) {
    return e.id;
}

string suTitulo(Anuncio e) {
    return e.titulo;
}

Anuncio cambiarTítulo(Anuncio e, string n) {
    e.titulo = n;
    return e;
}

string suDescripción(Anuncio e) {
    return e.descripcion;
}

string suCategoria(Anuncio e) {
    return e.categoria;
}

Anuncio cambiarCategoria(Anuncio e, string n) {
    e.categoria = n;
    return e;
}

Anuncio cambiarDescripción(Anuncio e, string n) {
    e.descripcion = n;
    return e;
}

Fecha suPublicación(Anuncio e) {
    return e.publicacion;
}

Fecha suFinalización(Anuncio e) {
    return e.finalizacion;
}