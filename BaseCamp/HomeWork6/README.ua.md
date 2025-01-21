
# Звіт по домашній роботі №6

В цій роботі я не буду пояснювати роботу команд, лише приведу приклад. Вважаю що цього буде достатньо.

## 1. Command cut

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo1.jpg)

## 2. Commands cut/tr

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo2.jpg)

## 3. Commands cut/tr/sort

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo3.jpg)

## 4. Command sed

Працювати з регулярними виразами трохи складно тому використовував ChatGPT та інтернет.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo4.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo5.jpg)

видалити коментарі
sed '/^\s*#/d;/^\s*$/d' ~/.profile 

видалити дублікати
sed '$!N;/^\(.*\)\n\1$/!P;D' ~/.profile 

дві зразу
sed '/^\s*#/d;/^\s*$/d;$!N;/^\(.*\)\n\1$/!P;D' ~/.profile

## 5. Command awk

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo6.jpg)

