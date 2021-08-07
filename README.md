# Ratata
Object-Oriented platform game by:\
Bar Ifrah\
Sharon Levi\
Oren Holtzman
## About
#### This is a story of 'Hulda', a Tel-Avivian sewer rat.
Being kicked out of her home due to Metro train construction in Tel Aviv, Hulda went out on the streets,\
looking for food to survive. But, there are many dangers in the city, such as: getting run over by a scooter,\
eating poison and having the city exterminator on your tail.\
To survive- Hulda needs:\
Hulda needs to avoid all enemies:\
![Screen Shot 2021-06-24 at 0 44 52 (2)](https://user-images.githubusercontent.com/71547715/123172253-8d391780-d485-11eb-940f-cd2525a10e5a.png)

and avoid the poisonous apples:\
<img width="159" alt="Screen Shot 2021-06-21 at 22 30 23" src="https://user-images.githubusercontent.com/71547715/122817594-c5532580-d2e0-11eb-906f-e15e614d3660.png">\

to gain powers, Hulda needs to eat some burgers!:\
<img width="160" alt="Screen Shot 2021-06-21 at 22 31 01" src="https://user-images.githubusercontent.com/71547715/122817697-eb78c580-d2e0-11eb-8e98-fe195cf0cc34.png">

to gain some points, Hulda needs to eat pizza, watermelon and bananas:\
<img width="163" alt="Screen Shot 2021-06-21 at 22 45 48" src="https://user-images.githubusercontent.com/71547715/122818976-7c03d580-d2e2-11eb-80fd-2d0cd2b59922.png">
<img width="172" alt="Screen Shot 2021-06-21 at 22 44 02" src="https://user-images.githubusercontent.com/71547715/122818987-7f975c80-d2e2-11eb-8ab2-204013790784.png">
<img width="172" alt="Screen Shot 2021-06-21 at 22 44 42" src="https://user-images.githubusercontent.com/71547715/122818988-7f975c80-d2e2-11eb-97ed-62d9d566f9d6.png">\

To move to the next level, Hulda needs to go inside the 'teleport' trash can:\
![huldaTrash](https://user-images.githubusercontent.com/71547715/123173460-4ea45c80-d487-11eb-8b22-6390ee88953b.gif)



Hulda starts with 3 lives. Every 100 points collected- hulda gets an extra life.\
Hulda can gain lives from the 'special force' burgers. no more than 6 lives can be collected.

##### Create levels:
creating new levels by editing the 'Levels.txt' file in the "resources" directory.\
level format is 20 rows height, 100 columns width. (can be seen inside 'Levels.txt' file.\
symbols are defined in "macros.h" file.
'Levels.txt' file is located in resources file



## Files and descriptions
CPP's + Headers:\
To build a game object:\
PhysicsObject.h/cpp\
GameObject.h/cpp

Static Game Objects inherit from 'StaticObject.cpp':\
Adanit.h/cpp\
Food.h/cpp\
ToxicFood.h/cpp
PortalTrash.h/cpp
Trash.h/cpp\
RegularFood.h/cpp\
SpecialFood.h/cpp\
Road.h/cpp

Dynamic Game Objects inherit from 'MovingObject.cpp'\
Enemy.h/cpp\
-Exterminator.h/cpp\
-Scooter.h/cpp\
Player.h/cpp\
DynamicFloor.h/cpp

Game controlling classes:\
Controller.h/cpp\
Stats.h/cpp\
Board.h/cpp\
DataReader.h/cpp\
Resources.h/cpp\
HighScores.h/cpp

Collision management:				
Collisions.h/cpp
Listener.h/cpp
Utilities.h/cpp
Menu.h/cpp
main.cpp
	

## Implementation:
Algorithms we used:\
A 'chaser'- the exterminator- chased Hulda in the X axis.\
std::sort from STL.

Data structures we used:\
2D vector for storing the current level objects.\
Unordered maps- in 'Resources' class- to control the resources and extract them in O(1) time complexity.\
Used unordered map to keep track of objects in the board, and assign them with unique ID's.\
Used vector of (string, int) pairs- for names and scores in 'HighScores' class.

Design Patterns:
Resources & Music - Singelton classes. \
Used MultiMethods for manage collisions between objects. 

## Compile and run:
#### With IDE's:
Import all source code to your favorite IDE (works cross platform).\
Compile and run.\

If you choose to run via CMD or Terminal:
#### Unix machines:
Go to either *Cmake-Build-Debug/Hulda* or to *out/build/x64-Debug (default)/Hulda.exe*\
Open Terminal window.\
Run:
 ```
 % ./Hulda
 ```
Enjoy!
#### Windows Machines:
Go to either *Cmake-Build-Debug/Hulda* or to *out/build/x64-Debug (default)/Hulda.exe*\
Double click Hulda.exe and play!
## GitHub Repository
https://github.com/BarIfrah/Hulda-FinalProject

## LinkedIn
[Sharon Levi](https://www.linkedin.com/in/sharon-levy-8434471a5/) \
[Bar Ifrah](https://www.linkedin.com/in/bar-ifrah-660878203/) \
[Oren Holtzman](https://www.linkedin.com/in/oren-holtzman-923b04206/)
## Credits
Game design:\
[Shaked 'Keti' Zahor (instagram)](https://www.instagram.com/shaketi___/?hl=en)

Physics:\
[Box2D](https://box2d.org) Physical engine

Graphic implementation:
[SFML](https://www.sfml-dev.org)




## Game ScreenShots:
<img width="748" alt="Screen Shot 2021-06-20 at 18 32 30" src="https://user-images.githubusercontent.com/71547715/122680019-fc004180-d1f5-11eb-9425-8f5b9ab20e2b.png">


<img width="747" alt="Screen Shot 2021-06-20 at 18 37 49" src="https://user-images.githubusercontent.com/71547715/122680185-b85a0780-d1f6-11eb-9722-e53636b1f172.png">
