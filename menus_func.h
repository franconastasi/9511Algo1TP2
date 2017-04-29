#ifndef MENUSFUNC__H
#define MENUSFUNC__H

void imprimir_menu_inicial(void);
void imprimir_menu_principal(void);
void pedir_tiempo_inicial(float * ti);
void pedir_tiempo_final(float* ti, float* tf);
void pedir_muestreo(int* muestreo);
void pedir_precision(int* precision);
void imprimir_menu_funciones(void);
void imprimir_menu_finalizado_muestreo(void);
void confirmar_parametros(int * confirmacion, e_estado* estado);


#endif
