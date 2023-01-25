#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define POT(x) ((x) * (x))
const ll MX = 2e3 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

bool near(double a, double b) {
    return fabs(a - b) < EPS;
}

struct coordenadas {
    double x, y;
    coordenadas(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator<(coordenadas other) const {
        if (fabs(x - other.x) > EPS) {
            return x < other.x;
        }
        return y < other.y;
    }
    bool operator==(const coordenadas &P) const {
        return near(x, P.x) && near(y, P.y);
    }
    coordenadas operator*(double t) const {
        return coordenadas(x * t, y * t);
    }
    coordenadas operator-(const coordenadas &other) const {
        return coordenadas(x - other.x, y - other.y);
    }
    coordenadas operator-=(const coordenadas &other) {
        *this = *this - other;
        return *this;
    }
    coordenadas operator+(const coordenadas &other) const {
        return coordenadas(x + other.x, y + other.y);
    }
    coordenadas operator+=(const coordenadas &other) {
        *this = *this + other;
        return *this;
    }
    double cross(const coordenadas &other) const {
        return x * other.y - y * other.x;
    }
    double cross(const coordenadas &A, const coordenadas &B) const {
        // Given the current point P, this calculate PA x PB
        return (A - *this).cross(B - *this);
    }
};

struct coordenadasEntero {
    ll x, y;
    coordenadasEntero(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator<(coordenadasEntero other) const {
        if (fabs(x - other.x) > EPS) {
            return x < other.x;
        }
        return y < other.y;
    }
    bool operator==(const coordenadasEntero &P) const {
        return P.x == x && P.y == y;
    }
    coordenadasEntero operator*(ll t) const {
        return coordenadasEntero(x * t, y * t);
    }
    coordenadasEntero operator-(const coordenadasEntero &other) const {
        return coordenadasEntero(x - other.x, y - other.y);
    }
    coordenadasEntero operator-=(const coordenadasEntero &other) {
        *this = *this - other;
        return *this;
    }
    coordenadasEntero operator+(const coordenadasEntero &other) const {
        return coordenadasEntero(x + other.x, y + other.y);
    }
    coordenadasEntero operator+=(const coordenadasEntero &other) {
        *this = *this + other;
        return *this;
    }
    ll cross(const coordenadasEntero &other) const {
        return x * other.y - y * other.x;
    }
    ll cross(const coordenadasEntero &A, const coordenadasEntero &B) const {
        // Given the current point P, this calculate PA x PB
        return (A - *this).cross(B - *this);
    }
};

bool cmpX(const coordenadasEntero P1, coordenadasEntero P2) {
    return (P1.x != P2.x ? P1.x < P2.x : P1.y < P2.y);
}

bool cmpY(const coordenadasEntero P1, coordenadasEntero P2) {
    return (P1.y != P2.y ? P1.y < P2.y : P1.x < P2.x);
}

enum { CCW, CW, CNOT };

ll ccw(coordenadas a, coordenadas b, coordenadas c) {
    double dx1 = b.x - a.x;
    double dx2 = c.x - b.x;
    double dy1 = b.y - a.y;
    double dy2 = c.y - b.y;
    double t1 = dy2 * dx1;
    double t2 = dy1 * dx2;

    if (fabs(t1 - t2) < EPS) {
        if (dx1 * dx2 < 0 || dy1 * dy2 < 0)
            if (POT(dx1) + POT(dy1) >= POT(dx2) + POT(dy2) - EPS) return CNOT;
            else return CW;
        else return CCW;
    }
    if (t1 > t2) return CCW;
    return CW;
}

double areaPoligono(vector<coordenadas> &valores) {
    double tot = 0;
    for (ll i = 0; i < valores.size() - 1; i++) {
        tot += (valores[i].x * valores[i + 1].y - valores[i].y * valores[i + 1].x);
    }
    return fabs(tot) / 2.0;
}

bool esConvexo(vector<coordenadas> &valores) {
    bool igual = true;
    ll primero = ccw(valores[0], valores[1], valores[2]);
    for (ll i = 1; i <= valores.size(); i++) {
        if (primero != ccw(valores[(i - 1) % valores.size()], valores[i % valores.size()],
                           valores[(i + 1) % valores.size()])) {
            igual = false;
            break;
        }
    }
    return igual;
}

struct vector1 {
    double x, y;
};

vector1 direccion(coordenadas a, coordenadas b) {
    vector1 nuevo;
    nuevo.x = b.x - a.x;
    nuevo.y = b.y - a.y;
    return nuevo;
}

vector1 scale(vector1 a, double factor) {
    vector1 nuevo;
    nuevo.x = a.x * factor;
    nuevo.y = a.y * factor;
    return nuevo;
}

coordenadas trasladar(coordenadas a, vector1 b) {
    coordenadas c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

double potDistancia(coordenadas a, coordenadas b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

double distancia(coordenadas a, coordenadas b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double productoEscalar(vector1 a, vector1 b) {
    return a.x * b.x + a.y * b.y;
}

double moduloPot(vector1 a) {
    return a.x * a.x + a.y * a.y;
}

double angulo(coordenadas a, coordenadas o, coordenadas b) {
    vector1 oa = direccion(o, a);
    vector1 ob = direccion(o, b);
    ll p = 0;
    cout << " qweqweqweq " << moduloPot(oa) << endl;
    cout << " asdadas " << moduloPot(ob) << endl;
    cout << " fhfghgfh " << productoEscalar(oa, ob) / sqrt(moduloPot(oa) * moduloPot(ob))
         << endl;
    cout << " rtyrtyrtyrt "
         << acos(productoEscalar(oa, ob) / sqrt(moduloPot(oa) * moduloPot(ob))) << endl;
    p += acos(productoEscalar(oa, ob) / sqrt(moduloPot(oa) * moduloPot(ob)));
    cout << "Valor de p: " << p << endl;
    return acos(productoEscalar(oa, ob) / sqrt(moduloPot(oa) * moduloPot(ob)));
}

bool puntoEnPoligono(coordenadas a, vector<coordenadas> &valores) {
    if (valores.size() == 0) {
        return false;
    }
    double sum = 0.0;
    for (ll i = 0; i < valores.size() - 1; i++) {
        if (ccw(a, valores[i], valores[i + 1])) {
            sum += angulo(valores[i], a, valores[i + 1]);
        } else {
            sum -= angulo(valores[i], a, valores[i + 1]);
        }
    }
    return fabs(fabs(sum) - 2.0 * PI) < EPS;
}

pair<double, coordenadas> distanciaRecta(coordenadas p, coordenadas a, coordenadas b) {
    vector1 ap = direccion(a, p);
    vector1 ab = direccion(a, b);
    double proyeccionDivididoAB = productoEscalar(ap, ab) / moduloPot(ab);
    coordenadas puntoMinimo = trasladar(a, scale(ab, proyeccionDivididoAB));
    return {distancia(p, puntoMinimo), puntoMinimo};
}

pair<double, coordenadas> distanciaSegmento(coordenadas p, coordenadas a, coordenadas b) {
    vector1 ap = direccion(a, p), ab = direccion(a, b);
    double proyeccionDivididoAB = productoEscalar(ap, ab) / moduloPot(ab);
    if (proyeccionDivididoAB < 0.0) {
        return {distancia(p, a), a};
    }
    if (proyeccionDivididoAB > 1.0) {
        return {distancia(p, b), b};
    }
    return distanciaRecta(p, a, b);
}

vector<coordenadas> convexHull(vector<coordenadas> &valores) {
    coordenadas pivote;
    pivote.x = valores[0].x;
    pivote.y = valores[0].y;
    for (ll i = 0; i < valores.size(); i++) {
        if (pivote.y > valores[i].y) {
            pivote.y = valores[i].y;
            pivote.x = valores[i].x;
        } else {
            if (pivote.y == valores[i].y) {
                if (pivote.x < valores[i].x) {
                    pivote.x = valores[i].x;
                }
            }
        }
    }
    vector<pair<double, coordenadas>> angulos;
    for (ll i = 0; i < valores.size(); i++) {
        if (pivote.x == valores[i].x && pivote.y == valores[i].y) {
            angulos.pb(make_pair(0.0, valores[i]));
            continue;
        }
        double valorAngulo = angulo({INF_DOUBLE, pivote.y}, pivote, valores[i]);
        angulos.pb(make_pair(valorAngulo, valores[i]));
    }
    sort(angulos.begin(), angulos.end());
    vector<coordenadas> resultados;
    resultados.pb(angulos[angulos.size() - 1].second);
    resultados.pb(angulos[0].second);
    resultados.pb(angulos[1].second);
    ll i = 2;
    while (i < angulos.size()) {
        ll j = resultados.size() - 1;
        if (ccw(resultados[j - 1], resultados[j], angulos[i].second) == 0) {
            resultados.pb(angulos[i].second);
            i++;
        } else {
            resultados.pop_back();
        }
    }
    return resultados;
}

ll validar(coordenadas a, coordenadas b) {
    if (a.x == b.x && a.y == b.y) {
        return 0;
    }
    if (a.x == b.x || a.y == b.y) {
        return 1;
    }
    return 2;
}

ll potDistancia(coordenadasEntero a, coordenadasEntero b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

pair<coordenadasEntero, coordenadasEntero> combine(
    pair<coordenadasEntero, coordenadasEntero> D1,
    pair<coordenadasEntero, coordenadasEntero> D2) {
    if (potDistancia(D1.first, D1.second) > potDistancia(D2.first, D2.second)) {
        swap(D1, D2);
    }
    return D1;
}

pair<coordenadasEntero, coordenadasEntero> closestPair(vector<coordenadasEntero> &X,
                                                       vector<coordenadasEntero> &Y) {
    ll n = X.size();
    assert(X.size() == Y.size());
    if (n <= 3) {
        pair<coordenadasEntero, coordenadasEntero> minPair = {X[0], X[1]};
        for (ll i = 0; i < X.size() - 1; i++) {
            for (ll j = i + 1; j < X.size(); j++) {
                minPair = combine(minPair, {X[i], X[j]});
            }
        }
        return minPair;
    }
    vector<coordenadasEntero> XL;
    vector<coordenadasEntero> XR;
    vector<coordenadasEntero> YL;
    vector<coordenadasEntero> YR;
    ll med = n / 2;
    for (ll i = 0; i < med; i++) {
        XL.pb(X[i]);
        if (cmpX(Y[i], X[med])) {
            YL.pb(Y[i]);
        } else {
            YR.pb(Y[i]);
        }
    }
    for (ll i = med; i < n; i++) {
        XR.pb(X[i]);
        if (cmpX(Y[i], X[med])) {
            YL.pb(Y[i]);
        } else {
            YR.pb(Y[i]);
        }
    }
    pair<coordenadasEntero, coordenadasEntero> ans =
        combine(closestPair(XL, YL), closestPair(XR, YR));
    ll d = potDistancia(ans.first, ans.second);
    vector<coordenadasEntero> YP;
    for (ll i = 0; i < n; i++) {
        if ((X[med].x - Y[i].x) * (X[med].x - Y[i].x) <= d) {
            YP.push_back(Y[i]);
        }
    }
    ll sz = YP.size();
    for (int i = 0; i < sz; i++) { // one pair from L and one from R
        ll j = i + 1;
        while (j < sz && (YP[j].y - YP[i].y) * (YP[j].y - YP[i].y) <= d) { // 7 points maximum
            ans = combine(ans, {YP[i], YP[j]});
            j++;
        }
    }

    return ans;
}

pair<coordenadasEntero, coordenadasEntero> closestPair(vector<coordenadasEntero> &todos) {
    ll n = todos.size();
    vector<coordenadasEntero> X = todos;
    vector<coordenadasEntero> Y = todos;
    sort(X.begin(), X.end(), cmpX);
    sort(Y.begin(), Y.end(), cmpY);
    for (ll i = 0; i < n - 1; i++) {
        if (X[i] == X[i + 1]) {
            return {X[i], X[i + 1]};
        }
    }
    return closestPair(X, Y);
}

struct linea {
    // ax+by+c=0
    double a, b, c;
    linea() {}
    linea(double a, double b, double c) : a(a), b(b), c(c) {}
    linea(coordenadas p1, coordenadas p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = -a * p1.x - b * p1.y;
    }
};

bool sonParalelos(linea x, linea y) {
    return fabs(x.a - y.a) < EPS && fabs(x.b - y.b) < EPS;
}

bool seIntersectan(linea x, linea y, coordenadas &p) {
    if (sonParalelos(x, y)) {
        return false;
    }
    p.x = (y.b * x.c - x.b * y.c) / (y.a * x.b - x.a * y.b);
    if (fabs(x.b) > EPS) {
        p.y = -(x.a * p.x + x.c);
    } else {
        p.y = -(y.a * p.x + y.c);
    }
    return true;
}

double areaTriangulo(double ab, double bc, double ca) {
    double s = (ab + bc + ca) / 2.0;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

double radioCircuncentro(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * areaTriangulo(ab, bc, ca));
}

double radioCircuncentroCoordenadas(coordenadas a, coordenadas b, coordenadas c) {
    return radioCircuncentro(distancia(a, b), distancia(b, c), distancia(c, a));
}

double rInCircle(double ab, double bc, double ca) {
    return areaTriangulo(ab, bc, ca) / (0.5 * (ab + bc + ca));
}

double rInCircleCordenadas(coordenadas a, coordenadas b, coordenadas c) {
    return rInCircle(distancia(a, b), distancia(b, c), distancia(c, a));
}

void pointsToLine(coordenadas p1, coordenadas p2, linea &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -double(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -double(l.a * p1.x) - p1.y;
    }
}

bool coordenadasIncentro(coordenadas a, coordenadas b, coordenadas c, coordenadas &incentro,
                         double &radio) {
    radio = rInCircleCordenadas(a, b, c);
    if (fabs(radio) < EPS) {
        return false;
    }
    linea l1, l2;
    double ratio = distancia(a, b) / distancia(a, c);
    coordenadas p = trasladar(b, scale(direccion(b, c), ratio / (1 + ratio)));
    pointsToLine(a, p, l1);

    ratio = distancia(b, a) / distancia(b, c);
    p = trasladar(a, scale(direccion(a, c), ratio / (1 + ratio)));
    pointsToLine(b, p, l2);
    seIntersectan(l1, l2, incentro);
    return true;
}

struct circulo {
    coordenadas centro;
    double radio;
    circulo() {
        radio = 0;
    }
    circulo(coordenadas centro, double radio) : centro(centro), radio(radio) {}
};

vector<coordenadas> intersect(linea L, circulo C) {
    double delta = C.centro.x * L.a + C.centro.y * L.b;
    L.c += delta;
    double den = POT(L.a) + POT(L.b);
    double x0 = -L.a * L.c / den;
    double y0 = -L.b * L.c / den;
    double diff = POT(C.radio) - POT(L.c) / den;
    vector<coordenadas> ans;
    if (near(diff, 0)) {
        ans = {coordenadas(x0, y0)};
    } else if (diff < EPS) {
        return {};
    } else {
        double d = sqrt(diff / den);
        ans.push_back(coordenadas(x0 + L.b * d, y0 - L.a * d));
        ans.push_back(coordenadas(x0 - L.b * d, y0 + L.a * d));
    }
    for (coordenadas &P : ans) P += C.centro;
    return ans;
}

vector<coordenadas> intersect(circulo C, linea L) {
    return intersect(L, C);
}

vector<coordenadas> interseccionCircles(circulo c1, circulo c2) {
    if (c1.centro == c2.centro) {
        if (c1.radio == c2.radio) {
            return vector<coordenadas>(3);
        } else {
            return {};
        }
    }
    double d = distancia(c1.centro, c2.centro);
    if (d > c1.radio + c2.radio + EPS) {
        return {};
    }
    if (d < fabs(c1.radio - c2.radio) - EPS) {
        return {};
    }
    coordenadas nuevo(0, 0);
    c2.centro -= c1.centro;
    double x2 = c2.centro.x;
    double y2 = c2.centro.y;
    double a = -2 * x2;
    double b = -2 * y2;
    double c = POT(x2) + POT(y2) + POT(c1.radio) - POT(c2.radio);
    linea l(a, b, c);
    vector<coordenadas> ans = intersect(circulo(nuevo, c1.radio), l);
    for (coordenadas &P : ans) {
        P += c1.centro;
    }
    return ans;
}

struct Triangle {
    coordenadas A, B, C;
    Triangle() {}
    Triangle(coordenadas A, coordenadas B, coordenadas C) : A(A), B(B), C(C) {}
    double area() {
        return fabs(A.cross(B, C)) / 2.0;
    }
};

void escribir(coordenadas a) {
    cout << a.x << " " << a.y << endl;
}

void escribir(coordenadas a, coordenadas b) {
    if (a.x == b.x && a.y == b.y) {
        return;
    }
    if (a.x == b.x || a.y == b.y) {
        cout << ll(a.x) << " " << ll(a.y) << " " << ll(b.x) << " " << ll(b.y) << endl;
        return;
    }
    cout << ll(a.x) << " " << ll(a.y) << " " << ll(a.x) << " " << ll(b.y) << endl;
    cout << ll(a.x) << " " << ll(b.y) << " " << ll(b.x) << " " << ll(b.y) << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<coordenadas> vpa;
    coordenadas nuevo;
    for (ll i = 1; i <= n; i++) {
        cin >> nuevo.x >> nuevo.y;
        vpa.pb(nuevo);
    }
    vpa.pb(vpa[0]);

    // cout << areaPoligono(vpa) << endl;

    // cout << esConvexo(vpa) << endl;

    // cout << puntoEnPoligono({1.0001, 1.00001}, vpa) << endl;
    cout << puntoEnPoligono({0.000, 0.00000}, vpa) << endl;

    // cout << distanciaRecta({0.0, 0.0}, {0.0, 1.0}, {1.0, 0.0}).first << endl;

    // vpa.clear();
    // ll m;
    // cin >> m;
    // for (ll i = 1; i <= m; i++) {
    //     cin >> nuevo.x >> nuevo.y;
    //     vpa.pb(nuevo);
    // }
    // vector<coordenadas> a = convexHull(vpa);
    // cout << "Los puntos son: " << endl;
    // for (ll i = 0; i < a.size() - 1; i++) {
    //     cout << a[i].x << " " << a[i].y << endl;
    // }
    // coordenadas prim, seg, terc;
    // cin >> prim.x >> prim.y >> seg.x >> seg.y >> terc.x >> terc.y;

    // cout << distanciaSegmento(prim, seg, terc).first << " " << endl;
    // cout << distanciaSegmento(prim, seg, terc).second.x << " adasds "
    //      << distanciaSegmento(prim, seg, terc).second.y << endl;

    return 0;
}
