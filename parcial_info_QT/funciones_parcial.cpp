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
char letra;
char datos[tamaño];

    fstream base_de_datos;

    base_de_datos.open(pensum_nombre,ios::in | ios::binary | ios::ate);//parametro de entrada binario y coloca el cursor al final del texto


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


                    for(unsigned long long pass=0;pass<g+1;pass++){
                                            matriz_temp[i][k][pass]=grupitos[pass];
                                            (*(*(*(*(matriz_punter)+i)+k)+pass))=grupitos[pass];
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

                    }

            }

        }}}


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

void inicializar_horary(unsigned long long**** horary, unsigned long long tamaño, int dias, unsigned long long horas_total) {
    for (unsigned long long i = 0; i <= horas_total; i++) {
        (*horary)[i] = new unsigned long long*[dias + 1];
        for (int j = 0; j <= dias; j++) {
            (*horary)[i][j] = new unsigned long long[tamaño];
            for (unsigned long long k = 1; k < tamaño; k++) {
                ((*horary)[i][j][0]) = 0;
                ((*horary)[i][j][k]) = '\0';
            }
        }
    }
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

bool existe_cod(char****pensum,int codigo_materia,unsigned long long materias_pensum,unsigned long long tam_c_pensum){
    char codigo_m[tam_c_pensum];
    char codigo_mf[tam_c_pensum];
    unsigned long long contador=0,cd=codigo_materia;
    for(unsigned long long i=0;i<tam_c_pensum;i++){codigo_m[i]='\0';codigo_mf[i]='\0';}
    //pasamos de int a char modificar int por numero mas grande

    while ((cd > 0) and (contador < tam_c_pensum)) { // Asegurar que cd sea mayor a 0 y contador esté dentro de los límites del arreglo
        int modulo = cd % 10;
        codigo_m[contador] = modulo + 48;
        cd = cd / 10;
        contador++; // Incrementar contador en cada iteración
    }
    for(int voltear=0,n=1;voltear<contador;voltear++,n++){
        codigo_mf[voltear]=codigo_m[contador-n];}
codigo_mf[contador]='\0';//le colocamos el valor nulo para decir que se termina el arreglo

    unsigned long long contador2=contador;
    for(unsigned long long materias=0;materias<materias_pensum;materias++){
        for(unsigned long long codigo=0,contador2=contador;((*pensum)[materias][0][codigo])!='\0';codigo++)//la posicion 0 es la del codigo
            if (((*pensum)[materias][0][codigo])==(codigo_mf[codigo])){
                contador2--;
            if((contador2==0) and (((*pensum)[materias][0][codigo+1])=='\0')){return true;}
            }
    }
    return false;
}
void imp_horario(unsigned long long *** horario,unsigned long long hora_total,int dias,unsigned long long tamaño_Caracter_matriz,unsigned long long hora_inic,unsigned long long hora_fin){
int diass=0;
    for(unsigned long long i=0;i<hora_total+1;i++){
    for(int j=0;j<dias+1;j++){



        for(unsigned long long k=0;k<tamaño_Caracter_matriz;k++){
            if(i>0 and j>0){horario[i][j][k]=0;
            horario[i][j][k+1]='\0';
            cout<<horario[i][j][k];
            k=tamaño_Caracter_matriz;}
           if(i==0 and j==0){horario[i][j][k]='\0';
           cout<<"H-D  ";
           k=tamaño_Caracter_matriz;}
            if(i>0 and j==0){
                cout<<endl;
                horario[i][j][k]=hora_inic;
                horario[i][j][k+1]=hora_inic+1;
                horario[i][j][k+2]='\0';
                hora_inic++;
                if(horario[i][j][k]<9){cout<<"0"<<horario[i][j][k]<<'-'<<"0"<<horario[i][j][k+1]<<" ";}
                else if((horario[i][j][k]==9)){cout<<"0"<<horario[i][j][k]<<'-'<<horario[i][j][k+1]<<" ";}
                else{
                cout<<horario[i][j][k]<<'-'<<horario[i][j][k+1]<<" ";}
                k=tamaño_Caracter_matriz;
            }
            if(i==0 and j>0){
                horario[i][j][k]=diass;
               // cout<<horario[i][j][k];//aqui toma un valor numerico
                if((horario[i][j][k]==0)){cout<<"L";}
                else if((horario[i][j][k]==1)){cout<<"M";}
                else if((horario[i][j][k]==2)){cout<<"W";}
                else if((horario[i][j][k]==3)){cout<<"J";}
                else if((horario[i][j][k]==4)){cout<<"V";}
                else if((horario[i][j][k]==5)){cout<<"S";}
                else if((horario[i][j][k]==6)){cout<<"D";}
                diass++;
                //cout<<" ";
                k=tamaño_Caracter_matriz;


        }
    }cout<<"  ";
}cout<<endl;
}
}
void imp_horarioV2(unsigned long long *** horario,unsigned long long hora_total,int dias,unsigned long long tamaño_Caracter_matriz,unsigned long long hora_inic,unsigned long long hora_fin){
int diass=0;
    for(unsigned long long i=0;i<hora_total+1;i++){
    for(int j=0;j<dias+1;j++){if(j==1){j++;}
        if((j==0) and (i==0)){cout<<" H-D ";}
        else if((i==0) and (j==2)){cout<<"L";}
        else if((i==0) and (j==3)){cout<<"M";}
        else if((i==0) and (j==4)){cout<<"W";}
        else if((i==0) and (j==5)){cout<<"J";}
        else if((i==0) and (j==6)){cout<<"V";}
        else if((i==0) and (j==7)){cout<<"S";}
        else if((i>0)and(j==0)){if(horario[i][j][0]<9){cout<<"0"<<horario[i][j][0]<<"-"<<"0"<<((horario[i][j][0])+1);}
            else if(horario[i][j][0]==9){cout<<"0"<<horario[i][j][0]<<"-"<<((horario[i][j][0])+1);}
                    else{cout<<horario[i][j][0]<<"-"<<((horario[i][j][0])+1);

        }
        }
        else{

               cout << horario[i][j][0];}
    cout<<" ";}

cout<<endl;
}}

bool abrio_archivo(char *nombre_pensum){
    fstream base_de_datos;
    base_de_datos.open(nombre_pensum,ios::in | ios::binary | ios::ate);
    if(base_de_datos.is_open()){
        //tamaño=base_de_datos.tellg();//toma la longitud de datos hasta donde se encuentra el cursor
        //base_de_datos.seekg(0);//colocamos el puntero en la primer posicion
         base_de_datos.close();
        return true;
        }
    else {
         base_de_datos.close();
    return false;
}}
void codigo_int_a_char(int codigo_materia,char*materias_pensum, unsigned long long tam_c_pensum){
    char codigo_m[tam_c_pensum];
    //char codigo_mf[tam_c_pensum];
    unsigned long long contador=0,cd=codigo_materia;
    for(unsigned long long i=0;i<tam_c_pensum;i++){codigo_m[i]='\0';*(materias_pensum+i)='\0';}
    //pasamos de int a char modificar int por numero mas grande

    while ((cd > 0) and (contador < tam_c_pensum)) { // Asegurar que cd sea mayor a 0 y contador esté dentro de los límites del arreglo
        int modulo = cd % 10;
        codigo_m[contador] = modulo + 48;
        cd = cd / 10;
        contador++; // Incrementar contador en cada iteración
    }
    for(int voltear=0,n=1;voltear<contador;voltear++,n++){
        *(materias_pensum+voltear)=codigo_m[contador-n];}

    *(materias_pensum+contador)='\0';//le colocamos el valor nulo para decir que se termina el arreglo

}

void datos_materias(char****pensum,char****materias,unsigned long long****horario,unsigned long long lineas,int grupos,unsigned long long tam_max,unsigned long long cant_materias,int hora_inicio_estudio,int hora_fin_estudio){
        int hora_total=(hora_fin_estudio-hora_inicio_estudio);
        int horas_t_clase=0,horas_materia=0,dia_clase,nomb_cod_mat,cant_dias,in_clase,fin_clase,materia_orden=0;
        char codigo_char[tam_max];
        for (int i=0,materia_orden=1;i<=cant_materias;i++,materia_orden++)
         {horas_materia=0;
            bool existe=false;
            while(existe==false){
         cout << "ingrese el nombre/codigo de una de las materias que matriculo: " << "\n";

         cin >> nomb_cod_mat;
         //mirar si ese codigo o nombre de la materia si esta en el pensum
         existe=existe_cod(pensum,nomb_cod_mat,lineas,tam_max);
         if(existe==false){cout<<"el codigo no existe"<<endl;}//no existe
         else {cout<<"se encontro la materia"<<endl;
        codigo_int_a_char(nomb_cod_mat,codigo_char,tam_max);//la funcion para pasar codigo numero a char
        //fincion que nos de la pocicion del codigo de materia del pensum para guardarlo
        //en la matriz materias matriculadas
         }}
         cout<<"cuantos dias a la semana ve esta materia: "<< "\n";

         cin>>cant_dias;
         while(cant_dias>6 or cant_dias<=0)
         {
             cout<<"ingrese una cantidad de dias valida maximo 6 minimo 1 (solo se ven clases de lunes a sabado): "<<"\n";
             cin>>cant_dias;
         }
         if(cant_dias<=6 and cant_dias>0)//solo se ve clase de lunes a sabado
         {
         for (int i=0;i<cant_dias;i++) //pregunta que dias se ve esa materia segun el numero de veces que ve la materia en la semana
         {
         cout<<"ingrese el dia en el que ve esa materia siendo el Lunes=1 Martes=2 Miercoles=3 Jueves=4 Viernes=5 Sabado=6: "<< "\n";
         cin>> dia_clase;

         while ((dia_clase <1) or (dia_clase>6))
         {
             cout<<"ingrese un numero valido"<<"\n";
             cin>>dia_clase;
         }
         if ((dia_clase>=1) and (dia_clase<=6))
         {
         cout<<"ingrese la hora de inicio de la clase en horario militar: "<< "\n";
         cin>> in_clase;
         cout<< "ingrese la hora de finalizacion de la clase en horario militar: "<< "\n";

         cin>> fin_clase;
         while (in_clase>=fin_clase)
         {
         cout<<"ingrese un horario de inicio de clase y de finalizacion de clase valido (la hora de inicio no puede ser mayor que la hora de finalizacion)"<<"\n";
         cout<<"ingrese la hora de inicio de la clase en horario militar: "<< "\n";
         cin>> in_clase;
         cout<< "ingrese la hora de finalizacion de la clase en horario militar: "<< "\n";
         cin>> fin_clase;
         }
        //agregamos la condicion por si coloca una hora diferente a la jornada de estudio
         while((in_clase<hora_inicio_estudio)or (fin_clase>hora_fin_estudio)) {
             cout<<"ingrese un horario de inicio de clase y de finalizacion de clase valido hora inicio y hora fin no pueden ser mayor o menor a la jornada de estudio"<<"\n";
             cout<<"La jornada de estudio es de: "<<hora_inicio_estudio<<"horas hasta "<<hora_fin_estudio<<"horas"<<endl;
             cout<<"ingrese la hora de inicio de la clase en horario militar: "<< "\n";
             cin>> in_clase;
             cout<< "ingrese la hora de finalizacion de la clase en horario militar: "<< "\n";
             cin>> fin_clase;
               if(in_clase>=fin_clase){cout<<"el horario de inicio de clase nuepuede ser mayor que el de fin de clases"<<endl;
         in_clase=hora_inicio_estudio-1;
         fin_clase=hora_fin_estudio+1;
         }
         }
         }
          if (in_clase<fin_clase and in_clase>=hora_inicio_estudio and fin_clase<=hora_fin_estudio)
         {
              horas_materia=horas_materia+(fin_clase-in_clase);

         horas_t_clase=horas_t_clase +(fin_clase-in_clase);//horas de claseeee
         cout<<"horas totales de la materia son: "<<horas_materia<<endl;
         cout<<"las horas de clase totales son: "<<horas_t_clase<< "\n";
         //agregamos horario a matriz
         int hora_clase=0;
         hora_clase=(in_clase - hora_inicio_estudio);
         int hora_materia_dia=fin_clase-in_clase;
         for(int k=0;k<hora_materia_dia;k++){

         (*horario)[(hora_clase+1)+k][dia_clase+1][0]=materia_orden;
             in_clase=0;
         //cout<<(*horario)[dia_clase+1][(hora_clase+k)][0]<<endl;
         }
         //in_clase++;//inclase va a estar limitado por horas de estudio
//imprimimos para ver si se guardo
         imp_horarioV2(*horario,hora_total,7,tam_max,hora_inicio_estudio,hora_fin_estudio);
         }
         }

         }//cierre while escoger dia clase
         }

    }

