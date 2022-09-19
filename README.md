# SimulationBanque

## Compilation du Programme
Pour compiler le programme, on peut utiliser cette liste de commande.

* **-make / make all** : Cette commande permet de compiler et construire le programme sous le nom: **simulationBank.out**
     
* **-make simule** : Execute un exemple de la simulation avec les paramètres par défaut.
     
* **-make clean_o** : Supprime tous les fichiers .o générés lors de la compilation.
* **-make clean**: Supprime tous les fichiers .o générés lors de la compilation et l'executable.
* **-make doxygene**: Génère une documentation du programme en doxygène.


## Démarrage du Programme
Une fois que la compilation est finie, un exécutable simulationBank va être généré.
Pour lancer l'éxecutable on peut soit le lancer avec des des arguments ou sans argument. 
 -h: (help) permet d'avoir de l'aide sur les arguments à utiliser. 

La liste d'arguments sont:
* **-c**: qui reçoit un int pour le nombre de cashier. 
* **-s**: qui reçoit un int pour la durée totale de simulation. 
* **-t**: qui reçoit un int ou double pour le temps entre les arrivées. 
* **-a**: qui reçoit un int ou double pour le temps moyen de service. 



## Exemple de Programme

~~~
./simulationBank.out -c 3 -s 200 -t 2 -a 3
~~~
<h3> Résultats de la simulation</h3>

~~~
-----------Statistiques de fin de simulation----------------

Temps attendue de la simulation : 200s
Temps reel de la simulation : 125.394s
Temps d'attente moyen dans la file d'attente : 1.71051s
Taille moyenne de la file d'attente : 1.06017
Taille maximale de la file d'attente : 3
Cashier ID 0 : Taux d'occupation = 30.2606% du temps total et nombre client servis = 21
Cashier ID 1 : Taux d'occupation = 36.6985% du temps total et nombre client servis = 18
Cashier ID 2 : Taux d'occupation = 26.706% du temps total et nombre client servis = 26
Fin simulation : 125.394s

~~~