#include <stdio.h>
#include <stdlib.h>
#include "cjt_paraules.h"
#include <string.h>


void inicialitzar(cjt_paraules_t *c)
{
    c->n_el=0; //incialitza //FET 100%

}
bool pertany(cjt_paraules_t *c, char p[])
{
    int i;
    bool r;
    r=false;


    for(i=0; i< (c->n_el); i++)
    {
         if(strcmp(c->paraules[i], p)==0) //si son iguals retorna 0
        {
           r=true;
        }
    }
    return r;
    //problemas chicos, error de novato
}


bool ple(cjt_paraules_t *c)
{
    n_elems(&c);
    bool r;
    r = false;
    if(c->n_el== MAX_EL)
    {
        r=true;
    }
    return r;
}
bool buit(cjt_paraules_t *c)
{
    bool r;
    r=false;
    if(c->n_el==0)     //SI no hi ha cap element esta buit   //FET 100%
    {
          r=true; //indica que es veritat
    }

    return r; //envia el resultat
    //S'ha enganchao, s'ha enganchao, s'ha enganchao; en la puzolana! ¡Ahí está el milagro!
}
bool afegir(cjt_paraules_t *c, char p[])
{

    n_elems(&c); //falla algo amb aquesta merda, funciona amb inicialitzar i fa el retorn 1 pero no podem inicialitzar
    bool r =true;

            if(ple(c)) r=false;
            else
            {
                if(strlen(p)>=8) r=false;//discrimina la llargada de la paraula
                else
                {
                     if(pertany(c, p)) r=false;

                     else //discrimina si ja pertany al string
                     {
                         c->paraules[c->n_el]=(char*)malloc(sizeof(char)*(strlen(p)+1)); //obra l'espai per memoria dinamica char * cadena + 1
                         strcpy(c->paraules[c->n_el], p); //copia la paraula a la cadena
                         c->n_el++; //suma elements
                     }


                }
            }


    return r;
    //falta corregir + aplicar els caracters predeterminats per l'enunciat.
}
void eliminar(cjt_paraules_t *c, char p[])
{

    n_elems(&c->n_el); //reb els elements que hi ha
    c->paraules[c->n_el]=(char*)malloc(sizeof(char)*strlen(p+1)); //calcula la llargada de la paraula
    free(c->paraules[c->n_el]);  //borra la paraula
    c->n_el--; //resta el numero d'elements
     //Grans avanços
    //problamement ya esta.
}
int n_elems(cjt_paraules_t *c)
{
    return(c->n_el);
}
void mostrar(cjt_paraules_t *c)
{
    for(int i=0; i<c->n_el; i++)
    {
        printf("%s", c->paraules[i]);
        printf("\n");
    }
}


