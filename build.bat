gcc -shared com.example.democ.c -o com.example.democ.dll -lCQP -L. -fPIC -Wl,--kill-at,--enable-stdcall-fixup
gcc -shared com.example.democpp.cpp -o com.example.democpp.dll -lCQP -lstdc++ -L. -fPIC -Wl,--kill-at,--enable-stdcall-fixup