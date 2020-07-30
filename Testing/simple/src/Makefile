all:
	
simple:	simple.c
	clang -std=c11 -fPIC -c -I/Users/Octosquid/git/godot_headers simple.c -o simple.os -arch i386 -arch x86_64
	clang -dynamiclib simple.os -o ../bin/osx/libsimple.dylib -arch i386 -arch x86_64
	
macos:
	clang -std=c11 -fPIC -c -I/Users/Octosquid/git/godot_headers custombits.c -o custombits.os -arch i386 -arch x86_64
	clang -dynamiclib custombits.os -o ../bin/osx/libcustombits.dylib -arch i386 -arch x86_64
	
windows: custombits.c
	cl /Focustombits.obj /c custombits.c /nologo -EHsc -DNDEBUG /MD /I. /I..\..\godot_headers
	link /nologo /dll /out:..\bin\win64\libcostumbits.dll /implib:..\bin\win64\libcostumbits.lib custombits.obj
	
