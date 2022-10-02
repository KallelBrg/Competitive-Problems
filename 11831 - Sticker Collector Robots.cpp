#include <bits/stdc++.h> 

using namespace std;
int a, b, c;
char mat[105][105];
bool isValid(int x, int y)
{
    if(x>=0 && x<a && y>=0 && y<b && mat[x][y] != '#') return true;
    return false;
}

int main()
{
    cin >> a >> b >> c;
    while(a || b || c)
    {
        char dir;
        int o, d;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                cin >> mat[i][j];
                if(mat[i][j] != '*' && mat[i][j] != '.' &&  mat[i][j] != '#')
                {
                    dir=mat[i][j];
                    o=i;
                    d=j;
                }

            }
        }
        //Aqui eu salvei a direção que meu cara vai estar
        string comandos;
        for(int i=0; i<c; i++)
        {
            char f; cin >> f;
            comandos+=f;
        }
        int ans=0;
        for(int i=0; i<comandos.size(); i++)
        {
            if(dir == 'N')
            {
                if(comandos[i] == 'D')
                {
                    dir='L';
                }
                else if(comandos[i] == 'E')
                {
                    dir='O';
                }
                else
                {// Aqui é pra andar
                    if(isValid(o-1,d))
                    {
                        o=o-1;
                        if(mat[o][d] == '*')
                        {
                            ans++;
                            mat[o][d]='.';
                        }
                    }
                }
            }
            else if(dir == 'O')
            {
                 if(comandos[i] == 'D')
                {
                    dir='N';
                }
                else if(comandos[i] == 'E')
                {
                    dir='S';
                }
                else
                {// Aqui é pra andar
                    if(isValid(o,d-1))
                    {
                        d=d-1;
                        if(mat[o][d] == '*')
                        {
                            ans++;
                            mat[o][d]='.';
                        }
                    }
                }
            }
            else if(dir == 'L')
            {
                 if(comandos[i] == 'D')
                {
                    dir='S';
                }
                else if(comandos[i] == 'E')
                {
                    dir='N';
                }
                else
                {// Aqui é pra andar
                    if(isValid(o,d+1))
                    {
                        d=d+1;
                        if(mat[o][d] == '*')
                        {
                            ans++;
                            mat[o][d]='.';
                        }
                    }
                }
            }
            else
            {//Se entrar aqui ele é SUL
                 if(comandos[i] == 'D')
                {
                    dir='O';
                }
                else if(comandos[i] == 'E')
                {
                    dir='L';
                }
                else
                {// Aqui é pra andar
                    if(isValid(o+1,d))
                    {
                        o=o+1;
                        if(mat[o][d] == '*')
                        {
                            ans++;
                            mat[o][d]='.';
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        cin >> a >> b >> c;

    }

}
