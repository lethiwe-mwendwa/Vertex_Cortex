#include "Vertex.h"

void drawShape(SDL_Renderer* renderer, Cube shape)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int i = 0; i < 12; i++) {
		Vertex currentVertex = shape.vectices[i];
		Point3D point1 = shape.points[currentVertex.point1];
		Point3D point2 = shape.points[currentVertex.point2];

		Point2D screenPoint1{
			((point1.x * FOV) / (point1.z + FOV)) + SCREEN_WIDTH / 2,
			((point1.y * FOV) / (point1.z + FOV)) + SCREEN_HEIGHT / 2
		};
		Point2D screenPoint2{
			((point2.x * FOV) / (point2.z + FOV)) + SCREEN_WIDTH / 2,
			((point2.y * FOV) / (point2.z + FOV)) + SCREEN_HEIGHT / 2
		};
		

		SDL_RenderDrawLine(
			renderer, screenPoint1.x, screenPoint1.y,
			screenPoint2.x, screenPoint2.y
		);

	}
};

/*
Point2D screenPoint1{
			((point1.x*FOV) / (point1.z+FOV)) + SCREEN_WIDTH/2,
			((point1.y * FOV) / (point1.z + FOV)) + SCREEN_HEIGHT/2
		};
		Point2D screenPoint2{
			((point2.x * FOV)/ (point2.z + FOV)) + SCREEN_WIDTH/2,
			((point2.y * FOV) / (point2.z + FOV)) + SCREEN_HEIGHT/2
		};


Point2D screenPoint1{
			(point1.x / point1.z) + SCREEN_WIDTH / 2,
			(point1.y /point1.z) + SCREEN_HEIGHT / 2
		};
		Point2D screenPoint2{
			(point2.x / point2.z) + SCREEN_WIDTH / 2,
			(point2.y / point2.z) + SCREEN_HEIGHT / 2
		};
*/