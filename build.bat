gcc -c cqpmgw.c com.example.democ.c com.example.democpp.cpp 
gcc -shared com.example.democ.o cqpmgw.o -o com.example.democ.dll -lCQP -lcrypt32 -L. -fPIC -Wl,--kill-at,--enable-stdcall-fixup
gcc -shared com.example.democpp.o cqpmgw.o -o com.example.democpp.dll -lCQP -lcrypt32 -lstdc++ -L. -fPIC -Wl,--kill-at,--enable-stdcall-fixup