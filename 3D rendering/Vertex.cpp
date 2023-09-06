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

void rotateShape(int theta, Cube &shape) {
	theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{1,0,0},
		{0,cos(theta),-sin(theta)},
		{0,sin(theta),cos(theta)}
	};
	
	for (int i = 0; i < 8; i++) {
		Point3D currentPoint = shape.points[i];
		shape.points[i].x = (transMatrix[0][0] * currentPoint.x) + (transMatrix[0][1] * currentPoint.y) + (transMatrix[0][2] * currentPoint.z);
		shape.points[i].y = (transMatrix[1][0] * currentPoint.x) + (transMatrix[1][1] * currentPoint.y) + (transMatrix[1][2] * currentPoint.z);
		shape.points[i].z = (transMatrix[2][0] * currentPoint.x) + (transMatrix[2][1] * currentPoint.y) + (transMatrix[2][2] * currentPoint.z);
	}

}


/*
* 
Hey, if you want me to tell tom to call you and ask for some homework or something "important" that would
need you to use your phone, I can do.
* 
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