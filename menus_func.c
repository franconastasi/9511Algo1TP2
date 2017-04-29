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
