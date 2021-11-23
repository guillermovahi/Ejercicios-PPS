#define DATA_SIZE 4

typedef struct node {
	int len;
	int data[DATA_SIZE];
	struct node* next;
} node_t;

typedef struct {
	struct node* first;
	struct node* last;
} queue;


queue* create();
void add(queue*, int);
int is_empty(queue*);
int peek(queue*);
void poll(queue*);
