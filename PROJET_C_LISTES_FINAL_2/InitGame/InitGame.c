#include "../TankEnnemis/TankEnnemis.h"

OBUSP * allocation_dyn_tab_obus(){
	return malloc(NBOBUSALLOWED * sizeof(OBUSP));
}

int * allocation_dyn_tab_repar_tank_ennemis(){
	return malloc(3 * sizeof(int));
}

void init_terminal(){
	system("clear"); // On nettoie le terminal
	system("setterm -cursor off"); // On n'affiche pas le curseur clignotant dans le terminal
	system("stty -echo"); // Ne pas afficher les lettres/codes flèches tappées dans le terminal
	
	NBOBUSALLOWED = 50; // On initialise le nombre d'obus autorisés à apparaitre à l'écran
	TabPointeursObus = allocation_dyn_tab_obus(); // Allocation dynamique du tableau de pointeurs d'obus
}

void fin_win(){
	system("clear");
	afficher_message(15, 60, "Vous avez perdu ...");
	fflush(stdout);
	system("sleep 1");
	system("setterm -cursor on");
	system("stty echo");
	system("clear");
}

void fin_game_over(){
	system("clear");
	afficher_message(15, 60, "Vous avez gagné !!");
	fflush(stdout);
	system("sleep 1");
	system("setterm -cursor on");
	system("stty echo");
	system("clear");
}

void quit_terminal(){
	system("clear");
	afficher_message(15, 60, "Vous quittez le jeu ...");
	fflush(stdout);
	system("sleep 0.8");
	system("setterm -cursor on");
	system("stty echo");
	system("clear");
}

void initialiserLaPartieSelonLeMode(){
	
	// On initialise la répartition des différents types de tanks ennemis
	repartitionTankEnnemis = allocation_dyn_tab_repar_tank_ennemis();
	
	if (mode == 11){
		// On initialise la map à afficher
		true_map = creer_charger_map(LONGUEURMAP, LARGEURMAP, PATHMAPTERMINAL);
		
		// On initialise la répartition des différents types de tanks ennemis
		repartitionTankEnnemis[0] = NBTANKWEAKFACILE; // ... 8 tanks faibles
		repartitionTankEnnemis[1] = NBTANKMEDIUMFACILE; // ... 7 tanks moyens
		repartitionTankEnnemis[2] = NBTANKSTRONGFACILE; // ... 5 tanks forts
	}
	else if (mode == 12){
		true_map = creer_charger_map(LONGUEURMAP, LARGEURMAP, PATHMAPTERMINAL);
		
		repartitionTankEnnemis[0] = NBTANKWEAKDIFFICILE; // ... 10 tanks faibles
		repartitionTankEnnemis[1] = NBTANKMEDIUMDIFFICILE; // ... 10 tanks moyens
		repartitionTankEnnemis[2] = NBTANKSTRONGDIFFICILE; // ... 10 tanks forts
		
	}
	else if (mode == 21){
		true_map = creer_charger_map(LONGUEURMAP, LARGEURMAP, PATHMAPGRAPHIQUE);
		
		repartitionTankEnnemis[0] = NBTANKWEAKFACILE;
		repartitionTankEnnemis[1] = NBTANKMEDIUMFACILE;
		repartitionTankEnnemis[2] = NBTANKSTRONGFACILE;
	}
	else if (mode == 22){
		true_map = creer_charger_map(LONGUEURMAP, LARGEURMAP, PATHMAPGRAPHIQUE);
		
		repartitionTankEnnemis[0] = NBTANKWEAKDIFFICILE;
		repartitionTankEnnemis[1] = NBTANKMEDIUMDIFFICILE;
		repartitionTankEnnemis[2] = NBTANKSTRONGDIFFICILE;
	}
}