# COREWAR
Projet de l ecole 42 qui a pour but de faire affronter des programmes .cor dans une machine virtuelle 
   Fin du jeu : plus de processus en vie
   Gagnant dernier qui a fait live (avec affichage du gagnant)
   4 champions max le dernier joue en premier sauf indication contraire
## 3 Parties:
 ### Executable ASM
 ```
     transforme un programme en assembleur (fichier .s-> fichier .cor)
 ```
 ### Machine Virtuelle
 #### Arene {CYCLE_TO_DIE, NBR_LIVE, CYCLE_DELTA, MEMSIZE, MAX_CHECK, CHAMP_MAX_SIZE, CYCLE}
 ##### CYCLE_TO_DIE: Periode de temps sur laquelle on verifie qu un live a ete execute. 
 #####   NBR_LIVE:Mort subite(NBR_LIVE a partir du moment ou il y a eu au moins NBR_LIVE on reduit le cycle to die)
 #####  CYCLE_DELTA: La variation de cycle to die(accelerateur de jeu)
 #####   MEM_SIZE: taille de l arene
 #####    MAX_CHECK: Nombre max de CYCLE_TO_DIE effectues sans cumul des lives > NBR_LIVE
 #####    CHAMP_MAX_SIZE : taille limite d un champion
 #####    CYCLE: Definis dans OP.c pour chaque instruction
 ```
 Sert d arene pour les fichier .cor (possibilite de multiple executable sur la machine)
   les champions sont equidistants.
 ```
 #### Processus {REG_NUMBER, REG_SIZE, PC, CARRY}

   ##### REG_NUMBER: Nombre de registres par processus,   
   ###### REGISTRE: Definis par processus, VALEURE ACCESSIBLE RAPIDEMENT
   ##### REG_SIZE: Taille d un processus en octet,
   ##### PC :codé sur 2 octets, qui compte le nombre de case entre l'instruction courante, et le point de depart du      programme.Il designe donc la postion de l'instruction courante par rapport au point d'adressage effectif.
   ##### CARRY: Un flag nommé carry, qui vaut 1 si la dernière opération a réussi. Seules certaines opérations vont modifier le carry
  ```
  sont des valeurs definies pour chaque processus(un champion est au depart un seul processus qui peut se "fork"), tous les processus subissent de facon egale les contraintes de l arene.
  ``` 
 ### Champion
      ```
    les 139 premieres lignes correspondent au header dans le .cor (affichage a regarder).
      ```
