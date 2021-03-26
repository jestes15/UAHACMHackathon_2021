SOURCE_FILES = curltest.cpp 
HEADER_FILES = 

OUT	= curl_test
CC	 = g++
FLAGS	 =
LFLAGS   = -lcurl

all: $(OBJS)
	$(CC) $(FLAGS) -o $(OUT) $(HEADER_FILES) $(SOURCE_FILES) $(LFLAGS)

clean:
	rm -f $(OUT)
