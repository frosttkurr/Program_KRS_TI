#include "struct.h"

/* MENCETAK JUDUL */
void mencetak_judul(int garis){
    printf("\n\t\t\t\t\xc9");
    for (garis=0; garis<50; garis++){
        printf("\xcd");
    }
    printf("\xbb");
    printf("\n\t\t\t\t\xba\t\t PROGRAM MENGISI KRS\t\t   \xba");
    printf("\n\t\t\t\t\xc8");
    for (garis=0; garis<50; garis++){
        printf("\xcd");
    }
    printf("\xbc");
}

/* MENCETAK TABEL ATAS KRS */
void mencetak_header_krs(int garis) {
    printf("\n  \xda");
    for (garis=0;garis<59;garis++){
            printf("\xc4");
        }
    printf("\xbf");
    printf("\n  \xb3 NO \xb3    KODE    \xb3\t      MATA KULIAH\t\t\xb3 SKS \xb3");
    printf("\n  \xc3");
        for (garis=0;garis<59;garis++){
            printf("\xc4");
        }
    printf("\xb4 \t\xf9 Pilihan: ");
}

/* MENCETAK TABEL BAWAH KRS */
void mencetak_footer_krs(int garis, int total_sks){
    printf("  \xc3");
    for (garis=0;garis<59;garis++){
        printf("\xc4");
    }
    printf("\xb4");
    printf("\n  \xb3\t\tTOTAL \t\t\t\t\t\xb3  %02d \xb3", total_sks);
    printf("\n  \xc0");
    for (garis=0;garis<59;garis++){
        printf("\xc4");
    }
    printf("\xd9");
}

/* MENCETAK PILIHAN MATKUL */
void memilih_matakuliah(struct Data user){
    int garis;
    char daftar_matkul[100];

    if (user.semester==3) {
        FILE*matkul;
        matkul=fopen("matkul_smt3.txt","r");
        while(!feof(matkul)){
            fgets(daftar_matkul,100,matkul);
            printf("%s", daftar_matkul);
        }
        fclose(matkul);

    } else if (user.semester>=4 && user.semester <=14) {
        if (strcmp(user.konsentrasi,"Manajemen Keamanan Jaringan")==0 || strcmp(user.konsentrasi,"MKJ")==0){
            FILE*matkul;
            matkul=fopen("matkul_mkj.txt","r");
            while(!feof(matkul)){
                fgets(daftar_matkul,100,matkul);
                printf("%s", daftar_matkul);
            }
            fclose(matkul);

        } else if (strcmp(user.konsentrasi,"Teknologi Cerdas")==0 || strcmp(user.konsentrasi,"TC")==0){
            FILE*matkul;
            matkul=fopen("matkul_tc.txt","r");
            while(!feof(matkul)){
                fgets(daftar_matkul,100,matkul);
                printf("%s", daftar_matkul);
            }
            fclose(matkul);

        } else if (strcmp(user.konsentrasi,"Manajemen Bisnis")==0 || strcmp(user.konsentrasi,"MB")==0){
            FILE*matkul;
            matkul=fopen("matkul_mb.txt","r");
            while(!feof(matkul)){
                fgets(daftar_matkul,100,matkul);
                printf("%s", daftar_matkul);
            }
            fclose(matkul);

        } else if (strcmp(user.konsentrasi,"Manajemen Data dan Informasi")==0 || strcmp(user.konsentrasi,"MDI")==0){
            FILE*matkul;
            matkul=fopen("matkul_mdi.txt","r");
            while(!feof(matkul)){
                fgets(daftar_matkul,100,matkul);
                printf("%s", daftar_matkul);
            }
            fclose(matkul);
        }
    }
}

/* MENCETAK KETENTUTAN SKS */
void mencetak_ketentuan_sks(struct Data user){
    if ((user.ipk > 4 || user.ipk <= 0) && (user.semester != 1 || user.semester !=2)){
        printf("\n\t#ERROR: Input salah, ulangi!");
    } else if (user.semester==1 || user.semester==2){
        printf("\n\t#KET: KRS Paket\n");
    } else if (user.ipk <= 4 && user.ipk >= 3){
        printf("\n\t#KET: Jumlah SKS maksimal 24\n");
    } else if (user.ipk < 3 && user.ipk >= 2.5){
        printf("\n\t#KET: Jumlah SKS maksimal 21\n");
    } else if (user.ipk < 2.5 && user.ipk >= 2){
        printf("\n\t#KET: Jumlah SKS maksimal 18\n");
    } else if (user.ipk < 2 && user.ipk >= 1.5){
        printf("\n\t#KET: Jumlah SKS maksimal 15\n");
    } else if (user.ipk < 1.5 && user.ipk >= 1){
        printf("\n\t#KET: Jumlah SKS maksimal 12\n");
    }
}

/* MENCETAK DATA USER */
void mencetak_data_diri(struct Data user, int nim, char name[40]){
    int garis;

    printf("\n\n\n");
    for (garis=0; garis<110; garis++){
        printf("\xcd");
    }
    printf("\n\n\n   Nama       : %s", name);
    printf("\n   NIM        : %d", nim);

    if (user.semester > 3 && user.semester <= 14) {
        printf("\n   Konsentrasi: %s", user.konsentrasi);
    }

    printf("\n   Semester   : %d", user.semester);
    printf("\n   Tahun      : %d", user.tahun_ajaran);
}

/* MENCHECK KEABSAHAN KRS */
int mengecek_krs(struct Data user, int total_sks){
    if (user.semester==1 || user.semester==2){
        Sleep(1000);
        printf("\n\t#KET: KRS tercetak");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(2300);
        printf("\r                             ");

    } else if (user.semester>=3 && user.semester <=14){
        if (user.ipk <= 4 && user.ipk >= 3){
            if (total_sks > 24) {
                printf("\n\t#ERROR: Jumlah SKS maksimal 24\n");
                Sleep(2000);
                main();
            } else {
                Sleep(1000);
                printf("\n\t#KET: KRS tercetak");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(2300);
                printf("\r                             ");
            }

        } else if (user.ipk < 3 && user.ipk >= 2.5){
            if (total_sks > 21) {
                printf("\n\t#ERROR: Jumlah SKS maksimal 21\n");
                Sleep(2000);
                main();
            } else {
                Sleep(1000);
                printf("\n\t#KET: KRS tercetak");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(2300);
                printf("\r                             ");
            }

        } else if (user.ipk < 2.5 && user.ipk >= 2){
            if (total_sks>18){
                printf("\n\t#ERROR: Jumlah SKS maksimal 18\n");
                Sleep(2000);
                main();
            } else {
                Sleep(1000);
                printf("\n\t#KET: KRS tercetak");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(2300);
                printf("\r                             ");
            }

        } else if (user.ipk < 2 && user.ipk >= 1.5){
            if (total_sks>15) {
                printf("\n\t#ERROR: Jumlah SKS maksimal 15\n");
                Sleep(2000);
                main();
            } else {
                Sleep(1000);
                printf("\n\t#KET: KRS tercetak");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(2300);
                printf("\r                             ");
            }

        } else if (user.ipk < 1.5 && user.ipk >= 1){
            if (total_sks>12) {
                printf("\n\t#ERROR: Jumlah SKS maksimal 12\n");
                Sleep(2000);
                main();
            } else {
                Sleep(1000);
                printf("\n\t#KET: KRS tercetak");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(2300);
                printf("\r                             ");
            }
        }
    }
    return total_sks;
}
