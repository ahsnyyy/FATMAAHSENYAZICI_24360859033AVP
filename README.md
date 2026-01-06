# Algoritmalar ve Programlama Dönem Projesi

Bu depo, Algoritmalar ve Programlama dersi kapsamında bireysel olarak geliştirilen
“Güneş Sistemi Tabanlı Fizik Deney Simülasyonu” adlı dönem projesine ait kaynak kodları
ve proje raporunu içermektedir.

## Proje Hakkında
Bu proje kapsamında C programlama dili kullanılarak konsol tabanlı bir uzay simülasyonu
geliştirilmiştir. Program, kullanıcıdan alınan fiziksel büyüklüklere göre farklı fizik
deneylerini Güneş Sistemi’ndeki gezegenler için ayrı ayrı hesaplamakta ve elde edilen
sonuçları karşılaştırmalı olarak kullanıcıya sunmaktadır.

Uygulama geliştirilirken modüler programlama yaklaşımı benimsenmiş, her bir deney
ayrı fonksiyonlar halinde tasarlanmıştır. Gezegenlere ait yerçekimi ivmeleri tek bir
dizi içerisinde tutulmuş ve bu veriler fonksiyonlara pointer mantığıyla aktarılmıştır.

## Proje Yapısı
- `src/` klasörü proje kapsamında geliştirilen C kaynak kodlarını içermektedir.
- `docs/` klasörü proje raporunu (PDF formatında) barındırmaktadır.
- `README.md` dosyası projeye ait genel açıklamaları içermektedir.

## Kullanılan Teknolojiler
- C Programlama Dili
- Standart C Kütüphaneleri

## Çalıştırma Bilgisi
Proje, herhangi bir C derleyicisi kullanılarak çalıştırılabilir.
Kaynak kodlar `src` klasörü içerisinde yer almaktadır.

## Not
Bu proje Algoritmalar ve Programlama dersi kapsamında bireysel olarak geliştirilmiştir.
