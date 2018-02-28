/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:44:41 by allauren          #+#    #+#             */
/*   Updated: 2018/02/27 16:01:23 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ncurses.h>
int main(void)
{
		initscr(); // Initialise la structure WINDOW et autres paramètres
		//printw("Hello World"); // Écrit Hello World à l'endroit où le curseur logique est positionné
//		refresh(); // Rafraîchit la fenêtre courante afin de voir le message apparaître
	attron(A_NORMAL);
	printw("Texte sans mise en forme\n");
	attron(A_STANDOUT);
	printw("Texte en meilleur surlignement\n");
	attroff(A_STANDOUT);
	attron(A_REVERSE);
	printw("Texte en inversion video\n");
	attroff(A_REVERSE);
	attron(A_DIM);
	printw("Texte a moitie brillant\n");
	attroff(A_DIM);
	attron(A_BOLD);
	printw("Texte en gras\n");
	attroff(A_BOLD);
	attron(A_UNDERLINE);
	printw("Texte en souligne\n");
	attroff(A_UNDERLINE);
	attron(A_INVIS);
	printw("Texte invisible\n");
	attroff(A_INVIS);
	attron(A_UNDERLINE |
			A_BOLD); // Pour appliquer plusieurs type de mises en forme, on utilise l'opérateur unaire |
	printw("Texte en gras souligne\n");
	//attroff(A_UNDERLINE |
	//		A_BOLD);

	move(LINES / 2, COLS / 2); // Déplace le curseur tout en bas à droite de l'écran
	addch('.'); // Écrit le caractère . au nouvel emplacement
	getch();
	endwin();

	return 0;
}
