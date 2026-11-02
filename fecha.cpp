#include "fecha.hpp"

// Implementacion de las operaciones del TAD fecha.
// Operaciones auxiliares sobre enteros.

// Devuelve verdad si y solo si el anyo a es bisiesto.
bool esBisiesto(int a) {
    return (a % 4 == 0 && !(a % 100 == 0 && a % 400 != 0));
}

// Devuelve verdad si y solo si (d,m,a) representan una fecha valida.
bool esFechaValida(int d, int m, int a) {
    bool valida = 1583 <= a && 1 <= m && m <= 12;
    if (valida) {
        switch (m) {
        case 4: case 6: case 9: case 11:
            valida = 1 <= d && d <= 30;
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            valida = 1 <= d && d <= 31;
            break;
        case 2:
            if (!esBisiesto(a)) {
                valida = 1 <= d && d <= 28;
            }
            else
                valida = 1 <= d && d <= 29;
            break;
        }
    }
    return valida;
}

// Crea una fecha con los valores dados y devuelve en error si la fecha es invalida.
void crear(int dia, int mes, int anyo, Fecha& f, bool& error) {
    if (esFechaValida(dia, mes, anyo)) {
        f.elDia = dia;
        f.elMes = mes;
        f.elAnyo = anyo;
        error = false;
    }
    else
        error = true;
};

// Devuelve el dia de la fecha.
int dia(const Fecha& f) {
    return f.elDia;
};

// Devuelve el mes de la fecha.
int mes(const Fecha& f) {
    return f.elMes;
};

// Devuelve el anyo de la fecha.
int anyo(const Fecha& f) {
    return f.elAnyo;
};

// Devuelve verdad si y solo si las fechas f1 y f2 son iguales, es decir, representan el mismo da, mes y ao.
bool iguales(const Fecha& f1, const Fecha& f2) {
    return f1.elDia == f2.elDia && f1.elMes == f2.elMes && f1.elAnyo == f2.elAnyo;
};

// Devuelve verdad si y solo si la fecha f1 es anterior a la fecha f2.
bool anterior(const Fecha& f1, const Fecha& f2) {
    return f1.elAnyo <  f2.elAnyo ||
           (f1.elAnyo == f2.elAnyo && f1.elMes < f2.elMes) ||
           (f1.elAnyo == f2.elAnyo && f1.elMes == f2.elMes && f1.elDia < f2.elDia);
};

// Devuelve verdad si y slo si la fecha f1 es posterior a la fecha f2.
bool posterior(const Fecha& f1, const Fecha& f2) {
    return !iguales(f1,f2) && !anterior(f1,f2);
};


