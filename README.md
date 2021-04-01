# 2020_2021_DERGICI_LOISON

## Projet Capteur - liste des livrables

- [x] KiCAD PCB shield: transimpedance amplifier, BT module, OLED screen
- [x] Code Arduino: mesure jauge contrainte & contrôle communication BT/affichage sur l'OLED
- [] APK Android interface sur MIT App Inventor: évolution de la valeur de la résistance
- [] Datasheet du capteur jauge contrainte
- [] Protocole du banc test


## Livrable 1 - KiCAD PCB shield
- le PCB simple face 


## Livrale 2 - Code Arduino
- le code Arduino permet la communication avec le téléphone portable (réception et envoi de données sous forme de bit)
- il transforme la valeur en ADC en valeur de résistance, selon l'équation du circuit établie
- il gère aussi l'affichage des valeurs de résistance sur l'OLED pendant la mesure, et gère l'arrêt de mesure avec l'affichage de l'écran d'accueil sur l'OLED


## Livrable 3 - APK Android interface
- L'application nommée "Capteur_Graphite_SDML" se connecte par bluetooth au capteur 
- L'état de la connexion s'affiche ainsi que le nom de l'appareil connecté
- Mesure la valeur de la résistance selon la déformation appliquée sur le capteur et l'affiche
- Trace le graphique en temps réel des valeurs d'ADC mesurées (choix de l'ADC et non de la résistance pour le graph. car l'ADC varie moins fortement que la résistance)
- Les données sont sauvegardées sous le nom entré par l'utilisateur et accessibles depuis le téléphone 
- L'arrêt de la mesure est annoncé par l'application (déclenche un message vocal)


