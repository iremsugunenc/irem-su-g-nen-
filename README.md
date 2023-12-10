# iremsugunenc
## Sifreleme ve Şifre Çözme Programı
Bu program, txt dosyasını okuyarak dosyadaki metni belirtilen bir anahtar değeri kullanarak şifreler ve aynı anahtar değeri kullanarak şifreyi çözer. Program, küçük harf ve büyük harf ayrımı yapar ve şifreleme işlemlerini gerçekleştirir. Ayrıca, şifrelenmiş metinleri bir dosyaya yazarak kaydeder ve şifreyi çözüp ekrana yazdırır.
## Kullanım
Karakter küçük harfse, şifreleme işlemi bu blokta gerçekleşir.Değilse büyük harf kontrolü yapılır.
Küçük harfin ASCII değeri a  çıkartılarak  bir indekse dönüştürülür. Şifreleme anahtarı eklenir ve mod 26 alınır (26 karakter olduğu için). Son olarak, a eklenerek tekrar ASCII değerine dönüştürülür ve metin[i] karakterine atanır.
Büyük harfin ASCII değeri A  çıkartılarak bir indekse dönüştürülür. Şifreleme anahtarı eklenir ve mod 26 alınır. Son olarak, A eklenerek tekrar ASCII değerine dönüştürülür ve metin[i] karakterine atanır.
dosya1 ve dosya2 adlı iki dosya sırasıyla şifrelenecek metin dosyasını ve şifrelenmiş metinlerin yazılacağı dosyayı temsil eder. metin adlı dizi, dosyadan okunan veya dosyaya yazılacak metni tutar. anahtar ise kullanıcıdan alınan şifreleme anahtarını içerir.
fopen fonksiyonu kullanılarak şifrelenecek metin dosyasını okumak üzere açar. "C:\Users\İrem\Desktop\sifrelemeodev2\uyg.txt.txt" dizinindeki "uyg.txt.txt" adlı dosya, "r" (read) modunda açılır. Eğer dosya açılamazsa, program hata mesajı verir ve return 1; ile program sonlandırılır.
Yeni bir dosya oluşturulur. "sifreli_metinler.txt" adlı dosya, "w" (write) modunda açılır. dosya1 dosyasından satır satır veri okur. fscanf fonksiyonu, belirtilen formata göre dosyadan veri okur.
Okunan metin, sifrele fonksiyonu ile şifrelenir.
Şifrelenmiş metin, ekrana yazdırılır ve dosya2 dosyasına yazılır.
Son olarak, fclose fonksiyonu ile açılan dosyalar kapatılır.
