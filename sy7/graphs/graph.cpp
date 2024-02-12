//
// Created by xiaodian& on 2022/11/8.
//

#include "graph"

mgraph::mgraph(graphtype k):vexmun(0), arcnum(0), kind(k)
{
    ////这里使得时间复杂度在初始化即为 MAX^2, 若改为在输入时进行，则为 vexnum^2
    int init;
    if(kind == DG || kind == UDG)
        init = 0;
    else init = ENDLESS;
    for(int i=0; i<MAX_NODE_NUM; i++)
        for(int j=0; j<MAX_NODE_NUM; j++)
            arcs[i][j] = init;
    if(kind == DN || kind == UDN)
        for(int i=0; i<MAX_NODE_NUM; i++)
            arcs[i][i] = 0;
}

void mgraph::DFS(int start)
{
    for(int i=0; i<vexmun; i++)
        visited[i] = false;
    if(kind == DG || kind == UDG)
        DFS_heart_G(start);
    else
        DFS_heart_N(start);
}
void mgraph::DFS_heart_G(int start) {
    //这里以输出作为一次访问，访问过后visited中标为true
    visited[start] = true;
    cout<<vexs[start]<<" ";
    //访问所有的邻接结点
    for(int i=0; i<vexmun; i++){
        if(visited[i] == false){//如果没访问过
            if(arcs[start][i] == 1)//且为其邻接结点
                DFS_heart_G(i);//以它为起点进行深度优先遍历
        }
    }
}
void mgraph::DFS_heart_N(int start) {
    visited[start] = true;
    cout<<vexs[start]<<" ";
    for(int i=0; i<vexmun; i++){
        if(visited[i] == false){
            if(arcs[start][i] != ENDLESS)
                DFS_heart_N(i);
        }
    }
}

void mgraph::BFS(int start)
{
    for(int i=0; i<vexmun; i++)
        visited[i] = false;
    if(kind == DG || kind == UDG)
        BFS_heart_G(start);
    else
        BFS_heart_N(start);
}
void mgraph::BFS_heart_G(int start) {
    int queue[vexmun];
    int front = -1;
    int rear = -1;
    queue[++rear] = start;
    visited[start] = true;
    while (front < rear){
        int t = queue[++front];
        cout<<vexs[t]<<"  ";
        for(int i=0; i<vexmun; i++){
            if(visited[i] == false){
                if(arcs[t][i] == 1){
                    queue[++rear] = i;
                    visited[i] = true;
                }
            }
        }
    }
}
void mgraph::BFS_heart_N(int start) {
    int queue[vexmun];
    int front = -1;
    int rear = -1;
    queue[++rear] = start;
    visited[start] = true;
    while (front < rear){
        int t = queue[++front];
        cout<<vexs[t]<<"  ";
        for(int i=0; i<vexmun; i++){
            if(visited[i] == false){
                if(arcs[t][i] != ENDLESS){
                    queue[++rear] = i;
                    visited[i] = true;
                }
            }
        }
    }
}

void mgraph::Floyd() {
    int dist[vexmun][vexmun];
    int path[vexmun][vexmun];
    for(int i=0; i<vexmun; i++)
        for(int j=0; j<vexmun; j++){
            dist[i][j] = arcs[i][j];
            if(i==j || dist[i][j] == ENDLESS)
                path[i][j] = -1;
            else
                path[i][j] = i;
        }
    for(int k=0; k<vexmun; k++){
        for(int i=0; i<vexmun; i++)
            for(int j=0; j<vexmun; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
    }
    cout<<"dist:"<<endl;
    for(int i=0; i<vexmun; i++){
        for(int j=0; j<vexmun; j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"path:"<<endl;
    for(int i=0; i<vexmun; i++){
        for(int j=0; j<vexmun; j++)
            cout<<path[i][j]<<"\t";
        cout<<endl;
    }
}

void mgraph::min_path(int u, int v) {
    for(int i=0; i<vexmun; i++)
        visited[i] = false;
    min_path_heart(u,v);
}

void mgraph::min_path_heart(int u, int v) {
    fmp queue[vexmun];
    int front = -1;
    int rear = -1;
    queue[++rear] = {-1,u};
    visited[u] = true;
    while(front < rear){
        fmp t = queue[++front];
        int p = t.data;
        if(p == v){
            while(t.last != -1){
                cout<<p<<" ";
                t = queue[t.last];
                p = t.data;
            }
            cout<<u;
            return;
        }
        for(int i=0; i<vexmun; i++)
            if(visited[i] == false){
                if(kind == DG || kind == UDG){
                    if(arcs[p][i] == 1){
                        queue[++rear] = {front,i};
                        visited[i] = true;
                    }
                }
                else{
                    if(arcs[p][i] != ENDLESS){
                        queue[++rear] = {front,i};
                        visited[i] = true;
                    }
                }
            }
    }
}

void mgraph::prim(int u) {
    int lowcost[vexmun];
    int closest[vexmun];
    for(int i=0; i<vexmun; i++){
        lowcost[i] = ENDLESS;
        closest[i] = -1;
    }
    lowcost[u] = 0;
    for(int i=1; i<vexmun; i++){
        for(int i=0; i<vexmun; i++){
            if(lowcost[i] != 0){
                if(arcs[u][i] != ENDLESS && lowcost[i] > arcs[u][i]){
                    lowcost[i] = arcs[u][i];
                    closest[i] = u;
                }
            }
        }

        int k;
        int min = ENDLESS;
        for(int i=0; i<vexmun; i++){
            if(lowcost[i] != 0){
                if(lowcost[i] < min){
                    k = i;
                    min = lowcost[i];
                }
            }
        }

        cout<<closest[k]<<"-"<<k<<" ";
        if(i%4 == 0)
            cout<<endl;
        lowcost[k] = 0;

        u = k;
    }
}


istream & operator>>(istream & cin, mgraph & a)
{
    int i,j,q;
    cout<<"how many vexs:  ";
    cin>>a.vexmun;
    cout<<"then input them in seq:"<<endl;
    for(int m=0; m<a.vexmun; m++)
        cin>>a.vexs[m];
    cout<<"how many arcs:  ";
    cin>>a.arcnum;
    cout<<"then the arcs:"<<endl;
    for(int m=0; m<a.arcnum; m++){
        cin>>i>>j;
        if(a.kind == DN || a.kind == UDN){
            cin>>q;
            a.arcs[i][j] = q;
            if(a.kind == UDN)
                a.arcs[j][i] = q;
        } else{
            a.arcs[i][j] = 1;
            if(a.kind == UDG)
                a.arcs[j][i] = 1;
        }
    }
    return cin;
}
ostream & operator<<(ostream & cout, mgraph & m)
{
    if(m.kind == DN || m.kind == UDN){
        for(int i=0; i<m.vexmun; i++){
            for(int j=0; j<m.vexmun; j++){
                if(m.arcs[i][j] == ENDLESS)
                    cout<<"~";
                else  cout<<m.arcs[i][j];
                cout<<"  ";
            }
            cout<<endl;
        }
        return cout;
    }
    for(int i=0; i<m.vexmun; i++){
        for(int j=0; j<m.vexmun; j++)
            cout<<m.arcs[i][j]<<"  ";
        cout<<endl;
    }
    return cout;
}



void algraph::copy(pnode & a,const pnode & b){
    if(b != nullptr){
        a = new node;
        a->adjvex = b->adjvex;
        if(kind == DN || kind == UDN)
            a->q = b->q;
        copy(a->next_adjvex, a->next_adjvex);
    } else a = nullptr;
}
void algraph::destroy(pnode & p){
    if(p != nullptr){
        destroy(p->next_adjvex);
        delete p;
    }
}

algraph::algraph(graphtype k)
{
    kind = k;
    vexnum = 0;
    arcnum = 0;
    for(int i=0; i<MAX_NODE_NUM; i++){
        vexs[i].firstarc = nullptr;
    }
}
algraph::algraph(const algraph & g)
{
    int i;
    kind = g.kind;
    vexnum = g.vexnum;
    arcnum = g.arcnum;
    for(i=0; i<vexnum; i++){
        vexs[i].data = g.vexs[i].data;
        vexs[i].num_in = g.vexs[i].num_in;
        copy(vexs[i].firstarc,g.vexs[i].firstarc);
    }
    while(i<MAX_NODE_NUM){
        vexs[i++].firstarc = nullptr;
    }
}
algraph & algraph::operator=(const algraph & g)
{
    if(this == &g)
        return *this;
    this->~algraph();
    int i;
    kind = g.kind;
    vexnum = g.vexnum;
    arcnum = g.arcnum;
    for(i=0; i<vexnum; i++){
        vexs[i].data = g.vexs[i].data;
        vexs[i].num_in = g.vexs[i].num_in;
        copy(vexs[i].firstarc,g.vexs[i].firstarc);
    }
    while(i<MAX_NODE_NUM){
        vexs[i++].firstarc = nullptr;
    }
    return *this;
}
algraph::~algraph()
{
    for(int i=0; i<vexnum; i++){
        destroy(vexs[i].firstarc);
    }
}

istream & operator>>(istream & cin, algraph & g){
    cout<<"how many vertexs: ";
    cin>>g.vexnum;
    cout<<"how may arcs: ";
    cin>>g.arcnum;
    if(g.kind == DN || g.kind == UDN){
        for(int i=0; i<g.vexnum; i++){
            cout<<i<<"-";
            cin>>g.vexs[i].data;

            cout<<"how many adjvex: ";
            int num_out;
            cin>>num_out;
            for(int j=1; j<=num_out; j++){
                algraph::pnode p = new algraph::node;
                cin>>p->adjvex>>p->q;
                p->next_adjvex = g.vexs[i].firstarc;
                g.vexs[i].firstarc = p;
            }
        }
    } else{
        for(int i=0; i<g.vexnum; i++){
            cout<<i<<"-";
            cin>>g.vexs[i].data;

            cout<<"how many adjvex: ";
            int num_out;
            cin>>num_out;
            for(int j=1; j<=num_out; j++){
                algraph::pnode p = new algraph::node;
                cin>>p->adjvex;
                p->next_adjvex = g.vexs[i].firstarc;
                g.vexs[i].firstarc = p;
            }
        }
    }
    return cin;
}
ostream & operator<<(ostream & cout, algraph & g)
{
    if(g.kind == UDG){
        for(int i=0; i<g.vexnum; i++){
            algraph::pnode p = g.vexs[i].firstarc;
            vertextype a = g.vexs[i].data;
            while (p){
                cout<<a<<"--"<<g.vexs[p->adjvex].data<<"  ";
                p = p->next_adjvex;
            }
            cout<<endl;
        }
        return cout;
    }
    if(g.kind == DG){
        for(int i=0; i<g.vexnum; i++){
            algraph::pnode p = g.vexs[i].firstarc;
            vertextype a = g.vexs[i].data;
            while (p){
                cout<<a<<"->"<<g.vexs[p->adjvex].data<<"  ";
                p = p->next_adjvex;
            }
            cout<<endl;
        }
        return cout;
    }
    if(g.kind == UDN){
        for(int i=0; i<g.vexnum; i++){
            algraph::pnode p = g.vexs[i].firstarc;
            vertextype a = g.vexs[i].data;
            while (p){
                cout<<a<<"--"<<g.vexs[p->adjvex].data<<"-"<<p->q<<"  ";
                p = p->next_adjvex;
            }
            cout<<endl;
        }
        return cout;
    }
    if(g.kind == DN){
        for(int i=0; i<g.vexnum; i++){
            algraph::pnode p = g.vexs[i].firstarc;
            vertextype a = g.vexs[i].data;
            while (p){
                cout<<a<<"->"<<g.vexs[p->adjvex].data<<"-"<<p->q<<"  ";
                p = p->next_adjvex;
            }
            cout<<endl;
        }
        return cout;
    }
}



////一些算法实现
void algraph::DFS(void visit(vertextype &), int start)
{
    //初始化
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    DFS_heart(visit,start);
}
inline void algraph::DFS_heart(void visit(vertextype &), int start)
{
    visit(vexs[start].data);
    visited[start] = true;

    //与图的数组表示法实现的仅有这一点不同，数组是遍历那一行找邻接结点，这里是遍历邻接表中的链表结构访问邻接结点
    pnode p = vexs[start].firstarc;
    while(p){
        if(visited[p->adjvex] == false)
            DFS_heart(visit,p->adjvex);
        p = p->next_adjvex;
    }
}

void algraph::BFS(void visit(vertextype &), int start)
{
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    BFS_heart(visit,start);
}
inline void algraph::BFS_heart(void visit(vertextype &), int start)
{
    int queue[vexnum];
    int front;
    int rear;
    front = rear = -1;
    queue[++rear] = start;
    visited[start] = true;
    int t;
    pnode p;
    while(front != rear){
        t = queue[++front];
        visit(vexs[t].data);
        p = vexs[t].firstarc;
        while(p){
            if(visited[p->adjvex] == false){
                queue[++rear] = p->adjvex;
                visited[p->adjvex] = true;
            }
            p = p->next_adjvex;
        }
    }
}


void algraph::DFS_All(void visit(vertextype &), int start)
{
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    DFS_heart(visit,start);
    cout<<endl;
    for(int i=0; i<vexnum; i++){
        if(visited[i] == false){
            DFS_heart(visit,i);
            cout<<endl;
        }
    }
}
void algraph::BFS_All(void visit(vertextype &), int start)
{
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    BFS_heart(visit,start);
    cout<<endl;
    for(int i=0; i<vexnum; i++){
        if(visited[i] == false){
            BFS_heart(visit,i);
            cout<<endl;
        }
    }
}


bool algraph::link() {
    if(kind == UDN || kind == UDG){
        for(int i=0; i<vexnum; i++)
            visited[i] = false;
        DFS_heart(fun,0);
        for(int i=0; i<vexnum; i++){
            if(visited[i] == false)
                return false;
        }
        return true;
    }
    else{
        for(int start=0; start<vexnum; start++){
            for(int i=0; i<vexnum; i++)
                visited[i] = false;
            BFS_heart(fun,start);
            for(int i=0; i<vexnum; i++){
                if(visited[i] == false)
                    return false;
            }
        }
        return true;
    }
}

bool algraph::link(int u, int v) {
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    return link_heart(u,v);
}
inline bool algraph::link_heart(int u, int v) {
    if(u == v)
        return true;
    visited[u] = true;
    pnode p = vexs[u].firstarc;
    while (p){
        if(visited[p->adjvex] == false)
            if(link_heart(p->adjvex,v))
                return true;
        p = p->next_adjvex;
    }
}


bool algraph::link2(int u, int v) {
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    int que[vexnum];
    int front = -1;
    int rear = -1;
    que[++rear] = u;
    visited[u] = true;
    while(front != rear){
        int t = que[++front];
        if(t == v)
            return true;
        pnode p = vexs[t].firstarc;
        while(p){
            if(visited[p->adjvex] == false){
                que[++rear] = p->adjvex;
                visited[p->adjvex] = true;
            }
            p = p->next_adjvex;
        }
    }
    return false;
}

inline bool algraph::path_heart(int u, int v, int path[], int d) {
    path[++d] = u;
    visited[u] = true;
    if(u == v){
        for(int i=0; i<d; i++)
            cout<<path[i]<<"-";
        cout<<path[d]<<endl;
        return true;
    }
    pnode p = vexs[u].firstarc;
    while (p){
        if(visited[p->adjvex] == false){
            if(path_heart(p->adjvex,v,path,d))
                return true;
        }
        p = p->next_adjvex;
    }
}
inline void algraph::path_all_heart(int u, int v, int path[], int d) {
    path[++d] = u;
    visited[u] = true;
    if(u == v){
        for(int i=0; i<d; i++)
            cout<<path[i]<<"-";
        cout<<path[d]<<endl;
        visited[v] = false;
        return;
    }
    pnode p = vexs[u].firstarc;
    while (p){
        if(visited[p->adjvex] == false)
            path_all_heart(p->adjvex,v,path,d);
        p = p->next_adjvex;
    }
    visited[u] = false;
}
inline void algraph::path_min_heart(int u, int v, int path[], int path_min[], int d, int & min) {
    path[++d] = u;
    visited[u] = true;
    if(u == v){
        if(d<min){
            for(int i=0; i<=d; i++)
                path_min[i] = path[i];
            min = d;
        }
        visited[v] = false;
        return;
    }
    if(d>=min-1){
        visited[u] = false;
        return;
    }
    pnode p = vexs[u].firstarc;
    while (p){
        if(visited[p->adjvex] == false)
            path_min_heart(p->adjvex,v,path,path_min,d,min);
        p = p->next_adjvex;
    }
    visited[u] = false;
}
inline void algraph::min_path_heart(int u, int v) {
    min_path_queue que[vexnum];
    int front,rear;
    front = rear = -1;
    que[++rear] = {u,-1};
    visited[u] = true;
    while(front != rear){
        if(que[++front].data == v){
            cout<<v<<" ";
            int t = que[front].parent;
            while(t != -1){
                cout<<que[t].data<<" ";
                t = que[t].parent;
            }
            return;
        }
        pnode p = vexs[que[front].data].firstarc;
        while(p){
            if(visited[p->adjvex] == false){
                que[++rear] = {p->adjvex,front};
                visited[p->adjvex] = true;
            }
            p = p->next_adjvex;
        }
    }
}

void algraph::path(int u, int v) {
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    int path[vexnum];
    path_heart(u,v,path,-1);
}
void algraph::path_all(int u, int v){
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    int path[vexnum];
    path_all_heart(u,v,path,-1);
}
void algraph::path_min(int u, int v){
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    int min = vexnum;
    int path[vexnum];
    int path_min[vexnum];
    path_min_heart(u,v,path,path_min,-1,min);
    for(int i=0; i<min; i++)
        cout<<path_min[i]<<"-";
    cout<<path_min[min];
}
void algraph::min_path(int u, int v) {
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    min_path_heart(u,v);
}


void algraph::prim(int v) {
    int count = 1;
    int closest[vexnum];
    int lowcost[vexnum];
    for(int i=0; i<vexnum; i++){
        lowcost[i] = ENDLESS;
    }
    lowcost[v] = 0;
    while(count < vexnum){
        pnode p = vexs[v].firstarc;
        while (p){
            if(p->q<lowcost[p->adjvex]){
                lowcost[p->adjvex] = p->q;
                closest[p->adjvex] = v;
            }
            p = p->next_adjvex;
        }
        int min = ENDLESS;
        int k;
        for(int i=0; i<vexnum; i++){
            if(lowcost[i]!=0 && lowcost[i]<min){
                k = i;
                min = lowcost[i];
            }
        }
        cout<<closest[k]<<"-"<<k<<"  ";
        lowcost[k] = 0;
        v = k;
        count++;
        if(count % 4 == 0)
            cout<<endl;
    }
}

void algraph::kruskal(int v) {
    int link[vexnum];
    for(int i=0; i<vexnum; i++)
        link[i] = i;
    edge a[arcnum];
    int n = 0;
    for(int i=0,end=vexnum-1; i<end; i++){
        pnode p = vexs[i].firstarc;
        while (p){
            if(p->adjvex > i)
               a[n++] = {i,p->adjvex,p->q};
            p = p->next_adjvex;
        }
    }
    ////sort edge
    for(int i=1,end=arcnum-1; i<=end; i++){
        for(int j=0; j<arcnum-i; j++){
            if(a[j].weight > a[j+1].weight)
                swap(a[j],a[j+1]);
        }
    }
    ////end
    n = 0;
    int count = 0;
    int end = vexnum-1;
    while(count < end){
        if(link[a[n].from] != link[a[n].to]){
            cout<<a[n].from<<"-"<<a[n].to<<"  ";
            count++;
            if(count % 3 == 0)
                cout<<endl;
            int t = link[a[n].to];
            int q = link[a[n].from];
            for(int i=0; i<vexnum; i++)
                if(link[i] == t)
                    link[i] = q;
        }
        n++;
    }
}

void algraph::dijkstra(int u, int v)
{
    pnode p;
    for(int i=0; i<vexnum; i++){
        visited[i] = false;
        dijk_path[i] = u;
        dist[i] = ENDLESS;
    }
    visited[u] = true;
    dist[u] = 0;
    p = vexs[u].firstarc;
    while(p){
        dist[p->adjvex] = p->q;
        p = p->next_adjvex;
    }
    for(int i=1,end=vexnum-1; i<=end; i++){
        int min_dist = ENDLESS;
        int t;
        for(int i=0; i<vexnum; i++){
            if(visited[i] == false && dist[i] < min_dist){
                t = i;
                min_dist = dist[i];
            }
        }
        visited[t] = true;
        p = vexs[t].firstarc;
        while (p){
            if(visited[p->adjvex] == false){
                if(dist[p->adjvex] > dist[t]+p->q){
                    dist[p->adjvex] = dist[t]+p->q;
                    dijk_path[p->adjvex] = t;
                }
            }
            p = p->next_adjvex;
        }
    }
    cout<<dist[v]<<"--";
    int last = v;
    while(last != u){
        cout<<last<<"<-";
        last = dijk_path[last];
    }
    cout<<u;

    return;
}

void algraph::tuopusort() {
    cout<<"for tuopusort, input the num_in in seq: "<<endl;
    for(int i=0; i<vexnum; i++){
        cin>>vexs[i].num_in;
    }
    int du[vexnum];
    int stack[vexnum];
    int top = -1;
    for(int i=0; i<vexnum; i++){
        du[i] = vexs[i].num_in;
        if(du[i] == 0){
            stack[++top] = i;
        }
    }
    int t;
    while(top>=0){
        t = stack[top--];
        cout<<t<<" ";
        pnode p = vexs[t].firstarc;
        while (p){
            du[p->adjvex]--;
            if(du[p->adjvex] == 0)
                stack[++top] = p->adjvex;
            p = p->next_adjvex;
        }
    }
}

void algraph::max_path_deep(int u, int v) {
    for(int i=0; i<vexnum; i++)
        visited[i] = false;
    int path[vexnum];
    int key[vexnum];
    int max = -1;
    int len = -1;
    max_path(u,v,path,0,0,key,len,max);
    for(int i=0; i<=len; i++)
        cout<<key[i]<<" ";
    cout<<"max = "<<max;
}
void algraph::max_path(int u, int v, int path[], int d, int time, int key[], int & len, int & max)
{
    path[d] = u;
    visited[u] = true;
    if(u == v){
        if(time>max){
            max = time;
            for(int i=0; i<=d; i++)
                key[i] = path[i];
            len = d;
        }
        visited[v] = false;
        return;
    }
    pnode p = vexs[u].firstarc;
    while(p){
        if(visited[p->adjvex] == false){
            max_path(p->adjvex,v,path,d+1,time+p->q,key,len,max);
        }
        p = p->next_adjvex;
    }
    visited[u] = false;
}

void algraph::max_path_critical(int u, int v){
    cout<<"for tuopusort, input the num_in in seq: "<<endl;
    for(int i=0; i<vexnum; i++){
        cin>>vexs[i].num_in;
    }
    int stack[vexnum];
    int top = -1;
    int cost[vexnum];
    int path[vexnum];
    int in[vexnum];
    for(int i=0; i<vexnum; i++){
        cost[i] = -1;
        path[i] = -1;
        in[i] = vexs[i].num_in;
    }
    cost[u] = 0;
    stack[++top] = u;
    while(top>=0){
        int t = stack[top--];
        pnode p = vexs[t].firstarc;
        while(p){
            if(cost[p->adjvex] < cost[t]+p->q){
                cost[p->adjvex] = cost[t]+p->q;
                path[p->adjvex] = t;
            }
            in[p->adjvex]--;
            if(in[p->adjvex] == 0)
                stack[++top] = p->adjvex;
            p = p->next_adjvex;
        }
    }
    cout<<cost[v]<<endl;
    for(;path[v] != -1; v = path[v])
        cout<<v<<" ";
    cout<<u<<endl;
}

void algraph::critical_path(int u) {
    cout<<"for tuopusort, input the num_in in seq: "<<endl;
    for(int i=0; i<vexnum; i++){
        cin>>vexs[i].num_in;
    }
    int que_stack[vexnum];
    int front = -1;
    int rear = -1;
    int earlist[vexnum];
    int last[vexnum];
    int in[vexnum];
    for(int i=0; i<vexnum; i++){
        earlist[i] = -1;
        last[i] = ENDLESS;
        in[i] = vexs[i].num_in;
    }
    earlist[u] = 0;
    que_stack[++rear] = u;
    while(front < rear){
        int t = que_stack[++front];
        pnode p = vexs[t].firstarc;
        while(p){
            if(earlist[t]+p->q > earlist[p->adjvex]){
                earlist[p->adjvex] = earlist[t] + p->q;
            }
            in[p->adjvex]--;
            if(in[p->adjvex] == 0)
                que_stack[++rear] = p->adjvex;
            p = p->next_adjvex;
        }
    }
    int top = rear;
    last[top] = earlist[top];
    for(; top >=0; top--){
        int t = que_stack[top];
        pnode p = vexs[t].firstarc;
        for(; p!= nullptr; p = p->next_adjvex){
            if(last[p->adjvex] - p->q < last[t])
                last[t] = last[p->adjvex] - p->q;
        }
    }

    cout<<"关键活动为:"<<endl;
    pnode p;
    int t;
    for(int i=0; i<vexnum; i++){
        if(earlist[i] == last[i]){
            p = vexs[i].firstarc;
            while (p){
                t = p->adjvex;
                if(earlist[t] == last[t])
                    cout<<i<<"-"<<t<<" ";
                p = p->next_adjvex;
            }
        }
    }
}
