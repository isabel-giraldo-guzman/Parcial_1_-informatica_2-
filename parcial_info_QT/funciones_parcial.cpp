#include "funciones_parcial.h"
#include <iostream>
#include <fstream>
using namespace std;
unsigned long long tamaño_pensum(char *nombre_pensum){
    unsigned long long tamaño=0;
    fstream base_de_datos;
    base_de_datos.open(nombre_pensum,ios::in | ios::binary | ios::ate);
    if(base_de_datos.is_open()){
        tamaño=base_de_datos.tellg();//toma la longitud de datos hasta donde se encuentra el cursor
        base_de_datos.seekg(0);//colocamos el puntero en la primer posicion
         base_de_datos.close();
        return tamaño;
        }
    else {
         base_de_datos.close();
    return tamaño;
}}

void leer_pensum1(unsigned long long  tamaño,char* datoss,char* pensum_nombre){
//char linea[500];//toca darle una cantidad para poder inicializarlo entonces estamos diciendo que cada linea no tiene mas de 500 caracteres
char letra;
char datos[tamaño];
    //char name_text[1000];//estamos diciendo que el nombre del texto no puede tener mas de 1000 caracteres
    //int tamaño_nombre_pensum=0;
    //for (long long int numero=0;numero<1000;numero++){name_text[numero]='\0';}//inicializamos toda la matriz con caracter nulo
    //cout<<"ingrese el lugar donde esta guardado el pensum: "<<endl;
    //cin>>name_text;
    //for(int i=0;name_text[i]!='\0';i++){cout<<name_text[i];tamaño_nombre_pensum++;}
    //char name_texto_2[tamaño_nombre_pensum+1];
    //name_texto_2[tamaño_nombre_pensum]='\0';
    //pensum_nombre=&name_text[0];
    //for(int k=0;name_text[k]=!'\0';k++){*(pensum_nombre+k)=name_text[k];}
    //for (int k=0;k<tamaño_nombre_pensum;k++){name_texto_2[k]=name_text[k];}// para imprimir la ruta
    //cout<<endl;
    fstream base_de_datos;

    base_de_datos.open(pensum_nombre,ios::in | ios::binary | ios::ate);//parametro de entrada binario y coloca el cursor al final del texto
 //   base_de_datos.open("D:/Pensum.txt",ios::in | ios::binary | ios::ate);

    if(base_de_datos.is_open()){
        base_de_datos.seekg(0);//colocamos el puntero en la primer posicion
        for(unsigned long long i=0;i<tamaño;i++)
        {
            base_de_datos.get(letra);//asigna a letra el caracter en esa posicion
            datos[i]=letra;
        }

         for (unsigned long long i=0;i<tamaño;i++){
             *(datoss+i)=datos[i];
         }
         base_de_datos.close();
         return ;//datoss;
         //return &datos;
    }

    else {
    datos[0] = '\0';cout<<"Error de Lectura"<<endl;}

    for (unsigned long long i=0;i<tamaño;i++){
        *(datoss+i)=datos[i];
    }
    base_de_datos.close();
    return; //datoss;
    //return &datoss;

}
void leer_pensum2(unsigned long long  tamaño,char* datoss,char* nombre){
char letra;
char datos[tamaño];
    fstream base_de_datos;
    base_de_datos.open(nombre,ios::in | ios::binary | ios::ate);
    if(base_de_datos.is_open()){
        base_de_datos.seekg(0);//colocamos el puntero en la primer posicion
        for(unsigned long long i=0;i<tamaño;i++)
        {
            base_de_datos.get(letra);//asigna a letra el caracter en esa posicion
            datos[i]=letra;
        }

         for (unsigned long long i=0;i<tamaño;i++){
             *(datoss+i)=datos[i];
         }
         base_de_datos.close();
         return ;//datoss;
         //return &datos;
    }

    else {
    datos[0] = '\0';cout<<"Error de Lectura"<<endl;}

    for (unsigned long long i=0;i<tamaño;i++){
        *(datoss+i)=datos[i];
    }
    base_de_datos.close();
    return; //datoss;
    //return &datoss;

}

unsigned long long tamaño_nombre_archivo(char* archivo){
    unsigned long long tamaño;
    for(tamaño=0;*(archivo+tamaño)!='\0';tamaño++)
        tamaño++;
        return tamaño;
}
char* nombre_archivo(char* nombrefinal,char *nombre,unsigned long long tamaño_text_archivo){
unsigned long long numero=tamaño_text_archivo-1;

char nombre2[tamaño_text_archivo];
nombre2[numero]='\0';
for(unsigned long long numero3=0;numero3<numero;numero3++){
    nombre2[numero3]=*(nombre+numero3);
}
for(unsigned long long numero3=0;numero3<numero+1;numero3++){
    *(nombrefinal+numero3)=nombre2[numero3];
}
return &nombre2[0];
}
void incicializar_arreglo_char(char*arreglo,unsigned long long tamaño_inic,char caracter){
    for(unsigned long long k=0;k<tamaño_inic;k++){*(arreglo+k)=caracter;}
}
unsigned long long caracter_numero(char*datos,char caracter,unsigned long long tamaño_archivo){
    unsigned long long caracter_n=0;
    for(unsigned long long the_caracter=0;the_caracter<tamaño_archivo;the_caracter++){
    if(*(datos+the_caracter)==caracter){caracter_n++;}
}
return caracter_n;}

void incicializar_arreglo_char_m_n(char(*arreglo)[5],unsigned long long tamaño_m,unsigned long long tamaño_n,char caracter_inic){
    for(unsigned long long i=0;i<tamaño_m;i++){
        for(unsigned long long j=0;j<tamaño_n;j++){
            *(*(arreglo+i)+j)=caracter_inic;
        }
    }
}
//necesitamos archivo, tamaño archivo,tamaño m, tamaño n(5),puntero [5]
void separar_archivo_fin(unsigned long long  tamaño,unsigned long long tamaño_m,unsigned long long tamaño_n,char(*arreglo)[5],char*archivo){
   unsigned long long n=0;
   for(unsigned long long i=0;i<tamaño_m;i++){
       for(unsigned long long j=0;j<tamaño_n;j++){
           *(*(arreglo+i)+j)=*(archivo+n);
           n++;
       }
   }
}

void separar_caracter(unsigned long long  tamaño,char* original,char*separado){

}
