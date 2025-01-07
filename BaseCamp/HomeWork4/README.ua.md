
# Звіт по домашній роботі №4

## 1. Інсталяція пакетів

Для інтаслації пакетів в Ubuntu/Debian використовується менеджер пакетів apt. Також для додаванн сторонніх репозиторії використовуєтьтся PPA з командою add-apt-repository.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo1.jpg)

GPG ключі використовуються як гарантія що дані надходять з надійного джерела. Вони зберігаються в /etc/apt/trusted.gpg.d/, /usr/share/keyrings/ або безпосередньо в .sources файлі.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo2.jpg)

Більш нові репозиторії використовують .sources файли які зберігаються в папці /etc/apt/sources.list.d/

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo8.jpg)

Щоб вивести ключи які є в системі можна використати apt-key list, проте ця команда не покаже ключі що є в .source файлах. 
Я вписав команду gpg --list-key з надією вивести gpg ключі, вона створила локальну папку .gnupg з файлами pubring.kbx та trustdb.gpg. 

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo9.jpg)

Після цього я ще раз вписав gpg --list-key щоб побачити gpg ключі, але нічого не вивело, тому я вирішив додав його вручну. Щоб додати ключ до --list-key я спочатку скопіював ключ з .source файлу та помісти його в файл telegram-ppa-gpg.asc який імпортував командою gpg --import telegram-ppa-gpg.asc. Після цих дій команда gpg --list-key показує що ключ у системі. Для перевірки валідності ключа я вписав gpg --fingerprint ID_GPG_KEY

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo10.jpg)

Щоб переконатися що ключ дійсно коректний я перешов за посиланням що було у .source файлі та найшов fingerpint ключа який збігається з тим що є у мене

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo11.jpg)

Також щоб переконати що ключ коректний можна використати команду sudo apt update 

Щоб дізнатися PID телеграму я використав команду
ps aux | grep telegram

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo3.jpg)

Після цього я ввів команди для того щоб видалити телеграм з системи та пакетів  
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

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo5.jpg)

## 4. Розширення BASH

alias - команда що дозволяє створювати псевдоніми для власник команд  
.bashrc - конфігураційний файл для BASH оболонок терміналу.  
Я додав функцію arps яка викликає arp -a  
arps  
{  
    arp -a  
}  

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo6.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork4/Photo7.jpg)




