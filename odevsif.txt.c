#include <stdio.h>

// �ifreleme fonksiyonu
void sifrele(char metin[], int anahtar) {
    int i;
    for (i = 0; metin[i] != '\0'; i++) {
// K���k harf ise
        if (metin[i] >= 'a' && metin[i] <= 'z') {
        	
        	
// Harfi �ifrelerken ASCII de�erinden a ��kart�l�p anahtar degeri eklenir. 
//  26y a b�l�n�p mod al�n�r ve en son olarak a eklenir.
            metin[i] = ((metin[i] - 'a' + anahtar) % 26) + 'a';
            
            
// B�y�k harf ise
        } else if (metin[i] >= 'A' && metin[i] <= 'Z') {
        	
        	
// Harfi �ifrelerken ASCII de�erinden A ��kart�l�p anahtar degeri eklenir. 
// 26 ya b�l�n�p mod al�n�r ve en sonvA eklenir.
            metin[i] = ((metin[i] - 'A' + anahtar) % 26) + 'A';
        }
    }
}

// �ifre ��zme fonksiyonu
void sifreCoz(char metin[], int anahtar) {
    int i;
    for (i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
        	
        	
// Harfi �ifrelerken ASCII de�erinden a ��kart�l�p anahtar degeri ��kart�l�r. 
//  26ya b�l�n�p mod al�n�r ve en son olarak a eklenir.
            metin[i] = ((metin[i] - 'a' - anahtar + 26) % 26) + 'a';
        } else if (metin[i] >= 'A' && metin[i] <= 'Z') {
        	       	
// Harfi �ifrelerken ASCII de�erinden A ��kart�l�p anahtar degeri ��kart�l�r. 
// 26 ya b�l�n�p mod al�n�r ve en son A eklenir.
            metin[i] = ((metin[i] - 'A' - anahtar + 26) % 26) + 'A';
        }
    }
}

int main() {
    FILE *dosya1;
    FILE *dosya2;
    char metin[100];
    int anahtar;


//fopen fonksiyonu ile �ifrelenecek metin dosyas� a��l�r. 
//E�er dosya a��lamazsa, bir hata mesaj� verilir ve program sonland�r�l�r.
    dosya1 = fopen("C:\\Users\\�rem\\Desktop\\sifrelemeodev2\\uyg.txt.txt", "r");

// Dosyan�n var olup olmad���n� kontrol et
    if (dosya1 == NULL) {
        printf("Dosya acilamadi veya bulunamadi.\n");
        return 1;
    }

//�ifrelenmi� metinlerin yaz�laca�� dosya olu�turulur
// w  modu dosyay� yazma modunda a�ar.
   dosya2 = fopen("sifreli_metinler.txt", "w");

    // Kullan�c�dan �ifreleme anahtar�n� iste
    printf("Anahtar degerini giriniz: ");
    scanf("%d", &anahtar);

// Dosyadan metni oku,�ifrele,�ifreli metni ayn� dosyaya yaz ve �ifreyi ��z
//Bu d�ng� dosyadan bir sat�r okuyup, bu sat�r� �ifreleyip ��zen i�lemleri ger�ekle�tirir.
    while (fscanf(dosya1, " %[^\n]s", metin) != EOF) {
        sifrele(metin, anahtar);

// �ifrelenmi� metni ekrana ve farkl� bir dosyaya yazd�r
        printf("Sifrelenmis Metin: %s\n", metin);
        fprintf(dosya2, "%s\n", metin);

// �ifre ��z ve ekrana yazd�r
        sifreCoz(metin, anahtar);
        printf("Cozulmus Metin: %s\n", metin);
    }

// Dosyalar� kapat
    fclose(dosya1);
    fclose(dosya2);

    return 0;
}

