#include <iostream>
#include <cmath>
#include <limits>
#define M 1000000
#define delta 0.00000001
#define epsilon 0.00000001
using namespace std;

const double pi = acos(-1);


class EquationSolver{
private:
    char c='0';
    double x=-1;
    double A1,B1,C1,E1;
    double *A=&A1,*B=&B1,*C=&C1,*E=&E1,l,b1,D,h;
public:
    int count=0;
    virtual double solve(){
        return 0;
    }
    void find_ABCE(double l,double b1,double D,double h){
        cin>>l>>b1>>D>>h;
        cout<<endl;
        A1=l*sin(b1);
        B1=l*cos(b1);
        C1=(h+0.5*D)*sin(b1)-0.5*D*tan(b1);
        E1=(h+0.5*D)*cos(b1)-0.5*D;
    }
    
    double f(char c,double x){
        
        switch (c) {
            case '1':
                return 1/x-tan(x);
                break;
            case '2':
                return 1/x-pow(2,x);
                break;
            case '3':
                return 1/(pow(2,x))+exp(x)+2*cos(x)-6;
                break;
            case '4':
                return (pow(x, 3)+4*pow(x, 2)+3*x+5)/(2*pow(x, 3)-9*pow(x, 2)+18*x-2);
                break;
            case '5':
                return x-tan(x);
                break;
            case 'd':       //Diff of 5
                return 1-1/(cos(x)*cos(x));
            case '6':
                return sin(x/2)-1;
                break;
            case '7':
                return exp(x)-tan(x);
                break;
            case '8':
                return pow(x, 3)-12*pow(x,2)+3*x+1;
                break;
            case '9':
                return 12.4-10*(pi/2-asin(x)-x*sqrt(1-pow(x, 2)));
                break;
            case 'z':       //Diff of 9
                return 10/(sqrt(1-x*x))-10*x*x/(sqrt(1-x*x))+10*sqrt(1-x*x);
            case 'F':
                if(count==0){
                    find_ABCE(l, b1, D, h);
                    count++;
                }
                double A,B,C,E;
                A=A1;
                B=B1;
                C=C1;
                E=E1;
                return A*sin(x)*cos(x)+B*sin(x)*sin(x)-C*cos(x)-E*sin(x);
                break;
            case 'f':
                A=A1;
                B=B1;
                C=C1;
                E=E1;
                return A*cos(2*x)+B*sin(2*x)+C*sin(x)-E*cos(x);
                break;
            default:
                return 0;
                break;
        }
    }
};

class bisection:public EquationSolver{
private:
    double u,v,x,h,c,w;
    int sgn(double x){
        if(x>0){
            return 1;
        }
        else if(x<0){
            return -1;
        }
        else return 0;
    }
public:
    double solve(char C,double a,double b){
        u=f(C,a);
        v=f(C,b);
        if(sgn(u)==sgn(v)){
            cout<<"NO ROOT IS IN THE INTERVAL";
            return 0;
        }
        else{
            for(int k=1;k<=M;k++){
                h=b-a;
                c=a+h*1.0/2;
                w=f(C,c);
                if(fabs(h)<delta||fabs(w)<epsilon){
                    break;
                }
                else if (sgn(w)!=sgn(u)){
                    b=c;
                    v=w;
                }
                else{
                    a=c;
                    u=w;
                }
            }
            return c;
        }
    };
    /*double solve(char C,double a,double b){
        if(sgn(f(C,a)!=sgn(f(C,b)))){
            h=b-a;
            u=f(C,a);
            for(int k=1;k<=M;k++){
                h=h/2;
                c=a+h;
                w=f(C,c);
                if((fabs(h)<delta)||fabs(w)<epsilon){
                    break;
                }
                else if(sgn(w)==sgn(u)){
                    a=c;
                }
            }
        }
        return c;
    }*/

};

class newton:public EquationSolver{
private:
    double x=1;
public:
    double solve1(char C,double x_0){
        double u;
        x=x_0;
        for(int k=0;k<=M;k++){
            u=f(C,x);
            if(fabs(u)<epsilon){
                break;
            }
            x=x-u/f('d',x);
        }
        return x;
    }
    double solve2(char C,double x_0){
        double u;
        x=x_0;
        for(int k=0;k<=M;k++){
            u=f(C,x);
            if(fabs(u)<epsilon){
                break;
            }
            x=x-u/f('z',x);
        }
        return x;
    }
    double solve3(char C,double x_0){
        double u;
        x=x_0;
        for(int k=0;k<=M;k++){
            u=f(C,x);
            if(fabs(u)<epsilon){
                break;
            }
            x=x-u/f('f',x);
        }
        return x;
    }
};
    
class secant:public EquationSolver{
private:
    double u,v,s;
public:
    double solve(char C,double x_0,double x_1){
        /*if(x_0>x_1){
            swap(x_0, x_1);
        }*/
        u=f(C,x_1);
        v=f(C,x_0);
        for(int k=2;k<=M;k++){
            if(fabs(u)>fabs(v)){
                swap(x_1, x_0);
                swap(u,v);
            }
            s=(x_1-x_0)/(u-v);
            x_0=x_1;
            v=u;
            x_1=x_1-u*s;
            u=f(C,x_1);
            if(fabs(x_1-x_0)<delta||fabs(u)<epsilon){
                break;
            }
        }
        return x_1;
    }
};
    
