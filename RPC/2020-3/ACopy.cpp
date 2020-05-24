#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  long double n, m;
  cin >> n >> m;
  vector<long double> absLive(n, 1.0);
  vector<vector<long double>> absDamage(n + 1, vector<long double>(n + 1, 1.0));
  vector<vector<long double>> mx(n + 1, vector<long double>(n + 1, 1.0));
  vector<pii> op(m);
  FOR(i, 0, m)
  {
    int a, b;
    long double p;
    cin >> a >> b >> p;
    op[i].F = a;
    op[i].S = b;

    long double probAssLive = 1.0;

    FOR(i, 1, n + 1)
    {

      /*
      
      Podemos guardar todos los casos y cuando vayan a atacar a nuestro atacante so,amente lo 
      ignoramos y de esa forma volvemos a caulcular todo suponiendo que nuestro compilla esta vivo
      Si creo que esa es la solucion
      puedes guardar este codigo?
      lo voy a borrar 

      */
      if (b != i)
      {
        probAssLive *= mx[i][a];
      }

      else
        probAssLive *= absDamage[b][a];
    }
    absDamage[a][b] *= 1.0 - p;

    mx[a][b] -= mx[a][b] * p * probAssLive;

    /*
      3 4
      3 2 .5
      3 1 .5
      1 2 .5
      2 3 .5

      por ejemplo matrix[Asesino][Asegura que esta vivo][Asesinado]
      Esto ya se esta volviendo muy complicado
      
      Que se te ocurre?
      es que nada mas es a~nadirle una capa de si uno esta vivo o no
      creo que no va por ahi, no creo que sea tan complejo

    */
  }
  FOR(i, 1, n + 1)
  {
    long double ans = 1.0;
    FOR(j, 1, n + 1)
    {
      ans *= mx[j][i];
    }
    cout << fixed << setprecision(12) << ans << ENDL;
  }

  return 0;
}
/*

eso que significa jajaja
0.77-(0.77*0.99*0.01)

////
2 3
1 2 0.23
2 1 0.99
1 2 0.99

0.2377000000
0.7623770000


*/