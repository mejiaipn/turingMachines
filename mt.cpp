#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include "mt.h"

int main(void)
{
	
	int opc1,aux1=0,fgp,cadlen,auxsigma=1,ncic,o,oo,i,t,ii,a,xa=0,xx=0,izq=0,der=0,u,auxiliarsuma=0;
	char cs1,cs2,cs3,dir,araux;
	char auxs1[s1sigma+4],stzero[5][2],st1[5][3],st2[5][3],st3[5][2],st4[4],s2tzero[5][2],s2t1[5][2],s2t2[5][3],s2t3[5][3],s2t4[5][3],s2t5[5][3],s2t6[5][1],head[2];
	char s3tzero[5][2],s3t1[5][2];
	char cad[maxcad],backupcad[maxcad];
	for(int l=0;l<maxcad;l++) // inicializando arreglo que recibe la cadena a ser evaluada
	{
	  cad[l]='\0';
	}
	FILE *stream1; 
	FILE *stream2;
	FILE *stream3;
	stream1=fopen("stream1.amt","r"); // maquina de turing 1
	stream2=fopen("stream2.amt","r"); // maquina de turing 2
	stream3=fopen("stream3.amt","r"); // maquina de turing 3
	system("clear");
	n_saltos_de_linea(2);
	titulo();
	n_saltos_de_linea(2);
	menu_maq_t();	
	scanf("%d",&opc1);
	n_saltos_de_linea(1);
	switch(opc1)
	{
		case 1:
			
			cs1=fgetc(stream1);
			for(i=0;i<=s1sigma+4;i++) //Inicializando arreglo auxiliar 
			{
				auxs1[i]='\0';
				}
			while(cs1!='?')
			{
				printf("Leyendo archivo linea 1\r");
				
				if(cs1!=',')
				{
					auxs1[aux1]=cs1;
					aux1++;
					
					}
				cs1=fgetc(stream1);
				
				}
			puts(w);
			puts(mt1);
			puts(fstream1);
			printf("\nΣ={");
			for(a=0;a<=s1sigma-1;a++)
			{
				printf("%c",auxs1[a]);
				if(a<s1sigma-1)
				printf(",");
				if(a==s1sigma-1)
				printf("}");
				}
			printf("\n>>Ingrese una cadena para ser evaluada en la máquina de Turing\t>>>");
			setbuf(stdin,NULL);
			gets(cad);
			strcpy(backupcad,cad);
			cadlen=strlen(cad);
			printf("Longitud: [%d]\nRespaldando original...Modificando la cadena...Agregando espacio en blanco...\n",cadlen);
			cad[cadlen]='B'; // agregando espacio en blanco
			printf("Trabajando con la cadena:");
			puts(cad);
			aux1=0;
			for(u=0;u<=3;u++)
			{
			  switch(u)
			  {
			    case 0:
			      ncic=2;
			      break;
			     case 1:
			      ncic=3;
			      break;
			     case 2:
			      ncic=3;
			      break;
			     case 3:
			      ncic=2;
			      break;
			  }
			  for(o=1;o<=ncic;o++)
			  {
			     printf(">>>Leyendo archivo...\r");
			    cs1=fgetc(stream1);
			    aux1=0;
			    while(cs1!='?')
			    {
				  if(cs1!=',')
				  {
					  switch(u)
					  {
					    case 0:
					      stzero[aux1][o-1]=cs1;
					      break;
					    case 1:
					      st1[aux1][o-1]=cs1;
					      break;
					    case 2:
					      st2[aux1][o-1]=cs1;
					      break;
					    case 3:
					      st3[aux1][o-1]=cs1;
					      break;
					    default:
					      exit(0);
					  }
					  aux1++;
					  cs1=fgetc(stream1);
				  }
				  else{
				    cs1=fgetc(stream1);
				  }
			    }
			  }
			}
			printf("\n[Función δ]\n");
			  for(oo=0;oo<=3;oo++)
			  {
			    switch(oo)
			    {
			    case 0:
			      ncic=2;
			      break;
			     case 1:
			      ncic=3;
			      break;
			     case 2:
			      ncic=3;
			      break;
			     case 3:
			      ncic=2;
			      break;
			    }
			    for(t=0;t<ncic;t++)
			    {
			      usleep(500000); //esperando ½segundo
			      for(ii=0;ii<5;ii++)
			      {
				if(!ii)
				{printf(" Estado:");}
				if(ii==1)
				{printf(" Recibe:");}
				if(ii==2)
				{printf(" Manda a:");}
				if(ii==3)
				{printf("Sobreescribe:");}
				if(ii==4)
				{printf("Se mueve:");}
			    switch(oo)
			    {
			    case 0:
			      printf("[%c]\t",stzero[ii][t]);
			      break;
			     case 1:
			      printf("[%c]\t",st1[ii][t]);
			      break;
			     case 2:
			      printf("[%c]\t",st2[ii][t]);
			      break;
			     case 3:
			      printf("[%c]\t",st3[ii][t]);
			      break;
			    }
			      }
			      n_saltos_de_linea(2);
			    }
			  }
			  printf("\nArchivo \".../stream1.amt\" leido exitosamente, simulando comportamiento de una máquina de turing...Presione cualquier tecla para continuar...");
			n_saltos_de_linea(5);
			head[0]='0';// inicializando cabezal en estado 0
			getchar();
			do
			{
			  switch(cad[xa])
			  {
			    case '0': // Recibe 0
				
			       head[1]='0';// contenidod el caezal es 0
			       
				switch(head[0]) // estado 
				{
				  
				  case '0':
				    head[0]=stzero[2][0]; // estado 1
				    cad[xa]=stzero[3][0]; // sobreescribe x
				    dir=stzero[4][0]; // se mueve a la derecha 
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '1':
				    head[0]=st1[2][0]; // manda a estado 1
				    cad[xa]=st1[3][0]; // sobreescribe 0
				    dir=st1[4][0];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '2':
				  head[0]=st2[2][0]; //manda a estdo 2 
				  cad[xa]=st2[3][0]; //sobreescribe un 0
				  dir=st2[4][0];
				   xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la izquierda
				   izq--;
				  printf("%c",head[0]);
				  n_saltos_de_linea(1);
				  puts(cad);usleep(500000); //esperando ½segundo
				    break;
				  case '3':
				    error_cadena_invalida(); printf("\nLa cádena %s no pudo ser procesada correctamente por la Máquina de Turing\n",backupcad);
				    break;
				}
				break;
			    case '1': // Recibe 1
			   if(head[0]=='1')
			   {
			      head[1]='1';// contenidod el caezal es 1
			    head[0]=st1[2][1]; //manda al estado 2
			    cad[xa]=st1[3][1]; //sobreescribe Y
			    dir=st1[4][1]; // se mueve
			     xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la izquierda
			     izq--;
			    printf("%c",head[0]);
			    n_saltos_de_linea(1);
			    puts(cad);usleep(500000); //esperando ½segundo
			  }
			  else
			  {
			    error_cadena_invalida(); printf("\nLa cádena %s no pudo ser procesada correctamente por la Máquina de Turing\n",backupcad);
			  }
			      break;
			      case 'X': // Recibe X
			    if(head[0]=='2')
			    {
			      head[1]='X';// contenidod el caezal es x
			    head[0]=st2[2][2]; //manda al estado 0
			    cad[xa]=st2[3][2]; //sobreescribe X
			    dir=st2[4][2]; // se mueve a la derecha
			    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}
			    der++;
			    printf("%c",head[0]);
			    n_saltos_de_linea(1);
			    puts(cad);usleep(500000); //esperando ½segundo
			    }
			    else
			    {
			      error_cadena_invalida(); printf("\nLa cádena %s no pudo ser procesada correctamente por la Máquina de Turing\n",backupcad);
			    }
			      break;
			        case 'Y': // Recibe Y
			    switch(head[0]) // estado 
				{
				  case '0':
				  head[0]=stzero[2][1]; //manda a estado 3 
				  cad[xa]=stzero[3][1]; // sobreescribe una Y
				  dir=stzero[4][1];
				  xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} // se mueve a la derecha 
				  der++;
				 printf("%c",head[0]);
				  n_saltos_de_linea(1);
				  puts(cad);usleep(500000); //esperando ½segundo
				  break;
				  case '1':
				  head[0]=st1[2][2]; // manda a estado 1
				  cad[xa]=st1[3][2]; // sobreescribe una Y 
				  dir=st1[4][2];
				   xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}// se mueve a la derecha 
				   der++;
				 printf("%c",head[0]);
				  n_saltos_de_linea(1);
				  puts(cad);usleep(500000); //esperando ½segundo
				  break;
				  case '2':
				  head[0]=st2[2][1];
				  cad[xa]=st2[3][1];
				  dir=st2[4][1];
				  xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}
				  izq--;
				  printf("%c",head[0]);
				  n_saltos_de_linea(1);
				  puts(cad);usleep(500000); //esperando ½segundo
				    break;
				    case '3':
				  head[0]=st3[2][0];
				  cad[xa]=st3[3][0];
				 xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}
				 der++;
				  printf("%c",head[0]);
				  n_saltos_de_linea(1);
				  puts(cad);usleep(500000); //esperando ½segundo
				    break;
				}
			      break;
				  case 'B':
				    if(head[0]!='3')
				    {
				      error_cadena_invalida(); printf("\nLa cádena %s no pudo ser procesada correctamente por la Máquina de Turing\n",backupcad);				      
				    }
				    head[0]=st3[2][1];
				    cad[xa]=st3[3][1];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
			  }
			}while(cad[xa]!='\0');
			puts(exito);
			printf("\n\nCádena %s procesada correctamente por la Máquina de Turing ",backupcad);
			printf("\nMovimientos a la izquierda: %d\nMovimientos a la derecha: %d\n",abs(izq),der);
		break;
		case 2:
		  
			cs1=fgetc(stream2);
			for(i=0;i<=s1sigma+4;i++) //Inicializando arreglo auxiliar 
			{
				auxs1[i]='\0';
				}
			while(cs1!='?')
			{
				printf("Leyendo archivo linea 1\r");
				
				if(cs1!=',')
				{
					auxs1[aux1]=cs1;
					aux1++;
					
					}
				cs1=fgetc(stream2);
				
				}
			puts(w);
			puts(mt2);
			puts(fstream2);
			printf("\nΣ={");
			for(a=0;a<=s2sigma-1;a++)
			{
				printf("%c",auxs1[a]);
				if(a<s2sigma-1)
				printf(",");
				if(a==s2sigma-1)
				printf("}");
				}
			printf("\n>>Ingrese una cadena para ser evaluada en la máquina de Turing\t>>>");
			setbuf(stdin,NULL);
			gets(cad);
			strcpy(backupcad,cad);
			cadlen=strlen(cad);
  			printf("Longitud: [%d]\nRespaldando original...Modificando la cadena...Agregando espacio en blanco...\n",cadlen);
  			cad[cadlen]='B'; // agregando espacio en blanco
			printf("Trabajando con la cadena:");
			puts(cad);
			printf("Continuando lectura de:");
			puts(fstream2);
			aux1=0;
			for(u=0;u<=5;u++)
			{
			  switch(u)
			  {
			    case 0:
			      ncic=2;
			      break;
			     case 1:
			      ncic=2;
			      break;
			     case 2:
			      ncic=3;
			      break;
			     case 3:
			      ncic=3;
			      break;
			      case 4:
			      ncic=3;
			      break;
			      case 5:
			      ncic=3;
			      break;
			  }
			  for(o=1;o<=ncic;o++)
			  {
			    puts(fstream2);
			    cs1=fgetc(stream2);
			    aux1=0;
			    while(cs1!='?')
			    {
				  if(cs1!=',')
				  {
					  switch(u)
					  {
					    case 0:
					      s2tzero[aux1][o-1]=cs1;
					      break;
					    case 1:
					      s2t1[aux1][o-1]=cs1;
					      break;
					    case 2:
					      s2t2[aux1][o-1]=cs1;
					      break;
					    case 3:
					      s2t3[aux1][o-1]=cs1;
					      printf("-%c @ (%d,%d)",s2t3[aux1][o-1],aux1,o-1);
					      break;
					    case 4:
					    s2t4[aux1][o-1]=cs1;
					      break;
					    case 5:
					    s2t5[aux1][o-1]=cs1;
					      break;
					    default:
					      exit(0);
					  }
					  aux1++;
					  cs1=fgetc(stream2);
				  }
				  else{
				    cs1=fgetc(stream2);
				  }
			    }
			  }
			}
			printf("\n[Función δ]\n");
			
			  for(oo=0;oo<=5;oo++)
			  {
			    switch(oo)
			    {
			    case 0:
			      ncic=2;
			      break;
			     case 1:
			      ncic=2;
			      break;
			     case 2:
			      ncic=3;
			      break;
			     case 3:
			      ncic=3;
			      break;
			      case 4:
			      ncic=3;
			      break;
			      case 5:
			      ncic=3;
			      break;
			    }
			    for(t=0;t<ncic;t++)
			    {
			      usleep(500000); //esperando ½segundo
			      for(ii=0;ii<5;ii++)
			      {
					if(!ii)
					{printf(" Estado:");}
					if(ii==1)
					{printf(" Recibe:");}
					if(ii==2)
					{printf(" Manda a:");}
					if(ii==3)
					{printf("Sobreescribe:");}
					if(ii==4)
					{printf("Se mueve:");}
					switch(oo)
					{
					case 0:
					  printf("[%c]\t",s2tzero[ii][t]);
					  break;
					 case 1:
					  printf("[%c]\t",s2t1[ii][t]);
					  break;
					 case 2:
					  printf("[%c]\t",s2t2[ii][t]);
					  break;
					 case 3:
					  printf("[%c]\t",s2t3[ii][t]);
					  break;
					 case 4:
					  printf("[%c]\t",s2t4[ii][t]);
					  break;
					  case 5:
					  printf("[%c]\t",s2t5[ii][t]);
					  break;
					}
				
			      }
			      n_saltos_de_linea(2);
			    }
			  }
			  printf("\nArchivo \".../stream2.amt\" leido exitosamente, simulando comportamiento de una máquina de turing...");
			n_saltos_de_linea(5);
			head[0]='0';// inicializando cabezal en estado 0
			araux=head[0]; 
			sleep(2);
			do
			{
			  if(head[0]=='6')
			    break;
			  switch(cad[xa])
			  {
			    case '0': // Recibe 0
				
			       head[1]='0';// contenidod el caezal es 0
			       
				switch(head[0]) // estado 
				{
				  
				  case '0':
				    head[0]=s2tzero[2][0]; // estado 1
				    cad[xa]=s2tzero[3][0]; // sobreescribe x
				    dir=s2tzero[4][0]; // se mueve a la derecha 
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '1':
				    head[0]=s2t1[2][0]; // manda a estado 1
				    cad[xa]=s2t1[3][0]; // sobreescribe 0
				    dir=s2t1[4][0];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '2':
				 head[0]=s2t2[2][1]; // manda a estado 3
				    cad[xa]=s2t2[3][1]; // sobreescribe 1
				    dir=s2t2[4][1];
				    xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    izq--;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				    break;
				    case '3':
				 head[0]=s2t3[2][1]; // manda a estado 3
				    cad[xa]=s2t3[3][1]; // sobreescribe 1
				    dir=s2t3[4][1];
				    xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    izq--;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				    break;
				  case '4':
				    head[0]=s2t4[2][0]; // manda a estado 4
				    cad[xa]=s2t4[3][0]; // sobreescribe 0
				    dir=s2t4[4][0];
				    xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    izq--;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000);
				    break;
				    case '5':
				    head[0]=s2t5[2][1]; // manda a estado 4
				    cad[xa]=s2t5[3][1]; // sobreescribe 0
				    dir=s2t5[4][1];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000);
				    break;
				}
				break;
			    case '1': // Recibe 1
			  switch(head[0]) // estado 
				{
				  
				  case '0':
				    head[0]=s2tzero[2][1]; // estado 1
				    cad[xa]=s2tzero[3][1]; // sobreescribe x
				    dir=s2tzero[4][1]; // se mueve a la derecha 
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '1':
				    head[0]=s2t1[2][1]; // manda a estado 1
				    cad[xa]=s2t1[3][1]; // sobreescribe 0
				    dir=s2t1[4][1];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '2':
				 head[0]=s2t2[2][0]; // manda a estado 1
				    cad[xa]=s2t2[3][0]; // sobreescribe 0
				    dir=s2t2[4][0];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				    break;
				    case '3':
				 head[0]=s2t3[2][2]; // manda a estado 1
				    cad[xa]=s2t3[3][2]; // sobreescribe 0
				    dir=s2t3[4][2];
				    xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    izq--;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				    break;
				  case '4':
				  head[0]=s2t4[2][1]; // manda a estado 1
				    cad[xa]=s2t4[3][1]; // sobreescribe 0
				    dir=s2t4[4][1];
				    xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    izq--;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				  break; 
				  case '5':
				    head[0]=s2t5[2][2]; // manda a estado 4
				    cad[xa]=s2t5[3][2]; // sobreescribe 0
				    dir=s2t5[4][2];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000);
				    
				  break;
				}
			      break;
			    case 'B': // Recibe B
			    switch(head[0]) // estado 
				{
				  case '2':
				 head[0]=s2t2[2][2]; // manda a estado 3
				    cad[xa]=s2t2[3][2]; // sobreescribe 1
				    dir=s2t2[4][2];
				    xa--; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    izq--;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				    break;
				    case '3':
				 head[0]=s2t3[2][0]; // manda a estado 3
				    cad[xa]=s2t3[3][0]; // sobreescribe 1
				    dir=s2t3[4][0];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				    break;
				  case '4':
				    head[0]=s2t4[2][2]; // manda a estado 4
				    cad[xa]=s2t4[3][2]; // sobreescribe 0
				    dir=s2t4[4][2];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000);
				    break;
				    case '5':
				    head[0]=s2t5[2][0]; // manda a estado 4
				    cad[xa]=s2t5[3][0]; // sobreescribe 0
				    dir=s2t5[4][0];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000);
				    break;
				}
			      break;
			  }
			  
			}while(cad[xa]!='\0');
			printf("\n\nCádena %s procesada correctamente por la Máquina de Turing ",backupcad);
			
			for(int sum=0;sum<=cadlen;sum++)
			{
			  if(cad[sum]=='0')
			    auxiliarsuma++;
			}
			printf("\n>>Resultado de la Sustracción Propia: [%d]",auxiliarsuma);
		break;
		case 3:
			cs1=fgetc(stream3);
			for(i=0;i<=s1sigma+4;i++) //Inicializando arreglo auxiliar 
			{
				auxs1[i]='\0';
				}
			while(cs1!='?')
			{
				printf("Leyendo archivo linea 1\r");
				
				if(cs1!=',')
				{
					auxs1[aux1]=cs1;
					aux1++;
					
					}
				cs1=fgetc(stream3);
				
				}
			puts(w);
			puts(mt3);
			puts(fstream3);
			printf("\nΣ={");
			for(a=0;a<=s3sigma-1;a++)
			{
				printf("%c",auxs1[a]);
				if(a<s3sigma-1)
				printf(",");
				if(a==s3sigma-1)
				printf("}");
				}
			printf("\n>>Ingrese una cadena para ser evaluada en la máquina de Turing\t>>>");
			setbuf(stdin,NULL);
			gets(cad);
			strcpy(backupcad,cad);
			cadlen=strlen(cad);
  			printf("Longitud: [%d]\nRespaldando original...Modificando la cadena...Agregando espacio en blanco...\n",cadlen);
  			cad[cadlen]='B'; // agregando espacio en blanco
			printf("Trabajando con la cadena:");
			puts(cad);
			printf("Continuando lectura de:");
			puts(fstream3);
			aux1=0;
			for(u=0;u<=1;u++)
			{
			  ncic=2;
			    
			  
			  for(o=1;o<=ncic;o++)
			  {
			    puts(fstream3);
			    cs1=fgetc(stream3);
			    aux1=0;
			    while(cs1!='?')
			    {
				  if(cs1!=',')
				  {
					  switch(u)
					  {
					    case 0:
					      s3tzero[aux1][o-1]=cs1;
					      break;
					    case 1:
					      s3t1[aux1][o-1]=cs1;
					      break;
					  }
					  aux1++;
					  cs1=fgetc(stream3);
				  }
				  else{
				    cs1=fgetc(stream3);
				  }
			    }
			  }
			}
			printf("\n[Función δ]\n");
			
			  for(oo=0;oo<=1;oo++)
			  {
			    for(t=0;t<ncic;t++)
			    {
			      usleep(500000); //esperando ½segundo
			      for(ii=0;ii<5;ii++)
			      {
					if(!ii)
					{printf(" Estado:");}
					if(ii==1)
					{printf(" Recibe:");}
					if(ii==2)
					{printf(" Manda a:");}
					if(ii==3)
					{printf("Sobreescribe:");}
					if(ii==4)
					{printf("Se mueve:");}
					switch(oo)
					{
					case 0:
					  printf("[%c]\t",s3tzero[ii][t]);
					  break;
					 case 1:
					  printf("[%c]\t",s3t1[ii][t]);
					  break;
					 }
				
			      }
			      n_saltos_de_linea(2);
			    }
			  }
			  printf("\nArchivo \".../stream3.amt\" leido exitosamente, simulando comportamiento de una máquina de turing...");
			n_saltos_de_linea(5);
			head[0]='0';// inicializando cabezal en estado 0
			araux=head[0]; 
			sleep(2);
			do
			{
			 
			
			  switch(cad[xa])
			  {
			    case '0': // Recibe 0
				
			       head[1]='0';// contenidod el caezal es 0
			       
				switch(head[0]) // estado 
				{
				  
				  case '0':
				    head[0]=s3tzero[2][0]; // estado 1
				    cad[xa]=s3tzero[3][0]; // sobreescribe x
				    dir=s3tzero[4][0]; // se mueve a la derecha 
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '1':
				    head[0]=s3t1[2][1]; // manda a estado 1
				    cad[xa]=s3t1[3][1]; // sobreescribe 0
				    dir=s2t1[4][1];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				}
				break;
			    case 'B': // Recibe B
			    switch(head[0]) // estado 
				{
				  case '0':
				    head[0]=s3tzero[2][1]; // estado 1
				    cad[xa]=s3tzero[3][1]; // sobreescribe x
				    dir=s3tzero[4][1]; // se mueve a la derecha 
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");}//se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				  case '1':
				    head[0]=s3t1[2][0]; // manda a estado 1
				    cad[xa]=s3t1[3][0]; // sobreescribe 0
				    dir=s3t1[4][0];
				    xa++; system("clear");   for(int h=1;h<=xa;h++){printf(" ");} //se mueve a la derecha
				    der++;
				    printf("%c",head[0]);
				    n_saltos_de_linea(1);
				    puts(cad);usleep(500000); //esperando ½segundo
				      break;
				}
			      break;
			  }
			  
			}while(cad[xa]!='\0');
			if(head[0]=='N')
			{
			  error_cadena_invalida();
			  printf("\n>>Resultado: Cantidad de ceros impar");
			}
			printf("\n\nCádena %s procesada correctamente por la Máquina de Turing ",backupcad);
			
			for(int sum=0;sum<=cadlen;sum++)
			{
			  if(cad[sum]=='0')
			    auxiliarsuma++;
			}
			printf("\n>>Resultado: Cantidad de ceros par");
		break;
		default:
		  puts(errcmtnde);
		  getchar();
		break;
		
		}
	n_saltos_de_linea(2);
	margin_hor();	
	n_saltos_de_linea(5);
	getchar();
	system("clear");
	return 0;
	}
