# Proje Başlığı

Gerçek Zamanlı Haberleşme İçin IEEE TSN 802.1Qbu Frame Preemption Protokolünün OMNeT++’da Simülasyonu

----------------------------------------------------------------------------------------------
## Açıklama

Bu çalışmada IEEE 802.1 Time Sensitive Network’un (TSN) bir protokolü olan 802.1Qbu Frame Preemption’ın ve IEEE 802.3 Standard Ethernet’in 
bir protokolü olan 802.3Br Interspersing Express Traffic'in çalışma ilkeleri üzerine kurulu modelin OMNeT++’da simülasyonu gerçeklenmektedir.

----------------------------------------------------------------------------------------------
### Gereksinimler

İşletim Sistemi için:

• Windows 7 and 10 / 64-bit
• MacOS 10.12
• Ubuntu 16.04 LTS

OMNeT++ için:

• OMNeT++ 5.5.1 ve yukarısı

----------------------------------------------------------------------------------------------

#### Kurulum Ve Başlangıç Ayarları

**** Windows için ****

• Yükleme Önkoşulu:

- Java 5.0 ve daha yukarısı

• OMNeT++ Yükleme:

- https://omnetpp.org/download/

•  OMNeT ++ Yapılandırma ve Oluşturma:

- Windows Gezgini'nde çift tıklatarak omnetPP dizinindeki mingwenv.cmd dosyasını başlatın.Ardından sırayla aşağıdaki komutları girin:

$ ./configure
$ make

• Yüklemeyi Doğrulama:

- Proje omnetpp samples klasörüne kopyalandıktan sonra:

$ cd samples/TSN8021QBU  
$ ./TSN8021QBU

- Yüklemeyi Doğrulama aşamasına alternatif olarak proje OMNeT++ programına girdikten sonra:

File --> Existing Projects into Workspace(next denilir)---> Browse(proje yolu seçilir) --> Finish

• IDE'yi başlatma:

$ omnetpp

---------------------------------------------------------------------------------------------------------
**** Linux için ****

• OMNeT++ Yükleme:

https://omnetpp.org/download/

• Sıkıştırılmış dosyayı açma

tar xvfz omnetpp-5.6.1-src.tgz

• Ortam Değişkenleri

- OMNeT ++ ' da  bin / dizinine gittikden sonra:

$ cd omnetpp-5.6.1
$ . setenv

• OMNeT ++ Yapılandırma ve Oluşturma:

- OMNeT ++ dizinine girdikten sonra aşağıdaki komuları sırayla yazın:

$ ./configure
$ make

• Yüklemeyi Doğrulama:

- Proje omnetpp samples klasörüne kopyalandıktan sonra:

$ cd samples/TSN8021QBU veya doğrudan projeyi import ederek
$ ./TSN8021QBU

- Yüklemeyi Doğrulama aşamasına alternatif olarak proje OMNeT++ programına girdikten sonra:

File --> Existing Projects into Workspace(next denilir)---> Browse(proje yolu seçilir) --> Finish

• IDE'yi başlatma:

$ omnetpp

----------------------------------------------------------------------------------------------
##### Versiyon

- OMNeT++ 5.5.1
----------------------------------------------------------------------------------------------

###### Projenin Çalıştırılması

Kurulum aşamaları başarılı bir şekilde tamamlandıktan ve proje yukarıda anlatıldığı gibi açıldıktan sonra:

• TSN8021QBU klasörü açıldıktan sonra network.ned dosyası açılır.(TSN8021QBU klasörü içindeki herhangi bir .cc dosyası ile de açılabilir).

• Editör alanında veya Proje Gezgini'nde "Run(Çalıştır)" düğmesine basarak simülasyonu başlatabilirsiniz. Veya kısa yol şeklinde "Ctrl + B" 'ye basarak da simülasyonu başlatabilirsiniz.

• Ardından proje çalışmaya başlamadan hemen önce küçük bir pencerede periyot değerlerinin girilmesi beklenir:

- Burada "Enter parameter  'Network.workstation.uretimPeriyodu': " kısımına sayısal(doğal sayı) bir değer girerek "workstation" 'ın paket üretim periyodunu,

- "Enter parameter  'Network.ExpressGenerator.uretimPeriyodu': " kısımına sayısal(doğal sayı) değer girerek "ExpressGenerator" ' nın üretim periyodunu belirlemek zorundasınız.

• Ana pencere araç çubuğu geçerli simülasyon zamanını görüntüler. Bu programın yürütülmesi için gereken sanal bir zamandır. Gerçek zamanla ilgisi yoktur. 

• Grafik penceresinin üst kısmındaki kaydırıcıyla animasyonu yavaşlatarak veya daha hızlı hale getirerek oynayabilirsiniz.

• Simülasyonu araç çubuğundan "stop(durdur)"'a basarak veya klavyeden  F8'e basarak durdurabilirsiniz. Devam etmek için araç çubuğundan "run(çalıştır)" tuşuna veya klavyeden F5 tuşuna tekrar basmanız yeterlidir.

• Simülasyonda içinde bulunulan ağ ya da model ile ilgili bilgilerin tümü solda bulunan "bilgilendirme penceresinde" gösterilmektedir.

• Simülasyon sırasında gerçekleşen bir takım olaylar "Console" penceresi kısmında yazdırılmaktadır.(Örneğin atılan paketler)

• Simülasyon için açılmış olan pencerenin, sağ üst kısmındaki çarpıya tıklanarak simülasyon ekranından çıkılabilir veya kısayol olarak klavyeden "ALT+F4" yapılarak simülasyon ekranından çıkılabilir.

----------------------------------------------------------------------------------------------
####### İpucu

• Açılan herhangi bir .ned dosyasının altında bulunan "source" kısmına tıklanarak ağ ya da modüllerin kaynak kodu incelenebilir ve değiştirilebilir.

• Simülasyon esnasında "Network" içerisinde bulunan modüllere çift tıklayarak modül iç yapısını inceleyebiliriz.

• Eğer proje derlendiğinde  " Define_Module(Xmodule) " tanımlamalarının birinde hata ile karşılaşılırsa "Makefile." dosyasını silip projeyi tekrar derleyiniz.
  Derleyici tarafından hiç bir syntax hatası belirtilmemişse OMNeT++'ı kapatıp yeniden açmak işe yarayabilir.

----------------------------------------------------------------------------------------------
######## Geliştiriciler


***Mehmed Emre AKDİN*** --- ***Emre KURŞUN****

----------------------------------------------------------------------------------------------
######### Teşekkürler

- Projede büyük katkısı olan Dr. Öğr. Üyesi Selçuk CEVHER'e
- Kodu kullanan ve inceleyen herkese
