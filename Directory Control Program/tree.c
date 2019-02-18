#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "treeapi.h"
#include "tree.h"

struct file *createTree()
{
	char buffer[64];

	struct file *tree = NULL;

	tree = malloc(sizeof(struct file));

	if (tree == NULL) {
		printf("Could not initialize tree @main\n");
	}

	// tree->fileName = "root";
	tree->fileName = malloc(8 * sizeof(char)); /* Otherwise freeTree() does not work properly */

	memset(tree->fileName, '\0', 8);

	strcpy(tree->fileName, "root");
	tree->next   = NULL;
	tree->subdir = NULL;

	while (fgets(buffer, sizeof(buffer), stdin)) {
		buffer[strcspn(buffer, "\n")] = 0; /* Removes the trailing newline */

		char *currentFileName;
		currentFileName = strtok(buffer, "/");

		struct file *currentDirectory = tree;

		while(currentFileName != NULL) {

			currentDirectory = insert(currentDirectory, currentFileName);
			currentFileName  = strtok(NULL, "/");
		}
	}

	return tree;
}

/*
 * Insert the <file> under <directory>'s <subdirectory>
 * Return the last inserted directory so the next token can continue searching from there
 */
struct file *insert(struct file* directory, char *fileName)
{
	struct file *tmp = search(directory->subdir, fileName);
	/* Returns the existing directory or NULL */

	if (tmp != NULL) /* a file already exists under <directory> named <fileName> */
		return tmp;
	else if (directory->subdir == NULL)	/* directory is an empty folder */
		return addAsFirstFileUnder(directory, fileName);
	else	/* directory is not an empty folder, identical to linkedList::add */
		return addToDirectory(directory, fileName);
}

struct file *addAsFirstFileUnder(struct file* directory, char *fileName)
{
	directory->subdir = malloc(sizeof(struct file));

	if (directory->subdir == NULL)
		printf("Could not initialize %s @ insert()\n", fileName);

	directory->subdir->fileName = malloc((strlen(fileName) * sizeof(char)) + 1);

	strcpy(directory->subdir->fileName, fileName);
	directory->subdir->next   = NULL;
	directory->subdir->subdir = NULL;

	return directory;
}

struct file *addToDirectory(struct file* directory, char *fileName)
{

	struct file *dir = directory->subdir;

	while (dir->next != NULL)
		dir = dir->next;

	dir->next = malloc(sizeof(struct file));

	if (dir->next == NULL)
		printf("Could not malloc %s->%s @insert\n", dir->fileName, fileName);

	dir->next->fileName = malloc((strlen(fileName) * sizeof(char)) + 1);

	if (dir->next->fileName == NULL)
		printf("Could not malloc the filename of %s->%s @insert\n", dir->fileName, fileName);

	strcpy(dir->next->fileName, fileName);

	dir->next->next   = NULL;
	dir->next->subdir = NULL;

	return dir;
}

struct file *search(struct file *directory, char *fileName)
{
	struct file *cursor = directory;

	while (cursor != NULL) {
		if (strcmp(cursor->fileName, fileName) == 0)
			break;

		cursor = cursor->next;
	}
	return cursor;
}


void freeTree(struct file *root)
{
	if (root == NULL) {
		return;
	}

	struct file *next;
	struct file *down;

	down = root->subdir;
	next = root->next;

	freeTree(down);
	freeTree(next);

	free(root->fileName);
	root->fileName = NULL;

	free(root);
}
