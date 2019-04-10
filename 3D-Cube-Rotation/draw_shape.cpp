
#include "../3D-Cube-Rotation/draw_shape.h"




void DrawLine::draw(RasterGrid* pRasterGrid)
{
	int dx = abs(m_finishPos.x - m_startPos.x), sx = m_startPos.x < m_finishPos.x ? 1 : -1;
	int dy = -abs(m_finishPos.y - m_startPos.y), sy = m_startPos.y < m_finishPos.y ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	for (;;) {  /* loop */
		pRasterGrid->setPixel(m_startPos.x, m_startPos.y);
		if (m_startPos.x == m_finishPos.x && m_startPos.y == m_finishPos.y) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; m_startPos.x += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; m_startPos.y += sy; } /* e_xy+e_y < 0 */
	}
}