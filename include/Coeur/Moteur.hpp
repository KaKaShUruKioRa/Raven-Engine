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
	//                               Constructeur par D�faut                               
	//--------------------------------------------------------------------------------------//

	//Constructeur : Constructeur Priv�e (SingleTone / static GetInstance )
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
	//                                Attributs/Propri�t�s                                
	//------------------------------------------------------------------------------------//

	//Attribut : La Fen�tre 
	SDL_Window* fenetre;
	//Attribut : Le Rendu
	SDL_Renderer* rendu;

	//Attribut : Le Moteur est-il en cours d'ex�cution ?
	bool running;

public:
	//                                 METHODES INTERNES                                 //
	//-----------------------------------------------------------------------------------//
	//                                 Accesseurs/Getters                                 
	//-----------------------------------------------------------------------------------//

	//Getter : Retourne le Rendu
	inline SDL_Renderer* get_rendu() { return rendu; }
	//-----------------------------------------------------------------------------------//
	//                                    M�thode Is                                    
	//-----------------------------------------------------------------------------------//

	//M�thode Is : Retourne True si le Moteur est en cours d'ex�cution
	inline bool is_running() const { return running; }
	//-----------------------------------------------------------------------------------//
	//                                 M�thodes Statiques                                 
	//-----------------------------------------------------------------------------------//

	//M�thode Statique : Retourne l'instance Moteur si elle existe, sinon en cr�e une.
	static Moteur* get_instance() { return instance = (instance != nullptr) ? instance : new Moteur(); }
	//-----------------------------------------------------------------------------------//
	//                                      M�thodes                                      
	//-----------------------------------------------------------------------------------//
	
	//M�thode : Initialise le Moteur
	bool nettoyer();
	//M�thode : Initialise le Moteur
	void quitter();
	//M�thode : Initialise le Moteur
	void evenement();
	//M�thode : Initialise le Moteur
	void traitement();
	//M�thode : Initialise le Moteur
	void affichage();

protected:
	//                                 METHODES INTERNES                                 //
	//-----------------------------------------------------------------------------------//
	//                                      M�thodes                                      
	//-----------------------------------------------------------------------------------//

	//M�thode : Initialise le Moteur
	bool initialiser();
};

#endif // !__MOTEUR_HPP__
