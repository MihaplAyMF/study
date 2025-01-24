
# Звіт по домашній роботі №7

## 1. Hexdump

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo1.jpg)
![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo2.jpg)

## 2. Lsof

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo3.jpg)

## 3. Crontab and logrotate

crontab -e  
Я додав наступний рядок

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo4.jpg)

mkdir log  
Щоб не чекати 00:12 самостійно виконав цю команду  
du -ah /tmp | sort -rh » ~/log/tmp_fs.log  
створив logrotate  
sudo dd vim /etc/logrotate.d/tmp_fs_log   

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo5.jpg)

і запустив  
logrotate -d /etc/logrotate.d/tmp_fs_log  
Оскільки у мене в папці /tmp не було файлів що займають більше 150К, я створив декілька наступною командою   
dd if=/dev/zero of=/tmp/testfile bs=1K count=200  

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo6.jpg)

## 4. Archive

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo7.jpg)

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo8.jpg)

Після стискаємо цей архів відповідними командами.  
Ось так можна об'єднати пошук, архівування та сиснення.  

```tar -cvf - $(find ~/ -type f -name "*.txt") | bzip2 > txt_iles.tar.bz2```  
```tar -cvf - $(find ~/ -type f -name "*.txt") | gzip > txt_files.tar.gz```   
```tar -cvf - $(find ~/ -type f -name "*.txt") | zip > txt_files.tar.zip```  
 

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo9.jpg)

Як бачимо архів bz2 займає наймешне місця, але він стискатиметься трохи довше ніж інші два.   
Також є цікава гра bandit в якій у 12 завданні вимагало 10 разів розархівувати файл різними архіваторами, щоб дістати пароль до наступного рівня.   

![image](https://github.com/MihaplAyMF/study/blob/main/BaseCamp/HomeWork7/Photo10.jpg)

