/*
PROG: fence6
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>

#define MAXS 100
int conn[2*MAXS][8], ccnt[2*MAXS], length[MAXS], alist[2*MAXS][8], nfence, npl, dist[2*MAXS], heap[2*MAXS], hsize, hloc[2*MAXS];
void check_heap()
{
	int lv;
	for (lv = 1; lv < hsize; lv++)
		if (dist[heap[lv]] < dist[heap[(lv-1)>>1]])
		{
			fprintf (stderr, "HEAP ERROR!\n");
			return;
		}
 }
void delete_min()
{
	int loc, val, p, t;
	loc = heap[--hsize];
	val = dist[loc];
	p = 0;
	while (((p<<1)|1) < hsize)
	{
		t = (p<<1)|1;
		if (t+1 < hsize && dist[heap[t+1]] < dist[heap[t]])
			t++;
		if (dist[heap[t]] < val)
		{
			heap[p] = heap[t];
			hloc[heap[p]] = p;
			p = t;
		}
		else break;
	}
	heap[p] = loc;
	hloc[loc] = p;
	check_heap();
}

void update(int loc)
{
	int val, p, t;
	val = dist[loc];
	p = hloc[loc];
	while (p > 0)
	{
		t = (p-1)>>1;
		if (dist[heap[t]] > val)
		{
			heap[p] = heap[t];
			hloc[heap[p]] = p;
			p = t;
		}
		else break;
	}
	heap[p] = loc;
	hloc[loc] = p;
	check_heap();
}

void add_heap(int loc)
{
	heap[hsize++] = loc;
	hloc[loc] = hsize-1;
	update(loc);
}

void fill_dist(int s)
{
	int lv, p, t, l;
	for (lv = 0; lv < npl; lv++)
	{
		hloc[lv] = -1;
		dist[lv] = 255*MAXS + 1;
	}
	dist[s] = hsize = 0;
	add_heap(s);
	while (hsize)
	{
		p = heap[0];
		delete_min();
		t = dist[p];
		for (lv = 0; lv < ccnt[p]; lv++)
		{
			l = alist[p][lv];
			if (dist[l] > t)
			{
				dist[l] = t;
				add_heap(l);
			}
		}
		t = dist[p] + length[p>>1];
		p = p ^ 0x1;
		if (dist[p] > t)
		{
			dist[p] = t;
			add_heap(p);
		}
	}
}

FILE* fin = fopen("fence6.in", "r");
FILE* fout = fopen("fence6.out", "w");
int main(int argc, char **argv)
{
	int lv, lv2, lv3, c1, c2, segid, len, p, min;
	fscanf (fin, "%d\n", &nfence);
	npl = nfence*2;
	for (lv = 0; lv < nfence; lv++)
	{
		fscanf (fin, "%d %d %d %d", &segid, &len, &c1, &c2);
		segid--;
		length[segid] = len;
		ccnt[segid<<1] = c1;
		ccnt[(segid<<1)|1] = c2;
		while (c1--)
		{
			fscanf (fin, "%d", &p);
			conn[segid<<1][c1] = p-1;
		}
		while (c2--)
		{
			fscanf (fin, "%d", &p);
			conn[(segid<<1)|1][c2] = p-1;
		}
	}
	for (lv = 0; lv < npl; lv++)
		for (lv2 = 0; lv2 < ccnt[lv]; lv2++)
		{
			c1 = lv>>1;
			c2 = conn[lv][lv2]*2;
			for (lv3 = 0; lv3 < ccnt[c2]; lv3++)
				if (conn[c2][lv3] == c1)
					break;
			if (lv3 >= ccnt[c2])
				c2++;
			alist[lv][lv2] = c2;
		}
	min = 255*MAXS+1;
	for (lv = 0; lv < nfence; lv++)
	{
		len = length[lv];
		length[lv] = 255*MAXS+1;
		fill_dist(lv<<1);
		if (dist[(lv<<1)|1] + len < min)
			min = dist[(lv<<1)|1] + len;
		length[lv] = len;
	}
	fprintf (fout, "%i\n", min);
	return 0;
}