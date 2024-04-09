/**
 * Computes the intersection of a set of half-planes, each on the form: $x P_x + y P_y \ge P_c$.
 * The resulting polygon extending to infinity is not handled. If that is possible add some extra half-planes
 * far away and check for those in the result.
 * Each half-plane is given as a pair where the first value is $(P_x, P_y)$ and the second value is $P_c$.
 * In the returned vector, ret[i].first is the position of the i:th vertex and ret[i].second is the index in
 * the input vector of the half-plane that created the edge between vertex i and (i+1)\%ret.size().
 * There may be duplicate points in the output vector if there are multiple half-planes that intersect at the same point.
 */using lll = __int128_t;
// For double:
using P = dpoint;
double fraction(double e, double d) { return e / d; }
const double inf = INFINITY, neginf = -INFINITY;
// For fractions:
using P = point<fraction>;
const fraction inf = fraction(1, 0), neginf = fraction(-1, 0);

vector<pair<P, ll>> halfPlaneIntersection(const vector<pair<ipoint, ll>>& pts) {
	vector<ll> planesL, planesU;
	pair<double, ll> maxvx = {inf, -1}, minvx = {neginf, -1};
	for (ll i = 0; i < (ll)pts.size(); i++) {
		auto [n, c] = pts[i];
		if (n.y > 0) planesL.push_back(i);
		else if (n.y < 0) planesU.push_back(i);
		else {
			auto x = fraction(c, n.x);
			if (n.x < 0) maxvx = min(maxvx, make_pair(x, i));
			else if (n.x > 0) minvx = max(minvx, make_pair(x, i));
			else if (c > 0) return {};
		}
	}
	if (maxvx.first < minvx.first) return {};
	if (minvx.second != -1) planesU.emplace_back(minvx.second);
	if (maxvx.second != -1) planesL.emplace_back(maxvx.second);
	auto intersect = [&] (ll a, ll b) -> optional<P> {
		auto [an, ac] = pts[a]; auto [bn, bc] = pts[b];
		if (ll cr = bn.cross(an))
			return P(fraction((lll)bc*an.y - (lll)ac*bn.y, cr), fraction((lll)bc*an.x - (lll)ac*bn.x, -cr));
		return nullopt;
	};
	auto hull = [&] (vector<ll>& planes, bool rev) {
		sort(all(planes), [&] (ll a, ll b) {
			auto [ap, ac] = pts[a]; auto [bp, bc] = pts[b];
			return make_tuple(ap.x*bp.y, (lll)ac*(lll)bp.y) < make_tuple(bp.x * ap.y, (lll)bc*(lll)ap.y);
		});
		if (rev) reverse(all(planes));
		vector<pair<ll, P>> st;
		for (ll pi : planes) { start:
			if (st.empty())
				st.emplace_back(pi, P(neginf, 0));
			else if (auto i = intersect(pi, st.back().first))
				if (st.back().second.x <= i->x) { st.emplace_back(pi, *i); }
				else { st.pop_back(); goto start; }
		}
		return st;
	};
	auto stL = hull(planesL, true);
	auto stU = hull(planesU, false);
	assert(!stL.empty() && !stU.empty()); // otherwise infinite result
	optional<P> intersectL, intersectR;
	ll ril = stL.size() - 1, riu = stU.size() - 1, lil = 0, liu = 0;
	stL.emplace_back(-1, P(inf, 0));
	stU.emplace_back(-1, P(inf, 0));
	while (ril >= 0 && riu >= 0) {
		auto i = intersect(stL[ril].first, stU[riu].first);
		if (!i) break;
		if (stL[ril].second <= *i && stU[riu].second <= *i) {
			if (*i <= stL[ril + 1].second && *i <= stU[riu + 1].second)
				intersectR = i;
			break;
		} else
			(stL[ril].second.x < stU[riu].second.x ? riu : ril)--;
	}
	while (lil <= ril && liu <= riu) {
		auto i = intersect(stL[lil].first, stU[liu].first);
		if (!i) break;
		if (*i <= stL[lil + 1].second && *i <= stU[liu + 1].second) {
			intersectL = i;
			break;
		} else
			(stL[lil + 1].second.x < stU[liu + 1].second.x ? lil : liu)++;
	}
	if (!intersectR || !intersectL) return {};
	vector<pair<P, ll>> result;
	for (ll i = riu; i > liu; i--)
		result.emplace_back(stU[i].second, stU[i - 1].first);
	result.emplace_back(*intersectL, stL[lil].first);
	for (ll i = lil + 1; i <= ril; i++)
		result.emplace_back(stL[i].second, stL[i].first);
	result.emplace_back(*intersectR, stU[riu].first);
	return result;
}
