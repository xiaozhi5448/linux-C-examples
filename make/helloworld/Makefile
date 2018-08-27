objs = hello.o
Hello : $(objs)
	cc -o Hello $(objs)
hello.o : hello.h 
	cc -c hello.c
.PHONY : clean
clean:
	-rm Hello $(objs)
