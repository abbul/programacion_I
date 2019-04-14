#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

typedef struct
{
    int idCliente; // PK
    int formaDePago;
    int cantidaComprada;
    int vendedor;
    int fechaVenta;
    int cuentaEmisora;
    int cuentaReceptora;
    int recibo;

}ePago;

int agrega_capital (int[]);
ePago cargar_pago (ArrayList*,ArrayList*, ArrayList*, int[],int);
ePago* nuevo_pago(ArrayList*,ArrayList*, ArrayList*, int[]);

#endif // PAGOS_H_INCLUDED
