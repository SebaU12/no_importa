
#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "AppleStore.csv"
using namespace std;

int main()
{
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string idProducto, codigoBarras, descripcion, precioCompra, precioVenta, price, stock;
        // Extraer todos los valores de esa fila
        getline(stream, price, delimitador);
        getline(stream, idProducto, delimitador);
        getline(stream, codigoBarras, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "Id: " << price << endl;
        cout << "cs: " << idProducto << endl;
        cout << "tp: " << codigoBarras<< endl;
    }

    archivo.close();
}