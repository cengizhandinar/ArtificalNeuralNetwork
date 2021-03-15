#define Class1 -1
#define Class2 1
#define ConstNum 1
#define C 1
#define M 0.1

int YPoint(int x, double* w, int dim = 0, int = 1);
struct Samples {
	double X, Y;
	int Class, Const;
};
struct Colors {
	int r, g, b;
};
int YPoint(int x, double* w, int dim, int Multiplier)
{
	return (int)((double)(-1 * (double)Multiplier * w[(dim * 3) + 2] - w[dim * 3] * x) / (double)(w[(dim * 3) + 1]));
}