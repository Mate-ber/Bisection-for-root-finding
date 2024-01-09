#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-3;
double fun1(double x){
	return (x-3)*(x-1)*(x-3)*(x-1);
}
double fun2(double x){
	return 4*(x-3)*(x-2)*(x-1);
}	
int main(){
	cout<<setprecision(9)<<fixed;
	double g=-2;
	int it=0;
	double l=eps,r=1e9;
	bool b=true;
	while(r-l>eps){
		it++;
		double m=(l+r)/2;
		double g_next=g-fun1(g)/fun2(g);
		
		if(fabs(fun1(m))<=eps){
			cout<<"guess: "<<m<<" it: "<<it<<endl;
			return 0;
		}
		else if(fabs(g_next-g)<=eps){
			g=g_next;
			break;
		}
		else if(b){
			if(fun1(l)*g_next<0){
				r=g_next;
			}
			else if(fun1(l)*fun1(m)<0){
				r=m;
			}
			else{
				l=m;
			}
		}
		g=g_next;
	}
	cout<<"guess: "<<g<<" it:"<<it<<endl;
}
