/*Write a program that uses composition to implement a game engine. A game engine is madeup of
several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logicforhow these individual components work.*/

#include<iostream> 
#include<string>
using namespace std ;

class graphicsEngine{
public:
void render(){
    cout<<"rendering graphics engine..."<<endl;

}
};

class physicsEngine{
public:
   void updatephysics(){
    cout<<"updating physics engine..."<< endl;

   }
};

class inputHandler{
public:
   void handlinginput(){
    cout<<"handling input..."<<endl;
   }
};


class gameEngine{
graphicsEngine graphics;
physicsEngine physics;
inputHandler input;
public:
void rungame(){
    input.handlinginput();
    graphics.render();
    physics.updatephysics();
   
    cout <<"game loop completed ! "<<endl;

}


};

int main (){
    gameEngine game1;
    game1.rungame();
    return 0;
}
