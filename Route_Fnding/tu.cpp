#include<iostream>
#include<map>

using namespace std;

typedef struct node{
    int id;
    double x;
    double y;
}node;

int main()
{
    node new_node[5000];
    map<int,int> id;
    map<int,int>::iterator git;
    FILE *fp = fopen("Final_Map.txt","r");
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
            printf("%f %f\n%f %f\n\n",new_node[id[node1_id]].y,new_node[id[node1_id]].x,new_node[id[node2_id]].y,new_node[id[node2_id]].x);
        }
    }
    fclose(fp);
    return 0;
}
