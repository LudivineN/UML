all: bin/Jeu
	./bin/Jeu
bin/Jeu: obj/IO.o obj/Plateau.o obj/Objet.o obj/Player.o obj/Pirate.o obj/Boucanier.o obj/Flibustier.o   
	g++ $^ -o $@ -std=c++11
obj/IO.o: src/IO.cpp
	g++ -c $< -o $@ -std=c++11
obj/Plateau.o: src/plateau.cpp
	g++ -c $< -o $@ -std=c++11
obj/Objet.o: src/objet.cpp
	g++ -c $< -o $@ -std=c++11
obj/Player.o: src/Player.cpp
	g++ -c $< -o $@ -std=c++11
obj/Pirate.o: src/Pirate.cpp
	g++ -c $< -o $@ -std=c++11
obj/Boucanier.o: src/Boucanier.cpp
	g++ -c $< -o $@ -std=c++11
obj/Flibustier.o: src/Flibustier.cpp
	g++ -c $< -o $@ -std=c++11




net:
	rm obj/Player.o
	rm obj/Boucanier.o
	rm obj/Flibustier.o
	rm obj/Objet.o
	rm obj/Pirate.o
	rm obj/Plateau.o
	rm obj/IO.o
	rm bin/Jeu
