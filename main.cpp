#include <iostream>
#include "fecha.hpp"
#include "anuncio.hpp"
#include "coleccionITF.hpp"
#include <string>
#include <fstream>

using namespace std;

const string RUTA_FICHERO_SALIDA = "./salida.txt";
const string RUTA_FICHERO_ENTRADA = "./entrada.txt";
const string SEPARADOR_SALIDA = ":::";

string identificador(const Anuncio& a);
string tema(const Anuncio& a);
Fecha fecha(const Anuncio& a);
void gestionar_entrada_salida(const string entrada, ifstream& archivo_entrada, ofstream& archivo_salida,
    coleccionITF<Anuncio>& coleccionAnuncios);
void obtener_datos_anuncio(string &id, string &titulo, string &descripcion,
    string &categoria, Fecha &fecha_publicacion, Fecha &fecha_finalizacion, ifstream& archivo);
void anyadir_anuncio(coleccionITF<Anuncio>& coleccionAnuncios, ifstream& archivoEntrada, ofstream& archivoSalida);
void escribir_datos_anuncio(ofstream& archivo_salida , const Anuncio& anuncio);
void obtener_anuncio(ifstream& archivo_entrada, ofstream& archivo_salida, const coleccionITF<Anuncio>& coleccionAnuncios);
string fecha_string(const Fecha& f);

int main() {
    ifstream archivo_entrada(RUTA_FICHERO_ENTRADA);
    ofstream archivo_salida(RUTA_FICHERO_SALIDA);
    string linea;
    coleccionITF<Anuncio> coleccionAnuncios;

    crear(coleccionAnuncios);

    if (archivo_entrada.is_open()) {
        while(getline(archivo_entrada, linea)){
            gestionar_entrada_salida(linea, archivo_entrada, archivo_salida, coleccionAnuncios);
        }
        archivo_entrada.close();
    }else {
        cout << "No se pudo abrir el archivo de entrada" << endl;
        exit(1);
    }
    archivo_salida.close();

}


// Función para procesar la entrada del archivo
void gestionar_entrada_salida(const string entrada, ifstream& archivo_entrada, ofstream& archivo_salida,
    coleccionITF<Anuncio>& coleccionAnuncios) {
    if(entrada == "A"){
        anyadir_anuncio(coleccionAnuncios, archivo_entrada, archivo_salida);
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

        if (esta(coleccionAnuncios, id)) {
            actualizar(coleccionAnuncios, anuncio);
            cout << "CAMBIADO: " << id << endl;
        } else {
            archivo_salida << "NO CAMBIADO: " << id << endl;
        }

    }else if(entrada == "O"){
        obtener_anuncio(archivo_entrada, archivo_salida, coleccionAnuncios);

    }else if(entrada == "E"){
        //la siguiente línea del fichero contendrá el identificador de anunci
        
        string existe_ident;
        getline(archivo_entrada, existe_ident);
        bool encontrado = esta(coleccionAnuncios, existe_ident);
        if(archivo_salida.is_open()){
            if(encontrado){
                archivo_salida << "EXISTENTE " << existe_ident << endl;
            }else{
                archivo_salida << "DESCONOCIDO " << existe_ident << endl;
            }
        }else{
            cerr << "No se pudo abrir el archivo de salida" << endl;
        }


    }else if(entrada == "B"){
        //la siguiente línea del fichero contendrá el identificador de anuncio 

    }else if(entrada == "EC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios
        // --- Instrucción EC: Existe Categoría ---
        string categoria;
        getline(archivo_entrada, categoria);
    
        // Se comprueba en la colección usando existeTema
        if (existeTema(coleccionAnuncios, categoria)) {
            archivo_salida << "CATEGORIA CONOCIDA: " << categoria << endl;
        } else {
            archivo_salida << "CATEGORIA DESCONOCIDA: " << categoria << endl;
        }

    }else if(entrada == "BC"){
        int aux = tamanyo(coleccionAnuncios);
        string tema;
        getline(archivo_entrada, tema);
        zanjarTema(coleccionAnuncios, tema);
        if(aux != tamanyo(coleccionAnuncios)){ //Para saber si se ha anyadido con exito compararemos la cantidad de anuncios
            if(archivo_salida.is_open()){
                archivo_salida << "BORRADO: ";
            }else{
                cout << "Error tipo BC";
            }

        }else{
        if(archivo_salida.is_open()){
                archivo_salida << "NO BORRADO: ";
            }else{
                cout << "Error tipo BC";
        }

        if(archivo_entrada.is_open()){
            archivo_salida << tema << endl;
        }else{
            cout << "Error tipo BC";
        }
        

    }

    }else if(entrada == "LC"){
        //la siguiente línea del fichero contendrá la categoría de los anuncios
        // --- Instrucción LC: Listar Categoría ---
        string categoria;
        getline(archivo_entrada, categoria);
    
        // Se listan los identificadores separados por ":::" usando delTema
        archivo_salida << "DE CATEGORIA: " << categoria << " --- "
            << delTema(coleccionAnuncios, categoria, ":::") << " ---" << endl;
    }else if(entrada == "P"){
        //la siguiente línea del fichero contendrá el valor de la fecha a utilizar
        // --- Instrucción P: Purgar por fecha ---
        string fecha_anyo, fecha_mes, fecha_dia;
        getline(archivo_entrada, fecha_anyo, '-');
        getline(archivo_entrada, fecha_mes, '-');
        getline(archivo_entrada, fecha_dia);

        Fecha limite;
        bool error;
        crear(stoi(fecha_dia), stoi(fecha_mes), stoi(fecha_anyo), limite, error);
        if (!error) {
            purgar(coleccionAnuncios, limite);
            archivo_salida << "PURGADOS: " << fecha_string(limite) << endl;
        }

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

    obtener_datos_anuncio(id, titulo, descripcion, categoria,
        fecha_publicacion, fecha_finalizacion, archivoEntrada);
    crearAnuncio(id, titulo, descripcion, categoria,
        fecha_publicacion, fecha_finalizacion, anun);

    int aux = tamanyo(coleccionAnuncios);
    anyadir(coleccionAnuncios, anun);
    if(aux != tamanyo(coleccionAnuncios)){ //Para saber si se ha anyadido con exito compararemos la cantidad de anuncios
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
    archivo_salida << suIdentificador(anuncio) << SEPARADOR_SALIDA << suTitulo(anuncio) << SEPARADOR_SALIDA
    << suCategoria(anuncio) << SEPARADOR_SALIDA << suDescripcion(anuncio) << SEPARADOR_SALIDA
    << fecha_string(suPublicacion(anuncio)) << SEPARADOR_SALIDA << fecha_string(suFinalizacion(anuncio)) << endl;
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

void obtener_anuncio(ifstream& archivo_entrada, ofstream& archivo_salida, const coleccionITF<Anuncio>& coleccionAnuncios) {
    Anuncio anuncio;
    string ident;
    bool error;

    getline(archivo_entrada, ident);
    obtenerITF(coleccionAnuncios, ident, anuncio, error);

    if (!error) {
        archivo_salida << "LOCALIZADO: ";
        escribir_datos_anuncio(archivo_salida, anuncio);
    } else {
        archivo_salida << "NO LOCALIZADO: " << ident << endl;
    }
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