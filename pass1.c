#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    FILE *f1,*f2,*output,*symtab;
    int lc,sa,len,op1;
    char m1[20],la[20],op[20],hex[20],op2[20];

    f1=fopen("input.txt","r");
    f2=fopen("optab.txt","r");
    output=fopen("output.txt","w");
    symtab=fopen("symtab.txt","w");

    fscanf(f1,"%s\t%s\t%d",la,m1,&op1);

    if(strcmp(m1,"START")==0)
    {
        sa=op1;
        lc=sa;
        fprintf(output,"\tPRGM1\t%s\t%d\n",m1,op1);
    }
    else
    {
        lc=0;
    }
    
    fscanf(f1,"%s\t%s\t%s",la,m1,op2);
    while(strcmp(m1,"END")!=0)
    {
        //fscanf(f1,"%s\t%s\t%s",la,m1,op2);
        fprintf(output,"%d\t",lc);
        //if( (strcmp(la,"**")==0) && (strcmp(m1,"END")!=0) )
         if(strcmp(la,"**")==0)
        {
        	int flag=0;
        	while(!feof(f2))
        	{	
                	fscanf(f2,"%s\t%s\n",op,hex);
                	if(strcmp(m1,op)==0)
                	{
                    		lc=lc+3;
                    		flag=1;
                    		break;
                	}
            	}
            	if(flag==0)
            	{
            		printf("Opcode not found !!  ERROR !!\n Exiting....");
            		exit(0);
            	}
        }
        
        //else if((strcmp(la,"**")!=0))
        else
        {
        	fprintf(symtab,"%s\t%d\n",la,lc);
        }
        
        if(strcmp(m1,"WORD")==0)
        {
            lc=lc+3;
        }
        else if(strcmp(m1,"RESW")==0)
        {
            lc=3*atoi(op2)+lc;
        }
        else if(strcmp(m1,"RESB")==0)
        {
            lc=lc+atoi(op2);
        }
        fprintf(output,"%s\t%s\t%s\n",la,m1,op2);
        fscanf(f1,"%s\t%s\t%s",la,m1,op2);
    }
    fprintf(output,"%d\t%s\t%s\t%d\n",lc,la,m1,sa);
}
