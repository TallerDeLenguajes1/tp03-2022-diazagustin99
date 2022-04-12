#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

Cliente pedircliente(int id);
void mostrarpedido(Cliente pedido);
int main(int argc, char const *argv[])
{
    int t = 3;
    Cliente clientes[t];
    printf("\n\n\n        ***SISTEMA DE CARGA DE PEDIDOS Y CLIENTES**         \n\n\n");
     printf("Cuantos clientes ingresara?");
     scanf("%i", &t);
     fgetc(stdin);
     for (int i = 0; i < t; i++)
     {
    clientes[i] = pedircliente(i);
     }
    printf("\n\n\n        ***TODOS LOS PEDIDOS REALIZADOS**         \n\n\n");
     for (int i = 0; i < t; i++)
     {
         mostrarpedido(clientes[i]);
     }
     
    return 0;
}

Cliente pedircliente(int id)
{
    Cliente cliente;
    char *Buff;
    int aux;
    Buff = (char *)malloc(100 * sizeof(char));
    cliente.ClienteID = id;
    cliente.CantidadProductosAPedir = rand() % 6;
    cliente.Productos = (Producto *)calloc(cliente.CantidadProductosAPedir, sizeof(Producto));
    printf("\n***PEDIDO NUEVO: ***\n\n");

    printf("Ingrese el nombre del cliente:");
    gets(Buff);
    cliente.NombreCliente = (char *)malloc((strlen(Buff) + 1) * sizeof(char));
    strcpy(cliente.NombreCliente, Buff);

    printf("\nCarga de productos (%i Productos por cargar):\n\n", cliente.CantidadProductosAPedir);
    for (int i = 0; i < cliente.CantidadProductosAPedir; i++)
    {
        cliente.Productos[i].ProductoID = 1;
        printf("Lista de productos:\n");
        for (int j = 0; j < 5; j++)
        {
            printf("%i- %s\n", j, TiposProductos[j]);
        }
        printf("Seleccione un producto: ");
        scanf("%i", &aux);
        fgetc(stdin);
        cliente.Productos[i].TipoProducto = (char *)malloc((strlen(TiposProductos[aux]) + 1) * sizeof(char));
        strcpy(cliente.Productos[i].TipoProducto, TiposProductos[aux]);
        printf("Ingrese la cantidad de estos productos: ");
        scanf("%i", &cliente.Productos[i].Cantidad);
        fgetc(stdin);
        switch (aux)
        {
        case 0:
            cliente.Productos[i].PrecioUnitario = 10;
            break;
        case 1:
            cliente.Productos[i].PrecioUnitario = 25;
            break;
        case 2:
            cliente.Productos[i].PrecioUnitario = 16;
            break;
        case 3:
            cliente.Productos[i].PrecioUnitario = 75;
        case 4:
            cliente.Productos[i].PrecioUnitario = 93;
            break;
        default:
         cliente.Productos[i].PrecioUnitario = 999;
            break;
        }
    }
    free(Buff);
    mostrarpedido(cliente);
    return cliente;
}

void mostrarpedido(Cliente pedido)
{
    float total = 0;
    int cantidadP = 0;
    printf("***PEDIDO A NOMBRE DE: %s***\n\n", pedido.NombreCliente);
    printf("CLIENTE ID: %i\n", pedido.ClienteID);
    printf("Productos:\n");
    for (int i = 0; i < pedido.CantidadProductosAPedir; i++)
    {
        printf("%i-%s CANTIDAD: %i\n", i, pedido.Productos[i].TipoProducto, pedido.Productos[i].Cantidad);
        total = total + (pedido.Productos[i].Cantidad * pedido.Productos[i].PrecioUnitario);
        cantidadP = cantidadP + pedido.Productos[i].Cantidad;
    }

    printf("\nEN %i PRODUCTOS SE HIZO UN TOTAL DE $%.2f\n", cantidadP, total);
}

