
## Звіт по домашній роботі №12 (13 лекція)

В цій домашній роботі потрібно дослідити роботу наступних утиліт: dig, dnmasq, nslookup, tcpdump.

## dig

dig - команда для отримання детальної інформації про DNS сервер.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo1.jpg)

Команда ```dig @a.root-servers.net com NS``` повертає детальну інформацію про сервери імен NS що обслуговуються зоною com, для сервера a.root-servers.net. З цієї зони навмання було взято сервер для наступнної перевірки.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo2.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo3.jpg)

У запиті ```dig @e.gtld-servers.net example.com NS``` використовується example.com, мені стало цікаво чому, виявилося що це зарезервованийдля навчальний цілей домен, який можна виокристовувати без попередньої згоди. Сервер e.gtld-servers.net повертає два авторитарних сервери для example.com, це a.iana-servers.net та b.iana-servers.net.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo4.jpg)

Запит ```dig @b.iana-servers.net example.com A``` відправляється до b.iana-servers.net, з метою отримання A-запису (IP-адресу) для домену example.com.

## dnsmasq

dnsmasq - простий сервер який використовується для кешуванн DNS та DHCP.

Після встановлення слід відредагувати файл /etc/dnsmasq.conf та /etc/resolv.conf. В resolv.conf ми вказуємо локальну адресу, бо саме її використовує dnsmasq.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo5.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo6.jpg)

## nslookup

nslookup - дуже проста утиліта, дозволяє звертатися до серверів DNS, з ціллю отримати ip адресу.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo7.jpg)

## tcpdump

tcpdump - інтсрумент для захоплення мережевого трафіку в реальному часі.

dnsmasq за замовчуванням використовує локалхост та 53 порт, тому я й буду захоплювати трафік за цими ознаками.
```sudo tcpdump -i lo udp and port 53 -w dnsmasq_requests.pcap``` 

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork12/Photo8.jpg)

