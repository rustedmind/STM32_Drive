This purpose of this project is:
1. Train some people in DO-178 development lifecycle and embedded software in general
2. MISRA-C:2012 Training

The goal is to produce sources that are suitable for:
1.Static Analysis
2.Unit testing
3.Dynamic Testing

Main considerations are:
1. Write safe code - No MISRA:C 2012 mandatory rules violations 
2. Write compact code - Only necessary HAL will be used
3. Write code that can be compiled with GCC, IAR, Keil etc

Project uses GCC-ARM toolchain and tries to be self-sufficient (all necessary libs and so on are included).

LICENSE:
GNU GPL

