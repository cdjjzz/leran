//
// Created by Administrator on 2023/12/4.
//

#ifndef C_MATHSTATUS_RB_H
#define C_MATHSTATUS_RB_H

#endif //C_MATHSTATUS_RB_H

typedef void* key_type;
typedef void* value_type;

typedef enum COLOR COLOR;
enum COLOR
{
    RED    = 0x00000000,
    BLACK     = 0x00000001
};

typedef struct rb_node  rb_node;
struct rb_node
{
    rb_node *left;  //left child
    rb_node *right; //right child
    rb_node *parent; //parent node

    void*       key;
    void*       value;

    int         ksz; //key size
    int         vsz; //value size

    //函数指针
    int         (*_key_compare)(void* k1,void* k2);
    void        (*_key_copy)(void *dest, void *src);
    void        (*_value_copy)(void *dest, void* src);

    COLOR     color;
    int       used;
};
struct rb_tree
{
    rb_node *root;
    int  nodecount;
};

rb_node * rb_node_new(key_type key, value_type value);
rb_node * _rbnode_new(int ksz,int vsz, void *k,void*v);

void    rb_node_free(rb_node *node);

rb_node * rb_node_rotate_left( rb_node *node, rb_node **root);

rb_node * rb_node_rotate_right(rb_node *node, rb_node **root);

rb_node * rb_search_auxiliary(rb_node *root, key_type key, rb_node **save);

rb_node * rb_search(rb_node *root, key_type key);

rb_node * rb_insert_rebalance(rb_node *node, rb_node **root);
rb_node * rb_insert(const key_type key, const value_type value, rb_node **root);
rb_node * rb_add_node( rb_node* node, rb_node **root);


rb_node * rb_erase_balance(rb_node *node, rb_node *parent, rb_node *root);

rb_node * rb_erase(const key_type key, rb_node *root);

void        rb_free( rb_node *root);
