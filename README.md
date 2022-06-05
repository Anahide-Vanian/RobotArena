# RobotArena
Created by Benjamin Tieu and Anahide Silahli



— La liste des bibliothèques, framework et outils externes que nous avons utilisés:
 Pour le graphisme, la dernière version de la bibliothèque SFML à été utilisé et installé.
 
— Les instructions sur comment compiler notre programme:

Pour compiler notre programme, il faut se rendre dans le dossier contenant le code source et le Makefile. Ouvrir un terminal dans ce chemin et taper "make", le programme sera compilé. Puis pour l'exécuter taper: "./jeu". Alors, la fenêtre de jeu devrait apparaitre.

— Un rapide manuel d’utilisation de votre jeu (but, comment jouer, commandes, etc.):
Notre jeu se nomme "RobotArena", il s'agit d'un jeu de combat multijoueur. 
Le principe est le suivant: 2 joueurs (2 robots) se déplacent et se battent dans un environnement contenant des obstacles (maisons) et des boites cadeaux. Le but est de collecter le maximum de boites afin d'avoir plus d'armes en possession et attaquer le joueur adverse tout en apportant des améliorations et avantages à son propre robot. 
Il existe 2 types de boîtes dans l'environnement, des boîtes dites "Bonus" ou des boites dites "Arme".

- Les boites "BONUS": 
Parmi les Bonus, 3 améliorations sont possibles. Le robot peut se soigner, c'est à dire augmenter ses points de vie en attrapant des boites 'Health" (en forme de coeur). Il peut augmenter sa rapidité en attrapant des boites "Spees" (en forme d'éclair). Enfin, en attrappant des boites en forme "Attack" (en forme d'épée), il peut augmenter ses points d'attaque, c'est à dire enlever plus de points de vie de son adversaire lors d'une attaque future.
Au début du jeu, par défaut, tous les joueurs ont 5 points d'attaque, X points de vie et X points de rapidité.
1 boite vie attrapé apporte 15 points
1 boite d'attaque attrapé apporte 1 point
1 boite de vitesse 

- Les boites "ARME":

— Un commentaire sur comment votre programme est conçu, ce que vous avez fait,
ce qui ne marche pas, et ce qui vous parait intéressant (i.e. ce que vous avez envie
que votre correcteur regarde) dans votre implémentation.
— Une explication de votre organisation au sein du binôme (qui a fait quoi, comment
vous avez travaillé ensemble, etc.)
