

/*
   Miniprocesador de texto con funcions
   * 484 lineas de codigo, 14 paxinas
   
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DIA     2
#define MES     5
#define ANO  2008

#define MAX 200
#define MAX_DOCS 19

// funcions auxiliares do programa




//estructuras de variables

typedef struct f2
  {
  char _dia[20],
       hora[20];
  } fecha2;
typedef struct f
  {
  int dia,
      mes,
      ano;
  } fecha; 
typedef struct a
  {
  char nombre[30],
       apellidos[70],
       telefono[15],
       direccion[70],
       ciudad[40];
  } autor;

typedef struct d
  {
  autor _autor;
  char titulo[60],
       *texto;
  int tam,
      pals;
  fecha  fecha_c;
  fecha2 fecha_m;
  char comentario[100];
  } datos;

char menu(void);
int intro_doc(datos _datos[MAX_DOCS]);
int visualizar_doc(datos _datos[MAX_DOCS]);
int corregir_doc(datos _datos[MAX_DOCS]);
int datos_doc(datos _datos[MAX_DOCS]);
int errores_conecidos();





// funcion main()

int main(void)
{
datos _datos[MAX_DOCS];

//_datos=(char*)(malloc(sizeof(char)*(450+MAX)));

int g=1;

menu();

//free(_datos);

system("pause");
return 0;
}

//*****************funcions auxiliares********************
char menu(void)
{
datos _datos[MAX_DOCS];
int g;
char opcion;

do{

printf("\n1. Intro documento");   
printf("\n2. Visualizar documento");
printf("\n3. Correxir documento");
printf("\n4. Datos do documento");
printf("\n5. Errores conecidos");
printf("\nESC para sair");



printf("\n\n");
opcion=getch(stdin);

switch(opcion)
{

case '1':
  intro_doc(_datos);
  break;

case '2':
  visualizar_doc(_datos);
  break;

case '3':
  corregir_doc(_datos);

case '4':
  datos_doc(_datos);
  break;

case '5':
  errores_conecidos();
  break;

if(opcion==27) break;

}           //pecho o switch
}           //pecho o do-while  
while(opcion!=27);

return 0;
}           //pecho a funcion menu()




int intro_doc(datos _datos[MAX_DOCS])
{

int g;

printf("\n\nIntroducir documento:");
printf("\n==========================\n\n");
gets(_datos[g].texto);
printf("\nIntro titulo:\n");
gets(_datos[g].titulo);
printf("\nFecha creacion:\n");
do{
printf("Dia(numero):");
scanf("%d", &_datos[g].fecha_c.dia);
}
while(_datos[g].fecha_c.dia >31 || _datos[g].fecha_c.dia<1);
do{
printf("\nMes(numero):");
scanf("%d", &_datos[g].fecha_c.mes);
}
while(_datos[g].fecha_c.mes >12 || _datos[g].fecha_c.mes<1);
do{
printf("\nAno(numero):");
scanf("%d", &_datos[g].fecha_c.ano);
}
while(_datos[g].fecha_c.ano >5000 || _datos[g].fecha_c.ano<-2500);

printf("\n\nIntroduccion de datos:");
printf("\n=======================\n\n");

                //datos del documento
printf("\nIntro nombre:");
gets(_datos[g]._autor.nombre);
printf("\nIntro apellidos:");
gets(_datos[g]._autor.apellidos);
printf("\nIntro telefono:");
gets(_datos[g]._autor.telefono);
printf("\nIntro direccion:");
gets(_datos[g]._autor.direccion);
printf("\nIntro ciudad:");
gets(_datos[g]._autor.ciudad);
printf("\nComentario/otros:");
gets(_datos[g].comentario);

strcpy(_datos[g].fecha_m._dia, __DATE__);
strcpy(_datos[g].fecha_m.hora, __TIME__);

g++;

return g;
}



int visualizar_doc(datos _datos[MAX_DOCS])
{

int g, sw2=1;
char _titulo[60];
printf("\nIntro titulo(requerido):");
gets(_titulo);
for(g=1;g<(MAX_DOCS+1);g++)
  {
  if(_titulo=='\0') sw2=1;
  if(strcmp(_titulo, _datos[g].titulo)==0)
    {
    printf("\n\n       Documento:\n\n\n");
    printf("%s", _datos[g].texto);
    printf("\n\n\n");
    sw2=0;
    }
  }
if(sw2==1) printf("\nERROR: Documento non atopado\n");


return 0;
}




int corregir_doc(datos _datos[MAX_DOCS])

{
int f, g, h=1, i, j , k , l , m , n;
int tamo, cars;
char *texto_x;

texto_x=(char*)(malloc(sizeof(char)*MAX));

char _titulo[60];

printf("\nIntro titulo(requerido):");
gets(_titulo);
for(g=1;g<(MAX_DOCS+1);g++)
  {
  if(_titulo=='\0') h=1;
  if(strcmp(_titulo, _datos[g].titulo)==0)
    {
        //...



/*NUMERO DE CARACTERES "DOC. SIN CORREGIR"*/

for(tamo=0;tamo<MAX;tamo++)
  if(_datos[g].texto[tamo]=='\0') break;
//tamo guarda el numero de caracteres de texto y,
// ocupa bytes de 8 bits(char)*(número de caracteres)


/*QUITAR ESPACIOS DOBLES*/



printf("\n\n       Documento:\n");
 


for(tamo=0;tamo<200;tamo++)
  if(_datos[g].texto[tamo]=='\0') break;




l=0;
for(i=0;i<tamo;i++)       
  {
  k=i+1; 
  if((_datos[g].texto[i]==32 && _datos[g].texto[k]==32)==1)
    l++;
  else
    {
    j=i-l;
    _datos[g].texto[j]=_datos[g].texto[i];
    }
  }



for(f=0;f<(tamo-l);f++)
  texto_x[f]=_datos[g].texto[f];

for(f=0;f<tamo;f++)
  _datos[g].texto[f]='\0';


for(f=0;f<(tamo-l);f++)
  _datos[g].texto[f]=texto_x[f];

m=l;

//texto guarda esta correccion





/*PRIMERA LETRA DE LA PRIMERA PALABRA EN MAYUSCULA*/


if(_datos[g].texto[0]>=97 && _datos[g].texto[0]<=122)
  _datos[g].texto[0]=_datos[g].texto[0]-32;
else _datos[g].texto[1]=_datos[g].texto[1]-32;   




/*ELIMINAR ESPACIO ANTES DE SIGNO DE PUNTUACION*/

l=0;
for(i=0;i<tamo;i++)       
  {
  k=i+1; 
  if((_datos[g].texto[i]==32 && (_datos[g].texto[k]==58 || _datos[g].texto[k]==59 || _datos[g].texto[k]==33 ||
     _datos[g].texto[k]==41 || _datos[g].texto[k]==44 || _datos[g].texto[k]==46))==1)
    l++;
  else
    {
    j=i-l;
    _datos[g].texto[j]=_datos[g].texto[i];
    }
  }

for(f=0;f<(tamo-l);f++)
  texto_x[f]=_datos[g].texto[f];

for(f=0;f<tamo;f++)
  _datos[g].texto[f]='\0';

for(f=0;f<(tamo-l);f++)
  _datos[g].texto[f]=texto_x[f];


m=m+l;






//texto guarda la correccion    


/*PUNTO, "¡", "¿" Y DESPUES MAYUSCULA*/

for(i=0;i<(tamo-m);i++)
  {
  k=i+1;
  if(((_datos[g].texto[i]==46) && (_datos[g].texto[k]>=97 && _datos[g].texto[k]<=122))==1)
      _datos[g].texto[k]=_datos[g].texto[k]-32;
  }
//error: charmap 1-127


/*ESPACIO DESPUES DE PUNTO, DOS PUNTOS, COMA, PUNTO Y COMA*/


l=0;
for(i=0;i<(tamo-m);i++)       
  {
  n=i+1;
  j=i+l;
  texto_x[j]=_datos[g].texto[i];
  if(((_datos[g].texto[i]==31 || _datos[g].texto[i]==33 || _datos[g].texto[i]==44 || _datos[g].texto[i]==46 ||
     _datos[g].texto[i]==58 || _datos[g].texto[i]==59) && _datos[g].texto[n]!=32)==1)
    {
    k=j+1;
    texto_x[k]=32;
    l++;
    }
  }
for(i=0;i<(tamo-m+l);i++)
  _datos[g].texto[i]=texto_x[i];


m=m-l;




/*PUNTO FINAL*/

_datos[g].texto[tamo-m]=46;


/*NUMERO DE PALABRAS*/

for(i=0;i<(tamo-m);i++)
  if(_datos[g].texto[i]=='\0') break;
cars=i;

//recalculado el tamaño en caracteres y bytes de doc.

_datos[g].pals=1;
for(cars=0;cars<(tamo-m);cars++)
  if (_datos[g].texto[cars]==32) _datos[g].pals++;

//pals guarda el numero de palabras





_datos[g].tam=cars; 

// _datos[g].tam guarda el tamaño en bytes


printf("\n\n      correxindo documento...\n\n\n");

printf("%s", _datos[g].texto);


     //...

    h=0;
    }
  }
if(h==1) printf("\nERROR: Documento non atopado\n");


free(texto_x);
return 0;
}





int datos_doc(datos _datos[MAX_DOCS])

{
int g, sw2=1;
char _titulo[60];
printf("\n\nIntro titulo(requerido):");
gets(_titulo);
for(g=1;g<(MAX_DOCS+1);g++)
  {
  if(_titulo=='\0') sw2=1;
  if(strcmp(_titulo, _datos[g].titulo)==0)
    {
//...o if
printf("\n\nDatos do documento:\n");

printf("Nome: %s", _datos[g]._autor.nombre);
printf("\nApelidos: %s", _datos[g]._autor.apellidos);
printf("\nTelefono: %s", _datos[g]._autor.telefono);
printf("\nDireccion: %s", _datos[g]._autor.direccion);
printf("\nCidade: %s", _datos[g]._autor.ciudad);
printf("\nTitulo: %s", _datos[g].titulo);
printf("\nData de creacion: %d/%d/%d", _datos[g].fecha_c.dia, _datos[g].fecha_c.mes, _datos[g].fecha_c.ano);
printf("\nData de modificacion: %s   ---- %s", _datos[g].fecha_m._dia, _datos[g].fecha_m.hora);
printf("\nTamano: %d bytes", _datos[g].tam);
printf("\nNumero de caracteres: %d", _datos[g].tam);
printf("\nNumero de palabras: %d", _datos[g].pals);
printf("\nComentario: %s", _datos[g].comentario);

    sw2=0;
    }    //pecho o if
  }      //pecho o for
if(sw2==1) printf("\nERROR:Documento non atopado\n");

return 0;
} 

int errores_conecidos()
{

printf("\n\nErrores conecidos\n\n");
printf("=================\n\n");


printf("\nCharmap 1-127. Falla o ASCII extendido 850latin1\n");
printf("\nDatas: meses de 28, 29--bixestos-- e 31 dias\n");
printf("\nComprobacions de entrada de datos\n");
printf("\nIdiomas: english, castellano, galego\n");
printf("=================\n\n");

return 0;
}
