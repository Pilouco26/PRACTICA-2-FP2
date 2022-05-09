#include <stdio.h>
#include <stdlib.h>
#include "cjt_paraules.h"
#include <string.h>


void inicialitzar(cjt_paraules_t *c)
{
    c->n_el=0; //incialitza el conjunt amb zeros
}
bool pertany(cjt_paraules_t *c, char p[])
{
    int i;
    bool r;
    r=false;

    //Bucle per mirar si la paraula ja pertany al conjunt, amb un strcmp si les paraules son iguals retorna 0 i true.
    for(i=0; i< (c->n_el); i++)
    {
         if(strcmp(c->paraules[i], p)==0) //si son iguals retorna 0
        {
           r=true;
        }
    }
    return r;
}
// Esta ple si el numero d'elements coincideix amb el maxim
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
//Si el num d'elements es 0 retorna true
bool buit(cjt_paraules_t *c)
{
    bool r;
    r=false;
    if(c->n_el==0)     //Si no hi ha cap element esta buit
    {
          r=true;
    }
    return r;
}

bool afegir(cjt_paraules_t *c, char p[])
{

    int i;
    bool r =true;
    n_elems(c); //obtenim num d'elements

        //bucle per mirar que les lletres siguin minuscules o numeros
        i=0;
        while (i<(c->n_el+1) && (r!=false) ) //fa el bucle mentre i sigui menor que el num d'elements mes 1 i mentre sigui true.
        {
              if ((((int)p[i]<48) && ((int)p[i]>57)) || (((int)p[i] <97) && ((int)p[i] >122))) //comprova comparant amb el codi ascii
                {
                    r= false;//si es compleix una de les condicions retorna fals
                }
                i++;
        }

            if(ple(c)||(strlen(p)>=8)|| pertany(c, p)) r=false; //si esta ple o la paraula es mes llarga del indicat o ia pertany retorna false
            else
                {
                    c->paraules[c->n_el]=(char*)malloc(sizeof(char)*(strlen(p)+1)); //obra l'espai per memoria dinamica char * cadena + 1
                    strcpy(c->paraules[c->n_el], p); //copia la paraula a la cadena
                    c->n_el++; //suma elements
                }
    return r;

}
void eliminar(cjt_paraules_t *c, char p[])
{
    int i, posicio;
    n_elems(c); //reb els elements que hi ha

    if (!buit(c) && pertany(c, p)) // si no esta buit i pertany
    {
        i=0;
        posicio=0; // variable per obtenir la posicio a on esta.
    	while(strcmp(c->paraules[i], p)!=0)  //mentre les paraules siguin diferents fa el bucle
    	{
         	if(strcmp(c->paraules[i], p)==0) //quan siguin iguals guardem la posicio.
        	{
                posicio=i; //posicio de la paraula a eliminar
        	}
        	i++;
    	}
    	free(c->paraules[c->n_el]); //eliminem la paraula
    	c->n_el--;
    	//borra la paraula i restem un element

    	for(i=posicio; i<(c->n_el); i++)
    	{
        	c->paraules[i]= c->paraules[i+1]; //movem tot una posicio enrere
    	}
	}

}
//obtenim numero d'elements
int n_elems(cjt_paraules_t *c)
{
    return(c->n_el);
}
//procediment per mostra
void mostrar(cjt_paraules_t *c)
{
    for(int i=0; i<c->n_el; i++)
    {
        printf("%s", c->paraules[i]);
        printf("\n");
    }

}
