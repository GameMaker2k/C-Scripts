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

/*
    https://sourceforge.net/p/predef/wiki/Compilers/
    https://sourceforge.net/p/predef/wiki/OperatingSystems/
*/

int main(int argc, char *argv[])
{
   int sysset = 0;
   int archset = 0;

   #ifdef __i386__
    char architecture[] = "IA32";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef __i486__
     char architecture[] = "IA32";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __i586__
     char architecture[] = "IA32";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __i686__
     char architecture[] = "IA32";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _M_I86
     char architecture[] = "IA16";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _M_IX86
     char architecture[] = "IA32";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __X86__
     char architecture[] = "IA32";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _X86_
     char architecture[] = "IA32";
     archset = 1;
    #endif
   }
   #ifdef __amd64__
    char architecture[] = "AMD64";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef __amd64
     char architecture[] = "AMD64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __x86_64__
     char architecture[] = "AMD64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __x86_64
     char architecture[] = "AMD64";
     archset = 1;
    #endif
   }
   #ifdef __arm__
    #ifndef __aarch64__
     char architecture[] = "Arm32";
     archset = 1;
    #endif
   #endif
   #ifdef __aarch64__
    char architecture[] = "Arm64";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef __thumb__
     char architecture[] = "Thumb";
     archset = 1;
    #endif
   }
   #ifdef __ia64__
    char architecture[] = "IA64";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef _IA64
     char architecture[] = "IA64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __IA64__
     char architecture[] = "IA64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _M_IA64
     char architecture[] = "IA64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _M_IA64
     char architecture[] = "IA64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __itanium__
     char architecture[] = "IA64";
     archset = 1;
    #endif
   }
   #ifdef __mips__
    char architecture[] = "MIPS";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef mips
     char architecture[] = "MIPS";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __mips
     char architecture[] = "MIPS";
     archset = 1;
    #endif
   }
   #ifdef __powerpc
    char architecture[] = "PowerPC";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef __powerpc__
     char architecture[] = "PowerPC";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __powerpc64__
     char architecture[] = "PowerPC64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __POWERPC__
     char architecture[] = "PowerPC";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __ppc__
     char architecture[] = "PowerPC";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef __ppc64__
     char architecture[] = "PowerPC64";
     archset = 1;
    #endif
   }

   #ifdef __PPC__
    char architecture[] = "PowerPC";
    archset = 1;
   #endif
   if(archset==0)
   {
    #ifdef __PPC64__
     char architecture[] = "PowerPC64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _ARCH_PPC
     char architecture[] = "PowerPC";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _ARCH_PPC64
     char architecture[] = "PowerPC64";
     archset = 1;
    #endif
   }
   if(archset==0)
   {
    #ifdef _M_PPC
     char architecture[] = "PowerPC";
     archset = 1;
    #endif
   }
   #ifdef _AIX
    char system[] = "Aix";
    sysset = 1;
   #endif
   #ifdef __ANDROID__
    char system[] = "Android";
    sysset = 1;
   #endif
   #ifdef __FreeBSD__
    char system[] = "FreeBSD";
    sysset = 1;
   #endif
   #ifdef __FreeBSD_kernel__
    #ifdef __GLIBC__
     char system[] = "GNUkFreeBSD";
     sysset = 1;
    #endif
   #endif
   #ifdef __NetBSD__
    char system[] = "NetBSD";
    sysset = 1;
   #endif
   #ifdef __OpenBSD__
    char system[] = "OpenBSD";
    sysset = 1;
   #endif
   #ifdef __bsdi__
    char system[] = "BSDi";
    sysset = 1;
   #endif
   #ifdef __DragonFly__
    char system[] = "DragonFlyBSD";
    sysset = 1;
   #endif
   #ifdef __gnu_hurd__
    char system[] = "GNUHurd";
    sysset = 1;
   #endif
   #ifdef __linux__
    char system[] = "Linux";
    sysset = 1;
   #endif
   #ifndef __linux__
    #ifdef __gnu_linux__
     char system[] = "GNULinux";
     sysset = 1;
    #endif
   #endif
   #ifdef macintosh
    char system[] = "MacOS9";
    sysset = 1;
   #endif
   #ifdef __APPLE__
    char system[] = "MacOSX";
    sysset = 1;
   #endif
   #ifdef __minix
    char system[] = "Minix";
    sysset = 1;
   #endif
   if(sysset==0)
   {
    #ifdef __unix__
     char system[] = "Unix";
     sysset = 1;
    #endif
   }
   if(sysset==0)
   {
    #ifdef __unix
     char system[] = "Unix";
     sysset = 1;
    #endif
   }
   #ifdef __TINYC__
    #ifdef _WIN16
     char system[] = "Win16";
     sysset = 1;
    #endif
    #ifdef _WIN32
     #ifndef _WIN64
      char system[] = "Win32";
      sysset = 1;
     #endif
    #endif
    #ifdef _WIN64
     char system[] = "Win64";
     sysset = 1;
    #endif
    char compiler[] = "TinyCC";
    char language[] = "C";
   #endif
   #ifndef __TINYC__
    #ifdef __GNUC__
     #ifdef __clang__
      #ifdef _WIN16
       char system[] = "Win16";
       sysset = 1;
      #endif
      #ifdef _WIN32
       #ifndef _WIN64
        char system[] = "Win32";
        sysset = 1;
       #endif
      #endif
      #ifdef _WIN64
       char system[] = "Win64";
       sysset = 1;
      #endif
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
     #ifdef _WIN16
      char system[] = "Win16";
      sysset = 1;
     #endif
     #ifdef _WIN32
      #ifndef _WIN64
       char system[] = "Win32";
       sysset = 1;
      #endif
     #endif
     #ifdef _WIN64
      char system[] = "Win64";
      sysset = 1;
     #endif
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
        char compiler[] = "Something++";
        char language[] = "C++";
       #endif
       #ifndef __cplusplus
        char compiler[] = "Something";
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
   if(archset==0)
   {
    char architecture[] = "Something";
    sysset = 1;
   }
   // printf() displays the string inside quotation
   printf("Hello, World!\nSystem: %s\nArchitecture: %s\nCompiler: %s\nLanguage: %s\n", system, architecture, compiler, language);
   return 0;
}
