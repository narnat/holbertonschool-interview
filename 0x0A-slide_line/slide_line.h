#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>

/**
 * enum direction - tells the direction where to move
 * @SLIDE_LEFT: value 0, slides left
 * @SLIDE_RIGHT: value 1, slides right
 */
enum direction
{
	SLIDE_LEFT,
	SLIDE_RIGHT
};

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
