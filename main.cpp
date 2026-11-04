#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"
#include <string>   //importante para manejar 
#include <fstream> //para abrir archivos

using namespace std;

string identificador(Anuncio a){
    return suIdentificador(a);
}

string tema(Anuncio a){
    return suCategoria(a);
}

Fecha fecha(Anuncio a){
    return suPublicacion(a);;
}

void procesarEntrada(const std::string entrada, std::ifstream& archivo);

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
    std::ifstream archivo("entrada.txt");
    std::string aux;
    if (archivo.is_open()) {
        while(std::getline(archivo, aux)){ //leemos linea a linea, se consumira el delimitador (\n)

            procesarEntrada(aux, archivo);
        }
    archivo.close();
    }else{
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return 0;
}


// Función para procesar la entrada del archivo
void procesarEntrada(const std::string entrada, std::ifstream& archivo) {
    std::string aux;
    if(entrada == "A"){
        //las siguientes 6 líneas del fichero contendrán los datos para la información de un anuncio,
        //en el orden: id, título, descripción, categoría, fecha de publicación y fecha de finalización
        std::getline(archivo, aux);

        std::getline(archivo, aux);
        
        std::getline(archivo, aux);
        
        std::getline(archivo, aux);
        
        std::getline(archivo, aux);
        
        std::getline(archivo, aux);     

    }else if(entrada == "C"){
        //las siguientes 6 líneas del fichero contendrán los datos para la información de un anuncio,
        //en el orden: id, título, descripción, categoría, fecha de publicación y fecha de finalización

    }else if(entrada == "O"){
        //la siguiente línea del fichero contendrá el identificador de anuncio 

    }else if(entrada == "E"){
        //la siguiente línea del fichero contendrá el identificador de anuncio 
        std::getline(archivo, aux);

    }else if(entrada == "B"){
        //la siguiente línea del fichero contendrá el identificador de anuncio 

    }else if(entrada == "EC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios

    }else if(entrada == "BC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios

    }else if(entrada == "LC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios

    }else if(entrada == "P"){
        //la siguiente línea del fichero contendrá el valor de la fecha a utilizar

    }else if(entrada == "LO"){
        //la siguiente línea del fichero contendrá el valor de la fecha a utilizar

    }else if(entrada == "LT"){
        //no requiere que le sigan otras líneas con más datos para su ejecución, así que la siguiente 
        //línea sería la de la siguiente instrucción, o el final del fichero

    }
}


