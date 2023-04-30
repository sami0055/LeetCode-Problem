#include<bits/stdc++.h>
using namespace std;
const int N=200;
char graph[N][N];
int Fire[N][N];
int Jane[N][N];
bool visited[N][N];
int R,C;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void resetVis()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            visited[i][j]=false;
        }
    }

}
void Reset()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            Fire[i][j]=INT_MAX;
            Jane[i][j]=INT_MAX;
        }
    }
}
struct Cell{
 int x;
 int y;
};
bool valid(int x,int y)
{
    return x>=1 && x<=R && y>=1 && y<=C && graph[x][y]!='#' && !visited[x][y];

}
bool escape(int x,int y)
{
    return x<1 || x>R || y<1 || y>C;
}
void FireBFS(vector<Cell> fires)
{
    resetVis();
    queue<Cell>q;
    for(auto fire:fires)
    {
        q.push(fire);
        visited[fire.x][fire.y]=1;
        Fire[fire.x][fire.y]=0;

    }
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            if(valid(next_x,next_y))
            {
                Fire[next_x][next_y]=Fire[x][y]+1;
                visited[next_x][next_y]=1;
                q.push({next_x,next_y});
            }

        }
    }

}
int JaneBFS(Cell jane)
{
    resetVis();
    queue<Cell> q;
    q.push(jane);
    visited[jane.x][jane.y]=1;
    Jane[jane.x][jane.y]=0;
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            if(escape(next_x,next_y))
            return Jane[x][y]+1;
            if(valid(next_x,next_y))
            {
                if(Fire[next_x][next_y]>Jane[x][y]+1)
                {
                    Jane[next_x][next_y]=Jane[x][y]+1;
                    visited[next_x][next_y]=1;
                    q.push({next_x,next_y});
                }
            }
        }
    }
    return -1;
}
int main()
{

  int t;
  cin>>t;
  while(t--)
  {
    cin>>R>>C;
    Reset();
    vector<Cell> fires;
    Cell jane;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
           cin>>graph[i][j];
           if(graph[i][j]=='F')
           fires.push_back({i,j});
           else if(graph[i][j]=='J')
           jane={i,j};
        }
    }
    FireBFS(fires);
    if(JaneBFS(jane)==-1)
    cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<JaneBFS(jane)<<endl;
    }

  }
}