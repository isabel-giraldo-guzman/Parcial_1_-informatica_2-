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

 /*  //esto es para luego
   for (unsigned long long i=1;i<=cant_materias;i++)
    {//toca meter en ciclo a nomb_cod
   bool existe=false;
   while(existe==false){
    cout << "ingrese el nombre/codigo de una de las materias que matriculo: " << "\n";
    int nomb_cod_mat;
    char nom_cod_m[max_tam];
   cin >> nomb_cod_mat;
   existe=existe_cod(puntero_finalV2,nomb_cod_mat,caracter_salto_linea,max_tam);
   if(existe==false){cout<<"el codigo no existe"<<endl;}//no existe
   //if para cuando existe cambiar existe a true
   else {
//void codigo_int_a_char(nomb_cod_mat,nomb_cod_mat,max_tam);//la funcion para pasar codigo numero a char
//print
   }
   }

    //verificamos si el codigo existe si no deveriamos volver a preguntar
    //una de las maneras es bajandle i-- para que no aumente si no es correcto el codigo
    //se podria dar a elegir en otro if si quiere registrar, o no una materia
    //si existe agg la materia en la matriz tem materias
    //devulve un true si existe y un false si no

    cout<<"cuantos dias a la semana ve esta materia: "<< "\n";
    int cant_dias;
    cin>>cant_dias;
    if (cant_dias<=7)
    {
    for (int i=1;i<=cant_dias;i++) //pregunta que dias se ve esa materia segun el numero de veces que ve la materia en la semana
    {
    cout<<"ingrese el dia en el que ve esa materia siendo el Lunes=1 Martes=2 Miercoles=3 Jueves=4 Viernes=4 Sabado=5 Domingo=6: "<< "\n";
    int dia_clase;
    cin>> dia_clase;
    cout<<"ingrese la hora de inicio de la clase en horario militar: "<< "\n";
    int in_clase;
    cin>> in_clase;//verificar las horas de estudio que pida de nuevo la informacion
    if (in_clase>=6 and in_clase<=22)
    {
    cout<< "ingrese la hora de finalizacion de la clase en horario militar: "<< "\n";
    int fin_clase;
    cin>> fin_clase;

    //condiciones// en las condiciones llenamos la matriz 0 para la primer materia
    //1 segunda materia etc
    if (fin_clase<6 and fin_clase>22)
    {
    if (in_clase<fin_clase)
    {
    int horas_t_clase=fin_clase-in_clase;
    //hacemos matriz materias dias+1(7)-(11)
    //funcion materias[cantidad_materias][]
    cout<<"las horas de clase totales son: "<<horas_t_clase<< "\n";
    int horas_t_semana=0;
    horas_t_semana=horas_t_semana + horas_t_clase;
    //int horas_ttss= horas_t_semana+horas_t_clase; //mirar error
    cout<<"las horas de clase totales de esa materia en la semana son: "<<horas_t_semana<< "\n";

    }
    else
    {

        cout<<"ingrese ingrese un horario valido de clase(el inicio de clase no puede estar despues del final de clase): "<< "\n";
        cout<<"ingrese la hora de inicio de la clase: "<< "\n";
    int in_clase;
    cin>> in_clase;
    cout<< "ingrese la hora de finalizacion de la clase: "<< "\n";
    int fin_clase;
    cin>> fin_clase;
    }
    }
    }
    else
    {
     cout<<"el primer horario donde se brinda clase en la universidad es a las 6" << "\n";
    }
    }
    }
    else
     {
     cout<<"No es posible ver una materia mas de 7 dias en una semana"<< "\n";
     }
    }/*/
//liveramos la memoria

   //horary

liberarMemoria_horario_int(horario,tamaño_Caracter_matriz,dias+1,hora_total+1);
//aqui colocamos la llave del if
    }
//matriz
liberarMemoria_matriz_3(matriz,tamaño_Caracter_matriz,conjuntos,caracter_salto_linea);

}
