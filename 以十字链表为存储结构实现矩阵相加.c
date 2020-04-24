//
// Created by sqx08 on 2020/4/24.
//
/*#include<stdio.h>
#include<stdlib.h>
typedef struct OLNode
{
	int r,c,e;
	struct OLNode *right, *down;
}OLNode,*OLink;
typedef struct
{
	OLink rhead[100], chead[100];
	int ru,cu,tu;
}CrossList;
CrossList *M;
void init(CrossList *M,int n)
{
	int r,c,t;
	OLink s;
	while(n--)
	{
		OLink q=(OLink)malloc(sizeof(OLNode));
		scanf("%d%d%d",&r,&c,&t);
		q->r=r;
		q->c=c;
		q->e=t;
		if(M->rhead[r]==NULL||M->rhead[r]->c>c)
		{
			q->right=M->rhead[r];
			M->rhead[r]=q;
			M->ru++;
		}
		else
		{
			for(s=M->rhead[r];s->right&&s->right->c<c;s=s->right);
			q->right=s->right;
			s->right=q;
			M->ru++;
		}
		if(M->chead[c]==NULL||M->chead[c]->c>c)
		{
			q->down=M->chead[c];
			M->chead[c]=q;
			M->cu++;
		}
		else
		{
			for(s=M->chead[c];s->down&&s->down->r<r;s=s->down);
			q->down==s->down;
			s->down=q;
			M->cu++;
		}
	}
}
void add(CrossList *M,int n)
{
	OLink l,t,p;
	int flag,flag1;
	int i,x,y,z;
	while(n--)
	{
		scanf("%d%d%d",&x,&y,&z);
		OLink s=(OLink)malloc(sizeof(OLNode));
		OLink l,p,t;
		s->r=x;
		s->c=y;
		s->e=z;
		flag=1;
		flag1=1;
		if(M->rhead[x]!=NULL)
		{
			for(l=M->rhead[x];l;l=l->right)
			{
				if(l->c==s->c)
				{
					l->e+=s->e;
					if(l->e==0)
					{
						if(flag1)
						{
							flag1=0;
							M->rhead[x]=M->rhead[x]->right;
						}
						else
						{
							p=M->rhead[x];
							while(p->right!=l)
							{
								p=p->right;
							}
							p->right=l->right;
						}
						for(t=M->chead[y];t;t=t->down)
						{
							if(t==M->chead[y])
							{
								M->chead[y]=t->right;
								break;
							}
							else
							{
								p=M->chead[y];
								while(p->down!=l)
								{
									p=p->down;
								}
								p->down=l->down;
								break;
							}
						}
						free(l);
					}
					flag=0;
					break;
				}
			}
		}
		if(flag)//flag:0-> 此元素已删除    flag1:0->首元素删除，此行或列为空
		{
			if(M->rhead[x]==NULL)
			{
				s->right=M->rhead[x];
				M->rhead[x]=s;
				M->ru++;
			}
			else if(M->rhead[x]->c>y)
			{
				s->right=M->rhead[x];
				M->rhead[x]=s;
			}
			else
			{
				for(l=M->rhead[x];l->right && l->right->c < y;l=l->right);
				s->right=l->right; l->right=s;
			}
			if(M->chead[y]==NULL)
			{
				s->down=M->chead[y];
				M->chead[y]=s;
				M->cu++;
			}
			else if(M->chead[y]->r > x)
			{
				s->down = M->chead[y];
				M->chead[y]=s;
			}
			else
			{
				for(l=M->chead[y];l->down && l->down->r < x;l=l->down);
				s->down=l->down; l->down=s;
			}
		}
	}
}
void display(CrossList *M)
{
	int i;
	OLink r,t;
	for(i=0;i<M->ru;i++)
	{
		if(M->rhead[i])
		{
			for(t=M->rhead[i];t;t=t->right)
			{
				printf("%d %d %d\n",t->r,t->c,t->e);
			}
		}
	}
}
int main()
{
	int max;
	M=(CrossList *)malloc(sizeof(CrossList));
	int m,n,t1,t2;
	scanf("%d%d%d%d",&m,&n,&t1,&t2);
	M->ru=0;
	M->cu=0;
	if(m>n)
		max=m;
	else
		max=n;
	for(int i=0;i<max;i++)
	{
		M->rhead[i]=NULL;
		M->chead[i]=NULL;
	}
	init(M,t1);
	add(M,t2);
	display(M);
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>

typedef struct OLNode{
    int row,col;
    int num;
    struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct CrossList{
    OLink rHead[100],cHead[100];
    int ru,cu,tu;
}CrossList;

CrossList *M;

void init(CrossList *M,int cnt){
    int x,y,z;
    OLink r;
    while(cnt--){
        OLink q=(OLink)malloc(sizeof(OLNode));
        scanf("%d%d%d",&x,&y,&z);
        q->row=x;q->col=y;q->num=z;
        if(M->rHead[x]==NULL||M->rHead[x]->col > y){
            q->right=M->rHead[x]; M->rHead[x]=q;
            M->ru++;
        }
        else{
            for(r=M->rHead[x];r->right && r->right->col < y;r=r->right);
            q->right=r->right; r->right=q;
            M->ru++;
        }//完成行插入
        if(M->cHead[y]==NULL||M->cHead[y]->row > x){
            q->down=M->cHead[y]; M->cHead[y]=q;
            M->cu++;
        }
        else{
            for(r=M->cHead[y];r->down && r->down->row < x;r=r->down);
            q->down=r->down; r->down=q;
            M->cu++;
        }//完成列插入
    }
}

void add(CrossList *M,int cnt){
    OLink l,t,p;
    int flag,flag1;
    int i,x,y,z;
    while(cnt--){
        scanf("%d%d%d",&x,&y,&z);
        OLink r=(OLink)malloc(sizeof(OLNode));
        r->row=x; r->col=y; r->num=z;
        flag=1;  flag1=1;
        if(M->rHead[x] != NULL){
            for(l=M->rHead[x];l;l=l->right){
                if(l->col == r->col){
                    l->num+=r->num;
                    if(l->num == 0){//删除0
                        if(flag1){
                            flag1=0;
                            M->rHead[x] = M->rHead[x]->right;
                        }
                        else{
                            p = M->rHead[x];
                            while(p->right != l){
                                p = p->right;
                            }
                            p->right = l->right;
                        }
                        for(t = M->cHead[y];t;t=t->down){
                            if(t == M->cHead[y]){
                                M->cHead[y] = t->right;
                                break;
                            }
                            else{
                                p = M->cHead[y];
                                while(p->down != l){
                                    p = p->down;
                                }
                                p->down = l->down;
                                break;
                            }
                        }
                        free(l);
                    }
                    flag=0; break;
                }
            }
        }
        if(flag){
            if(M->rHead[x]==NULL){
                r->right=M->rHead[x];
                M->rHead[x]=r;
                M->ru++;
            }
            else if(M->rHead[x]->col > y){
                r->right=M->rHead[x];
                M->rHead[x]=r;
            }
            else{
                for(l=M->rHead[x];l->right && l->right->col < y;l=l->right);
                r->right=l->right; l->right=r;
            }
            if(M->cHead[y]==NULL){
                r->down=M->cHead[y];
                M->cHead[y]=r;
                M->cu++;
            }
            else if(M->cHead[y]->row > x){
                r->down = M->cHead[y];
                M->cHead[y]=r;
            }
            else{
                for(l=M->cHead[y];l->down && l->down->row < x;l=l->down);
                r->down=l->down; l->down=r;
            }
        }
    }
}

void output(CrossList *M){
    int i;
    OLink r,t;
    for(i=1;i<=M->ru;i++){
        if(M->rHead[i]){
            for(t=M->rHead[i];t;t=t->right){
                printf("%d %d %d\n",t->row,t->col,t->num);
            }
        }
    }
}

int main(){
    M=(CrossList *)malloc(sizeof(CrossList));
    int m,n,t1,t2,max;
    scanf("%d%d%d%d",&m,&n,&t1,&t2);
    int i;
    M->cu=0;M->ru=0;
    if(m>n) max=m;
    else max=n;
    for(i=1;i<=max;i++){
        M->cHead[i]=NULL;
        M->rHead[i]=NULL;
    }
    init(M,t1);
    add(M,t2);
    output(M);
    return 0;
}
