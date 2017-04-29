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


/* menu_func.h */


void pedir_tiempo_inicial(float * ti){
	printf("%s\n", MSG_PARAM_TI);								
	scanf("%f", ti);
}

void pedir_tiempo_final(float* ti, float* tf){
	do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);
			scanf ("%f", tf);
			if (*tf <= *ti)
			{
				printf("%s\n",MSG_INVALID_INPUT);
			}
		}while (*tf <= *ti);
}
void pedir_muestreo(int* muestreo){
	do
	{
		printf("%s\n", MSG_PARAM_MUEST);		
		scanf("%d", muestreo);
		if (*muestreo <= MIN_CANT_SAMPLE_VALUE)
			{
				printf("%s\n",MSG_INVALID_INPUT);
			}
	}while (*muestreo <= MIN_CANT_SAMPLE_VALUE);
}

void pedir_precision(int* precision){
	do
	{
		printf("%s\n", MSG_PARAM_PRES);				
		scanf("%d", precision);
		if (*precision <= MIN_PRECIS_VALUE)
			{
				printf("%s\n",MSG_INVALID_INPUT);
			}
	}
	while (*precision <= MIN_PRECIS_VALUE);
}
void imprimir_menu_funciones(void){
	printf("%s\n", MSG_ASK_OPTION_FUNC_MENU);
	printf("%i %c %s\n", OPTION_SENO, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_SEN );
	printf("%i %c %s\n", OPTION_LOG_10, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_LOG);
	printf("%i %c %s\n", OPTION_LOG_LIN, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_LOG_LIN);
	printf("%i %c %s\n", OPTION_EXP, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_EXPON);
	printf("%i %c %s\n", OPTION_ESCALON, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_STEP);
	printf("%i %c %s\n", OPTION_MRUA, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_MRUA);
	printf("%i %c %s\n", OPTION_PAR, MSG_MENU_SEP, MSG_FUNC_MENU_OPT_PARH);
	printf("%i %c %s\n", OPTION_EXIT, MSG_MENU_SEP, MSG_FUNC_MENU_EXIT_OPTION);
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

void imprimir_menu_principal(void){
	printf("\n \n \n %s\n", MSG_MAIN_MENU);
	printf("%i %c %s\n", OPTION_SAME_PARAM, MSG_MENU_SEP, MSG_MAIN_MENU_SAME_PARAM_OPTION);
	printf("%i %c %s\n", OPTION_NEW_PARAM, MSG_MENU_SEP, MSG_MAIN_MENU_NEW_PARAM_OPTION);
	printf("%i %c %s\n", OPTION_EXIT, MSG_MENU_SEP, MSG_SAMPLE_ENDING_EXIT_OPTION);
}

void imprimir_menu_inicial(void){
	printf("%s %s\n", SYMBOL_FST_OPTION, MSG_INITIAL_FST_OPTION);
	printf("%s %s\n\n", SYMBOL_EXIT_MENU_OPTION, MSG_INITIAL_EXIT_OPTION);
}

void confirmar_parametros(int * confirmacion){	
	printf ("%s\n \n %f \n %f \n %d \n %d \n \n %s\n", MSG_CONFIR1, ti, tf, num_muestras, precision, MSG_CONFIR2);	
	scanf ("%d", confirmacion);
	if (*confirmacion==OPTION_CONFIR)
	{
		estado = ST_FUNC_MENU;
	}else {
		printf("%s\n", MSG_NEGATIVE_CONFIR);
		estado = ST_ASK_PARAM;
	}
	break;
}

/* funciones de muestreo */


void muestrear_senoidal (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float freq,amp,phi,fseno,time;

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
		fseno=Amp*(sin((PI_TIMES_TWO*freq*time)+phi));

		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fseno);
	}
}

void muestrear_loglineal (int muestreo, int precision, float ti,float delta_t)
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

void muestrear_log_10 (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float time,flog_10;

	printf("%s\n\n",MSG_LOG10_DESCRIP);

	for(i=0; i<muestreo ; i++)
	{
		time=ti+(i*delta_t);
		flog_10=log10(time);
		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,flog_10);
	}
}

void muestrear_mrua (int muestreo,int precision,float ti,float delta_t)
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

void  muestrear_expon (int muestreo, int precision, float ti,float delta_t)
{	int i;
	float fexpon,time,k1,k2;

	printf("%s\n",MSG_EXP_DESCRIP);

	printf("%s\n",MSG_PARAM_EXP_CONST_UNO);
	scanf("%f",&k1);

	printf("%s\n",MSG_PARAM_EXP_CONST_DOS);
	scanf("%f",&k2);

	printf("%s\n", MSG_XFX);

	for(i=0;i<muestreo;i++)
	{
		time=ti+i*delta_t;
		fexpon=k1*exp(k2*time);

		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fexpon);
	}
}

void muestrear_escalon (int muestreo, int precision, float ti, float delta_t)
{
	int i;
	float time;
	printf("%s\n", MSG_ESCALON_DESCRIP);

	printf("%s\n", MSG_XFX);
	
	for(i=0;i<=muestreo;i++)
	{
		time=ti+i*delta_t;

		printf("\n%2.*f %50.*f\n", precision, time, precision, (time < 0)? 0.0 : 1.0);
	        
	}
}
void muestrear_parh (int muestreo,int precision,float ti,float delta_t)
{
	int i;
	float x_a,x_b,fparh,time;

	printf("%s\n",MSG_HIP_DESCRIP);

	do
	{
		printf("%s\n",MSG_HIP_X_A );
		scanf("%f",&x_a);
		if (x_a==0)
		{
			printf("%s\n",MSG_INVALID_INPUT);
		}
	}while (x_a==0); 


	do
	{
		printf("%s\n",MSG_HIP_X_B );
		scanf("%f",&x_b);
		if (x_b==0)
		{
			printf("%s\n",MSG_INVALID_INPUT);
		}
	}while (x_b==0); 

	
	printf("%s\n", MSG_XFXY);

	for (i = 0; i<muestreo; i++)
	{
	  	time = ti+delta_t*i;
		fparh = (time/x_a) * (time/x_a) + (time/x_b) * (time/x_b);

		printf("\n(%.*f,%.*f)\t %50.4f\n",precision,time,precision,time,fparh);
	}
}
