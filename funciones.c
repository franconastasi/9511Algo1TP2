
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
