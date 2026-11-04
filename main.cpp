#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"
//#include "coleccionITF.hpp"
#include <string>   //importante para manejar cadenas de caracteres
#include <fstream> //para abrir archivos

using namespace std;

string RUTA_FICHERO_SALIDA = "./output.txt";
string RUTA_FICHERO_ENTRADA = "../entrada.txt";

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
void obtener_datos_anuncio(string &id, string &titulo, string &descripcion,
    string &categoria, Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo);
string anyadir_anuncio(ifstream& archivo);

int main() {
    ifstream archivo(RUTA_FICHERO_ENTRADA);
    string linea;

    // Abrimos el archivo de entrada para leer la entrada
    if (archivo.is_open()) {
        while(getline(archivo, linea)){ //leemos linea a linea, se consumira el delimitador (\n)
            procesarEntrada(linea, archivo);
        }
        archivo.close();
    }else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}


// Función para procesar la entrada del archivo
void procesarEntrada(const string entrada, ifstream& archivo) {
    if(entrada == "A"){
        //las siguientes 6 líneas del fichero contendrán los datos para la información de un anuncio,
        //en el orden: id, título, descripción, categoría, fecha de publicación y fecha de finalización

        anyadir_anuncio(archivo);

    }else if(entrada == "C"){
        //las siguientes 6 líneas del fichero contendrán los datos para la información de un anuncio,
        //en el orden: id, título, descripción, categoría, fecha de publicación y fecha de finalización

    }else if(entrada == "O"){
        //la siguiente línea del fichero contendrá el identificador de anuncio 

    }else if(entrada == "E"){
        //la siguiente línea del fichero contendrá el identificador de anuncio

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


string anyadir_anuncio(ifstream& archivo) {
    string id;
    string titulo;
    string descripcion;
    string categoria;
    Fecha fecha_publicacion;
    Fecha fecha_finalizacion;
    Anuncio anun;

    obtener_datos_anuncio(id, titulo, descripcion, categoria, fecha_publicacion, fecha_finalizacion, archivo);
    crearAnuncio(id, titulo, descripcion, categoria, fecha_publicacion, fecha_finalizacion, anun);
}

void obtener_datos_anuncio(string &id, string &titulo, string &descripcion, string &categoria, Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo) {
    string fecha_publicacion_dia;
    string fecha_publicacion_mes;
    string fecha_publicacion_anyo;
    string fecha_finalizacion_dia;
    string fecha_finalizacion_mes;
    string fecha_finalizacion_anyo;
    bool error;

    getline(archivo, id);
    getline(archivo, titulo);
    getline(archivo, descripcion);
    getline(archivo, categoria);
    getline(archivo, fecha_publicacion_anyo, '-');
    getline(archivo, fecha_publicacion_mes, '-');
    getline(archivo, fecha_publicacion_dia);
    getline(archivo, fecha_finalizacion_anyo, '-');
    getline(archivo, fecha_finalizacion_mes, '-');
    getline(archivo, fecha_finalizacion_dia);

    crear(stoi(fecha_publicacion_dia), stoi(fecha_publicacion_mes),
        stoi(fecha_publicacion_anyo), fecha_publicacion, error);

    crear(stoi(fecha_finalizacion_dia), stoi(fecha_finalizacion_mes),
        stoi(fecha_finalizacion_anyo), fecha_finalizacion, error);

    cout << "Fecha de publicación: " << dia(fecha_publicacion) << "/" << mes(fecha_publicacion) << "/" << anyo(fecha_publicacion) << endl;
    cout << "Fecha de finalización: " << dia(fecha_finalizacion) << "/" << mes(fecha_finalizacion) << "/" << anyo(fecha_finalizacion) << endl;
}