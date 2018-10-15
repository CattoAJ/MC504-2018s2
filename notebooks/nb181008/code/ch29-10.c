#define BUCKETS (101)

typedef struct 	hash_t {
    list_t lists[BUCKETS] ;
} hash_t;

void Hash_Init(hash_t *H)	{
    for (int i = 0; i < BUCKETS; i++)	{
        List_Init(&H->lists [i]);
    }
}

int Hash_Insert(hash_t *H, int key) {
    int bucket = key % BUCKETS;
    return List_Insert(&H->lists[bucket], key)
}

int Hash_Lookup(hash_t *H, int key) {
    int bucket = key % BUCKETS;
    return List_Lookup(&H->lists[bucket], key);
}