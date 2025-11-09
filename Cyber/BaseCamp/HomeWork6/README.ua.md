
# Звіт по домашній роботі №6

В цій роботі я не буду пояснювати роботу команд.

Також зрозумів що командою VBoxManage startvm "Study" --type headless можна запустити віртуальну машину у прихованому режимі, а підключитися до неї через SSH і працювати зі свого терміналу. Це зручніше ніж працювати через саму віртуальну машину. 

## 1. Command cut

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo1.jpg)

## 2. Commands cut/tr

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo2.jpg)

## 3. Commands cut/tr/sort

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo3.jpg)

## 4. Command sed

Працювати з регулярними виразами складно!

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo4.jpg)

видалити коментарі
sed '/^\s*#/d;/^\s*$/d' ~/.profile 

видалити дублікати
sed '$!N;/^\(.*\)\n\1$/!P;D' ~/.profile 

дві зразу
sed '/^\s*#/d;/^\s*$/d;$!N;/^\(.*\)\n\1$/!P;D' ~/.profile

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo5.jpg)

## 5. Command awk

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork6/Photo6.jpg)

