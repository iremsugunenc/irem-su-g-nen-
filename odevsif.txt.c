#include <stdio.h>

// Þifreleme fonksiyonu
void sifrele(char metin[], int anahtar) {
    int i;
    for (i = 0; metin[i] != '\0'; i++) {
// Küçük harf ise
        if (metin[i] >= 'a' && metin[i] <= 'z') {
        	
        	
// Harfi þifrelerken ASCII deðerinden a çýkartýlýp anahtar degeri eklenir. 
//  26y a bölünüp mod alýnýr ve en son olarak a eklenir.
            metin[i] = ((metin[i] - 'a' + anahtar) % 26) + 'a';
            
            
// Büyük harf ise
        } else if (metin[i] >= 'A' && metin[i] <= 'Z') {
        	
        	
// Harfi þifrelerken ASCII deðerinden A çýkartýlýp anahtar degeri eklenir. 
// 26 ya bölünüp mod alýnýr ve en sonvA eklenir.
            metin[i] = ((metin[i] - 'A' + anahtar) % 26) + 'A';
        }
    }
}

// Þifre çözme fonksiyonu
void sifreCoz(char metin[], int anahtar) {
    int i;
    for (i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
        	
        	
// Harfi þifrelerken ASCII deðerinden a çýkartýlýp anahtar degeri çýkartýlýr. 
//  26ya bölünüp mod alýnýr ve en son olarak a eklenir.
            metin[i] = ((metin[i] - 'a' - anahtar + 26) % 26) + 'a';
        } else if (metin[i] >= 'A' && metin[i] <= 'Z') {
        	       	
// Harfi þifrelerken ASCII deðerinden A çýkartýlýp anahtar degeri çýkartýlýr. 
// 26 ya bölünüp mod alýnýr ve en son A eklenir.
            metin[i] = ((metin[i] - 'A' - anahtar + 26) % 26) + 'A';
        }
    }
}

int main() {
    FILE *dosya1;
    FILE *dosya2;
    char metin[100];
    int anahtar;


//fopen fonksiyonu ile þifrelenecek metin dosyasý açýlýr. 
//Eðer dosya açýlamazsa, bir hata mesajý verilir ve program sonlandýrýlýr.
    dosya1 = fopen("C:\\Users\\Ýrem\\Desktop\\sifrelemeodev2\\uyg.txt.txt", "r");

// Dosyanýn var olup olmadýðýný kontrol et
    if (dosya1 == NULL) {
        printf("Dosya acilamadi veya bulunamadi.\n");
        return 1;
    }

//Þifrelenmiþ metinlerin yazýlacaðý dosya oluþturulur
// w  modu dosyayý yazma modunda açar.
   dosya2 = fopen("sifreli_metinler.txt", "w");

    // Kullanýcýdan þifreleme anahtarýný iste
    printf("Anahtar degerini giriniz: ");
    scanf("%d", &anahtar);

// Dosyadan metni oku,þifrele,þifreli metni ayný dosyaya yaz ve þifreyi çöz
//Bu döngü dosyadan bir satýr okuyup, bu satýrý þifreleyip çözen iþlemleri gerçekleþtirir.
    while (fscanf(dosya1, " %[^\n]s", metin) != EOF) {
        sifrele(metin, anahtar);

// Þifrelenmiþ metni ekrana ve farklý bir dosyaya yazdýr
        printf("Sifrelenmis Metin: %s\n", metin);
        fprintf(dosya2, "%s\n", metin);

// Þifre çöz ve ekrana yazdýr
        sifreCoz(metin, anahtar);
        printf("Cozulmus Metin: %s\n", metin);
    }

// Dosyalarý kapat
    fclose(dosya1);
    fclose(dosya2);

    return 0;
}

