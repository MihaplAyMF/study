
# Звіт по домашній роботі №4

## 1. Інсталяція пакетів

Для інтаслації пакетів в Ubuntu/Debian використовується менеджер пакетів apt. Також для додаванн сторонніх репозиторії використовуєтьтся PPA з командою add-apt-repository, а дані про це зберігаються у /etc/apt/sources.list.d/

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo1.jpg)

GPG ключі використовуються як гарантія що дані надходять з надійного джерела. Вони зберігаються в /etc/apt/trusted.gpg.d/

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo2.jpg)

Щоб дізнатися PID телегрмау я використав команду
ps aux | grep telegram

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo3.jpg)

Після цього я ввів команди для того щоб видилаи телеграм з системиiта пакетів.
sudo apt-get remove telegram
sudo add-apt-repository --remove ppa:atareao/telegram
І перевірив чи є пакет в sources.list.d, його немає!!
ls /etc/apt/sources.list.d/

## 2.
