typedef struct 	counter_t {
    int	global;				// global count
    Mutex_t glock;		        // global lock
    int	local[NUM_CPUS];		// local count (per cpu)
    Mutex_t llock[NUM_CPUS];	        // ... and locks
    int	threshold;			// update frequency
} counter_t;

// init: record threshold, init locks, init values
//	 of all local counts and global count
void init(counter_t *c, int threshold) {
    c->threshold = threshold;
    c->global = 0;
    Mutex_init(&c->glock);
    for (int i = 0; i < NUM_CPUS; i++) {
        c->local[i] = 0;
        Mutex_init(&c->llock[i]);
    }
}

// update: usually, just grab local lock and update local amount
//	   once local count has risen by 'threshold', grab global
//	   lock and transfer local values to it
void update(counter_t *c, int threadID, int amt) {
    int cpu = threadID % NUM_CPUS;
    Mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt;	                // assumes amt > 0
    if (c->local[cpu] >= c->threshold) {	// transfer to global
        Mutex_lock(&c->glock);
        c->global += c->local[cpu];
        Mutex_unlock(&c->glock);
        c->local[cpu] = 0;
    }
    Mutex_unlock(&c->llock[cpu]);
}

// get: just return global amount (which may not be perfect)
int get(counter_t *c) {
    Mutex_lock(&c->glock);
    int val = c->global;
    Mutex_unlock(&c->glock) ;
    return val; // only approximate!
}

