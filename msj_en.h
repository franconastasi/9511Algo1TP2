#ifndef MSJ_EN__H
#define MSJ_EN__H

//#define MSG_FUNCIONES "1.Sine \n 2.Logarithm \n 3.Linear logarithm \n 4.Exponential \n 5.Step \n 6.Uniform acceleration \n 7.Paraboloid \n 0.Return to main menu"
#define MSG_SEGUIR "Enter 0 if you wish to stop sampling."
//#define MSG_MENU_PRINCIPAL "1.Sample \n0. Exit program"
#define MSG_REASIG1 "The following values are the ones previously asigned to the sampling parameters (initial time, final time, sample number and precision respectively): \n"
#define MSG_REASIG2 "Enter 1 if you wish to keep these values for your next sample."
#define MSG_CONFIR1 "The following values are the ones asigned to the sampling parameters (initial time, final time, sample number and precision respectively): \n"
#define MSG_CONFIR2 "Enter 1 to confirm that these are the values you wish to work with."
#define MSG_NEGATIVE_CONFIR "Please, insert the parameters again"
#define MSG_NUEVO_INGRESO "Please, choose one of the available option"

#define MSG_TIEMPO_INICIAL_INVALIDO "The defined interval is not included in the function domain. Please, enter a new value for initial time"
#define MSG_TIEMPO_FINAL_INVALID "Enter a final time value, greater than the initial time"

#define MSG_XFX "\n  x\t\t\t\t\t\t   f(x)"
#define MSG_XFXY "\n  (x,y)\t\t\t\t\t\t f(x,y)"

#define MSG_PARAM_EXP_CONST_UNO "Enter first constant"
#define MSG_PARAM_EXP_CONST_DOS "Enter second constant"
#define MSG_EXP_DESCRIP "the exponential function has the following form k1 * exp(k2 * x) "

#define MSG_HIP_DESCRIP "The parabolic function follows the following formula:\n\n (x^2) / (a^2 ) + (y^2) / (b^2)"
#define MSG_HIP_X_A "Please, enter the parameter 'a' corresponding to x, which it must be different than zero"
#define MSG_HIP_X_B "Please, enter the parameter 'b' corresponding to y, which it must be different than zero"
//#define MSG_HIP_ERROR_A0B "PLease re-enter the parameter, different from 0"

#define MSG_MRUA_DESCRIP "The ARM function has this form: \n\ninitial position + velocity * t + acceleration * (t^2) / 2"
#define MSG_MRUA_ACEL "Please enter the acceleration value"
#define MSG_MRUA_VEL_INI "Please enter the initial velocity value"
#define MSG_MRUA_POS_INI "Please enter the initial position value"

#define MSG_ESCALON_DESCRIP "The step function aka Heaviside is represented by the following formula:\n\nSi x<0 then f(x)=0\n\nSi x>=0  then f(x)=1"

#define MSG_LOG10_DESCRIP "The logarithmic function (base10) is represented by the following formula:\n\n log (x)"

#define MSG_LOGLINEAL_DESCRIP "The linear logarithmic function (base10) it's represented by the following formula\\n xlog(x))"

#define MSG_SENOIDAL_DESCRIP "The sinusoidal function it follows this  formula: \n\nA * sen ((2π * f * t) + ø)\n\nSiendo, A being the amplitude, f frequency and ø the phase angle"
#define MSG_SENOIDAL_AMP "Insert the Amplitude"
#define MSG_SENOIDAL_FREQ " Insert the frequency or angular velocity"
#define MSG_SENOIDAL_PHI "Insert the phase angle value"

#define MSG_PARAM_TI "Insert Initial Time"
#define MSG_PARAM_MUEST "Insert the number of samples"
#define MSG_PARAM_PRES "Insert precision"
#define MSG_ERROR "The character is not valid"

#define MSG_INITIAL_FST_OPTION "Sample"
#define MSG_INITIAL_EXIT_OPTION "Exit program"

#define MSG_FUNC_MENU_OPT_SEN "Sine"
#define MSG_FUNC_MENU_OPT_LOG "Logarithm"
#define MSG_FUNC_MENU_OPT_LOG_LIN "Linear logarithm"
#define MSG_FUNC_MENU_OPT_EXPON "Exponential"
#define MSG_FUNC_MENU_OPT_STEP "Step"
#define MSG_FUNC_MENU_OPT_MRUA "Uniform acceleration"
#define MSG_FUNC_MENU_OPT_PARH "Paraboloid"
#define MSG_FUNC_MENU_EXIT_OPTION "Return to main menu"
#define MSG_ASK_OPTION_FUNC_MENU "Por favor, ingrese el número de opción de la función que quiere muestrear"

#define MSG_MAIN_MENU "Please, choose one of the following options:"
#define MSG_MAIN_MENU_NEW_PARAM_OPTION "Change parameter"
#define MSG_MAIN_MENU_SAME_PARAM_OPTION "Sample another function with same parameters"
#define MSG_SAMPLE_ENDING_EXIT_OPTION "Exit program"

#define MSG_INVALID_INPUT "Invalid input value."
#define MSG_MENU_SEP '.'

#endif