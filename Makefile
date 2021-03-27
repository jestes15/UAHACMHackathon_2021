SOURCE_FILES = updater_TEST.cpp 
HEADER_FILES = 

OUT	= updateTEST
CC	 = g++
FLAGS	 =
LFLAGS   = -lcurl

update_test: $(OBJS)
	$(CC) $(FLAGS) -o $(OUT) $(HEADER_FILES) $(SOURCE_FILES) $(LFLAGS)

clean_update_test:
	rm -f $(OUT)
