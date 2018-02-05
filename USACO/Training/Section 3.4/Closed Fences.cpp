/*
PROG: fence4
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <assert.h>
#include <math.h>

enum{MAXN=200};
const double O=0.0000001;
const double OO=100000000;
FILE* fin = fopen("fence4.in", "r");
FILE* fout = fopen("fence4.out", "w");
struct Point
{
	int x, y;
}P[MAXN], V[MAXN], H;

int NP, NV;
int EVIS[MAXN], PVIS[MAXN], is_V[MAXN], P2V[MAXN];

Point& gp(int i)
{
	return P[(i+NP)%NP];
}
Point& gv(int i)
{
	return V[(i+NV)%NV];
}

void input()
{
	int i;
	fscanf(fin, "%d", &NP);
	fscanf(fin, "%d %d", &H.x, &H.y);
	for(i=0; i<NP; i++)
		fscanf(fin, "%d %d", &P[i].x, &P[i].y);
}

int xd(Point a1, Point a2, Point b1, Point b2)
{
	int adx = a2.x-a1.x, ady = a2.y-a1.y;
	int bdx = b2.x-b1.x, bdy = b2.y-b1.y;
	return adx*bdy-ady*bdx;
}
int biside(Point a1, Point a2, Point c, Point d)
{
	return xd(a1, a2, a1, c)*xd(a1, a2, a1, d) < 0.0;
}
int is_insect(Point a1, Point a2, Point b1, Point b2)
{
	return biside(a1, a2, b1, b2) && biside(b1, b2, a1, a2);
}
int is_fence()
{
	int i, j;
	for(i=0; i<NP; i++)
		for(j=0; j<NP; j++)
			if(is_insect(gp(i), gp(i+1), gp(j), gp(j+1))==1)
				return 0;
	return 1;
}
double lenth(Point a1, Point a2)
{
	int dx = a2.x-a1.x;
	int dy = a2.y-a1.y;
	return sqrt((double)(dx*dx + dy*dy));
	
}
int is_line(Point a, Point b, Point c)
{
	return lenth(a, b)+lenth(b, c)-lenth(a, c) < O;
}
int is_line2(Point a, Point b, Point c)
{
	return is_line(a, b, c) || is_line(a, c, b);
}
void build_V()
{
	int i, s, s0;
       	for(i=0; i<NP && is_line(gp(i-1), gp(i), gp(i+1)); i++)
		;
	s = s0 = i;
	is_V[i] = 1;
	P2V[i] = 0;
	V[NV++] = gp(i);
	for(i=s+1; i!=s0; i=(i+1)%NP){
		if(!is_line(gp(s), gp(i), gp(i+1))){
			V[NV++] = P[i];
			is_V[i] = 1;
			s = i;
		}else{
			P2V[i] = NV-1;
		}
	}
}
int on_cross_point(int i, int j)
{
	if(gp(i).x==gv(j).x && gp(i).y==gv(j).y)
		return 0;
	return is_line(H, gv(j), P[i]) && biside(H, P[i], gv(j-1), gv(j+1));
}
int on_cross_line(int i, int j)
{
	if(gp(i).x==gv(j).x && gp(i).y==gv(j).y)
		return 0;
	if(gp(i).x==gv(j+1).x && gp(i).y==gv(j+1).y)
		return 0;
	return is_line2(H, gv(j), gv(j+1)) && is_line2(gv(j), gv(j+1), P[i]) && is_insect(H, P[i], gv(j-1), gv(j+2));
}
int is_cross(Point a1, Point a2, Point b1, Point b2, double &tmp)
{
	double hx=a1.x, hy=a1.y, rx=a2.x-a1.x, ry=a2.y-a1.y;
	double ex=b1.x, ey=b1.y, qx=b2.x-b1.x, qy=b2.y-b1.y;
	if(fabs(rx*qy-ry*qx)<O)
		return 0;
	double i=((ex*qy-ey*qx)-(qy*hx-qx*hy))/(rx*qy-ry*qx);
	double j=((ry*hx-rx*hy)-(ex*ry-ey*rx))/(qx*ry-qy*rx);
	if(i<0.0 || !(0.0<j && j<1.0))
		return 0;
	tmp = i;
	return 1;	
}
int can_see_through(int i)
{
	return 	is_insect(H, gp(i+1), gp(i), gp(i-1)) ||
		is_insect(H, gp(i-1), gp(i), gp(i+1));
}
int solve()
{
	int i, j, beste, corner, par;
	double best, tmp=0.00;
	if(is_fence()==0)
		return 0;
	else{
		build_V();
		for(i=0; i<NP; i++){
			for(j=0; j<NV; j++)
				if(	is_insect(H, gp(i), gv(j), gv(j+1)) ||
					on_cross_point(i, j) ||
					on_cross_line(i, j) ){
					break;
				}
			if(j!=NV)
				continue;
			PVIS[i] = 1;
			if(!can_see_through(i) || !is_V[i])
				continue;
			best = OO;
			beste = -1;
			corner = -1;
			for(j=0; j<NP; j++){
				if(i!=j && is_line2(H, P[i], P[j])){
					if(is_V[j]!=1)
						continue;
					if(is_line(H, P[i], gp(i+1)))
						par = i-1;
					else
						par = i+1;
					if(is_line2(H, P[i], gp(j+1))){
						if((biside(H, gp(j), gv(P2V[j]-1), gp(par)) ||
						    biside(H, gp(j), gv(P2V[j]+2), gp(par)) ) &&
						    (tmp=lenth(H, P[j])/lenth(H, P[i]))<best){
								best = tmp;
								beste = -1;
							}
					}else if((biside(H, gp(j), gp(j+1), gp(par)) ||
						 biside(H, gp(j), gp(j-1), gp(par))) &&
						 (tmp=lenth(H, P[j])/lenth(H, P[i]))<best){
							best = tmp;
							beste = -1;
						}
						
				}
				else if(is_cross(H, gp(i), gp(j), gp(j+1), tmp) && tmp<best){
					best = tmp;
					beste = j;
				}
			}
			if(beste!=-1)
				EVIS[beste] = 1;
		}
		for(i=0; i<NP; i++)
			if(PVIS[i]==1 && PVIS[(i+1)%NP]==1 && !is_line2(H, P[i], P[i+1])){
				EVIS[i] = 1;
			}
		return 1;
	}
}

void output(int res)
{
	int i, ne;
	if(res==0)
		fprintf(fout, "NOFENCE\n");
	else{
		for(i=0, ne=0; i<NP; i++)
			if(EVIS[i]==1)
				ne++;
		fprintf(fout, "%d\n", ne);
		for(i=0; i<NP-2; i++)
			if(EVIS[i]==1)
				fprintf(fout, "%d %d %d %d\n", gp(i).x, gp(i).y, gp(i+1).x, gp(i+1).y);
		if(EVIS[NP-1]==1)
				fprintf(fout, "%d %d %d %d\n", gp(0).x, gp(0).y, gp(NP-1).x, gp(NP-1).y);
		if(EVIS[NP-2]==1)
				fprintf(fout, "%d %d %d %d\n", gp(NP-2).x, gp(NP-2).y, gp(NP-1).x, gp(NP-1).y);
	}
}

int main()
{
	input();
	output(solve());
}