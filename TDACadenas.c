#include "TDACadenas.h"

#include <stdio.h>

char* normalizarCadena(const char* cadOrg, char* cadDest)
{
    SecuenciaPalabras secLect, secEscr;
    Palabra palLeida, palEscr;

    crearSecuenciaPalabras(&secLect, cadOrg);
    crearSecuenciaPalabras(&secEscr, cadDest);

    while(leerPalabra(&secLect, &palLeida))
    {
        escribirPalabra(&secEscr, &palLeida, &palEscr);
        aTitulo(&palEscr);
        escribirCaracter(&secEscr, ' ');
    }

    reposicionarSecuenciaPalabras(&secEscr, -1);
    cerrarSecuenciaPalabras(&secEscr);

    return cadDest;
}


void crearSecuenciaPalabras(SecuenciaPalabras* sec, const char* cad)
{
    sec->cursor = (char*)cad;
    sec->iniCad = (char*)cad;
}


bool leerPalabra(SecuenciaPalabras* sec, Palabra* pal)
{
    int cont = 0;

    while(*sec->cursor && !esLetra(*sec->cursor))
        sec->cursor++;

    if(!*sec->cursor)
        return false;

    pal->ini = sec->cursor;
    cont++;
    sec->cursor++;

    while(*sec->cursor && esLetra(*sec->cursor))
    {
        sec->cursor++;
        cont++;
    }


    pal->fin = sec->cursor - 1;
    pal->cantLetras = cont;

    return true;
}


bool escribirPalabra(SecuenciaPalabras* secEsc, const Palabra* pal, Palabra* palEscr)
{
    palEscr->ini = secEsc->cursor;

    for(char* i = pal->ini; i <= pal->fin; i++, secEsc->cursor++)
        *secEsc->cursor = *i;

    palEscr->fin = secEsc->cursor - 1;

    return true;
}


bool escribirCaracter(SecuenciaPalabras* sec, char c)
{
    *sec->cursor = c;
    sec->cursor++;

    return true;
}


void aTitulo(Palabra* pal)
{
    *pal->ini = miToUpper(*pal->ini);

    for(char* i = pal->ini + 1; i <= pal->fin; i++)
        *i = miToLower(*i);

}

void mostrarPalabra(const Palabra* pal)
{
    for(char* i = pal->ini; i <= pal->fin; i++)
        putchar(*i);
}


bool reposicionarSecuenciaPalabras(SecuenciaPalabras* sec, int despl)
{
    sec->cursor += despl;

    return true;
}


void cerrarSecuenciaPalabras(SecuenciaPalabras* sec)
{
    *sec->cursor = '\0';
}