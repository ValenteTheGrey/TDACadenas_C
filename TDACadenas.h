#ifndef TDACADENAS_TDACADENAS_H
#define TDACADENAS_TDACADENAS_H

#include <stdbool.h>

//LIB PARA USARSE DE ESTA MANERA:
/*
int main()
{
char cadOrig[]= "@#$%esT0%^$&*eS{}:uNA@#$%CadENa#$%^a$%^";
char cadDest[100];
normalizarCadena(cadOrig, cadDest);
printf("%s\n", cadDest);
return 0;
}
*/


typedef struct
{
    char* cursor;
    char* iniCad;
}
SecuenciaPalabras;

typedef struct
{
    char* ini;
    char* fin;
    int cantLetras;
}
Palabra;



#define esLetra(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#define miToUpper(c) (((c) >= 'a' && (c) <= 'z') ? (c) - ('a' - 'A') : (c))
#define miToLower(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + ('a' - 'A') : (c))

char* normalizarCadena(const char* cadOrg, char* cadDest);
void crearSecuenciaPalabras(SecuenciaPalabras* sec, const char* cad);
bool leerPalabra(SecuenciaPalabras* sec, Palabra* pal);
bool escribirPalabra(SecuenciaPalabras* secEsc, const Palabra* pal, Palabra* palEscr);
bool escribirCaracter(SecuenciaPalabras* sec, char c);
void aTitulo(Palabra* pal);
void mostrarPalabra(const Palabra* pal);
bool reposicionarSecuenciaPalabras(SecuenciaPalabras* sec, int despl);
void cerrarSecuenciaPalabras(SecuenciaPalabras* sec);

#endif //TDACADENAS_TDACADENAS_H
