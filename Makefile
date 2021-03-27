CC	 = g++
UPDATE_LDFLAGS = -lcurl
SOURCE_PATH = ./source
HEADER_PATH = ./header

update_TEST: $(OBJS)
	$(CC) $(FLAGS) -o updater_TEST $(SOURCE_PATH)/updater_TEST.cpp $(UPDATE_LDFLAGS)
clean_updater_TEST:
	rm -f updater_TEST

graph_TEST: $(OBJS)
	$(CC) $(FLAGS) -o graph_TEST $(SOURCE_PATH)/graph_TEST.cpp
clean_graph_TEST:
	rm -f graph_TEST 

