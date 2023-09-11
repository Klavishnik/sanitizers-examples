## Описание 
Несколько небольших прмеров с типичными ошибками, которые бывают при работе с массивами, а также способы их детектирования через санитайзеры, статический анализ и valgrind.

## Список примеров:
### UBSAN
Undefined Santizer - Санитайзер, который определяет неопределенное поведение. 

Мы его будем использовать для определения:

1. Переполнение типа;
2. Деление на ноль.

Соответствубщие примеры приведены в папке UBSAN

### MSAN
MemorySanitizer (MSan) Санитайзер памяти позволяет обнаружить работу с объявленной, но неинициализированной (как на стекек, так и на куче) памятью в C/C++.

Пример определения ошибки лежит внутри папки *msan*

### ASAN
AddressSanitizer (aka ASan) - Адресный санитайзер позволяет обнаруживать ошибки памяти в C/C++.

Список ошибок, которые может обнаружить ASAN с примерами:
(ASAN детектирует больше ошибок, но они специфичны. За подробностями в раздел "Ссылки")

1. Использование указателя после освобождения памяти
2. Переполнение буффера на куче
3. Переполнение буффера на стэке
4. Утечки памяти

В файлах репозитория эти ошибки разбиты по папкам, которые имеют следующие названия:

1. use_after_free
2. stack_buffer_overflow
3. heap_buffer_overflow
4. memory_leak
5. heap_example - отдельный пример неправильного выделения памяти под динамический массив

## Как собрать?
  в каждой папке есть **Makefile** который принимает параметры в формате ``make name``, где ``name``:
 - *static* - позволяет прогнать код статическим анализатором clang и поместить очет в папку **html-dir**;
 - *orig* - собирает обычный бинарь без всяких проверок и инструментации. Имя скомпилированного файла - **bin_clear**;
 - *asan/msan/ubsan* - сборка бинаря с инструментацией ASAN or MSAN (смотря в какой папке собираете). Имя скомпилированного файла **bin_asan** или **bin_msan**;
 - *clean* - удаляет все файлы, полученные при сборке;
 - *all* - выполнит стадии *static, asan/(msan), orig*. Данная стадия запускается при выполнении ``make`` без аргументов

  Примеры:
  
  *build all:*
  ```2
  cd asan/heap_buffer_overflow/
  make
  ```
  *clean:*
  ```
  make clean
  ```

## Как использовать?
> 1. Перейдите в директорию с нужным вам примером и выполните:
> ``./bin_asan ``
> > или для папки с  msan 
> > `` ./bin_msan  ``
> >
> > или для папки с  ubsan 
> > `` ./bin_uban  ``
> > Вы увидете вывод санитайзера с описанием ошибки
> 
> 2. Выполните ```valgrind ./bin_clear``` чтобы увидеть вывод memcheck 
> 3. После сборки (выполнения команды ``make``) перейдите в **html_dir** - в ней есть файлик *.html* с отчетом статического анализатора. Его можно посмотреть через веб-браузер.


## Шаблон
### Как использовать?

Напишите свой код в любой файлик с расширением **.c** в папке **template**

Например ``test.c``

После этого выполните 

```make```

Все, что написано выше, будет применено к вашему файлу

## Exmaple output

>### Static analyzer
>
>![Static analyzer output!](/docks/static.jpg "Static analyzer")
>
>### ASAN sanitizer
>
>![ASAN sanitizer output!](/docks/ASAN.jpg "ASAN sanitizer")
>
>### MSAN sanitizer
>
>![MSAN sanitizer output!](/docks/MSAN.jpg "MSAN sanitizer")
>
>### Valgrind
>
>![Valgrind sanitizer output!](/docks/valgrind.jpg "Valgrind sanitizer")


### Если при запуске ./bin_asan или ./bin_msan вылетела ошибка с трассой выполнения, выполните следующее
Для ASAN:
``
export ASAN_OPTIONS=use_sigaltstack=false
``

Для MSAN :
``
export MSAN_OPTIONS=use_sigaltstack=false
``

## Ссылки:
https://github.com/google/sanitizers

https://releases.llvm.org/11.0.0/tools/clang/docs/AddressSanitizer.html

https://releases.llvm.org/11.0.0/tools/clang/docs/MemorySanitizer.html

https://valgrind.org/docs/manual/quick-start.html#quick-start.intro


