## Как использовать UBSAN самому?
Пусть у вас есть файл с исходным кодом ``test.c``, который вы хотите собрать с ASAN

Запустите:
```
clang -g -fsanitize=undefined test.c -o bin
```
run ``bin`` <-- это ваш бинарь с ASAN

## Как использовать статический анализатор??
```
clang --analyze -Xanalyzer -analyzer-output=html -o dir_output test.c
```
В папке **dir_ouput** будет ваш отчет *.html*
