CFLAGS = -std=c99 -Wall -lraylib -lX11 -lGL -lm -lpthread -ldl -lrt

release: 
	gcc $(CFLAGS) -o ../bin/release/dwars dwars.c scene.h assets.c gameplay.c
	../bin/release/./dwars

debug:
	gcc -g $(CFLAGS) -o ../bin/debug/dwars dwars.c scene.h assets.c gameplay.c
	gdb ../bin/debug/dwars
