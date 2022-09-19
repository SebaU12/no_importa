#ifndef ESTRUCTURAS_H 
#define ESTRUCTURAS_H

#include <iostream>
using namespace std;

struct App {
    long id; 
    long long size_bytes; 
    string track_name, id_app, 
        cont_rating, ver, prime_rating;
    int lang, vpp, ipad_url; 
    double sup_devices, price, user_rating, 
        user_rating_ver, rating_tot, rating_cont;
};

#endif