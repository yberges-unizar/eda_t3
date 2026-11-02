#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"
#include <string>   //importante para manejar 
#include <fstream> //para abrir archivos

int main()
{
    std::cout << "Hello, World!" << std::endl;
    Fecha fecha_publicacion;
    Fecha fecha_finalizacion;
    bool error;
    crear(1, 1, 2020, fecha_publicacion, error);
    crear(1, 1, 2020, fecha_finalizacion, error);

    Anuncio a = crearAnuncio("1", "Titulo", "Descripcion", "Categoria", fecha_publicacion, fecha_finalizacion);

    // Abrimos el archivo de entrada para leer la entrada
    ifstream archivo("entrada.txt");
    string aux;
    if (archivo.is_open()) {
        while(getline(archivo, aux)){ //leemos linea a linea, se consumira el delimitador (\n)

        
        



        }
    archivo.close();
    }else{
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return 0;
}
