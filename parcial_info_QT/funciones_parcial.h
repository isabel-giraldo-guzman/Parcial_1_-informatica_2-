#ifndef FUNCIONES_PARCIAL_H
#define FUNCIONES_PARCIAL_H
unsigned long long tamaño_pensum(char*nom_pensum);

void incicializar_arreglo_char(char*arreglo,unsigned long long tamaño_inic,char caracter);
void leer_pensum1(unsigned long long  tamaño,char* datoss,char* pensum_nombre);
void leer_pensum2(unsigned long long  tamaño,char* datoss,char* nombre);
unsigned long long tamaño_nombre_archivo(char* archivo);
char* nombre_archivo(char* nombrefinal,char *nombre,unsigned long long tamaño_text_archivo);
unsigned long long caracter_numero(char*datos,char caracter,unsigned long long tamaño_archivo);
void incicializar_arreglo_char_m_n(char(*arreglo)[5],unsigned long long tamaño_m,unsigned long long tamaño_n,char caracter_inic);
void separar_archivo_fin(unsigned long long  tamaño,unsigned long long tamaño_m,unsigned long long tamaño_n,char(*arreglo)[5],char*archivo);
unsigned long long tamaño_max_for(char* archivo,char caracter,unsigned long long cantidad_ln);
void separar_char_ln(char** separar_lineas,unsigned long long cantidad_salto_linea,unsigned long long max_tam_matriz, char caracter,char* archivo);
unsigned long long tamaño_matriz_conjuntos_punto_c(char **matriz,char caracter,unsigned long long cantidad_ln);

void matriz_separada(char**** matriz_punter,char**spp_lineas,unsigned long long tamaño_Caracter_matriz,unsigned long long caracter_salto_linea,int conjuntos,unsigned long long max_tamaño);
void matriz_separada_imprimir(char*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);
void matriz_separada_imprimirV2(char**** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);

void inc_matriz_3(char****matriz,unsigned long long tamaño_Caracter_matriz,int conjuntos,unsigned long long caracter_salto_linea);
void liberarMemoria_matriz_3(char*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);

char*** matriz_separada_v2(char*** matriz_punter,char**spp_lineas,unsigned long long tamaño_Caracter_matriz,unsigned long long caracter_salto_linea,int conjuntos,unsigned long long max_tamaño);

void inc_matriz_horario(char**** matriz, unsigned long long tamaño_materia, int dias, unsigned long long horas, unsigned long long hora_inicio, unsigned long long hora_fin);
void liberarMemoria_horario_int(unsigned long long*** matriz, unsigned long long tamaño_Caracter_matriz, int conjuntos, unsigned long long caracter_salto_linea);

bool existe_cod(char****pensum,int codigo_materia,unsigned long long materias_pensum,unsigned long long tam_c_pensum);

void imp_horario(unsigned long long *** horario,unsigned long long hora_total,int dias,unsigned long long tamaño_Caracter_matriz,unsigned long long hora_inic,unsigned long long hora_fin);
void inicializar_horary(unsigned long long**** horary, unsigned long long tamaño, int dias, unsigned long long horas_total);

#endif // FUNCIONES_PARCIAL_H
