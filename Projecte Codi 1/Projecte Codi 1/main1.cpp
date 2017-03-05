#include "include/SDL.h"
#include <iostream>

#pragma comment( lib, "lib/x86/SDL2.lib")
#pragma comment( lib, "lib/x86/SDL2main.lib" )

int main(int argc, char *args[]) {
	SDL_Init(SDL_INIT_EVERYTHING); // Inici Llibrería SDL
	int h = 500;
	int w = 500;//Mides
	SDL_Window *MainWindow = SDL_CreateWindow("SDL_RenderClear", // Creació de la finestra on volem que surti el programa
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, // Establim una posició a la finestra
		h, w, // Mides
		SDL_WINDOW_SHOWN // Visibilitat de la pantalla
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(MainWindow, -1, 0); // Actua com a inici per dibuixar la pantalla, el -1 representa el numero de gráficas y el 0 representa el numero de SDL_RendererFlags

	SDL_Rect square; //Crees el quadrat i li dones posicions
	square.x = 50;
	square.y = 50;
	square.w = 50;
	square.h = 50;

	SDL_Event event;


	while (1) { //Main loop, tota l'estona actualitza el que s'està dibuixant
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer); // Borro el que hi havia i creo pantalla vermella

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Li apliques el color
		SDL_RenderFillRect(renderer, &square);

		while (SDL_PollEvent(&event)) { // Sol·licita els events
			if (event.type == SDL_KEYDOWN) { //Condició per la qual mantens presionat una tecla
				switch (event.key.keysym.sym) { //Establiment de les tecles que necessitem
				case SDLK_DOWN: //Moure abaix i establir abaix
					square.y += 10;
					if (square.y > (h-square.h))
					{
						square.y = (h-square.h);
					}
					break;
				case SDLK_UP: //Moure adalt i establir adalt
					square.y -= 10;
					if (square.y < 0)
					{
						square.y = 0;
					}
					break;
				case SDLK_LEFT: //Moure esquerra i establir limit esquerra
					square.x -= 10;
					if (square.x < 0)
					{
						square.x = 0;
					}
					break;
				case SDLK_RIGHT: //Moure dreta i establir limit dreta
					square.x += 10;
					if (square.x > (w-square.w))
					{
						square.x = (w-square.w);
					}
					break;
				case SDLK_ESCAPE: //Tancar amb el Escape
					SDL_Quit;
					return EXIT_SUCCESS;
					break;
				default:
					printf("No valid\n");
				}
			}
			else if (event.type == SDL_QUIT) { //Tancar amb la creu
				SDL_Quit;
				return EXIT_SUCCESS;
				break;
			}
		}
		SDL_RenderPresent(renderer); //Fa que pinti totes les accions que han sigut sol·licitades al renderer
	}

	/*SDL_Delay(5000);*/ // Que la pantalla tardi uns segons en tancar
} //https://wiki.libsdl.org/SDL_CreateRenderer
  //Deures:Finestra vermella, quadrat blau
