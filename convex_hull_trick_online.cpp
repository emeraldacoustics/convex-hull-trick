#include <vector>

using namespace std;

template <class T>
class ConvexHullTrick
{
public:
	vector<Point<T> > hull, vecs;

	bool cmp(const Point<T> & lhs, const Point<T> & rhs) const
	{
		return lhs * rhs > 0;
	}

	ConvexHullTrick(void)
	{

	}

	void clear(void)
	{
		hull.clear();
		vecs.clear();
	}

	void add(const T & x, const T & y)
	{
		add(Point<T>(x, y));
	}

	void add(const Point<T> & p)
	{
		for (; !vecs.empty() && !cmp(vecs.back(), (p - hull.back()).normal()); )
		{
			hull.pop_back();
			vecs.pop_back();
		}
		if (!hull.empty())
			vecs.push_back((p - hull.back()).normal());
		hull.push_back(p);
	}

	T get(const T & x) const
	{
		Point<T> p(x, 1);
		return p & hull[lower_bound(vecs.begin(), vecs.end(), p, cmp) - vecs.begin()];
	}
};

