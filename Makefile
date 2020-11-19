#Compiling the entire game

FLAGS = -pedantic-errors -std=c++11

account_save_load.o: account_save_load.cpp account_save_load.h variable_structs.h
	g++ $(FLAGS) -c $<

art_call.o: art_call.cpp art_call.h
	g++ $(FLAGS) -c $<

bug_fix.o: bug_fix.cpp bug_fix.h
	g++ $(FLAGS) -c $<

life_event.o: life_event.cpp life_event.h
	g++ $(FLAGS) -c $<

stocks_and_news.o: stocks_and_news.cpp variable_structs.h stocks_and_news.h
	g++ $(FLAGS) -c $<

main.o: main.cpp art_call.h bug_fix.h account_save_load.h variable_structs.h stocks_and_news.h life_event.h
	g++ $(FLAGS) -c $<

game: account_save_load.o art_call.o bug_fix.o stocks_and_news.o main.o life_event.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f account_save_load.o art_call.o bug_fix.o stocks_and_news.o main.o game life_event.o

.PHONY: clean
