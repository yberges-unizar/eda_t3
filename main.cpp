#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    Fecha fecha_publicacion;
    Fecha fecha_finalizacion;
    bool error;
    crear(1, 1, 2020, fecha_publicacion, error);
    crear(1, 1, 2020, fecha_finalizacion, error);

    Anuncio a = crearAnuncio("1", "Titulo", "Descripcion", "Categoria", fecha_publicacion, fecha_finalizacion);
    return 0;
}
