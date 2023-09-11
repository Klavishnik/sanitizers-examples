CC=clang

CFLAGS=-g -fsanitize=undefined -fno-omit-frame-pointer 
LDFLAGS=

SOURCES=*.c
STATIC_REPORT_DIR=html_dir

SANITISER=ubsan
EXECUTABLE_PREFIX=bin
EXECUTABLE_CLEAR=$(EXECUTABLE_PREFIX)_clear 
EXECUTABLE_ASAN=$(EXECUTABLE_PREFIX)_$(SANITISER)
EXECUTABLE_COMPILER=$(EXECUTABLE_PREFIX)_compiler_avoid 

.PHONY: all clean
.SECONDARY: $(SANITISER) static orig compiler_avoid

all:	$(SANITISER) orig compiler_avoid

static:
	$(CC) --analyze -Xanalyzer -analyzer-output=html -o $(STATIC_REPORT_DIR) $(SOURCES)
	
orig:
	$(CC) $(SOURCES) -o $(EXECUTABLE_CLEAR) 

compiler_avoid:
	$(CC) $(SOURCES) -o $(EXECUTABLE_COMPILER) -ftrapv

$(SANITISER):
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE_ASAN)

clean:
	rm -rf $(STATIC_REPORT_DIR) 
	rm $(EXECUTABLE_PREFIX)*
