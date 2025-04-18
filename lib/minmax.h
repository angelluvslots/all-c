#ifndef MINMAX_H
#define MINMAX_H

#define min(X, Y) (X) > (Y) ? (Y) : (X)
#define max(X, Y) (X) < (Y) ? (Y) : (X)
#define clamp(X, LOW, HIGH) max(min(X, HIGH), LOW)

#endif
