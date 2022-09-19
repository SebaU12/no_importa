#ifndef POBLAR_H 
#define POBLAR_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "estructuras.h"
#define NOMBRE_ARCHIVO "AppleStore.csv"
using namespace std;

void poblar_bd(){
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    long cont = 0; 
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {   
        //if(cont == 1400) break; 
        string id_str, id_app, track_name, size_bytes_str, currency, 
            price_str, rating_tot_str, rating_cont_str, user_rating_str, 
            user_rating_ver_str, ver, cont_rating, prime_rating,
            sup_devices_str, ipad_url_str, lang_str, vpp_str;
        string cr; 
        string acumulador; 
        int cont_br = 0;
        stringstream stream(linea); // Convertir la cadena a un stream
        // Extraer todos los valores de esa fila
        getline(stream, cr, '"');
        getline(stream, id_str, '"');
        getline(stream, cr, delimitador);
        getline(stream, id_app, delimitador);
        while(true){
            if(cont_br == 2) break; 
            getline(stream, track_name, '"');
            cont_br++; 
        }
        getline(stream, cr, delimitador);
        getline(stream, size_bytes_str, delimitador);
        getline(stream, currency, delimitador);
        getline(stream, price_str, delimitador);
        getline(stream, rating_tot_str, delimitador);
        getline(stream, rating_cont_str, delimitador);
        getline(stream, user_rating_str, delimitador);
        getline(stream, user_rating_ver_str, delimitador);
        getline(stream, ver, delimitador);
        getline(stream, cont_rating, delimitador);
        getline(stream, prime_rating, delimitador);
        getline(stream, sup_devices_str, delimitador);
        getline(stream, ipad_url_str, delimitador);
        getline(stream, lang_str, delimitador);
        getline(stream, vpp_str, delimitador);
        long id = stol(id_str); 
        long long size_bytes = stoll(size_bytes_str); 
        int lang = stoi(lang_str); 
        int vpp = stoi(vpp_str); 
        int ipad_url = stoi(ipad_url_str); 
        double sup_devices = atof(sup_devices_str.c_str());;
        double price  = atof(price_str.c_str());;
        double user_rating  = atof(user_rating_str.c_str());;
        double user_rating_ver  = atof(user_rating_ver_str.c_str());;
        double rating_tot = atof(rating_tot_str.c_str());;
        double rating_cont = atof(rating_cont_str.c_str());;
        // Imprimir
        cout << "==================" << endl;
        cout << id << "  --  " << sizeof(id) << endl; 
        cout << size_bytes << "  --  " << sizeof(size_bytes) << endl;
        cout << price << "  --  " << sizeof(price) << endl;
        cout << rating_tot << "  --  " << sizeof(rating_tot) << endl;
        cout << rating_cont << "  --  " << sizeof(rating_cont) << endl;
        cout << user_rating << "  --  " << sizeof(user_rating) << endl; 
        cout << user_rating_ver << "  --  " << sizeof(user_rating_ver) << endl;
        cout << sup_devices  << "  --  " << sizeof(sup_devices)  << endl; 
        cout << ipad_url  << "  --  " << sizeof(ipad_url)  << endl;
        cout <<  lang << "  --  " << sizeof(lang) << endl;  
        cout << vpp << "  --  " << sizeof(vpp) << endl;

        cout << ver << endl;
        cout << cont_rating << endl;
        cout << prime_rating << endl;
        cout << id_app << endl;
        cout << track_name << endl;
        cout << currency << endl;
        App app = {id, size_bytes, track_name, id_app, 
        cont_rating, ver, prime_rating, lang, vpp, ipad_url, 
        sup_devices, price, user_rating, 
        user_rating_ver, rating_tot, rating_cont};
    cout << endl << "CONTADOR: " << cont << endl;
        cont++; 
    }
    archivo.close();
}

#endif