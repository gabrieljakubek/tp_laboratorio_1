#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void funIniEstadoPelicula(EMovie* movie, int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        (movie+i)->estado = 0;
    }
}

int funObtenerEspacioLibre(EMovie* movie, int t)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if ((movie+i)->estado == 0)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    return index;
}

int funAgregarPelicula(EMovie* movie, int t)
{
    int auxInt, auxRetor, index;
    char auxChar [2000];
    int respuesta = 0;
    index=funObtenerEspacioLibre(movie,t);
    if(index != -1)
    {
        printf("Ingrese un ID ya cargado para salir!");
        printf("\nIngrese el ID de la nueva pelicula: ");
        fflush(stdin);
        gets(auxChar);
        auxRetor = funChequeoNumero(auxChar);
        while (auxRetor != 0)
        {
            printf("Reingrese el ID de la nueva pelicula: ");
            fflush(stdin);
            gets(auxChar);
            auxRetor = funChequeoNumero(auxChar);
        }
        auxInt = atoi(auxChar);
        auxRetor = funBuscarId(movie,t,auxInt);
        if (auxRetor==-1)
        {
            (movie+index)->idPelicula = auxInt;

            printf("Ingrese el titulo(%d caracteres Maximo) : ",TAMTIT);
            fflush(stdin);
            gets(auxChar);
            auxRetor = funContarCaracteres(auxChar, TAMTIT);
            while (auxRetor!=0)
            {
                printf("Reingrese el titulo (%d caracteres Maximo) : ",TAMTIT);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMTIT);
            }
            strcpy((movie+index)->titulo,auxChar);

            printf("Ingrese el genero(%d caracteres Maximo) : ",TAMGEN);
            fflush(stdin);
            gets(auxChar);
            auxRetor = funContarCaracteres(auxChar, TAMGEN);
            while (auxRetor!=0)
            {
                printf("Reingrese el genero (%d caracteres Maximo) : ",TAMGEN);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMGEN);
            }
            strcpy((movie+index)->genero,auxChar);

            printf("Ingrese la duracion: ");
            fflush(stdin);
            gets(auxChar);
            auxRetor = funChequeoNumero(auxChar);
            while (auxRetor != 0)
            {
                printf("Reingrese la duracion: ");
                fflush(stdin);
                gets(auxChar);
                auxRetor = funChequeoNumero(auxChar);
            }
            auxInt = atoi(auxChar);
            (movie+index)->duracion = auxInt;

            printf("Ingrese la descripcion(%d caracteres Maximo) : ",TAMDESC);
            fflush(stdin);
            gets(auxChar);
            auxRetor = funContarCaracteres(auxChar, TAMDESC);
            while (auxRetor!=0)
            {
                printf("Reingrese la descripcion (%d caracteres Maximo) : ",TAMDESC);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMDESC);
            }
            strcpy((movie+index)->descripcion,auxChar);

            printf("Ingrese el puntaje: ");
            fflush(stdin);
            gets(auxChar);
            auxRetor = funChequeoNumero(auxChar);;
            while (auxRetor != 0)
            {
                printf("Reingrese el puntaje: ");
                fflush(stdin);
                gets(auxChar);
                auxRetor = funChequeoNumero(auxChar);
            }
            auxInt = atoi(auxChar);
            (movie+index)->puntaje = auxInt;

            printf("Ingrese el link de imagen(%d caracteres Maximo) : ",TAMLINK);
            fflush(stdin);
            gets(auxChar);
            auxRetor = funContarCaracteres(auxChar, TAMLINK);
            while (auxRetor!=0)
            {
                printf("Reingrese el link de imagen (%d caracteres Maximo) : ",TAMLINK);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMLINK);
            }
            strcpy((movie+index)->linkImagen,auxChar);

            (movie+index)->estado = 1;

            respuesta = 1;
        }
        else
        {
            respuesta = -1;
        }
    }
    else
    {
        respuesta = 0;
    }
    return respuesta;
}

int funModificarPelicula(EMovie* movie, int t)
{
    int auxInt,index, opcion,auxRetor;
    int flag = 0;
    char auxChar [2000];
    char auxResp, respuesta = 's';
    funMostrarTodasPeliculas(movie,t);
    printf("Ingrese un ID no cargado para salir!\n");
    printf("Ingrese el ID de la pelicula a modificar: ");
    scanf("%d",&auxInt);
    index=funBuscarId(movie,t,auxInt);
    if (index != -1)
    {
        system("cls");
        do
        {
            printf("ID\t%30s\t%30s\t%s\t%s\n","Titulo","Genero","Duracion","Puntaje");
            funMostrarPelicula(movie+index);
            opcion=funMostrarMenu("1-Modificar Titulo\
                             \n2-Modificar Genero\
                             \n3-Modificar Duracion\
                             \n4-Modificar Descripcion\
                             \n5-Modificar Puntaje\
                             \n6-Modificar Link de Imagen\
                             \n7-Finalizar");
            switch (opcion)
            {
            case 1:
                printf("Ingrese el nuevo titulo(%d caracteres Maximo) : ",TAMTIT);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMTIT);
                while (auxRetor!=0)
                {
                    printf("Reingrese el nuevo titulo (%d caracteres Maximo) : ",TAMTIT);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, TAMTIT);
                }
                printf("Esta seguro de cambiar el titulo? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy((movie+index)->titulo, auxChar);
                    printf("\nSe modifico el titulo\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico el titulo\n");
                }
                funBorrarPantalla();
                break;

            case 2:
                printf("Ingrese el nuevo genero(%d caracteres Maximo) : ",TAMGEN);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMGEN);
                while (auxRetor!=0)
                {
                    printf("Reingrese el nuevo genero (%d caracteres Maximo) : ",TAMGEN);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, TAMGEN);
                }
                printf("Esta seguro de cambiar el genero? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy((movie+index)->genero, auxChar);
                    printf("\nSe modifico el genero\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico el genero\n");
                }
                funBorrarPantalla();
                break;

            case 3:
                printf("Ingrese la nueva duracion: ");
                fflush(stdin);
                gets(auxChar);
                auxRetor = funChequeoNumero(auxChar);;
                while (auxRetor != 0)
                {
                    printf("Reingrese la nueva duracion: ");
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funChequeoNumero(auxChar);
                }
                printf("Esta seguro de cambiar la duracion? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    auxInt = atoi(auxChar);
                    (movie+index)->duracion=auxInt;
                    printf("\nSe modifico la duracion\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico la duracion\n");
                }
                funBorrarPantalla();
                break;

            case 4:
                printf("Ingrese la nueva descripcion(%d caracteres Maximo) : ",TAMDESC);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMDESC);
                while (auxRetor!=0)
                {
                    printf("Reingrese la nueva descripcion (%d caracteres Maximo) : ",TAMDESC);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, TAMDESC);
                }
                printf("\nEsta seguro de cambiar la descripcion? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy((movie+index)->descripcion, auxChar);
                    printf("\nSe modifico la descripcion\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico la descripcion\n");
                }
                funBorrarPantalla();
                break;

            case 5:
                printf("Ingrese el nuevo puntaje: ");
                scanf("%d",&auxInt);
                printf("Esta seguro de cambiar el puntaje? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    auxInt = atoi(auxChar);
                    (movie+index)->puntaje=auxInt;
                    printf("\nSe modifico el puntaje\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico el puntaje\n");
                }
                funBorrarPantalla();
                break;

            case 6:
                printf("Ingrese el nuevo link de imagen(%d caracteres Maximo) : ",TAMLINK);
                fflush(stdin);
                gets(auxChar);
                auxRetor = funContarCaracteres(auxChar, TAMLINK);
                while (auxRetor!=0)
                {
                    printf("Reingrese el nuevo link de imagen (%d caracteres Maximo) : ",TAMLINK);
                    fflush(stdin);
                    gets(auxChar);
                    auxRetor = funContarCaracteres(auxChar, TAMLINK);
                }
                printf("Esta seguro de cambiar el link? s/n");
                auxResp = getche();
                if (auxResp == 's')
                {
                    strcpy((movie+index)->linkImagen, auxChar);
                    printf("\nSe modifico el link\n");
                    flag = 1;
                }
                else
                {
                    printf("\nNo se modifico el link\n");
                }
                funBorrarPantalla();
                break;

            case 7:
                respuesta = 'n';
                break;

            default:
                printf("Opcion inexistente!!!\n");
                funBorrarPantalla();
                break;
            }
        }
        while (respuesta == 's');
    }
    else
    {
        flag = -1;
    }
    return flag;
}

int funBorrarPelicula(EMovie* movie, int t)
{
    int auxInt;
    int index;
    int flag = 0;
    char respuesta;
    funMostrarTodasPeliculas(movie,t);
    printf("Ingrese un ID no cargado para salir!\n");
    printf("Ingrese el ID de la pelicula a borrar:");
    scanf("%d",&auxInt);
    index = funBuscarId(movie,t,auxInt);
    if (index != -1)
    {
        system("cls");
        printf("ID\t%30s\t%30s\t%s\t%s\n","Titulo","Genero","Duracion","Puntaje");
        funMostrarPelicula(movie+index);
        printf("Esta seguro/a de borrar esta persona? s/n :");
        respuesta = getche();
        printf("\n");
        if (respuesta == 's')
        {
            (movie+index)->estado = 0;
        }
        else
        {
            flag = 1;
        }
    }
    else
    {
        flag = -1;
    }
    system("cls");
    return flag;
}

int funGuardar(EMovie* movie, int t, char destino[])
{
    int flag = 0;
    int cant, i;
    FILE* arch;
    arch=fopen(destino, "wb");
    if(arch != NULL)
    {
        cant = funContAlta(movie,t);
        fwrite(&cant, sizeof(int), 1, arch);
        for(i=0; i<t; i++)
        {
            if((movie+i)->estado!=0)
            {
                fwrite(movie+i, sizeof(EMovie), 1, arch);
            }
        }
        fclose(arch);
    }
    else
    {
        flag = 1;
    }
    return flag;
}

int funGenerarPagina(EMovie* movie, char nombreHTML[], int t)
{
    FILE* html;
    int i;
    char buffer [5000]= {};
    html = fopen(nombreHTML,"w");
    if (html!=NULL)
    {
        strcat(buffer,"<html lang='en'>");
        strcat(buffer,"<head>");
        strcat(buffer,"<meta charset='utf-8'>");
        strcat(buffer,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>");
        strcat(buffer,"<meta name='viewport' content='width=device-width, initial-scale=1'>");
        strcat(buffer,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->");
        strcat(buffer,"<title>Lista peliculas</title>");
        strcat(buffer,"<!-- Bootstrap Core CSS -->");
        strcat(buffer,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
        strcat(buffer,"<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->");
        strcat(buffer,"<link href='css/custom.css' rel='stylesheet'>");
        strcat(buffer,"<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->");
        strcat(buffer,"<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->");
        strcat(buffer,"<!--[if lt IE 9]>");
        strcat(buffer,"<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>");
        strcat(buffer,"<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>");
        strcat(buffer,"<![endif]-->");
        strcat(buffer,"</head>");
        strcat(buffer,"<body>");
        strcat(buffer,"<div class='container'>");
        strcat(buffer,"<div class='row'>");
        fprintf(html,"%s",buffer);
        for(i=0; i<t; i++)
        {
            if((movie+i)->estado != 0)
            {
                fprintf(html,"<article class='col-md-4 article-intro'>");
                fprintf(html,"<a href='#'>");
                fprintf(html,"<img class='img-responsive img-rounded' src='%s' alt=''>",(movie+i)->linkImagen);
                fprintf(html,"</a>");
                fprintf(html,"<h3>");
                fprintf(html,"<a href='#'> %s </a>",(movie+i)->titulo);
                fprintf(html,"</h3>");
                fprintf(html,"<ul>");
                fprintf(html,"<li>Genero:%s</li>",(movie+i)->genero);
                fprintf(html,"<li>Puntaje:%d</li>",(movie+i)->puntaje);
                fprintf(html,"<li>Duracion:%d</li>",(movie+i)->duracion);
                fprintf(html,"</ul>");
                fprintf(html,"<p>%s</p>",(movie+i)->descripcion);
                fprintf(html,"</article>");
            }
        }
        strcat(buffer,"</div>");
        strcat(buffer,"<!-- /.row -->");
        strcat(buffer,"</div>");
        strcat(buffer,"<!-- /.container -->");
        strcat(buffer,"<!-- jQuery -->");
        strcat(buffer,"<script src='js/jquery-1.11.3.min.js'></script>\<!-- Bootstrap Core JavaScript -->");
        strcat(buffer,"<script src='js/bootstrap.min.js'></script>");
        strcat(buffer,"<!-- IE10 viewport bug workaround -->");
        strcat(buffer,"<script src='js/ie10-viewport-bug-workaround.js'></script>");
        strcat(buffer,"<!-- Placeholder Images -->");
        strcat(buffer,"<script src='js/holder.min.js'></script>");
        strcat(buffer,"</body>");
        strcat(buffer,"</html>");
        fprintf(html,"%s",buffer);
    }
    else
    {
        printf("No se puede crear el archivo HTML");
    }
    fclose(html);

    return 0;
}

void funMostrarPelicula(EMovie* movie)
{
    printf("%d\t%30s\t%30s\t%8d\t%7d\n", movie->idPelicula, movie->titulo, movie->genero, movie->duracion, movie->puntaje);
}

void funMostrarTodasPeliculas(EMovie* movie, int t)
{
    int i;
    printf("ID\t%30s\t%30s\t%s\t%s\n","Titulo","Genero","Duracion","Puntaje");
    for(i=0; i<t; i++)
    {
        if ((movie+i)->estado != 0)
        {
            funMostrarPelicula(movie+i);
        }
    }
}

int funMostrarMenu(char texto[])
{
    int opcion;
    printf("%s", texto);
    printf("\nIngrese la opcion a usar: ");
    scanf("%d", &opcion);

    return opcion;
}

int funBuscarId(EMovie* movie,int t, int id)
{
    int i;
    int index;
    for (i=0; i<t; i++)
    {
        if ((movie+i)->estado != 0 && id == (movie+i)->idPelicula)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }

    }
    return index;
}

int funContarCaracteres(char campo[], int tamano)
{
    int flag = 0;
    int cont;
    cont = strlen(campo);
    if (cont > tamano)
    {
        flag = 1;
    }
    return flag;
}

int funChequeoNumero(char num[])
{
    int i = 0, cont;
    int flag = 0;
    cont = strlen(num);
    while (i<cont && flag == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

void funCargarArchivo(EMovie* movie, char destino[])
{
    int auxInt;
    FILE* arch;

    arch = fopen(destino, "rb");
    if (arch != NULL)
    {
        fread(&auxInt, sizeof(int), 1, arch);
        fread(movie, sizeof(EMovie), auxInt, arch);
        fclose(arch);
    }
}

int funContAlta(EMovie* movie, int t)
{
    int contAltas = 0, i;
    for(i=0; i<t; i++)
    {
        if((movie+i)->estado != 0)
        {
            contAltas++;
        }
    }
    return contAltas;
}

void funBorrarPantalla()
{
    system("pause");
    system("cls");
}
