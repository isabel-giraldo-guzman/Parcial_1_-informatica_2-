#include <iostream>
#include "funciones_parcial.h"
using namespace std;

unsigned long long tamaño_pensum();
void leer_pensum2(unsigned long long tamaño,char* datoss);

int main()
{
    unsigned long long tamaño=0;
    tamaño=tamaño_pensum();
    char datos[tamaño];
    for(unsigned long long i=0;i<tamaño;i++){datos[i]=' ';}
    char *datoss;
    datoss=&datos[0];
    leer_pensum2(tamaño,datoss);
    for(unsigned long long i=0;i<tamaño;i++){cout<<*(datos+i);}
    return 0;
}
