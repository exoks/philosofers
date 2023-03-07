NAME := main
SRC := main.java
OBJS := main.class

JC := javac

all: $(OBJS)

%.class: %.java
	$(JC) $^

test:
	java $(NAME)
