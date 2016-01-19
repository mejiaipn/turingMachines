

// FUNCIONES 
void titulo(void);
void margin_hor(void );
void n_saltos_de_linea(int);
void menu_maq_t(void);
void error_cadena_invalida(void);
// FUNCIONES

// DEFINICIONES

#define mt1 "\t{0ⁿ1ⁿ|n>0}"
#define mt2 "\t[Sustraccion propia], i.e.:  m¯.n={ m-n si m>n ; 0 si m≤n }"
#define mt3 "\t {0ⁿ|n es par}"
#define w " \n>>Trabajando con Máquina de Turing: \n"
#define fstream1 "Leyendo desde : .../stream1.amt (Archivo de Máquina de Turing)"
#define fstream2 "Leyendo desde : .../stream2.amt (Archivo de Máquina de Turing)"
#define fstream3 "Leyendo desde : .../stream3.amt (Archivo de Máquina de Turing)"
#define s1sigma 2 //caracteres en alfabeto de maquina 1
#define s2sigma 3 //caracteres en alfabeto de maquina 2
#define s3sigma 1 //caracteres en alfabeto de maquina 3
#define maxcad 50
#define errcna "[×] Error Fatal: Cadena no aceptada... SALIENDO"
#define errcmtnde "[×] Error Fatal:No tengo esa máquina de turing... SALIENDO"
#define exito "[✔] Éxito, Cadena aceptada "
// DEFINICIONES


// PROTOTIPOS
void titulo(void) // Título, nombre de la practica, alumno. header
{
  margin_hor(); // Margen
  printf("\n");
  printf("*\t      . \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t║\n*\t.-.-.-|-\t » Teoría Computacional |3er Departamental | Máquina de Turing «\t\t\t\t\t\t║\n*\t' ' ' '-\t\tAlumno:\t\t\t\t\t\t\t\t@ ESCOM \t\t\t\t║\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t║\n\t\t\t\tMEJÍA PÉREZ JAVIER       \t\t\t\t\t\t\t\t\t\t║\n\t\t\t\t\t\t\tDr. Benjamin Luna Benoso\t\t\t\t\t\t\t║\n");	
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t║\n");
  margin_hor(); //margen
  printf("\n");
}

void margin_hor(void ) // Margen con caracter ' ▬ '
{
  for(int form=0;form<=137;form++)
  {
    printf("▬");
  }
}
void error_cadena_invalida(void )
{
  puts(errcna);
  exit(0);
}


void n_saltos_de_linea(int n)
{
  for(int m=0;m<n;m++)
  {
    printf("\n");
  }
}

void menu_maq_t(void)
{
	
	printf("1.-");
	puts(mt1);
	printf("\n2.-");
	puts(mt2);
	printf("\n3.-");
	puts(mt3);
	printf("\n\nElija Máquina de Turing :\t >>\t");	
	}



//PROTOTIPOS
