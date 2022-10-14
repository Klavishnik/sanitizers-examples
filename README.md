##Description
Some simplest examples of typicall errors and how to etect them with sanitizers

##List of examples:
###MSAN


##If you got errors 
If ASAN get errors take this:
```
export ASAN_OPTIONS=use_sigaltstack=false
```

If MSAN get errors take this:
```
export MSAN_OPTIONS=use_sigaltstack=false
```
