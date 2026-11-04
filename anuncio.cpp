//
// Created by yaret on 21/10/26.
//

#include "anuncio.hpp"


void crearAnuncio(string id, string t, string descrip, string categ, Fecha publi, Fecha fi, Anuncio& anuncio) {
    anuncio.id = id;
    anuncio.titulo = t;
    anuncio.descripcion = descrip;
    anuncio.categoria = categ;
    anuncio.publicacion = publi;
    anuncio.finalizacion = fi;
}

string suIdentificador(Anuncio e) {
    return e.id;
}

string suTitulo(Anuncio e) {
    return e.titulo;
}

Anuncio cambiarTitulo(Anuncio e, string n) {
    e.titulo = n;
    return e;
}

string suDescripcion(Anuncio e) {
    return e.descripcion;
}

string suCategoria(Anuncio e) {
    return e.categoria;
}

Anuncio cambiarCategoria(Anuncio e, string n) {
    e.categoria = n;
    return e;
}

Anuncio cambiarDescripcion(Anuncio e, string n) {
    e.descripcion = n;
    return e;
}

Fecha suPublicacion(Anuncio e) {
    return e.publicacion;
}

Fecha suFinalizacion(Anuncio e) {
    return e.finalizacion;
}