
## Звіт по домашній роботі №11 (12 лекція)

В цій домашці потрібно запустіть сервер з netcat, що прослуховує порт 27664 і зберігає ввід у файл. Перенаправити трафік з порту 21 на 27664, та захопити його (трафік) за допомогою wireshark.

## netcat

Команда ```nc -l -p 27664 > recieved.txt &``` створює сервер у фоновому режимі, що порслуховує TCP-порт 27664 та перенаправляє увесь вивід у текстовий файл.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork11/Photo1.jpg)

fg %num використано для закриття фоного процесу. 

## Wireshar

Я використав Wireshark для перехоплення пакетів з фільтром tcp.port == 27664 і зберіг їх у файлі my.pcap

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork11/Photo2.jpg)

І після отримав повідомлення що були в цих пакетах

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork11/Photo3.jpg)

## iptables

Командою ```iptables -t nat -A OUTPUT -p tcp -s 127.0.0.1 --dport 21 -j REDIRECT --to-ports 27664``` ми перенаправляємо вивід з 21 на 27664 порт. 

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork11/Photo4.jpg)

Усе працює!

