#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"
#include "coleccionITF.hpp"
#include <string>
#include <fstream>

using namespace std;

const string RUTA_FICHERO_SALIDA = "./salida.txt";
const string RUTA_FICHERO_ENTRADA = "./entrada.txt";
string SEPARADOR_SALIDA = ":::";

string identificador(Anuncio a);
string tema(Anuncio a);
Fecha fecha(Anuncio a);
void procesar_entrada(const string entrada, ifstream& archivo, coleccionITF<Anuncio>& coleccionAnuncios);
void obtener_datos_anuncio(string &id, string &titulo, string &descripcion,
    string &categoria, Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo);
void anyadir_anuncio(ifstream& archivo);
void salida_anuncio(ofstream& archivo_salida ,const string id, const string titulo, const string categoria,
    const string descripcion, const Fecha fecha_publicacion, const Fecha fecha_finalizacion, bool& error);
void obtener_anuncio(ifstream& archivo);
string fecha_string(const Fecha& f);

int main() {
    ifstream archivo_entrada(RUTA_FICHERO_ENTRADA);
    ofstream archivo_salida(RUTA_FICHERO_SALIDA);
    string linea;
    coleccionITF<Anuncio> coleccionAnuncios;

    crear(coleccionAnuncios);

    if (archivo_entrada.is_open()) {
        while(getline(archivo_entrada, linea)){
            procesar_entrada(linea, archivo_entrada, archivo_salida, coleccionAnuncios);
        }
        archivo_entrada.close();
    }else {
        cout << "No se pudo abrir el archivo de entrada" << endl;
        exit(1);
    }
    archivo_salida.close();

}


// Función para procesar la entrada del archivo
void procesar_entrada(const string entrada, ifstream& archivoEntrada, ofstream& archivoSalida, coleccionITF<Anuncio>& coleccionAnuncios) {
    if(entrada == "A"){
        anyadir_anuncio(coleccionAnuncios, archivoEntrada, archivoSalida);
    }else if(entrada == "C"){
        //las siguientes 6 líneas del fichero contendrán los datos para la información de un anuncio,
        //en el orden: id, título, descripción, categoría, fecha de publicación y fecha de finalización

    }else if(entrada == "O"){
        obtener_anuncio(archivoEntrada);

    }else if(entrada == "E"){
        //la siguiente línea del fichero contendrá el identificador de anunci
        
        string existe_ident;
        getline(archivoEntrada, existe_ident);
        bool encontrado = esta(coleccionAnuncios, existe_ident);
        if(archivoSalida.is_open()){
            if(encontrado){
                archivoSalida << "EXISTENTE " << existe_ident << endl;
            }else{
                archivoSalida << "DESCONOCIDO " << existe_ident << endl;
            }
        }else{
            cout << "No se pudo abrir el archivo de salida" << endl;
        }


    }else if(entrada == "B"){
        //la siguiente línea del fichero contendrá el identificador de anuncio 

    }else if(entrada == "EC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios

    }else if(entrada == "BC"){
        int aux = tamanyo(coleccionAnuncios);
        string tema;
        getline(archivoEntrada, tema);
        zanjarTema(coleccionAnuncios, tema);
        if(aux != tamanyo(coleccionAnuncios)){ //Para saber si se ha anyadido con exito compararemos la cantidad de anuncios
            if(archivoSalida.is_open()){
                archivoSalida << "BORRADO: ";
            }else{
                cout << "Error tipo BC";
            }

        }else{
        if(archivoSalida.is_open()){
                archivoSalida << "NO BORRADO: ";
            }else{
                cout << "Error tipo BC";
        }

        if(archivoEntrada.is_open()){
            archivoSalida << tema << endl;
        }else{
            cout << "Error tipo BC";
        }
        

    }

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


void anyadir_anuncio(coleccionITF<Anuncio>& coleccionAnuncios, ifstream& archivoEntrada, ofstream& archivoSalida) {
    string id;
    string titulo;
    string descripcion;
    string categoria;
    Fecha fecha_publicacion;
    Fecha fecha_finalizacion;
    Anuncio anun;

    obtener_datos_anuncio(id, titulo, descripcion, categoria, fecha_publicacion, fecha_finalizacion, archivoEntrada);
    crearAnuncio(id, titulo, descripcion, categoria, fecha_publicacion, fecha_finalizacion, anun);

    int aux = tamanyo(coleccionAnuncios);
    anyadir(coleccionAnuncios, anun);
    if(aux != tamanyo(coleccionAnuncios)){ //Para saber si se ha anyadido con exito compararemos la cantidad de anuncios
        if(archivoSalida.is_open()){
            archivoSalida << "INTRODUCIDO: ";
        }else{
            cout << "Error tipo 1";
        }
        

    }else{
        if(archivoSalida.is_open()){
            archivoSalida << "NO INTRODUCIDO: ";
        }else{
            cout << "Error tipo 1";
        }
        

    }

    bool error = false;
    salida_anuncio(archivoSalida, id, titulo, categoria, descripcion, fecha_publicacion, fecha_finalizacion, error);
    if(error){ cout << "Error en fun salida_anuncio" << endl;}
    
}

void obtener_datos_anuncio(string &id, string &titulo, string &descripcion, string &categoria, Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo){
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

    if (error) {return;}

    crear(stoi(fecha_finalizacion_dia), stoi(fecha_finalizacion_mes),
        stoi(fecha_finalizacion_anyo), fecha_finalizacion, error);
}

void salida_anuncio(ofstream& archivo_salida, const string id, const string titulo, const string categoria,
    const string descripcion, const Fecha fecha_publicacion, const Fecha fecha_finalizacion, bool& error) {
    


    if (archivo_salida.is_open()) {
        archivo_salida << id << SEPARADOR_SALIDA << titulo << SEPARADOR_SALIDA << categoria
        << SEPARADOR_SALIDA << descripcion << SEPARADOR_SALIDA << fecha_string(fecha_publicacion)
        << SEPARADOR_SALIDA << fecha_string(fecha_finalizacion) << endl;
    } else {
        error = true;
    }
}

string fecha_string(const Fecha& f) {
    string fecha_string;

    fecha_string = to_string(anyo(f)) + "-";

    if (mes(f) < 10) {
        fecha_string += "0";            // relleno para meses de un dígito
    }
    fecha_string += to_string(mes(f)) + "-";
    if (dia(f) < 10) {
        fecha_string += "0";            // relleno para días de un dígito
    }

    fecha_string += to_string(dia(f));
    return fecha_string;
}

void obtener_anuncio(ifstream& archivo) {
    string id;

    getline(archivo, id);


}

string identificador(Anuncio a){
    return suIdentificador(a);
}

string tema(Anuncio a){
    return suCategoria(a);
}

Fecha fecha(Anuncio a){
    return suPublicacion(a);;
}