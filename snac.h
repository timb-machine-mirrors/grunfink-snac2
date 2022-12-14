/* snac - A simple, minimalistic ActivityPub instance */
/* copyright (c) 2022 grunfink - MIT license */

#define VERSION "2.15"

#define USER_AGENT "snac/" VERSION

extern double db_layout;
extern d_char *srv_basedir;
extern d_char *srv_config;
extern d_char *srv_baseurl;
extern int     srv_running;

extern int dbglevel;

extern const char *susie;

#define L(s) (s)

int valid_status(int status);
d_char *tid(int offset);
double ftime(void);

void srv_debug(int level, d_char *str);
#define srv_log(str) srv_debug(0, str)

int srv_open(char *basedir, int auto_upgrade);
void srv_free(void);

typedef struct _snac {
    d_char *uid;        /* uid */
    d_char *basedir;    /* user base directory */
    d_char *config;     /* user configuration */
    d_char *key;        /* keypair */
    d_char *actor;      /* actor url */
    d_char *md5;        /* actor url md5 */
} snac;

int user_open(snac *snac, const char *uid);
void user_free(snac *snac);
d_char *user_list(void);

void snac_debug(snac *snac, int level, d_char *str);
#define snac_log(snac, str) snac_debug(snac, 0, str)

int validate_uid(const char *uid);

d_char *hash_password(const char *uid, const char *passwd, const char *nonce);
int check_password(const char *uid, const char *passwd, const char *hash);

void srv_archive(char *direction, char *req, char *payload, int p_size,
                 int status, char *headers, char *body, int b_size);

double mtime_nl(const char *fn, int *n_link);
#define mtime(fn) mtime_nl(fn, NULL)

int index_add(const char *fn, const char *md5);
int index_del(const char *fn, const char *md5);
int index_first(const char *fn, char *buf, int size);
int index_len(const char *fn);
d_char *index_list(const char *fn, int max);
d_char *index_list_desc(const char *fn, int skip, int show);

int object_add(const char *id, d_char *obj);
int object_add_ow(const char *id, d_char *obj);
int object_here_by_md5(char *id);
int object_here(char *id);
int object_get_by_md5(const char *md5, d_char **obj, const char *type);
int object_get(const char *id, d_char **obj, const char *type);
int object_del(const char *id);
int object_del_if_unref(const char *id);
int object_admire(const char *id, const char *actor, int like);

int object_likes_len(const char *id);
int object_announces_len(const char *id);

d_char *object_children(const char *id);
d_char *object_likes(const char *id);
d_char *object_announces(const char *id);
int object_parent(const char *id, char *buf, int size);

int object_user_cache_add(snac *snac, const char *id, const char *cachedir);
int object_user_cache_del(snac *snac, const char *id, const char *cachedir);

int follower_add(snac *snac, const char *actor);
int follower_del(snac *snac, const char *actor);
int follower_check(snac *snac, const char *actor);
d_char *follower_list(snac *snac);

double timeline_mtime(snac *snac);
int timeline_del(snac *snac, char *id);
d_char *timeline_simple_list(snac *snac, const char *idx_name, int skip, int show);
d_char *timeline_list(snac *snac, const char *idx_name, int skip, int show);
int timeline_add(snac *snac, char *id, char *o_msg, char *parent, char *referrer);
void timeline_admire(snac *snac, char *o_msg, char *id, char *admirer, int like);

d_char *timeline_top_level(d_char *list);

d_char *local_list(snac *snac, int max);

int following_add(snac *snac, char *actor, char *msg);
int following_del(snac *snac, char *actor);
int following_check(snac *snac, char *actor);
int following_get(snac *snac, char *actor, d_char **data);
d_char *following_list(snac *snac);

void mute(snac *snac, char *actor);
void unmute(snac *snac, char *actor);
int is_muted(snac *snac, char *actor);

void hide(snac *snac, const char *id);
int is_hidden(snac *snac, const char *id);

int actor_add(snac *snac, const char *actor, d_char *msg);
int actor_get(snac *snac, const char *actor, d_char **data);

int static_get(snac *snac, const char *id, d_char **data, int *size);
void static_put(snac *snac, const char *id, const char *data, int size);

double history_mtime(snac *snac, char *id);
void history_add(snac *snac, char *id, char *content, int size);
d_char *history_get(snac *snac, char *id);
int history_del(snac *snac, char *id);
d_char *history_list(snac *snac);

void enqueue_input(snac *snac, char *msg, char *req, int retries);
void enqueue_output(snac *snac, char *msg, char *inbox, int retries);
void enqueue_output_by_actor(snac *snac, char *msg, char *actor, int retries);
void enqueue_email(snac *snac, char *msg, int retries);

d_char *queue(snac *snac);
d_char *dequeue(snac *snac, char *fn);

void purge(snac *snac);
void purge_all(void);

d_char *http_signed_request(snac *snac, char *method, char *url,
                        d_char *headers,
                        d_char *body, int b_size,
                        int *status, d_char **payload, int *p_size);
int check_signature(snac *snac, char *req);

void httpd(void);

int webfinger_request(char *qs, char **actor, char **user);
int webfinger_get_handler(d_char *req, char *q_path,
                          char **body, int *b_size, char **ctype);

d_char *msg_admiration(snac *snac, char *object, char *type);
d_char *msg_create(snac *snac, char *object);
d_char *msg_follow(snac *snac, char *actor);
d_char *msg_note(snac *snac, char *content, char *rcpts, char *in_reply_to, char *attach);
d_char *msg_undo(snac *snac, char *object);
d_char *msg_delete(snac *snac, char *id);
d_char *msg_actor(snac *snac);
d_char *msg_update(snac *snac, char *object);

int activitypub_request(snac *snac, char *url, d_char **data);
int actor_request(snac *snac, char *actor, d_char **data);
int send_to_inbox(snac *snac, char *inbox, char *msg, d_char **payload, int *p_size);
d_char *get_actor_inbox(snac *snac, char *actor);
int send_to_actor(snac *snac, char *actor, char *msg, d_char **payload, int *p_size);
int is_msg_public(snac *snac, char *msg);
void process_queue(snac *snac);
void post(snac *snac, char *msg);
int activitypub_get_handler(d_char *req, char *q_path,
                            char **body, int *b_size, char **ctype);
int activitypub_post_handler(d_char *req, char *q_path,
                             char *payload, int p_size,
                             char **body, int *b_size, char **ctype);

d_char *not_really_markdown(const char *content);
d_char *sanitize(const char *str);

int html_get_handler(d_char *req, char *q_path, char **body, int *b_size, char **ctype);
int html_post_handler(d_char *req, char *q_path, d_char *payload, int p_size,
                      char **body, int *b_size, char **ctype);

int initdb(const char *_basedir);
int adduser(const char *uid);
int resetpwd(snac *snac);
