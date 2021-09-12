//------------------------- Include --------------------------//
//-------- STD C++ --------//
#include <string>
#include <iostream>
#include <vector>
#include <memory>

//--------- SDL 2 --------//
#include <SDL.h>

//-------- Raven --------//
#include <Coeur/Moteur.hpp>

int main(int argc, char* args[]) {
	while (Moteur::get_instance()->is_running()) {
		Moteur::get_instance()->evenement();
		Moteur::get_instance()->traitement();
		Moteur::get_instance()->affichage();

		SDL_Delay(16);
	}

	Moteur::get_instance()->nettoyer();
	
	return EXIT_SUCCESS;
}