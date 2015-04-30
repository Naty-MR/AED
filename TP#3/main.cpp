/* 
* TP #3 Juego de preguntas y respuestas

* Martin Ribola, Cynthia Natalia Soledad 

* 29/04/15
*/
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

void printCent(string cad);
int jugar();
void verReglas();
void verRecord();
void gameOver(int puntaje);
bool sinContestar(char resp[4][4], int op);


int record=0;
string recordNomb="";
string preg[4][4] = {//Ciencias Naturales
                 {"Cuantas patas tiene un caballo?\n1. 4\n2. 2\n3. 0",
                  "Cuál es el unico mamifero con cuatro rodillas?\n1. Jirafa\n2. Gorila\n3. Elefante",
                  "Cuál de los cinco sentidos se desarrolla el primero?\n1. Olfato\n2. Audicion\n3. Tacto",
                  "Las arañas pertenecen a los artropodos?\n1. No, son insectos\n2. No, son aracnidos\n3. Si"
                  }, 
                 //Historia
                 {"Cuando comenzaron las cruzadas?\n1. 1010\n2. 1096\n3. 1291",
                 "Cuanto mide la muralla china?\n1. 1530km\n2. 670km\n3. 2400km",
                 "Con cuantos soldados fue Leonidas al paso de las termopidas?\n1. 300\n2. 1500\n3. 6000",
                 "Que paises apoyaron a Vietnam del norte durante la guerra de Vietnam?\n1. China, Corea del Norte y URSS\n2. China, URSS y Laos\n3. Camboya, URSS y Laos"
                 },
                 //Curiosidades
                 {"Cual es el ojo defectuoso de Popeye?\n1. El derecho\n2. El izquierdo\n3. Ambos",
                 "Cuantas personas se refugiaron en el Arca de Noe?\n1. 2\n2. 4\n3. 8",
                 "Como se transmiten mas rapidamente las ondas sonoras?\n1. A travez del aire\n2. A travez del agua\n3. A travez de la tierra", 
                 "Con qué dos color/es suele tener problemas un daltonico?\n1. Rojo\n2. Verde\n3. Ambos"
                 },
                 //Informatica General
                 {"Cuantos MB almacena un CD?\n1. 1200\n2. 700\n3. 300",
                 "En C++ si se tiene un puntero a un objeto, para acceder a los miembros de la clase se emplea:\n1. ->\n2. .\n3. &",
                 "Cual no es un nivel de visibilidad en C++?\n1. public\n2. hidden\n3. protected",
                 "En HTML, para definir que el idioma principal de una página es el español se emplea:\n1. <html lang=\"es\">\n2. <head lang=\"es\"> \n3. <html id=\"es\"> "
                 }};
char resp[4][4] = {{'2','3','1','3'},
                 {'2','3','3','1'},
                 {'1','3','2','3'},
                 {'2','1','2','1'}}; 

int main(int argc, char *argv[])
{    
    char op;
    do{        
    system("cls");
    printCent("Bienvenido a este juego de preguntas y respuestas!");
    printCent("0 : *Jugar*");
    printCent("1 : Reglas ");    
    printCent("2 : Records");
    printCent("3 : Salir  ");
    cin>>op;
    if(op=='0')gameOver(jugar());
    else if(op=='1') verReglas();
    else if(op=='2') verRecord();
    else if(op!='3'){         
         system("cls");
         printCent("ingrese un valor valido");
         system ("pause");
         }
         
    } while(op!='3');
         
    return EXIT_SUCCESS;
}

int jugar()
{
 int puntj=0;
 int op=-1;
 char resp[4][4];
for(int i=0; i<4; i++)
{
        for(int j=0; j<4; j++)
        resp[i][j] = ::resp[i][j];
}
 do
 {
 if(op==-1)
 {
 do{
 system("cls");
 printCent("Elija una categoria:");   
 printCent("0 : Ciencias naturales");
 printCent("1 : Historia          ");    
 printCent("2 : Curiosidades      ");
 printCent("3 : Informatica       ");
 printCent("4 : Salir             ");
 cin>>op;
 if(op<0||op>4){         
             system("cls");
             printCent("ingrese un valor valido");
             system ("pause");
             op=-1;
             }
 else{
 if(op==4) return puntj;
 else
 {
if(!sinContestar(resp,op)){ system("cls");
                            printCent("no hay mas preguntas sin responder en esta categoria");
                             system ("pause");
                             op=-1;}
 }}
 }while(op==-1);
}

int pregunta;      
do
{
pregunta = rand() % 4;
}while(resp[op][pregunta]=='*');
 system("cls");
 char respuesta;
 cout<<preg[op][pregunta]<<endl;
 cin>>respuesta;
 if(respuesta==resp[op][pregunta])
 {
   system("cls");
   cout<<"Felicidades a respondido correctamente!"<<endl;
   resp[op][pregunta]='*';
   cout<<"Desea jugar con otra categoria?\n1. si  2. no"<<endl;
   cin>>respuesta;
   if(!sinContestar(resp,op))
                            {
                            system("cls");
                            printCent("no hay mas preguntas sin responder en esta categoria");
                             system ("pause");
                             op=-1;
                             }
   if(respuesta=='1')op=-1;
   puntj+=5;
 }
 else{
      
   system("cls");
   printCent("Incorrecto!");
   system ("pause");
   op=-2;
   }
}
while(op!=-2);
return puntj;
}

void gameOver(int puntaje)
{ 
  system("cls");
  cout<<"El juego a terminado"<<endl;
  cout<<"su puntaje fue de "<<puntaje<<endl;
  if(puntaje>record) 
  {
  cout<<"Felicidades ha batido el record"<<endl<<"ingrese su nombre"<<endl;
  string nombre;
  cin>>nombre;
  recordNomb=nombre;
  record=puntaje;
}
else cout<<"No ha batido el record";

  system("pause"); 
}

bool sinContestar(char resp[4][4], int op)
{
      bool sinCont = false;
    for (int i=0; i<4; i++)
    {
        if(resp[op][i]!='*') sinCont=true;
    }
      return sinCont;
}
void verRecord()
{
  system("cls");
  cout<<recordNomb<<": "<<record<<endl;    
  system("pause");    
}

void verReglas()
{
}

void printCent(string cad)
{
    int i, k;
    int n = cad.size();
    k = (80-n)/2;
    for(i = 0; i<k; i++)
    {
        cout<<" ";
    }
    cout<<cad<<endl;
}
