final: go_fish.o player.o deck.o card.o
	g++ -otest go_fish.o player.o deck.o card.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPodDriver.cpp
gameOn: go_fish.cpp card.h player.h deck.h
	g++ -c go_fish.cpp
player.o: player.cpp player.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp