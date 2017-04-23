#ifndef MSJ_ES__H
#define MSJ_ES__H

#define MSG_TIEMPO_INICIAL_INVALIDO "El intervalo a muestrear no está incluido en el dominio de la función. Ingrese un nuevo valor de tiempo inicial \n"
#define MSG_TIEMPO_FINAL_INVALID "Ingrese un valor de tiempo final, mayor al tiempo inicial \n"

#define MSG_XFX "\n  x\t\t\t\t\t\t   f(x)\n"
#define MSG_XFXY "\n  (x,y)\t\t\t\t\t\t f(x,y)\n"

#define MSG_PARAM_EXP_CONST_UNO "Ingrese la primera constante\n"
#define MSG_PARAM_EXP_CONST_DOS "Ingrese la segunda constante\n"
#define MSG_EXP_DESCRIP "La función  exponencial tiene la forma k1 * exp(k2 * x) \n"

#define MSG_HIP_DESCRIP "La función parabólica es de la forma:\n\n (x^2) / (a^2 ) + (y^2) / (b^2) \n"
#define MSG_HIP_X_A "Por favor, ingrese el parametro 'a' correspondiente a x \n"
#define MSG_HIP_X_B "Por favor, ingrese el parametro 'b' correspondiente al eje y \n"
#define MSG_HIP_ERROR_A0B "Por favor reingrese el parametro, siendo este distinto de 0\n"

#define MSG_MRUA_DESCRIP "La función MRUA es de la siguiente forma: \n\nposicion_inicial + velocidad * t + aceleracion * (t^2) / 2 \n"
#define MSG_MRUA_ACEL "Por favor, ingrese el valor de la aceleración\n"
#define MSG_MRUA_VEL_INI "Por favor, ingrese el valor de la velocidad inicial \n"
#define MSG_MRUA_POS_INI "Por favor, ingrese el valor de la posición inicial \n"

#define MSG_ESCALON_DESCRIP "La función escalon o Heaviside es de la siguiente forma:\n\nSi x<0 entonces f(x)=0\n\nSi x>=0  entonces f(x)=1\n"

#define MSG_LOG10_DESCRIP "La función logarítmica en base diez es de la siguiente forma:\n\nlog (x)\n\n"

#define MSG_LOGLINEAL_DESCRIP "La función loglineal en base diez es de la siguiente forma: n * log (n)"

#define MSG_SENOIDAL_DESCRIP "La función senoidal es de la siguiente forma: A * sen ((2π * f * t) + ø)Siendo, A la amplitud, f la frecuencia y ø el ángulo de desfasaje"
#define MSG_SENOIDAL_AMP "Ingrese la Amplitud deseada, esta determinará el valor absoluto de los extremos de la funcion"
#define MSG_SENOIDAL_FREQ "Ingrese la frecuencia, esta determinará la rapidez angular"
#define MSG_SENOIDAL_PHI "Ingrese el ángulo inicial de desfasaje"

#define MSG_SEGUIR "Si desea dejar de muestrear ingrese 0. Si desea continuar ingrese cualquier tecla."
#define MSG_MENU_PRINCIPAL "1.Muestrear \n0.Salir del programa"
#define MSG_FUNCIONES "\n 1.Senoidal \n 2.Logarítmica \n 3.Logarítmica lineal \n 4.Exponencial \n 5.Escalón \n 6.Movimiento rectilíneo unifórmemente acelerado  7.Paraboloide  0.Volver al menú principal"
#define MSG_REASIG1 "Los siguientes son los valores de los parámetros de muestreo (tiempo inicial, tiempo final, número de muestras y presición respectivamente) asignados previamente: "
#define MSG_REASIG2 "Ingrese 1 si quiere mantener estos mismos valores para el próximo muestreo."
#define MSG_CONFIR1 "Los siguientes son los valores de los parámetros de muestreo (tiempo inicial, tiempo final, número de muestras y presición respectivamente) elegidos: "
#define MSG_CONFIR2 "Ingrese 1 para confirmar que desea usar estos valores."
#define MSG_NUEVO_INGRESO "Por favor, elija una de las opciones disponibles. "
	
#define MSG_PARAM_TI "Inserte tiempo inicial"
#define MSG_PARAM_MUEST "Inserte un número de muestras mayor a 0"
#define MSG_PARAM_PRES "Inserte la precisión"
#define MSG_ERROR "El carácter ingresado no es válido."








#define SYMBOL_EXIT_MENU_OPTION "0."
#define SYMBOL_FST_OPTION "1."
#define SYMBOL_SND_OPTION "2."
#define SYMBOL_TRD_OPTION "3."
#define SYMBOL_4TH_OPTION "4."
#define SYMBOL_5TH_OPTION "5."
#define SYMBOL_6TH_OPTION "6."
#define SYMBOL_7TH_OPTION "7."


#define SYMBOL_SAME_PARAM "1."
#define SYMBOL_NEW_PARAM "2."

#define MSG_INITIAL_FST_OPTION "Muestrear"
#define MSG_INITIAL_EXIT_OPTION "Salir del programa"

#define MSG_FUNC_MENU_FST_OPTION "Senoidal"
#define MSG_FUNC_MENU_SND_OPTION "Logarítmica"
#define MSG_FUNC_MENU_TRD_OPTION "Logarítmica lineal"
#define MSG_FUNC_MENU_4TH_OPTION "Exponencial"
#define MSG_FUNC_MENU_5TH_OPTION "Escalón"
#define MSG_FUNC_MENU_6TH_OPTION "Movimiento rectilíneo unifórmemente acelerado"
#define MSG_FUNC_MENU_7TH_OPTION "Paraboloide"
#define MSG_FUNC_MENU_EXIT_OPTION "Volver al menú principal"
#define MSG_ASK_OPTION_FUNC_MENU "Por favor, ingrese el número de opción de la función que quiere muestrear"

#define OPTION_EXIT 0
#define OPTION_SENO 1
#define OPTION_LOG_10 2
#define OPTION_LOG_LIN 3
#define OPTION_EXP 4
#define OPTION_ESCALON 5
#define OPTION_MRUA 6
#define OPTION_PAR 7

#define OPTION_SAME_PARAM 1
#define OPTION_NEW_PARAM 2

#define MSG_MAIN_MENU "Elija una de las siguientes opciones:"
#define MSG_MAIN_MENU_NEW_PARAM "Muestrear función con distintos parámetros"
#define MSG_MAIN_MENU_SAME_PARAM "Muestrear función con los parámetros ya asignados"
#define MSG_MAIN_MENU_EXIT_OPTION "Salir del programa"

#define MIN_CANT_SAMPLE_VALUE 0
#define MIN_PRECIS_VALUE 0

#endif
