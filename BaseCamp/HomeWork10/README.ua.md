
## Звіт по домашній роботі №10 (11 лекція)

В цій домашній роботі потрібно реалізувати мережеву конфігурацію для трьох комп'ютерів (A, B, C) з IP-адресами у діапазоні 10.10.10.0/24, щоб:  
    A міг спілкуватися з B  
    B міг спілкуватися з C  
    A не міг спілкуватися з C  
    Кожен комп'ютер мав ім'я хоста та FQDN  
    Працювало перетворення імен у IP-адреси  

## VirtualBox

Не було вказано як саме потрібно реалізувати таку мережу, я вирішив зробити це за допомогою VirtualBox.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork10/Photo1.jpg)

Я створив два клони уже існуючої віртуальної машини. Для кожної обрав мережу типу Internal Network, для другої також додав Bridged Adapter для можливості підключатися через SSH.

## Hostname

Командою ```sudo hostnamectl set-hostname hosta```, я змінив хостові імена. Після цього відредагував файл /etc/hosts.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork10/Photo2.jpg)

## nmcli

Налаштовував мережу я за допомогою утилі nmcli. Довго не міг зрозуміти чому мережевий інтерфейс enp0s3 не переходив в стан сonnected.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork10/Photo3.jpg)

Ось цими командами зміг налаштувати:  
```sudo nmcli connection modify enp0s3 ipv4.method manual ipv4.addresses 10.10.10.2/24 ipv4.gateway 10.10.10.1 ipv4.dns "8.8.8.8, 8.8.4.4"```  
```sudo nmcli connection up enp0s3```  

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork10/Photo4.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork10/Photo5.jpg)

## ip route and ping

ip roure - повертає нам поточну таблицю маршутизації, налаштував її так щоб комп'ютери спілкувалися відповідно до вимог завдання. Перевіряв зв'язок між хостами командою ping

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork10/Photo6.png)

Як видно з фото, hosta не має можливості комунікувати з hostc, тоді як hostb може з обома. 










