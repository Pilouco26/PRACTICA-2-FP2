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

    int i;

    bool r =true;
    i=0;
        while (i<(c->n_el+1) && (r!=false) )
        {
              if ((((int)p[i]<48) && ((int)p[i]>57)) || (((int)p[i] <97) && ((int)p[i] >122)))
                {
                    r= false;
                }
            i++;
        }

            n_elems(c);
             if(ple(c)||(strlen(p)>=8)|| pertany(c, p)) r=false;
            else
                {
                    c->paraules[c->n_el]=(char*)malloc(sizeof(char)*(strlen(p)+1)); //obra l'espai per memoria dinamica char * cadena + 1
                    strcpy(c->paraules[c->n_el], p); //copia la paraula a la cadena
                    c->n_el++; //suma elements
                }

    return r;
    //falta corregir + aplicar els caracters predeterminats per l'enunciat.
}
void eliminar(cjt_paraules_t *c, char p[])
{
    int i, posicio, comparacio;
    n_elems(c); //reb els elements que hi ha

    if (!buit(c) && pertany(c, p))
    {

        i=0;
        posicio=0;
    	while(strcmp(c->paraules[i], p)!=0)
    	{
         	if(strcmp(c->paraules[i], p)==0) //si son iguals retorna 0
        	{
                posicio=i; //posicio de la paraula a eliminar
        	}
        	i++;
    	}
    	free(c->paraules[i]);
    	c->n_el--;
    	//borra la paraula

    	for(i=posicio; i<(c->n_el); i++)
    	{
        	c->paraules[i]= c->paraules[i+1];
    	}
	}
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

    //Falla algo amb  mostar
}
