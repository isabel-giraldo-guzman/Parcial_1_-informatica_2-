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
unsigned long long tamaño_max_for(char* archivo,char caracter,unsigned long long cantidad_ln);
void separar_char_ln(char** separar_lineas,unsigned long long cantidad_salto_linea,unsigned long long max_tam_matriz, char caracter,char* archivo);
bool abrio_archivo(char *nombre_pensum);
unsigned long long tamaño_matriz_conjuntos_punto_c(char **matriz,char caracter,unsigned long long cantidad_ln);
void matriz_separada(char**** matriz_punter,char**spp_lineas,unsigned long long tamaño_Caracter_matriz,unsigned long long caracter_salto_linea,int conjuntos,unsigned long long max_tamaño);
void inc_matriz_3(char****matriz,unsigned long long tamaño_Caracter_matriz,int conjuntos,unsigned long long caracter_salto_linea);
void liberarMemoria_matriz_3(char*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);
char*** matriz_separada_V2(char*** matriz_punter,char**spp_lineas,unsigned long long tamaño_Caracter_matriz,unsigned long long caracter_salto_linea,int conjuntos,unsigned long long max_tamaño);
void matriz_separada_imprimirV2(char**** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);
void matriz_separada_imprimir(char*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);
void inc_matriz_horario(char**** matriz, unsigned long long tamaño_materia, int dias, unsigned long long horas, unsigned long long hora_inicio, unsigned long long hora_fin);
bool existe_cod(char****pensum,int codigo_materia,unsigned long long materias_pensum,unsigned long long tam_c_pensum);
void imp_horario(unsigned long long *** horario,unsigned long long hora_total,int dias,unsigned long long tamaño_Caracter_matriz,unsigned long long hora_inic,unsigned long long hora_fin);
void inicializar_horary(unsigned long long**** horary, unsigned long long tamaño, int dias, unsigned long long horas_total);
void liberarMemoria_horario_int(unsigned long long*** horario, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);
void codigo_int_a_char(int codigo_materia,char*materias_pensum, long long tam_c_pensum);
void datos_materias(char****pensum,char****materias,unsigned long long****,unsigned long long lineas,int grupos,unsigned long long tam_max,unsigned long long cant_materias,int hora_inicio_estudio,int hora_fin_estudio);

int main()
{
    unsigned long long tamaño=0;
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
    char *datoss;
    datoss=&datos[0];
    leer_pensum1(tamaño,datoss,nom_pensum);
    //aqui leemos los datos que obtuvimos del archivo
    for(unsigned long long i=0;i<tamaño;i++){cout<<*(datos+i);}//aqui imprimimos lo que se almaceno en datos
    //contador de caracteres especiales
    unsigned long long caracter_salto_linea=0;
    char caracter='\n';
    caracter_salto_linea=caracter_numero(datoss,caracter,tamaño);
    //aqui imprimimos la cantidad de salto de lineas que tiene el archivo
    cout<<caracter_salto_linea<<endl;// miramos el numeros de salto de linea
    char datos_separados[caracter_salto_linea];
    char *saltos_ln=&datos_separados[0];
    incicializar_arreglo_char(saltos_ln,caracter_salto_linea,caracter_inicializador);
    //mayor tamaño entre cada salto de linea
    unsigned long long max_tam=0;
    //aqui nos damos cuenta del tamaño maximo de la columna
    max_tam=tamaño_max_for(datoss,caracter,caracter_salto_linea);
    //separar por salto de linea
    char sp_lineas[caracter_salto_linea][max_tam];
    // inicializamos la matriz
    // llenar la funcion para ln
    char* spp_lineas[caracter_salto_linea];
    for(unsigned long long i=0;i<caracter_salto_linea;i++){spp_lineas[i] = &sp_lineas[i][0];}
    //pasar info al char
    separar_char_ln(spp_lineas,caracter_salto_linea,max_tam,caracter,datoss);
    //ahora separamos por comas..
    unsigned long long tamaño_Caracter_matriz;
    tamaño_Caracter_matriz=tamaño_matriz_conjuntos_punto_c(spp_lineas,caracter,caracter_salto_linea);
    //0-codigo 1-materia 2-creditos 3-hora docente 4- hora autonomas
    int  conjuntos=5;
    char **** puntero_finalV2;
    //hacemos la matriz tridimencional
    char*** matriz = new char**[caracter_salto_linea];
    puntero_finalV2=&matriz;
    //inicializamos la matriz[filas/total salto de linea][grupos][tamaño-grupos]
    inc_matriz_3(&matriz,max_tam,conjuntos,caracter_salto_linea);
    //despues de inicializar la matriz le damos los valores separados en forma matriz[filas][columnas][tam_datos]
    matriz_separada(puntero_finalV2,spp_lineas,tamaño_Caracter_matriz,caracter_salto_linea,conjuntos,max_tam);
    //imprimimos los datos que hemos asignado mediante el puntero en matriz
    matriz_separada_imprimirV2(puntero_finalV2,tamaño_Caracter_matriz,conjuntos,caracter_salto_linea);
    //colocamos condicionpor si nos dan el archivo erroneo-no lee
    if(abrio_archivo(nom_pensum)==true){
    //hacemos la segunda matriz sabemos que son [horas del dia][dias][tamaño max del caracter]
    unsigned long long hora_inic=0,hora_fin=0,hora_total;
    //condiciones para que los numeros sean >0 <24
    cout<<"ingrese hora de inicio de su jornada de estudio semanal y luego la hora que culmina su jornada de estudio"<<endl;
    cin>>hora_inic;
    cin>>hora_fin;
    int dias=7;
    hora_total=hora_fin-hora_inic;//horas totales al dia

//si hacemos como una matriz de numeros tendriamos
// debemos crear horario como puntero tridimencional para poder trabajar con el

unsigned long long*** horario=new unsigned long long**[hora_total + 1];//sumamos 1 para hacer el marco de dias y horas
unsigned long long**** horary;
horary=&horario;
//inicializamos la matriz debe quedar horary[hora_total][dias][max_tam]
inicializar_horary(horary,max_tam,dias,hora_total);

//imprimimos matriz segun nuestros criterios

imp_horario(horario,hora_total,dias,max_tam,hora_inic,hora_fin);

//ahora hacemos el primer modelo el cual lo aplicariamos a una funcion

   cout << "ingrese el numero de materias que matriculo" << "\n";

   unsigned long long cant_materias;
   cin >> cant_materias;

    //hacemos una matriz del tamaño de cantidad de materias matriculado

   //0-codigo 1-materia 2-creditos 3-hora docente 4- hora autonomas ---->>conjuntos

   char*** materias_matriculadas= new char**[cant_materias];

   //inicializamos materias

   inc_matriz_3(&materias_matriculadas,max_tam,conjuntos,cant_materias);

//ahora implementamos la funcion
datos_materias(puntero_finalV2,&materias_matriculadas,horary,caracter_salto_linea,conjuntos,max_tam,cant_materias,hora_inic,hora_fin);

//liveramos la memoria

   //horary

liberarMemoria_horario_int(horario,tamaño_Caracter_matriz,dias+1,hora_total+1);
//aqui colocamos la llave del if
    }
//matriz
liberarMemoria_matriz_3(matriz,tamaño_Caracter_matriz,conjuntos,caracter_salto_linea);

}
