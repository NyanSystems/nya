OBJECTS= ./build/compiler.o ./build/cprocess.o ./build/helpers/buffer.o ./build/helpers/vector.o ./build/lexer.o ./build/lex_process.o
INCLUDES= -I./include -I./helpers

all: ${OBJECTS}
	gcc src/main.c ${INCLUDES} ${OBJECTS} -g -o ./build/nyagcc

./build/compiler.o: ./src/compiler.c
	gcc ./src/compiler.c ${INCLUDES} -o ./build/compiler.o -g -c

./build/cprocess.o: ./src/cprocess.c
	gcc ./src/cprocess.c ${INCLUDES} -o ./build/cprocess.o -g -c

./build/lexer.o: ./src/lexer.c
	gcc ./src/lexer.c ${INCLUDES} -o ./build/lexer.o -g -c

./build/lex_process.o: ./src/lex_process.c
	gcc ./src/lex_process.c ${INCLUDES} -o ./build/lex_process.o -g -c

./build/helpers/buffer.o: ./helpers/buffer.c
	gcc ./helpers/buffer.c ${INCLUDES} -o ./build/helpers/buffer.o -g -c

./build/helpers/vector.o: ./helpers/vector.c
	gcc ./helpers/vector.c ${INCLUDES} -o ./build/helpers/vector.o -g -c

clean:
	rm ./build/nyagcc
	rm -rf ${OBJECTS}

format:
	/usr/bin/find . -regex '.*\.\(c\|h\)' -exec clang-format -style=file -i {} \;
