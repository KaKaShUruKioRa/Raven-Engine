#include <Coeur/Moteur.hpp>

//                                  ATTRIBUTS GLOBAUX                                  //	
//-------------------------------------------------------------------------------------//
//                                 Attributs Statiques                                 
//-------------------------------------------------------------------------------------//

//Attribut Global : Le Moteur (un seul instance possible)
Moteur* Moteur::instance = nullptr;
//                              CONSTRUCTEURS/DESTRUCTEURS                              //
//--------------------------------------------------------------------------------------//
//                               Constructeur par Défaut                               
//--------------------------------------------------------------------------------------//

Moteur::Moteur() { this->initialiser(); }

//                                 METHODES INTERNES                                 //	
//-----------------------------------------------------------------------------------//
//                                      Méthodes                                      
//-----------------------------------------------------------------------------------//

void Moteur::quitter() {
	std::cout << "Quitter..." << std::endl;
	this->running = false;
}

void Moteur::evenement() {
	SDL_Event event;
	std::cout << "Evenement..." << std::endl;

	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		this->quitter();
		break;
	}
}

void Moteur::traitement() {
	std::cout << "Traitement..." << std::endl;
}

void Moteur::affichage() {
	std::cout << "Affichage..." << std::endl;
	SDL_SetRenderDrawColor(this->rendu, 0, 0, 0, 255);
	SDL_RenderClear(rendu);
	SDL_RenderPresent(rendu);
	std::cout << "Affichage mis à jour." << std::endl;
}

bool Moteur::nettoyer() {
	std::cout << "Nettoyage..." << std::endl;

	if (rendu != nullptr) {
		SDL_DestroyRenderer(rendu);
		std::cout << "Destruction de Rendu" << std::endl;
	}
	this->rendu = nullptr;

	if (fenetre != nullptr) {
		SDL_DestroyWindow(fenetre);
		std::cout << "Destruction de Fenetre" << std::endl;
	}
	this->fenetre = nullptr;

	IMG_Quit();
	SDL_Quit();

	return true;
}
//                                 METHODES INTERNES                                 //
//-----------------------------------------------------------------------------------//
//                                      Méthodes                                      
//-----------------------------------------------------------------------------------//

bool Moteur::initialiser() {
	std::cout << "Initalisation..." << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO != 0 && IMG_Init(IMG_INIT_PNG) != 0)) {
		SDL_Log("L'Initialisation n'a pas fonctionné : %s", SDL_GetError());
		return false;
	}

	this->fenetre = SDL_CreateWindow("Raven Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_ECRAN, HAUTEUR_ECRAN, 0);
	if (this->fenetre == nullptr) {
		SDL_Log("Impossible de créer la fenetre : %s", SDL_GetError());
		return false;
	}
	this->rendu = SDL_CreateRenderer(this->fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->fenetre == nullptr) {
		SDL_Log("Impossible de créer le rendu : %s", SDL_GetError());
		return false;
	}

	std::cout << "Initialiser !" << std::endl;

	return this->running = true;
}