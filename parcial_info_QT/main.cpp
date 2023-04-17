#include <iostream>
#include <fstream>
#include "funciones_parcial.h"
using namespace std;

unsigned long long tamaño_pensum(char*nom_pensum);
void leer_pensum1(unsigned long long  tamaño,char* datoss,char* pensum_nombrtxt);
void leer_pensum2(unsigned long long  tamaño,char* datoss,char* pensum_nombre);
unsigned long long tamaño_nombre_archivo(char* archivo);
char* nombre_archivo(char* nombrefinal,char *nombre,unsigned long long tamaño_text_archivo);
void incicializar_arreglo_char(char*arreglo,unsigned long long tamaño_inic,char caracter);
unsigned long long caracter_numero(char*datos,char caracter,unsigned long long tamaño_archivo);
void incicializar_arreglo_char_m_n(char(*arreglo)[5],unsigned long long tamaño_m,unsigned long long tamaño_n,char caracter_inic);
void separar_archivo_fin(unsigned long long  tamaño,unsigned long long tamaño_m,unsigned long long tamaño_n,char(*arreglo)[5],char*archivo);

int main()
{
    unsigned long long tamaño=0,tamañotxt=0;//este es para el tamaño del prensum y la ruta del pensum
     unsigned long long tamaño_inc=0;//tamaño de arreglo
    char nombre_pensum[1000];
    char*nom_pensum;
    nom_pensum=&nombre_pensum[0];
    tamaño_inc=1000;
    char caracter_inicializador='\0';
    incicializar_arreglo_char(nom_pensum,tamaño_inc,caracter_inicializador);
    cout<<"ingrese la ruta del pensum"<<endl;//D:/Pensum.txt
    cin>>nombre_pensum;

    tamaño=tamaño_pensum(nom_pensum);
    char datos[tamaño];
    for(unsigned long long i=0;i<tamaño;i++){datos[i]=' ';}//inicializamos datos con un espacio
  //char*pensum_nombrtxt;
    char *datoss;
    datoss=&datos[0];
    leer_pensum1(tamaño,datoss,nom_pensum);
    for(unsigned long long i=0;i<tamaño;i++){cout<<*(datos+i);}//aqui imprimimos lo que se almaceno en datos
    //contador de caracteres especiales
    unsigned long long caracter_salto_linea=0;
    char caracter='\n';
    caracter_salto_linea=caracter_numero(datoss,caracter,tamaño);
    cout<<caracter_salto_linea<<endl;// miramos el numeros de salto de linea
    char datos_separados[caracter_salto_linea];
    char *saltos_ln=&datos_separados[0];
    incicializar_arreglo_char(saltos_ln,caracter_salto_linea,caracter_inicializador);


    //char (*arreglo)[5] = datos_separados;//aqui hacemos un puntero a la matriz seriaun puntero a un arreglo de caracteres de longitud 5
    unsigned long long tamaño_m,tamaño_n;
    char caracter_inic;
    tamaño_m=caracter_salto_linea;
    tamaño_n=5;
    caracter_inic=' ';
    incicializar_arreglo_char_m_n(arreglo,tamaño_m,tamaño_n,caracter_inic);
//asignamos los valores a datos separados
    //necesitamos archivo, tamaño archivo,tamaño m, tamaño n(5),puntero [5]
     separar_archivo_fin(tamaño,tamaño_m,tamaño_n,arreglo,datoss);
 // return 0;



}
