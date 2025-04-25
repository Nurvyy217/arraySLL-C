#ifndef ARRAYSLL_H
#define ARRAYSLL_H

#define nama(P) (P)->nama
#define nextNama(P) (P)->nextNama
#define headWarga(P) (P)->headWarga

typedef struct dataNama *alamat;
typedef struct dataNama
{
    char *nama;
    alamat nextNama;
} dataNama;


typedef struct dataKota
{
    char *kota;
    alamat headWarga;
} dataKota;

extern dataKota *arrayKota;

void alokasiArray(int jmlElemen);
int searchKota(const char *namaKota, int jumlahKota);
alamat alokasiWarga(const char *namaWarga);
void addWarga(int indexKota, alamat P);
void printDataWargaPerKota(int indexKota);
void delWarga(int indexKota, alamat current, alamat prev);
void addKota(const char *namaKota, int *jmlElemen);
void delKota(const char *namaKota, int *jmlElemen, int i);
void printDataKota(int elemenArray);
int jmlDataNamaPerKota(int i);
int jmlTotalKota(int jmlElemen);
int jmlTotalNama(int jmlElemen);
#endif