#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define n 20

typedef struct {
    char nom[n];
    char stade[n];
    char entreneur[n];
    char country[n];
} Equipe;

typedef struct {
    int numero;
    char nom[n];
    char poste[n];
    Equipe eq;
} Player;

//saisir numbers of players
int saisir() {
    int N;
    printf("How many Players do you want: ");
    scanf("%d", &N);
    return N;
}


//affichier all players
void affichier(Player p[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Informations Sur Player Number %d: \n",i+1);
        printf("\tNumero: %d, Nom: %s, Poste: %s\n", p[i].numero, p[i].nom, p[i].poste);
        printf("\tNom de Equipe: %s, Stade de Equipe: %s, Entreneur de Equipe: %s, Country de Equipe: %s\n", p[i].eq.nom, p[i].eq.stade, p[i].eq.entreneur, p[i].eq.country);
    }
}
//affichier les attaquant
void affi_atta(Player p[], int k) {
    for (int i = 0; i < k; i++) {
        if (strcasecmp(p[i].poste, "attaque") == 0) {
            printf("Informations Sur les Players: \n");
            printf("\tNumero: %d, Nom: %s\n", p[i].numero, p[i].nom);
            printf("\tNom de Equipe: %s, Stade de Equipe: %s, Entreneur de Equipe: %s, Country de Equipe: %s\n", p[i].eq.nom, p[i].eq.stade, p[i].eq.entreneur, p[i].eq.country);
        }
    }
}

//affichier les middles
void affi_mid(Player p[], int k) {
    for (int i = 0; i < k; i++) {
        if (strcasecmp(p[i].poste, "middle") == 0) {
            printf("Informations Sur les Players: \n");
            printf("\tNumero: %d, Nom: %s\n", p[i].numero, p[i].nom);
            printf("\tNom de Equipe: %s, Stade de Equipe: %s, Entreneur de Equipe: %s, Country de Equipe: %s\n", p[i].eq.nom, p[i].eq.stade, p[i].eq.entreneur, p[i].eq.country);
        }
    }
}

//affichier les defense
void affi_defense(Player p[], int k) {
    for (int i = 0; i < k; i++) {
        if (strcasecmp(p[i].poste, "defense") == 0) {
            printf("Informations Sur les Players: \n");
            printf("\tNumero: %d, Nom: %s\n", p[i].numero, p[i].nom);
            printf("\tNom de Equipe: %s, Stade de Equipe: %s, Entreneur de Equipe: %s, Country de Equipe: %s\n", p[i].eq.nom, p[i].eq.stade, p[i].eq.entreneur, p[i].eq.country);
        }
    }
}


//afichier les gardians
void affi_gard(Player p[], int k) {
    for (int i = 0; i < k; i++) {
        if (strcasecmp(p[i].poste, "gardien") == 0) {
            printf("Informations Sur les Players: \n");
            printf("\tNumero: %d, Nom: %s\n", p[i].numero, p[i].nom);
            printf("\tNom de Equipe: %s, Stade de Equipe: %s, Entreneur de Equipe: %s, Country de Equipe: %s\n", p[i].eq.nom, p[i].eq.stade, p[i].eq.entreneur, p[i].eq.country);
        }
    }
}

//remplissage de list avec les players et les stockers
void Saisir_P(Player p[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Player Number %d His Maryol Number: ", i + 1);
        scanf("%d", &p[i].numero);
        printf("Player Name: ");
        scanf(" %[^\n]s", p[i].nom);
        printf("Player Poste: ");
        scanf(" %[^\n]s", p[i].poste);

        printf("Player Equipe Name: ");
        scanf(" %[^\n]s", p[i].eq.nom);

        printf("Player Equipe Stade: ");
        scanf(" %[^\n]s", p[i].eq.stade);

        printf("Player Equipe Entreneur: ");
        scanf(" %[^\n]s", p[i].eq.entreneur);

        printf("Player Equipe Country: ");
        scanf(" %[^\n]s", p[i].eq.country);
    }
}
//echanger les players par their name 
void echange(Player p[], int k) {
    char nom_p[n], new_equipe_name[n], new_equipe_entre[n], new_equipe_country[n],new_equipe_stade[n];
    int new_num;
    printf("Saisir Player Name pour quelle est changer sa equipe: ");
    scanf(" %[^\n]s", nom_p);

    for (int i = 0; i < k; i++) {
        if (strcmp(p[i].nom, nom_p) == 0) {
            printf("Player New Maryol Number: ");
            scanf("%d", &new_num);
            printf("Player New Equipe Name: ");
            scanf(" %[^\n]s", new_equipe_name);

            printf("Player New Equipe Stade: ");
            scanf(" %[^\n]s", new_equipe_stade);

            printf("Player's New Entreneur Name: ");
            scanf(" %[^\n]s", new_equipe_entre);

            printf("Player's New Country Name: ");
            scanf(" %[^\n]s", new_equipe_country);

            p[i].numero = new_num;
            strcpy(p[i].eq.nom, new_equipe_name);
            strcpy(p[i].eq.stade, new_equipe_stade);
            strcpy(p[i].eq.entreneur, new_equipe_entre);
            strcpy(p[i].eq.country, new_equipe_country);

            printf("=>Modification Done\n");
            return;
        }
    }
    printf("Player Not Found\n");
}
//programme principale
int main() {
    Player *p = NULL;
    int N;
    char choix[5];
    int nb;

    printf("--------------football_team_management-----------------\n");
    while (true) {
        printf("1-Add Football's Players\n");
        printf("2-Affichier Les Attaquant\n");
        printf("3-Affichier Les Middle\n");
        printf("4-Affichier Les Defense\n");
        printf("5-Affichier Les Gardian\n");
        printf("6-Echange Players\n");
        printf("7-Affichier ALL PLayers\n");
        printf("8-Quittez Le Programme\n");

        printf("****************************\n");
        printf("Saisir Votre Choix: ");
        scanf("%d", &nb);

        if (nb == 1) {
            N = saisir();
            p = (Player *)malloc(N * sizeof(Player));
            if (p == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            Saisir_P(p, N);
            printf("\n");
        } else if (nb == 2) {
            printf("Do you want to see les Attaquant Players(y,n)? :");
            getchar();
            fgets(choix, 2, stdin);
            if ((strcmp(choix, "y") == 0) || (strcmp(choix, "Y") == 0)) {
                affi_atta(p, N);
                printf("\n");
            } else {
                printf("\n");
            }
        } else if (nb == 3) {
            printf("Do you want to see les Middle Players(y,n)? :");
            getchar();
            fgets(choix, 2, stdin);
            if ((strcmp(choix, "y") == 0) || (strcmp(choix, "Y") == 0)) {
                affi_mid(p, N);
                printf("\n");
            } else {
                printf("\n");
            }
        } else if (nb == 4) {
            printf("Do you want to see les Defense Players(y,n)? :");
            getchar();
            fgets(choix, 2, stdin);
            if ((strcmp(choix, "y") == 0) || (strcmp(choix, "Y") == 0)) {
                affi_defense(p, N);
                printf("\n");
            } else {
                printf("\n");
            }
        } else if (nb == 5) {
            printf("Do you want to see les gardian Players(y,n)? :");
            getchar();
            fgets(choix, 2, stdin);
            if ((strcmp(choix, "y") == 0) || (strcmp(choix, "Y") == 0)) {
                affi_gard(p, N);
                printf("\n");
            } else {
                printf("\n");
            }
        } else if (nb == 6) {
            printf("Do you want to Echange Player(y,n)? :");
            getchar();
            fgets(choix, 2, stdin);
            if ((strcmp(choix, "y") == 0) || (strcmp(choix, "Y") == 0)) {
                echange(p, N);
                printf("\n");
            } else {
                printf("\n");
            }
        } else if (nb == 7) {
            affichier(p, N);
            printf("\n");
        } else if (nb == 8) {
            printf("=>Programme Terminer\n");
            free(p);
            break;
        } else {
            printf("Choix Invalide !\n");
        }
    }
    return 0;
}

