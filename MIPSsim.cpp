#include <list>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <fcntl.h>

using namespace std;

enum instruction_type {ADD, SUB, MUL, ST};
enum reg {R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15};


struct INM_token			//Instruction tokens that will be stored in INM
{
	instruction_type opcode;
	reg dest;
	reg op1;
	reg op2;
	int immediate;
};

struct INB_token			//Tokens that will be stored in INB, AIB, SIB, PRB
{
	instruction_type opcode;
	reg dest;
	int op1_value;
	int op2_value;
};

struct RGF_token			//Tokens that will be stored in RGF, REB, ADB
{
	reg r;
	int value;
};

struct DAM_token			//Tokens that will be stored in DAM
{
	int address;
	int value;
};


// Contents of places will be stored as lists
list<INM_token> INM;
list<INB_token> INB, AIB, SIB, PRB;
list<RGF_token> RGF, REB, ADB;
list<DAM_token> DAM;

//Mapping the enum opcode types to values that represent them in string form
string EnumInstructionToString(instruction_type opcode)
{
    switch(opcode) {
        case ADD:
           return "ADD";
        case SUB:
           return "SUB";
        case MUL:
           return "MUL";
        case ST:
           return "ST";
        
    }
}

//Mapping the enum register types to values that represent them in string form
string EnumRegToString(reg r)
{  
    switch ( r )
       {
         case R0:
            return "R0";
         case R1:
            return "R1";
         case R2:
            return "R2";
         case R3:
            return "R3";
         case R4:
            return "R4";
         case R5:
            return "R5";
         case R6:
            return "R6";
         case R7:
            return "R7";
         case R8:
            return "R8";
         case R9:
            return "R9";
         case R10:
            return "R10";
         case R11:
            return "R11";
         case R12:
            return "R12";
         case R13:
            return "R13";
         case R14:
            return "R14";
         case R15:
            return "R15";   
            
        
		}
}


// Parsing the "instructions.txt" file to extract instructions and store in INM
void StoreInstructionsInINM(list<INM_token> &INM)
{
	/*code here*/
	char line[20];
	INM_token parsed_inst;
	list<string> inst_list;
	FILE *fp = fopen("instructions.txt","r");
	if (!fp){
		perror("Opening of file has failed.");
		exit(1);
	}
	while(fscanf(fp, "%s",line)!= EOF){	
		inst_list.push_back(line);
	}
	fclose(fp);

	
	list<string>::iterator list_iter;
	char temp[20]="";


	string list_entry;
	list_iter=inst_list.begin();

	while(list_iter != inst_list.end())

	{
		
		/*Parsing happens here*/
		list_entry = *list_iter;		// Refers to an entry in the list of instructions


		int NumofCommasYet=0;
		int i,j;
		j=0;
		



		for(i=1;i<list_entry.length()-1;i++)
		{
			
			
			if(list_entry[i]==',')
			{
				
				if(NumofCommasYet==0)
				{
					/*OpCode extraction*/
					//cout<<"Comma DEtected!!!!!!"<<endl;
					

					temp[j]='\0';
					
					if(!strcmp(temp,"ADD"))
					{
			        parsed_inst.opcode=ADD;
			   		} 
			   		else if(!strcmp(temp,"SUB"))
			   		{
			        parsed_inst.opcode=SUB;
			    	}
			    	else if(!strcmp(temp,"MUL"))
			    	{
			        parsed_inst.opcode=MUL;
			    	}
			    	else if(!strcmp(temp,"ST"))
			    	{
			        parsed_inst.opcode=ST;
			    	}
			    	
					NumofCommasYet++;
					j=0;
					continue;
					}

				else if(NumofCommasYet==1)
				{
					/*Destination extraction*/
					temp[j]='\0';
					if(!strcmp(temp,"R0"))   
					{
			        parsed_inst.dest= R0;
			    	} 
			    	else if(!strcmp(temp,"R1"))   
			    	{
			        parsed_inst.dest=R1;
			    	} 
			   		else if(!strcmp(temp,"R2"))   
			   		{
			        parsed_inst.dest= R2;
			   		} 
			    	else if(!strcmp(temp,"R3"))   
			    	{
			        parsed_inst.dest=R3;
			    	} 
			    	else if(!strcmp(temp,"R4"))   
			    	{
			        parsed_inst.dest=R4;
			    	} 
			    	else if(!strcmp(temp,"R5"))   
			    	{
			        parsed_inst.dest= R5;
			    	} 
			    	else if(!strcmp(temp,"R6"))   
			    	{
			        parsed_inst.dest= R6;
			    	}
			     	else if(!strcmp(temp,"R7"))   
			     	{
			        parsed_inst.dest= R7;
			    	}
			     	else if(!strcmp(temp,"R8"))   
			     	{
			        parsed_inst.dest= R8;
			    	}
			     	else if(!strcmp(temp,"R9"))   
			     	{
			        parsed_inst.dest= R9;
			    	}
			     	else if(!strcmp(temp,"R10"))   
			     	{
			        parsed_inst.dest= R10;
			    	}
			     	else if(!strcmp(temp,"R11"))   
			     	{
			        parsed_inst.dest= R11;
			    	} 
			    	else if(!strcmp(temp,"R12"))   
			    	{
			        parsed_inst.dest= R12;
			    	} 
			    	else if(!strcmp(temp,"R13"))   
			    	{
			        parsed_inst.dest= R13;
			    	}
			    	else if(!strcmp(temp,"R14"))   
			    	{
			        parsed_inst.dest= R14;
			    	}
			     	else if(!strcmp(temp,"R15"))   
			     	{
			        parsed_inst.dest= R15;
			    	}



					NumofCommasYet++;
					j=0;
					continue;
				}

				else if(NumofCommasYet==2)
				{
					temp[j]='\0';
					/*Operand 1 extraction*/

					if(!strcmp(temp,"R0"))  
					{
			        parsed_inst.op1= R0;
			    	} 
			    	else if(!strcmp(temp,"R1"))   
			    	{
			        parsed_inst.op1=R1;
			    	} 
			   		else if(!strcmp(temp,"R2"))   
			   		{
			        parsed_inst.op1= R2;
			   		} 
			    	else if(!strcmp(temp,"R3"))   
			    	{
			        parsed_inst.op1=R3;
			    	} 
			    	else if(!strcmp(temp,"R4"))   
			    	{
			        parsed_inst.op1=R4;
			    	} 
			    	else if(!strcmp(temp,"R5"))   
			    	{
			        parsed_inst.op1= R5;
			    	} 
			    	else if(!strcmp(temp,"R6"))   
			    	{
			        parsed_inst.op1= R6;
			    	}
			     	else if(!strcmp(temp,"R7"))   
			     	{
			        parsed_inst.op1= R7;
			    	}
			     	else if(!strcmp(temp,"R8"))   
			     	{
			        parsed_inst.op1= R8;
			    	}
			     	else if(!strcmp(temp,"R9"))   
			     	{
			        parsed_inst.op1= R9;
			    	}
			     	else if(!strcmp(temp,"R10"))   
			     	{
			        parsed_inst.op1= R10;
			    	}
			     	else if(!strcmp(temp,"R11"))   
			     	{
			        parsed_inst.op1= R11;
			    	} 
			    	else if(!strcmp(temp,"R12"))   
			    	{
			        parsed_inst.op1= R12;
			    	} 
			    	else if(!strcmp(temp,"R13"))   
			    	{
			        parsed_inst.op1= R13;
			    	}
			    	else if(!strcmp(temp,"R14"))   
			    	{
			        parsed_inst.op1= R14;
			    	}
			     	else if(!strcmp(temp,"R15"))   
			     	{
			        parsed_inst.op1= R15;
			    	}
					NumofCommasYet++;
					j=0;
					continue;
				}


			}

			temp[j]=list_entry[i];
			j++;


		}



		temp[j]='\0';
		/*Operand 2 exraction*/
		/*For ST instruction*/
		if(parsed_inst.opcode==ST){
			istringstream(temp) >> parsed_inst.immediate;
		}
		else{
					if(!strcmp(temp,"R0"))   
					{
			        parsed_inst.op2= R0;
			    	} 
			    	else if(!strcmp(temp,"R1"))   
			    	{
			        parsed_inst.op2=R1;
			    	} 
			   		else if(!strcmp(temp,"R2"))   
			   		{
			        parsed_inst.op2= R2;
			   		} 
			    	else if(!strcmp(temp,"R3"))   
			    	{
			        parsed_inst.op2=R3;
			    	} 
			    	else if(!strcmp(temp,"R4"))   
			    	{
			        parsed_inst.op2=R4;
			    	} 
			    	else if(!strcmp(temp,"R5"))   
			    	{
			        parsed_inst.op2= R5;
			    	} 
			    	else if(!strcmp(temp,"R6"))   
			    	{
			        parsed_inst.op2= R6;
			    	}
			     	else if(!strcmp(temp,"R7"))   
			     	{
			        parsed_inst.op2= R7;
			    	}
			     	else if(!strcmp(temp,"R8"))   
			     	{
			        parsed_inst.op2= R8;
			    	}
			     	else if(!strcmp(temp,"R9"))   
			     	{
			        parsed_inst.op2= R9;
			    	}
			     	else if(!strcmp(temp,"R10"))   
			     	{
			        parsed_inst.op2= R10;
			    	}
			     	else if(!strcmp(temp,"R11"))  
			     	{
			        parsed_inst.op2= R11;
			    	} 
			    	else if(!strcmp(temp,"R12"))   
			    	{
			        parsed_inst.op2= R12;
			    	} 
			    	else if(!strcmp(temp,"R13"))   
			    	{
			        parsed_inst.op2= R13;
			    	}
			    	else if(!strcmp(temp,"R14"))   
			    	{
			        parsed_inst.op2= R14;
			    	}
			     	else if(!strcmp(temp,"R15"))   
			     	{
			        parsed_inst.op2= R15;
			    	}
			}



		INM.push_back(parsed_inst);
		list_entry[0]='\0';


		list_iter++;
	}
}

//Parsing the "registers.txt" file to extract registers and values and store in RGF
void StoreRegistersInRGF(list<RGF_token> &RGF)
{
	/*Parsing code here*/
	char line[20];
	RGF_token parsed_registerfile;
	list<string> reg_list;
	int i,j;
	FILE *fp = fopen("registers.txt","r");
	if (!fp){
		perror("Opening of file has failed.");
		exit(1);
	}
	while(fscanf(fp, "%s",line)!= EOF){	
		reg_list.push_back(line);
	}
	fclose(fp);
	/*Scanning register file done*/

	list<string>::iterator list_iter;
	char temp[20]="";

	string list_entry;
	list_iter=reg_list.begin();

	while(list_iter != reg_list.end())
	{
		/*Line by line parsing*/
		list_entry= *list_iter;
        //temp[0] = '\0';
        j = 0;
        for (i=1;i < list_entry.length()-1;i++)
        {
            if (list_entry[i] == ',')
            {
                temp[j] = '\0';
                //extraction of register
 				if(!strcmp(temp,"R0"))   
 				{
			        parsed_registerfile.r= R0;
			    	} 
			    	else if(!strcmp(temp,"R1"))   
			    	{
			        parsed_registerfile.r=R1;
			    	} 
			   		else if(!strcmp(temp,"R2"))   
			   		{
			        parsed_registerfile.r= R2;
			   		} 
			    	else if(!strcmp(temp,"R3"))   
			    	{
			        parsed_registerfile.r=R3;
			    	} 
			    	else if(!strcmp(temp,"R4"))   
			    	{
			        parsed_registerfile.r=R4;
			    	} 
			    	else if(!strcmp(temp,"R5"))   
			    	{
			        parsed_registerfile.r= R5;
			    	} 
			    	else if(!strcmp(temp,"R6"))   
			    	{
			        parsed_registerfile.r= R6;
			    	}
			     	else if(!strcmp(temp,"R7"))   
			     	{
			        parsed_registerfile.r= R7;
			    	}
			     	else if(!strcmp(temp,"R8"))   
			     	{
			        parsed_registerfile.r= R8;
			    	}
			     	else if(!strcmp(temp,"R9"))   
			     	{
			        parsed_registerfile.r= R9;
			    	}
			     	else if(!strcmp(temp,"R10"))   
			     	{
			        parsed_registerfile.r= R10;
			    	}
			     	else if(!strcmp(temp,"R11"))   
			     	{
			        parsed_registerfile.r= R11;
			    	} 
			    	else if(!strcmp(temp,"R12"))   
			    	{
			        parsed_registerfile.r= R12;
			    	} 
			    	else if(!strcmp(temp,"R13"))   
			    	{
			        parsed_registerfile.r= R13;
			    	}
			    	else if(!strcmp(temp,"R14"))   
			    	{
			        parsed_registerfile.r= R14;
			    	}
			     	else if(!strcmp(temp,"R15"))   
			     	{
			        parsed_registerfile.r= R15;
			    	}



 				//extraction complete               
                j = 0;
                temp[j] = '\0';
                continue;
            }
            temp[j] = list_entry[i];
            j++;

        }
        temp[j] = '\0';
        
        istringstream(temp) >> parsed_registerfile.value;

        RGF.push_back(parsed_registerfile);
        list_iter++;
	}
}

//Parsing the "datamemory.txt" file to fill up contents of DAM
void StoreDataMemoryInDAM(list<DAM_token> &DAM)
{
	//Opening and scanning datamemory.txt
	char line[20];
	DAM_token parsed_datamemory;
	list<string> datamemory_list;
	int i,j;
	FILE *fp = fopen("datamemory.txt","r");
	if (!fp){
		perror("Opening of file has failed.");
		exit(1);
	}
	while(fscanf(fp, "%s",line)!= EOF){	
		datamemory_list.push_back(line);
	}
	fclose(fp);
	//Datamemory.txt scanned


	list<string>::iterator list_iter;
	char temp[20]="";

	string list_entry;
	list_iter=datamemory_list.begin();

	while(list_iter != datamemory_list.end())
	{
		/*Line by line parsing*/
		list_entry= *list_iter;
        //temp[0] = '\0';
        j = 0;
        for (i=1;i < list_entry.length()-1;i++)
        {
        	 if (list_entry[i]==',')
        	    {

                temp[j] = '\0';
                istringstream(temp)>>parsed_datamemory.address;
                j = 0;
                temp[j] = '\0';
                continue;
            }
            temp[j]=list_entry[i];
            j++;

        }
        temp[j] = '\0';
        istringstream(temp)>>parsed_datamemory.value;

        DAM.push_back(parsed_datamemory);
        list_iter++;	
	}
}

//Printing the contents of INM
void PrintINM(list<INM_token> INM, FILE* fpsim)
{
	list<INM_token>::iterator list_iter;
    list_iter=INM.begin();
    int entry=0;
    while(list_iter!=INM.end())
    {
        if (EnumInstructionToString(list_iter->opcode)=="ST")
        {
            //cout<<"<"<< EnumInstructionToString(list_iter->opcode)<<","<<EnumRegToString(list_iter->dest)<<","<<EnumRegToString(list_iter->op1)<<","<< list_iter->immediate<<">";
            fprintf(fpsim,"<%s,%s,%s,%d>",EnumInstructionToString(list_iter->opcode).c_str(),EnumRegToString(list_iter->dest).c_str(),EnumRegToString(list_iter->op1).c_str(),list_iter->immediate);
        } 
        else  
        {
           // cout<<"<"<< EnumInstructionToString(list_iter->opcode)<<","<< EnumRegToString(list_iter->dest)<<","<< EnumRegToString(list_iter->op1)<<","<< EnumRegToString(list_iter->op2)<<">";
            fprintf(fpsim,"<%s,%s,%s,%s>",EnumInstructionToString(list_iter->opcode).c_str(),EnumRegToString(list_iter->dest).c_str(),EnumRegToString(list_iter->op1).c_str(),EnumRegToString(list_iter->op2).c_str());

        }
        if (entry< INM.size()-1)
        {
           //cout<<",";
           fprintf(fpsim, ",");
        }

        entry++;

        list_iter++;
    }
}

//Printing the contents of RGF or ADB
void PrintRGForADB(list<RGF_token> RGF, FILE* fpsim)
{
	/*printing code here*/
	list<RGF_token>::iterator list_iter;
	list_iter=RGF.begin();
	int entry=0;
	while(list_iter!=RGF.end())
	{
		//cout<<"<"<<EnumRegToString(list_iter->r)<<","<<list_iter->value<<">";
		fprintf(fpsim, "<%s,%d>",EnumRegToString(list_iter->r).c_str(), list_iter->value);

		if (entry<RGF.size()-1)
		{
           // cout<<",";
            fprintf(fpsim, ",");
        }
        entry++;
        list_iter++;
	}
}

//Printing the contents of DAM
void PrintDAM(list<DAM_token> DAM, FILE* fpsim)
{
	/*printing code here*/
	list<DAM_token>::iterator list_iter;
	list_iter=DAM.begin();
	int entry=0;
	while(list_iter!=DAM.end())
	{
		//cout<<"<"<<list_iter->address<<","<<list_iter->value<<">";
		fprintf(fpsim, "<%d,%d>",list_iter->address,list_iter->value);
		if (entry<DAM.size()-1)
		{
            //cout<<",";
            fprintf(fpsim, ",");
        }
        entry++;
        list_iter++;
	}
}
//Printing the contents of INB or AIB or SIB or PRB
void PrintINBorAIBorSIBorPRB(list<INB_token> INB, FILE* fpsim)
{
	/*printing code here*/
	list<INB_token>::iterator list_iter;
	list_iter=INB.begin();
	int entry=0;
	while(list_iter!=INB.end())
	{
		//cout<<"<"<<EnumInstructionToString(list_iter->opcode)<<","<<EnumRegToString(list_iter->dest)<<","<<list_iter->op1_value<<","<<list_iter->op2_value<<">";
		fprintf(fpsim,"<%s,%s,%d,%d>",EnumInstructionToString(list_iter->opcode).c_str(),EnumRegToString(list_iter->dest).c_str(),list_iter->op1_value,list_iter->op2_value);
		if (entry<INB.size()-1)
		{
           // cout<<",";
            fprintf(fpsim, ",");
        }
        entry++;
        list_iter++;
	}
}


void PrintSteps(int step, FILE* fpsim)
{
    if(step!=0)
    {
    fprintf(fpsim, "\n");
	}

    fprintf(fpsim,"STEP %d:\n", step);
    //cout << "INM:";
    fprintf(fpsim,"INM:");

    PrintINM(INM,fpsim);
    //cout << endl;
    fprintf(fpsim, "\n");
    //cout << "INB:";
    fprintf(fpsim,"INB:");
    PrintINBorAIBorSIBorPRB(INB,fpsim);    
    //cout << endl;
    fprintf(fpsim, "\n"); 
   // cout<< "AIB:";
    fprintf(fpsim,"AIB:");
    PrintINBorAIBorSIBorPRB(AIB,fpsim); 
   // cout << endl;
    fprintf(fpsim, "\n");
    //cout << "SIB:";
    fprintf(fpsim,"SIB:");
    PrintINBorAIBorSIBorPRB(SIB,fpsim); 
    //cout << endl;
    fprintf(fpsim, "\n");
    //cout<< "PRB:";
    fprintf(fpsim,"PRB:");
    PrintINBorAIBorSIBorPRB(PRB,fpsim);  
    //cout << endl;
    fprintf(fpsim, "\n");
    //cout << "ADB:";
    fprintf(fpsim,"ADB:");
    PrintRGForADB(ADB,fpsim);    
    //cout << endl;
    fprintf(fpsim, "\n");
    //cout << "REB:";
    fprintf(fpsim,"REB:");
    PrintRGForADB(REB,fpsim);   
    //cout << endl;
    fprintf(fpsim, "\n");
    //cout << "RGF:";
    fprintf(fpsim,"RGF:");
    PrintRGForADB(RGF,fpsim);    
    //cout << endl;
    fprintf(fpsim, "\n");
    //cout << "DAM:";
    fprintf(fpsim,"DAM:");
    PrintDAM(DAM,fpsim);
    //cout << endl;
    fprintf(fpsim, "\n");
}


void DecodeTransition(list<INM_token> &INM,list<RGF_token> &RGF, list<INB_token> &INB)
{

	list<INM_token>::iterator Iterator_INM;
    list<RGF_token>::iterator Iterator_RGF;
    INB_token Instruction_to_INB;

    

    Iterator_INM = INM.begin();
    Iterator_RGF = RGF.begin();
    int flag1, flag2;
    flag1=0;
    flag2=0;


    if(Iterator_INM->opcode == ST)
    {	
    	Instruction_to_INB.opcode= Iterator_INM->opcode; //ST stored in INB at place for opcode
    	Instruction_to_INB.dest= Iterator_INM->dest;    // Destination register stored in place at INB
    	Instruction_to_INB.op2_value= Iterator_INM->immediate;  //Immediate value stored in place at INB
    	/*for ST */
    	while(Iterator_RGF!= RGF.end())
    	{
    		if(Iterator_INM->op1==Iterator_RGF->r)
    		{
    			Instruction_to_INB.op1_value=Iterator_RGF->value;
    			INB.push_back(Instruction_to_INB);
    			INM.pop_front();
    			//cout<<"HERERERERE"<<endl;
    			break;

    			
    		}

    		Iterator_RGF++;
    	}
    }

    else 
    {
    	/*for all other instructions*/
    	Instruction_to_INB.opcode= Iterator_INM->opcode; //Opcode stored in INB at place for opcode
    	Instruction_to_INB.dest= Iterator_INM->dest;

    	while(Iterator_RGF!= RGF.end())
    	{
    		if(Iterator_INM->op1==Iterator_RGF->r)
    		{
    			Instruction_to_INB.op1_value=Iterator_RGF->value;
    			flag1=1;
    		}
    		if(Iterator_INM->op2==Iterator_RGF->r)
    		{
    			Instruction_to_INB.op2_value=Iterator_RGF->value;
    			flag2=1;
    		}
    		if(flag1==1 && flag2==1)
    		{
    			INB.push_back(Instruction_to_INB);
    			INM.pop_front();
    			break;
    		}

    		Iterator_RGF++;
    	}

    }

}

bool dm_sort(const DAM_token &i, const DAM_token &j) //sorting of lists of custom type in cpp
{
    return i.address < j.address;
}

bool rgf_sort(const RGF_token &i, const RGF_token &j)
{
	return i.r < j.r;
}



int main(){

	int decodeflag=0;

	int IssueConsumeFlag=0;

	int IssueProduceASUFlag=0;
	int IssueProduceMLU1Flag=0;

	int IssueProduceADDRFlag=0;

	int ASUConsumeFlag=0;
	int ASUProduceWRITEFlag=0;

	int MLU1ConsumeFlag=0;
	int MLU1ProduceMLU2Flag=0;

	int ADDRConsumeFlag=0;
	int ADDRProduceSTOREFlag=0;

	int MLU2ConsumeFlag=0;
	int MLU2ProduceWRITEFlag=0;

	int WRITEConsumeFlag=0;
	

	int STOREConsumeFlag=0;

	RGF_token adbstruct;
	DAM_token dm;
	RGF_token mlt;
	RGF_token arith;

	list<DAM_token>::iterator Iterator_DAM;
    list<RGF_token>::iterator RGFlist_iter;



	FILE* fpsim; 
	fpsim=fopen("simulation.txt","w+");
    

	
	StoreInstructionsInINM(INM);	
	
	StoreRegistersInRGF(RGF);
	
	StoreDataMemoryInDAM(DAM);

	int s=0;
	PrintSteps(0, fpsim);
	
	//PrintSteps(0);

	while(!(   INM.empty() &&  INB.empty() &&  PRB.empty() && ADB.empty() && AIB.empty() && SIB.empty() && REB.empty()  ) )
	{
	
	
		if(!(INM.empty()))
		{
			DecodeTransition(INM,RGF,INB);
			decodeflag = 1;
		}
		//cout<<"1"<<endl;


		if(IssueConsumeFlag==1)
		{
			IssueConsumeFlag=0;  //Down the flag
			//cout<<"1.1"<<endl;
			
            if(INB.front().opcode == ST)
            {
            	SIB.push_back(INB.front());
            	IssueProduceADDRFlag=1;
            	
            }
            else
            {
            	AIB.push_back(INB.front());
            	if(INB.front().opcode == ADD || INB.front().opcode == SUB)
            	{
            		IssueProduceASUFlag=1;	
            	}
            	else
            	{
            		IssueProduceMLU1Flag=1;
            	}

            	//break;
            }

            INB.pop_front();
		}
		//cout<<"2"<<endl;

		if(ADDRConsumeFlag==1)
		{
			ADDRConsumeFlag=0;
            adbstruct.r = SIB.front().dest;
            adbstruct.value = SIB.front().op1_value + SIB.front().op2_value;            
            ADB.push_back(adbstruct);
            SIB.pop_front();
            ADDRProduceSTOREFlag=1;
		}

		//cout<<"3"<<endl;

		if(STOREConsumeFlag==1)
		{	
			STOREConsumeFlag=0;
			int dr;

			list<RGF_token>::iterator list_iter;
    	    list_iter = RGF.begin();
    		while(list_iter!=RGF.end())    
    		{
            	if (list_iter->r == ADB.front().r) 
            	{
            		dr = list_iter->value;
            		
        		}
        		list_iter++;
    		}

			
			int ISRegAlreadyInDAM =0;
                Iterator_DAM = DAM.begin();
                while(Iterator_DAM != DAM.end())
                    {
                    	if (Iterator_DAM->address == ADB.front().value)
                    	{
                        	ISRegAlreadyInDAM=1;
                        	break;
                    	}

                    	Iterator_DAM++;
                	}

                if (ISRegAlreadyInDAM==1)    
                {
                    Iterator_DAM->value = dr;
                } 

                else

                {
                    dm.address = ADB.front().value;
                    dm.value = dr;
                    DAM.push_back(dm);
                    DAM.sort(dm_sort);
                }

                ADB.pop_front();

		}

		//cout<<"4"<<endl;


		if(MLU1ConsumeFlag==1)
		{
			MLU1ConsumeFlag=0;
			//cout<<"4.22"<<endl;
            PRB.push_back(AIB.front());
            AIB.pop_front();
            MLU1ProduceMLU2Flag=1;
		}

		//cout<<"4.3"<<endl;

		if(MLU2ConsumeFlag==1)
		{
			MLU2ConsumeFlag=0;
            mlt.r = PRB.front().dest;
            mlt.value = PRB.front().op1_value * PRB.front().op2_value;
            REB.push_back(mlt);
            PRB.pop_front();
            MLU2ProduceWRITEFlag = true;
		}
		//cout<<"5"<<endl;


		if(ASUConsumeFlag==1)
		{
			ASUConsumeFlag=0;
            arith.r = AIB.front().dest;

            

            if(AIB.front().opcode == ADD)
            {
            	arith.value=AIB.front().op1_value + AIB.front().op2_value;
            	
            }
            else
            {
            	arith.value=AIB.front().op1_value - AIB.front().op2_value;
            }

            REB.push_back(arith);

            AIB.pop_front();

            ASUProduceWRITEFlag=1;
		}

		//cout<<"6"<<endl;

		if(WRITEConsumeFlag>=1)
		{
			WRITEConsumeFlag--;

            int IsRegAlreadyInRGF=0;

            RGFlist_iter = RGF.begin();
            while(RGFlist_iter != RGF.end())    
            {
                if (RGFlist_iter->r == REB.front().r) 
                {
                    IsRegAlreadyInRGF=1;
                    break;
                }

                RGFlist_iter++;
            }

            if (IsRegAlreadyInRGF==1)    
            {
                RGFlist_iter->value = REB.front().value;
            }
            else  
            {
                RGF.push_back(REB.front());
                RGF.sort(rgf_sort);
            }

            REB.pop_front();
		}

		//cout<<"7"<<endl;

		if(decodeflag==1)
		{
			decodeflag=0;
			IssueConsumeFlag=1;
		}
		//cout<<"8"<<endl;

		if(IssueProduceASUFlag==1)
		{
			IssueProduceASUFlag=0;
			ASUConsumeFlag=1;
		}
		//cout<<"9"<<endl;

		
		//cout<<"10"<<endl;

		

		//cout<<"11"<<endl;

		if(IssueProduceMLU1Flag==1)
		{
			IssueProduceMLU1Flag=0;
			MLU1ConsumeFlag=1;
		}

		if(ADDRProduceSTOREFlag==1)
		{
			ADDRProduceSTOREFlag=0;
			STOREConsumeFlag=1;
		}

		if(IssueProduceADDRFlag==1)
		{
			IssueProduceADDRFlag=0;
			ADDRConsumeFlag=1;

		}

		//cout<<"12"<<endl;

		if(MLU1ProduceMLU2Flag==1)
		{
			MLU1ProduceMLU2Flag=0;
			MLU2ConsumeFlag=1;

		}

		if(ASUProduceWRITEFlag==1)
		{
			ASUProduceWRITEFlag=0;
			WRITEConsumeFlag++;
		}


		if(MLU2ProduceWRITEFlag==1)
		{
			MLU2ProduceWRITEFlag=0;
			WRITEConsumeFlag++;
		}

		
		s++;
		PrintSteps(s, fpsim);


	
	}	

	






	
	return 0;
}






