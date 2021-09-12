#ifndef __MOTEUR_HPP__
#define __MOTEUR_HPP__

//------------------------- Include --------------------------//
//-------- STD C++ --------//
#include <string>
#include <iostream>
#include <vector>
#include <memory>

//--------- SDL 2 --------//
#include <SDL.h>
#include <SDL_image.h>

//-------- Raven --------//


#define LARGEUR_ECRAN 1280
#define HAUTEUR_ECRAN 720

//Class Moteur en Singletone
class Moteur {
private:
	//                              CONSTRUCTEURS/DESTRUCTEURS                              //
	//--------------------------------------------------------------------------------------//
	//                               Constructeur par Défaut                               
	//--------------------------------------------------------------------------------------//

	//Constructeur : Constructeur Privée (SingleTone / static GetInstance )
	Moteur();

protected:
	//                                  ATTRIBUTS GLOBAUX                                  //	
	//-------------------------------------------------------------------------------------//
	//                                 Attributs Statiques                                 
	//-------------------------------------------------------------------------------------//

	//Attribut Global : Le Moteur (un seul instance possible)
	static Moteur* instance;
	//                                 ATTRIBUTS INTERNES                                 //
	//------------------------------------------------------------------------------------//
	//                                Attributs/Propriétés                                
	//------------------------------------------------------------------------------------//

	//Attribut : La Fenêtre 
	SDL_Window* fenetre;
	//Attribut : Le Rendu
	SDL_Renderer* rendu;

	//Attribut : Le Moteur est-il en cours d'exécution ?
	bool running;

public:
	//                                 METHODES INTERNES                                 //
	//-----------------------------------------------------------------------------------//
	//                                 Accesseurs/Getters                                 
	//-----------------------------------------------------------------------------------//

	//Getter : Retourne le Rendu
	inline SDL_Renderer* get_rendu() { return rendu; }
	//-----------------------------------------------------------------------------------//
	//                                    Méthode Is                                    
	//-----------------------------------------------------------------------------------//

	//Méthode Is : Retourne True si le Moteur est en cours d'exécution
	inline bool is_running() const { return running; }
	//-----------------------------------------------------------------------------------//
	//                                 Méthodes Statiques                                 
	//-----------------------------------------------------------------------------------//

	//Méthode Statique : Retourne l'instance Moteur si elle existe, sinon en crée une.
	static Moteur* get_instance() { return instance = (instance != nullptr) ? instance : new Moteur(); }
	//-----------------------------------------------------------------------------------//
	//                                      Méthodes                                      
	//-----------------------------------------------------------------------------------//
	
	//Méthode : Initialise le Moteur
	bool nettoyer();
	//Méthode : Initialise le Moteur
	void quitter();
	//Méthode : Initialise le Moteur
	void evenement();
	//Méthode : Initialise le Moteur
	void traitement();
	//Méthode : Initialise le Moteur
	void affichage();

protected:
	//                                 METHODES INTERNES                                 //
	//-----------------------------------------------------------------------------------//
	//                                      Méthodes                                      
	//-----------------------------------------------------------------------------------//

	//Méthode : Initialise le Moteur
	bool initialiser();
};

#endif // !__MOTEUR_HPP__
