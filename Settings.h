#define _USE_MATH_DEFINES
#include <cmath>
#include <tuple>
using namespace std;


	const double PI = 3.14159265358979323846;

	int WIDTH = 1600;
	int HEIGHT = 900;
	tuple<int, int> RES = make_tuple (WIDTH, HEIGHT);
	int HALF_WIDTH = WIDTH / 2;
	int HALF_HEIGHT = HEIGHT / 2;
	double FPS = 0;

	tuple<double, double> PLAYER_POS = make_tuple (1.5, 5);
	double PLAYER_ANGLE = 0;
	double PLAYER_SPEED = 0.004;
	double PLAYER_ROT_SPEED = 0.002;
	double PLAYER_SIZE_SCALE = 60;
	double PLAYER_MAX_HEALTH = 100;

	double MOUSE_SENSITIVITY = 0.0003;
	int MOUSE_MAX_REL = 40;
	int MOUSE_BORDER_LEFT = 100;
	int MOUSE_BORDER_RIGHT = WIDTH - MOUSE_BORDER_LEFT;

	tuple<int, int, int>FLOOR_COLOR = make_tuple (30, 30, 30);

	double FOV = PI / 3;
	double HALF_FOV = FOV / 2;
	int NUM_RAYS = WIDTH / 2;
	int HALF_NUM_RAYS = NUM_RAYS / 2;
	double DELTA_ANGLE = FOV / NUM_RAYS;
	int MAX_DEPTH = 20;

	double SCREEN_DIST = HALF_WIDTH / tan (HALF_FOV);
	int SCALE = WIDTH / NUM_RAYS;

	int TEXTURE_SIZE = 256;
	int HALF_TEXTURE_SIZE = TEXTURE_SIZE / 2;






