#include "Vertex.h"

void drawShape(SDL_Renderer* renderer, Shape shape)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// if I dont change to arrays, maybe optimise?? beep beep
	for (int i = 0; i < shape.vecticesNum; i++) {
		Vertex currentVertex = shape.vectices[i];
		Point3D point1 = shape.points[currentVertex.point1];
		Point3D point2 = shape.points[currentVertex.point2];

		Point2D screenPoint1{
			((point1.x * FOV) / (point1.z + FOV)) + SCREEN_WIDTH / 2,
			((-point1.y * FOV) / (point1.z + FOV)) + SCREEN_HEIGHT / 2
		};
		Point2D screenPoint2{
			((point2.x * FOV) / (point2.z + FOV)) + SCREEN_WIDTH / 2,
			((-point2.y * FOV) / (point2.z + FOV)) + SCREEN_HEIGHT / 2
		};
		SDL_RenderDrawLine(
			renderer, screenPoint1.x, screenPoint1.y,
			screenPoint2.x, screenPoint2.y
		);

	}
};

void rotateShapeX(double theta, Shape &shape) {
	//theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{1,0,0},
		{0,cos(theta),-sin(theta)},
		{0,sin(theta),cos(theta)}
	};
	applyMatrix(transMatrix, shape);

}

void rotateShapeY(double theta, Shape& shape) {
	//theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{cos(theta),0,sin(theta)},
		{0,1,0},
		{-sin(theta),0,cos(theta)}
	};
	applyMatrix(transMatrix, shape);

}

void rotateShapeZ(double theta, Shape& shape) {
	double transMatrix[3][3] = {
		{cos(theta),-sin(theta),0},
		{0,1,0},
		{-sin(theta),0,cos(theta)}
	};
	applyMatrix(transMatrix, shape);
}

void moveShapeX(double x, Shape& shape) {
	for (int i = 0; i < shape.pointNum; i++) {
		Point3D currentPoint = shape.points[i];
		shape.points[i].x = currentPoint.x + x;
	}
}
void moveShapeZ(double z, Shape& shape) {
	for (int i = 0; i < shape.pointNum; i++) {
		Point3D currentPoint = shape.points[i];
		shape.points[i].z = currentPoint.z + z;
	}
}
void moveShapeY(double y, Shape& shape) {
	for (int i = 0; i < shape.pointNum; i++) {
		Point3D currentPoint = shape.points[i];
		shape.points[i].y = currentPoint.y + y;
	}
}

void reflectShapeYZ(double theta, Shape& shape) {
	//theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{-1,0,0},
		{0,1,0},
		{0,0,-1}
	};
	applyMatrix(transMatrix, shape);

}

void reflectShapeXZ(double theta, Shape& shape) {
	//theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{1,0,0},
		{0,-1,0},
		{0,0,1}
	};
	applyMatrix(transMatrix, shape);

}


void applyMatrix(double transMatrix[3][3], Shape& shape) {
	for (int i = 0; i < shape.pointNum; i++) {
		Point3D currentPoint = shape.points[i];
		shape.points[i].x = (transMatrix[0][0] * currentPoint.x) + (transMatrix[0][1] * currentPoint.y) + (transMatrix[0][2] * currentPoint.z);
		shape.points[i].y = (transMatrix[1][0] * currentPoint.x) + (transMatrix[1][1] * currentPoint.y) + (transMatrix[1][2] * currentPoint.z);
		shape.points[i].z = (transMatrix[2][0] * currentPoint.x) + (transMatrix[2][1] * currentPoint.y) + (transMatrix[2][2] * currentPoint.z);
	}
}


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