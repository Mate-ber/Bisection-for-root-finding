#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-9;
double fun1(double x){
	return 2*sin(x)-2;
}
double fun2(double x){
	return 2*cos(x);
}
double newton(double g){
	return g-fun1(g)/fun2(g);
}
int main(){
	cout<<setprecision(9)<<fixed;
//    ofstream cout;
//    cout.open ("data2.txt");
    
	double g=0;
	int it=0;
	double l=-2,r=2;
	
	while(r-l>eps){
		it++;
		double m=(l+r)/2;
		double new_g=newton(g);
		
		cout<<min(fabs(new_g-g),(r-l))<<" "<<it<<endl;
		
		if(fabs(new_g-g)<=eps){
//			cout<<"(newton)g: "<<new_g<<" it: "<<it<<endl;
			return 0;	
		}
		
		else if(fun1(l)*fun1(m)<0){
			r=m;
			if(l<=new_g && new_g<=r){
				g=new_g;
			}
			else{
				g=(l+r)/2;
			}
		}
		
		else{
			l=m;
			if(l<=new_g && new_g<=r){
				g=new_g;
			}
			else{
				g=(l+r)/2;
			}	
		}
	}
//	cout<<"(bisection2)g: "<<(l+r)/2<<" it:"<<it<<endl;
}
