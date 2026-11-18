/*
 * Fichero: main.cpp
 * Descripción: programa de prueba que gestiona una colección de anuncios.
 *   Lee las instrucciones de "entrada.txt" y escribe los resultados en "salida.txt".
 * Autores:
 *   Yaret Berges Calero, NIP 838561
 *   Diego Masip Sisa, NIP 959248 
 *   Sergio Iso Blasco, NIP 927177
 */

#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"
#include "coleccionITF.hpp"
#include <string>
#include <fstream>

using namespace std;

const string RUTA_FICHERO_SALIDA = "./salida.txt";
const string RUTA_FICHERO_ENTRADA = "./entrada.txt";
const string SEPARADOR_DATOS = ":::";

string identificador(const Anuncio& a);
string tema(const Anuncio& a);
Fecha fecha(const Anuncio& a);
/* Ejecuta la instrucción entrada ("A", "C", "O", "E", "B", "EC", "BC", "LC", "P", "LO" o "LT")
   sobre coleccion_anuncios: lee de archivo_entrada las líneas de datos que necesita la
   instrucción y escribe su resultado en archivo_salida. Una instrucción desconocida se ignora. */
void gestionar_entrada_salida(const string entrada, ifstream& archivo_entrada, ofstream& archivo_salida,
    coleccionITF<Anuncio>& coleccion_anuncios);

/* Lee de archivo las 6 líneas con los datos de un anuncio, en el orden del fichero de entrada:
   identificador, título, descripción, categoría, fecha de publicación y fecha de finalización
   (fechas en formato aaaa-mm-dd), y los devuelve en los parámetros correspondientes. */
void obtener_datos_anuncio(string &id, string &titulo, string &descripcion,
    string &categoria, Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo);
void anyadir_anuncio(coleccionITF<Anuncio>& coleccion_anuncios, ifstream& archivoEntrada, ofstream& archivoSalida);

/* Escribe en archivo_salida una línea con los datos de anuncio separados por ":::", en el orden:
   identificador, título, categoría, descripción, publicación y finalización (aaaa-mm-dd).
   Es el formato común de las salidas de A, C y O. */
void escribir_datos_anuncio(ofstream& archivo_salida , const Anuncio& anuncio);

/* Instrucción LT: escribe en archivo_salida la línea "-----LISTADO: N", con N el número de anuncios,
   después una línea por anuncio en orden creciente de identificador con el formato
   "[ id -de-> categoria ;;; título ] (publicación) --- descripción --- (finalización)"
   y por último la línea "-----". Recorre la colección con su iterador, que queda al final. */
void listar_anuncios(ofstream& archivo_salida, coleccionITF<Anuncio>& coleccion);

/* Instrucción O: lee de archivo_entrada una línea con un identificador. Si en coleccion_anuncios
   hay un anuncio con ese identificador, escribe "LOCALIZADO: " seguido de sus datos (formato de
   escribir_datos_anuncio); si no, escribe "NO LOCALIZADO: " seguido del identificador. */
void obtener_anuncio(ifstream& archivo_entrada, ofstream& archivo_salida, const coleccionITF<Anuncio>& coleccion_anuncios);

/* Lee de f una línea con una fecha en formato aaaa-mm-dd y la devuelve en fecha.
   error es true si la fecha leída no es válida; en ese caso fecha no se modifica. */
void leer_fecha(ifstream& f, Fecha& fecha, bool& error);

/* Devuelve la fecha f como cadena en formato aaaa-mm-dd, con el mes y el día
   rellenados con un cero a la izquierda si tienen una sola cifra (p. ej. 2026-09-01). */
string fecha_string(const Fecha& f);

/* Crea una colección de anuncios vacía, ejecuta en orden todas las instrucciones de
   "entrada.txt" y escribe el resultado de cada una en "salida.txt". */
int main() {
    ifstream archivo_entrada(RUTA_FICHERO_ENTRADA);
    ofstream archivo_salida(RUTA_FICHERO_SALIDA);
    string instruccion;
    coleccionITF<Anuncio> coleccion_anuncios;

    crear(coleccion_anuncios);//Inicializamos la coleccion de anuncios

    if (archivo_entrada.is_open()) {
        while(archivo_entrada >> instruccion){
            archivo_entrada.ignore(1000, '\n'); // Ignora el resto de la linea. Solo nos interesa la instruccion
            gestionar_entrada_salida(instruccion, archivo_entrada, archivo_salida, coleccion_anuncios);
        }
        archivo_entrada.close();
    }else {
        cerr << "No se pudo abrir el archivo de entrada" << endl;
    }
    archivo_salida.close();

}


// Función para procesar la entrada del archivo
void gestionar_entrada_salida(const string entrada, ifstream& archivo_entrada, ofstream& archivo_salida,
    coleccionITF<Anuncio>& coleccion_anuncios) {
    if(entrada == "A"){
        anyadir_anuncio(coleccion_anuncios, archivo_entrada, archivo_salida);
    }else if(entrada == "C"){
        //las siguientes 6 líneas del fichero contendrán los datos para la información de un anuncio,
        //en el orden: id, título, descripción, categoría, fecha de publicación y fecha de finalización
        // --- Instrucción C: Cambiar / Actualizar Anuncio --
        string id, titulo, descripcion, categoria;
        Fecha fecha_publicacion, fecha_finalizacion;
        obtener_datos_anuncio(id, titulo, descripcion, categoria,
            fecha_publicacion, fecha_finalizacion, archivo_entrada);

        Anuncio anuncio;
        crearAnuncio(id, titulo, descripcion, categoria,
            fecha_publicacion, fecha_finalizacion, anuncio);

        if (esta(id, coleccion_anuncios)) {
            actualizar(coleccion_anuncios, anuncio);
            archivo_salida << "CAMBIADO: ";
            escribir_datos_anuncio(archivo_salida, anuncio);
        } else {
            archivo_salida << "NO CAMBIADO: " << id << endl;
        }

    }else if(entrada == "O"){
        obtener_anuncio(archivo_entrada, archivo_salida, coleccion_anuncios);

    }else if(entrada == "E"){
        //la siguiente línea del fichero contendrá el identificador de anunci
        
        string existe_ident;
        getline(archivo_entrada, existe_ident);
        bool encontrado = esta(existe_ident, coleccion_anuncios);
        if(archivo_salida.is_open()){
            if(encontrado){
                archivo_salida << "EXISTENTE: " << existe_ident << endl;
            }else{
                archivo_salida << "DESCONOCIDO: " << existe_ident << endl;
            }
        }else{
            cerr << "No se pudo abrir el archivo de salida" << endl;
        }


    }else if(entrada == "B"){
        string ident;
        int tamanyo_previo_coleccion;

        getline(archivo_entrada, ident);
        tamanyo_previo_coleccion = tamanyo(coleccion_anuncios);
        borrar(ident, coleccion_anuncios);
        if (tamanyo(coleccion_anuncios) < tamanyo_previo_coleccion) {
            archivo_salida << "BORRADO: " << ident << endl;
        } else {
            archivo_salida << "NO BORRADO: " << ident << endl;
        }

    }else if(entrada == "EC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios
        // --- Instrucción EC: Existe Categoría ---
        string categoria;
        getline(archivo_entrada, categoria);
    
        // Se comprueba en la colección usando existeTema
        if (existeTema(coleccion_anuncios, categoria)) {
            archivo_salida << "CATEGORIA CONOCIDA: " << categoria << endl;
        } else {
            archivo_salida << "CATEGORIA DESCONOCIDA: " << categoria << endl;
        }

    }else if(entrada == "BC"){
        int tamanyo_previo = tamanyo(coleccion_anuncios);
        string tema;
        getline(archivo_entrada, tema);
        zanjarTema(coleccion_anuncios, tema);

        if(tamanyo_previo < tamanyo(coleccion_anuncios)){ //Para saber si se ha anyadido con exito compararemos la cantidad de anuncios
            archivo_salida << "ELIMINADOS: " << tema << endl;
        } else {
            archivo_salida << "NO ELIMINADOS: " << tema << endl;
        }

    

    }else if(entrada == "LC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios
        // --- Instrucción LC: Listar Categoría ---
        string categoria;
        getline(archivo_entrada, categoria);
        string ids = delTema(coleccion_anuncios, categoria, SEPARADOR_DATOS);
        archivo_salida << "DE CATEGORIA: " << categoria << " ---";
        if (!ids.empty()) {
            archivo_salida << " " << ids;
        }
        archivo_salida << " ---" << endl;
    }else if(entrada == "P"){
        Fecha limite;
        bool error;
        leer_fecha(archivo_entrada, limite, error);
        if (!error) {
            int tamanyo_previo = tamanyo(coleccion_anuncios);
            purgar(coleccion_anuncios, limite);

            if (tamanyo(coleccion_anuncios) < tamanyo_previo) {
                archivo_salida << "PURGADOS: " << fecha_string(limite) << endl;
            } else {
                archivo_salida << "NO PURGADOS: " << fecha_string(limite) << endl;
            }
        }

    }else if(entrada == "LO"){
        Fecha fecha_limite;
        bool error;
        string ident_obsoletos;

        leer_fecha(archivo_entrada, fecha_limite, error);
        ident_obsoletos = obsoletos(fecha_limite, SEPARADOR_DATOS, coleccion_anuncios);

        archivo_salida << "ANTERIORES A: " << fecha_string(fecha_limite) << " --- "
            << ident_obsoletos << " --- " << endl;

    }else if(entrada == "LT"){
        listar_anuncios(archivo_salida, coleccion_anuncios);

    }
}


void anyadir_anuncio(coleccionITF<Anuncio>& coleccion_anuncios, ifstream& archivoEntrada, ofstream& archivoSalida) {
    string id;
    string titulo;
    string descripcion;
    string categoria;
    Fecha fecha_publicacion;
    Fecha fecha_finalizacion;
    Anuncio anun;

    obtener_datos_anuncio(id, titulo, descripcion, categoria,
        fecha_publicacion, fecha_finalizacion, archivoEntrada);
    crearAnuncio(id, titulo, descripcion, categoria,
        fecha_publicacion, fecha_finalizacion, anun);

    int aux = tamanyo(coleccion_anuncios);
    anyadir(coleccion_anuncios, anun);
    if(aux != tamanyo(coleccion_anuncios)){ //Para saber si se ha anyadido con exito compararemos la cantidad de anuncios
        if(archivoSalida.is_open()){
            archivoSalida << "INTRODUCIDO: ";
        }else{
            cerr << "No se pudo escribir en el archivo de salida";
        }
        

    }else{
        if(archivoSalida.is_open()){
            archivoSalida << "NO INTRODUCIDO: ";
        }else{
            cerr << "No se pudo escribir en el archivo de salida";
        }
    }

    bool error = false;
    escribir_datos_anuncio(archivoSalida, anun);
    if(error){ cerr << "Error al escribir el anuncio en el archivo de salida" << endl;}
    
}

void obtener_datos_anuncio(string &id, string &titulo, string &descripcion, string &categoria,
    Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo){
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

void escribir_datos_anuncio(ofstream& archivo_salida, const Anuncio& anuncio) {
    archivo_salida << suIdentificador(anuncio) << SEPARADOR_DATOS << suTitulo(anuncio) << SEPARADOR_DATOS
    << suCategoria(anuncio) << SEPARADOR_DATOS << suDescripcion(anuncio) << SEPARADOR_DATOS
    << fecha_string(suPublicacion(anuncio)) << SEPARADOR_DATOS << fecha_string(suFinalizacion(anuncio)) << endl;
}

string fecha_string(const Fecha& f) {
    string fecha_string;

    fecha_string = to_string(anyo(f)) + "-";

    if (mes(f) < 10) {
        fecha_string += '0';
    }
    fecha_string += to_string(mes(f)) + "-";
    if (dia(f) < 10) {
        fecha_string += '0';
    }

    fecha_string += to_string(dia(f));
    return fecha_string;
}

void obtener_anuncio(ifstream& archivo_entrada, ofstream& archivo_salida, const coleccionITF<Anuncio>& coleccion_anuncios) {
    Anuncio anuncio;
    string ident;
    bool error;

    getline(archivo_entrada, ident);
    obtenerITF(ident, coleccion_anuncios, anuncio, error);

    if (!error) {
        archivo_salida << "LOCALIZADO: ";
        escribir_datos_anuncio(archivo_salida, anuncio);
    } else {
        archivo_salida << "NO LOCALIZADO: " << ident << endl;
    }
}

void listar_anuncios(ofstream& archivo_salida, coleccionITF<Anuncio>& coleccion) {
    Anuncio anuncio;

    archivo_salida << "-----LISTADO: " << tamanyo(coleccion) << endl;

    iniciarIterador(coleccion);
    
    while (existeSiguiente(coleccion)) {
        anuncio = siguiente(coleccion);
        archivo_salida << "[ " << suIdentificador(anuncio) << " -de-> " << suCategoria(anuncio) << " ;;; "
        << suTitulo(anuncio) << " ] (" << fecha_string(suPublicacion(anuncio)) << ") --- "
        << suDescripcion(anuncio) << " --- (" << fecha_string(suFinalizacion(anuncio)) << ")" << endl;
        avanza(coleccion);
    }

    archivo_salida << "-----" << endl;
}


void leer_fecha(ifstream& f, Fecha& fecha, bool& error) {
    string anyo_str, mes_str, dia_str;
    getline(f, anyo_str, '-');
    getline(f, mes_str, '-');
    getline(f, dia_str);
    crear(stoi(dia_str), stoi(mes_str), stoi(anyo_str), fecha, error);
}

string identificador(const Anuncio& a){
    return suIdentificador(a);
}

string tema(const Anuncio& a){
    return suCategoria(a);
}

Fecha fecha(const Anuncio& a){
    return suPublicacion(a);;
}