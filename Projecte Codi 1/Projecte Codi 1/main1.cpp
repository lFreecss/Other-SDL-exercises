#include "include/SDL.h"
#include <iostream>

#pragma comment( lib, "lib/x86/SDL2.lib")
#pragma comment( lib, "lib/x86/SDL2main.lib" )

int main(int argc, char *args[]) {
	SDL_Init(SDL_INIT_EVERYTHING); // Inici Llibrería SDL
	int h = 500;
	int w = 500;//Mides
	bool down = false;
	bool up = false;
	bool left = false;
	bool right = false;
	bool bulletmov = false;
	SDL_Window *MainWindow = SDL_CreateWindow("SDL_RenderClear", // Creació de la finestra on volem que surti el programa
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, // Establim una posició a la finestra
		h, w, // Mides
		SDL_WINDOW_SHOWN // Visibilitat de la pantalla
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_PRESENTVSYNC); // Actua com a inici per dibuixar la pantalla, el -1 representa el numero de gráficas y el 0 representa el numero de SDL_RendererFlags

	SDL_Rect square; //Crees el quadrat i li dones posicions
	square.x = 50;
	square.y = 50;
	square.w = 50;
	square.h = 50;

	SDL_Rect bullet; //Bala
	bullet.x = square.x + (square.x/2);
	bullet.y = square.y + (square.y/2);
	bullet.w = 5;
	bullet.h = 25;

	//SDL_LoadBMP("smiley 16.bmp"); 





	while (1) { //Main loop, tota l'estona actualitza el que s'està dibuixant
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer); // Borro el que hi havia i creo pantalla vermella

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //Li apliques el color
		SDL_RenderFillRect(renderer, &square);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &bullet);
		
		SDL_Event event;
		while (SDL_PollEvent(&event)) { // Sol·licita els events
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0) { //Condició per la qual mantens presionat una tecla
				switch (event.key.keysym.sym) { //Establiment de les tecles que necessitem
				case SDLK_DOWN: //Moure abaix i establir abaix
					down = true;
					break;
				case SDLK_UP: //Moure adalt i establir adalt
					up = true;
					break;
				case SDLK_LEFT: //Moure esquerra i establir limit esquerra
					left = true;
					break;
				case SDLK_RIGHT: //Moure dreta i establir limit dreta
					right = true;
					break;
				case SDLK_SPACE:
					bulletmov = true;
					break;
				case SDLK_ESCAPE: //Tancar amb el Escape
					SDL_Quit;
					return EXIT_SUCCESS;
					break;
				default:
					printf("No valid\n");
				}
			}
			 if (event.type == SDL_QUIT) { //Tancar amb la creu
				SDL_Quit;
				return EXIT_SUCCESS;
				break;
			}
			 if (event.type == SDL_KEYUP) 
			 {
				 switch (event.key.keysym.sym) { //Establiment de les tecles que necessitem
				 case SDLK_DOWN: //Moure abaix i establir abaix
					 down = false;
					 break;
				 case SDLK_UP: //Moure adalt i establir adalt
					 up = false;
					 break;
				 case SDLK_LEFT: //Moure esquerra i establir limit esquerra
					 left = false;
					 break;
				 case SDLK_RIGHT: //Moure dreta i establir limit dreta
					 right = false;
					 break;
				 }
			 }
			
		}
		if (down == true)
		{
			square.y += 10;
			if (square.y > (h - square.h))
			{
				square.y = (h - square.h);
			}
		}
		if (up == true)
		{
			square.y -= 10;
			if (square.y < 0)
			{
				square.y = 0;
			}
		}
		if (left == true)
		{
			square.x -= 10;
			if (square.x < 0)
			{
				square.x = 0;
			}
		}
		if (right == true)
		{
			square.x += 10;
			if (square.x >(w - square.w))
			{
				square.x = (w - square.w);
			}
		}
		if (bulletmov == false)
		{
			bullet.x = square.x + (square.w / 2);
			bullet.y = square.y + (square.h / 2);
		}
		if (bulletmov == true)
		{
			bullet.y -= 10;
			if (bullet.y < 0)
			{
				bullet.x = square.x + (square.w / 2);
				bullet.y = square.y + (square.h / 2);
				bulletmov = false;
			}
		}
		SDL_RenderPresent(renderer); //Fa que pinti totes les accions que han sigut sol·licitades al renderer
	}
	

	/*SDL_Delay(5000);*/ // Que la pantalla tardi uns segons en tancar
} //https://wiki.libsdl.org/SDL_CreateRenderer
  //Deures:Finestra vermella, quadrat blau

//SDL_LoadBMP (ficher .bmp)