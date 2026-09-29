typedef struct sklad{
    char ime[10];
    int *vrsta;
    int index;
    int velikost;
} s;

void init(s *sk,int velikost);
int push(int x, s *sk);
int pop(s *sk);
int isEmpty(s *sk);
void izpisi(s *sk);