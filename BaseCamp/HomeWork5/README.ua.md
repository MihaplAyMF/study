
# Звіт по домашній роботі №5

## 1 та 2

Виконання 1 та 2 завданн є у 3 звіті

## 3.  Додавання та створення дисків в лінукс

В віртуальній машниі я додав необхідні диски до системи

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo1.jpg)

Ось як це виглядало в системі

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo2.jpg)

На кожному диску я створив по 4 розділи, відповідно до вимох завдання

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo3.jpg)

Ті з дисків, що використовують MBR замість GPT, мають extended розділ який поділений на два logical диски

Після цього я створив 24 папки для кожного розділу відповідно

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo4.jpg)

Використовуючи наступні команди

mkfs.ext4 /dev/sd*
mkfs.xfs /dev/sd*
mkfs.reiserfs /dev/sd*
mkfs.btrfs /dev/sd*
замість * назву відповідного розідлу

я створив відповідні файлові системи, та монтував їх у створені папки

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo5.jpg)

Та додав до файлу fstab щоб вони автоматично монтувалися після завантаження систми

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo6.jpg)

Порівнюючи fdisk та parted зрозумів що fdisk більш зручний і простий у використанні.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo7.jpg)


