CC=clang

CFLAGS=-g -fsanitize=address -fno-omit-frame-pointer 
LDFLAGS=

SOURCES=*.c
STATIC_REPORT_DIR=html_dir

SANITISER=asan
EXECUTABLE_PREFIX=bin
EXECUTABLE_CLEAR=$(EXECUTABLE_PREFIX)_clear 
EXECUTABLE_ASAN=$(EXECUTABLE_PREFIX)_$(SANITISER)

.PHONY: all clean
.SECONDARY: $(SANITISER) static orig

all:	 $(SANITISER) orig

static:
	$(CC) --analyze -Xanalyzer -analyzer-output=html -o $(STATIC_REPORT_DIR) $(SOURCES)
	
orig:
	$(CC) $(SOURCES) -g -o $(EXECUTABLE_CLEAR)

$(SANITISER):
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE_ASAN)

clean:
	rm -rf $(STATIC_REPORT_DIR) 
	rm $(EXECUTABLE_PREFIX)*

help:
	@echo "Доступные цели:"
	@echo "  all           - Собрать все исполняемые файлы и отчеты"
	@echo "  static        - Выполнить статический анализ и сгенерировать отчеты"
	@echo "  orig          - Компилировать исходный код без санитизации"
	@echo "  $(SANITISER)  - Компилировать с использованием санитайзера $(SANITISER)"
	@echo "  clean         - Удалить отчеты и исполняемые файлы"