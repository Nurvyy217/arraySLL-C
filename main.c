#include <stdio.h>
#include "arraySSL.h"
#include <string.h>
#include <stdlib.h>
#include "linked.h"

int main()
{
    int elemenArray, choice;
    char *cityName;
    char *peopleName;
    char buffer[100];
    int indexKota;


start:
    printf("Masukkan jumlah elemen array (minimal 5): ");
    scanf("%d", &elemenArray);
    if (elemenArray < 5)
    {
        printf("jumlah elemen array minimal 5\n");
        goto start;
    }
    else
    {
        alokasiArray(elemenArray);

        for (int i = 0; i < elemenArray; i++)
        {
            printf("array kota : %s\n", arrayKota[i].kota);
        }

        do
        {
            printf("\n\n ------MENU UTAMA------- \n");
            printf("1. Masukkan nama warga \n");
            printf("2. Delete warga \n");
            printf("3. Hapus kota \n");
            printf("4. Tambah kota \n");
            printf("5. Print data nama per kota \n");
            printf("6. Print data kota \n");
            printf("7. Print jumlah total kota \n");
            printf("8. Print jumlah total data nama \n");
            printf("9. Print jumlah total warga untuk suatu kota \n");
            printf("10. Keluar program \n");
            printf("Pilihan: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("masukkan nama kota yang ingin diisi data warga: ");
                scanf("%s", buffer);
                cityName= strdup(buffer);
                indexKota = searchKota(cityName, elemenArray);
                printf("%d\n", indexKota);
                printf("masukkan nama warga yang akan ditambahkan: ");
                scanf("%s", buffer);
                peopleName = strdup(buffer);
                alamat warga = alokasiWarga(peopleName);
                addWarga(indexKota, warga);
                break;
            case 2:
                printf("masukkan nama kota yang data warganya akan di delete: ");
                scanf("%s", buffer);
                cityName= strdup(buffer);
                indexKota = searchKota(cityName, elemenArray);
                printf("masukkan nama warga yang akan di delete: ");
                scanf("%s", buffer);
                peopleName = strdup(buffer);
                alamat current = Search(indexKota, peopleName);
                alamat prev = SearchPrec(indexKota, peopleName);
                if (current == NULL) {
                    printf("Warga dengan nama '%s' tidak ditemukan!\n", peopleName);
                } else {
                    delWarga(indexKota, current, prev);
                    printf("Warga berhasil dihapus!\n");
                }
                break;
            case 3:
                printf("masukkan nama kota yang akan di delete: ");
                scanf("%s", buffer);
                cityName= strdup(buffer);
                indexKota = searchKota(cityName, elemenArray);
                delKota(cityName, &elemenArray, indexKota);
                break;
            case 4:
                printf("masukkan nama kota yang akan di ditambahkan: ");
                scanf("%s", buffer);
                cityName= strdup(buffer);
                addKota(cityName, &elemenArray);
                break;
            case 5:
                printf("masukkan nama kota yang akan dilihat data warganya: ");
                scanf("%s", cityName);
                indexKota = searchKota(cityName, elemenArray);
                printDataWargaPerKota(indexKota);
                break;
            case 6:
                printDataKota(elemenArray);
                break;
            case 7:
                int totalKota = jmlTotalKota(elemenArray);
                printf("jumlah total kota adalah: %d\n", totalKota);
                break;
            case 8:
                int totalWarga = jmlTotalNama(elemenArray);
                printf("jumlah total data nama warga: %d\n",totalWarga);
                break;
            case 9:
                printf("masukkan nama kota yang akan dilihat total warga nya: ");
                scanf("%s", buffer);
                cityName= strdup(buffer);
                indexKota = searchKota(cityName, elemenArray);
                int totWarga = jmlDataNamaPerKota(indexKota);
                printf("jumlah total warga di kota %s adalah: %d\n",cityName, totWarga);
                break;
            case 10:
                printf("program selesai\n");
                break;
            default:
                printf("pilihan tidak valid!\n");
                break;
            }
        } while (choice != 10);
    }
    return 0;
}