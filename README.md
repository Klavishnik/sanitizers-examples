## Description
Some simplest examples of typicall errors and how to etect them with sanitizers

## List of examples:
### MSAN



### ASAN



## How to build?
>  Each folder contains **Makefile** that takes the following parameters:
> - *static* - build source with static analyzer and get report to **html-dir** folder;
> - *orig* - build source general binary file without instrumentation. Output name - **bin_clear**;
> - *asan/msan* - build with instrumentation ASAN or MSAN (look at name of main folder). Output name **bin_asan** or **bin_msan**;
> - *clean* - remove builded files;
> - *all* - make stages *static, asan/(msan), orig*;
>
>  Examples:
>  build all:
>  ```
>  cd asan/heap_buffer_overflow/
>  make
>  ```
>  clean:
>  ```
>  make clean
>  ```

## How to use?
>  1. Go to folder with needed example and run:
> ``./bin_asan ``
> > or for msan folder
> `` ./bin_msan  ``
> 
> you will see sanitiser output with table and description of error
> 
> 2. Run ```valgrind ./bin_clear``` to see memcheck analyzer output
> 3. After build go to **html_dir** - it contain *.html* report of static analyze. You can see this file with web browser.









### If you got errors 
If ASAN get errors take this:
``
export ASAN_OPTIONS=use_sigaltstack=false
``

If MSAN get errors take this:
``
export MSAN_OPTIONS=use_sigaltstack=false
``
