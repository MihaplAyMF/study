
# Звіт по домашній роботі №5

## 1. та 2.

Цізавдання є у 3 звіті ![HomeWork3](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/README.ua.md)

## 3. Додавання та створення дисків в лінукс

В віртуальній машниі я додав необхідні диски до системи

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo1.jpg)

Ось як це виглядало в системі

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo2.jpg)

На кожному диску я створив по 4 розділи

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo3.jpg)

Для дисків створених на MBR, додав extended розділ, який було поділено на два logical диски

Після цього було створего 24 папки, які відповідають кожного розділу 

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo4.jpg)

Використовуючи наступні команди

mkfs.ext4 /dev/sd*
mkfs.xfs /dev/sd*
mkfs.reiserfs /dev/sd*
mkfs.btrfs /dev/sd*
замість * назву відповідного розідлу

створив відповідні файлові системи, та змонтував їх у створені папки. Для xfs потрібно не менше 300 мб тому довелося перевиділяти пам'ять, отримав її зменшивши розмір першої частини диску. І так для кожного.

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo5.jpg)

Після перезавантаження системи монтування зникло, тому щоб не монтувати кожного разу знову, до файлу fstab додав наступне

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo6.jpg)

Порівнюючи fdisk та parted зрозумів що fdisk більш зручний і простий у використанні. 

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork5/Photo7.jpg)


