CC=clang

CFLAGS=-g -fsanitize=memory -fno-omit-frame-pointer -fPIE -pie
LDFLAGS=

SOURCES=uninitialized_memory_reads.c
STATIC_REPORT_DIR=html_dir


EXECUTABLE_PREFIX=bin
EXECUTABLE_CLEAR=$(EXECUTABLE_PREFIX)_clear 
EXECUTABLE_ASAN=$(EXECUTABLE_PREFIX)_msan

.PHONY: all clean
.SECONDARY: msan static orig

all:	 msan orig

static:
	$(CC) --analyze -Xanalyzer -analyzer-output=html -o $(STATIC_REPORT_DIR) $(SOURCES)
	
orig:
	$(CC) $(SOURCES) -o $(EXECUTABLE_CLEAR)
msan:	
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE_ASAN)

clean:
	rm $(EXECUTABLE_PREFIX)*
	rm -rf $(STATIC_REPORT_DIR) 


