
# Звіт по домашній роботі №9 (10 лекція)

В цій домашній роботі потрібно проаналізувати перші 100 пакетів з наданого файлу.

## tshark

Для аналізу пакетів я використовуватиму tshark.

-r прочитати  
-c кількість  
-w записати  
-Y тип пакету (http, tcp тощо...)  
-T вказуємо вивести лише певні дані  
-e вказуємо які саме дані вивести (викорстовується разом з -T)

Цією командою: 
```tshark -r GL_BS_capture.pcapng -c 100 -w first_100_packets.pcapng```  
я створив новий файл що містить перші 100 пакетів.

Так можна вивести усі дані про пакет: 
```tshark -r first_100_packets.pcapng```    

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork9/Photo1.jpg)

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork9/Photo2.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork9/Photo3.jpg)

Ці пакети не містять ніяких запитів в гугл!! І або я не зміг такі запити знайти.

## Wireshark

Графічний аналог tshark, за допомогою якого можна зручно аналізувати трафік

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork9/Photo4.jpg)

