# Mi asombroso Makefile

# (Objetivo) : (dependecias)
# 	(comando 1)
# 	(comando 2)

bin/proyecto.exe : src/main.cpp
	@echo Compilando codigo fuente.....
	g++ -o bin/proyecto src/main.cpp -Iinclude
