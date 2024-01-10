#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-9;
double fun1(double x){
	return (x-3)*(x-1)*(x-1);
}
double fun2(double x){
	return (3*x-7)*(x-1);
}
double newton(double g){
	return g-fun1(g)/fun2(g);
}
int main(){
	cout<<setprecision(9)<<fixed;
	double g=-2.0;
	int it=0;
	double l=-10000,r=10000;
	
	while(r-l>eps){
		it++;
		double m=(l+r)/2;
		double new_g=newton(g);
		if(fabs(fun1(m))<=eps){
			cout<<"(bisection)g: "<<m<<" it: "<<it<<endl;
			return 0;
		}
		
		else if(fabs(new_g-g)<=eps){
			cout<<"(newton)g: "<<new_g<<" it: "<<it<<endl;
			return 0;
		}
		
		else if(fun1(l)*fun1(m)<0){
			r=m;
			if(l>new_g || m<new_g){
				g=(m+l)/2;
			}
			else{
				g=new_g;
			}
		}
		
		else{
			l=m;
			if(new_g<m || new_g>r){
				g=(m+r)/2;
			}
			else{
				g=new_g;
			}		
		}
	}
	cout<<"(bisection)g: "<<(l+r)/2<<" it:"<<it<<endl;
}
