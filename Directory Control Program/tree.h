#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

extern struct file *insert(struct file *directory, char *fileName);
extern struct file *addAsFirstFileUnder(struct file* directory, char *fileName);
extern struct file *addToDirectory(struct file* directory, char *fileName);
extern struct file *search(struct file *directory, char *fileName);

#endif
