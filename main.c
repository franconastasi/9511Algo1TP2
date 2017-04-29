#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include "muestreador.h"

int main (void)
{
	int num_muestras, precision, opcion_inicio, funcion, menu, confirmacion;
	float ti, tf, delta_t;
	e_estado estado = ST_INITIAL;

	do
	{
		switch (estado)
		{

			case ST_ERROR:
				return EXIT_FAILURE;

			case ST_INITIAL:
				imprimir_menu_inicial();
				if (scanf("%d",&opcion_inicio) != 1)
				{
					fprintf(stderr, "%s\n", MSG_ERROR);
					estado = ST_ERROR;
					break;
				}
				if (opcion_inicio == OPTION_EXIT)	estado = ST_EXIT;
					else	estado = ST_ASK_PARAM;
				break;

			case ST_ASK_PARAM:
				pedir_tiempo_inicial(&ti);
				pedir_tiempo_final(&ti,&tf);
				pedir_muestreo(&num_muestras);
				delta_t = (tf - ti)/num_muestras;
				pedir_precision(&precision);
				confirmar_parametros(&confirmacion);
				break;

			case ST_FUNC_MENU:
				imprimir_menu_funciones();
				scanf ("%d", &funcion);
				switch (funcion)
				{
					case OPTION_EXIT:
						estado = ST_MAIN_MENU;
						break;
					case OPTION_SENO:
						senoidal (num_muestras, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_LOG_10:
						muestrear_log_10 (&ti, & tf, &delta_t, num_muestras, precision);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_LOG_LIN:
						muestrear_log_lineal(&ti, &tf, &delta_t, num_muestras, precision);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_EXP:
						expon (num_muestras, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_ESCALON:
						escalon (num_muestras, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_MRUA:
						mrua (num_muestras, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_PAR:
						parh (num_muestras, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					default: 	
						printf("%s\n", MSG_NUEVO_INGRESO);			
				}
				break;

			case ST_MAIN_MENU:
				imprimir_menu_principal();
				scanf("%d", &menu);
				switch(menu)
				{
					case OPTION_EXIT:
						estado = ST_EXIT;
						break;
					case OPTION_NEW_PARAM:
						estado = ST_ASK_PARAM;
						break;
					case OPTION_SAME_PARAM:
						estado = ST_FUNC_MENU;
						break;
					default: printf("%s\n", MSG_NUEVO_INGRESO);
				}
		}
	}
	while(estado != ST_EXIT);
	return EXIT_SUCCESS;
}


