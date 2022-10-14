CC=clang

CFLAGS=-g -fsanitize=address -fno-omit-frame-pointer 
LDFLAGS=

SOURCES=example_UseAfterFree.c
STATIC_REPORT_DIR=html_dir


EXECUTABLE_PREFIX=bin
EXECUTABLE_CLEAR=$(EXECUTABLE_PREFIX)_clear 
EXECUTABLE_ASAN=$(EXECUTABLE_PREFIX)_asan

.PHONY: all clean
.SECONDARY: asan static orig

all:	static asan orig

static:
	$(CC) --analyze -Xanalyzer -analyzer-output=html -o $(STATIC_REPORT_DIR) $(SOURCES)
	
orig:

	$(CC) $(SOURCES) -o $(EXECUTABLE_CLEAR)
asan:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE_ASAN)

clean:
	rm $(EXECUTABLE_PREFIX)*
	rm -rf $(STATIC_REPORT_DIR) 


