#include <stdio.h>

int main(int argc, char *argv[])
{
   #ifdef __TINYC__
    char compiler[] = "TinyCC";
   #endif
   #ifndef __TINYC__
    #ifdef __GNUC__
     #ifdef __clang__
      #ifdef __cplusplus
       #ifdef __OBJC__
        char compiler[] = "ObjClang++";
       #endif
       #ifndef __OBJC__
        char compiler[] = "Clang++";
       #endif
      #endif
      #ifndef __cplusplus
       #ifdef __OBJC__
        char compiler[] = "ObjClang";
       #endif
       #ifndef __OBJC__
        char compiler[] = "Clang";
       #endif
      #endif
     #endif
     #ifndef __clang__
      #ifdef __GNUG__
       #ifdef __OBJC__
        char compiler[] = "ObjG++";
       #endif
       #ifndef __OBJC__
        char compiler[] = "G++";
       #endif
      #endif
      #ifndef __GNUG__
       #ifdef __cplusplus
        #ifdef __OBJC__
         char compiler[] = "ObjG++";
        #endif
        #ifndef __OBJC__
         char compiler[] = "G++";
        #endif
       #endif
       #ifndef __cplusplus
        #ifdef __OBJC__
         char compiler[] = "ObjGCC";
        #endif
        #ifndef __OBJC__
         char compiler[] = "GCC";
        #endif
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
   // printf() displays the string inside quotation
   printf("Hello, World!\nFrom %s.\n", compiler);
   return 0;
}
