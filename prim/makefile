all: prim

prim: prim.cpp
	@echo "Compilando arquivo objeto: prim"
	@g++ -o prim prim.cpp

install: prim
	@echo "Instalando no Sistema."
	@sudo cp prim /usr/local/bin/prim

clean:
	@echo "Limpando arquivos"
	-@rm -f prim
