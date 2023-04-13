#include "funciones_parcial.h"
#include <iostream>
#include <fstream>
using namespace std;
unsigned long long tamaño_pensum(){
    unsigned long long tamaño=0;
    fstream base_de_datos;
    base_de_datos.open("D:/Pensum.txt",ios::in | ios::binary | ios::ate);
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
/*
char* leer_pensum(unsigned long long tamaño,char datos[tamaño]){
char linea[500];//toca darle una cantidad para poder inicializarlo entonces estamos diciendo que cada linea no tiene mas de 500 caracteres
char letra;
//    char name_text[1000];//estamos diciendo que el nombre del texto no puede tener mas de 1000 caracteres
//    int tamaño_nombre_pensum=0;
//    cout<<"ingrese el lugar donde esta guardado el pensum: "<<endl;
//    cin>>name_text;
//    for(int i=0;name_text[i]!='\0';i++){cout<<name_text[i];tamaño_nombre_pensum++;}
//    char name_texto[tamaño_nombre_pensum];
//    for (int k=0;k<tamaño_nombre_pensum;k++){name_texto[k]=name_text[k];}// para imprimir la ruta
//    cout<<endl;
    fstream base_de_datos;

//    base_de_datos.open(name_texto,ios::in | ios::binary | ios::ate);//parametro de entrada binario y coloca el cursor al final del texto
    base_de_datos.open("D:/Pensum.txt",ios::in | ios::binary | ios::ate);

    if(base_de_datos.is_open()){

        for(unsigned long long i=0;i<tamaño;i++)
        {
            base_de_datos.get(letra);//asigna a letra el caracter en esa posicion
            datos[i]=letra;
        }
         base_de_datos.close();
         return datos;
    }

    else {char datoss[0];
    datoss[0] = '\0';cout<<"Error de Lectura"<<endl;}
    base_de_datos.close();
    return datoss;

}*/
void leer_pensum2(unsigned long long  tamaño,char* datoss){
char letra;
char datos[tamaño];
    fstream base_de_datos;
    base_de_datos.open("D:/Pensum.txt",ios::in | ios::binary | ios::ate);
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

