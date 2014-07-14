#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.0000001
#define N 1000
double f(double x)
{
	{
		return pow(x,2)+40/x;
		//x1*x2+40*(1/x1+1/x2);
	}
}
double f2(double x,double X[N],int i)
{
	X[i]=x;//a1*L+a2*L*V*V*V
	return 2000*X[0]+5000*X[0]*pow(X[1],3);
}
double dichotomy(double left,double right,double eps)
{
	if ( fabs(right-left)/(2+eps)<=eps)
	{
		return (right+left)/2;
	}
	double mid2=(right+left)/2+eps;
	double mid1=(right+left)/2-eps;
	if ( f(mid1)<f(mid2))
	{
		return dichotomy(left,mid2,eps);
	}
	else
	{
		return dichotomy(mid1,right,eps);
	}
}
double dichotomy2(double left,double right,double eps,int i,double X[N])
{
	if ( fabs(right-left)/(2+eps)<=eps)
	{
		return (right+left)/2;
	}
	double mid2=(right+left)/2+eps;
	double mid1=(right+left)/2-eps;
	if ( f2(mid1,X,i)<f2(mid2,X,i))
	{
		return dichotomy2(left,mid2,eps,i,X);
	}
	else
	{
		return dichotomy2(mid1,right,eps,i,X);
	}
}
int main()
{
	double X[N]={1+EPS};
	double XP[N]={1};
	//Q=( (x1*x2)^2+20x2+20x1)/(x1x2)
  printf("%lf\n",dichotomy(0+EPS,10,EPS));
	int i=0,j=0;
	while (fabs(XP[0]-X[0])>EPS)
	{
		for ( j=0;j<2;j++)
		{
			XP[j]=X[j];
			X[j]=dichotomy2(0+EPS,100,EPS,j,X);
		}
	}
	for ( i=0;i<2;i++)
		printf("%lf ",X[i]);
	system("pause");
	return 0;
}
