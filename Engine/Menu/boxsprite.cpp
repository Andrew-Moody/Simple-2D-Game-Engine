#include "boxsprite.h"


BoxSprite::BoxSprite(int borderWidth, int x, int y, int w, int h)
{
	setSRC(0, 0);

	int cornerWidth = (borderWidth * corner_src.w) / edge_src.h;

	corner1_dest = { x, y, cornerWidth, cornerWidth };
	corner2_dest = { x + w - cornerWidth, y, cornerWidth, cornerWidth };
	corner3_dest = { x + w - cornerWidth, y + h - cornerWidth, cornerWidth, cornerWidth };
	corner4_dest = { x, y + h - cornerWidth, cornerWidth, cornerWidth };

	edge1_dest = { x + cornerWidth, y, w - (2 * cornerWidth), borderWidth };

	edge2_dest = { x + w - (h + borderWidth) / 2 + cornerWidth, y + (h - borderWidth) / 2, h - (2 * cornerWidth), borderWidth };

	edge3_dest = { x + cornerWidth, y + h - borderWidth, w - (2 * cornerWidth), borderWidth };

	edge4_dest = { x - (h - borderWidth) / 2 + cornerWidth, y + (h - borderWidth) / 2, h - (2 * cornerWidth), borderWidth };

	fill_dest = { x + borderWidth, y + borderWidth, w - (2 * borderWidth), h - (2 * borderWidth) };
}

BoxSprite::~BoxSprite() {}

void BoxSprite::setSRC(int x, int y)
{
	corner_src = { x, y, 4, 4 };
	edge_src = { x + 4, y, 4, 3 };
	fill_src = { x + 8, y, 4, 4 };
}


int BoxSprite::getSRCX()
{
	return corner_src.x;
}

int BoxSprite::getSRCY()
{
	return corner_src.y;
}