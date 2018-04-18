#include<stdio.h>

int main()
{

		int ref_string[10];
		int page_faults = 0;
		int m,n,s;
		int pages,frames;
		
    	printf("\nEnter Total Number of Pages:\t");
    	scanf("%d", &pages);     // no of pages input into pages
    	
    	printf("\nEnter values of Reference String:\n");
    	
    	for(m = 0; m < pages; m++)   //input reference string
      	{
            printf("Value No.%d:\t", m + 1);
        	scanf("%d", &ref_string[m]);
      	}
      	
      printf("\nEnter number of Frames that you want:\t");   //input frame size
      {
            scanf("%d", &frames);
      }
      
      int temp[frames];   // declare a frame array of previously input size
      
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      
      for(m = 0; m < pages; m++)   //fifo algorithm
      {
            s = 0;
            
            for(n = 0; n < frames; n++)
            {
                  if(ref_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;
                  }
            }     
            
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {
                  temp[m] = ref_string[m];
            }   
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = ref_string[m];
            }
            else
            	s--;
            	
            printf("\n");
            
            for(n = 0; n < frames; n++)
            {     
                  printf("%d\t", temp[n]);
            }
      } 
      
    	printf("\nTotal Page Faults:\t%d\n", page_faults);
		printf("\nTotal no of Page Hit:%d\t\n",pages-page_faults);
}
