# corewar
## 3 Parties:
    1) Executable ASM
      transforme un programme en assembleur (fichier .s-> fichier .cor)
    2) Machine Virtuelle
    {REG_NUMBER
    REG_SIZE}
    Donnees globales sont definies dans le .H et sont globaux
    {PC
    carry}
    sont des valeurs definies pour chaque processus(un champion est au depart un seul processus qui peut se "fork").
    Sert d arene pour les fichier .cor (possibilite de multiple executable sur la machine)
    les champions sont equidistants.
    CYCLE_TO_DIE: Periode de temps sur laquelle on verifie qu un live a ete execute. 
    NBR_LIVE:Mort subite(NBR_LIVE a partir du moment ou il y a eu au moins NBR_LIVE on reduit le cycle to die)
    CYCLE_DELTA: La variation de cycle to die(accelerateur de jeu)
    MEM_SIZE: taille de l arene
    MAX_CHECK: Nombre max de CYCLE_TO_DIE effectues sans cumul des lives > NBR_LIVE
    CHAMP_MAX_SIZE : taille limite d un champion
    CYCLE: Definis dans OP.c pour chaque instruction
    REGISTRE: Definis par processus
    Fin du jeu : plus de processus en vie
    Gagnant dernier qui a fait live (avec affichage
    
    4 champions max le dernier joue en premier
    3) Champion
    les 139 premieres lignes correspondent au header dans le .cor (affichage a regarder).
    
