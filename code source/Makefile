CPP=g++
LD=g++



CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -fconcepts
EXES=jeu

all: $(EXES)

jeu: main.o Renderer.o Game.o Player.o Environment.o DynamicObject.o Arme.o Laser.o Gun.o Bonus.o Speed.o Health.o Attack.o Projectile.o
	$(LD) $(LDFLAGS)  main.o Renderer.o Game.o Player.o Environment.o DynamicObject.o Arme.o Laser.o Gun.o Bonus.o Speed.o Health.o Attack.o Projectile.o -o jeu $(LIBS)

main.o: main.cpp Player.hpp Environment.hpp Laser.o Renderer.hpp Projectile.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

DynamicObject.o: DynamicObject.cpp DynamicObject.hpp Object.hpp
	$(CPP) $(CPPFLAGS) -c DynamicObject.cpp

Arme.o: Arme.cpp Arme.hpp Object.hpp
	$(CPP) $(CPPFLAGS) -c Arme.cpp

Bonus.o: Bonus.cpp Bonus.hpp Object.hpp
	$(CPP) $(CPPFLAGS) -c Bonus.cpp

Player.o: Player.cpp Player.hpp DynamicObject.hpp Object.hpp Projectile.hpp
	$(CPP) $(CPPFLAGS) -c Player.cpp

Projectile.o: Projectile.cpp Projectile.hpp DynamicObject.hpp Object.hpp Player.hpp
	$(CPP) $(CPPFLAGS) -c Projectile.cpp

Environment.o: Environment.cpp Environment.hpp Object.hpp
	$(CPP) $(CPPFLAGS) -c Environment.cpp

Laser.o: Laser.cpp Laser.hpp Arme.hpp Object.hpp
		$(CPP) $(CPPFLAGS) -c Laser.cpp

Gun.o: Gun.cpp Gun.hpp Arme.hpp Object.hpp
		$(CPP) $(CPPFLAGS) -c Gun.cpp

Health.o: Health.cpp Health.hpp Bonus.hpp Object.hpp
		$(CPP) $(CPPFLAGS) -c Health.cpp

Speed.o: Speed.cpp Speed.hpp Bonus.hpp Object.hpp
		$(CPP) $(CPPFLAGS) -c Speed.cpp

Attack.o: Attack.cpp Attack.hpp Bonus.hpp Object.hpp
		$(CPP) $(CPPFLAGS) -c Attack.cpp

Renderer.o: Renderer.cpp Player.hpp Environment.hpp Laser.hpp Gun.hpp Speed.hpp Health.hpp Attack.hpp Renderer.hpp Projectile.hpp
	$(CPP) $(CPPFLAGS) -c Renderer.cpp

Game.o: Game.cpp Game.hpp Object.hpp Renderer.hpp Player.hpp Environment.hpp DynamicObject.hpp Laser.hpp Gun.hpp Speed.hpp Health.hpp Attack.hpp Projectile.hpp
	$(CPP) $(CPPFLAGS) -c Game.cpp

clean:
	rm -f *.o $(EXES)
