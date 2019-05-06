#include <cstddef> /* NULL */
#include <metis.h>
#include <iostream>
#include <ctime> 


int main(){
	
    clock_t t;
    int f;

    idx_t nVertices = 6;
    idx_t nEdges    = 7;
    idx_t nWeights  = 1;
    idx_t nParts    = 2;

    idx_t objval;
    idx_t part[nVertices];


    idx_t xadj[nVertices+1] = {0,2,5,7,9,12,14};

    idx_t adjncy[2 * nEdges] = {1,3,0,4,2,1,5,0,4,3,1,5,4,2};

    idx_t vwgt[nVertices * nWeights];
    

    // int ret = METIS_PartGraphRecursive(&nVertices,& nWeights, xadj, adjncy,
    // 				       NULL, NULL, NULL, &nParts, NULL,
    // 				       NULL, NULL, &objval, part);

    int ret = METIS_PartGraphKway(&nVertices,& nWeights, xadj, adjncy,
				       NULL, NULL, NULL, &nParts, NULL,
				       NULL, NULL, &objval, part);
               
    t = clock() - t;
    printf ("Tomó %d clicks (%f segundos).\n",t,((float)t)/CLOCKS_PER_SEC);           

    std::cout << ret << std::endl;
    
    for(unsigned part_i = 0; part_i < nVertices; part_i++){
	std::cout << part_i << " " << part[part_i] << std::endl;
    }

    
    return 0;
}

