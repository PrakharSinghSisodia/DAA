#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>


struct Point {
double x, y;
};


double dist(struct Point p1, struct Point p2) {
return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
(p1.y - p2.y)*(p1.y - p2.y));
}


int compareX(const void* a, const void* b) {
struct Point *p1 = (struct Point*)a;
struct Point *p2 = (struct Point*)b;
return (p1->x - p2->x);
}


int compareY(const void* a, const void* b) {
struct Point *p1 = (struct Point*)a;
struct Point *p2 = (struct Point*)b;
return (p1->y - p2->y);
}


double stripClosest(struct Point strip[], int size, double d) {
double min = d;
qsort(strip, size, sizeof(struct Point), compareY);


for (int i = 0; i < size; i++)
for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++)
if (dist(strip[i], strip[j]) < min)
min = dist(strip[i], strip[j]);
return min;
}


double closestUtil(struct Point P[], int n) {
if (n <= 3) {
double min = DBL_MAX;
for (int i = 0; i < n; i++)
for (int j = i + 1; j < n; j++)
if (dist(P[i], P[j]) < min)
min = dist(P[i], P[j]);
return min;
}


int mid = n / 2;
struct Point midPoint = P[mid];


double dl = closestUtil(P, mid);
double dr = closestUtil(P + mid, n - mid);


double d = (dl < dr) ? dl : dr;


struct Point strip[n];
int j = 0;
for (int i = 0; i < n; i++)
if (fabs(P[i].x - midPoint.x) < d)
strip[j++] = P[i];


return stripClosest(strip, j, d);
}


double closest(struct Point P[], int n) {
qsort(P, n, sizeof(struct Point), compareX);
return closestUtil(P, n);
}


int main() {
struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}};
int n = sizeof(P) / sizeof(P[0]);
printf("The smallest distance is %f", closest(P, n));
return 0;
}
