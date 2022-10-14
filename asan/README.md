## How to use ASAN manually?
Imagine, that you have file ``test.c`` with your C code and you want build it with ASAN

RUN:
```
clang -g -fsanitize=address test.c -o bin
```
run ``bin`` <-- this is your binary with ASAN

## How to use static analyzer manually?
```
clang --analyze -Xanalyzer -analyzer-output=html -o dir_output test.c
```
in **dir_ouput** will be report *.html*


## Как использовать ASAN самому?
Пусть у вас есть файл с исходным кодом ``test.c``, который вы хотите собрать с ASAN

Запустите:
```
clang -g -fsanitize=address test.c -o bin
```
run ``bin`` <-- это ваш бинарь с ASAN

## Как использовать статический анализатор??
```
clang --analyze -Xanalyzer -analyzer-output=html -o dir_output test.c
```
В папке **dir_ouput** будет ваш отчет *.html*
