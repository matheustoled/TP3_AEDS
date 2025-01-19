compile: src/main.c src/central_controle.c src/compartimento.c src/rocha_mineral.c
	gcc src/main.c src/central_controle.c src/compartimento.c src/rocha_mineral.c -o bin/programa