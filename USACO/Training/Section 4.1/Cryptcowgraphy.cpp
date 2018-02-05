/*
PROG: cryptcow
LANG: C++
ID: hayk.sa1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define MAX_MSG_LEN 76
#define MAX_N 9
#define MAX_N_TRIPLES (MAX_N*MAX_N*MAX_N)
#define C_ 0
#define O_ 1
#define W_ 2
#define NOT_COW 3

char Moo[] = "Begin the Escape execution at the Break of Dawn";
int Moo_len = 47;

char Hmm[MAX_MSG_LEN];
int Hmm_len;
int N;   // number of encryptions

int cowpos[3*MAX_N + 2];    // +2 for the start and end
int T;      // number of triples

int triple[MAX_N_TRIPLES + 1][3];   // triples will be numbered
                                    // starting from 1
// node in linked list
struct llnode_t
{
    int data;
    llnode_t *next;
} *its_triple[3*MAX_N+1] = {0};

// for curiosity's sake:
int n_calls_to_find_tripleset = 0;
int n_calls_to_find_ordering = 0;
int starttime;


void input ();
int submoo (const char *, int);
void subhmm (char *, int, int);
void init ();
int thingy (char);
void output (bool);
void find_tripleset (int decoded_len, int last_seg_start, int *its_triple_used);
void find_ordering (int *curcowpos, int *triple_used, int n_decodings_applied);

// add a node to the beginning of linked list
void addnode (llnode_t **np, int data)
{
    llnode_t *temp = *np;
    *np = new llnode_t;
    (*np)->data = data;
    (*np)->next = temp;
}
int thingy (char c)
{
    switch (c) {
    case 'C':
        return C_;
    case 'O':
        return O_;
    case 'W':
        return W_;
    default:
        return NOT_COW;
    }
}
// is word a subsequence of Moo, starting from position 'start' in Moo?
// if so, return position of first character in Moo that starts it
// otherwise return -1
int submoo (const char *word, int start)
{
    int word_len = strlen (word);
    
    if (word_len == 0)
        return start;

    int i, j;
    
    for (i = start; i <= Moo_len - word_len; i++) {
        for (j = 0; j < word_len && Moo[i+j] == word[j]; j++)
            ;
        if (j == word_len)
            return i;
    }

    return -1;
}
// get Hmm[start..end]
void subhmm (char *target, int start, int end)
{
    int i, j = 0;
    for (i = start; i <= end; i++)
        target[j++] = Hmm[i];
    target[j] = '\0';
}
// output the answer
void output (bool result)
{
    FILE *fout = fopen ("cryptcow.out", "w");
    if (result) {
        fprintf (fout, "1 %d\n", N);
        printf ("The answer is yes.\n");
    } else {
        fprintf (fout, "0 0\n");
        printf ("The answer is no.\n");
    }
    fclose(fout);

    printf ("%d calls to find_tripleset; %d calls to find_ordering.\n",
        n_calls_to_find_tripleset, n_calls_to_find_ordering);
    printf ("Runtime: %g seconds.\n", (double) (clock () - starttime) / CLOCKS_PER_SEC);
    exit (0);
}
// just get the input
void input ()
{
    FILE *fin = fopen ("cryptcow.in", "r");
    fscanf (fin, "%[^\n]", Hmm);
    fclose (fin);

#ifndef NDEBUG
    printf ("%s\n", Hmm);
#endif
}
// do stuff
void init ()
{
    Hmm_len = strlen (Hmm);

    // is length acceptable?
    if (Hmm_len < Moo_len || (Hmm_len - Moo_len) % 3 != 0) {
        printf ("Length badness.\n");
        output (0);
    } else
        N = (Hmm_len - Moo_len) / 3;

    // while forming array cowpos[],
    // make sure N = # of C's = # of O's = # of W's
    int i;
    int chartype;
    int ncows[3] = {0};
    int totncows = 1;   // 1, and not 0, because of the start

    cowpos[0] = -1;

    for (i = 0; i < Hmm_len; i++) {
        chartype = thingy (Hmm[i]);
        if (chartype != NOT_COW) {
            if (++ncows[chartype] > N) {
                // too many cows
                printf ("Too many of one type of cow.\n");
                output (0);
            }
            cowpos[totncows++] = i;
            if (totncows == 1 && chartype != C_) {
                // first cow is not a 'C'
                printf ("First cow not C.\n");
                output (0);
            } else if (totncows == 3*N+1 && chartype != W_) {
                // last cow is not a 'W'
                printf ("Last cow not W\n");
                output (0);
            }
        } else {
            if (totncows == 1 && Hmm[i] != Moo[i]) {
                // first segments don't match
                printf ("First segments don't match.\n");
                output (0);
            } else if (totncows == 3*N+1 && Hmm[i] != Moo[i+Moo_len-Hmm_len]) {
                // last segments don't match
                printf ("Last segments don't match.\n");
                output (0);
            }
        }
    }    
    cowpos[3*N+1] = Hmm_len;
    if (ncows[0] != N || ncows[1] != N || ncows[2] != N)
	{
        printf ("Wrong number of some cow.\n");
        output (0);
    }
    if (Hmm_len == Moo_len)
        output (1);

    // find the triples that might work
    int c, o, w;
    char segment[3][2][MAX_MSG_LEN];    // [C, O, or W][left or right][]
    char subword[MAX_MSG_LEN];
    int c_start;

    T = 0;
    for (c = 1; c <= 3*N; c++) {
        if (Hmm[cowpos[c]] != 'C')
            continue;
        
        subhmm (segment[C_][0], cowpos[c-1] + 1, cowpos[c] - 1);
        subhmm (segment[C_][1], cowpos[c] + 1, cowpos[c+1] - 1);

        c_start = submoo (segment[C_][0], 0);
        
        if (c_start == -1) {
            printf ("Some segment does not exist.\n");
            output (0);
        }

        for (o = 1; o <= 3*N; o++) {
            if (Hmm[cowpos[o]] != 'O')
                continue;

            subhmm (segment[O_][0], cowpos[o-1] + 1, cowpos[o] - 1);
            subhmm (segment[O_][1], cowpos[o] + 1, cowpos[o+1] - 1);

            // the segment left of c and the segment right of o must fit
            // together to form a subsequence of Moo

            strcpy (subword, segment[C_][0]);
            strcat (subword, segment[O_][1]);
            if (submoo (subword, c_start) == -1) {
                assert (submoo (subword, 0) == -1);
                continue;
            }

            for (w = 1; w <= 3*N; w++) {
                if (Hmm[cowpos[w]] != 'W')
                    continue;

                subhmm (segment[W_][0], cowpos[w-1] + 1, cowpos[w] - 1);
                subhmm (segment[W_][1], cowpos[w] + 1, cowpos[w+1] - 1);

                // the segment left of o and the segment right of w must fit
                strcpy (subword, segment[O_][0]);
                strcat (subword, segment[W_][1]);
                if (submoo (subword, 0) == -1)
                    continue;
                
                // the segment left of w and the segment right of c must fit
                strcpy (subword, segment[W_][0]);
                strcat (subword, segment[C_][1]);
                if (submoo (subword, 0) == -1)
                    continue;

                // finally, after all these tests we have found a triple
                // worthy of further consideration
                T++;
                triple[T][C_] = c;
                triple[T][O_] = o;
                triple[T][W_] = w;
                addnode (&its_triple[c], T);
                addnode (&its_triple[o], T);
                addnode (&its_triple[w], T);
            }
        }
    }
    //printf ("All %d triples found.\n", T);
    // verify that each cow has at least one triple
    for (i = 1; i <= 3*N; i++)
        if (its_triple[i] == 0)
		{
            printf ("Cow %d has no triples.\n", i);
            output (0);
        }

#ifndef NDEBUG
    printf ("Initialization results (after %g seconds):\n",
        (double) (clock () - starttime) / CLOCKS_PER_SEC);
    printf ("\tNumber of encrpytions (possibly): %d.\n", N);
    printf ("\tNumber of triples: %d.\n", T);
#endif
}


// use this function recursively
// find a set of triples given:
// - the length of Moo already decoded (i.e., the position in Moo from which
//   further consideration is necessary)
// - the id of the cow to the left of the last segment used,
// - the triples that you've already committed to using
void find_tripleset (int decoded_len, int last_seg_start, int *its_triple_used)
{
    n_calls_to_find_tripleset++;
//  printf ("Trying to find tripleset.\n");
    int i;
    int last_seg_end = last_seg_start+1;
    int last_seg_end_type = thingy (Hmm[cowpos[last_seg_end]]);
    int last_seg_len;
    int next_seg_start;
    int triple_to_use;
    // first see if the segment from last_seg_start to last_seg_end really fits
    assert (0 <= last_seg_start && last_seg_end <= 3*N+1);
    last_seg_len = cowpos[last_seg_end] - cowpos[last_seg_start] - 1;
    if (decoded_len + last_seg_len > Moo_len)
        return;
    for (i = 0; i < last_seg_len &&
            Moo[decoded_len + i] == Hmm[cowpos[last_seg_start]+1+i]; i++)
        ;
    if (i < last_seg_len)
        return;
    //  printf ("The last segment does fit.\n");
    // the last segment indeed fits
    decoded_len += last_seg_len;
    if (last_seg_start == 3*N && decoded_len == Moo_len) {
        // we have found a successful tripleset!
#ifndef NDEBUG
        printf ("Tripleset found after %d calls to find_tripleset.\n",
            n_calls_to_find_tripleset);
#endif
        int triple_used[MAX_N];
        int curcowpos[3*MAX_N+2];
        int j = 0;
        for (i = 1; i <= 3*N; i++) {
            if (Hmm[cowpos[i]] == 'C') {
                triple_used[j++] = its_triple_used[i];
            }
        }
        memcpy (curcowpos, cowpos, sizeof (*cowpos) * (3*N+2));

        find_ordering (curcowpos, triple_used, 0);
        return;     
    }

    assert (0 <= last_seg_end_type && last_seg_end_type < 3);
    assert (last_seg_end <= 3*N);

    if ((triple_to_use = its_triple_used[last_seg_end]) != 0)
	{
        // the next segment to be used has already been decided
        next_seg_start = triple[triple_to_use][(last_seg_end_type + 1) % 3];
        find_tripleset (decoded_len, next_seg_start, its_triple_used);
    }
	else
	{
        // the next segment to be used is up for grabs
//      printf ("The next segment to be used is up for grabs.\n");

        llnode_t *trytriple;
        assert (0 < last_seg_end && last_seg_end <= 3*N);

        for (trytriple = its_triple[last_seg_end];
                trytriple != 0; trytriple = trytriple->next) {
            triple_to_use = trytriple->data;

            assert (1 <= triple_to_use && triple_to_use <= T);
            assert (1 <= triple[triple_to_use][(last_seg_end_type + 1) % 3]);
            assert (triple[triple_to_use][(last_seg_end_type + 1) % 3] <= 3*N);

            if (its_triple_used[triple[triple_to_use]
                [(last_seg_end_type + 1) % 3]] != 0)
            {
                continue;
            }

            if (its_triple_used[triple[triple_to_use]
                [(last_seg_end_type + 2) % 3]] != 0)
            {
                continue;
            }

            assert (last_seg_end == triple[triple_to_use][last_seg_end_type]);

            its_triple_used[last_seg_end] = triple_to_use;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 1) % 3]]
                = triple_to_use;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 2) % 3]]
                = triple_to_use;

            next_seg_start = triple[triple_to_use][(last_seg_end_type+1) % 3];
            find_tripleset (decoded_len, next_seg_start, its_triple_used);

            its_triple_used[last_seg_end] = 0;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 1) % 3]]
                = 0;
            its_triple_used[triple[triple_to_use][(last_seg_end_type + 2) % 3]]
                = 0;
        }
    }
}


// use this function recursively
// find an ordering of the triples given in triple_used
// that accomplishes the task given:
// - the current positions of all cows, which includes
//   information about which triples have already been used
//   (those cows that have already been used are at position -1)
// - which triples are to be used
void find_ordering (int *curcowpos, int *triple_used, int n_decodings_applied)
{
    n_calls_to_find_ordering++;


    if (n_decodings_applied == N)
        output (1);

    int nextcowpos[3*MAX_N+2];
        
    int i, j, cpos, opos, wpos;
    for (i = 0; i < N; i++) {
        cpos = curcowpos[triple[triple_used[i]][C_]];
        opos = curcowpos[triple[triple_used[i]][O_]];
        wpos = curcowpos[triple[triple_used[i]][W_]];
        if (cpos >= opos || opos >= wpos) {
            continue;
        }
        for (j = 1; j <= 3*N; j++) {
            if (curcowpos[j] == -1)
                nextcowpos[j] = -1;
            else if (curcowpos[j] < cpos)
                nextcowpos[j] = curcowpos[j];
            else if (curcowpos[j] == cpos)
                nextcowpos[j] = -1;
            else if (curcowpos[j] < opos)
                nextcowpos[j] = curcowpos[j] + wpos - opos - 2;
            else if (curcowpos[j] == opos)
                nextcowpos[j] = -1;
            else if (curcowpos[j] < wpos)
                nextcowpos[j] = curcowpos[j] + cpos - opos - 1;
            else if (curcowpos[j] == wpos)
                nextcowpos[j] = -1;
            else
                nextcowpos[j] = curcowpos[j] - 3;
        }
        find_ordering (nextcowpos, triple_used, n_decodings_applied+1);
    }
}


int main ()
{
    starttime = clock ();
    input ();
    init ();

    int its_triple_used[3*MAX_N+1] = {0};
    find_tripleset (0, 0, its_triple_used);

    output (0);
    return 0;
}
/*
// Hash - with linked lists
// Strings - with linked lists
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

bool found;
int level, len, h;
int nl1[256];
int nl2[256];
char s[76], a[76], str[76], original[] = "Begin the Escape execution at the Break of Dawn\0";
struct node
{
	char element;
	node *next;
} *head;
struct hash_t
{
	char str[76];
	hash_t *next;
} *hash_table[502973];
int hash()
{
	int m, i;
	m = 0;
	for (i = 0; i < len; i++)
		m = (m*2377+((int)str[i]))%502973;
	return m;
}
void turn_string()
{
	int j;
	node* i;
	for (i = head, j = 0; i != NULL; i = i->next, j++)
		str[j] = i->element;
	str[j] = 0;
}
bool is_in(int p, int q)
{
	int i, j, k;
	if (p > q)
		return 1;
	for (i = 0; i+q-p < 47; i++)
		if (original[i+q-p] == str[q])
		{
			for (k = p, j = i; k <= q; k++, j++)
				if (original[j] != str[k])
					break;
			if (k == q+1)
				return 1;
		}
	return 0;
}
bool check_string(int c, int o, int w)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (str[i] == 'C')
			break;
		if (str[i] == 'O' || str[i] == 'W')
			return 0;
	}
	for (i = len-1; i >= 0; i--)
	{
		if (str[i] == 'W')
			break;
		if (str[i] == 'C' || str[i] == 'O')
			return 0;
	}
	bool t1, t2, t3;
	t1 = t2 = t3 = 1;
	int bc, bo, bw;
	bc = bo = bw = -1;
	for (i = 0; i < len; i++)
		if (str[i] == 'C' || str[i] == 'O' || str[i] == 'W')
		{
			if (t1)
				if (i < c)
					bc = i;
				else
				{
					t1 = 0;
					if (!is_in(bc+1, i-1))
						return 0;
				}
			if (t2)
				if (i < c+w-o-1)
					bo = i;
				else
				{
					t2 = 0;
					if (!is_in(bo+1, i-1))
						return 0;
				}
			if (t3)
				if (i < w-2)
					bw = i;
				else
				{
					t3 = 0;
					return is_in(bw+1, i-1);
				}
		}
	if (t3)
		return is_in(bw+1, len-1);
}
void rec()
{
	int i, j, k, x, y, z;
	int cn, on, wn;
	int plc[9], plo[9], plw[9];
	bool t1, t2, t3;
	node *s1, *s2, *s3, *p, *l;
	node *fh, *C[9], *O[9], *W[9];
	node *pC[9], *pO[9], *pW[9];
	hash_t *curr;
	p = NULL;
	for (l = head, cn = on = wn = i = 0; l != NULL; l = l->next, i++)
	{
		if (l->element == 'C')
		{
			C[cn] = l;
			pC[cn] = p;
			plc[cn++] = i;
		}
		if (l->element == 'O')
		{
			O[on] = l;
			pO[on] = p;
			plo[on++] = i;
		}
		if (l->element == 'W')
		{
			W[wn] = l;
			pW[wn] = p;
			plw[wn++] = i;
		}
		p = l;
	}
	fh = head;
	level--;
	len -= 3;
	for (i = 0; i < cn; i++)
		for (j = 0; j < on; j++)
			for (k = 0; k < wn; k++)
				if (plc[i] < plo[j] && plo[j] < plw[k])
				{
					t1 = t2 = t3 = 0;
					if (plc[i]+1 == plo[j] && plo[j]+1 == plw[k])
					{
						t1 = 1;
						if (pC[i] == NULL)
						{
							s1 = NULL;
							head = W[k]->next;
						}
						else
						{
							s1 = pC[i]->next;
							pC[i]->next = W[k]->next;
						}
					}
					else
						if (plc[i]+1 == plo[j])
						{
							t2 = 1;
							if (pC[i] == NULL)
							{
								s1 = NULL;
								head = O[j]->next; 
							}
							else
							{
								s1 = pC[i]->next;
								pC[i]->next = O[j]->next;
							}
							s2 = pW[k]->next;
							pW[k]->next = W[k]->next;
						}
						else
							if (plo[j]+1 == plw[k])
							{
								t3 = 1;
								if (pC[i] == NULL)
								{
									s1 = NULL;
									head = C[i]->next;
								}
								else
								{
									s1 = pC[i]->next;
									pC[i]->next = C[i]->next;
								}
								s2 = pO[j]->next;
								pO[j]->next = W[k]->next;
							}
							else
							{
								if (pC[i] == NULL)
								{
									s2 = NULL;
									head = O[j]->next;
								}
								else
								{
									s2 = pC[i]->next;
									pC[i]->next = O[j]->next;
								}
								s1 = pW[k]->next;
								s3 = pO[j]->next;
								pO[j]->next = W[k]->next;
								pW[k]->next = C[i]->next;
							}
					turn_string();
					if(level == 0)
						if (strcmp(str, original) == 0)
						{
							found = 1;
							return;
						}
					if (level)
						if (check_string(plc[i], plo[j], plw[k]))
						{
							h = hash();
							if (level < 3)
							{
								curr = new hash_t;
								strcpy(curr->str, str);
								curr->next = hash_table[h];
								hash_table[h] = curr;
								rec();
								if (found)
									return;
							}
							else
							{
								for (curr = hash_table[h]; curr != NULL; curr = curr->next)
									if (strcmp(curr->str, str) == 0)
										break;
								if (level < 3 || curr == NULL)
								{
									curr = new hash_t;
									strcpy(curr->str, str);
									curr->next = hash_table[h];
									hash_table[h] = curr;
									rec();
									if (found)
										return;
								}
							}
						}
					head = fh;
					if (t1)
					{
						if (s1 != NULL)
							pC[i]->next = s1;
					}
					else
						if (t2)
						{
							if (s1 != NULL)
								pC[i]->next = s1;
							pW[k]->next = s2;
						}
						else
							if (t3)
							{
								if (s1 != NULL)
									pC[i]->next = s1;
								pO[j]->next = s2;
							}
							else
							{
								pW[k]->next = s1;
								if (s2 != NULL)
									pC[i]->next = s2;
								pO[j]->next = s3;
							}
				}
	level++;
	len += 3;
}
FILE* fin = fopen("cryptcow.in", "r");
FILE* fout = fopen("cryptcow.out", "w");
int main()
{
	cout << clock() << '\n';
	char c[76];
	node *trail;
	int length, i, j, k, l, r;
	fgets(s, 76, fin);
	length = strlen(s)-1;
	if (s[length] == '\n')
		s[length] = 0;
	if (strcmp(s, original) == 0)
	{
		fprintf(fout, "1 0\n");
		return 0;
	}
	if ((length-47)%3)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < 47; i++)
		nl1[(int)original[i]]++;
	for (i = 0; i < length; i++)
		nl2[(int)s[i]]++;
	for (i = 0; i < 256; i++)
		if ((char)i != 'C' && (char)i != 'O' && (char)i != 'W' && nl1[i] != nl2[i])
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	if (nl2[(int)'C'] != nl2[(int)'O'] || nl2[(int)'O'] != nl2[(int)'W'] || nl2[(int)'C'] != nl2[(int)'W'])
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	if (nl2[(int)'C'] > 9)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < length; i++)
	{
		if (s[i] == 'C')
			break;
		if (s[i] == 'O' || s[i] == 'W')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = length-1; i >= 0; i--)
	{
		if (s[i] == 'W')
			break;
		if (s[i] == 'C' || s[i] == 'O')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = 0; i < length; i++)
	{
		r = 0;
		while (s[i] && s[i] != 'C' && s[i] != 'O' && s[i] != 'W')
			c[r++] = s[i++];
		for (j = 0; j+r <= 47; j++)
		{
			k = 0;
			l = j;
			while (k < r && c[k] == original[l])
			{
				k++;
				l++;
			}
			if (k == r)
				break;
		}
		if (j+r >= 48)
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = 0; i < 502973; i++)
		hash_table[i] = NULL;
	len = length;
	strcpy(str, s);
	h = hash();
	hash_table[h] = new hash_t;
	strcpy(hash_table[h]->str, s);
	hash_table[h] = hash_table[h]->next;
	head = trail = new node;
	for (i = 0; i < length-1; i++)
	{
		trail->element = s[i];
		trail = trail->next = new node;
	}
	trail->element = s[length-1];
	trail->next = NULL;
	level = nl2[(int)'C'];
	rec();
	if (found)
		fprintf(fout, "1 %d\n", nl2[(int)'C']);
	else
		fprintf(fout, "0 0\n");
	cout << clock() << '\n';
	return 0;
}
/*
// Hash - with linked lists
// Strings - with linked lists(arrays)
#include <stdio.h>
#include <string.h>

bool found;
int len, h;
int nl1[256];
int nl2[256];
int next[77], head;
char s[77], str[77], original[] = "Begin the Escape execution at the Break of Dawn\0";
struct hash_t
{
	char str[77];
	hash_t *next;
} *hash_table[502973];

int hash()
{
	int m, i;
	m = 0;
	for (i = 0; i < len; i++)
		m = (m*2377+((int)str[i]))%502973;
	return m;
}

void turn_string()
{
	int i, j;
	for (i = head, j = 0; i != -1; i = next[i], j++)
		str[j] = s[i];
	str[j] = 0;
}
bool is_in(int p, int q)
{
	int i, j, k;
	if (p > q)
		return 1;
	for (i = 0; i+q-p < 47; i++)
		if (original[i+q-p] == str[q])
		{
			for (k = p, j = i; k <= q; k++, j++)
				if (original[j] != str[k])
					break;
			if (k == q+1)
				return 1;
		}
	return 0;
}
bool check_string(int c, int o, int w)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (str[i] == 'C')
			break;
		if (str[i] == 'O' || str[i] == 'W')
			return 0;
	}
	for (i = len-1; i >= 0; i--)
	{
		if (str[i] == 'W')
			break;
		if (str[i] == 'C' || str[i] == 'O')
			return 0;
	}
	bool t1, t2, t3;
	t1 = t2 = t3 = 1;
	int bc, bo, bw;
	bc = bo = bw = -1;
	for (i = 0; i < len; i++)
		if (str[i] == 'C' || str[i] == 'O' || str[i] == 'W')
		{
			if (t1)
				if (i < c)
					bc = i;
				else
				{
					t1 = 0;
					if (!is_in(bc+1, i-1))
						return 0;
				}
			if (t2)
				if (i < c+w-o-1)
					bo = i;
				else
				{
					t2 = 0;
					if (!is_in(bo+1, i-1))
						return 0;
				}
			if (t3)
				if (i < w-2)
					bw = i;
				else
				{
					t3 = 0;
					return is_in(bw+1, i-1);
				}
		}
	if (t3)
		return is_in(bw+1, len-1);
	else
		return 1;
/*	return (is_in(bc, ac) && is_in(bo, ao)  && is_in(bw, aw));
	int j;
	for (i = c-1; i >= 0; i--)
		if (str[i] == 'C')
			break;
	i++;
	j = c;
	while (str[j] != 'C' && str[j] != 'O' && str[j] != 'W')
		j++;
	j--;
	if (!is_in(i, j))
		return 0;
	i = c+w-o-2;
	while (str[i] != 'C' && str[i] != 'O' && str[i] != 'W')
		i--;
	i++;
	j =c+w-o-1;
	while (str[j] != 'C' && str[j] != 'O' && str[j] != 'W')
		j++;
	j--;
	if (!is_in(i, j))
		return 0;
	i = w-3;
	while (str[i] != 'C' && str[i] != 'O' && str[i] != 'W')
		i--;
	i++;
	j = w-2;
	while (j < len && str[j] != 'C' && str[j] != 'O' && str[j] != 'W')
		j++;
	j--;
	return is_in(i, j);
}
/*
bool check_string()
{
	char c[77];
	int i, j, k, l, r;
	for (i = 0; i < len; i++)
	{
		if (str[i] == 'C')
			break;
		if (str[i] == 'O' || str[i] == 'W')
			return 0;
	}
	for (i = len-1; i >= 0; i--)
	{
		if (str[i] == 'W')
			break;
		if (str[i] == 'C' || str[i] == 'O')
			return 0;
	}
	for (i = 0; i < len; i++)
	{
		r = 0;
		while (str[i] && str[i] != 'C' && str[i] != 'O' && str[i] != 'W')
			c[r++] = str[i++];
		for (j = 0; j+r <= 47; j++)
		{
			k = 0;
			l = j;
			while (k < r && c[k] == original[l])
			{
				k++;
				l++;
			}
			if (k == r)
				break;
		}
		if (j+r == 48)
			return 0;
	}
	return 1;
}

void rec()
{
	hash_t *curr;
	bool t1, t2, t3;
	int i, j, k, s1, s2, s3;
	int cn, on, wn, fh;
	int C[9], O[9], W[9];
	int pC[9], pO[9], pW[9];
	int plc[9], plo[9], plw[9];
	k = -1;
	for (i = head, cn = on = wn = j = 0; i != -1; i = next[i], j++)
	{
		if (s[i] == 'C')
		{
			C[cn] = i;
			pC[cn] = k;
			plc[cn++] = j;
		}
		if (s[i] == 'O')
		{
			O[on] = i;
			pO[on] = k;
			plo[on++] = j;
		}
		if (s[i] == 'W')
		{
			W[wn] = i;
			pW[wn] = k;
			plw[wn++] = j;
		}
		k = i;
	}
	fh = head;
	for (i = 0; i < cn; i++)
		for (j = 0; j < on; j++)
			for (k = 0; k < wn; k++)
				if (plc[i] < plo[j] && plo[j] < plw[k])
				{
					t1 = t2 = t3 = 0;
					if (plc[i]+1 == plo[j] && plo[j]+1 == plw[k])
					{
						t1 = 1;
						if (pC[i] == -1)
						{
							s1 = -1;
							head = next[W[k]];
						}
						else
						{
							s1 = next[pC[i]];
							next[pC[i]] = next[W[k]];
						}
					}
					else
						if (plc[i]+1 == plo[j])
						{
							t2 = 1;
							if (pC[i] == -1)
							{
								s1 = -1;
								head = next[O[j]];
							}
							else
							{
								s1 = next[pC[i]];
								next[pC[i]] = next[O[j]];
							}
							s2 = next[pW[k]];
							next[pW[k]] = next[W[k]];
						}
						else
							if (plo[j]+1 == plw[k])
							{
								t3 = 1;
								if (pC[i] == -1)
								{
									s1 = -1;
									head = next[C[i]];
								}
								else
								{
									s1 = next[pC[i]];
									next[pC[i]] = next[C[i]];
								}
								s2 = next[pO[j]];
								next[pO[j]] = next[W[k]];
							}
							else
							{
								if (pC[i] == -1)
								{
									s2 = -1;
									head = next[O[j]];
								}
								else
								{
									s2 = next[pC[i]];
									next[pC[i]] = next[O[j]];
								}
								s1 = next[pW[k]];
								s3 = next[pO[j]];
								next[pW[k]] = next[C[i]];
								next[pO[j]] = next[W[k]];
							}
					turn_string();
					if (strcmp(str, original) == 0)
					{
						found = 1;
						return;
					}
					len -= 3;
					if (check_string(plc[i], plo[j], plw[k]))
					{
						h = hash();
						for (curr = hash_table[h]; curr != NULL; curr = curr->next)
							if (strcmp(curr->str, str) == 0)
								break;
						if (curr == NULL)
						{
							curr = new hash_t;
							strcpy(curr->str, str);
							curr->next = hash_table[h];
							hash_table[h] = curr;
							rec();
							if (found)
								return;
						}
					}
					len += 3;
					head = fh;
					if (t1)
					{
						if (s1 != -1)
							next[pC[i]] = s1;
					}
					else
						if (t2)
						{
							if (s1 != -1)
								next[pC[i]] = s1;
							next[pW[k]] = s2;
						}
						else
							if (t3)
							{
								if (s1 != -1)
									next[pC[i]] = s1;
								next[pO[j]] = s2;
							}
							else
							{
								if (s2 != -1)
									next[pC[i]] = s2;
								next[pW[k]] = s1;
								next[pO[j]] = s3;
							}
				}
}
FILE* fin = fopen("cryptcow.in", "r");
FILE* fout = fopen("cryptcow.out", "w");
int main()
{
	char c[77];
	int length, i, j, k, l, r;
	fgets(s, 76, fin);
	length = strlen(s)-1;
	if (s[length] == '\n')
		s[length] = 0;
	if (strcmp(s, original) == 0)
	{
		fprintf(fout, "1 0\n");
		return 0;
	}
	if ((length-47)%3)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < 47; i++)
		nl1[(int)original[i]]++;
	for (i = 0; i < length; i++)
		nl2[(int)s[i]]++;
	for (i = 0; i < 256; i++)
		if ((char)i != 'C' && (char)i != 'O' && (char)i != 'W' && nl1[i] != nl2[i])
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	if (nl2[(int)'C'] != nl2[(int)'O'] || nl2[(int)'O'] != nl2[(int)'W'] || nl2[(int)'C'] != nl2[(int)'W'])
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	if (nl2[(int)'C'] > 9)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < length; i++)
	{
		if (s[i] == 'C')
			break;
		if (s[i] == 'O' || s[i] == 'W')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = length-1; i >= 0; i--)
	{
		if (s[i] == 'W')
			break;
		if (s[i] == 'C' || s[i] == 'O')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = 0; i < length; i++)
	{
		r = 0;
		while (s[i] && s[i] != 'C' && s[i] != 'O' && s[i] != 'W')
			c[r++] = s[i++];
		for (j = 0; j+r <= 47; j++)
		{
			k = 0;
			l = j;
			while (k < r && c[k] == original[l])
			{
				k++;
				l++;
			}
			if (k == r)
				break;
		}
		if (j+r == 48)
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	head = 0;
	for (i = 0; i < length-1; i++)
		next[i] = i+1;
	next[length-1] = -1;
	for (i = 0; i < 502973; i++)
		hash_table[i] = NULL;
	len = length;
	strcpy(str, s);
	h = hash();
	hash_table[h] = new hash_t;
	strcpy(hash_table[h]->str, s);
	hash_table[h] = hash_table[h]->next;
	found = 0;
	rec();
	if (found)
		fprintf(fout, "1 %d\n", nl2[(int)'C']);
	else
		fprintf(fout, "0 0\n");
	return 0;
}
/*
#include <cstdio>
#include <string.h>

struct String
{
	char item;
	String *next;
};/*
struct hash_t
{
	char str[76];
	hash_t *next;
} *first[502973], *last[502973];
int len, h;
bool t[502973] = {0}, found = 0;
int nl1[256] = {0};
int nl2[256] = {0};
char s[76], str[76], original[] = "Begin the Escape execution at the Break of Dawn\0";
int hash()
{
	int n, m, i;
	m = 0;
	n = strlen(str);
	for (i = 0; i < n; i++)
		m = (m*2377+((int)str[i]))%502973;
	return m;
}
bool check_string(char *a)
{
	char c[76];
	int length, i, j, k, l, r;
	length = strlen(a);
	for (i = 0; i < length; i++)
	{
		if (a[i] == 'C')
			break;
		if (a[i] == 'O' || a[i] == 'W')
			return 0;
	}
	for (i = length-1; i >= 0; i--)
	{
		if (a[i] == 'W')
			break;
		if (a[i] == 'C' || a[i] == 'O')
			return 0;
	}
	for (i = 0; i < length; i++)
	{
		r = 0;
		while (a[i] && a[i] != 'C' && a[i] != 'O' && a[i] != 'W')
			c[r++] = a[i++];
		for (j = 0; j+r <= 47; j++)
		{
			k = 0;
			l = j;
			while (k < r && c[k] == original[l])
			{
				k++;
				l++;
			}
			if (k == r)
				break;
		}
		if (j+r == 48)
			return 0;
	}
	return 1;
}
void turn_string(String *st, String *end)
{
	int l;
	String *i;
	for (i = st, l = 0; i != end; i = i->next, l++)
		str[l] = i->item;
	str[l] = 0;
}
void rec(String *st, String *end)
{
	String *i, *sw;
	int k, l, j;
	int cn, on, wn;//number of C/O/W in the string
	int plc[9], plo[9], plw[9];//positions of the C/O/W
	String *C[9], *O[9], *W[9];//pointers to the C/O/W
	String *pC[9], *pO[9], *pW[9];//pointers to the previous elements of the C/O/W
	cn = on = wn = 0;
	for (i = st, l = 0; i != end; i = i->next, l++)
	{
		char &q = i->item;
		if (q == 'C')
		{
			C[cn] = i;
			plc[cn++] = l;
		}
		if (q == 'O')
		{
			O[on] = i;
			plo[on++] = l;
		}
		if (q == 'W')
		{
			W[wn] = i;
			plw[wn++] = l;
		}
		if (i->next != end)
		{
			char &ww = i->next->item;
			if (ww == 'C')
				pC[cn] = i;
			if (ww == 'O')
				pO[on] = i;
			if (ww == 'W')
				pW[wn] = i;
		}
	}
	for (k = 0; k < cn; k++)
		for (l = 0; l < on; l++)
			for (j = 0; j < wn; j++)
				if (plc[k] < plo[l] && plo[l] < plw[j])
				{
					String *p, *q, *c, *o, *w, *pc, *po, *pw;
					p = q = new String;
					for (i = st; i != end; i = i->next)
					{
						if (i == C[k])
							c = q;
						if (i == O[l])
							o = q;
						if (i == W[j])
							w = q;
						if (i == pC[k])
							pc = q;
						if (i == pO[l])
							po = q;
						if (i == pW[j])
							pw = q;
						q->item = i->item;
						q->next = new String;
						q = q->next;
					}
/*					if (C[k] == st)
						p = st->next;
					if (W[j] == end)
						q = pW[j];*/
/*					if (c == p)
					{
						pc = p;
						p = p->next;
					}
					else
						pc->next = c->next;
					po->next = o->next;
					if (w == end)
						q = pw;
					else
						pw->next = w->next;
					delete c;
					delete o;
					delete w;
					if (c == p)
					{
						pc = p;
						p = p->next;
					}
					if (w == end)
						q = pw;
					sw = pc->next;
					pc->next = po->next;
					po->next = sw;
					sw = po->next;
					po->next = pw->next;
					pw->next = sw;
					pc->next = c->next;
					po->next = o->next;
					pw->next = w->next;
					turn_string(p, q);
					if (check_string(str))
					{
						if (strcmp(str, original) == 0)
						{
							found = 1;
							return;
						}
						h = hash();
						if (!t[h])
						{
							t[h] = 1;
							rec(p, q);
						}
					}
					delete p;
					delete q;
					delete pc;
					delete po;
					delete pw;
					delete c;
					delete o;
					delete w;
/*					if (C[k] == st)
						p = st->next;
					else
						pC[k]->next = C[k]->next;
					pO[l]->next = O[l]->next;
					if (W[j] == end)
						q = pW[j];
					else
						pW[j]->next = W[j]->next;
					pO[l]->next = C[k]->next;
					pC[k]->next = O[l]->next;
					sw = pO[l]->next = ;
					pO[l]->next = pW[j]->next;
				}
}
FILE* fin = fopen("cryptcow.in", "r");
FILE* fout = fopen("cryptcow.out", "w");
int main()
{
	String *head, *trail;
	int length, i;
	fgets(s, 76, fin);
	length = strlen(s)-1;
	if (s[length] == '\n')
		s[length] = 0;
	if (strcmp(s, original) == 0)
	{
		fprintf(fout, "1 0\n");
		return 0;
	}
	if ((length-47)%3)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < 47; i++)
		nl1[(int)original[i]]++;
	for (i = 0; i < length; i++)
		nl2[(int)s[i]]++;
	for (i = 0; i < 256; i++)
		if ((char)i != 'C' && (char)i != 'O' && (char)i != 'W' && nl1[i] != nl2[i])
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	if (nl2[(int)'C'] != nl2[(int)'O'] || nl2[(int)'O'] != nl2[(int)'W'] || nl2[(int)'C'] != nl2[(int)'W'])
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	if (nl2[(int)'C'] > 9)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	if (!check_string(s))
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	head = new String;
	trail = new String;
	head->next = trail;
	head->item = s[0];
	for (i = 1; i < length; i++)
	{
		trail->item = s[i];
		trail->next = new String;
		trail = trail->next;
	}
	strcpy(str, s);
	t[hash()] = 1;
	len = length;
	rec(head, trail);
	if (found)
		fprintf(fout, "1 %d\n", (strlen(s)-47)/3);
	else
		fprintf(fout, "0 0\n");
	return 0;
}
/*
#include <cstdio>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

int nl1[256] = {0};
int nl2[256] = {0};
int length, len, p, q;
bool t[502973] = {0}, found;
char s[76], c[76], original[] = "Begin the Escape execution at the Break of Dawn\0";
int hash(char *a)
{
	int n, m, i;
	m = 0;
	n = strlen(a);
	for (i = 0; i < n; i++)
		m = (m*2377+((int)a[i]))%502973;
	return m;
}
void rec(char *a)
{
	int C[30] = {0};
	int O[30] = {0};
	int W[30] = {0};
	int cn, on, wn, i, j, k, l;
	if (p == 0)
		if (strcmp(a, original) == 0)
		{
			found = 1;
			return;
		}
	cn = on = wn = 0;
	for (i = 0; i < len; i++)
	{
		if (a[i] == 'C')
			C[cn++] = i;
		if (a[i] == 'O')
			O[on++] = i;
		if (a[i] == 'W')
			W[wn++] = i;
	}
	for (i = 0; i < cn; i++)
		for (j = 0; j < on; j++)
			for (k = 0; k < wn; k++)
			{
				int &cc = C[i], &oo = O[j], &ww = W[k];
				if (cc < oo && oo < ww)
				{
					for (l = 0; l < cc; l++)
						c[l] = a[l];
					for (l = oo+1; l < ww; l++)
						c[l-oo+cc-1] = a[l];
					for (l = cc+1; l < oo; l++)
						c[l+ww-oo-2] = a[l];
					for (l = ww+1; l < len; l++)
						c[l-3] = a[l];
					q = hash(c);
					if (!t[q])
					{
						t[q] = 1;
						p--;
						len -= 3;
						c[len] = 0;
						rec(c);
						if (found)
							return;
						p++;
						len += 3;
					}
				}
			}
}
FILE* fin = fopen("cryptcow.in", "r");
FILE* fout = fopen("cryptcow.out", "w");
int main()
{
	cout << clock() << '\n';
	int i, j, k, l, r;
	fgets(s, 76, fin);
	length = strlen(s)-1;
	if (s[length] == '\n')
		s[length] = 0;
	if ((length-47)%3)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < 47; i++)
		nl1[(int)original[i]]++;
	for (i = 0; i < length; i++)
		nl2[(int)s[i]]++;
	for (i = 0; i < 256; i++)
		if ((char)i != 'C' && (char)i != 'O' && (char)i != 'W' && nl1[i] != nl2[i])
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	if (nl2[(int)'C'] != nl2[(int)'O'] || nl2[(int)'O'] != nl2[(int)'W'] || nl2[(int)'C'] != nl2[(int)'W'])
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < length; i++)
	{
		if (s[i] == 'C')
			break;
		if (s[i] == 'O' || s[i] == 'W')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = length-1; i >= 0; i--)
	{
		if (s[i] == 'W')
			break;
		if (s[i] == 'C' || s[i] == 'O')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = 0; i < length; i++)
	{
		r = 0;
		while (s[i] && s[i] != 'C' && s[i] == 'O' && s[i] == 'W')
			c[r++] = s[i++];
		for (j = 0; j+r <= 47; j++)
		{
			k = 0;
			l = j;
			while (c[k] && c[k++] == s[l++]);
			if (k == r)
				break;
		}
		if (j+r == 48)
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	p = nl2[(int)'C'];
	if (p > 9)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	t[hash(s)] = 1;
	len = length;
	rec(s);
	if (found)
		fprintf(fout, "1 %d\n", (length-47)/3);
	else
		fprintf(fout, "0 0\n");
	cout << clock() << '\n';
	return 0;
}
/*
#include <cstdio>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

int C[76] = {0};
int O[76] = {0};
int W[76] = {0};
int nl1[256] = {0};
int nl2[256] = {0};
bool t[502973] = {0};
char s[76], c[76], original[] = "Begin the Escape execution at the Break of Dawn\0";
struct node
{
	node *next;
	char string[76];
}*head, *trail, *temp;
int hash(char *a)
{
	int n, m, i;
	m = 0;
	n = strlen(a);
	for (i = 0; i < n; i++)
		m = (m*2377+((int)a[i]))%502973;
	return m;
}
FILE* fin = fopen("cryptcow.in", "r");
FILE* fout = fopen("cryptcow.out", "w");
int main()
{
	cout << clock() << '\n';
	int length, last, cn, on, wn, n, h, i, j, k, l, r;
	fgets(s, 76, fin);
	length = strlen(s)-1;
	if (s[length] == '\n')
		s[length] = 0;
	if ((length-47)%3)
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < 47; i++)
		nl1[(int)original[i]]++;
	for (i = 0; i < length; i++)
		nl2[(int)s[i]]++;
	for (i = 0; i < 256; i++)
		if ((char)i != 'C' && (char)i != 'O' && (char)i != 'W' && nl1[i] != nl2[i])
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	if (nl2[(int)'C'] != nl2[(int)'O'] || nl2[(int)'O'] != nl2[(int)'W'] || nl2[(int)'C'] != nl2[(int)'W'])
	{
		fprintf(fout, "0 0\n");
		return 0;
	}
	for (i = 0; i < length; i++)
	{
		if (s[i] == 'C')
			break;
		if (s[i] == 'O' || s[i] == 'W')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = length-1; i >= 0; i--)
	{
		if (s[i] == 'W')
			break;
		if (s[i] == 'C' || s[i] == 'O')
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	for (i = 0; i < length; i++)
	{
		r = 0;
		while (s[i] && s[i] != 'C' && s[i] == 'O' && s[i] == 'W')
			c[r++] = s[i++];
		for (j = 0; j+r <= 47; j++)
		{
			k = 0;
			l = j;
			while (c[k] && c[k++] == s[l++]);
			if (k == r)
				break;
		}
		if (j+r == 48)
		{
			fprintf(fout, "0 0\n");
			return 0;
		}
	}
	last = nl2[(int)'C'];
	head = new node;
	trail = new node;
	head->next = trail;
	strcpy(head->string, s);
	t[hash(s)] = 1;
	while (head != trail)
	{
		strcpy(s, head->string);
		temp = head;
		head = head->next;
		delete temp;
		n = strlen(s);
		if (n == 47)
			if (strcmp(s, original) == 0)
			{
				fprintf(fout, "1 %d\n", (length-47)/3);
				cout << clock() << '\n';
				return 0;
			}
		cn = on = wn = 0;
		for (i = 0; i < n; i++)
		{
			if (s[i] == 'C')
				C[cn++] = i;
			if (s[i] == 'O')
				O[on++] = i;
			if (s[i] == 'W')
				W[wn++] = i;
		}
		if (last != cn)
		{
			last = cn;
			memset(t, 0, 502973);
		}
		for (i = 0; i < cn; i++)
			for (j = 0; j < on; j++)
				for (k = 0; k < wn; k++)
					if (C[i] < O[j] && O[j] < W[k])
					{
						int &cc = C[i], &oo = O[j], &ww = W[k];
						for (l = 0; l < cc; l++)
							c[l] = s[l];
						for (l = oo+1; l < ww; l++)
							c[l-oo+cc-1] = s[l];
						for (l = cc+1; l < oo; l++)
							c[l+ww-oo-2] = s[l];
						for (l = ww+1; l < n; l++)
							c[l-3] = s[l];
						c[n-3] = 0;
						h = hash(c);
						if (!t[h])
						{
							t[h] = 1;
							strcpy(trail->string, c);
							trail->next = new node;
							trail = trail->next;
						}
					}
	}
	fprintf(fout, "0 0\n");
	cout << clock() << '\n';
	return 0;
}*/