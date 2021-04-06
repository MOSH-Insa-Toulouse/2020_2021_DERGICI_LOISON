# 2020_2021_DERGICI_LOISON

## Description 
Projet Capteur 2020/2021: design et fabrication d'un PCB shield comprenant une jauge de contrainte à base de graphite, couplée à un circuit analogique qui communique, via un microcontrôleur, avec une application Android 
 
## Projet Capteur - liste des livrables

- [x] KiCAD PCB shield: transimpedance amplifier, BT module, OLED screen
- [x] Code Arduino: mesure jauge contrainte & contrôle communication BT/affichage sur l'OLED
- [x] APK Android interface sur MIT App Inventor: évolution de la valeur de la résistance
- [] Datasheet du capteur jauge contrainte
- [] Protocole du banc test


## Livrable 1 - KiCAD PCB shield
- le PCB simple face 


## Livrale 2 - Code Arduino
- le code Arduino permet la communication avec le téléphone portable (réception et envoi de données sous forme de bit), sur la base d'une machine à états il gère ensuite les différents cas de figure possibles
- il transforme la valeur en ADC en valeur de résistance, selon l'équation du circuit établie
- il gère aussi l'affichage des valeurs de résistance sur l'OLED pendant la mesure, et gère l'arrêt de mesure avec l'affichage de l'écran d'accueil sur l'OLED


## Livrable 3 - APK Android interface
# Notre application: Capteur_Graphite_SDML
- L'application nommée "Capteur_Graphite_SDML" se connecte par bluetooth au capteur 
- L'état de la connexion s'affiche ainsi que le nom de l'appareil connecté
- Mesure la valeur de la résistance selon la déformation appliquée sur le capteur et l'affiche
- Trace le graphique en temps réel des valeurs d'ADC mesurées (choix de l'ADC et non de la résistance pour le graph. car l'ADC varie moins fortement que la résistance)
- Les données sont sauvegardées sous le nom entré par l'utilisateur et accessibles depuis le téléphone 
- L'arrêt de la mesure est annoncé par l'application (déclenche un message vocal)
# Lien de téléchargement de l'application
# Interface de Capteur_Graphite_SDML

## Livrable 4 - Datacheet du capteur jauge contrainte 

## Livrable 5 - Protocole du banc de test
On utilise un banc de test demi-circulaire des portions de différents rayons. Les rayons sont compris entre 1 cm et 2.5 cm avec un intervalle de 0.25cm. Chaque rayon correspond à un rayon de courbure que l'on calcul et engendre une déformation sur le capteur graphite. Le capteur peut être placé de sorte a ce que la déformation soit effectuée de l'intérieur ou de l'extérieur. Une petite fente présente a chaque début de courbure permet de coincer l'extrémité du capteur ne possédant pas les pinces crocodiles, ce qui permet d'avoir une mesure fixe par rapport au bon rayon de courbure. Le capteur doit bien épouser la surface du banc de test afin d'avoir la valeur de la résistance souhaitée.
À chaque test, les données (la clock, la valeur de la résistance et la valeur de l'ADC) sont enregistrées dans un fichier texte sur le téléphone nommé de ce type "myFile_typeCrayon_rayon.txt".
Une fois tous les tests effectués selon les différents rayons de courbure et selon le type de crayon choisi, les données sont traitées.

## Pistes d'améliorations possibles
- Le banc de test peut être améliorer. Le capteur se détériore rapidement ce qui parfois ne permet pas de faire les tests suivant toutes les différentes coubures et ainsi engendre des erreurs. Afin d'avoir des résultats de tests analysables il faut utiliser ce même capteur pour les différentes courbures et sans rajouter de graphite. Néanmoins avec les frottements la piste de graphite et la pince crocodile, il y a une perte de graphite. Un banc de test avec la partie supérieur du capteur (artie de contact avec les pinces crocodiles) immobile serait plus judicieux.
On observe une faible reproductibilité des expériences, chaque capteur est unique même en utilisant le même type de crayon. En effet, tout dépend de la quantité de graphite que l'on dépose sur le capteur. Il est rare de retrouver les même valeurs de résistance pour un même crayon.  
- Dans notre cas, nous avons eu des difficultés a détecter les valeurs de résistance des crayons du type H. Leur résistance est trop grande, pour mieux les détecter il faudrait mettre des résistances en parrallèle. 
