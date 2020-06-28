#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
int Tablero[3][3],Z=1,X,Y,M=1,Fila,Columna;//X,Y,Z y M Son Variables Universales.
void VaciarTablero();
void DibujarTablero();
void Jugador();
void PosicionDentroDelParametro();
void ReconocimientoDeLugar();
void MostrarSimbolo();
void GraficacionEnMatriz();
void ValidacionDeLugar();
void Bot();
void ValidacionMaquina();
void DetectarWin();
int main()
{
    VaciarTablero();
    gotoxy(1,1);DibujarTablero();
    while(Z!=0)
    {
        while(X!=0)
        {
        Jugador();
        gotoxy(1,7);printf("                    \n");
        gotoxy(1,6);
        }
        X=1;
        while(Y!=0)
        {
        Bot();
        gotoxy(1,7);printf("                    \n");
        gotoxy(1,6);
        }
        DetectarWin();
        Y=1;
    }
    return 0;
}
void VaciarTablero()
{
    for(X=0;X<3;X++)
    {
        for(Y=0;Y<3;Y++)
        {
            Tablero[X][Y]=0;
        }
    }
}
void DibujarTablero()
{
    gotoxy(2,1);printf("%c",179);
    gotoxy(4,1);printf("%c",179);
    gotoxy(1,2);printf("%c",196);
    gotoxy(2,2);printf("%c",197);
    gotoxy(3,2);printf("%c",196);
    gotoxy(4,2);printf("%c",197);
    gotoxy(5,2);printf("%c",196);
    gotoxy(2,3);printf("%c",179);
    gotoxy(4,3);printf("%c",179);
    gotoxy(1,4);printf("%c",196);
    gotoxy(2,4);printf("%c",197);
    gotoxy(3,4);printf("%c",196);
    gotoxy(4,4);printf("%c",197);
    gotoxy(5,4);printf("%c",196);
    gotoxy(2,5);printf("%c",179);
    gotoxy(4,5);printf("%c\n",179);
}
void Jugador()
{
    int Posicion;
    printf("Ingrese Un Numero Del 1-9\n");
    while(M!=0)
    {
    scanf("%d",&Posicion);
    PosicionDentroDelParametro(Posicion);
    ValidacionDeLugar(Fila,Columna);
    }
    Tablero[Fila][Columna]=88;
    MostrarSimbolo(Fila,Columna);
    M=1;
    X=0;
}
void PosicionDentroDelParametro(int Posicion)
{
    if(Posicion>=1 && Posicion<=9)
    {
        ReconocimientoDeLugar(Posicion);//Aca Lo Que Se Logra Es Saber Si Esta Dentro Del Parametro Y Saber La Fila Y Columna Del Mismo.
    }
    else
    {
        printf("El Valor Ingresado No Corresponde Al Parametro Indicado\n");
    }
}
void ReconocimientoDeLugar(int Posicion)//Esta Misma Es La Funcion Enviada Anterior Hecha "Mejor" Por El Hecho Que La Anterior No Funcionaba Del Todo Bien.
{
    if(Posicion<4)//Fila 1.
    {
        Fila=0;
        Columna=Posicion-1;
    }
    else if(Posicion>=4 && Posicion<7)//Fila 2.
    {
        Fila=1;
        Columna=Posicion-4;
    }
    else if(Posicion>=7)//Fila 3.
    {
        Fila=2;
        Columna=Posicion-7;
    }
}
void MostrarSimbolo(int Fila,int Columna)
{
    if(Fila==0)
    {
        GraficacionEnMatriz(Columna,Fila);
    }
    else if(Fila==1)
    {
        GraficacionEnMatriz(Columna,Fila);
    }
    else if(Fila==2)
    {
        GraficacionEnMatriz(Columna,Fila);
    }
}
void GraficacionEnMatriz(int Columna, int Fila)
{
    if(Columna==0)
    {
        if(Fila==0)
        {
            gotoxy(Columna+1,Fila+1);printf("%c",Tablero[Fila][Columna]);
        }
        else if(Fila==1)
        {
            gotoxy(Columna+1,Fila+2);printf("%c",Tablero[Fila][Columna]);
        }
        else if(Fila==2)
        {
            gotoxy(Columna+1,Fila+3);printf("%c",Tablero[Fila][Columna]);
        }
    }
    else if(Columna==1)
    {
        if(Fila==0)
        {
            gotoxy(Columna+2,Fila+1);printf("%c",Tablero[Fila][Columna]);
        }
        else if(Fila==1)
        {
            gotoxy(Columna+2,Fila+2);printf("%c",Tablero[Fila][Columna]);
        }
        else if(Fila==2)
        {
            gotoxy(Columna+2,Fila+3);printf("%c",Tablero[Fila][Columna]);
        }
    }
    else if(Columna==2)
    {
        if(Fila==0)
        {
            gotoxy(Columna+3,Fila+1);printf("%c",Tablero[Fila][Columna]);
        }
        else if(Fila==1)
        {
            gotoxy(Columna+3,Fila+2);printf("%c",Tablero[Fila][Columna]);
        }
        else if(Fila==2)
        {
            gotoxy(Columna+3,Fila+3);printf("%c",Tablero[Fila][Columna]);
        }
    }
}
void ValidacionDeLugar(int Fila,int Columna)
{
    if(Tablero[Fila][Columna]==79 || Tablero[Fila][Columna]==88)
    {
        printf("Lo Siento Pero El Lugar Elegido Ya Esta Ocupado\n");
    }
    else
    {
        M=0;
    }
}
void Bot()
{
    int Posicion;
    srand(time(NULL));
    while(M!=0)
    {
    Posicion=rand()%(9-1+1)+1;
    PosicionDentroDelParametro(Posicion);
    ValidacionMaquina(Fila,Columna);
    }
    Tablero[Fila][Columna]=79;
    MostrarSimbolo(Fila,Columna);
    Y=0;
    M=1;
}
void ValidacionMaquina(int Fila,int Columna)
{
    if(Tablero[Fila][Columna]==79 || Tablero[Fila][Columna]==88)
    {

    }
    else
    {
        M=0;
    }
}
void DetectarWin()
{
    for(X=0;X<3;X++)
        {
        if(Tablero[X][0]==88 && Tablero[X][1]==88 && Tablero[X][2]==88)
        {
            printf("Has Ganado");
        }
        else if(Tablero[0][X]==88 && Tablero[1][X]==88 && Tablero[2][X]==88)
        {
            printf("Has Ganado");
        }
        }
}
