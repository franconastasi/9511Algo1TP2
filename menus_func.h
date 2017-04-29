#ifndef MENUSFUNC__H
#define MENUSFUNC__H

void imprimir_menu_inicial(void);
void imprimir_menu_principal(void);
void pedir_tiempo_inicial(float * ti);
void pedir_tiempo_final(float* ti, float* tf);
void pedir_muestreo(int* muestreo);
void pedir_precision(int* precision);
void imprimir_menu_funciones(void);
void muestrear_log_10 (float* ti, float* tf, float* delta_t, int muestreo, int precision);
void muestrear_log_lineal(float* ti, float* tf, float* delta_t, int muestreo, int precision);
void imprimir_menu_finalizado_muestreo(void);
void confirmar_parametros(int * confirmacion);


#endif
