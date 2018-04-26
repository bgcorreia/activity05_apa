all: kruskal

kruskal: kruskal.cpp
	@echo "Compilando arquivo objeto: kruskal"
	@g++ -o kruskal kruskal.cpp

install: kruskal
	@echo "Instalando no Sistema."
	@sudo cp kruskal /usr/local/bin/kruskal

clean:
	@echo "Limpando arquivos"
	-@rm -f kruskal
