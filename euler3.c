#include<stdio.h>
#define	n  600
double func1(double x,double v);
double func2(double x,double v);


void main(){
	FILE *fp1,*fp2;
	double k=2.880;//バネ係数
	double m=2.0;//室力
	double sqrt_omega=-1*(k/m);//kx
	double x_one,x_two;//
	double v_one,v_two;//速度　v(t)
	double x_t[n];
	double v_t[n];
	double dt=0.05;//⊿
	
	x_t[0]=0.5;
	v_t[0]=0.0;
	x_one=0.0;
	x_two=0.0;
	v_one=0.0;
	//v_t[i]=v_t[i-1]-sqrt_omega*x_t[i-1]*dt;
	//x_t[i]=x_t[i-1]+dt*v_t[i-1];

	for(int i=0;i<n;i++){
		x_one = v_t[i];
		v_one = sqrt_omega*x_t[i];	

		x_two=v_t[i] + dt*x_one;
 		v_two=sqrt_omega* (x_t[i] + dt*v_one);
		
		x_t[i+1]=x_t[i]+ dt*(x_one+x_two)*0.5;
        v_t[i+1]=v_t[i]+ dt*(v_one+v_two)*0.5;

	}





  fp1=fopen("euler3_vt.txt","w+");
	fp2=fopen("euler3_xt.txt","w+");

	for(int i=0;i<n;i++)
		fprintf(fp1,"%d %lf\n",i,v_t[i]);

	for(int i=0;i<n;i++)
		  fprintf(fp2,"%d %lf\n",i,x_t[i]);

fclose(fp1);
fclose(fp2);
return;
}

double func1(double x,double v){//x
            return -1*(2.88/2.0)*x;
}

double func2(double x,double v){//v
           return v;
}
