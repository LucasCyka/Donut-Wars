CFLAGS = -std=c99 -Wall -lraylib -lX11 -lGL -lm -lpthread -ldl -lrt

release: 
	gcc $(CFLAGS) -o ../bin/release/dwars dwars.c
	../bin/release/./dwars
clean:
	@echo "removing everything but source files"
