//Tori Overholtzer

#include <iostream>
#include <stdio.h>
using namespace std;

//This program gets up to 10 scores from a students, calculates the average and final grade
//Security: NO INPUT SANITIZATION, TYPE CHECKING AT ALL


int main()
{
  //------DO NOT CHANGE THESE------
  int scores[10];
  char name[100] = "abc";
  char id[12] = "";
  int number_of_score = 0;
  double average = 0;
  int sum = 0;
  char grade = 'X';
  char comments[5] = "NONE";
  
  //------------------------------

  cout << "\n---------------------------------------\n";
  cout << "Welcome to the scoring system!" <<endl;
  cout << "Enter student's name: " ;  //BUFFER OVERFLOW 
//  scanf("%s", name);
  fgets(name, sizeof(name), stdin);
  //for(int i =0; i < (sizeof(name)); i++){
	//cout<<"array, name[]"<< name[i]<< "\n";
  //}
  
  //cout << "\nPlease enter student ID: ";
  //scanf("%s", id);
  //fgets(id, sizeof(id), stdin);
//  cout<<"\n";
//  for(int y=0; y<(sizeof(id)); y++){
//	cout<<"array,id[]"<<id[y]<<"\n";
// }
  int x2 = 0;
  char c2;
  bool bad_flag = 0; // Flag for bad input
  do {
    bad_flag = 0;
    x2 = 0;
    id[0] = '\n';
    cout << "\nPlease enter student ID: ";
    
    // Get input
    do {
      c2 = getchar();
      id[x2] = c2;
      // Test and break if needed. set bad flag
      if (isdigit(c2)){
        if(x2==3){
          id[3]='-';
          x2++;
          id[4]=c2;
        }else{
          id[x2]=c2;
        }
      }else if (x2==3 && c2=='-')
      {
        id[x2]=c2;
      }else if (c2=='\n'){
        id[x2]=c2;
        break;
      }else{
        bad_flag = 1;
        cout << "Incorrect Character" << endl;
        break;
      }
      x2++;
    } while (x2 < 10 && c2 != '\n'); 
    id[x2] = '\n';
    if(x2!=9){
      cout << "Incorrect id length" << endl;
      bad_flag=1;
    }

    if (bad_flag) {
      cout << "Bad input. Try again" << endl;
    }

  } while (bad_flag != 0);
  
  // We should have a proper id string here
  for(int z = 0; z< (sizeof(id)); z++){
    cout<<"ID[]"<<id[z]<<"\n";
  }


  //NO INPUT SANITAZATION, TYPE CHECKING
  cout << "Enter up to 10 student's scores (0-100) (if done, enter -1 to stop): ";  //DIVIDE BY ZERO PROBLEM
  cout << endl;
  for (int i = 0; i< 10; i++)
    { cout << "Score " << i+1 << ": ";
      int temp;
      cin >> temp;
   
      //  cout << "  temp is " << temp << endl;
      if (temp != -1)
    {
      scores[i] = temp;
      number_of_score++;
      sum = sum + temp;
    }
      else{
    break;
      }
    }
  average = sum / number_of_score;
  cout << "Student's name is: " << name << endl;
  cout << "Student has " << number_of_score << " scores, sum is " << sum <<", and the average score is " << average << endl;

  // figure out the final grade, A, B, C, D, or F
  if( average >= 90)
    grade = 'A';
  if(average < 90 and average >= 80)
    grade = 'B';
  if (average < 80 and average >= 70)
    grade = 'C';
  if (average < 70 and average >= 60)
    grade = 'D';
  if (average < 60 and average >= 0)
    grade = 'F';
  
  cout << "Based on the average score, final grade is: " << grade << endl;

  cout << "looks good? (Yes or No)";
  cin.ignore();
  //cin >> comments;  //BUFFER OVERFLOW, POSSIBLY OVERWRITE THE GRADE VARIABLE TO CHANGE THE FINAL GRADE OF A STUDENT
  int c = 0;
  int x = 0;
  do{
	c=getchar();
	comments[x]=c;
	x++;
  }while(c!='\n' && x < sizeof(comments)-1);
  comments[x] = NULL;

  for(int z = 0; z< (sizeof(comments)); z++){
  	cout<<"array,comments[]"<<comments[z]<<"\n";
}

  cout << "Comments - Looks good? - " << comments << endl << endl;
  cout << "Student name: " << name << endl;
  cout << "Student ID: " << id <<endl;
  cout << "Final grade is: " << grade << endl <<endl;

  cout << "Program exits successfully..." <<endl;

}

