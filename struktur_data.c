#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 100
#define MAX_STRING 100

typedef struct {
    char npm[10];
    char nama[MAX_STRING];
    char tempat_lahir[MAX_STRING];
    char tanggal_lahir[11];
    char prodi[MAX_STRING];
} Mahasiswa;

Mahasiswa mahasiswa[MAX_MAHASISWA];
int jumlah_mahasiswa = 0;

/**
 * Prosedur untuk menambahkan mahasiswa baru ke sistem.
 *
 * Prosedur ini meminta pengguna untuk memasukkan detail mahasiswa baru,
 * seperti NPM, nama, tempat lahir, tanggal lahir, dan program studi.
 * Prosedur ini kemudian menambahkan mahasiswa ke array mahasiswa jika masih
 * ada ruang tersedia. Jika jumlah maksimum mahasiswa telah tercapai,
 * ditampilkan pesan error.
 *
 * @param void
 * @return void
 */
void tambah_mahasiswa() {
    if (jumlah_mahasiswa < MAX_MAHASISWA) {
        Mahasiswa m;
        printf("NPM: ");
        scanf("%s", m.npm);
        printf("Nama: ");
        scanf("%s", m.nama);
        printf("Tempat Lahir: ");
        scanf("%s", m.tempat_lahir);
        printf("Tanggal Lahir (DD/MM/YYYY): ");
        scanf("%s", m.tanggal_lahir);
        printf("Prodi: ");
        scanf(" %[^\n]", m.prodi);

        mahasiswa[jumlah_mahasiswa++] = m;
        printf("Mahasiswa berhasil ditambahkan.\n");
    } else {
        printf("Batas maksimum mahasiswa telah tercapai.\n");
    }
}

/**
 * Prosedur untuk mengedit informasi mahasiswa.
 *
 * Prosedur ini meminta pengguna untuk memasukkan NPM (ID mahasiswa) dari mahasiswa yang akan diedit.
 * Kemudian, Prosedur ini mencari mahasiswa dengan NPM yang diberikan dalam array mahasiswa.
 * Jika ditemukan, Prosedur ini meminta pengguna untuk memasukkan nama baru, tempat lahir baru,
 * tanggal lahir baru, dan program studi baru untuk mahasiswa tersebut.
 * Prosedur ini mengupdate informasi mahasiswa dan menampilkan pesan berhasil.
 * Jika tidak ada mahasiswa dengan NPM yang diberikan, ditampilkan pesan error.
 */
void edit_mahasiswa() {
    char npm[10];
    printf("Masukkan NPM mahasiswa yang akan diedit: ");
    scanf("%s", npm);

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (strcmp(mahasiswa[i].npm, npm) == 0) {
            printf("Nama baru: ");
            scanf("%s", mahasiswa[i].nama);
            printf("Tempat Lahir baru: ");
            scanf("%s", mahasiswa[i].tempat_lahir);
            printf("Tanggal Lahir baru (DD/MM/YYYY): ");
            scanf("%s", mahasiswa[i].tanggal_lahir);
            printf("Prodi baru: ");
            scanf(" %[^\n]", mahasiswa[i].prodi);
            printf("Data mahasiswa berhasil diubah.\n");
            return;
        }
    }
    printf("Mahasiswa dengan NPM tersebut tidak ditemukan.\n");
}

/**
 * Prosedur untuk menampilkan informasi semua mahasiswa.
 * Jika tidak ada mahasiswa, akan mencetak pesan yang menunjukkan bahwa tidak ada data mahasiswa.
 */
void tampilkan_mahasiswa() {
    if (jumlah_mahasiswa == 0) {
        printf("Tidak ada data mahasiswa.\n");
        return;
    }

    printf("--------------------\n");

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("NPM: %s\n", mahasiswa[i].npm);
        printf("Nama: %s\n", mahasiswa[i].nama);
        printf("Tempat Lahir: %s\n", mahasiswa[i].tempat_lahir);
        printf("Tanggal Lahir: %s\n", mahasiswa[i].tanggal_lahir);
        printf("Prodi: %s\n", mahasiswa[i].prodi);
        printf("--------------------\n");
    }
}

/**
 * Prosedur untuk menghapus mahasiswa dari struktur data.
 *
 * Prosedur ini meminta pengguna untuk memasukkan NPM (ID mahasiswa) dari mahasiswa yang akan dihapus.
 * Kemudian, Prosedur ini mencari mahasiswa dengan NPM yang diberikan dalam struktur data.
 * Jika ditemukan, Prosedur ini menghapus mahasiswa dari struktur data dengan menggeser elemen-elemen setelahnya.
 * Terakhir, Prosedur ini mengupdate jumlah mahasiswa dan mencetak pesan berhasil.
 * Jika tidak ada mahasiswa dengan NPM yang diberikan, ditampilkan pesan error.
 */
void hapus_mahasiswa() {
    char npm[10];
    printf("Masukkan NPM mahasiswa yang akan dihapus: ");
    scanf("%s", npm);

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (strcmp(mahasiswa[i].npm, npm) == 0) {
            for (int j = i; j < jumlah_mahasiswa - 1; j++) {
                mahasiswa[j] = mahasiswa[j + 1];
            }
            jumlah_mahasiswa--;
            printf("Data mahasiswa berhasil dihapus.\n");
            return;
        }
    }
    printf("Mahasiswa dengan NPM tersebut tidak ditemukan.\n");
}


/**
 * @file struktur_data.c
 * @brief Program untuk mengelola data mahasiswa.
 *
 * Program ini menyediakan antarmuka berbasis menu untuk mengelola data mahasiswa. Ini memungkinkan pengguna untuk melakukan operasi berikut:
 * 1. Tambah Mahasiswa
 * 2. Edit Mahasiswa
 * 3. Tampilkan Mahasiswa
 * 4. Hapus Mahasiswa
 * 0. Keluar
 *
 * Program menggunakan loop do-while untuk secara berulang menampilkan menu dan meminta pengguna untuk memilih sampai mereka memilih untuk keluar.
 * Berdasarkan pilihan pengguna, program memanggil Prosedur yang sesuai untuk melakukan operasi yang diinginkan.
 *
 * @return 0 jika berhasil dieksekusi.
 */
int main() {
    int pilihan;

    do {
        printf("\nSistem Manajemen Mahasiswa\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Edit Mahasiswa\n");
        printf("3. Tampilkan Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambah_mahasiswa();
                break;
            case 2:
                edit_mahasiswa();
                break;
            case 3:
                tampilkan_mahasiswa();
                break;
            case 4:
                hapus_mahasiswa();
                break;
            case 0:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}
