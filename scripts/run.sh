clang -o Connect4 src/*.c -Iinclude -I/opt/local/include -L/opt/local/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
./Connect4
