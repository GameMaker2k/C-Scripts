#include <iostream>

int main(int argc, char *argv[])
{
   // printf() displays the string inside quotation
   #ifdef __TINYC__
    std::cout << "Hello, World!\nFrom TinyCC.\n";
   #endif
   #ifndef __TINYC__
    #ifdef __GNUC__
     #ifdef __clang__
      #ifdef __cplusplus
       std::cout << "Hello, World!\nFrom Clang++.\n";
      #endif
      #ifndef __cplusplus
       std::cout << "Hello, World!\nFrom Clang.\n";
      #endif
     #endif
     #ifndef __clang__
      #ifdef __GNUG__
       std::cout << "Hello, World!\nFrom G++.\n";
      #endif
      #ifndef __GNUG__
       #ifdef __cplusplus
        std::cout << "Hello, World!\nFrom G++.\n";
       #endif
       #ifndef __cplusplus
        std::cout << "Hello, World!\nFrom GCC.\n";
       #endif
      #endif
     #endif
    #endif
    #ifndef __GNUC__
     #ifdef _MSC_VER
      #ifdef __cplusplus
       std::cout << "Hello, World!\nFrom MSVC++.\n";
      #endif
      #ifndef __cplusplus
       std::cout << "Hello, World!\nFrom MSVC.\n";
      #endif
     #endif
     #ifndef _MSC_VER
      #ifdef __cplusplus
       std::cout << "Hello, World!\nFrom Somewhere++.\n";
      #endif
      #ifndef __cplusplus
       std::cout << "Hello, World!\nFrom Somewhere.\n";
      #endif
     #endif
    #endif
   #endif
   return 0;
}
