/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** graphical functions
*/

#include "vm_prototype.h"
#include "my.h"

sfRenderWindow 	*my_window_create(void)
{
	sfRenderWindow 	*window;
	sfVideoMode	mode;

	mode.width = 800;
	mode.height = 600;
	mode.bitsPerPixel = 16;
	window = sfRenderWindow_create(mode, "Corewar", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 128);
	return (window);
}

void 	corewar_events(sfRenderWindow *window, sfEvent event)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(window);
	}
}

void 	box_color(sfRectangleShape *box, char mem)
{
	(mem == 0) ? sfRectangleShape_setFillColor(box, sfBlack) : (void)0;
	(mem == 1) ? sfRectangleShape_setFillColor(box, sfRed) : (void)0;
	(mem == 2) ? sfRectangleShape_setFillColor(box, sfBlue) : (void)0;
	(mem == 3) ? sfRectangleShape_setFillColor(box, sfYellow) : (void)0;
	(mem == 4) ? sfRectangleShape_setFillColor(box, sfGreen) : (void)0;
	(mem == 5) ? sfRectangleShape_setFillColor(box, sfMagenta) : (void)0;
}

void	display_win(data_t *champion, sfRenderWindow *window, core_t *core)
{
	static sfFont 	*font = NULL;
	sfText 		*txt;

	font = (font == NULL) ? sfFont_createFromFile("font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setPosition(txt, (sfVector2f) {25, 525});
	while (1) {
		sfText_setString(txt, champion->prog_name);
		if (core->last_live == 0) {
			sfText_setString(txt, "No lives");
			break;
		}
		if (core->last_live == champion->player_nb)
			break;
		champion = champion->next;
	}
	sfRenderWindow_drawText(window, txt, NULL);
}

void 	window_display_mem(sfRenderWindow *window, char *mem)
{
	sfVector2f pos = (sfVector2f) {1, 1};
	sfRectangleShape  *box = sfRectangleShape_create();

	sfRectangleShape_setSize(box, (sfVector2f) {6, 6});
	sfRectangleShape_setFillColor(box, sfBlack);
	for (int i = 1; i < 6 * 1024 + 1; i++) {
		box_color(box, mem[i - 1]);
		sfRectangleShape_setPosition(box, pos);
		sfRenderWindow_drawRectangleShape(window, box, NULL);
		pos.x += 8;
		if (i % 100 == 0) {
			pos.x = 1;
			pos.y += 8;
		}
	}
}
