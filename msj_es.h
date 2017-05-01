#ifndef MSJ_ES__H
#define MSJ_ES__H

#define MSG_TIEMPO_INICIAL_INVALIDO "El intervalo a muestrear no está incluido en el dominio de la función. Ingrese un nuevo valor de tiempo inicial"
#define MSG_TIEMPO_FINAL_INVALID "Ingrese un valor de tiempo final, mayor al tiempo inicial"

#define MSG_XFX "\n  x\t\t\t\t\t\t   f(x)"
#define MSG_XFXY "\n  (x,y)\t\t\t\t\t\t f(x,y)"

#define MSG_PARAM_EXP_CONST_UNO "Ingrese la primera constante"
#define MSG_PARAM_EXP_CONST_DOS "Ingrese la segunda constante"
#define MSG_EXP_DESCRIP "La función  exponencial tiene la forma k1 * exp(k2 * x)"

#define MSG_HIP_DESCRIP "La función parabólica es de la forma:\n\n (x^2) / (a^2 ) + (y^2) / (b^2)"
#define MSG_HIP_X_A "Por favor, ingrese el parametro 'a' correspondiente a x, el cual debe ser distinto de 0"
#define MSG_HIP_X_B "Por favor, ingrese el parametro 'b' correspondiente al eje y, el cual debe ser distinto de 0"

#define MSG_MRUA_DESCRIP "La función MRUA es de la siguiente forma: \n\nposicion_inicial + velocidad * t + aceleracion * (t^2) / 2"
#define MSG_MRUA_ACEL "Por favor, ingrese el valor de la aceleración"
#define MSG_MRUA_VEL_INI "Por favor, ingrese el valor de la velocidad inicial"
#define MSG_MRUA_POS_INI "Por favor, ingrese el valor de la posición inicial"

#define MSG_ESCALON_DESCRIP "La función escalon o Heaviside es de la siguiente forma:\n\nSi x<0 entonces f(x)=0\n\nSi x>=0  entonces f(x)=1"

#define MSG_LOG10_DESCRIP "La función logarítmica en base diez es de la siguiente forma:\n\nlog (x)"

#define MSG_LOGLINEAL_DESCRIP "La función loglineal en base diez es de la siguiente forma: n * log (n)"

#define MSG_SENOIDAL_DESCRIP "La función senoidal es de la siguiente forma: A * sen ((2π * f * t) + ø)Siendo, A la amplitud, f la frecuencia y ø el ángulo de desfasaje"
#define MSG_SENOIDAL_AMP "Ingrese la Amplitud deseada, esta determinará el valor absoluto de los extremos de la funcion"
#define MSG_SENOIDAL_FREQ "Ingrese la frecuencia, esta determinará la rapidez angular"
#define MSG_SENOIDAL_PHI "Ingrese el ángulo inicial de desfasaje"

#define MSG_SEGUIR "Si desea dejar de muestrear ingrese 0. Si desea continuar ingrese cualquier tecla."
#define MSG_REASIG1 "Los siguientes son los valores de los parámetros de muestreo (tiempo inicial, tiempo final, número de muestras y presición respectivamente) asignados previamente: "
#define MSG_REASIG2 "Ingrese 1 si quiere mantener estos mismos valores para el próximo muestreo."
#define MSG_CONFIR1 "Los siguientes son los valores de los parámetros de muestreo (tiempo inicial, tiempo final, número de muestras y presición respectivamente) elegidos: "

#define MSG_NEGATIVE_CONFIR "Por favor, vuelva a ingresar los parámetros"
#define MSG_NUEVO_INGRESO "Por favor, elija una de las opciones disponibles. "
	
#define MSG_PARAM_TI "Inserte tiempo inicial"
#define MSG_PARAM_MUEST "Inserte un número de muestras mayor a 0"
#define MSG_PARAM_PRES "Inserte la precisión"
#define MSG_ERROR "El carácter ingresado no es válido."

#define MSG_INITIAL_FST_OPTION "Muestrear"
#define MSG_INITIAL_EXIT_OPTION "Salir del programa"

#define MSG_FUNC_MENU_OPT_SEN "Senoidal"
#define MSG_FUNC_MENU_OPT_LOG "Logarítmica"
#define MSG_FUNC_MENU_OPT_LOG_LIN "Logarítmica lineal"
#define MSG_FUNC_MENU_OPT_EXPON "Exponencial"
#define MSG_FUNC_MENU_OPT_STEP "Escalón"
#define MSG_FUNC_MENU_OPT_MRUA "Movimiento rectilíneo unifórmemente acelerado"
#define MSG_FUNC_MENU_OPT_PARH "Paraboloide"
#define MSG_FUNC_MENU_EXIT_OPTION "Volver al menú principal"
#define MSG_ASK_OPTION_FUNC_MENU "Por favor, ingrese el número de opción de la función que quiere muestrear"


#define MSG_MAIN_MENU "Elija una de las siguientes opciones:"
#define MSG_MAIN_MENU_NEW_PARAM_OPTION "Muestrear función con distintos parámetros"
#define MSG_MAIN_MENU_SAME_PARAM_OPTION "Muestrear función con los parámetros ya asignados"
#define MSG_SAMPLE_ENDING_EXIT_OPTION "Salir del programa"

#define MSG_ASK_CONF "¿Desea utiizar estos valores para realizar el proximo muestreo?"
#define MSG_CONFIR_ACCEPT_PARAM "Confirmar"
#define MSG_CONFIR_ASK_FOR_PARAM_AGAIN "Volver a ingresar parámetros"

#define MSG_INVALID_INPUT "Valor ingresado inválido."
#define MSG_MENU_SEP '.'
#endif
