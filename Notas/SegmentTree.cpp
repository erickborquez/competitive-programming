
// RMQ = Range Minimum Query
// u = nodo en el que estas
#include <bits/stdc++.h>

using namespace std;

int mx[1000]; /// Arreglo del segment tree
int a[1000];  /// Arreglo donde estna los valores iniciales
void build(int u, int l, int r)
{
  if (l == r)
  {
    mx[u] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(2 * u, l, m);
  build(2 * u + 1, m + 1, r);
  pull(u);
}

void pull(int u)
{
  mx[u] = max(mx[2 * u], mx[2 * u + 1]);
  // sum[u] = sum[2 * u] + sum[2 * u + 1]; para poder hacer mas de una operacin con el segment tree tendrimaos que declararlo desde el build
}

int query(int u, int l, int r, int ll, int rr)
{
  if (rr < l || r < ll || r < l)
  {
    return -INFINITY;
  }
  if (ll <= l && r <= rr)
  {
    return mx[u];
  }
  int m = (l + r) / 2;
  return max(query(u * 2, l, m, ll, rr), query(u * 2 + 1, m + 1, r, ll, rr));
}

void update(int u, int l, int r, int pos, int val)
{
  if (l == r)
  {
    mx[u] = val;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m)
  {
    update(2 * u, l, m, pos, val);
  }
  else
  {
    update(2 * u + 1, m + 1, r, pos, val);
  }
  pull(u);
}

//////////
struct segTree
{

  vector<int> mx; // Aqui va a estar el segment tree
  segTree(int nn)
  {
    mx.resize(4 * nn);
    build(1, 1, nn);
  }
};

/////////////// lazy segment tree
// Te permite cambiar todos los valores en una rango de posiciones
// Es en tiempo constante
// Se van a hacer las actualizaciones en un segundo arbol que es el lazy
// El arbol principal no va a ser actualiado ahsta que no hagas queries en un rango donde se haya actualizado.

void push(int u, int l, int r)
{
  if (lazy[u] != 0)
  {
    sum[u] = (l - r + 1) * lazy[u];
    if (l != r)
    {
      lazy[2 * u] = lazy[u];
      lazy[2 * u + 1] = lazy[u];
    }
    lazy[u] = 0;
  }
}
//Este update es cuando tiene sun ragno que quieres actualizar, solo en lazy
void update(int u, int l, int r, int ll, int rr, int val)
{
  push(u, l, r);
  if (rr < l || r < ll || r < l)
  {
    return;
  }
  if (ll <= l && r <= rr)
  {
    lazy[u] = val;
    push(u, l, r);
  }

  int m = (l + r) / 2;
  update(2 * u, l, m, ll, rr, val);
  update(2 * u + 1, m + 1, r, ll, rr, val);
  pull(u);
}

int query(int u, int l, int r, int ll, int rr)
{
  push(u, l, r);
  if (rr < l || r < ll || r < l)
    return;
  if (ll <= l && r <= rr)
  {
    push(u, l, r);
    return mx[u];
  }
  int m = (l + r) / 2;
  return query(2 * u, l, r, ll, rr) + query(2 * u + 1, l, r, ll, rr);
}

/**/