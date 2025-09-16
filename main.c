#include <stdio.h>
#include <stdlib.h>
// menambahkan library


const char* index_nilai(int nilai) {
// menambahkan tipe data integer pada nilai
    if (nilai >= 86) {
        return "A";
    } 
    else if (nilai >= 76) {
        return "AB";
    } 
    else if (nilai >= 66) {
        return "B";
    } 
    else if (nilai >= 61) {
        return "BC";
    } 
    else if (nilai >= 56) {
        return "C";
    } 
    else if (nilai >= 41) {
        return "D";
    } 
    else {
        return "E";
    }
}


float kalkulasi_ip(float *matkul, int *sks, int n) { // melengkapi tipe data *matkul

    int totalSKS = 0;
    float totalNilai = 0.0;
// mendeklarasikan variabel totalSKS dan totalNilai

    for (int i = 0; i < n; i++) {
        totalNilai += matkul[i] * sks[i];  
        totalSKS += sks[i];
    }

    return totalNilai / totalSKS; 
}



int main(){
    char nama[20];
    int umur;
    long long NRP;
// mendeklarasikan variabel umur dan NRP

    printf("ingfo nama: ");
    fgets(nama, sizeof(nama), stdin);

    printf("P Umur: ");
    scanf("%d" , &umur);

    printf("NRP dong biar tau: ");
    scanf("%lld" , &NRP); //mengubah pembacaan integer menjadi long 

    int n;
    printf("Jumlah matkul Semester ini berapa: ");
    scanf("%d", &n);

    float *matkul = malloc(n * sizeof(int)); 
    int *sks = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Masukkan nilai matkul %d tersebut \n" , i + 1);
        scanf("%f", &matkul[i]);
        printf("Masukkan SKS matkul %d tersebut \n" , i + 1);
        scanf("%d" , &sks[i]);
        if((matkul[i] < 0) && (sks[i] < 0)){
            printf("Nilai matkul dan sks tidak boleh negatif. Menghentikan input.\n");
            free(matkul);
            free(sks);
            return 0;
        }
    }


    printf("\nNama: %s", nama);
    printf("Umur: %d \n", umur);
    printf("NRP: %lld \n" , NRP); //mengubah pembacaan integer menjadi long

    for(int j = 0; j < n ; j++){
        printf("Indeks nilai matkul %d: %s\n", j + 1, index_nilai(matkul[j]));
    }
    float ip = kalkulasi_ip(matkul, sks, n);
    printf("Indeks Prestasi (IP): %.2f (%s)\n", ip , index_nilai(ip));


    free(matkul); 
    free(sks);
    system("pause"); //menmbahkan stop agar program tidak close
    return 0;
}