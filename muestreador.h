#ifndef MUESTREADOR__H
#define MUESTREADOR__H 

#include <stdio.h>
#include <stdlib.h>
#include "opciones.h"
#include "contantes.h"
#include "lenguage.h"
#include "estados.h"




void muestrear_senoidal (int muestreo, int precision, float ti,float delta_t);
void muestrear_log_10 (float* ti, float* tf, float* delta_t, int muestreo, int precision);
void muestrear_log_lineal(float* ti, float* tf, float* delta_t, int muestreo, int precision);
void muestrear_expon (int muestreo, int precision, float ti,float delta_t);
void muestrear_escalon (int muestreo, int precision, float ti, float delta_t);
void muestrear_mrua (int muestreo,int precision,float ti,float delta_t);
void muestrear_parh (int muestreo,int precision,float ti,float delta_t);
void imprimir_muestreo_log_10 (int muestreo, int precision, float ti,float delta_t);
void imprimir_muestreo_loglineal (int muestreo, int precision, float ti,float delta_t);

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
