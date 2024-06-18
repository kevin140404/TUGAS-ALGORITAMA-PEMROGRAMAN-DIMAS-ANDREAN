#include <stdio.h>

void ceksaldo(float dana) {
    printf("Saldo Anda: Rp. %.2f\n", dana);
    printf("Tekan 0 untuk kembali ke menu transaksi: ");
    int back;
    while (1) {
        scanf("%d", &back);
        if(back == 0){
            return;
        }else{
        	printf("Saldo Anda: Rp. %.2f\n", dana);
        	printf("Kode salah. Tekan 0 untuk kembali: ");
        }
    }
}
float setor(float dana){
    float setor;
    printf("Masukkan jumlah setor tunai: ");
    scanf("%f", &setor);
    dana += setor;
    printf("Setor tunai Anda berhasil\nSaldo Anda: Rp %.2f\n", dana);
    printf("Tekan 0 untuk kembali ke menu transaksi: ");
    int back;
    while(1){
        scanf("%d", &back);
        if (back == 0) {
            return dana;
        }else{
        	printf("Saldo Anda: Rp %.2f\n", dana);
            printf("Kode salah. Tekan 0 untuk kembali: ");
        }
    }
}
float tarik(float dana){
    float tarik;
    printf("Masukkan jumlah tarik tunai: ");
    scanf("%f", &tarik);
    if(tarik <= dana){
        dana -= tarik;
        printf("Tarik tunai Anda berhasil\nSaldo Anda: Rp %.2f\n", dana);
    }else{
        printf("Saldo Anda Tidak Cukup\n");
    }
    printf("Tekan 0 untuk kembali ke menu transaksi: ");
    int back;
    while(1){
        scanf("%d", &back);
        if (back == 0){
            return dana;
        }else{
        	printf("Saldo Anda: Rp %.2f\n", dana);
            printf("Kode salah. Tekan 0 untuk kembali: ");
        }
    }
}
void transaksi(float *dana){
    int kode;
    do{
        printf("\n1. Cek Saldo\n");
        printf("2. Setor Tunai\n");
        printf("3. Tarik Tunai\n");
        printf("4. Keluar\n");
        printf("Kode: ");
        
        while(scanf("%d", &kode) != 1 || kode < 1 || kode > 4) {
        	printf("1. Cek Saldo\n");
        	printf("2. Setor Tunai\n");
        	printf("3. Tarik Tunai\n");
        	printf("4. Keluar\n");
            printf("Kode tidak tersedia");
            printf("Kode: ");
            while (getchar() != '\n');
        }
        switch (kode){
            case 1:
                ceksaldo(*dana);
                break;
            case 2:
                *dana = setor(*dana);
                break;
            case 3:
                *dana = tarik(*dana);
                break;
            case 4:
                printf("##### Terima kasih #####\n");
                break;
            default:
                printf("Kode tidak tersedia\n");
        }
    }while(kode != 4);
}
int main(){
    int pass1 = 230623;
    int pass2;
    int count = 0;
    float dana = 0.0;
    printf("########## BANK BNI ##########\n");
    printf("PIN: ");
    scanf("%i", &pass2);
    if(pass2 == pass1){
        transaksi(&dana);
    }else{
        while(count < 2){
            printf("PIN Anda salah\n");
            printf("PIN: ");
            scanf("%i", &pass2);
            if(pass2 == pass1){
                transaksi(&dana);
                return 0;
            }
            count++;
        }
        printf("Akun Anda Diblokir\n");
    }
    return 0;
}

