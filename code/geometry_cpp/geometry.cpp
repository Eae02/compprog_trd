template <typename T> struct point {
	T x, y;
	point() { x=y=0; }
	point(T xx, T yy) : x(xx), y(yy) { }
	template <typename U> point(point<U> o) : x(o.x), y(o.y) { }
	point operator+(point o) const { return { x+o.x, y+o.y }; }
	point operator-(point o) const { return { x-o.x, y-o.y }; }
	point operator*(T o) const { return { x*o, y*o }; }
	point operator/(T o) const { return { x/o, y/o }; }
	bool operator==(point o) const { return x==o.x && y==o.y; };
	bool operator<(point o) const { return tie(x, y) < tie(o.x, o.y); };
	T dot(point o) const { return x*o.x + y*o.y; }
	T cross(point b) const { return x*b.y - y*b.x; }
	T cross(point b, point o) const { return (*this-o).cross(b-o); }
	T len2() const { return x*x + y*y; }
};
using ipoint = point<ll>;
using dpoint = point<double>;
ll sign(auto x) { return (x>0) - (x<0); }
bool zero(double x) { return abs(x) < 1E-9; }
