/* HEADER FILES */
	#include<stdio.h>  //For printf, scanf
	#include<conio.h>  //For clrscr, getch, getche
	#include<string.h> //For toupper
/* END OF HEADER FILES */

/* FUNCTION PROTOYPES*/
	void CreateFile();
	void List();
	void AppendFile();
	void ModifyFile();
	void DeleteRecords();
	void Bill();
	void Number();
	void Name();
	void Search();
/* END OF FUNCTION PROTOTYPES */

/* STRUCTURE SECTION */
	struct medicine
	{ 
		char Batch_no[7];           
  	  	char Medicine_name[31];      
      	char DOM[11];          
      	char DOE[11];  
      	float Quantity;
      	float Price;
	}record;
/* END OF STRUCTURE SECTION */

/* FILE POINTER SECTION */
	FILE *cfile,*rfile,*tfile,*bfile,*b1file;
/* END OF FILE POINTER SECTION */

/* MAIN PROGRAM SECTION */
	void main()
	{
		char choice;
		do
		{
			system("cls");
			printf("\n\n\n\tMAIN MENU");
			printf("\n\n\t Create A File");
			printf("\n\n\t List of Medicines");
			printf("\n\n\t Search Medicines");
			printf("\n\n\t Append List of Medicines");
			printf("\n\n\t Modify List of Medicines");
			printf("\n\n\t Delete Medicines From the List");
//			printf("\n\n\t Generate A Bill");
			printf("\n\n\t EXIT");
			printf("\n\n\tSelect First Character for further menu :  ");
			choice=toupper(getche());
			switch(choice)
			{
				case 'C' : CreateFile(); 
						   break;
				case 'L' : List(); 
						   break;
				case 'S' : Search();
						   break;
				case 'A' : AppendFile(); 
						   break;
				case 'M' : ModifyFile(); 
						   break;
				case 'D' : DeleteRecords(); 
		 				   break;
//				case 'G' : Bill();
						   break;
				case 'E' : system("cls"); 
						   break;
				default  : {
						    	printf("Invalid choice.");
						    	printf("Hit any key to exit.");
					  	   }
			}
		} while(choice != 'E');
	}
/* END OF MAIN PROGRAM SECTION */

/* FUNCTION DECLARATION SECTION */
	/* Creation of File */
		void CreateFile()
		{
			system("cls");
			char choice1 = 'Y';
  			cfile = fopen("MEDICINE.DAT","w");
  			while(toupper(choice1) == 'Y')
  			{
			  fflush(stdin); 
     			printf("\nEnter Batch No.: ");
     			gets(record.Batch_no);
     			printf("\nEnter Medicine Name(Up to 30 characters) : ");
    			toupper( gets(record.Medicine_name)); 
     			printf("Enter Manufacturing Date : ");
    			scanf("%s",&record.DOM);
     			printf("Enter Expiry Date : ");
    			scanf("%s",&record.DOE);
      			printf("Enter Quantity : ");
    			scanf("%f",&record.Quantity);     
    			printf("Enter Price per strip : ");
    			scanf("%f",&record.Price);
     			fwrite(&record, sizeof(record), 1, cfile);
    			printf("Press Y/y to Continue, Any other key to Stop ");
    			choice1 = getche();
  			}
  			fclose(cfile);
		}
	/* End of file creation*/
	
	/* Reading File */
		void List()
		{
			system("cls");
			int count = 0;
			cfile = fopen("MEDICINE.DAT","r"); 
			rfile = fopen("MEDICINE1.DAT","w");
			printf("\n ---------------------------------------------------------------------------------------- ");
			printf("\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E    |  Quantity |   Price  |");
			printf("\n ---------------------------------------------------------------------------------------- ");
			fprintf(rfile,"\n ---------------------------------------------------------------------------------------- ");
  			fprintf(rfile,"\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E   |  Quantity |   Price  |");
  			fprintf(rfile,"\n ---------------------------------------------------------------------------------------- ");
  			fread(&record, sizeof(record), 1, cfile); 
  			while(!feof(cfile))
  			{ 
			  count++;
    		  printf("\n%-12s %-30s %-10s %-15s %-8.2f %-13.2f",record.Batch_no,record.Medicine_name,record.DOM,record.DOE,record.Quantity,record.Price);
    		  fprintf(rfile,"\n%-12s %-30s %-10s %-15s %-8.2f %-13.2f",record.Batch_no,record.Medicine_name,record.DOM,record.DOE,record.Quantity,record.Price);
    		  if (count == 45)
    		  { 
			  	printf("\n ---------------------------------------------------------------------------------------- ");
      			printf("\nForty five records displayed. Press any key to continue for remaining records "); 
				getch();
      			printf("\n ---------------------------------------------------------------------------------------- ");
      			printf("\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E    |  Quantity |   Price  |");
      			printf("\n ---------------------------------------------------------------------------------------- ");
      			count = 0;
    		  }
			  fread(&record, sizeof(record), 1, cfile);
  			}
  			printf("\n ---------------------------------------------------------------------------------------- ");
  			fprintf(rfile,"\n ---------------------------------------------------------------------------------------- ");
  			fclose(cfile); 
			fclose(rfile);
  			printf("\nDisplaying records is over. Press any key to continue "); 
			getch();
		}
	/* End of Reading File */
	
	/* Appending Records */
	void AppendFile()
	{
		system("cls");
		char choice2 = 'Y';
  		cfile = fopen("MEDICINE.DAT","a");
  		while(toupper(choice2) == 'Y')
  		{ fflush(stdin);
     		printf("\nEnter Batch No.: ");
     		scanf("%s",&record.Batch_no);
     		printf("Enter Medicine Name(Up to 30 characters) : ");
    		scanf("%s", record.Medicine_name);   
     		printf("Enter Manufacturing Date : ");
    		scanf("%s",&record.DOM);
     		printf("Enter Expiry Date : ");
    		scanf("%s",&record.DOE);
      		printf("Enter Quantity : ");
    		scanf("%f",&record.Quantity);     
    		printf("Enter Price per strip : ");
    		scanf("%.2f",&record.Price);
     		fwrite(&record, sizeof(record), 1, cfile);
    		printf("Press Y/y to Continue, Any other key to Stop ");
    		choice2 = getche();    
			
  		}
  		fclose(cfile);
	}
	/*End of Appending Records */
	
	/* Modifying Records */
	void ModifyFile()
	{ 
			system("cls");
			int flag, n; 
			char temp[7]; 
			char choice = 'Y';
  			while(toupper(choice) == 'Y')
  			{ 
			  	flag = 0; 
				cfile = fopen("MEDICINE.DAT","r");
				tfile = fopen("TEMP.DAT","w");
    			printf("To Modify a Record");
    			printf("\n------------------");
    			printf("\n\nPlease Enter the Batch No. : ");
   				scanf("%s",temp);
   				rewind(cfile);
    			fread(&record, sizeof(record), 1, cfile); 
    			while(!feof(cfile))//&& flag == 0)
    			{ 
					if(strcmp(record.Batch_no,temp)==0)
      				{ 
					  
					    fflush(stdin);
					  	printf("\nExisting Record Details\n");
					 	printf("\n ---------------------------------------------------------------------------------------- ");
      				  	printf("\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E    |  Quantity |   Price  |");
      			      	printf("\n ---------------------------------------------------------------------------------------- ");
	                  	printf("\n%-12s %-30s %-10s %-15s %-8.2f %-13.2f",record.Batch_no,record.Medicine_name,record.DOM,record.DOE,record.Quantity,record.Price);
					  	printf("\n ---------------------------------------------------------------------------------------- ");
						printf("\n\nEnter the modified details");
						printf("\n--------------------------\n");
	 					printf("\nEnter Medicine Name(Up to 30 characters) : ");
    				  	scanf("%s", &record.Medicine_name);    
     				  	printf("\nEnter Manufacturing Date : ");
    				  	scanf("%s",&record.DOM);
     				  	printf("\nEnter Expiry Date : ");
    		          	scanf("%s",&record.DOE);
	     		        printf("\nEnter Quantity : ");
    		          	scanf("%f",&record.Quantity);     
    		          	printf("\nEnter Price per strip : ");
    		          	scanf("%f",&record.Price);
					    fwrite(&record,sizeof(record),1,tfile);	
					    printf("\nRecord Modified");
      					flag =1;
      				}
      				else //if(strcmp(record.Batch_no,temp)!=0)
      				{
      					fwrite(&record,sizeof(record),1,tfile);	
      					
					}
					fread(&record, sizeof(record), 1, cfile); 
    			}
    			fclose(cfile);
    			fclose(tfile);
    			remove("MEDICINE.DAT");
    			rename("TEMP.DAT","MEDICINE.DAT");
				if (flag == 0)
    			{ 
					printf("\n\nThe given record does not exist in the file!!!\n"); }
    				printf("\nPress any key to Return to main Menu ");
    				choice = getche();
				}
		}

	/* Deleting Records */
		void DeleteRecords()
		{ 
			system("cls");
			int flag, n; 
			char temp[7]; 
			char choice = 'Y';
  			while(toupper(choice) == 'Y')
  			{ 
			  	flag = 0; 
				cfile = fopen("MEDICINE.DAT","r");
				tfile = fopen("TEMP.DAT","w");
    			printf("To delete a Record");
    			printf("\n------------------");
    			printf("\n\nPlease Enter the Batch No. : ");
   				scanf("%s",temp);
   				rewind(cfile);
    			fread(&record, sizeof(record), 1, cfile); 
    			while(!feof(cfile))//&& flag == 0)
    			{ 
					if(strcmp(record.Batch_no,temp)==0)
      				{ 
					  printf("\nExisting Record Details\n");
					  printf("\n ---------------------------------------------------------------------------------------- ");
      				  printf("\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E    |  Quantity |   Price  |");
      			      printf("\n ---------------------------------------------------------------------------------------- ");
	                  printf("\n%-12s %-30s %-10s %-15s %-8.2f %-13.2f",record.Batch_no,record.Medicine_name,record.DOM,record.DOE,record.Quantity,record.Price);
					  printf("\n ---------------------------------------------------------------------------------------- ");
					  printf("\nRecord Deleted");
      					 flag =1;
      				}
      				else 
      				{
      					fwrite(&record,sizeof(record),1,tfile);	
					}
      				fread(&record, sizeof(record), 1, cfile); 
    			}
    			fclose(cfile);
    			fclose(tfile);
    			remove("MEDICINE.DAT");
    			rename("TEMP.DAT","MEDICINE.DAT");
				if (flag == 0)
    			{ 
					printf("\n\nThe given record does not exist in the file!!!\n"); }
    				printf("\nPress any key to Return to main Menu ");
    				choice = getche();
				}
		}

	/* End of Deleting Records */
	/* search*/
	/* SEARCHING RECORDS */
		void Search()
		{
			char choice;
			do
			{
				system("cls");
				printf("\n\n\n\tSEARCH MENU");
				printf("\n\n\t MEDICINE NAME SEARCH");
				printf("\n\n\t BATCH NUMBER SEARCH");
				printf("\n\n\t RETURN TO MAIN MENU");
				printf("\n\n\tSelect First Character for further menu :  ");
				choice=toupper(getche());
				switch(choice)
				{
					case 'M' : Name(); 
							   break;
					case 'B' : Number(); 
							   break;
					case 'R' : system("cls"); 
							   break;
					default  : 	{
							  		printf("Invalid choice.");
							  		printf("Hit any key to exit.");
	
					  	   		}	
				}
			} while(choice != 'R');	
		}
	/* END OF SEARCHING RECORDS */
	
	/* SEARCH BY NAME */
		void Name()
		{
			char choice='Y',medicine_name[31];
			int test,i;
			cfile = fopen("MEDICINE.DAT","r");
					while(choice == 'Y')
					{ 
						
	  					printf("\nEnter name of medicine to search : \n");
	  					gets(medicine_name); 
	  					rewind(cfile);
	  					while (fread(&record,sizeof(record),1,cfile) == 1)
	  					{ 
	  						//system("cls");
						  	test = 0; 
	    					for (i = 0; i <= strlen(medicine_name) - 1; i++)
	    					{ 
								if (toupper(medicine_name[i]) != toupper(record.Medicine_name[i])) 
								{ 
									test = 1; 
									continue; 
								} 
							}
	    					if (test == 0)
	    					{ 	
								printf("\n ---------------------------------------------------------------------------------------- ");
  								printf("\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E   |  Quantity |   Price  |");
  								printf("\n ---------------------------------------------------------------------------------------- ");
  			  					printf("\n%-12s %-30s %-10s %-15s %-8.2f %-13.2f",record.Batch_no,record.Medicine_name,record.DOM,record.DOE,record.Quantity,record.Price);
  			  					printf("\n ---------------------------------------------------------------------------------------- ");
	     						break;
	    					}
	  					}
	  					if (test == 1) 
						{
						  	printf("\n\nMedicine not found");
	  						printf("\n\n\nSearch another Record(Y/N) ? ");
	  						fflush(stdin); 
							choice = toupper(getche());
						}
					}
						fclose(cfile);
		}
	/* END OF SEARCH BY NAME */
	
	/* SEARCH BY BATCH NUMBER */
		void Number()
		{
			char choice='Y',Batch_number[13];
			int test,i;
			cfile = fopen("MEDICINE.DAT","r");
					while(choice == 'Y')
					{ 
						
	  					printf("\nEnter Batch Number of medicine to search : \n");
	  					gets(Batch_number);
	  					rewind(cfile);
	  					while (fread(&record,sizeof(record),1,cfile) == 1)
	  					{ 
	  						//system("cls");
						  	test = 0; 
	    					for (i = 0; i <= strlen(Batch_number) - 1; i++)
	    					{ 
								if (toupper(Batch_number[i]) != toupper(record.Batch_no[i])) 
								{ 
									test = 1; 
									continue; 
								} 
							}
	    					if (test == 0)
	    					{ 	
								printf("\n ---------------------------------------------------------------------------------------- ");
  								printf("\n| Batch No. |       Medicine Name          |   D.O.M  |  D.O.E   |  Quantity |   Price  |");
  								printf("\n ---------------------------------------------------------------------------------------- ");
  			  					printf("\n%-12s %-30s %-10s %-15s %-8.2f %-13.2f",record.Batch_no,record.Medicine_name,record.DOM,record.DOE,record.Quantity,record.Price);
  			  					printf("\n ---------------------------------------------------------------------------------------- ");
	     						 break;
	    					}
	  					}
	  					if (test == 1) 
						{
						  		printf("\n\nMedicine not found");
	  							printf("\n\n\nSearch another Record(Y/N) ? ");
	  							fflush(stdin); 
							  	choice = toupper(getche());
						}
					}
					fclose(cfile);
		}
	/* END OF SEARCH BY BATCH NUMBER */
/*END OF SEARCH*/

/* END OF FUNCTION DECLARATION SECTION */
