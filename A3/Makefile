CC = g++ 
CFLAGS = -Wall -std=c++11
FFLAGS = -fsanitize=undefined -fsanitize=address

TrieTest: Node.o Trie.o TrieTest.o
	$(CC) $(CFLAGS) $(FFLAGS) -o TrieTest Node.o Trie.o TrieTest.o

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) $(FFLAGS) -c Node.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) $(FFLAGS) -c Trie.cpp

TrieTest.o: TrieTest.cpp
	$(CC) $(CFLAGS) $(FFLAGS) -c TrieTest.cpp

clean:
	rm -f *.o TrieTest

test: 
	./TrieTest "test.txt" "queries.txt"