# Smurf-Hill

This game has been developed for a school project. This is a one player game based on a survival game. You have a Smurf community who has to survive against the enemies and find resources to feed and treat each Smurf.

Feel free to contribute or discuss the game.

## Contents

  * [Installation][Installation]
  * [Requirements][Requirements]
  * [Gameplay][Gameplay]
    * [Village][Village]
    * [Forests][Forests]
    * [Persos][Persos]
      * [NicePerso][NicePerso]
      * [MadPerso][MadPerso]
      * [NonPlayerPerso][NonPlayerPerso]
    * [Sceenshots][Screenshots]
  * [Team][Team]
  
## Install & Play

* Open QtCreator
* New Project
* In "Import Project" choose Git clone
* In Repository add : ```https://github.com/Alexia14/SmurfHill.git```
* Continue
* Run

## Requirements 

* Qt (>= 5.2) [(Install)][Qt]
* Qt multimedia

## Gameplay

The aim of the game is to survive in a world full of dangerous enemies.<br/>
At the very beginning of the game, you are near the Smurf Village. The Smurf village is composed of Smurfs’ houses and some characters. The main characters of the village are Papa Smurf, Smurfette, Farmer Smurf, Baker Smurf, Hefty Smurf, Doctor Smurf and Brainy Smurf. These characters are called the NonPlayerPerso, they help you as much as they can.<br/>
Around the village are some Smurfs, they are named NicePerso. These Smurfs can move on the map to find resources for the village. But be careful, enemies are hidden in the forests to prevent you from catching some wheat, berries and acorn.

### Village

The village is placed in the middle of the map. This area is a safe and pleasant place to live for the Smurfs. In it you’ll find the Smurf’s houses and some characters:
-	Papa Smurf is the leader of the village. His role is to give you some advice about the game.
-	Smurfette is the narrator.
-	Musician Smurf is a great musician playing the Smurf generic.
-	Brainy Smurf is annoying but he will inform you about the level of Farmer, Baker and Hefty. Beside this, he gives you each one’s features.
Farmer Smurf, Baker Smurf and Hefty Smurf are called NonPlayerPerso.

### Forests

The Smurf village is hidden in the forest so that Gargamel can’t find the Smurfs. All around the village, you’ll find forests in which are hidden resources and enemies.
There are 4 different types of resources:
-	Wheat which is used to make bread
-	Berries useful to feed and treat injured Smurfs
-	Acorns also used as a treatment
-	Sarsaparillas considered as a money

### Persos

#### NicePerso

The Smurf community is composed of NicePerso. These characters will move on the map to the point you clicked. If they go through a resource, the Smurf will pick it up and add it to the inventory of the village.<br/>
Going into a forest is dangerous because of the MadPerso. Fighting a MadPerso will give you 100 points for the score but the Smurfs will lose living points. You will need to feed them thanks to Doctor Smurf.

#### MadPerso

As in every world, enemies are there to make the game more difficult. The enemies are placed at every strategic point such as on a crossroad or at each forest entrance.<br/>
Each enemy has living and damage points. Each fight between NicePerso and MadPerso will cause point loose. As soon as the NicePerso is done fighting and wins, he can keep going but a new MadPerso will reappear after 30 seconds.

#### NonPlayerPerso

Farmer Smurf, Baker Smurf, Hefty Smurf and Doctor Smurf are called the NonPlayerPerso. Each one has specific skills:
-	Farmer Smurf has fields to harvest. He will give you some wheat.
-	Baker Smurf is the baker of the village. Thanks to the wheat you collected or the one Farmer harvested, Baker can cook bread for the community.
-	Hefty Smurf is the strongest Smurf. He is the best one to train the NicePerso to become stronger. Thanks to him, to can get new NicePerso to send them explore the forests and fight against the enemies. Improving Hefty will allow the new NicePerso to have more living and damage points.
-	Doctor Smurf is the doctor. Using food will treat the injure NicePerso.

### Sceenshots

## Team

- Alexia Couton (Save, Decor, Translations)
- Victor Fauquembergue (MVC, Perso, GameLoop, Resource)

[Installation]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#install--play
[Qt]: https://www.qt.io/download
[Requirements]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#requirements
[Gameplay]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#gameplay
[Village]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#village
[Forests]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#forests
[Persos]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#persos
[NicePerso]: https://github.com/Alexia14/Smurf-Hill//blob/master/README.md#niceperso
[MadPerso]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#madperso
[NonPlayerPerso]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#nonplayerperso
[Screenshots]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#screenshots
[Team]: https://github.com/Alexia14/Smurf-Hill/blob/master/README.md#team-
