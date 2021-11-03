#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

queue <int> q;

void BFS(int v, int **M, int *Vis, int Size)
{
	int i;
	q.push(v); Vis[v]=1;
	while (!q.empty())
	{
		v=q.front();
		q.pop();
		printf("%3d", v+1);
		for(i=0;i<Size;i++)
		{
			if((Vis[i]==0)&&(M[v][i]==1))
			{
				q.push(i);
				Vis[i]=1;
			}
		}
	}
}

void main()
{
	int **G=NULL, i=0, j=0, S=0, *Visited=NULL, N;
	char ReVis=0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("������� ����������� ������� ���������: ");
	scanf("%d", &S);
	while(S<=0)
	{
		printf("����������� �������� �����! ������� ����� ������������� �����: ");
		scanf("%d", &S);
	}
	G=(int**)malloc(S*sizeof(int));
	Visited=(int*)malloc(S*sizeof(int));
	for(i=0;i<S;i++)
		Visited[i]=0;
	for(i=0;i<S;i++)
	{
		G[i]=(int*)malloc(S*sizeof(int));
		for(j=0;j<S;j++)
		{
			G[i][j]=rand()%2;
			if(G[i][i]!=0)
				G[i][j]=0;
		}
	}
	for(i=0;i<S;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<S;j++)
			{
				G[j][i]=G[i][j];
				printf("%2d", G[i][j]);
			}
	}
	printf("\n� ����� ������� ������ ����� � ������? "); scanf("%d", &N);
	while (N<1 || N>S)
	{
		printf("����������� �������� �����! ������� ����� ������������� ����� � �������� ������� ������� ���������: ");
		scanf("%d", &N);
	}
	printf("\n\n������� ������ ����� � ������: ");
	
	for(i=N-1;Visited[i]<1;i++)
	{
		if(ReVis==1 && i==N-1)
			break;
		if(i==S-1)
			i=0;
		BFS(i, G, Visited, S);
		ReVis=1;
	}
	printf("\n");
	free(Visited);
	free(G);
}