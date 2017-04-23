#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "msj_es.h"
#include "funciones.h"
#include "estados.h"
#include "menus_func.h"

int main (void)
{
	int muestreo, precision, menu, funcion, opcion_fin_muestreo, confirmacion;
	float ti, tf, delta_t;
	E_ESTADO estado = ST_INITIAL;

	do
	{
		switch (estado)
		{

			case ST_EXIT_FAILURE:
				return EXIT_FAILURE;

			case ST_INITIAL:
				imprimir_menu_principal();
				if (scanf("%d",&menu) != 1)
				{
					fprintf(stderr, "%s", MSG_ERROR);
					estado = ST_EXIT_FAILURE;
				}
				else 	if (menu == OPTION_EXIT)	estado = ST_EXIT;
					else	estado = ST_ASK_PARAM;
				break;

			case ST_ASK_PARAM:
				pedir_tiempo_inicial(&ti);
				pedir_tiempo_final(&ti,&tf);
				pedir_muestreo(&muestreo);
				delta_t = (tf - ti)/muestreo;
				pedir_precision(&precision);
				printf ("%s\n \n %f \n %f \n %d \n %d \n \n %s\n", MSG_CONFIR1, ti, tf, muestreo, precision, MSG_CONFIR2);	
				scanf ("%d", &confirmacion);
				if (confirmacion)
				{
					estado = ST_FUNC_MENU;
				}
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
						senoidal (muestreo, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_LOG_10:
						muestrear_log_10 (&ti, & tf, &delta_t, muestreo, precision);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_LOG_LIN:
						muestrear_log_lineal(&ti, &tf, &delta_t, muestreo, precision);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_EXP:
						expon (muestreo, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_ESCALON:
						escalon (muestreo, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_MRUA:
						mrua (muestreo, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					case OPTION_PAR:
						parh (muestreo, precision, ti, delta_t);
						estado = ST_MAIN_MENU;
						break;
					default: 	
						printf("%s\n", MSG_NUEVO_INGRESO);			
				}
				break;

			case ST_MAIN_MENU:
				imprimir_menu_finalizado_muestreo();
				scanf("%d", &opcion_fin_muestreo);
				switch(opcion_fin_muestreo)
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

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */



void senoidal (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float freq,Amp,phi,fseno,time;

	printf("%s\n",MSG_SENOIDAL_DESCRIP);

	printf("%s\n",MSG_SENOIDAL_AMP);
	scanf("%f",&Amp);

	printf("%s\n",MSG_SENOIDAL_FREQ);
	scanf("%f",&freq);

	printf("%s\n",MSG_SENOIDAL_PHI);
	scanf("%f",&phi);

	printf("%s", MSG_XFX);

	for (i=0; i<muestreo ; i++) 
	{
		time=ti+(i*delta_t);
		fseno=Amp*(sin((6.28*freq*time)+phi));

		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fseno);
	}
}

void loglineal (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float time,floglineal;

	printf("%s\n",MSG_LOGLINEAL_DESCRIP);

	printf("%s", MSG_XFX);

	for(i=0; i<muestreo ; i++)
	{
		time=ti+(i*delta_t);
		floglineal=time*(log10(time));
		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,floglineal);
	}
}

void log_10 (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float time,flog_10;

	printf("%s\n",MSG_LOG10_DESCRIP);

	for(i=0; i<muestreo ; i++)
	{
		time=ti+(i*delta_t);
		flog_10=log10(time);
		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,flog_10);
	}
}

void mrua (int muestreo,int precision,float ti,float delta_t)
{
	int i;
	float time,fmrua,ac,vi,posin;

	printf("%s\n",MSG_MRUA_DESCRIP );

	printf("%s\n ",MSG_MRUA_ACEL );
	scanf("%f",&ac);

	printf("%s\n" ,MSG_MRUA_VEL_INI);
	scanf("%f",&vi);

	printf("%s\n",MSG_MRUA_POS_INI );
	scanf("%f",&posin);

	printf("%s", MSG_XFX);

	for (i=0;i<muestreo;i++)
	{
	        time = ti + delta_t * i;
	        fmrua = posin + vi * time + time * time * ac;
	        printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fmrua);
	}
}

void  expon (int muestreo, int precision, float ti,float delta_t)
{	int i;
	float fexpon,time,k1,k2;

	printf("%s\n",MSG_EXP_DESCRIP);

	printf("%s\n",MSG_PARAM_EXP_CONST_UNO);
	scanf("%f",&k1);

	printf("%s\n",MSG_PARAM_EXP_CONST_DOS);
	scanf("%f",&k2);

	printf("%s", MSG_XFX);

	for(i=0;i<muestreo;i++)
	{
		time=ti+i*delta_t;
		fexpon=k1*exp(k2*time);

		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fexpon);
	}
}

void escalon (int muestreo, int precision, float ti, float delta_t)
{
	int i;
	float time;
	
	printf("%s", MSG_XFX);
	
	for(i=0;i<=muestreo;i++)
	{
		time=ti+i*delta_t;

		printf("\n%2.*f %50.*f\n", precision, time, precision, (time < 0)? 0 : 1);
	        
	}
}
void parh (int muestreo,int precision,float ti,float delta_t)
{
	int i;
	float x_a,x_b,fparh,time;

	printf("%s\n",MSG_HIP_DESCRIP);

	printf("%s\n",MSG_HIP_X_A );
	scanf("%f",&x_a);

	while (x_a==0) 
	{
			
		printf("%s\n",MSG_HIP_ERROR_A0B);
		scanf("%f",&x_a);
	}

	printf("%s\n",MSG_HIP_X_B );
	scanf("%f",&x_b);

	while (x_b==0) 
	{
		printf("%s\n",MSG_HIP_ERROR_A0B);
		scanf("%f",&x_b);
	}
	
	printf("%s", MSG_XFXY);

	for (i = 0; i<muestreo; i++)
	{
	  	time = ti+delta_t*i;
		fparh = (time/x_a) * (time/x_a) + (time/x_b) * (time/x_b);

		printf("\n(%.*f,%.*f)\t %50.4f\n",precision,time,precision,time,fparh);
	}
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

void imprimir_menu_principal(void){
	printf("%s %s\n", SYMBOL_FST_OPTION, MSG_INITIAL_FST_OPTION);
	printf("%s %s\n", SYMBOL_EXIT_MENU_OPTION, MSG_INITIAL_EXIT_OPTION);
}

void pedir_tiempo_inicial(float * ti){
	printf("%s\n", MSG_PARAM_TI);								
	scanf("%f", ti);
}

void pedir_tiempo_final(float* ti, float* tf){
	do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);
			scanf ("%f", tf);
		}while (*tf <= *ti);
}
void pedir_muestreo(int* muestreo){
	do
	{
		printf("%s\n", MSG_PARAM_MUEST);		
		scanf("%d", muestreo);
	}while (*muestreo <= MIN_CANT_SAMPLE_VALUE);
}

void pedir_precision(int* precision){
	do
	{
		printf("%s\n", MSG_PARAM_PRES);				
		scanf("%d", precision);
	}
	while (*precision <= MIN_PRECIS_VALUE);
}
void imprimir_menu_funciones(void){
	printf("%s\n", MSG_ASK_OPTION_FUNC_MENU);
	printf("%s %s\n", SYMBOL_FST_OPTION, MSG_FUNC_MENU_FST_OPTION );
	printf("%s %s\n", SYMBOL_SND_OPTION, MSG_FUNC_MENU_SND_OPTION);
	printf("%s %s\n", SYMBOL_TRD_OPTION, MSG_FUNC_MENU_TRD_OPTION);
	printf("%s %s\n", SYMBOL_4TH_OPTION, MSG_FUNC_MENU_4TH_OPTION);
	printf("%s %s\n", SYMBOL_5TH_OPTION, MSG_FUNC_MENU_5TH_OPTION);
	printf("%s %s\n", SYMBOL_6TH_OPTION, MSG_FUNC_MENU_6TH_OPTION);
	printf("%s %s\n", SYMBOL_7TH_OPTION, MSG_FUNC_MENU_7TH_OPTION);
	printf("%s %s\n", SYMBOL_EXIT_MENU_OPTION, MSG_FUNC_MENU_EXIT_OPTION);
}




void muestrear_log_10 (float* ti, float* tf, float* delta_t, int muestreo, int precision){
	while (*ti <= 0)
	{
		printf ("%s\n", MSG_TIEMPO_INICIAL_INVALIDO);	
		scanf ("%f", ti);
		do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);		
			scanf ("%f", tf);
		}
		while (*tf <= *ti);

		*delta_t = (*tf - *ti)/muestreo;
	}
	log_10 (muestreo, precision, *ti, *delta_t);
} 


void muestrear_log_lineal(float* ti, float* tf, float* delta_t, int muestreo, int precision){
	while (*ti <= 0)
	{
		printf ("%s\n", MSG_TIEMPO_INICIAL_INVALIDO);				
		scanf ("%f", ti);
		do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);		
			scanf ("%f", tf);
		}
		while (*tf <= *ti);

		*delta_t = (*tf - *ti)/muestreo;
	};

		loglineal (muestreo, precision, *ti, *delta_t);
}

void imprimir_menu_finalizado_muestreo(void){
	printf("\n \n \n %s\n", MSG_MAIN_MENU);
	printf("%s %s\n", SYMBOL_SAME_PARAM, MSG_MAIN_MENU_SAME_PARAM_OPTION);
	printf("%s %s\n", SYMBOL_NEW_PARAM, MSG_MAIN_MENU_NEW_PARAM_OPTION);
	printf("%s %s\n", SYMBOL_EXIT_MENU_OPTION, MSG_SAMPLE_ENDING_EXIT_OPTION);
}





