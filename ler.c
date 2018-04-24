/*
 * ler.c
 * 
 * Copyright 2018 Vitor <vitor@vitor-mazon>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** ler(const char *nomeArq, int *xdim, int *ydim) {
	int i, j, x=0, y=1, cont;
	double **L, a; 
	char c;
	FILE *arq;
    arq=fopen(nomeArq, "r");
    while ((c=fgetc(arq)) != EOF) {
		if(c=='\n') {
			x++;
			cont=1;
		}
		else {
			if(c=='\t' && cont!=1)
				y++;
		}
	}
	fclose(arq);
	
	arq = fopen(nomeArq, "r");
	L=malloc(x*sizeof(double *));
	for(i=0; i<x; i++)
		L[i]=(double *)malloc((y)*sizeof(double));
	i=j=0;
	while (fscanf(arq,"%lf",&a) != EOF) {
		L[i][j] = a;
		j++;
		if (j == y) {
			j = 0;
			i++;
		}
	}
	*xdim=x;
	*ydim=y;
	return L;
}
