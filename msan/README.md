## How to use MSAN manually?
Imagine, that you have file ``test.c`` with your C code and you want build it with MSAN

RUN:
```
clang -g -fsanitize=memory test.c -o bin
```
run ``bin`` <-- this is your binary with MSAN

## Как использовать MSAN самому?
Пусть у вас есть файл с исходным кодом ``test.c``, который вы хотите собрать с MSAN

Запустите:
```
clang -g -fsanitize=memory test.c -o bin
```
run ``bin`` <-- это ваш бинарь с MSAN
