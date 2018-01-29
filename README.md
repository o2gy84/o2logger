# o2logger
logger in string-format style

## Introduction
Base concept - is a mix between `printf` and streams.

## Rationale
Usage of printf:
 + convenient for writing
 - it is necessary to specify types of variable
 - it is impossible to print complex type  
Example:
```
printf("easy to combain %s with data: %d\n", "what i want", 42);
```
Usage of streams:
 + no need to specify types
 + it is possible to print complex type
 - awkward syntax  
Example:
```
std::cerr << "all these " << "brackets are " << "forced to cry" << 42 << std::endl;
```

## Example of o2logger usage
```
logi("key value: {0}, {1}", 1, 2);
logi("key {0}, value: {1}", "key", 42);

TODO: for struct
```

## Abilities
 - can set loglevel
 - can write into syslog

### Authors
- Victor Mogilin (o2gy84@gmail.com)
