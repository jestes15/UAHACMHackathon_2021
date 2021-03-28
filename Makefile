CC	 = g++
UPDATE_LDFLAGS = -lcurl
SOURCE_PATH = ./source
HEADER_PATH = ./header

all: $(OBJS)
	$(CC) $(FLAGS) -o covidData $(SOURCE_PATH)/updater.cpp $(SOURCE_PATH)/graph.cpp  $(SOURCE_PATH)/main.cpp $(UPDATE_LDFLAGS)
clean:
	rm -f covidData 

updater_TEST: $(OBJS)
	$(CC) $(FLAGS) -o updater_TEST $(SOURCE_PATH)/updater_TEST.cpp $(SOURCE_PATH)/updater.cpp $(UPDATE_LDFLAGS)
clean_updater_TEST:
	rm -f updater_TEST

graph_TEST: $(OBJS)
	$(CC) $(FLAGS) -o graph_TEST $(SOURCE_PATH)/graph_TEST.cpp $(SOURCE_PATH)/graph.cpp
clean_graph_TEST:
	rm -f graph_TEST 

analyser_TEST: $(OBJS)
	$(CC) $(FLAGS) -o analyser_TEST $(SOURCE_PATH)/analyser_TEST.cpp $(SOURCE_PATH)/analyser.cpp $(UPDATE_LDFLAGS)
clean_analizer_TEST:
	rm -f analyser_TEST


