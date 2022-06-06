# RobotArena
Created by Benjamin Tieu and Anahide Silahli



— La liste des bibliothèques, framework et outils externes que nous avons utilisés:
 Pour le graphisme, la dernière version de la bibliothèque SFML à été utilisé et installé.
 
— Les instructions sur comment compiler notre programme:

Pour compiler notre programme, il faut se rendre dans le dossier contenant le code source et le Makefile. Ouvrir un terminal dans ce chemin et taper "make", le programme sera compilé. Puis pour l'exécuter taper: "./jeu". Alors, la fenêtre de jeu devrait apparaitre.

— Un rapide manuel d’utilisation de votre jeu (but, comment jouer, commandes, etc.):

A noter que la taille de la fenêtre de jeu est définis à 1600 x 900 pixels. (il faut une résolution d'écran suffisant pour voir le jeu en entier) 

1) Principe et explications
Notre jeu se nomme "RobotArena", il s'agit d'un jeu de combat multijoueur. 
Le principe est le suivant: 2 joueurs (2 robots) se déplacent et se battent dans un environnement contenant des obstacles (maisons) et des boites cadeaux. 
Le but est de détruire le robot adverse en faisant baissé ces points de vie à 0.
Pour renforcer sont propre robot, le joueur peut collecter des armes et des Bonus présent dans des "boîtes". 
Les Bonus peuvent améliorer son robot, et ainsi donner un avantage (plus de vie, de dégat, plus de vitesse) 

Il existe 2 types de boîtes dans l'environnement, des boîtes dites "Bonus" ou des boites dites "Arme".

- Les boites "BONUS": Les bonus apportent des améliorations sur les robots. Ils augmentent leur attributs d'attaque , de vitesse ou de point de vie.
Parmi les Bonus, 3 améliorations sont possibles. 
1) Bonus Health : (en attrapant des boites en forme de coeur) Le robot peut se soigner en regagnant 15 points de vie et augmenter sont nombre de points de vie maximum de 15. 
2) Bonus Speed : (en attrapant des boites en forme d'éclair) Le robot augmentee sa vitesse de déplacement de 1.  
3) Bonus Attack : (en attrappant des boites en forme d'épée) Le robot augmente ses points d'attaque de 1, cela augmente les dégats des armes utiliser par le robot. 

- Les boites "ARME":
Parmi les Armes, 2 sont disponibles. 
1) Le gun :  Le robot peut tirer des balles en attrapant un pistolet, c'est à dire des boites "Gun". (il tire des balles bleu géante) 
(attraper une boite avec un revolver donne 12 de munition pour le gun)
Le gun dispose d'un "shoottimer" qui correspond a un délai entre chaque tir pour éviter de tirer trop vite.
Les balles du gun ne traverse pas les obstacles et sont détruis s'il touche les bords de l'écran ou le décor (maison) 
Les tires se font dans les 4 directions haut, bas, gauche , droite.

2) Le laser : Il peut aussi avoir des lasers en attrapant des boites "Laser".   [le tire du faisceau laser n'a malheuresement pas été implémenté] 
(attraper une boite avec un laser donne 3 de munitions pour le laser)

Au début du jeu, 4 Bonus de chaque catégorie (attaque, vitesse, PV) et 3 armes de chaque catégorie apparaisse (gun et laser)
apparaissent à des emplacement aléatoire sur le terrain de jeu.
Par la suite du jeu après 20 secondes, de nouvelles boites (arme et bonus) réapparaisse. 
Par défaut, Le joueurs apparait avec aucune arme et ne peut donc pas tirer ou attaquer (il doit donc attraper des boites gun pour se défendre) 
Tous les joueurs ont au départ 10 points d'attaque, 150 points de vie et 8 points de vitesse.

2) Comment jouer ? /Commandes
Une fois le jeu lancé, les deux personnages robots apparaissent, le joueur 1 est tout en haut à gauche, et le joueur 2 tout en bas à droite
Les robots peuvent se déplacer dans l'environnement grâce aux touches du clavier en translatant vers le haut, le bas, vers la gauche et la droite. 
Pour tirer et attaquer l'adversaire, une touche suplémentaire et unique à chaque joueurs doit être enfoncée. Voici la correspondance touches/fonctionnalités pour nos 2 joueurs:
Touches du joueur 1:
Touche "Z" : Translation vers le haut
Touche "Q" : Translation vers la gauche
Touche "S" : Translation vers le bas 
Touche "D" : Translation vers la droite
Touche "E" : Tir de projectiles (gun)

Touches du joueur 2:
Touche "M" : Translation à droite
Touche "K" : Translation à gauche
Touche "O" : Translation vers le haut 
Touche "L" : Translation vers le bas
Touche "P" : Tir de projectiles (gun)

Si un joueur veut tirer, la direction du tir est le même que celui de son précédent déplacement. Ainsi, si le joueur se déplace vers le haut et appuie sur le bouton correspondant au tir, alors il tirera vers le haut.

3) Fin du jeu
Le jeu se termine lorsqu'aucun point de vie ne reste chez l'un des joueurs, alors le joueur adverse remporte la victoire. 
Le message "Game over" apparait. 

— Un commentaire sur comment votre programme est conçu, ce que vous avez fait,
ce qui ne marche pas, et ce qui vous parait intéressant (i.e. ce que vous avez envie
que votre correcteur regarde) dans votre implémentation.

Notre programme respecte les consignes de l'énoncé concernant la programmation objet. Nous utilisons des classes abstraites pour avoir usage au polymorphisme.
De même notre programme dispose de différentes classes dérivant d'autres.Ce qui nous parait intéressant est que nous avons utilisé le design pattern du Visiteur
pour structurer notre méthode de programmation. Ainsi, nous avons dissocié l'affichage graphique de la logique du jeu. Par ailleurs, notre jeu est plutôt riche car
elle utilise plusieurs fonctionnalités fournies par la bibliothèque SFML tel que l'affichage de texte ou l'usage de sprites. 

Concernant le coeur de notre code, nous n'avons pas pu régler certains problèmes provoquant de la fuite mémoire malgré la mise en place de delete la ou il nous semblait judicieux.


— Une explication de votre organisation au sein du binôme (qui a fait quoi, comment
vous avez travaillé ensemble, etc.)

Concevoir notre jeu nous a pris du temps et l'organisation ainsi que la communication nous ont été fondamental pour parvenir à produire un résultat. 
Pendant une première phase, nous avons décidé de nous laisser du temps pour s'amuser à coder des choses simples avec les fonctionnalités de SFML tel que l'affichage d'une fenêtre, de formes simples dans celle-ci, etc. pour se familiariser avec l'outil. 
Puis,dans une deuxième phase nous avons décidé de se départager les tâches en codant chacun de notre côté certaines classes ou fonctions nécessaires au jeu puis de les mettre en commun. 
Par exemple, au débu,  Benjamin s'est occupé de gérer les collisions des joueurs avec l'environnement et les obstacles et Anahide s'est occupé de gérer l'affichage aléatoires d'objets dans l'arene de jeu. 
A l'approche de la date de rendu, nous avons décidé de coder sur un seul ordinateur afin d'éviter le temps perdu lors de la mise en commun et gagner en efficacité. 
Pour l'organisation, nous avons régulièrement fait des appels sur Discord pour communiquer, se partager nos écrans, débattre et coder.
Nous avons régulièrement veillez à nous demander nos disponibilités l'un à l'autre afin de pouvoir effectuer nos réunions.
Nous sommes contents du résultat malgré le peu de temps que nous y avions consacré par soucis de disponibilié.


