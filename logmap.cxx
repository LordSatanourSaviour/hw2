
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    double x0 = 0.5;
    double x;
    int Nskip = 100; //Number of iterations to skip
    int Nend  = 200; //Number of total iterations
    double xx[Nend-Nskip];
    ofstream out("output_logmap.dat");
    
    for(double r=0; r <= 4; r += 0.001){
        x=x0;
        for(int k=1; k <= Nskip; k++)
            x = r*x*(1-x);
        for(int i=Nskip+1; i <= Nend; i++){
            x = r*x*(1-x);
            xx[i-Nskip-1]=x;
            
            
        }
        for(int j=0;j<=(Nend-Nskip);j++){
            out << r << "\t" << xx[j] << endl;
            
        }
    }
    
    out.close();
    return 0;
}
