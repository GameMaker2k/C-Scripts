#include <stdio.h>

int main(int argc, char *argv[])
{
   // printf() displays the string inside quotation
   #ifdef __TINYC__
    char compiler[] = "TinyCC";
   #endif
   #ifndef __TINYC__
    #ifdef __GNUC__
     #ifdef __clang__
      #ifdef __cplusplus
       char compiler[] = "Clang++";
      #endif
      #ifndef __cplusplus
       char compiler[] = "Clang";
      #endif
     #endif
     #ifndef __clang__
      #ifdef __GNUG__
       char compiler[] = "G++";
      #endif
      #ifndef __GNUG__
       #ifdef __cplusplus
        char compiler[] = "G++";
       #endif
       #ifndef __cplusplus
        char compiler[] = "GCC";
       #endif
      #endif
     #endif
    #endif
    #ifndef __GNUC__
     #ifdef _MSC_VER
      #ifdef __cplusplus
       char compiler[] = "MSVC++";
      #endif
      #ifndef __cplusplus
       char compiler[] = "MSVC";
      #endif
     #endif
     #ifndef _MSC_VER
      #ifdef __INTEL_COMPILER
       #ifdef __cplusplus
        char compiler[] = "ICC++";
       #endif
       #ifndef __cplusplus
        char compiler[] = "ICC";
       #endif
      #endif
      #ifndef __INTEL_COMPILER
       #ifdef __cplusplus
        char compiler[] = "Somewhere++";
       #endif
       #ifndef __cplusplus
        char compiler[] = "Somewhere";
       #endif
      #endif
     #endif
    #endif
   #endif
   printf("Hello, World!\nFrom %s.\n", compiler);
   return 0;
}
