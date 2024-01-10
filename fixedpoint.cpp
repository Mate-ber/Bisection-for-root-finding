#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-9;
const double alp=0.08;
double fun1(double x,double number){
    return 0.5*(x+number/x);
}
double fun2(double x){
//	return x-alp*(x*x-x-4);
	return 2*sin(x)-2;
}
void sqrtfun(){
	double num=5.0;
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
    cout<<"Num: "<<num<<" guess: "<<g<<" itterations: "<<it<<endl;
}
void modifiedalpha(){
	
	ofstream cout;
    cout.open ("data4.txt");
	double g=0;
	int it=0;
	while(1){
		it++;
		double g_next=alp*fun2(g)-(1-alp)*g;
		cout<<fabs(g_next-g)<<" "<<it<<endl;
		if(fabs(g_next-g)<eps){
			g=g_next;
			break;
		}
		g=g_next;
//		if(it==100000){
//			cout<<"invalid"<<endl;
//			return;
//		}
	}
//	cout<<"guess: "<<g<<" itterations: "<<it<<endl;
//	cout<<2*sin(g)-g<<endl;
}
int main(){
	cout<<setprecision(9)<<fixed;
//	sqrtfun();
    modifiedalpha();
    return 0;
}
