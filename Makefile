CC	 = g++

update_TEST: $(OBJS)
	$(CC) $(FLAGS) -o updater_TEST updater_TEST.cpp -lcurl
clean_update_TEST:
	rm -f updater_TEST

graph_TEST: $(OBJS)
	$(CC) $(FLAGS) -o graph_TEST graph_TEST.cpp -lncurses
clean_graph_TEST:
	rm -f graph_TEST 

