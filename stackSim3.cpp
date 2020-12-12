//Ryan Moran
//stackSim3.cpp
//ID: 902521253
//line 251 and others like it were influenced by the following website: /geeksforgeeks.org/program-extract-wrods-given-string/
//the file reader in the beginning of main() was influenced by a particular web page but i cannot 
//locate it. i think it may have been on tutorialspoint.com or cplusplus.com
//discovered stoi on https://careerkarma.com/blog/c-plus-plus-string-to-int/ for line 383 and others like it.
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <sstream>
using namespace std;
vector<string> text_segment;
vector<string> data_segment;
vector<string> stack;
string last_modified;
void actual_stack(int opcode, string *destination);

void stack_op(int opcode, string *destination, string *parameter1, string *parameter2);
string full_line;  
string  *$a0, *$a1, *$a2, *$a3, *$v0, *$v1, *$t0, *$t1,  *$t2,  *$t3,  *$t4,  *$t5, *$t6, *$t7, *$t8, *$t9;   
int push = 00000001, pop = 00000010, mult = 00000011, sub = 00000100, add = 00000101, divide = 00000110;
typedef unsigned int uint32;
typedef int int32;
typedef uint32 mem_addr;
void token_r(vector<string> text_segment);
void interpreter(string result);
void code_segment_interpreter(string result);	
void fetch_code_decode(string operation, string destination, string parameter1);
vector<string>::iterator thing;
string string1 = "ascii", string2 = "asciiz";
string placeholderArray[5];
int something = 0;

int main(){
	
	//cout << "mult is: "<< mult << " \n";
	ifstream file_for_loader("stackCode.txt");
	if ((bool)file_for_loader != 0){
		while (getline(file_for_loader, full_line)){
			//cout <<full_line;
     			//cout << "\n";
			text_segment.push_back(full_line);
    		}
    			file_for_loader.close();
    	}
	else cout << "file read error\n";
	
	int blah = 0;
	cout << "\n";
	//the below code calls the store function for the code/text segment and data segment
	token_r(text_segment);
	return 0;
 } 



size_t for_new_line;
string new_line = "\n";
int text_index = 0;
void token_r(vector<string> text_segment){
	
	/*
	The entire outer loop of this function is meant to go through one 
	line at a time and disperse all of the information it needs to to 
	different segments of memory. Assign variable names with adresses 
	of the data that they are "assigned" to in the program scan first 
	for a # sign and if that is present proceed to the next string in 
	the vector. If the # sign is not present is not present in the string
	acquired by searching within the string, then we will store that 
	string in a variable vector with the same index as the value it is
	 intended to hold. 	
	*/

	string temporaryStorage;		
	unsigned leading_space;
	unsigned following_space;
	string result;
	string previous_result;
	size_t comment;
	int t = 0;
	//char i;
	//char characterArrayForIndexing[];

	//the below for loop is meant to acquire the index where the text segment starts
 
	for(int i = 0; i < text_segment.size(); i++){
		temporaryStorage = text_segment.at(i);
        //cout << temporaryStorage << " \n";
				if(temporaryStorage == "" || temporaryStorage.at(0) == '#')
					continue;
				if(temporaryStorage.find('#')){
					//cout << "found a comment \n";
					comment = temporaryStorage.find('#');
					result = temporaryStorage.substr(0, comment);
					if(result != "#"){
						//interpreter(result);
						stringstream iss(result);
						while(iss >> result){
							if(result == ".text"){
//								cout << ".text was located at the: " << i << " index \n";
								text_index = i;
							}	
						}
					}
				}
				else
					if(temporaryStorage != "#"){
						interpreter(temporaryStorage);
                        cout << "blahblahblah";
                    }
	}
	
	//the below for loop is meant to store the data segment
	//its meant to stop running once the dta segment has been fully initiliazed.
	//the data segment will store parameters as follows: first word in string is the variable name, the second is the size that is allocated to it, 
	//and third is the actual value whos address will be stored in relation to the variable name. 
	//make a seperate function where it takes parameters to store into memory. ZZ	
	
	for(int i = 0; i < text_index; i++){
	temporaryStorage = text_segment.at(i);
				if(temporaryStorage == "" || temporaryStorage.at(0) == '#')
					continue;
				if(temporaryStorage.find('#')){
					//cout << "found a comment \n";
					comment = temporaryStorage.find('#');
					result = temporaryStorage.substr(0, comment);
					
					if(result != "#" && result != ".data"){
								//if the previous member of the data segment is "ascii" or "asciiz" then copy the rest of the string into result before 
								//sending it.
						//if(data_segment_index)
                        //cout << result << " \n";
						interpreter(result);					
						//	stringstream iss(result);
				//		while(iss >> result){
				//			//this portion inside of the while loop is meant to store the parameters in memory
				//			
				//			}
            
            		}
				}
				else
					if(temporaryStorage != "#" & temporaryStorage != ".data")
						interpreter(temporaryStorage);
                
                
	}

    for(int i = 0; i < data_segment. size(); i++){

       // cout << data_segment.at(i) << "\n";
    }

	//the below for loop of for reading the text segment and sending instructions as parameters to the stack emulator. 

	for(int i = text_index + 1; i < text_segment.size(); i++){
	temporaryStorage = text_segment.at(i);
				//the below if statement is for checking whether or not the string is empty or is just a full comment.
				if(temporaryStorage == "" || temporaryStorage.at(0) == '#')
					continue;
				//the below if statement is for finding a comment in a string and then keeping the string up the the point where the comment starts. 
				if(temporaryStorage.find('#')){
					//cout << "found a comment \n";
					comment = temporaryStorage.find('#');
					result = temporaryStorage.substr(0, comment);
					
					if(result != "#"){
						//if the previous member of the data segment is "ascii" or "asciiz" then copy the rest of the string into result before 
						//sending it.
						//if(data_segment_index)
						if(result != "main:"){
							code_segment_interpreter(result);
                            //for(int i = 0; i < data_segment.size(); i++)
                            //    cout << data_segment.at(i) << " in the data segment in rts\n\n";					
                        }
					}
				}
				else
					if(temporaryStorage != "#")
						code_segment_interpreter(temporaryStorage);
	}
}
	

string phrase;
string secondphrase;
string thirdphrase; 
char quotation = '"';
int beginning, ending;
void interpreter(string result){
	//cout << "this initial string has made it to the interepreter: " << result << "\n";
	int blah = 0;
	int nah = 0;
	//the below if statement is for handling thestring if there are any. 
	//it looks for the ascii variable name and stores the rest of the string as one vector element in the data segment.
	if(result.find(string1) < 1000 || result.find(string2) < 1000){
		stringstream iss(result);
		while(blah < 1){//old while condition is blah < 2
			 //we have to segment the datae inside of here now. its going to push the whold string so we have to pick apart the string manually. 
			 //maybe use delimiters?
			 // we have result right here inside of the function. 
			//first delimiter can be "" and the second delimiter can be "	" and the third delimiter can be " "
			beginning = result.find(" ");
           // cout << "the first element to get stored into the data segment for the string is: " << result.substr(0,beginning) << "\n";
            data_segment.push_back(result.substr(0,beginning));
			data_segment.push_back("asciiz");                  
			beginning = result.find("\"");
			phrase = result.substr(0,beginning);
            //cout << "first phrase in the interpreter is: " << phrase << "\n";
			ending = result.find("\"");
			secondphrase = result.substr(beginning + 1, ending - 4);

            //cout << "second phrase in the interpreter is: " << secondphrase << "\n";   
            ending = secondphrase.find("\"");
            thirdphrase = secondphrase.substr(0,ending);
            //cout << "third phrase in the interpreter is: " << thirdphrase << "\n";   
			//secondphrase.append("hello ");
			//find in the string where it says asciiz and send thridphrase to the slot after it. 
            data_segment.push_back(thirdphrase);
			

			blah++;
		}
		phrase = result.substr(result.find(string1) + 8, result.size() - 1);
		//cout << "phrase is: " << phrase << "\n";	
        //cout << "phrase is: " << phrase << "\n";
		//data_segment.push_back(phrase);
		//for(int i = 0; i , data_segment.size(); i++){
        //   cout << data_segment.at(i) << " is the new structure of the data segment\n\n"; 
        //}
	
	}
//		cout << "ascii or asciiz was found \n";

//	if(result contains ascii)
//		store the data elements in such a way that the data_segment for ascii or asciiz content is not interrupted.
	else{
		stringstream iss(result);//geeksforgeeks.org/program-extract-wrods-given-string/
		while(iss >> result){//sends every word but how do i ignore comments????
			if(result != ".data")
				 data_segment.push_back(result);
		}	
	}
    
}


string operation, destination, parameter1, parameter2, parameter3;
	//fetch_code_decode needs a program counter. 
unsigned int pc;
void code_segment_interpreter(string result){
	if(result == "10000111 00010 1010")
		cout << "Answer = " << last_modified << "\n";
    //cout << result << "\n";
	placeholderArray[0] = "";
	placeholderArray[1] = "";
	placeholderArray[2] = "";
	int i = 0;

	stringstream iss(result);
	while(iss >> result){
        if(result != "main:")
		    placeholderArray[i] = result;
		i++;
	}	
	operation = placeholderArray[0];
	destination = placeholderArray[1];
	parameter1 = placeholderArray[2];

	if(operation != "" && destination != "" && parameter1 != "")

 		    fetch_code_decode(operation, destination, parameter1);
    else if(operation != "" && destination != "")
    	    fetch_code_decode(operation, destination, parameter1);

    else if(operation != "")
    	    fetch_code_decode(operation, destination, parameter1);


}
string *data_segment_address;
string destination_for_stack;
//below is the register bank
//string  *$a0, *$a1, *$a2, *$a3, *$v0, *$v1, *$t0, *$t1,  *$t2,  *$t3,  *$t4,  *$t5, *$t6, *$t7, *$t8, *$t9;   
int count = 0;
void fetch_code_decode(string operation, string register_or_parameter, string parameter2){
    
    
	something++;
	//cout << "destination in the fetch_code_decode function is: " << destination << "\n";
	//cout << "fetch_code_decode has run: " << something << "\n";
	int push = 00000001;
	int pop = 00000010;
	string temp;
    string temp2;
	char adder = ':';
	int stak_op_opcode;
	string *stack_op_destination, *stack_op_parameter1, *stack_op_parameter2;
	//cout << " op:" << operation << "register or parameter:" << register_or_parameter << "p2:" << parameter2 << "\n";;
	if(operation == "10000111" && register_or_parameter == "00010" && parameter2 == "1010")
		cout << "Answer = " << last_modified << "\n";
    //each of the operations below will have an opcode associated with them before sending them to the stack. 
	//stack only takes an opcode and a memory address. 
	//look through it member by member until you get to the one that matches the variable name then increase the count by two to get the value in the 
	//string vector. then you get the memory address of that variable and go from there. 
	
	/*this section is where we put the opcodes to work. here is the list of opcodes
    #PUSH = 10000001
    #POP = 10000010
    #ADD = 10000011
    #MUL = 10000101
    #LI = 10000111
    #MOVE = 10010000
    #SYSCALL = 10001001
    */
    
    if(operation == "10000001"){
        
        //this is a push statement 
        //push whatever is two items ahead in the data segment onto the stack. 
        for(int i = 0; i < data_segment.size(); i++){
            if(data_segment.at(i) == register_or_parameter){
                destination_for_stack = data_segment.at(i + 2);
            }
        }
		//cout << "stack push back is: " << destination_for_stack << "\n\n";
        stack.push_back(destination_for_stack);//this is pushing the numeric value associated with that 
    }
	                                    //memory address onto the stack. 
	if(operation == "10000010"){
        //this is a pop statment
        //look for wherever the address is in the data segment and move 2 spots forward
        temp = stack.back(); 
		//cout << "temp is: " << temp << "\n";
        stack.pop_back();//what if it needs to     
        for(int i = 0; i < data_segment.size(); i++){
			//cout << "register or parameter is: " << register_or_parameter << "\n";
            if(data_segment.at(i) == register_or_parameter){
                //cout << "data segment that is causing all the trouble is: " << data_segment.at(i) << "\n\n";
                //cout << "that index is: " << i << "\n\n";
				//cout << "data segment at i + 2 = " << data_segment.at(i + 2) << "\n\n";
				data_segment.at(i + 2) = temp;
				//cout << "data segment at i + 2 = " << data_segment.at(i + 2) << "\n";
				//cout << "data segment at i + 2 after assignment = " << data_segment.at(i + 2) << "\n\n";
				last_modified = data_segment.at(i + 2);
				//cout << "parameter 2 is: " << parameter2 << "\n";
				if(parameter2 == "1010")
					cout << "Answer = " << last_modified << "\n";
            }
        }
	}
    if(operation == "10000011"){//this is an add operation (rewrite)
        temp = stack.back();
        stack.pop_back();
        temp2 = stack.back();
        stack.pop_back();
        int operand1 = stoi(temp);//careerkarma.com
        int operand2 = stoi(temp2);
        int addresult = operand1 + operand2;
        string add_result_string = to_string(addresult);
        stack.push_back(add_result_string);
    }

    if(operation == "10000101"){//this is an mult operation (rewrite)
        temp = stack.back();
		//cout << "temp1 in mult is: " << temp << "\n\n";
        stack.pop_back();
        temp2 = stack.back();
		//cout << "temp2 in mult is: " << temp2 << "\n\n";		
	    stack.pop_back();
        int operand1 = stoi(temp);//careerkarma.com
        int operand2 = stoi(temp2);
        int multresult = operand1 * operand2;
		//cout << "mult result is: " << multresult << "\n";
        string mult_result_string = to_string(multresult);
        stack.push_back(mult_result_string);
    }

	
}
 
//the code below is meant to send things to the stack. 

void stack_op(int opcode, string *destination,  string *parameter1, string *parameter2){
		//$t4 = &data_segment.push_back(0);
	
    
    //cout << "parameters in the stack_op function are: op:  " << opcode << " dest: " << destination << " p1: " 
	//<< parameter1 << " p2: " << parameter2 << "\n"; //" p3: " << parameter3 << "\n";
	//cout << "the value at parameter 1's address is: " << *parameter1 << "\n";
	
    
    
    //cout <<"opcode for add is: " << add << "\n";
	//cout <<"opcode for sub is: " << sub << "\n";
	//cout <<"opcode for mult is: " << mult << "\n";


	
	if(opcode == 65){
		//its add
		//which stack operation is it?
	}

}
string *mem_addr_from_stack1, *mem_addr_from_stack2; 
void actual_stack(int opcode, string *destination){
	for(int i = 0; i < data_segment.size(); i++){
			//cout << data_segment.at(i) << " is in the data segment \n";
	}
	if(opcode ==9){
		cout << "what is actually in destination: " << destination << " and " << &destination;
		cout  << " and " << *destination << "\n";
		int multinput1 = 0;
		int multinput2 = 0;
		int multresult = 0;
		string resultingstring;
		//mem_addr_from_stack1 = stack.front();
		stack.pop_back();
		//mem_addr_from_stack2 = stack.front();
		stack.pop_back();
		stringstream blahblah;
		stringstream blahblahblah;
		blahblah << *mem_addr_from_stack1;
		blahblah >> multinput1;
		blahblahblah <<	*mem_addr_from_stack2;
		blahblahblah >> multinput2;

		cout << "the parameters in actual_stack for mult are: " << *mem_addr_from_stack1 << " and " << *mem_addr_from_stack2 << "\n"; 
		//cout << "the parameters are: " << &mem_addr_from_stack1 << " and " << &mem_addr_from_stack2 << "\n";
		
		multresult = multinput1 * multinput2;
	

		resultingstring = to_string(multresult);
		destination = &resultingstring;
		cout << "destination is: " << destination << "  in actual_stack mult and the value is: " << resultingstring << "\n";
		cout << "$t4 is holding: " << $t4 << "\n";
		//cout << &resultingstring;
		//stack.push_back(&resultingstring);
	}
	

}


	


