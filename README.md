# GB(C) Dumper

Fork du projet "arduinogbdump" ( Auteur : Andrew Clark (FL4SHK) - https://github.com/fl4shk/arduinogbdump ), GB(C) Dumper vous permettra de récupérer les ROM/données de vos cartouches GameBoy & GameBoy Color.

Voici la liste des éléments **requis** : un Arduino **compatible**, une manette **officielle** N64, un Transfer Pak N64 et une résistance pull-up.

## Modifications appliquées
- Logiciel : Nettoyage du code & Correction des bugs  sur la détection & la lecture
- Firmware : Updated project structure & optimisation 

## Caractéristiques

Vous pouvez récupérer les données "ROM" des cartouches suivantes : ROM Only (32 kiB), MBC1, MBC2, MBC3, MBC5 (*quasiment* complète, mais pas au delà de 4 MiB).

Vous pouvez récupérer les données "ROM" des cartouches suivantes : MBC1, MBC2, MBC3 (support RTC non supporté),  MBC5.

Le logiciel a été testé sous Linux ( [Fenikkusu](https://jackobo.info/?datas=fenikkusu) / Debian ). Vous pouvez essayer de le compiler et de l'utiliser sur les autres systèmes Unix (tel que FreeBSD).

## Comment connecter la manette N64 sur la carte Arduino

![alt text](https://github.com/JackoboLeChocobo/GB_GBC_Dumper/blob/main/schematics/arduino_mega_2560.png?raw=true)

## Liste des cartes Arduino compatibles

12 Septembre 2024 : Testé avec succès sur Arduino Mega 2560 R3 

## Remerciements

- [Andrew Clark (FL4SHK)](https://github.com/fl4shk/arduinogbdump) 
- [brownan](https://github.com/brownan/Gamecube-N64-Controller)
