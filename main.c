#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "prosedur.c"

int main(){

    struct Data user;
    char daftar_matkul[100], name[40];
    int garis, count=0, pilihan, nim, no_matkul, sks, total_sks=0, found=0;

    /* REGISTRASI/LOGIN NIM & NAMA*/
    do {
        system("cls");
        mencetak_judul(garis);
        printf("\n\n\t\xfe   MENU AWAL   \xfe");
        printf("\n\n\t\xf0  1. Register  \xf0\n\t\xf0  2. Login     \xf0\n\n\t Input : ");
        scanf("%d", &pilihan);
        system("cls");

        if (pilihan==1){
            printf("\n\t\xf0 REGISTRASI \xf0");
            printf("\n\n\t\t\xf9 Input NIM  : ");
            scanf("%d", &user.nim);
            nim=user.nim;
            printf("\t\t\xf9 Input NAMA : ");
            scanf(" %[^\n]s", &user.nama);
            strcpy(name, user.nama);

            FILE *login;
            login=fopen("login_krs.txt","a+");

            while (!feof(login)){
                fscanf(login,"%[^#]#%d\n", &user.nama, &user.nim);
                if (nim==user.nim) {
                    found=1;
                    printf("\n\t\t#ERROR: Data sudah terdaftar!");
                    Sleep(1500);
                    main();
                }
                fflush(stdin);
            }
            user.nim=nim;
            strcpy(user.nama, name);
            fflush(stdin);
            fprintf(login,"%s#%d\n", user.nama, user.nim);
            printf("\n\t\t#KET: DATA berhasil terdaftar!");

            fclose(login);

            Sleep(1500);
            main();

        } else if (pilihan==2){
            printf("\n\t\xf0 LOGIN \xf0");
            printf("\n\n\t\t\xf9 Input NIM  : ");
            scanf("%d", &nim);

            FILE *login;
            login=fopen("login_krs.txt","r");
            while (!feof(login)){
                fscanf(login,"%[^#]#%d\n", &user.nama, &user.nim);
                if (nim==user.nim) {
                    found=1;
                    printf("\n\t\t#KET: Sedang memproses...");
                    strcpy(name, user.nama);
                }
            }
            if (found==0){
                printf("\n\t\t#ERROR: NIM tidak terdaftar!");
                Sleep(1500);
                main();
            }
            fclose(login);
        }
    } while (pilihan!=1 && pilihan!=2);

    /* MENGISI DATA TERKAIT KRS*/
    do {
        Sleep(1500);
        system("cls");
        mencetak_judul(garis);
        printf("\n\n   \xfe DATA DIRI MAHASISWA \xfe");
        printf("\n\t\xf9 Nama         : %s", name);
        printf("\n\t\xf9 NIM          : %d", nim);

        do {
            printf("\n\t\xf9 Semester     : ");
            scanf("%d", &user.semester);
                if (user.semester > 2 && user.semester <= 14){
                    printf("\t\xf9 IPK          : ");
                    scanf("%f", &user.ipk);
                    if (user.semester > 3 && user.semester <= 14){
                        printf("\t\xf9 Konsentrasi  : ");
                        scanf(" %[^\n]s", &user.konsentrasi);
                    }
                }
        } while (user.semester <= 0 || user.semester > 14);

        printf("\t\xf9 Tahun Ajaran : ");
        scanf("%d", &user.tahun_ajaran);
        Sleep(500);
        printf("\t");
        for (garis=0;garis<28;garis++){
            printf("\xc4");
        }
        mencetak_ketentuan_sks(user);
    } while ((user.ipk <= 0 || user.ipk > 4) && (user.semester != 1 || user.semester != 2));

    Sleep(1000);
    system("cls");
    Sleep(750);

    /* MEMILIH MATA KULIAH */
    if (user.semester >= 3 && user.semester <= 14){
        memilih_matakuliah(user);
        getch();
    }

    mencetak_data_diri(user, nim, name);
    mencetak_header_krs(garis);
    fflush(stdin);

    if (user.semester==1){
        printf("\n  \xb3 01 \xb3  TI031201  \xb3 AGAMA\t\t\t\t\xb3  2  \xb3\n");
        printf("  \xb3 02 \xb3  TI031202  \xb3 Bahasa Indonesia\t\t\t\xb3  2  \xb3\n");
        printf("  \xb3 03 \xb3  TI031203  \xb3 Bahasa Inggris\t\t\t\xb3  2  \xb3\n");
        printf("  \xb3 04 \xb3  TI031204  \xb3 Algoritma\t\t\t\t\xb3  2  \xb3\n");
        printf("  \xb3 05 \xb3  TI031305  \xb3 Pemprograman\t\t\t\xb3  3  \xb3\n");
        printf("  \xb3 06 \xb3  TI031306  \xb3 Pengantar Sistem TI\t\t\xb3  3  \xb3\n");
        printf("  \xb3 07 \xb3  TI031307  \xb3 Konsep Basis Data\t\t\t\xb3  3  \xb3\n");
        printf("  \xb3 08 \xb3  TI031308  \xb3 Aplikasi Sosial Media\t\t\xb3  3  \xb3\n");
        printf("  \xc3");
        for (garis=0;garis<59;garis++){
            printf("\xc4");
        }
        printf("\xb4");
        printf("\n  \xb3\t\tTOTAL \t\t\t\t\t\xb3  20 \xb3");
        printf("\n  \xc0");
        for (garis=0;garis<59;garis++){
            printf("\xc4");
        }
        printf("\xd9");

    } else if (user.semester==2){
        printf("\n  \xb3 01 \xb3  TI032209  \xb3 Manajemen Stress\t\t\t\xb3  2  \xb3\n");
        printf("  \xb3 02 \xb3  TI032210  \xb3 Kewarganegaraan\t\t\t\xb3  2  \xb3\n");
        printf("  \xb3 03 \xb3  TI032211  \xb3 Arsitektur STI\t\t\t\xb3  3  \xb3\n");
        printf("  \xb3 04 \xb3  TI032312  \xb3 Jaringan Komputer & Komunikasi\t\xb3  3  \xb3\n");
        printf("  \xb3 05 \xb3  TI032313  \xb3 Teknologi Basis Data\t\t\xb3  3  \xb3\n");
        printf("  \xb3 06 \xb3  TI032314  \xb3 Pemprograman Berorientasi Obyek\t\xb3  3  \xb3\n");
        printf("  \xb3 07 \xb3  TI032315  \xb3 Sistem Informasi Manajemen\t\xb3  3  \xb3\n");
        printf("  \xb3 08 \xb3  TI032316  \xb3 Praktikum Basis Data\t\t\xb3  1  \xb3\n");
        printf("  \xb3 09 \xb3  TI032317  \xb3 Praktikum Algoritma Pemprograman  \xb3  1  \xb3\n");
        printf("  \xc3");
        for (garis=0;garis<59;garis++){
            printf("\xc4");
        }
        printf("\xb4");
        printf("\n  \xb3\t\tTOTAL \t\t\t\t\t\xb3  20 \xb3");
        printf("\n  \xc0");
        for (garis=0;garis<59;garis++){
            printf("\xc4");
        }
        printf("\xd9");

    } else if (user.semester==3){
        while (no_matkul!=0){
            scanf("%d", &no_matkul);
            count++;
            switch (no_matkul){
                case 1:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI033318  \xb3 Interpersonal dan Life Skill\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 2:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI033219  \xb3 Imaging System\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 3:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI033320  \xb3 Interaksi Manusia Komputer\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 4:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI033321  \xb3 Rekayasa Perangkat Lunak\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 5:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI033222  \xb3 Pengantar Manajemen Bisnis\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 6:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI033323  \xb3 Pemprograman Internet\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 7:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI033224  \xb3 Technopreneurship\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 8:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI033125  \xb3 Praktikum Teknologi Basis Data\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 9:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI033126  \xb3 Praktikum Jaringan Komputer       \xb3  %d  \xb3\n",count,sks);
                    break;
                case 10:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI031201  \xb3 Agama\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 11:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI031202  \xb3 Bahasa Indonesia\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 12:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI031203  \xb3 Bahasa Inggris\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 13:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI031204  \xb3 Algoritma\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 14:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI031305  \xb3 Pemprograman\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 15:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI031306  \xb3 Pengantar Sistem TI\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 16:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI031307  \xb3 Konsep Basis Data \t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 17:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI031308  \xb3 Aplikasi Sosial Media\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 18:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI032209  \xb3 Manajemen Stress\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 19:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI032210  \xb3 Kewarganegaraan\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 20:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI032211  \xb3 Arsitektur STI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 21:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI032312  \xb3 Jaringan Komputer dan Komunikasi  \xb3  %d  \xb3\n",count,sks);
                    break;
                case 22:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI032313  \xb3 Teknologi Basis Data\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 23:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI032314  \xb3 Pemprograman Berorientasi Obyek\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 24:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI032315  \xb3 Sistem Informasi Manajemen\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 25:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI032315  \xb3 Praktikum Basis Data\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 26:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI032317  \xb3 Praktikum Algoritma Pemprograman\t\xb3  %d  \xb3\n",count,sks);
                break;
                default:
                    sks=0;
                    break;
            }
            total_sks+=sks;
        }
        mencetak_footer_krs(garis,total_sks);

    } else if (strcmp(user.konsentrasi,"Manajemen Keamanan Jaringan")==0 || strcmp(user.konsentrasi,"MKJ")==0){
        while (no_matkul!=0){
            scanf("%d", &no_matkul);
            count++;
            switch (no_matkul){
                case 1:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034327  \xb3 Analisis dan Desain Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 2:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI034238  \xb3 Isu dan Prinsip Proteksi TI\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 3:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034339  \xb3 Pemprograman Mobile\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 4:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034340  \xb3 Dasar Sistem Cerdas\t\t\xb3  %d  \xb3\n", count,sks);
                    break;
                case 5:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI034141  \xb3 Praktikum Pemprograman Internet\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 6:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039308  \xb3 Manajemen Jaringan dan Server\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 7:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039309  \xb3 Network Operating System\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 8:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039110  \xb3 Prak. Manaj. Jaringan dan Server  \xb3  %d  \xb3\n",count,sks);
                    break;
                case 9:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI035342  \xb3 IT Forensic\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 10:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035143  \xb3 Seminar TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 11:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035144  \xb3 Praktikum Pemprograman Mobile\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 12:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039303  \xb3 Multi Channel Access\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 13:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039302  \xb3 Pemprograman Jaringan (Socket)\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 14:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039304  \xb3 Internet of Things\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 15:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039311  \xb3 Manaj. & Implementasi Proteksi TI \xb3  %d  \xb3\n",count,sks);
                    break;
                case 16:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039312  \xb3 Jaringan Nirkabel\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 17:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036245  \xb3 Statistik dan Riset TI\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 18:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036346  \xb3 Grid and Cloud Computing\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 19:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036247  \xb3 Kerja Praktek\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 20:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036348  \xb3 Topik Khusus TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 21:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039313  \xb3 Manajemen Resiko Keamanan    \t\xb3     \xb3\n  \xb3    \xb3\t    \xb3 dan Penanganan Bencana\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 22:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039314  \xb3 Network Centric Principles\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 23:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039315  \xb3 Praktikum Jaringan Nirkabel\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 24:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037249  \xb3 Etika Profesi dan Pendidikan Anti \xb3     \xb3\n  \xb3    \xb3\t    \xb3 Korupsi\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 25:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037250  \xb3 Pancasila\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 26:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI037351  \xb3 Project Tugas Pra Akhir\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 27:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI037152  \xb3 Pra Pendadaran\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 28:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI038353  \xb3 KKN\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 29:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI038154  \xb3 Penulisan Ilmiah\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 30:
                    sks=4;
                    printf("  \xb3 %02d \xb3  TI038455  \xb3 Tugas Akhir\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 31:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039316  \xb3 System Administration\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 32:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039332  \xb3 Audit TI\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 33:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039344  \xb3 Teknologi Big Data\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 34:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039348  \xb3 Wireless Sensor Network\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 35:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039349  \xb3 IT Forensic Lanjut\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 36:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039350  \xb3 Perancangan Keamanan Aplikasi dan \xb3     \xb3\n  \xb3    \xb3\t    \xb3 Jaringan\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 37:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039361  \xb3 Sertifikasi\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                default:
                    sks=0;
                    break;
            }
            total_sks+=sks;
        }
        mencetak_footer_krs(garis,total_sks);

    } else if (strcmp(user.konsentrasi,"Teknologi Cerdas")==0 || strcmp(user.konsentrasi,"TC")==0){
        while (no_matkul!=0){
            scanf("%d", &no_matkul);
            count++;
            switch (no_matkul){
                case 1:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034327  \xb3 Analisis dan Desain Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 2:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI034238  \xb3 Isu dan Prinsip Proteksi TI\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 3:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034339  \xb3 Pemprograman mobile\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 4:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034340  \xb3 Dasar Sistem Cerdas\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 5:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI034141  \xb3 Praktikum Pemprograman Internet\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 6:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039304  \xb3 Internet Of Things\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 7:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039317  \xb3 Pengolahan Citra Digital\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 8:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039118  \xb3 Praktikum Pengolahan Citra Digital\xb3  %d  \xb3\n",count,sks);
                    break;
                case 9:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI035342  \xb3 IT Forensic\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 10:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035143  \xb3 Seminar TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 11:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035144  \xb3 Praktikum Pemprograman Mobile\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 12:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039305  \xb3 Data Warehouse\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 13:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039319  \xb3 Computer Vision\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 14:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039320  \xb3 Aplikasi Berbasis Sensor & Device \xb3  %d  \xb3\n",count,sks);
                    break;
                case 15:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039321  \xb3 Soft Computing\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 16:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039322  \xb3 Sistem Temu Kembali\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 17:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036245  \xb3 Statistik & Riset Tekno. Informasi\xb3  %d  \xb3\n",count,sks);
                    break;
                case 18:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036346  \xb3 Grid dan Cloud Computing\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 19:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036247  \xb3 Kerja Praktek\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 20:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036348  \xb3 Topik Khusus TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 21:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039306  \xb3 Data Mining\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 22:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039326  \xb3 Pengenalan Pola Cerdas\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 23:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039127  \xb3 Praktikum Pengenalan Pola Cerdas  \xb3  %d  \xb3\n",count,sks);
                    break;
                case 24:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037249  \xb3 Etika Profesi dan Pendidikan Anti \xb3     \xb3\n  \xb3    \xb3\t    \xb3 Korupsi\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 25:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037250  \xb3 Pancasila\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 26:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI037351  \xb3 Project Tugas Pra Akhir\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 27:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI037152  \xb3 Pra Pendadaran\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 28:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI038353  \xb3 KKN\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 29:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI038154  \xb3 Penulisan Ilmiah\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 30:
                    sks=4;
                    printf("  \xb3 %02d \xb3  TI038455  \xb3 Tugas Akhir\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 31:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039323  \xb3 Aplikasi Sistem Cerdas\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 32:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039324  \xb3 Natural Language\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 33:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039330  \xb3 Penginderaan Jauh\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 34:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039344  \xb3 Teknologi Big Data\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 35:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039351  \xb3 Pengaman Berbasis Biometrika\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 36:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039352  \xb3 Data Visualization\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 37:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039353  \xb3 Pemprograman Game Mobile\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 38:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039354  \xb3 Aplikasi Robotika\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 39:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039361  \xb3 Sertifikasi\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                default:
                    sks=0;
                    break;
            }
            total_sks+=sks;
        }
        mencetak_footer_krs(garis,total_sks);

    } else if (strcmp(user.konsentrasi,"Manajemen Bisnis")==0 || strcmp(user.konsentrasi,"MB")==0){
        while (no_matkul!=0){
            scanf("%d", &no_matkul);
            count++;
            switch (no_matkul){
                case 1:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034327  \xb3 Analisis dan Desain Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 2:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034339  \xb3 Pemprograman mobile\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 3:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034340  \xb3 Dasar Sistem Cerdas\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 4:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI034141  \xb3 Praktikum Pemprograman Internet\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 5:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039301  \xb3 Integrasi dan Migrasi Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 6:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039129  \xb3 Praktikum Integrasi Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 7:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039346  \xb3 Desain dan Perilaku Organisasi\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 8:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039347  \xb3 Sistem Informasi Keuangan\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 9:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI035342  \xb3 IT Forensic\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 10:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035143  \xb3 Seminar TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 11:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035144  \xb3 Praktikum Pemprograman Mobile\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 12:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039336  \xb3 Supply Chain Management\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 13:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039337  \xb3 Analisis Kelayakan Bisnis\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 14:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039338  \xb3 Customer Relationship Management  \xb3  %d  \xb3\n",count,sks);
                    break;
                case 15:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039339  \xb3 Enterprise Resource Planning\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 16:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039345  \xb3 Managemen Support System\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 17:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036245  \xb3 Statistik & Riset Tekno. Informasi\xb3  %d  \xb3\n",count,sks);
                    break;
                case 18:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036247  \xb3 Kerja Praktek\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 19:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036348  \xb3 Topik Khusus TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 20:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039340  \xb3 Project Technopreneurship\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 21:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039341  \xb3 Inovasi dan Manajemen Produk\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 22:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039342  \xb3 Internet Marketing\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 23:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037249  \xb3 Etika Profesi dan Pendidikan Anti \xb3     \xb3\n  \xb3    \xb3\t    \xb3 Korupsi\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 24:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037250  \xb3 Pancasila\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 25:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI037351  \xb3 Project Tugas Pra Akhir\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 26:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI037152  \xb3 Pra Pendadaran\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 27:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI038353  \xb3 KKN\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 28:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI038154  \xb3 Penulisan Ilmiah\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 29:
                    sks=4;
                    printf("  \xb3 %02d \xb3  TI038455  \xb3 Tugas Akhir\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 30:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039306  \xb3 Data Mining\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 31:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039335  \xb3 Aplikasi Bisnis\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 32:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039344  \xb3 Teknologi Big Data\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 33:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039355  \xb3 Korporasi Maya\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 34:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039358  \xb3 Manajemen Perubahan\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 35:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039359  \xb3 Perilaku Konsumen\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 36:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039360  \xb3 Pengembangan Start Up\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 37:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039361  \xb3 Sertifikasi\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                default:
                    sks=0;
                    break;
            }
            total_sks+=sks;
        }
        mencetak_footer_krs(garis,total_sks);

    } else if (strcmp(user.konsentrasi,"Manajemen Data dan Informasi")==0 || strcmp(user.konsentrasi,"MDI")==0){
        while (no_matkul!=0){
            scanf("%d", &no_matkul);
            count++;
            switch (no_matkul){
                case 1:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034327  \xb3 Analisis dan Desain Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 2:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI034238  \xb3 Isu dan Prinsip Proteksi TI\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 3:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034339  \xb3 Pemprograman Mobile\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 4:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI034340  \xb3 Dasar Sistem Cerdas\t\t\xb3  %d  \xb3\n", count,sks);
                    break;
                case 5:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI034141  \xb3 Praktikum Pemprograman Internet\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 6:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039301  \xb3 Integrasi dan Migrasi Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 7:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039328  \xb3 IT Service Manajemen\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 8:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039129  \xb3 Praktikum Integrasi Sistem\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 9:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI035342  \xb3 IT Forensic\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 10:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035143  \xb3 Seminar TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 11:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI035144  \xb3 Praktikum Pemprograman Mobile\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 12:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039304  \xb3 Internet of Things\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 13:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039305  \xb3 Data Warehouse\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 14:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039330  \xb3 Penginderaan Jauh\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 15:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039331  \xb3 Pemprograman Mobile Lanjut\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 16:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039345  \xb3 Managemen Support System\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 17:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036245  \xb3 Statistik & Riset Tekno. Informasi\xb3  %d  \xb3\n",count,sks);
                    break;
                case 18:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036346  \xb3 Grid and Cloud Computing\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 19:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI036247  \xb3 Kerja Praktek\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 20:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI036348  \xb3 Topik Khusus TI\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 21:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039306  \xb3 Data Mining\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 22:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039332  \xb3 Audit TI\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 23:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI039134  \xb3 Praktikum Data Warehouse\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 24:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037249  \xb3 Etika Profesi dan Pendidikan Anti \xb3     \xb3\n  \xb3    \xb3\t    \xb3 Korupsi\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 25:
                    sks=2;
                    printf("  \xb3 %02d \xb3  TI037250  \xb3 Pancasila\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 26:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI037351  \xb3 Project Tugas Pra Akhir\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 27:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI037152  \xb3 Pra Pendadaran\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 28:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI038353  \xb3 KKN\t\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 29:
                    sks=1;
                    printf("  \xb3 %02d \xb3  TI038154  \xb3 Penulisan Ilmiah\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 30:
                    sks=4;
                    printf("  \xb3 %02d \xb3  TI038455  \xb3 Tugas Akhir\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 31:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039303  \xb3 Multi Channel Access\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 32:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039339  \xb3 Enterprise Resource Planning\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 33:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039355  \xb3 Korporasi Maya\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 34:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039356  \xb3 Manajemen Sains\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 35:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039357  \xb3 Sistem Informasi Geografis Web\t\xb3     \xb3\n  \xb3    \xb3\t    \xb3 dan Mobile\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                case 36:
                    sks=3;
                    printf("  \xb3 %02d \xb3  TI039361  \xb3 Sertifikasi\t\t\t\xb3  %d  \xb3\n",count,sks);
                    break;
                default:
                    sks=0;
                    break;
            }
            total_sks+=sks;
        }
        mencetak_footer_krs(garis,total_sks);
    }

    /* MENCHECK KEABSAHAN KRS */
    mengecek_krs(user,total_sks);
    printf("\n\n\n\n\n");
    getch();
    return 0;
}
