
# Звіт по домашній роботі №4

## 1. Інсталяція пакетів

Для інтаслації пакетів в Ubuntu/Debian використовується менеджер пакетів apt. Також для додаванн сторонніх репозиторії використовуєтьтся PPA з командою add-apt-repository, а дані про це зберігаються у /etc/apt/sources.list.d/

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo1.jpg)

GPG ключі використовуються як гарантія що дані надходять з надійного джерела. Вони зберігаються в /etc/apt/trusted.gpg.d/

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo2.jpg)

Щоб дізнатися PID телегрмау я використав команду
ps aux | grep telegram

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo3.jpg)

Після цього я ввів команди для того щоб видилаи телеграм з системиiта пакетів
sudo apt-get remove telegram
sudo add-apt-repository --remove ppa:atareao/telegram
І перевірив чи є пакет в sources.list.d, його немає!!
ls /etc/apt/sources.list.d/

## 2. Команда find

2>/dev/null - перенаправляє вивід про помилки в null

find / -type f -size +1G 2>/dev/null
find /tmp -empty 2>/dev/null
find ~/ -mmin -60
find ~/ -cmin -60
find ~/ -perm 777

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo4.jpg)

-type  - вказати що шукаємо f (file) або d (directory)
-size  - шукає файли розмір яких більши/менишй/дорівнює n
-empty - шукає пусті файли або каталоги
-mmin  - шукає файли що були змінені за n хвилин
-cmin  - шукає файли метадані яких були змінені (включно з правами доступу)
-perm  - для пошуку файлів що мають відповідні права

## 3. Практика vimtutor

В мене встановлений nvim, в ньому можна практикуватися за допомогою конмади :Tutor що я й зробив

Я його почав використовую відвносно давно, тому вже знаю основний перелік команд, також змінив конфігураційний файл щоб було зручніше.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo1.jpg)

## 4. Розширення BASH

