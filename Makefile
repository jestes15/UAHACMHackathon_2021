SOURCE_FILES = updater.cpp 
HEADER_FILES = 

OUT	= update 
CC	 = g++
FLAGS	 =
LFLAGS   = -lcurl

all: $(OBJS)
	$(CC) $(FLAGS) -o $(OUT) $(HEADER_FILES) $(SOURCE_FILES) $(LFLAGS)

clean:
	rm -f $(OUT)
