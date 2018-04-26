all: djikstra

djikstra: djikstra.cpp
	@echo "Compilando arquivo objeto: djikstra"
	@g++ -o djikstra djikstra.cpp

install: djikstra
	@echo "Instalando no Sistema."
	@sudo cp djikstra /usr/local/bin/djikstra

clean:
	@echo "Limpando arquivos"
	-@rm -f djikstra
