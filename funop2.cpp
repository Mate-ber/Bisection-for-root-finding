#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-9;
const double alp=1e-4;
double fun1(double x,double number){
    return 0.5*(x+number/x);
}
double fun2(double x){
	return x-alp*(x*x-x-4);
}
void sqrtfun(){
	double num=100.0;
    double g=2.0;
    int it=0;
	while(1){
		it++;
		double g_next=fun1(g,num);
		if(fabs(g_next-g)<eps){
			g=g_next;
			break;
		}
		g=g_next;
		if(it==100000){
			cout<<"invalid num"<<endl;
			return;
		}
	}
    cout<<"Num: "<<num<<" guess of pos: "<<g<<" itterations: "<<it<<endl;
}
void modifiedalpha(){
	double g=2.0;
	int it=0;
	while(1){
		it++;
		double g_next=fun2(g);
		if(fabs(g_next-g)<eps){
			g=g_next;
			break;
		}
		g=g_next;
		if(it==100000){
			cout<<"invalid"<<endl;
			return;
		}
	}
	cout<<"guess of pos(for x^x-4): "<<g<<" itterations: "<<it<<endl;
}
int main(){
	cout<<setprecision(9)<<fixed;
	sqrtfun();
    modifiedalpha();
    return 0;
}
