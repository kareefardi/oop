OBJS := End.o Expr.o Fsm.o State.o Sleep.o Wait.o Out.o Action.o
CC := g++
CFLAGS := -c -std=c++11 
LFLAGS := -std=c++11
NAME := test
CNAME := main.cpp

all: $(OBJS)
	$(CC) $(CNAME) $(LFLAGS) $(OBJS) -o $(NAME)

End.o : End.h End.cpp Action.o
	$(CC) $(CFLAGS) End.cpp

State.o : State.h State.cpp End.o Sleep.o Out.o Expr.o Wait.o Action.o Run.o
	$(CC) $(CFLAGS) State.cpp

Wait.o : Wait.h Wait.cpp Action.o
	$(CC) $(CFLAGS) Wait.cpp

Expr.o : Expr.h Expr.cpp Action.o
	$(CC) $(CFLAGS) Expr.cpp

Out.o : Out.h Out.cpp Expr.h Action.o
	$(CC) $(CFLAGS) Out.cpp

Fsm.o : State.o Fsm.cpp Action.o
	$(CC) $(CFLAGS) Fsm.cpp

Sleep.o : Sleep.h Sleep.cpp Action.o
	$(CC) $(CFLAGS) Sleep.cpp

Action.o : Action.h Action.cpp
	$(CC) $(CFLAGS) Action.cpp

Run.o : Run.h Run.cpp 
	$(CC) $(CFLAGS) Run.cpp
