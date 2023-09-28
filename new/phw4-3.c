#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_DIM 2
struct kd_node_t {
    double x[MAX_DIM];
    struct kd_node_t* left, * right;
};

// buffer for range search
struct node {
    struct kd_node_t* node;
    struct node* next;
};
struct node result_root = { {NULL}, {NULL} };
struct node* buffer = &result_root;


double dist(struct kd_node_t* a, struct kd_node_t* b, int dim) 
{
    double t, d = 0;

    while (dim--) {
        t = a->x[dim] - b->x[dim];
        d += t * t;
    }
    return d; 
}


void swap(struct kd_node_t* x, struct kd_node_t* y) {

    double tmp[MAX_DIM];

    memcpy(tmp, x->x, sizeof(tmp));
    memcpy(x->x, y->x, sizeof(tmp));
    memcpy(y->x, tmp, sizeof(tmp));
}


/*see quickselect method*/
struct kd_node_t* find_median(struct kd_node_t* start, struct kd_node_t* end, int idx) {
    if (end <= start) return NULL;
    if (end == start + 1)
        return start;

    struct kd_node_t* p, * store, * md = start + (end - start) / 2;
    double pivot;
    while (1) {
        pivot = md->x[idx];

        swap(md, end - 1);
        for (store = p = start; p < end; p++) {
            if (p->x[idx] < pivot) {
                if (p != store) {
                    swap(p, store);
                }
                store++;
            }
        }
        swap(store, end - 1);

        /* median has duplicate values */
        if (store->x[idx] == md->x[idx])
            return md;

        if (store > md)
            end = store;
        else
            start = store;
    }
}

struct kd_node_t* make_tree(struct kd_node_t* t, int len, int i, int dim)
{
    struct kd_node_t* n;

    if (!len) return 0;

    if ((n = find_median(t, t + len, i))) {
        i = (i + 1) % dim;

        n->left = make_tree(t, n - t, i, dim);

        n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
    }
    return n;
}

/* global variable, so sue me */
int visited;

//Search the smallest distance
void best_dist_search(struct kd_node_t* root, struct kd_node_t* search, double* best_dist) {
    if (root != NULL) {
        if (root->x[0] != search->x[0] || root->x[1] != search->x[1]) {
            double temp_dist = dist(root, search, MAX_DIM);
            *best_dist = *best_dist >= temp_dist ? temp_dist : *best_dist;
        }
        best_dist_search(root->left, search, best_dist);
        best_dist_search(root->right, search, best_dist);
        visited++;
    }
}

//point_search
int point_search(struct kd_node_t* head, double x, double y, int h) {
    
    //When head is NULL, print search failed
    if (head == NULL) {
        printf("Search failed (%g, %g)\n", x, y);
        return 0;
    }
    h++;
    // X-coordinate search
    if (h % 2 == 1)
    {
        if (head->x[0] > x)
            point_search(head->left, x, y, h);  //recursive
        else if (head->x[0] < x)
            point_search(head->right, x, y, h); //recursive
        else if (head->x[0] == x) {
            //compare other coordinate that Y
            if (head->x[1] == y) {
                printf("Search successed (%g,%g)\n", x, y);

                return 1;
            }
            else {
                point_search(head->left, x, y, h);
            }
        }

        else {
            printf("searching failed\n");

            return 0;
        }
    }

    // Y-coordinate search
    else if (h % 2 == 0) {
        if (head->x[1] > y)
            point_search(head->left, x, y, h);  //recursive
        else if (head->x[1] < y)
            point_search(head->right, x, y, h); //recursive
        else if (head->x[1] == y) {
            //compare other coordinate that X
            if (head->x[0] == x) {
                printf("Search successed (%g,%g)\n", x, y);

                return 1;
            }
            else {
                point_search(head->left, x, y, h);
            }
        }
        else {
            printf("searching failed\n");
            return 0;
        }
    }
    return 0;
}

//range_search
int range_search(struct kd_node_t* root, struct kd_node_t leftbottom, double width, double height, int dimension, int check) {
    struct kd_node_t* p = root;
    double boundary[MAX_DIM] = { width,height };
    //change the value to the rest
    dimension %= MAX_DIM; 

    //when leaf node is reached
    if (p == NULL) {
        if (check != 0) //when at least one node has been discovered successfully
            return 1;
        else //No node in range when check is 0 days
            return 0;
    }

    if (leftbottom.x[dimension] <= p->x[dimension]) {
        //The node is in range on a given axis 
        if (leftbottom.x[dimension] + boundary[dimension] >= p->x[dimension]) {

            //Check if other axes are in range
            if (leftbottom.x[(dimension + 1) % MAX_DIM] <= p->x[(dimension + 1) % MAX_DIM] && 
                leftbottom.x[(dimension + 1) % MAX_DIM] + boundary[(dimension + 1) % MAX_DIM] >= p->x[(dimension + 1) % MAX_DIM]) 
            {
                printf("Found Node(%.1f, %.1f) in boundary (leftbottom: %.1f, %.1f width: %.1f height:%.1f)\n", 
                    p->x[0], p->x[1], leftbottom.x[0], leftbottom.x[1], width, height);
                check++;
            }
            range_search(p->left, leftbottom, width, height, dimension, check);
            range_search(p->right, leftbottom, width, height, dimension, check);
        }
        //The node is smaller than the larger threshold 
        else {
            //Navigating Left Subtrees Only
            range_search(p->left, leftbottom, width, height, dimension, check);
        }
    }
    // The node is on the left (when it is smaller) than the smaller threshold
    else {
        //Right subtree only navigation
        range_search(p->right, leftbottom, width, height, dimension, check);
    }

}

//nearest_neighbor_search
void nearest_neighbor_search(struct kd_node_t* root, struct kd_node_t* search, double* best_dist) {
    if (visited == 0)   //Search the smallest distance
        best_dist_search(root, search, best_dist);
    if (root != NULL) { //if root is exist

        if (*best_dist == dist(root, search, MAX_DIM)) {
            buffer->next = (struct node*)malloc(sizeof(struct node));   

            if (!buffer->next) {
                printf("Memory not allocated");
                exit(0);
            }
            buffer = buffer->next;
            buffer->node = root;
            buffer->next = NULL;
        }
        nearest_neighbor_search(root->left, search, best_dist); //recursive
        nearest_neighbor_search(root->right, search, best_dist);   //recursive
    }
}

int main(void)
{
    int i;
    struct kd_node_t wp[] = { {{2, 3}}, {{5, 4}}, {{3,4}}, {{9, 6}}, {{4, 7}}, {{8, 1}}, {{7, 2}} };
    
    //To test nearest_neighbor_search function 
    struct kd_node_t testNode = { {5, 4} }; //input1
    struct kd_node_t testNode1 = { {4, 7} };   //input2
    
    struct kd_node_t* root, * found, * million;


    //make_tree(header, node`s number, index , element number )
    root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);


    visited = 0;
    found = 0;


    double x_coordinate, y_coordinate;

    //---------------------------------------------------
    //point_search
    //print results
    printf("**[Point_Search]**\n");
    x_coordinate = 5; y_coordinate = 4;     //(5,4)
    point_search(root, x_coordinate, y_coordinate, 0);
    x_coordinate = 4; y_coordinate = 7;     //(4,7)
    point_search(root, x_coordinate, y_coordinate, 0);
    x_coordinate = 10; y_coordinate = 5;    //(10,5)
    point_search(root, x_coordinate, y_coordinate, 0);


    //---------------------------------------------------
    //range_search
    //print results
    printf("\n**[Range_Search]**\n");
    //specify rectangle (left x = 6, left y = 3)
    struct kd_node_t leftbottom;
    leftbottom.x[0] = 6;    //left x = 6
    leftbottom.x[1] = 3;    //left y = 3
    double width = 3, height = 4;   //width = 3, height = 4

    leftbottom.left = NULL;
    leftbottom.right = NULL;
    //Prints an error message after the last value returned is considered 
    int check = range_search(root, leftbottom, width, height, 0, 0);
    if (check == 0)
        printf("\nSearch Fail(Not exist any node in boundary)\n");


    //---------------------------------------------------
    //nearest_neighbor_search
    //print results
    printf("\n**[Nearest_Neighbor_Search]**\n");

    //Test function 1) input (5,4)
    //initializes best_dist
    double best_dist = 2147483647;  

    testNode.x[0] = 5, testNode.x[1] = 4;   //(5,4)
    visited = 0;
    nearest_neighbor_search(root, &testNode, &best_dist);
    struct node* r = &result_root;
    //prints most nearest Nodes
    printf("------(5, 4)------");
    while (r) {
        if (r != &result_root)
            printf("\nNODE(%.1f, %.1f) is most nearest NODE(%.1f, %.1f)", r->node->x[0], r->node->x[1], testNode.x[0], testNode.x[1]);
        r = r->next;
    }

    printf("\ndistance : %.1f\n", sqrt(best_dist));
    
    //Test function 2) input (4,7)
    //initializes best_dist
    best_dist = 2147483647;

    testNode.x[0] = 4, testNode.x[1] = 7;   //(4,7)
    visited = 0;
    nearest_neighbor_search(root, &testNode, &best_dist);
    r = &result_root;
    //prints more nearest Nodes
    printf("\n------(4, 7)------");
    while (r) {
        if (r != &result_root)
            printf("\nNODE(%.1f, %.1f) is most nearest NODE(%.1f, %.1f)", r->node->x[0], r->node->x[1], testNode.x[0], testNode.x[1]);
        r = r->next;
    }
    printf("\ndistance : %.1f", sqrt(best_dist));
    printf("\n\n");


    free(result_root.next);
    return 0;
}
