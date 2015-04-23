/* 
* TP #2 Operaciones con variables primitivas y string

* Martin Ribola, Cynthia Natalia Soledad 

* 23/04/15

*/
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int nota1, nota2, nota3;
    double promedio, promAprob=4;
    string outp="no regularizo";
    bool presentismo;
    
    cin>>nota1;
    cin>>nota2;
    cin>>nota3;
    cin>>presentismo;
    promedio=(nota1+nota2+nota3)/3; //operacion con int
    
    if((promedio>=promAprob)&&presentismo) //operacion con double, operacion con boolean
    outp="regularizo";
    
    cout<<outp+" la materia"<<endl; //operacion con string
    if(outp[0]=='n') cout<<"no aprobo"<<endl; //operacion con char
    if(outp.length()>10) cout<<"no aprobo"<<endl; //más operaciones con string
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
