# o2logger
logger in string-format style

## Introduction
Base concept - is a mix between `printf` and `std::streams`.

## Rationale
Usage of printf:  
 \+ convenient for writing  
 \- it is necessary to specify types of variable  
 \- it is impossible to print complex type  
Example:
```
printf("easy to combain %s with data: %d\n", "what i want", 42);
```
Usage of streams:  
 \+ no need to specify types  
 \+ it is possible to print complex type  
 \- awkward syntax  
Example:
```
std::cerr << "all these " << "brackets are " << "forced to cry" << 42 << std::endl;
```
  
## Abilities
 - can set loglevel
 - can write into syslog
  
## Usage
```
#include "o2logger.hpp"
using namespace o2logger;

o2logger::Logger::impl().setOptionLogLevel(0);             // [0-5], by default it is 0
o2logger::Logger::impl().setOptionSyslog("myprog", true);  // write into syslog, default false
```
  
## Severety
```
logi - [i] - info
logw - [w] - warning
loge - [e] - error
logd - [d] - debug 
logd1, logd2, logd3, logd4, logd5            // if LogLevel == 2, then logd3() won't write, but logd2() will
```
  
## Example of o2logger usage
```
// simple string
logi("Hello world!");                   // [i] Hello world!
logw("World is in a danger!");          // [w] World is in a danger!
loge("Oh no, it is cruel world :(");    // [e] Oh no, it is cruel world :(

// simple list of args
logi("key value: ", 1);                 // [i] key value: 1
loge("key value: ", 3.14);              // [e] key value: 3.14
logw("key value: ", "abc");             // [w] key value: abc
logd("Debug: ", 0, ", Debug2: ", 2);    // [d] Debug: 0, Debug2: 2

// formatted print
f::logi("key value: {0}, {1}", 1, 2);   // [i] key value: 1, 2
f::logw("key value: {1}, {0}", 1, 2);   // [w] key value: 2, 1
loge("key {0} value {1}", 3.14);        // [e] key 3.14 value nil

TODO: for struct
```

### Authors
- Victor Mogilin (o2gy84@gmail.com)
