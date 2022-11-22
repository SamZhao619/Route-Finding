#include<iostream>
#include<map>
using namespace std;

typedef struct node{
    int id;
    double x;
    double y;
}node;

double length[4000][4000];
double distc[4000];
int flag[4000];
int pre[4000];
node new_node[5000];

//最短路
void djjk(int first)
{
    distc[first]=0;
    for(int j=0;j<4000;j++)
    {
        int m=-1;//选出最近的点
        for(int i=0;i<4000;i++)
        {
            if(flag[i]==0&&(m==-1||distc[m]>distc[i]))
            {
                m=i;
            }
        }
        flag[m]=1;
        //跟新距离和pre
        for(int i=0;i<4000;i++)
        {
            if(i==m||flag[i])
                continue;
            if(distc[m]+length[i][m]<distc[i])
            {
                distc[i]=distc[m]+length[i][m];
                pre[i]=m;
            }
        }
    }
}

//跟踪路径
void dfs(int last,int first)
{
    if(last==first)
        cout<<new_node[last].id<<" ";
    else
    {
        dfs(pre[last],first);
        cout<<new_node[last].id<<" ";
    }
}


int main()
{
    //初始化length distance flag
    for(int i=0;i<4000;i++)
    {
        distc[i]=100000000.0;
        flag[i]=0;
    }
    for(int i=0;i<4000;i++)
        for(int j=0;j<4000;j++)
        {
            length[i][j]=100000000;
        }
    map<int,int> id;
    map<int,int>::iterator git;
    FILE *fp = fopen("Final_Map.txt","r");
    //文件中node的ID 经纬度 存入node 并建立map
    if (fp)
    {
        char buf[200] = {0};
        for(int i=1;i<=2345;i++)
        {
            fgets(buf,200,fp);
        }
        for(int i=0;i<=3940;i++)
        {
            fgets(buf,200,fp);
            sscanf(buf,"<node id=%d lat=%lf lon=%lf",&new_node[i].id,&new_node[i].x,&new_node[i].y);
            git=id.find(new_node[i].id);
            if(git==id.end())
            {
                id[new_node[i].id]=i;
            }
        }
    }
    fclose(fp);
    //文件中node的ID 经纬度 存入node 并建立map
    fp = fopen("Final_Map.txt","r");
    if (fp)
    {
        char buf[200] = {0};
        fgets(buf,200,fp);
        for(int i=1;i<=2344;i++)
        {
            fgets(buf,200,fp);
            long long linkid;
            int way,node1_id,node2_id;
            double len;
            sscanf(buf,"<link id=%ld node=%d node=%d way=%d length=%lf",&linkid,&node1_id,&node2_id,&way,&len);
            length[id[node2_id]][id[node1_id]]=length[id[node1_id]][id[node2_id]]=len;
            //printf("%d %d %f\n",id[node1_id],id[node2_id],len);
        }
    }
    fclose(fp);
    int first_id,last_id;
    cout<<"input first_id last_id";
    cin>>first_id>>last_id;
    djjk(id[first_id]);
    if(distc[id[last_id]]==100000000)
        cout<<"no way";
    else
    {
        cout<<"length:"<<distc[id[last_id]]<<" ";
        cout<<"route:";
        dfs(id[last_id],id[first_id]);
    }
    return 0;
}

