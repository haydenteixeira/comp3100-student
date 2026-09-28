/* ledger-hall.c -- Work Order No. 1851-06, the ledger hall.
 *
 * One page. The four district balances down the side -- Northgate,
 * Waterside, Old Quarter, Kiln Row, the same four as the waterworks
 * table -- and a total written at the foot. A page is correct only when
 * the four balances and the total agree. That is the entire purpose of
 * writing a total.
 *
 * One clerk posts to the page as the quarter's figures come in. Six
 * readers stand at the rail and read it, over and over, adding the four
 * balances up for themselves to see whether the foot of the page is
 * honest.
 *
 * The clerk posts the way a pen posts: one entry at a time, down the
 * column, and the total last. Nothing asks a reader to stand back while
 * the pen is moving, and nothing asks the pen to wait for the readers.
 *
 * Count how many pages balanced, then look at the page that did not.
 */
#define _GNU_SOURCE

/* ledger-hall.c -- Work Order No. 1851-06. */
#include <stdio.h>
#include <sched.h>
#include <pthread.h>

#define DISTRICTS 4
#define READERS 6
#define POSTINGS 2000000

static const long OPENING[DISTRICTS] = {
    53516, 61247, 44637, 54667
};

#define OPENING_SUM (53516L + 61247L + 44637L + 54667L)

static long balance[DISTRICTS];
static long stated_total;

/* The rail. Any number of readers may stand at it together; the pen may
 * not be at the page while anybody is standing there. */
static pthread_rwlock_t page_lock;

static int clerk_done = 0;

struct reader {
    int number;
    long pages;
    long torn;
    int have_specimen;
    long specimen[DISTRICTS];
    long specimen_total;
};

static void *read_the_page(void *arg)
{
    struct reader *r = arg;

    while (!clerk_done) {
        long seen[DISTRICTS];
        long sum = 0;
        long foot;
        int d;

        pthread_rwlock_rdlock(&page_lock);

        for (d = 0; d < DISTRICTS; d++) {
            seen[d] = balance[d];
            sum += seen[d];
        }
        foot = stated_total;

        pthread_rwlock_unlock(&page_lock);

        r->pages++;

        if (sum != foot) {
            r->torn++;

            if (!r->have_specimen) {
                for (d = 0; d < DISTRICTS; d++)
                    r->specimen[d] = seen[d];

                r->specimen_total = foot;
                r->have_specimen = 1;
            }
        }

        sched_yield();
    }

    return NULL;
}

static void *post_the_figures(void *arg)
{
    long n;
    int d;

    (void)arg;

    for (n = 1; n <= POSTINGS; n++) {
        pthread_rwlock_wrlock(&page_lock);

        /* One entry at a time, down the column, as a pen does. */
        for (d = 0; d < DISTRICTS; d++)
            balance[d] = OPENING[d] + n;

        /* And the total at the foot, when the column is done. */
        stated_total = OPENING_SUM + n * DISTRICTS;

        pthread_rwlock_unlock(&page_lock);

        sched_yield();
    }

    clerk_done = 1;
    return NULL;
}

int main(void)
{
    struct reader readers[READERS];
    pthread_t reader_thread[READERS], clerk_thread;
    long pages = 0, torn = 0;
    int d, r;
    int specimen_reader = -1;

    {
        /* The pen gets priority. Six readers at a tight rail never all
         * step back at once, and a default lock would leave the clerk
         * standing there for good. */
        pthread_rwlockattr_t how;

        pthread_rwlockattr_init(&how);
        pthread_rwlockattr_setkind_np(
            &how,
            PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP
        );
        pthread_rwlock_init(&page_lock, &how);
    }

    for (d = 0; d < DISTRICTS; d++)
        balance[d] = OPENING[d];

    stated_total = OPENING_SUM;

    printf("Ledger hall: one clerk posting %d times, %d readers at the rail.\n\n",
           POSTINGS, READERS);

    for (r = 0; r < READERS; r++) {
        readers[r].number = r + 1;
        readers[r].pages = 0;
        readers[r].torn = 0;
        readers[r].have_specimen = 0;
        readers[r].specimen_total = 0;

        for (d = 0; d < DISTRICTS; d++)
            readers[r].specimen[d] = 0;

        if (pthread_create(&reader_thread[r], NULL,
                           read_the_page, &readers[r]) != 0) {
            fprintf(stderr,
                    "ledger-hall: reader %d would not come on duty\n",
                    r + 1);
            return 1;
        }
    }

    if (pthread_create(&clerk_thread, NULL,
                       post_the_figures, NULL) != 0) {
        fprintf(stderr, "ledger-hall: the clerk would not come on duty\n");
        return 1;
    }

    pthread_join(clerk_thread, NULL);

    for (r = 0; r < READERS; r++)
        pthread_join(reader_thread[r], NULL);

    for (r = 0; r < READERS; r++) {
        printf("  reader %d: %ld pages read, %ld did not balance\n",
               readers[r].number,
               readers[r].pages,
               readers[r].torn);

        pages += readers[r].pages;
        torn += readers[r].torn;

        if (specimen_reader < 0 && readers[r].have_specimen)
            specimen_reader = r;
    }

    printf("\n");
    printf("  pages read: %ld\n", pages);
    printf("  pages that balanced: %ld\n", pages - torn);
    printf("  pages that did not balance: %ld\n", torn);

    if (specimen_reader >= 0) {
        struct reader *s = &readers[specimen_reader];
        long sum = 0;

        printf("\n");
        printf("  the first page reader %d could not make balance:\n",
               s->number);

        printf("    Northgate    %ld\n", s->specimen[0]);
        printf("    Waterside    %ld\n", s->specimen[1]);
        printf("    Old Quarter  %ld\n", s->specimen[2]);
        printf("    Kiln Row     %ld\n", s->specimen[3]);

        for (d = 0; d < DISTRICTS; d++)
            sum += s->specimen[d];

        printf("    total        %ld   <- and the column adds to %ld\n",
               s->specimen_total, sum);

        printf("\n");
        printf("  Nobody wrote a wrong figure. Every figure on that page was\n");
        printf("  true when the pen wrote it. The page is still wrong.\n");
    } else {
        printf("\n");
        printf("  every page balanced this time. Run it again.\n");
    }

    return 0;
}
