#include <stdio.h>
#include "arraySSL.h"
#include <stdlib.h>
#include <string.h>
#include "linked.h"

dataKota *arrayKota;

void alokasiArray(int jmlElemen)
{
    char buffer[100];

    arrayKota = (dataKota *)malloc(jmlElemen * sizeof(dataKota));

    if (arrayKota != NULL)
    {
        printf("alokasi berhasil\n");
        for (int i = 0; i < jmlElemen; i++)
        {
            printf("masukkan nama kota untuk array index ke-%d: ", i);
            scanf("%s", buffer);

            arrayKota[i].kota = strdup(buffer); // strdup alokasi + copy string
            arrayKota[i].headWarga = NULL;
        }
    }
}

alamat alokasiWarga(const char *namaWarga)
{
    alamat P;
    P = (alamat)malloc(sizeof(dataNama));
    if (P != NULL)
    {

        nextNama(P) = NULL;
        nama(P) = strdup(namaWarga);
        printf("alokasi warga berhasil!\n");
    }
    return (P);
}

int searchKota(const char *namaKota, int jumlahKota)
{
    start:
    for (int i = 0; i < jumlahKota; i++)
    {
        if (strcasecmp(arrayKota[i].kota, namaKota) == 0)
        {
            printf("Comparing: '%s' vs '%s'\n", arrayKota[i].kota, namaKota);
            return i;
        }
    }
    printf("nama kota tidak tersedia!\n");
    printf("masukkan nama kota: ");
    scanf("%s",namaKota);
    goto start;
    return -1;
}

void addWarga(int indexKota, alamat P)
{
    alamat current = arrayKota[indexKota].headWarga;
    if (arrayKota[indexKota].headWarga == NULL)
    {
        arrayKota[indexKota].headWarga = P;
        printf("add warga berhasil\n");
    }
    else
    {
        while (nextNama(current) != NULL)
        {
            current = nextNama(current);
        }
        nextNama(current) = P;
        printf("add warga berhasil\n");
    }
}

void delWarga(int indexKota, alamat current, alamat prev)
{
    if (prev == NULL) {
        // Kasus node pertama dihapus
        arrayKota[indexKota].headWarga = nextNama(current);
    } else {
        nextNama(prev) = nextNama(current);
    }
    free(current);
}


void addKota(const char *namaKota, int *jmlElemen)
{
    (*jmlElemen) ++;
    arrayKota = (dataKota *) realloc(arrayKota, (*jmlElemen) * sizeof(dataKota));
    arrayKota[(*jmlElemen)-1].kota = strdup(namaKota);
    printf("add kota berhasil\n");
}

void delKota(const char *namaKota, int *jmlElemen, int i)
{
    alamat current= arrayKota[i].headWarga;
    while(current!=NULL){
        alamat temp = current;
        current = nextNama(current);
        free(temp);
    }
    for (int k=i; k<(*jmlElemen)-1; k++){
        arrayKota[k] = arrayKota[k+1];
    }
    (*jmlElemen)--;
    arrayKota = (dataKota *) realloc(arrayKota, (*jmlElemen) * sizeof(dataKota));
    printf("delKota berhasil!\n");
}

void printDataWargaPerKota(int indexKota)
{
    alamat current = arrayKota[indexKota].headWarga;
    printf("%s ", arrayKota[indexKota].kota);
    if (arrayKota[indexKota].headWarga == NULL)
    {
        printf("Data nama kosong \a\n");
    }
    else
    {
        for (;;)
        {

            if (current != NULL)
            {
                printf("%s ", nama(current));
                current = nextNama(current);
            }
            else
            {
                break;
            }
        }
    }
}

int jmlDataNamaPerKota(int i)
{
    alamat current= arrayKota[i].headWarga;
    int count=0;
    while(current!=NULL){
        count++;
        current = nextNama(current);
    }
    return count;
}

int jmlTotalKota(int jmlElemen)
{
    return jmlElemen;
}

int jmlTotalNama(int jmlElemen)
{
    int count=0;\
    for (int i=0; i<jmlElemen; i++){
        alamat current = arrayKota[i].headWarga;
        while (current != NULL){
            count++;
            current = nextNama(current);
        }
    }
    return count;
}

void printDataKota(int elemenArray){
    for (int i=0; i<elemenArray; i++){
        printf("%s ", arrayKota[i].kota);
    }
}