#ifndef VARIABLERECORD_H 
#define VARIABLERECORD_H

#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include "estructuras.h"
using namespace std;

struct Index {
 int pos;
 int total;
 int size_codigo;
 int size_observaciones;
};

class VariableRecord {
private:
 string file;
 string index_file;
public:
 VariableRecord() {}
 VariableRecord(string _file);
 void add(App record);
 vector<App> load();
 App readRecord(int pos);
};
VariableRecord::VariableRecord(string _file) {
 this->file = _file + ".dat";
 this->index_file = _file + "_index.dat";
 ofstream inFile;
 inFile.open(this->file, ios::binary | ios::app);
 inFile.close();
 ofstream inFile_index;
 inFile_index.open(this->index_file, ios::binary | ios::app);
 inFile_index.close();
}
void VariableRecord::add(App record) {
 int size_codigo = record.codigo.size();
 int size_observaciones = record.observaciones.size();
 int cant_bytes =
 size_codigo + size_observaciones + sizeof(int) + sizeof(float);
 ofstream file;
 int scant_bytes = cant_bytes;
 Index getInd;
 int pos_total = 0;
 file.open(this->file, ios::binary | ios::app);
 if (file.is_open()) {
 file.write(&record.codigo[0], record.codigo.size());
 file.write((char *)&record.ciclo, sizeof(record.ciclo));
 file.write((char *)&record.mensualidad, sizeof(record.mensualidad));
 file.write(&record.observaciones[0], record.observaciones.size());
 file.close();
 } else {
 throw "No se pudo abrir el archivo";
 }
 ifstream file_ind;
 file_ind.open(this->index_file, ios::binary);
 if (file_ind.is_open()) {
 if (file_ind.peek() != EOF) {
 if (!file_ind.eof()) {
 file_ind.seekg(0, file_ind.beg);
 while (!file_ind.eof()) {
 file_ind.read((char *)&getInd, sizeof(Index));
 if (file_ind.eof()) {
 break;
 }
 pos_total += getInd.total;
 }
 }
 }
 file_ind.close();
 } else {
 throw "No se pudo abrir el archivo";
 }
 ofstream file_save;
 file_save.open(this->index_file, ios::binary | ios::app);
 if (file_save.is_open()) {
 Index ind = {pos_total, cant_bytes, size_codigo, size_observaciones};
 file_save.write((char *)&ind, sizeof(Index));
 file.close();
 } else {
 throw "No se pudo abrir el archivo";
 }
}
vector<Matricula> VariableRecord::load() {
 vector<Matricula> result;
 Matricula dataMatricula;
 Index dataIndex;
 ifstream file_ind;
 ifstream file;
 file_ind.open(this->index_file, ios::binary);
 if (file_ind.is_open() != true)
 throw "No se pudo abrir el archivo";
 file.open(this->file, ios::binary);
 if (file.is_open()) {
 while (true) {
 file_ind.read((char *)&dataIndex, sizeof(Index));
 dataMatricula.codigo.resize(dataIndex.size_codigo);
 dataMatricula.observaciones.resize(dataIndex.size_observaciones);
 file.read(&dataMatricula.codigo[0], dataIndex.size_codigo);
 file.read((char *)&dataMatricula.ciclo, sizeof(int));
 file.read((char *)&dataMatricula.mensualidad, sizeof(float));
 file.read(&dataMatricula.observaciones[0], dataIndex.size_observaciones);
 if (file.eof()){
 break;
 }
 result.push_back(dataMatricula);
 }
 file.close();
 file_ind.close();
 } else {
 throw "No se pudo abrir el archivo";
 }
 return result;
}
App VariableRecord::readRecord(int pos) {
 App result;
 Index index;
 ifstream file;
 ifstream file_index;
 pos -= 1;
 file_index.open(this->index_file, ios::binary);
 file.open(this->file, ios::binary);
 if (file_index.is_open()) {
 file_index.seekg(pos * sizeof(Index), ios::beg);
 file_index.read((char *)&index, sizeof(Index));
 file_index.close();
 } else {
 throw "No se pudo abrir el archivo";
 }
 int npos = index.pos;
 if (file.is_open()) {
 file.seekg(npos, ios::beg);
 result.codigo.resize(index.size_codigo);
 result.observaciones.resize(index.size_observaciones);
 file.read(&result.codigo[0], index.size_codigo);
 file.read((char *)&result.ciclo, sizeof(int));
 file.read((char *)&result.mensualidad, sizeof(float));
 file.read(&result.observaciones[0], index.size_observaciones);
 file.close();
 } else {
 throw "No se pudo abrir el archivo";
 }
 return result;
}

#endif