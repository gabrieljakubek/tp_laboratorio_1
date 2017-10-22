#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <windows.h>

int main()
{
    system("mode con: cols=120 lines=30");
    system("color 2");
    EMovie pelicula[TAM];
    int opcion;
    int auxInt;
    char seguir = 's';
    funIniEstadoPelicula(pelicula, TAM);
    funCargarArchivo(pelicula,"archivo.dat");
    do
    {
        opcion=funMostrarMenu("1- Agregar pelicula\
                                \n2- Modificar pelicula\
                                \n3- Borrar pelicula\
                                \n4- Guardar datos\
                                \n5- Generar pagina web\
                                \n6- Salir");

        switch(opcion)
        {
        case 1:
            funMostrarTodasPeliculas(pelicula,TAM);
            auxInt = funAgregarPelicula(pelicula, TAM);
            if (auxInt == 0)
            {
                printf("No se pueden cargar mas peliculas\n");
                funBorrarPantalla();
            }
            else if (auxInt == 1)
            {
                printf("Pelicula cargada\n");
                funBorrarPantalla();
            }
            else
            {
                printf("ID ya Cargada\n");
                funBorrarPantalla();
            }
            break;
        case 2:
            auxInt = funModificarPelicula(pelicula,TAM);
            if (auxInt == 0)
            {
                printf("No se modifico la pelicula\n");
                funBorrarPantalla();
            }
            else if (auxInt == 1)
            {
                printf("Pelicula modificada\n");
                funBorrarPantalla();
            }
            else
            {
                printf("El ID ingresado no existe\n");
                funBorrarPantalla();
            }
            break;

        case 3:
            auxInt = funBorrarPelicula(pelicula, TAM);
            if (auxInt == 0)
            {
                printf("La pelicula se ha borrado\n");
                funBorrarPantalla();
            }
            else if (auxInt == 1)
            {
                printf("Accion cancelada por el usuario\n");
                funBorrarPantalla();
            }
            else
            {
                printf("El ID ingresado es inexistente!!!\n");
                funBorrarPantalla();
            }
            break;

        case 4:
            auxInt = funGuardar(pelicula,TAM,"archivo.dat");
            if (auxInt != 1)
            {
                printf("Los datos fueron guradados exitosamente\n");
                funBorrarPantalla();
            }
            else
            {
                printf("Los daton no han podido ser guardados\n");
                funBorrarPantalla();
            }
            break;

        case 5:
            auxInt = funGuardar(pelicula,TAM,"archivo.dat");
            if (auxInt != 1)
            {
                funGenerarPagina(pelicula,"index.html",TAM);
                printf("Los datos fueron cargados\n");
                funBorrarPantalla();
            }
            else
            {
                printf("Los daton no han podido ser guardados y no se pudo generar la pagina\n");
                funBorrarPantalla();
            }
            break;

        case 6:
            seguir = 'n';
            printf("Chau Chau!!!!!");
            break;

        default:
            printf("Opcion inexistente!!!\n");
            funBorrarPantalla();
            break;
        }
    }
    while(seguir != 'n');
    return 0;
}
