#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

//sacar prom y var para cada difI, juego probar con otros tama;os de matriz y ver si siempre difi/cej=R*


int i,j,k,l,w,u,v,m,NoP,veces,muestra,raro,volado,rvar,rvar2,GA;



int gl1x[20][20];
int gl3x[20][20];
int egl3x[20][20];
int ttg1x[20][20];
int cpcx[20][20];
int tryx[20][20];
int etcsx[20][20];
int tclsx[20][20];
int atmyc1x[20][20];
int myb23x[20][20];
int mir156x[20][20];
int gisx[20][20];//como meter a gis3
int spyx[20][20];
int ttg2x[20][20];
int zfpgisx[20][20];
int zfp5x[20][20];
int zfp6x[20][20];
int spl9x[20][20];
int upl3x[20][20];
int dellax[20][20];
int jazx[20][20];
int gax[20][20];
int jax[20][20];
int herbx[20][20];
int edadx[20][20];
int ckx[20][20];


int gl1y[20][20];
int gl3y[20][20];
int egl3y[20][20];
int ttg1y[20][20];
int cpcy[20][20];
int tryy[20][20];
int etcsy[20][20];
int tclsy[20][20];
int atmyc1y[20][20];
int myb23y[20][20];
int mir156y[20][20];
int gisy[20][20];
int spyy[20][20];
int ttg2y[20][20];
int zfpgisy[20][20];
int zfp5y[20][20];
int zfp6y[20][20];
int spl9y[20][20];
int upl3y[20][20];
int dellay[20][20];
int jazy[20][20];
int gay[20][20];
int jay[20][20];
int herby[20][20];
int edady[20][20];
int cky[20][20];

int cpcDif[20][20];
int tryDif[20][20];
int ttgDif[20][20];

int degttg=1;
int degtry=6;
int degcpc=6;

float ttgDiff[20][20];

int ACint[20][20];
int AC[20][20];
int IC[20][20];
float In[20][20];
float cpcn[20][20];
float tryn[20][20];
float gl3n[20][20];
float egl3n[20][20];
int sumaAC[20][20];
int sumaIC[20][20];
float R[100];
int cel=20;
float DifCPC,DifTRY,DifA,sumR,promR,varR,sigmaR,sR,stdev,deg;
float Rd,Ra;
//float DifI=0;
int a,b,c,d;


int Iniciales(){//0 AC, 1 CI 
					 //srand(time(NULL));
					 //srand(2.5);
	
	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			gl1x[i][j]=rand()%2;
			gl3x[i][j]=rand()%2;
			egl3x[i][j]=rand()%2;
			ttg1x[i][j]=rand()%2;
			cpcx[i][j]=rand()%2;
			tryx[i][j]=rand()%2;
			etcsx[i][j]=rand()%2;
			tclsx[i][j]=rand()%2;
			atmyc1x[i][j]=rand()%2;
			myb23x[i][j]=rand()%2;
			mir156x[i][j]=rand()%2;
			gisx[i][j]=rand()%2;
			spyx[i][j]=rand()%2;
			ttg2x[i][j]=rand()%2;
			zfpgisx[i][j]=rand()%2;
			zfp5x[i][j]=rand()%2;
			zfp6x[i][j]=rand()%2;
			spl9x[i][j]=rand()%2;
			upl3x[i][j]=rand()%2;
			dellax[i][j]=rand()%2;
			jazx[i][j]=rand()%2;
			gax[i][j]=1;
			jax[i][j]=1;
			herbx[i][j]=1;
			edadx[i][j]=1;
			ckx[i][j]=1;
			In[i][j]=0;
			cpcDif[i][j]=0;
			tryDif[i][j]=0;
			sumaAC[i][j]=0;
			sumaIC[i][j]=0;
		}}
}	

int H(float x){// funcion escalon
	int y;
	if(x<=0.15)y=0;
	if(0.15<x&&x<=1)y=1;
	if(1<x)y=2;
	return y;
}


int itera(){//0 AC, 1 CI	
	
	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
		sumaAC[i][j]=sumaAC[i][j]+ACint[i][j];
		sumaIC[i][j]=sumaIC[i][j]+IC[i][j];		
	}
	}



	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			
			volado=rand()%10;
			if(volado<degcpc)rvar=1;
			else rvar=0;			
			cpcx[i][j]=(cpcx[i][j]+cpcDif[i][j]-rvar);
			if(cpcx[i][j]>2)cpcx[i][j]=2;			
			if(cpcx[i][j]<0)cpcx[i][j]=0;	
			
			volado=rand()%10;
			if(volado<degtry)rvar=1;
			else rvar=0;
			tryx[i][j]=(tryx[i][j]+tryDif[i][j]-rvar);
			if(tryx[i][j]>2)tryx[i][j]=2;			
			if(tryx[i][j]<0)tryx[i][j]=0;	
			
			volado=rand()%10;
			if(volado<degttg)rvar=1;
			else rvar=0;
			ttg1x[i][j]=(ttg1x[i][j]+ttgDif[i][j]-rvar);
			if(ttg1x[i][j]>2)ttg1x[i][j]=2;			
			if(ttg1x[i][j]<0)ttg1x[i][j]=0;

			if (gl1x[i][j]==0)ACint[i][j]=0;
			if (gl3x[i][j]==0&&egl3x[i][j]==0)ACint[i][j]=0;
			if (gl3x[i][j]==0&&ttg1x[i][j]==0)ACint[i][j]=0;
			if (egl3x[i][j]==0&&ttg1x[i][j]==0)ACint[i][j]=0;//hasta aquí queda bien
			if (gl1x[i][j]==0&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==0&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==0&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==1&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==0&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=0;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==1&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==0&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==1&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=1;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==0&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==0&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==1&&myb23x[i][j]==2)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==0)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==1)ACint[i][j]=2;
			if (gl1x[i][j]==2&&gl3x[i][j]==2&&egl3x[i][j]==2&&ttg1x[i][j]==1&&atmyc1x[i][j]==2&&myb23x[i][j]==2)ACint[i][j]=2;
			
			
		
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=0;//1
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==0&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=0;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==1&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=0;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=0;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=0;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=1;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==0&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=1;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==1&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==0&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==1&&tclsx[i][j]==2)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==0)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==1)IC[i][j]=2;
			if (cpcx[i][j]==2&&tryx[i][j]==2&&etcsx[i][j]==2&&tclsx[i][j]==2)IC[i][j]=2;
			
			
			if (ACint[i][j]==0&&IC[i][j]==0&&dellax[i][j]==0)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==0&&dellax[i][j]==1)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==0&&dellax[i][j]==2)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==1&&dellax[i][j]==0)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==1&&dellax[i][j]==1)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==1&&dellax[i][j]==2)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==2&&dellax[i][j]==0)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==2&&dellax[i][j]==1)AC[i][j]=0;
			if (ACint[i][j]==0&&IC[i][j]==2&&dellax[i][j]==2)AC[i][j]=0;
			if (ACint[i][j]==1&&IC[i][j]==0&&dellax[i][j]==0)AC[i][j]=1;
			if (ACint[i][j]==1&&IC[i][j]==0&&dellax[i][j]==1)AC[i][j]=1;
			if (ACint[i][j]==1&&IC[i][j]==0&&dellax[i][j]==2)AC[i][j]=0;
			if (ACint[i][j]==1&&IC[i][j]==1&&dellax[i][j]==0)AC[i][j]=1;
			if (ACint[i][j]==1&&IC[i][j]==1&&dellax[i][j]==1)AC[i][j]=1;
			if (ACint[i][j]==1&&IC[i][j]==1&&dellax[i][j]==2)AC[i][j]=0;
			if (ACint[i][j]==1&&IC[i][j]==2&&dellax[i][j]==0)AC[i][j]=1;
			if (ACint[i][j]==1&&IC[i][j]==2&&dellax[i][j]==1)AC[i][j]=0;
			if (ACint[i][j]==1&&IC[i][j]==2&&dellax[i][j]==2)AC[i][j]=0;
			if (ACint[i][j]==2&&IC[i][j]==0&&dellax[i][j]==0)AC[i][j]=2;
			if (ACint[i][j]==2&&IC[i][j]==0&&dellax[i][j]==1)AC[i][j]=2;
			if (ACint[i][j]==2&&IC[i][j]==0&&dellax[i][j]==2)AC[i][j]=1;
			if (ACint[i][j]==2&&IC[i][j]==1&&dellax[i][j]==0)AC[i][j]=2;
			if (ACint[i][j]==2&&IC[i][j]==1&&dellax[i][j]==1)AC[i][j]=1;
			if (ACint[i][j]==2&&IC[i][j]==1&&dellax[i][j]==2)AC[i][j]=1;
			if (ACint[i][j]==2&&IC[i][j]==2&&dellax[i][j]==0)AC[i][j]=2;
			if (ACint[i][j]==2&&IC[i][j]==2&&dellax[i][j]==1)AC[i][j]=2;
			if (ACint[i][j]==2&&IC[i][j]==2&&dellax[i][j]==2)AC[i][j]=0;//1
			
			
			
			if (jazx[i][j]==0&&gisx[i][j]==0&&AC[i][j]==0)gl1y[i][j]=1;				
			if (jazx[i][j]==0&&gisx[i][j]==0&&AC[i][j]==1)gl1y[i][j]=1;				
			if (jazx[i][j]==0&&gisx[i][j]==0&&AC[i][j]==2)gl1y[i][j]=1;				
			if (jazx[i][j]==0&&gisx[i][j]==1&&AC[i][j]==0)gl1y[i][j]=1;				
			if (jazx[i][j]==0&&gisx[i][j]==1&&AC[i][j]==1)gl1y[i][j]=2;				
			if (jazx[i][j]==0&&gisx[i][j]==1&&AC[i][j]==2)gl1y[i][j]=2;				
			if (jazx[i][j]==0&&gisx[i][j]==2&&AC[i][j]==0)gl1y[i][j]=2;				
			if (jazx[i][j]==0&&gisx[i][j]==2&&AC[i][j]==1)gl1y[i][j]=2;				
			if (jazx[i][j]==0&&gisx[i][j]==2&&AC[i][j]==2)gl1y[i][j]=2;				
			if (jazx[i][j]==1&&gisx[i][j]==0&&AC[i][j]==0)gl1y[i][j]=1;				
			if (jazx[i][j]==1&&gisx[i][j]==0&&AC[i][j]==1)gl1y[i][j]=1;				
			if (jazx[i][j]==1&&gisx[i][j]==0&&AC[i][j]==2)gl1y[i][j]=1;				
			if (jazx[i][j]==1&&gisx[i][j]==1&&AC[i][j]==0)gl1y[i][j]=1;				
			if (jazx[i][j]==1&&gisx[i][j]==1&&AC[i][j]==1)gl1y[i][j]=2;				
			if (jazx[i][j]==1&&gisx[i][j]==1&&AC[i][j]==2)gl1y[i][j]=2;				
			if (jazx[i][j]==1&&gisx[i][j]==2&&AC[i][j]==0)gl1y[i][j]=1;
			if (jazx[i][j]==1&&gisx[i][j]==2&&AC[i][j]==1)gl1y[i][j]=2;
			if (jazx[i][j]==1&&gisx[i][j]==2&&AC[i][j]==2)gl1y[i][j]=2;
			if (jazx[i][j]==2&&gisx[i][j]==0&&AC[i][j]==0)gl1y[i][j]=0;
			if (jazx[i][j]==2&&gisx[i][j]==0&&AC[i][j]==1)gl1y[i][j]=0;
			if (jazx[i][j]==2&&gisx[i][j]==0&&AC[i][j]==2)gl1y[i][j]=1;
			if (jazx[i][j]==2&&gisx[i][j]==1&&AC[i][j]==0)gl1y[i][j]=0;
			if (jazx[i][j]==2&&gisx[i][j]==1&&AC[i][j]==1)gl1y[i][j]=1;
			if (jazx[i][j]==2&&gisx[i][j]==1&&AC[i][j]==2)gl1y[i][j]=1;
			if (jazx[i][j]==2&&gisx[i][j]==2&&AC[i][j]==0)gl1y[i][j]=1;
			if (jazx[i][j]==2&&gisx[i][j]==2&&AC[i][j]==1)gl1y[i][j]=1;
			if (jazx[i][j]==2&&gisx[i][j]==2&&AC[i][j]==2)gl1y[i][j]=2;	
			
			
			
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=2;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=2;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=2;					
			if (jazx[i][j]==0&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=2;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=2;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=2;					
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=2;
			if (jazx[i][j]==0&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=2;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==0&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=2;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=2;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=2;
			if (jazx[i][j]==1&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=2;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==1&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==0&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==1&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==1)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==0&&AC[i][j]==2)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==1)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==1&&AC[i][j]==2)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==0)gl3y[i][j]=0;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==1)gl3y[i][j]=1;
			if (jazx[i][j]==2&&upl3x[i][j]==2&&gisx[i][j]==2&&AC[i][j]==2)gl3y[i][j]=1;
			
			
			if (jazx[i][j]==0&&AC[i][j]==0)egl3y[i][j]=0;
			if (jazx[i][j]==0&&AC[i][j]==1)egl3y[i][j]=2;
			if (jazx[i][j]==0&&AC[i][j]==2)egl3y[i][j]=2;
			if (jazx[i][j]==1&&AC[i][j]==0)egl3y[i][j]=0;
			if (jazx[i][j]==1&&AC[i][j]==1)egl3y[i][j]=1;
			if (jazx[i][j]==1&&AC[i][j]==2)egl3y[i][j]=1;
			if (jazx[i][j]==2&&AC[i][j]==0)egl3y[i][j]=0;
			if (jazx[i][j]==2&&AC[i][j]==1)egl3y[i][j]=0;
			if (jazx[i][j]==2&&AC[i][j]==2)egl3y[i][j]=1;			
			
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==0&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==0&&AC[i][j]==1)cpcy[i][j]=1;			
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==0&&AC[i][j]==2)cpcy[i][j]=2;
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==1&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==1&&AC[i][j]==1)cpcy[i][j]=1;//2
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==1&&AC[i][j]==2)cpcy[i][j]=2;
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==2&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==2&&AC[i][j]==1)cpcy[i][j]=2;
			if (atmyc1x[i][j]==0&&ttg2x[i][j]==2&&AC[i][j]==2)cpcy[i][j]=2;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==0&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==0&&AC[i][j]==1)cpcy[i][j]=0;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==0&&AC[i][j]==2)cpcy[i][j]=1;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==1&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==1&&AC[i][j]==1)cpcy[i][j]=1;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==1&&AC[i][j]==2)cpcy[i][j]=2;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==2&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==2&&AC[i][j]==1)cpcy[i][j]=2;
			if (atmyc1x[i][j]==1&&ttg2x[i][j]==2&&AC[i][j]==2)cpcy[i][j]=2;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==0&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==0&&AC[i][j]==1)cpcy[i][j]=0;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==0&&AC[i][j]==2)cpcy[i][j]=1;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==1&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==1&&AC[i][j]==1)cpcy[i][j]=0;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==1&&AC[i][j]==2)cpcy[i][j]=1;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==2&&AC[i][j]==0)cpcy[i][j]=0;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==2&&AC[i][j]==1)cpcy[i][j]=1;
			if (atmyc1x[i][j]==2&&ttg2x[i][j]==2&&AC[i][j]==2)cpcy[i][j]=2;
			
			
			if (atmyc1x[i][j]==0&&spl9x[i][j]==0&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==0&&AC[i][j]==1)tryy[i][j]=1;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==0&&AC[i][j]==2)tryy[i][j]=1;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==1&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==1&&AC[i][j]==1)tryy[i][j]=1;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==1&&AC[i][j]==2)tryy[i][j]=2;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==2&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==2&&AC[i][j]==1)tryy[i][j]=2;
			if (atmyc1x[i][j]==0&&spl9x[i][j]==2&&AC[i][j]==2)tryy[i][j]=2;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==0&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==0&&AC[i][j]==1)tryy[i][j]=0;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==0&&AC[i][j]==2)tryy[i][j]=1;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==1&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==1&&AC[i][j]==1)tryy[i][j]=1;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==1&&AC[i][j]==2)tryy[i][j]=2;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==2&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==2&&AC[i][j]==1)tryy[i][j]=2;
			if (atmyc1x[i][j]==1&&spl9x[i][j]==2&&AC[i][j]==2)tryy[i][j]=2;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==0&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==0&&AC[i][j]==1)tryy[i][j]=0;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==0&&AC[i][j]==2)tryy[i][j]=1;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==1&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==1&&AC[i][j]==1)tryy[i][j]=0;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==1&&AC[i][j]==2)tryy[i][j]=2;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==2&&AC[i][j]==0)tryy[i][j]=0;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==2&&AC[i][j]==1)tryy[i][j]=1;
			if (atmyc1x[i][j]==2&&spl9x[i][j]==2&&AC[i][j]==2)tryy[i][j]=2;
			
			
			if (spl9x[i][j]==0)tclsy[i][j]=1;
			if (spl9x[i][j]==1)tclsy[i][j]=1;
			if (spl9x[i][j]==2)tclsy[i][j]=2;
			
			
			if (dellax[i][j]==0&&spyx[i][j]==0&&zfp5x[i][j]==0)gisy[i][j]=1;//2
			if (dellax[i][j]==0&&spyx[i][j]==0&&zfp5x[i][j]==1)gisy[i][j]=2;
			if (dellax[i][j]==0&&spyx[i][j]==0&&zfp5x[i][j]==2)gisy[i][j]=2;
			if (dellax[i][j]==0&&spyx[i][j]==1&&zfp5x[i][j]==0)gisy[i][j]=1;
			if (dellax[i][j]==0&&spyx[i][j]==1&&zfp5x[i][j]==1)gisy[i][j]=2;
			if (dellax[i][j]==0&&spyx[i][j]==1&&zfp5x[i][j]==2)gisy[i][j]=2;
			if (dellax[i][j]==0&&spyx[i][j]==2&&zfp5x[i][j]==0)gisy[i][j]=1;
			if (dellax[i][j]==0&&spyx[i][j]==2&&zfp5x[i][j]==1)gisy[i][j]=1;
			if (dellax[i][j]==0&&spyx[i][j]==2&&zfp5x[i][j]==2)gisy[i][j]=1;
			if (dellax[i][j]==1&&spyx[i][j]==0&&zfp5x[i][j]==0)gisy[i][j]=1;
			if (dellax[i][j]==1&&spyx[i][j]==0&&zfp5x[i][j]==1)gisy[i][j]=2;
			if (dellax[i][j]==1&&spyx[i][j]==0&&zfp5x[i][j]==2)gisy[i][j]=2;
			if (dellax[i][j]==1&&spyx[i][j]==1&&zfp5x[i][j]==0)gisy[i][j]=1;//0
			if (dellax[i][j]==1&&spyx[i][j]==1&&zfp5x[i][j]==1)gisy[i][j]=1;
			if (dellax[i][j]==1&&spyx[i][j]==1&&zfp5x[i][j]==2)gisy[i][j]=1;
			if (dellax[i][j]==1&&spyx[i][j]==2&&zfp5x[i][j]==0)gisy[i][j]=0;
			if (dellax[i][j]==1&&spyx[i][j]==2&&zfp5x[i][j]==1)gisy[i][j]=0;
			if (dellax[i][j]==1&&spyx[i][j]==2&&zfp5x[i][j]==2)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==0&&zfp5x[i][j]==0)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==0&&zfp5x[i][j]==1)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==0&&zfp5x[i][j]==2)gisy[i][j]=1;
			if (dellax[i][j]==2&&spyx[i][j]==1&&zfp5x[i][j]==0)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==1&&zfp5x[i][j]==1)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==1&&zfp5x[i][j]==2)gisy[i][j]=1;
			if (dellax[i][j]==2&&spyx[i][j]==2&&zfp5x[i][j]==0)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==2&&zfp5x[i][j]==1)gisy[i][j]=0;
			if (dellax[i][j]==2&&spyx[i][j]==2&&zfp5x[i][j]==2)gisy[i][j]=0;
			
			
			if (gax[i][j]==0&&ckx[i][j]==0)spyy[i][j]=1;
			if (gax[i][j]==0&&ckx[i][j]==1)spyy[i][j]=2;
			if (gax[i][j]==0&&ckx[i][j]==2)spyy[i][j]=2;
			if (gax[i][j]==1&&ckx[i][j]==0)spyy[i][j]=1;
			if (gax[i][j]==1&&ckx[i][j]==1)spyy[i][j]=1;
			if (gax[i][j]==1&&ckx[i][j]==2)spyy[i][j]=2;
			if (gax[i][j]==2&&ckx[i][j]==0)spyy[i][j]=0;
			if (gax[i][j]==2&&ckx[i][j]==1)spyy[i][j]=0;
			if (gax[i][j]==2&&ckx[i][j]==2)spyy[i][j]=0;
			
			
			if (zfp6x[i][j]==0)zfp5y[i][j]=0;
			if (zfp6x[i][j]==1)zfp5y[i][j]=1;
			if (zfp6x[i][j]==2)zfp5y[i][j]=2;
			
			
			if (gax[i][j]==0&&ckx[i][j]==0)zfp6y[i][j]=0;
			if (gax[i][j]==0&&ckx[i][j]==1)zfp6y[i][j]=0;
			if (gax[i][j]==0&&ckx[i][j]==2)zfp6y[i][j]=1;
			if (gax[i][j]==1&&ckx[i][j]==0)zfp6y[i][j]=0;
			if (gax[i][j]==1&&ckx[i][j]==1)zfp6y[i][j]=1;
			if (gax[i][j]==1&&ckx[i][j]==2)zfp6y[i][j]=2;
			if (gax[i][j]==2&&ckx[i][j]==0)zfp6y[i][j]=1;
			if (gax[i][j]==2&&ckx[i][j]==1)zfp6y[i][j]=2;
			if (gax[i][j]==2&&ckx[i][j]==2)zfp6y[i][j]=1;//2
			
			
			if (spyx[i][j]==0&&ckx[i][j]==0)zfpgisy[i][j]=0;
			if (spyx[i][j]==0&&ckx[i][j]==1)zfpgisy[i][j]=0;//ZFP6/GIS3/ZFP5
			if (spyx[i][j]==0&&ckx[i][j]==2)zfpgisy[i][j]=1;
			if (spyx[i][j]==1&&ckx[i][j]==0)zfpgisy[i][j]=0;
			if (spyx[i][j]==1&&ckx[i][j]==1)zfpgisy[i][j]=1;
			if (spyx[i][j]==1&&ckx[i][j]==2)zfpgisy[i][j]=2;
			if (spyx[i][j]==2&&ckx[i][j]==0)zfpgisy[i][j]=1;
			if (spyx[i][j]==2&&ckx[i][j]==1)zfpgisy[i][j]=2;
			if (spyx[i][j]==2&&ckx[i][j]==2)zfpgisy[i][j]=2;
			
			
			if (mir156x[i][j]==0)spl9y[i][j]=2;
			if (mir156x[i][j]==1)spl9y[i][j]=1;
			if (mir156x[i][j]==2)spl9y[i][j]=0;
			
			if (edadx[i][j]==0)mir156y[i][j]=0;
			if (edadx[i][j]==1)mir156y[i][j]=1;
			if (edadx[i][j]==2)mir156y[i][j]=2;
			
			if (gl3x[i][j]==0)upl3y[i][j]=0;
			if (gl3x[i][j]==1)upl3y[i][j]=1;
			if (gl3x[i][j]==2)upl3y[i][j]=2;
			
			
			if (gax[i][j]==0)dellay[i][j]=2;
			if (gax[i][j]==1)dellay[i][j]=1;
			if (gax[i][j]==2)dellay[i][j]=0;
			
			//JAZ
			
			if (jax[i][j]==0)jazy[i][j]=2;
			if (jax[i][j]==1)jazy[i][j]=1;
			if (jax[i][j]==2)jazy[i][j]=0;
			
			// GA
			if (gax[i][j]==0)gay[i][j]=0;
			if (gax[i][j]==1)gay[i][j]=1;
			if (gax[i][j]==2)gay[i][j]=2;
			
			//CK
			if (ckx[i][j]==0)cky[i][j]=0;
			if (ckx[i][j]==1)cky[i][j]=1;
			if (ckx[i][j]==2)cky[i][j]=2;
			
			//JA
			if (jax[i][j]==0)jay[i][j]=1;
			if (jax[i][j]==1)jay[i][j]=1;
			if (jax[i][j]==1&&herbx[i][j]==2)jay[i][j]=1;
			if (jax[i][j]==2)jay[i][j]=1;
			
			//HERBIVORIA
			if (herbx[i][j]==0)herby[i][j]=1;
			if (herbx[i][j]==1)herby[i][j]=1;
			if (herbx[i][j]==2)herby[i][j]=1;
			
			//EDAD
			if (edadx[i][j]==0)edady[i][j]=1;
			if (edadx[i][j]==1)edady[i][j]=1;
			if (edadx[i][j]==2)edady[i][j]=1;
			
			
			
			/*if(AC[i][j]==3){
				atmyc1y[i][j]=0;//rand()%2;//0
				myb23y[i][j]=1;//rand()%2;//0
				ttg1y[i][j]=1;//1
				etcsy[i][j]=0;//0
				ttg2y[i][j]=0;//1
			}*/
			

			if(AC[i][j]==0){//0,0 inestable
				atmyc1y[i][j]=0;//rand()%2;//0
				myb23y[i][j]=1;//rand()%2;//0
				ttg1y[i][j]=1;//1
				etcsy[i][j]=0;//0
				ttg2y[i][j]=0;//1
			}
			
			if(AC[i][j]==1){
				atmyc1y[i][j]=1;//1
				myb23y[i][j]=2;//1
				ttg1y[i][j]=1;//1
				etcsy[i][j]=1;//1
				ttg2y[i][j]=1;//1
			}
			
			if(AC[i][j]==2){
				atmyc1y[i][j]=1;//2 // loop de reg neg
				myb23y[i][j]=2;//2 // loop de reg neg
				ttg1y[i][j]=1;//1
				etcsy[i][j]=1;//1
				ttg2y[i][j]=2;//1
			}
			

		}}//cierran ij
		
		if(rand()%2==0)GA=1;
		else GA=1;
		
	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			gl1x[i][j]=gl1y[i][j];
			gl3x[i][j]=gl3y[i][j];
			egl3x[i][j]=egl3y[i][j];
			atmyc1x[i][j]=atmyc1y[i][j];
			myb23x[i][j]=myb23y[i][j];
			ttg1x[i][j]=ttg1y[i][j];
			cpcx[i][j]=cpcy[i][j];
			tryx[i][j]=tryy[i][j];
			etcsx[i][j]=etcsy[i][j];
			tclsx[i][j]=tclsy[i][j];
			ttg2x[i][j]=ttg2y[i][j];
			mir156x[i][j]=mir156y[i][j];
			gisx[i][j]=gisy[i][j];
			spyx[i][j]=spyy[i][j];
			zfpgisx[i][j]=zfpgisy[i][j];
			zfp5x[i][j]=zfp5y[i][j];
			zfp6x[i][j]=zfp6y[i][j];
			spl9x[i][j]=spl9y[i][j];
			upl3x[i][j]=upl3y[i][j];
			dellax[i][j]=dellay[i][j];
			jazx[i][j]=jazy[i][j];
			gax[i][j]=gay[i][j];
			jax[i][j]=jay[i][j];
			herbx[i][j]=herby[i][j];
			edadx[i][j]=edady[i][j];
			ckx[i][j]=cky[i][j];
		}
		}
		
}//cierra itera

void imprimeAI(){//imprime la matriz con los valores de Activador e Inhibidor
	for (k=0;k<cel;k++){
		for(l=0;l<cel;l++){
			printf(" %d ", ACint[k][l]);
			}puts("");
	}puts("");
}

void imprimeCPCD(){//imprime la matriz con los valores de Activador e Inhibidor
	for (k=0;k<cel;k++){
		for(l=0;l<cel;l++){
			printf(" %d ", cpcDif[k][l]);
			}puts("");
	}puts("");
}

void imprimeTRYD(){//imprime la matriz con los valores de Activador e Inhibidor
	for (k=0;k<cel;k++){
		for(l=0;l<cel;l++){
			printf(" %d ", tryDif[k][l]);
		}puts("");
	}puts("");
}

void imprimeTTGD(){//imprime la matriz con los valores de Activador e Inhibidor
	for (k=0;k<cel;k++){
		for(l=0;l<cel;l++){
			printf(" %d ", ttgDif[k][l]);
		}puts("");
	}puts("");
}


void imprimeVector(){//imprime la matriz con los vectores de todos los elementos
	for (k=0;k<cel;k++){
		for(l=0;l<cel;l++){
			printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ||", ACint[k][l],gl1x[k][l],gl3x[k][l],egl3x[k][l],atmyc1x[k][l],myb23x[k][l],ttg1x[k][l],tryx[k][l],etcsx[k][l],tclsx[k][l],cpcx[k][l],ttg2x[k][l],mir156x[k][l],gisx[k][l],spyx[k][l],zfpgisx[k][l],zfp5x[k][l],zfp6x[k][l],spl9x[k][l],upl3x[k][l],dellax[k][l],jazx[k][l],gax[k][l],ckx[k][l],jax[k][l],herbx[k][l],edadx[k][l],IC[k][l]);
		}puts("");
	}puts("");
	
}

void imprimeSuma(){//imprime las matrices de sumas
	for (k=0;k<cel;k++){
		for(l=0;l<cel;l++){
			printf("%d %d, ", sumaAC[k][l], sumaIC[k][l]);
			}puts("");
	}puts("");
	//printf("%d", sumaA);puts("");
}



difundeCPC(){//discretizacion dej laplaciano con condiciones de frontera de cero fjujo
	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			
			volado=rand()%10;
			
			if(volado>=5){
			if(i==0){
				if(j==0){
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i+1][j]+cpcx[i][j+1]-2*cpcx[i][j]);
				}
				else if(j==(cel-1)){
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i][j-1]+cpcx[i+1][j]-2*cpcx[i][j]);
				}
				else{
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i+1][j]+cpcx[i][j+1]+cpcx[i][j-1]-3*cpcx[i][j]);
				}
			}
			
			else if(i==(cel-1)){
				if(j==0){
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i-1][j]+cpcx[i][j+1]-2*cpcx[i][j]);
				}
				else if(j==(cel-1)){
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i-1][j]+cpcx[i][j-1]-2*cpcx[i][j]);
				}
				else{
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i-1][j]+cpcx[i][j+1]+cpcx[i][j-1]-3*cpcx[i][j]);
				}
			}
			
			else if(j==0&&i!=(cel-1)&&i!=0){
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i-1][j]+cpcx[i][j+1]+cpcx[i+1][j]-3*cpcx[i][j]);
			}
			
			else if(j==(cel-1)&&i!=(cel-1)&&i!=0){
				cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i-1][j]+cpcx[i+1][j]+cpcx[i][j-1]-3*cpcx[i][j]);
			}

			else{
			cpcn[i][j]=cpcx[i][j]+DifCPC*(cpcx[i+1][j]+cpcx[i-1][j]+cpcx[i][j+1]+cpcx[i][j-1]-4*cpcx[i][j]);
			}
			
			cpcDif[i][j]=H(cpcn[i][j]);
			}//volado
		}//i
	}//j
	
}



difundeTRY(){//discretizacion dej laplaciano con condiciones de frontera de cero fjujo
	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			
			volado=rand()%10;
			
			if(volado>=5){
			if(i==0){
				if(j==0){
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i+1][j]+tryx[i][j+1]-2*tryx[i][j]-2*tryx[i][j]);
				}
				else if(j==(cel-1)){
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i][j-1]+tryx[i+1][j]-2*tryx[i][j]-2*tryx[i][j]);
				}
				else{
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i+1][j]+tryx[i][j+1]+tryx[i][j-1]-3*tryx[i][j]-3*tryx[i][j]);
				}
			}
			
			else if(i==(cel-1)){
				if(j==0){
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i-1][j]+tryx[i][j+1]-2*tryx[i][j]-2*tryx[i][j]);
				}
				else if(j==(cel-1)){
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i-1][j]+tryx[i][j-1]-2*tryx[i][j]-2*tryx[i][j]);
				}
				else{
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i-1][j]+tryx[i][j+1]+tryx[i][j-1]-3*tryx[i][j]-3*tryx[i][j]);
				}
			}
			
			else if(j==0&&i!=(cel-1)&&i!=0){
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i-1][j]+tryx[i][j+1]+tryx[i+1][j]-3*tryx[i][j]-3*tryx[i][j]);
			}
			
			else if(j==(cel-1)&&i!=(cel-1)&&i!=0){
				tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i-1][j]+tryx[i+1][j]+tryx[i][j-1]-3*tryx[i][j]-3*tryx[i][j]);
			}

			else{
			tryn[i][j]=tryx[i][j]+DifTRY*(tryx[i+1][j]+tryx[i-1][j]+tryx[i][j+1]+tryx[i][j-1]-4*tryx[i][j]-4*tryx[i][j]);
			}
			
			tryDif[i][j]=H(tryn[i][j]);
			}//volado
		}//i
	}//j
	
}

difundeTTG(){//discretizacion dej laplaciano con condiciones de frontera de cero fjujo
	for(i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			
			volado=rand()%10;
			
			if(volado>=5){
			if(i==0){
				if(j==0){
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i+1][j]+ttg1x[i][j+1]-2*ttg1x[i][j]);
				}
				else if(j==(cel-1)){
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i][j-1]+ttg1x[i+1][j]-2*ttg1x[i][j]);
				}
				else{
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i+1][j]+ttg1x[i][j+1]+ttg1x[i][j-1]-3*ttg1x[i][j]);
				}
			}
			
			else if(i==(cel-1)){
				if(j==0){
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i-1][j]+ttg1x[i][j+1]-2*ttg1x[i][j]);
				}
				else if(j==(cel-1)){
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i-1][j]+ttg1x[i][j-1]-2*ttg1x[i][j]);
				}
				else{
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i-1][j]+ttg1x[i][j+1]+ttg1x[i][j-1]-3*ttg1x[i][j]);
				}
			}
			
			else if(j==0&&i!=(cel-1)&&i!=0){
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i-1][j]+ttg1x[i][j+1]+ttg1x[i+1][j]-3*ttg1x[i][j]);
			}
			
			else if(j==(cel-1)&&i!=(cel-1)&&i!=0){
				In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i-1][j]+ttg1x[i+1][j]+ttg1x[i][j-1]-3*ttg1x[i][j]);
			}

			else{
			In[i][j]=ttg1x[i][j]+DifA*(ttg1x[i+1][j]+ttg1x[i-1][j]+ttg1x[i][j+1]+ttg1x[i][j-1]-4*ttg1x[i][j]);
			}
			
			ttgDif[i][j]=H(In[i][j]);
			}//volado
		}//i
	}//j
	
}



Distancia(){// esta funcion calcula la distancia minima promedio entre pelos
int CoordX[10000];
int CoordY[10000];
float Dist[100000];
float D; 
float s=0.0;


NoP=0;//NoP cuenta ej numero de pelos
for (i=0;i<cel;i++){
		for(j=0;j<cel;j++){
			if(ACint[i][j]>0){
				CoordX[NoP]=i;
				CoordY[NoP]=j;
				NoP++;
			}
		}
}

printf("pelos %d\n",NoP);

float minima=1000000;//aqui, minima vale lo que la dist max posible en condiciones de cero fluj0
if(NoP>1){
for(i=0;i<NoP;i++){
	for(j=0;j<NoP;j++){
		D=sqrt(((CoordX[i]-CoordX[j])*(CoordX[i]-CoordX[j]))+((CoordY[i]-CoordY[j])*(CoordY[i]-CoordY[j])));
		if((D<minima)&&(D>0))minima=D;
		//printf("%f\n", D);
	}
	
	Dist[i]=minima;
	minima=1000000;
}

for(i=0;i<NoP;i++){
	//printf("%f\n", Dist[i]);
	//puts("");
	s=s+Dist[i];
}

Rd=s/NoP; 
Ra=1/(2*(sqrt(NoP/(400.0))));
sumR=sumR+(Rd/Ra);
R[muestra]=Rd/Ra;
muestra++;//numero de matrices con m'as de un pelo
}//cierra NoP
}//cierra distancia


main(){
int ite;
srand(time(NULL));
//srand(453);
for(w=0;w<26;w++){
DifCPC=0.01*w;
DifTRY=0.01*w;
DifA=0.01*w;
//DifI=0.2;
printf("DI %.3f\n", DifCPC);
sumR=0;varR=0;
muestra=0;raro=0;
for(veces=0;veces<1;veces++){//de cero a cien
//IniciajesOrden();
Iniciales();
//imprimeVector();
//imprimeAI();
for (ite=0;ite<100;ite++){
		itera();//aqui se apjican jas reglas de jas tabjas
		difundeCPC();
		difundeTRY();	
		difundeTTG();	
		
}
Distancia();
}
promR=sumR/muestra;//obtiene promedio
for(u=0;u<muestra;u++){
varR=varR+((R[u]-promR)*(R[u]-promR));
}
		imprimeAI();
		//imprimeVector();
		//imprimeCPCD();
		//imprimeTRYD();
		//imprimeTTGD();

sR=varR/(muestra-1);//obtiene varianza
stdev=sqrt(sR);//obtiene desviacion estandar
printf(" <R> %f",promR);
printf(" +- %f\n",stdev);

}
}
