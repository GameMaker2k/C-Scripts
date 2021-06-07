/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the Revised BSD License.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Revised BSD License for more details.
 
    Copyright 2021 iDB Support - http://idb.berlios.de/
    Copyright 2021 Game Maker 2k - http://gamemaker2k.org/
 
    $FileInfo: hello.c - Last Update: 06/06/2021 Ver 1 - Author: cooldude2k $
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
   int sysset = 0;
   #ifdef __TINYC__
    char compiler[] = "TinyCC";
    char language[] = "C";
   #endif
   #ifndef __TINYC__
    #ifdef __GNUC__
     #ifdef __clang__
      #ifdef __cplusplus
       #ifdef __OBJC__
        char compiler[] = "ObjClang++";
        char language[] = "ObjC++";
       #endif
       #ifndef __OBJC__
        char compiler[] = "Clang++";
        char language[] = "C++";
       #endif
      #endif
      #ifndef __cplusplus
       #ifdef __OBJC__
        char compiler[] = "ObjClang";
        char language[] = "ObjC";
       #endif
       #ifndef __OBJC__
        char compiler[] = "Clang";
        char language[] = "C";
       #endif
      #endif
     #endif
     #ifndef __clang__
      #ifdef __GNUG__
       #ifdef __MINGW32__
        #ifndef __MINGW64__
         char system[] = "MinGW32";
         sysset = 1;
        #endif
       #endif
       #ifdef __MINGW64__
        char system[] = "MinGW64";
        sysset = 1;
       #endif
       #ifdef __CYGWIN32__
        #ifndef __CYGWIN64__
         char system[] = "CygWin32";
         sysset = 1;
        #endif
       #endif
       #ifdef __CYGWIN64__
        char system[] = "CygWin64";
        sysset = 1;
       #endif
       #ifdef __CYGWIN__
        #ifndef __CYGWIN32__
         #ifndef __CYGWIN64__
          char system[] = "CygWin32";
          sysset = 1;
         #endif
        #endif
       #endif
       #ifdef __DJGPP__
        char system[] = "DJGPP";
        sysset = 1;
       #endif
       #ifdef __OBJC__
        char compiler[] = "ObjG++";
        char language[] = "ObjC++";
       #endif
       #ifndef __OBJC__
        char compiler[] = "G++";
        char language[] = "C++";
       #endif
      #endif
      #ifndef __GNUG__
       #ifdef __MINGW32__
        #ifndef __MINGW64__
         char system[] = "MinGW32";
         sysset = 1;
        #endif
       #endif
       #ifdef __MINGW64__
        char system[] = "MinGW64";
        sysset = 1;
       #endif
       #ifdef __CYGWIN32__
        #ifndef __CYGWIN64__
         char system[] = "CygWin32";
         sysset = 1;
        #endif
       #endif
       #ifdef __CYGWIN64__
        char system[] = "CygWin64";
        sysset = 1;
       #endif
       #ifdef __CYGWIN__
        #ifndef __CYGWIN32__
         #ifndef __CYGWIN64__
          char system[] = "CygWin32";
          sysset = 1;
         #endif
        #endif
       #endif
       #ifdef __DJGPP__
        char system[] = "DJGPP";
        sysset = 1;
       #endif
       #ifdef __cplusplus
        #ifdef __OBJC__
         char compiler[] = "ObjG++";
         char language[] = "ObjC++";
        #endif
        #ifndef __OBJC__
         char compiler[] = "G++";
         char language[] = "C++";
        #endif
       #endif
       #ifndef __cplusplus
        #ifdef __OBJC__
         char compiler[] = "ObjGCC";
         char language[] = "ObjC";
        #endif
        #ifndef __OBJC__
         char compiler[] = "GCC";
         char language[] = "C";
        #endif
       #endif
      #endif
     #endif
    #endif
    #ifndef __GNUC__
     #ifdef _MSC_VER
      #ifdef __cplusplus
       char compiler[] = "MSVC++";
       char language[] = "C++";
      #endif
      #ifndef __cplusplus
       char compiler[] = "MSVC";
       char language[] = "C";
      #endif
     #endif
     #ifndef _MSC_VER
      #ifdef __INTEL_COMPILER
       #ifdef __cplusplus
        char compiler[] = "ICC++";
        char language[] = "C++";
       #endif
       #ifndef __cplusplus
        char compiler[] = "ICC";
        char language[] = "C";
       #endif
      #endif
      #ifndef __INTEL_COMPILER
       #ifdef __cplusplus
        char compiler[] = "Somewhere++";
        char language[] = "C++";
       #endif
       #ifndef __cplusplus
        char compiler[] = "Somewhere";
        char language[] = "C";
       #endif
      #endif
     #endif
    #endif
   #endif
   if(sysset==0)
   {
    char system[] = "Something";
    sysset = 1;
   }
   // printf() displays the string inside quotation
   printf("Hello, World!\nSystem: %s\nCompiler: %s\nLanguage: %s\n", system, compiler, language);
   return 0;
}
