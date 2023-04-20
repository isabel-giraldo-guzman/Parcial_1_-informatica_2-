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

unsigned long long tamaño_max_for(char* archivo,char caracter,unsigned long long cantidad_ln){
 unsigned long long tamaño,tamaño2=0,tamaño3=0;
 for(tamaño=0;cantidad_ln>0;tamaño++,tamaño3++){
     if(*(archivo+tamaño3)==caracter){
         if(tamaño2<tamaño){tamaño2=tamaño;}
     cantidad_ln--;
     tamaño=0;
     }}
 return tamaño2;
}

void separar_char_ln(char** separar_lineas,unsigned long long cantidad_salto_linea,unsigned long long max_tam_matriz, char caracter,char* archivo){
    unsigned long long contador=0,m,r;
    for(unsigned long long i=0;i<cantidad_salto_linea;i++){
        for(unsigned long long k=0;k<max_tam_matriz;k++){separar_lineas[i][k]='\0';}
    }
    for(unsigned long long i=0;0<cantidad_salto_linea;i++){
        for(unsigned long long k=0;k<max_tam_matriz;k++,contador++){
       if(archivo[contador]==caracter){if(k%max_tam_matriz!=0){
               //antes de cada salto de linea hay \r y luego \n que nos expresa un enter
               separar_lineas[i][k-1]='\0';//le comocamos un caracter nulo para indicar que finaliza el arreglo
               r=k%max_tam_matriz;
               m=max_tam_matriz-r;
               k=k+m;
           }
           cantidad_salto_linea--;
       }
       else{separar_lineas[i][k]=archivo[contador];
       //cout<<separar_lineas[i][k];
       }
        }
    //cout<<endl;
    }
// esta la podemos eliminar creo ya que modificamos anteriormente el \r
   /* for(unsigned long long i=0;i<cantidad_salto_linea;i++){
        for(unsigned long long k=0;k<max_tam_matriz;k++){

            if(separar_lineas[i][k]=='\r'){separar_lineas[i][k]='\0';}}
    }*/
    for(unsigned long long i=0;i<cantidad_salto_linea;i++){
        for(unsigned long long k=0;k<max_tam_matriz;k++){cout<<separar_lineas[i][k];}
       // cout<<endl;
    }

}

unsigned long long tamaño_matriz_conjuntos_punto_c(char **matriz,char caracter,unsigned long long cantidad_ln){
    unsigned long long tamaño2=0,tamaño3=0,cantidad_p_c=5;
    caracter=',';
    /*for(unsigned long long i=0;i<cantidad_ln;i++){
        for(unsigned long long k=0;matriz[i][k]!='\0';k++){
            if(matriz[i][k]=';'){cantidad_p_c++;}
        }
    }*/


    for(unsigned long long tamaño=0;tamaño<cantidad_ln;tamaño++){
        tamaño2=tamaño_max_for(matriz[tamaño],caracter,cantidad_p_c);//cantidad_ln ahora debe ser ;
        if(tamaño3<tamaño2){tamaño3=tamaño2;}
    }
    return tamaño3;

}
void matriz_separada(char**** matriz_punter,char**spp_lineas,unsigned long long tamaño_Caracter_matriz,unsigned long long caracter_salto_linea,int conjuntos,unsigned long long max_tamaño){
    //inicializamos el puntero  no la podemos inicializar aqui
   /* for (unsigned long long i = 0; i < caracter_salto_linea; ++i) {
        (*matriz_punter)[i] = new char*[conjuntos];
        for (int j = 0; j < conjuntos; ++j) {
            (*matriz_punter)[i][j] = new char[tamaño_Caracter_matriz];
            for (unsigned long long k = 0; k < tamaño_Caracter_matriz; ++k) {
                (*matriz_punter)[i][j][k] = '\0'; // asignación de valores este caso caracter nulo
            }
        }
    }
*/
    char matriz_temp[caracter_salto_linea][conjuntos][max_tamaño];//mirar luego el max tamaño
    //inicializamos la matriz
    for(unsigned long long fila=0;fila<caracter_salto_linea;fila++){
     for(unsigned long long columna=0;columna<conjuntos;columna++){
         for(unsigned long long caracter=0;caracter<max_tamaño;caracter++){
             matriz_temp[fila][columna][caracter]='\0';
         }
     }
    }
    char grupitos[max_tamaño];
    for(unsigned long long reset=0;reset<max_tamaño;reset++){
        grupitos[reset]='\0';
    }
    unsigned long long z,g,comas=0;
    for(unsigned long long i=0;i<caracter_salto_linea;i++){

        for(unsigned long long k=0,z=0,comas=0;k<conjuntos;z++,k++){//maximo tamaño de los conjuntos
           // probar con max_tamaño
            for(unsigned long long p=0,g=0;p<max_tamaño;p++,g++,z++){

                if(spp_lineas[i][z]==',' or (spp_lineas[i][z]=='\0' and conjuntos==(comas+1))){
                    grupitos[g+1]='\0';
                   /* for(unsigned long long pass=0;pass<g+1;pass++){
                        (*(*(*(*(matriz_punter)+i)+k)+pass))=grupitos[pass];
                    }
                   //(*(*(matriz_punter+i)+k)=grupitos;
                    //(*(*(*(matriz_punter)+i)+k))=grupitos;*/
                    //matriz_temp[i][k]=grupitos;

                    for(unsigned long long pass=0;pass<g+1;pass++){
                                            matriz_temp[i][k][pass]=grupitos[pass];
                                            (*(*(*(*(matriz_punter)+i)+k)+pass))=grupitos[pass];
                                           // for(unsigned long long l=g+1;l<max_tamaño;l++){matriz_temp[i][k][pass]='\0';}
                                        }

                    for(unsigned long long reset=0;reset<g;reset++){grupitos[reset]='\0';}

                    p=max_tamaño;
                    //cout<<"  ";
                    z=z-1;
                    g=-1;
                    comas++;
                    //k++;
                }
                else{if ((spp_lineas[i][z] >= 'A' and spp_lineas[i][z] <= 'Z') or
                         (spp_lineas[i][z] >= 'a' and spp_lineas[i][z] <= 'z') or
                         (spp_lineas[i][z] >= '0' and spp_lineas[i][z] <= '9') or
                         (spp_lineas[i][z] == ' ') or spp_lineas[i][z] <= 'ñ' or
                         spp_lineas[i][z] <= 'Ñ'){

                        grupitos[g]=spp_lineas[i][z];
                        //cout<<grupitos[g];
                    //(*(*(*(*(matriz_punter)+i)+k)+g))=(grupitos[g]);
                    }

            }
            //cout<<"--";
        }}}
       // cout<<endl;}
    //imprimimos la matriz temporal

   /*     for(unsigned long long fila=0;fila<caracter_salto_linea;fila++){
         for(unsigned long long columna=0;columna<conjuntos;columna++){
             for(unsigned long long caracter=0;caracter<max_tamaño;caracter++){
                 if((*(*(*(*(matriz_punter)+fila)+columna)+caracter))=='\0'){caracter=max_tamaño;}
                 else{
                 cout<<(*(*(*(*(matriz_punter)+fila)+columna)+caracter));}
             }cout<<" ";
         }cout<<endl;
}  */     //pasamos lo de la matriz temporal a nuestro puntero
   /*     for(unsigned long long fila=0;fila<caracter_salto_linea;fila++){
            for(unsigned long long columna=0;columna<conjuntos;columna++){
                for(unsigned long long caracter=0;caracter<max_tamaño;caracter++){
                   (*(*(*(*(matriz_punter)+fila)+columna)+caracter))=matriz_temp[fila][columna][caracter];

                    /*if(matriz_temp[fila][columna][caracter]=='\0'){
                        (*(*(*(*(matriz_punter)+fila)+columna)+caracter))='\0';
                        caracter=max_tamaño+1;
                    } else {
                        (*(*(*(*(matriz_punter)+fila)+columna)+caracter))=matriz_temp[fila][columna][caracter];
                    }*/
                   // cout<<(*(*(*(*(matriz_punter)+fila)+columna)+caracter));
          //      }
                //cout<<" ";
        //    }
            //cout<<endl;
      //  }     */

}

//intentemolos devolviendo la matriz a ver que pedo
char*** matriz_separada_v2(char*** matriz_punter,char**spp_lineas,unsigned long long tamaño_Caracter_matriz,unsigned long long caracter_salto_linea,int conjuntos,unsigned long long max_tamaño){
    char grupitos[max_tamaño];
    for(unsigned long long reset=0;reset<max_tamaño;reset++){
        grupitos[reset]='\0';
    }
    unsigned long long z,g,comas=0;
    for(unsigned long long i=0;i<caracter_salto_linea;i++){

        for(unsigned long long k=0,z=0,comas=0;k<conjuntos;z++,k++){//maximo tamaño de los conjuntos
           // probar con max_tamaño
            for(unsigned long long p=0,g=0;p<max_tamaño;p++,g++,z++){

                if(spp_lineas[i][z]==',' or (spp_lineas[i][z]=='\0' and conjuntos==(comas+1))){
                    grupitos[g+1]='\0';
                   matriz_punter[i][k]=grupitos;

                    for(unsigned long long reset=0;reset<g;reset++){grupitos[reset]='\0';}

                    p=max_tamaño;
                    //cout<<"  ";
                    z=z-1;
                    g=-1;
                    comas++;
                    //k++;
                }
                else{if ((spp_lineas[i][z] >= 'A' and spp_lineas[i][z] <= 'Z') or
                         (spp_lineas[i][z] >= 'a' and spp_lineas[i][z] <= 'z') or
                         (spp_lineas[i][z] >= '0' and spp_lineas[i][z] <= '9') or
                         (spp_lineas[i][z] == ' ')){

                        grupitos[g]=spp_lineas[i][z];
                        cout<<grupitos[g];}}
            }
            cout<<"--";
            }
        cout<<endl;}
    return matriz_punter;
    }

  // seria una matriz[filas][columnas][tamaño de las columnas]
void inc_matriz_3(char****matriz,unsigned long long tamaño_Caracter_matriz,int conjuntos,unsigned long long caracter_salto_linea){
    for (unsigned long long i = 0; i < caracter_salto_linea; ++i) {
        (*matriz)[i] = new char*[conjuntos];
        for (int j = 0; j < conjuntos; ++j) {
            (*matriz)[i][j] = new char[tamaño_Caracter_matriz];
            for (unsigned long long k = 0; k < tamaño_Caracter_matriz; ++k) {
                (*matriz)[i][j][k] = '0'; // asignación de valores
            }
        }
    }
}


void liberarMemoria_matriz_3(char*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea) {
    for (unsigned long long i = 0; i < caracter_salto_linea; ++i) {
        for (int j = 0; j < conjuntos; ++j) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

void liberarMemoria_horario_int(unsigned long long*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea) {
    for (unsigned long long i = 0; i < caracter_salto_linea; ++i) {
        for (int j = 0; j < conjuntos; ++j) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

void matriz_separada_imprimir(char*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea){

    for(unsigned long long fila=0;fila<caracter_salto_linea;fila++){

        for(unsigned long long columna=0;columna<conjuntos;columna++){

            for(unsigned long long tamaño_caracteres=0;matriz[fila][columna][tamaño_caracteres]=!'\0';tamaño_caracteres++){
                cout<<matriz[fila][columna][tamaño_caracteres];
            }
            cout<< "||";
        }
          cout<< "__";
    }
}

void matriz_separada_imprimirV2(char**** puntero, unsigned long long tamaño, int columnas, unsigned long long filas) {
    for(unsigned long long fila=0;fila<filas;fila++){
             for(unsigned long long columna=0;columna<columnas;columna++){
                 for(unsigned long long caracter=0;caracter<tamaño;caracter++){
                     if((*(*(*(*(puntero)+fila)+columna)+caracter))=='\0'){caracter=tamaño;}
                     else{
                     cout<<(*(*(*(*(puntero)+fila)+columna)+caracter));}
                 }cout<<" ";
             }cout<<endl;
    }
}

void inc_matriz_horario(char**** matriz, unsigned long long tamaño_materia, int dias, unsigned long long horas, unsigned long long hora_inicio, unsigned long long hora_fin) {
    for (unsigned long long k = 0; k < horas; k++) {
        for (int j = 0; j < dias; j++) {
            for (unsigned long long i = 0; i < tamaño_materia; i++) {
                if (k == 0 && j > 1) {
                    // Corrección en la asignación de valores a la matriz
                    (*(*(*(*(matriz + k) + j) + i))) = hora_inicio;
                    (*(*(*(*(matriz + k) + j) + i) + 1)) = '-';
                    (*(*(*(*(matriz + k) + j) + i) + 2)) = hora_inicio + 1;
                    (*(*(*(*(matriz + k) + j) + i) + 3)) = '\0';

                    cout<<(*(*(*(*(matriz + k) + j) + i) ));
                    cout<<(*(*(*(*(matriz + k) + j) + i) + 1));
                    cout<<(*(*(*(*(matriz + k) + j) + i) + 2));
                    cout<<(*(*(*(*(matriz + k) + j) + i) + 3));
                }
            }
        }
    }
}

