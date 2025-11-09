#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{ 
    /*
    ---------------------------------- Ієрархія потоку вводу/виводу --------------------------------
        
    Files:  
    1.                      ios
    2.              ostream     ofstream
    3.              istream     ifstream
    4.              iostream    fstream 
        
    classes: 
    1.                          _Iosb   
    2.                          ios_base
    3.                          basic_ios
    4. basic_ostream (ostream)     /   basic_istream (istream)        ->         basic_iostream
    5. basic_ofstream (ofstream)   /   basic_ifstream (ifstream)                 basic_fstream

    -------------------- Корисні функції для роботи з консольним ввводом/виводом --------------------

    cout
        width
        fill
        precision
        setw

    // маніпулятори
    
    setf 
    unsetf 

    ios_base   (setf 1 param)
        boolalpha   noboolalpha
        showbase    noshowbase
        showpoin    notshowpoint
        uppercase   nouppercase
        showpos     noshowpos
        
    ios_base   (setf 2 param)
        basefield   dec
                    oct
                    hex
        floatfield  fixed
                    scientific
        adjustfield left
                    right
                    internal

    ios_base (cout, cin)
        eofbit 
        badbit
        failbit
        goofbit
        good
        eof
        bad
        rdstate
        exception
        clear
        setstate


    // методи
        
    get
    getchar
    getline
    ignore
    put
    putback
    peek
    write
    read
    close
    open
    is_open

    seekg
    tellg
    tellp
    eatline

    ios_base (file pointer)
        beg
        cur
        end

    ios_base (files)
        in
        out
        ate
        app
        trunc
        binary

    1. Прототип:           
       Опис:
       Параметри:
       Повертаюче значення:

    2. Прототип:            istream& get(T* str, long long count, T delim) {
       Опис:                зчитує символи з потоку вводу, та записує їх в масив str
       Параметри:           str   - вказівник на масив, де зберігатимуться зчитані символи
                            count - кількість символів для зчитування
                            delim - символ-роздільник, який припиняє зчитування
       Повертаюче значення: поверає об'єкт типу istream 

    2. Прототип:            ostream& put(T ch)
       Опис:                виводить симвло ch в потік вводу cout, повертає cout
       Параметри:           ch - переданий символ для виводу
       Повертаюче значення: поверає об'єкт типу ostream

    1. Прототип:            istream& getline(char* str, streamsize count, char delim = '\n');
       Опис:                
       Параметри:
       Повертаюче значення:

    1. Прототип:            istream& getline(instream& str, streamsize count, char delim = '\n');
       Опис:
       Параметри:
       Повертаюче значення:
    */

    return 0;
}
