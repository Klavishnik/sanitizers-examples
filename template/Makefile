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
