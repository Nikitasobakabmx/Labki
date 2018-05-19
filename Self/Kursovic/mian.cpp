#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define n 5
#define m 3
void koeff(float x[n], float y[n], float A[m][m], float B[m]);
void value(float C[m], float x[n], float y[n], float &Kr, float Yl[n], float D[n]);
void maxi(float D[n], float x[n], float &Dmax, int &IM);
float fi(float x,int g);
void zeydel(float A[m][m], float B[m], float C[m]); 
int Shod(float A[m][m]); // проверка сходимости
float R[m][m];
int main()
{ setlocale(LC_ALL, "RUS");
 int l,k,i,IM;
 float A[m][m],B[m],C[m],Yl[n],D[n],Kr,Dmax,x[5],y[5];
 printf("Аппроксимация функции методом наименьших квадратов\n");
 printf("Метод зейделя\n\n");             
 printf("\n x ");
 for(i=0;i<n;i++)
   scanf("%f",&x[i]);
   printf("\n y ");
   for(i=0;i<n;i++)
   scanf("%f",&y[i]);
 koeff(x,y,A,B);
 printf("Matrix A vector B:\n");
for(i=0;i<m;i++)
{
 for(k=0;k<m;k++) printf("%9.3f ",A[i][k]);
 printf("%9.3f \n",B[i]);
}
zeydel(A,B,C);
printf("\nVector C:\n");
 for(i=0;i<m;i++) printf("C[%d]=%6.3f\n",i,C[i]);
 value(x,y,C,Kr,Yl,D);
 printf("\n\n approximation criterion J = %.3f",Kr);
 maxi(D,x,Dmax,IM);
 printf("\n\n maximum deviation = %.3f, при x[%i] = %.1f\n\n",fabs(Dmax),IM+1,x[IM]);
 getch();
 return 0;
}
float fi(float x,int g)
{
if (g==0)
return (1);
else
if (g==1)
return (2*x);
else
if (g==2)
return 4*x*x-2;
}
void koeff(float x[n],float y[n],float A[m][m],float B[m])
{
 int i,j,l;
 float S;
 for(i=0;i<m;i++)
 {
for(j=0;j<m;j++)
 {
 S=0;
 for(l=0;l<n;l++)
 S=S+fi(x[l],i)*fi(x[l],j);
 A[i][j]=S;
 }
 S=0;
 for(l=0;l<n;l++)
 S=S+y[l]*fi(x[l],i);
B[i]=S;
}
}
void value(float x[n], float y[n], float C[m], float &Kr, float Yl[n], float D[n])
{
 int k,i;
 Kr=0;
 k=0;
 Yl[0]=0;
 for(i=0;i<n;i++)
 {
 Yl[i]=C[0]*fi(x[i],k)+C[1]*fi(x[i],k+1)+C[2]*fi(x[i],k+2);
 D[i]=y[i]-Yl[i];
 Kr=Kr+D[i]*D[i];
 }
 printf("\n values approximating function\n");
 for(i=0;i<=n-1;i++)
 {
 printf("%.3f ",Yl[i]);
 }
 printf("\n\n deviation values approximating function\n");
 for(i=0;i<=n-1;i++)
 {
 printf("%.3f ",D[i]);
 }
}
void maxi(float D[n], float x[n], float &Dmax, int &IM)
{
 int i;
 Dmax=D[0];
 IM=0;
 for(i=0;i<n;i++)
 {
 if(fabs(D[i])>fabs(Dmax))
 {
 Dmax=D[i];
 IM=i;
 }
 }
 printf("\n");
}
int Shod(float A[m][m])
{
   int flag = 0;
   for (int i=0;i<m;i++)
   {
     float Ad = fabs(A[i][i]);
     float Sd=0;
     for(int j=0; j<m; j++)
        if (j!=i) Sd+=fabs(A[i][j]);
     if (Ad>Sd) flag=1;
   }
   if (flag=1) return 0;
   else return 1;
}
void zeydel (float A[m][m], float B[m], float C[m])
{
	int Key;
    float eps = 0.001;
    Key=Shod(A);
    if (Shod(A)) return;
    for (int i=0;i<m;i++)
       C[i]=B[i];
    float test;
    do
    {
      test=0;
      for (int i=0;i<m;i++)
      {
         float sum=0;
         for (int j=0;j<m;j++)
            if (j!=i) sum+=A[i][j]*C[j];
            float bpx = (B[i]-sum)/A[i][i];
            test+=fabs(bpx-C[i]);
            C[i]=bpx;
      }
    }
    while (test>eps);
}

