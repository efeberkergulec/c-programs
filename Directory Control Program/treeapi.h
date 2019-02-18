#ifndef TREEAPI_H_INCLUDED
#define TREEAPI_H_INCLUDED

struct file {
	char *fileName;
	struct file *next;
	struct file *subdir;
};

extern struct file *createTree();
extern void freeTree(struct file *root);

#endif
