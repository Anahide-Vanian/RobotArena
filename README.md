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
Parmi les Bonus, 3 améliorations sont possibles. Le robot peut se soigner, c'est à dire augmenter ses points de vie en attrapant des boites "Health" (en forme de coeur). Il peut augmenter sa rapidité en attrapant des boites "Speed" (en forme d'éclair). Enfin, en attrappant des boites en forme "Attack" (en forme d'épée), il peut augmenter ses points d'attaque, c'est à dire enlever plus de points de vie de son adversaire lors d'une attaque future.
Au début du jeu, par défaut, tous les joueurs ont 5 points d'attaque, X points de vie et X points de rapidité.
La relation type de boîte et points associé est la suivante:
1 boite vie attrapé apporte 15 points
1 boite d'attaque attrapé apporte 1 point
1 boite de vitesse 

- Les boites "ARME":
Parmi les Armes, 2 sont disponibles. Le robot peut tirer des balles en attrapant un pistolet, c'est à dire des boites "Gun". Il peut aussi avoir des lasers en attrapant des boites "Laser". Le joueur ne peut pas avoir plus d'une arme à disposition.

2) Comment jouer ? /Commandes
Une fois le jeu lancé, les deux personnages peuvent se déplacer dans l'environnement grâce aux touches du clavier en translatant vers le haut, le bas, vers la gauche et la droite. Pour tirer et attaquer l'adversaire, une touche suplémentaire et unique à chaque joueurs doit être enfoncée. Voici la correspondance touches/fonctionnalités pour nos 2 joueurs:
Touches du joueur 1:
Touche "Z" : Translation à droite
Touche "Q" : Translation à gauche
Touche "S" : Translation vers le haut 
Touche "D" : Translation vers le bas
Touche "E" : Tir de projectiles

Touches du joueur 2:
Touche "M" : Translation à droite
Touche "K" : Translation à gauche
Touche "O" : Translation vers le haut 
Touche "L" : Translation vers le bas
Touche "P" : Tir de projectiles

Si un joueur veut tirer, la direction du tir est le même que celui de son déplacement. Ainsi, si le joueur se déplace vers le haut et appuie sur le bouton correspondant au tir, alors il tirera vers le haut.

3) Fin du jeu
Le jeu se termine lorsqu'aucun point de vie ne reste chez l'un des joueurs, alors le joueur adverse remporte la victoire. 


— Un commentaire sur comment votre programme est conçu, ce que vous avez fait,
ce qui ne marche pas, et ce qui vous parait intéressant (i.e. ce que vous avez envie
que votre correcteur regarde) dans votre implémentation.

Notre programme respecte les consignes de l'énoncé concernant la programmation objet. Nous utilisons des classes abstraites pour avoir usage au polymorphisme. De même notre programme dispose de différentes classes dérivant d'autres.Ce qui nous parait intéressant est que nous avons utilisé le design pattern du Visiteur pour structurer notre méthode de programmation. Ainsi, nous avons dissocié l'affichage graphique de la logique du jeu. Par ailleurs, notre jeu est plutôt riche car elle utilise plusieurs fonctionnalités fournies par la bibliothèque SFML tel que l'affichage de texte ou l'usage de sprites. 

Nous aurions voulu aller plus loin dans le jeu en le décomposant en 2 parties. Une première ou les 2 joueurs se déplacent et collectent des boites pour s'améliorer et s'armer avec une durée limitée (timer). Puis une deuxième ou ils se battent dans une arene jusqu'a ce que l'un gagne. 
Par manque de temps, nous avons fait un mixte des deux.
Concernant le coeur de notre code, nous n'avons pas pu régler certains problèmes provoquant de la fuite mémoire malgré la mise en place de delete la ou il nous semblait judicieux.


— Une explication de votre organisation au sein du binôme (qui a fait quoi, comment
vous avez travaillé ensemble, etc.)

Concevoir notre jeu nous a pris du temps et l'organisation ainsi que la communication nous ont été fondamental pour parvenir à produire un résultat. Pendant une première phase, nous avons décidé de nous laisser du temps pour s'amuser à coder des choses simples avec les fonctionnalités de SFML tel que l'affichage d'une fenêtre, de formes simples dans celle-ci, etc. pour se familiariser avec l'outil. 
Puis,dans une deuxième phase nous avons décidé de se départager les tâches en codant chacun de notre côté certaines classes ou fonctions nécessaires au jeu puis de les mettre en commun. Par exemple, au débu,  Benjamin s'est occupé de gérer les collisions des joueurs avec l'environnement et les obstacles et Anahide s'est occupé de gérer l'affichage aléatoires d'objets dans l'arene de jeu. 
A l'approche de la date de rendu, nous avons décidé de coder sur un seul ordinateur afin d'éviter le temps perdu lors de la mise en commun et gagner en efficacité. 
Pour l'organisation, nous avons régulièrement fait des appels sur Discord pour communiquer, se partager nos écrans, débattre et coder.
Nous avons régulièrement veillez à nous demander nos disponibilités l'un à l'autre afin de pouvoir effectuer nos réunions.
Nous sommes contents du résultat malgré le peu de temps que nous y avions consacré par soucis de disponibilié.

