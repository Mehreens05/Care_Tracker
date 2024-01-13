#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
#ifdef _WIN32
#include <windows.h>//for the delay function 
#endif
#define MAX_NUM 5//defined maximum number of exercises.
#define NAME_LEN 18//defined the maximum length of exercise name.
#define TASK_CAPACITY_LIMIT 50
#define MAXIMUM_TASKS 100
#define RED_COLOR "\x1b[31m"//for Red color text in output
#define GREEN_COLOR "\x1b[32m"//for Green color text in output
#define BLUE_COLOR "\x1b[34m"//for blue colored text in output
#define RESET "\x1b[0m"//to reset the color


struct Task{
    char dsc[TASK_CAPACITY_LIMIT];
    int finished;
};

#define TASK_CAPACITY_LIMIT 50
#define TASK_CEILING 100
#define FILE_NAME "todo_list.txt"



struct Task tasks[TASK_CEILING];
int Count = 0;

// Function for adding tasks to the to-do list
void Taskadding() {
    if (Count < TASK_CEILING) {
        printf("Enter the task you'd like to do: ");
        char in[TASK_CAPACITY_LIMIT];
        fgets(in, TASK_CAPACITY_LIMIT, stdin);
        in[strcspn(in, "\n")] = '\0'; // Will place a terminating null character where it encounters a new line.

        strcpy(tasks[Count].dsc, in);
        tasks[Count].finished = 0; // Set the task as not finished

        FILE *fptr = fopen(FILE_NAME, "a");
        if (fptr != NULL) {
            fprintf(fptr, "%s %d\n", tasks[Count].dsc, tasks[Count].finished);
            fclose(fptr);
        } else {
            printf("Error saving task to file.\n");
        }

        Count++; // Incrementing the task count
        printf("The task is added successfully!\n");
    } else {
        printf("To-do list is full. You can't add more tasks.\n");
    }
}

// Function for viewing tasks in the to-do list
void seetasks() {
    if (Count == 0) {
        printf("There is nothing here :( Try to add tasks first.\n");
    } else {
        printf("To-Do List:\n");
        for (int i = 0; i < Count; i++) {
            printf("%d. %s - %s\n", i + 1, tasks[i].finished ? "[DONE]" : "[TODO]", tasks[i].dsc);
        }
    }
}

// Function for marking tasks as finished in the to-do list
void ticktasks() {
    int nooftasks;
    printf("Enter task number to be marked as finished: ");
    scanf("%d", &nooftasks);
    if (nooftasks > 0 && nooftasks <= Count) {
        tasks[nooftasks - 1].finished = 1;
        printf("You did it! The task is marked as completed.\n");
    } else {
        printf("Invalid task number!\n");
    }
}

// Function to load tasks from file at the beginning
void tasksfromfile() {
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr!= NULL) {
        while (fscanf(fptr, "%s %d", tasks[Count].dsc, &tasks[Count].finished) == 2) {
            Count++;
            if (Count >= TASK_CEILING) {
                break;
            }
        }
        fclose(fptr);
    }
}

// Function to save tasks to file when exiting the program
void saveToFile() {
    FILE *fptr = fopen(FILE_NAME, "w");
    if (fptr != NULL) {
        for (int i = 0; i < Count; i++) {
            fprintf(fptr, "%s %d\n", tasks[i].dsc, tasks[i].finished);
        }
        fclose(fptr);
    } else {
        printf("Error saving tasks to file.\n");
    }
}


void exer_progress(char ex[][NAME_LEN], int exer_completion[]){//Receiving two arrays as arguments. First one ahving the name sof exercise and second one is an array initialized to 0.
    printf("\nExercise Progress\n");
    for( int i = 0 ; i < 5 ; i++){
        
        printf("%d. %s    ",i+1,ex[i]);
        //if value at index i in exer_ completion  is zero then Pending is printed.
        //If one then Done is printed.
        if(exer_completion[i]==0){
            printf("%s\n","[Pending]");
        }
        else if(exer_completion[i]==1){
            printf("%s\n","[Done]");
        }
    }
}

int main(){
    int options;
    jump1:
    printf(RED_COLOR"\n\n           |   Welcome to your personalized Self-Care Tracker   |\n"RESET);
    Sleep(300);
    printf("          \nLet's prioritize your well-being and embark on the journey of self-discovery.");
    Sleep(300);
    printf("\nLet this space be a guide on your path to a healthier, better and happier you.\nReady to kickstart your day?\n");
    Sleep(300);
    printf(GREEN_COLOR"\nEnter (1/2/3/4/5/6)\n_____\n1. Quote of the Day.\n___\n2. To-Do List(Plan your day)\n___-\n3. Hydration Tracker.\n____\n4. Exercise Planner.\n____\n5. Day Checker\n.___\n6. Exit.\n_____\n"RESET);
    scanf("\n%d",&options);
    //Checks whether the input  is valid or not.
     if(options!=1 && options != 2 && options!=3 && options!=4 && options!=5 && options!=6){
        printf("\n| Invalid Input. |\n");
        goto jump1;//back to the menu.
    }
    //Incase of exit.
    if(options==6){
        printf("_____\nOKAY BYE BYEE!\nSEE YOU LATER!\nHAVE A GOOD DAY!");//Prints a message.
        exit(0);
    }
    //Incase of option#1
    if(options==1){
        
        printf(GREEN_COLOR"\n_________\n"RESET);
          srand(time(NULL));
          Sleep(300);
    const char *quotes[] = {
        "| The only limit to our realization of tomorrow \nwill be our doubts of today. - F. D. Roosevelt |",
        "| In the end, we will remember not the words of our enemies,\n but the silence of our friends. - M. L. King, Jr. |",
        "| Life is what happens when you're \nbusy making other plans. - John Lennon |",
        "| The only way to do great work is \nto love what you do. - Steve Jobs |",
        "| The future belongs to those who believe\n in the beauty of their dreams. - E. Roosevelt|",
       "| Surah Al-Baqarah (2:286): Allah does not \nburden a soul beyond that it can bear...|",

        "| Surah Ash-Sharh (94:5-6): For indeed, with hardship\n [will be] ease. Indeed, with hardship [will be] ease.|",

        "| Surah Al-Ankabut (29:69):And those who strive for Us - We will surely\n guide them to Our ways. And indeed, Allah is with the doers of good.|",

        "| Surah Al-Imran (3:139): So do not weaken and do not grieve, \nand you will be superior if you are [true] believers.|",

        "| Surah Al-Baqarah (2:286):\nAllah is with those who are patient.|",

        "| Surah At-Tawbah (9:51):\nSay, 'Never will we be struck except by what Allah has\n decreed for us; He is our protector.' And upon Allah let the believers rely.|",

        "| Surah An-Najm (53:39-40):And that there is not for man except that [good] for which he strives, And that his effort is going to be seen.|"
    };

    int noOfQ = sizeof(quotes) / sizeof(quotes[0]);
    int Index = rand() % noOfQ;

    printf("Remember:\n %s\n", quotes[Index]);
    printf(GREEN_COLOR"\n___________\n"RESET);
    goto jump1;
    

    }
    //Incase of option#2
    if(options==2){
       int choice;

    tasksfromfile(); // Load tasks from file at the beginning
    
    printf("\nWelcome to your To-Do List Menu!\nWhat would you like to do?\n");
    do {
        printf("\nPlease select the following:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the input buffer

        switch (choice) {
            case 1:
                Taskadding();
                break;
            case 2:
                seetasks();
                break;
            case 3:
                ticktasks();
                break;
            case 4:
                saveToFile();
                printf("See you another time. Goodbye!\n");
                goto jump1;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    }

    //INcase options#3
    if(options==3){
        start_again://control will come back here on invalid input
    #ifdef _WIN32
    //glasses will appear for the sake o looks T-T
    printf(BLUE_COLOR"|       |        |       |       |       |\n");
    Sleep(300);
    printf("\\       /        \\       /       \\......./\n");
    Sleep(300);
    printf(" |     |          |.....|         |.....|\n");
    Sleep(300);
    printf(" |     |          |.....|         |.....|\n");
    Sleep(300);
    printf(" |_____|          |_____|         |_____|  \n"RESET);
    #endif
    //starting of tracker:
    printf("________");
    printf(GREEN_COLOR"\n|   Welcome to your caring hydration tracker!!   |\n"RESET);
    printf("\nPlease set your daily Water/Hydration goal (In Glasses): ");
    //float values to be able to add decimal goals according to recommendations
    float goal, total_glasses = 0;
    scanf("%f", &goal);
   //invalid if goal input is less than 0 or greater than 50
    if (goal <= 0||goal>50) {
        printf("Please enter a valid number of glasses.\n");
        goto start_again;
    }

    printf("Your daily hydration goal is set to %.2f glasses.\n", goal);
    
    //menu:
    while (1) {
        printf(RED_COLOR"\nMenu:\n"RESET);
        printf(GREEN_COLOR"1. Update your daily hydration goal.\n");
        printf("2. Add the Glasses consumed.\n");
        printf("3. View current hydration.\n");
        printf("4. Recommend a hydration goal.\n");
        printf("5. Exit\n"RESET);
        
        int user_choice;
       //ask for user's choice:
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        //if user chooses option 1:
        if (user_choice == 1) {
            printf("Set your new hydration goal: ");
            scanf("%f", &goal);
            printf(BLUE_COLOR"Your new hydration goal is %.2f\n"RESET, goal);
        //if user chooses option 2:    
        } else if (user_choice == 2) {
            printf("Enter the number of glasses consumed: ");
            float glasses;
            scanf("%f", &glasses);
        //condition for if user enters invalid no of glasses:
            if (glasses < 0||glasses >50) {
                printf(RED_COLOR"\nPlease enter a valid number of glasses.\n\n"RESET);
                continue;
            }
            //update the no of glasses consumed:
            total_glasses += glasses;
            printf("%.2f glasses have been added. Total Number of Glasses consumed: %.2f\n", glasses, total_glasses);
            //for user input : 3, It will display the current level
        } else if (user_choice == 3) {
            printf("Your current water consumption in Glasses is: %.2f\n", total_glasses);
            //when user inputs 4, will recommend glasses no
        } else if (user_choice == 4) {
            printf("Please enter your weight in pounds: ");
            float weight;
            scanf("%f", &weight);

            float recommendation = (weight * (2.0 / 3.0)) / 8.0;
            printf("According to your weight, we recommend consuming %.2f glasses per day (where a glass is approximately 8 ounces).\n", recommendation);
        } else if (user_choice == 5) {
            goto jump1;
            //will tell user that its invald if the option is something not 1 to 5:
        } else {
            printf(RED_COLOR"Invalid choice. Please enter a valid option.\n"RESET);
            continue;
        }

    }

    }

    //INcase option#4
    if(options==4){

     int task;//a variable to store the  number of task.
    char timer;
    int mark;
    char exer[MAX_NUM][NAME_LEN];//A 2-D character array 
    int exer_completion[5] = {0}; //A 1-D array with all elements initialized to 0. when it's Done,the element at that index will be incremented to 1.
    jump:
    printf("\n\n");
    printf(RED_COLOR"\t\t|'''Welcome to Exercise Planner!'''|"RESET);//Welcoming text.
    printf("\n_______");
    //Taking user input.
    printf(GREEN_COLOR"\nWhat do you want to do? Type(1/2/3/4)\n1.Create your own Exercise Planner.\n2.Display Suggested planner.\n3.Display Exercise Progress\n4.Exit."RESET);
    printf("\n_______");
    scanf("%d",&task);
    if(task==4){
        goto jump1;
    }
    //Incase option #1
    if (task==1){
        jmps:
            //Prompting the user to add 5 exercises.
                printf("\n\nWhich exercise do you want to add?(Add 5 exercises )\n");
        for (int i = 0; i < 5; i++) {//keeps taking input until it reaches maximum exercise number i.e 5
            printf("Exercise %d: ", i + 1);
            scanf(" %s", exer[i]);
        }
        printf("Exercises added:\n");
        for (int i = 0; i < 5; i++) {//prints the input exercises by iterating through the array.
            printf("%d. %s\n", i + 1, exer[i]);//with the exercise number, also adding 1 to i to increment the number of exercise by 1 from the index number.
        }
    goto jump;  
  }

    if(task==2){
        int level;
        printf(BLUE_COLOR"| Which level do you wanna start with? |\n(From: 1-5)\n"RESET);//asks for the level of exercise.
        scanf("%d",&level);
        //Suggests an exercise planner on the basis of level.
        if(level>=1 && level<=5){//Checks if input is greater than or equal to 1 and less than or equal to 5.
        printf("""Here is your exercise plan.\n1.%d Pushups \n2.%d Squarts \n3.%d minutes Plank\n4.%d Jumping Jacks.\n5.%d Pull ups.""",level*10,level*5,level,level*15,level*7);
        goto jump;//goes back to menu.
        }
        else{
            printf(RED_COLOR"\nInvalid input."RESET);
            goto jump;//back to menu.
        }
    }
    if (task==3){
        int qtn;
        
        jum:
        printf("Have you added the exercises?\n(Enter 1 for yes and 0 for No.)");//asks if you have added exercises in the planner.
        scanf("%d",&qtn);
       
        if(qtn==1){//if yes, it displays the progress
            jumping:
        printf("Here is your Exercise Progress.");
        //PAssing the exer array which is a 2-d character array having names of 5 exercises.
        //Also the exer_completion array which is an array initialilzed to zero.
     exer_progress(exer, exer_completion);//function call.
        

        //Stores the number of exercise that needs to be marked done.
        int exerciseNumber;
        printf("\nEnter the exercise number you completed (1 to 5, 0 to exit): ");
        scanf("%d", &exerciseNumber);


        if (exerciseNumber == 0) {
            goto jump;//menu of exercise planner.
        }

        if (exerciseNumber < 1 || exerciseNumber > MAX_NUM) {//Checks if it is a valid input or not.
            printf(RED_COLOR"\n| Invalid exercise number. Please enter a number between 1 and 5.\n |"RESET);
            goto jumping;//back to progress planner.
        } else {
            //it assigns 1 to the of exercise number.
            exer_completion[exerciseNumber - 1] = 1;//mark that specific exercise as DOne.

            // Display the updated exercise plan
         exer_progress(exer, exer_completion);
            goto jump;//BAck to menu.
            
        }}
        else{
            printf("Firstly add Exercises.");
            goto jmps;//Creating an exercise planner
            goto jumping;//displaying exercise progress.
            goto jump;//back to menu.
        }
    }

   
}
    
    
        
    
    if(options==5){
   s_tart:
   printf("_______\n");
   printf(BLUE_COLOR"| How was your day on a scale of 1 to 10? |\n"RESET);//ask user about their day
   int scale;
   scanf("%d",&scale);//take user input
   if(scale>=0&&scale<=10)//enter loop for values 0-10
    {
        if(scale==0){
            printf(GREEN_COLOR"| It couldn't have been this bad. \n But if it was, Have trust that it was for the best.\n Learn from it well.\n Better days are not far away. |"RESET);
        }
        if(scale==1)
        {
            printf(GREEN_COLOR"| Every journey begins with a single step.\n Today might be tough, but you're stronger than you think.\n Keep going. |"RESET);
            
        }
        if(scale==2)
        {
            printf(GREEN_COLOR"| Challenges are what make life interesting.\n  Overcoming them is what makes life meaningful.\n  You've got this! |"RESET);
        }
        if(scale==3)
        {
            printf(GREEN_COLOR"| Progress is progress, no matter how small.\n  Tomorrow is a new day and a new chance for improvement.\n  Stay positive! |"RESET);
            
        }
        if(scale==4)
        {
            printf(GREEN_COLOR"| Remember, you're one step closer than you were yesterday.\n Keep pushing forward with determination. |"RESET);
        }
        if(scale==5)
        {
            printf(GREEN_COLOR"| Embrace the journey, celebrate the progress.\n You're on the right track. Keep moving forward! |"RESET);
        }
        if(scale==6)
        {
            printf(GREEN_COLOR"| Your efforts are paying off. \n Keep up the momentum and believe in the power of your resilience. |"RESET);
        }
        if(scale==7)
        {
            printf(GREEN_COLOR"| A positive attitude can turn a difficult day into a victorious one.\n  Keep shining bright! |"RESET);
        }
        if(scale==8)
        {
            printf(GREEN_COLOR"| You're doing amazing things.\n Keep up the great work and\n watch how your efforts transform your life. |"RESET);
            
        }
        if(scale==9)
        {
            printf(GREEN_COLOR"| Almost there! Your dedication is unmatched. Continue to strive for excellence. You're unstoppable! |"RESET);
        }
        if(scale==10)
        {
            printf(GREEN_COLOR"| Yay ! I'm so Proud of you.\n  Stay Happy , Always.|"RESET);
            
        }
        
    }
    //prints an error message if an invalid input is entered:
    else{
        printf(RED_COLOR"Please enter a valid number from 1 to 10.\n"RESET);
        goto s_tart;//takes us back to the question
    }
    printf("\n____");
    //2nd question about users day:
    start2:
    printf(BLUE_COLOR"\n\nIs there something you did today to be proud of?\ny/n\n"RESET);
    
    char op_tion;
    scanf(" %c",&op_tion);//take input
    //enter if user enters y/Y:
      if(op_tion=='y'||op_tion=='Y'){
        printf(GREEN_COLOR"Thats Great! Keep doing great things"RESET);
      }
      //enter if user enters n/N:
       else if(op_tion=='n'||op_tion=='N')
      {
          printf(GREEN_COLOR"Its ok if all you did today was hold yourself together.\n That too is an Achievement."RESET);
      }
      //if user inputs invalid option:
      else{
          printf(RED_COLOR"Invalid input. Please input Y/y/N/n\n"RESET);
          goto start2;
      }
      printf("\n____");
      //3rd question:
      printf(BLUE_COLOR"\nDid you achieve your daily goals of Todo-list?\n(y/n)"RESET);
     char op_tion2;
    scanf(" %c",&op_tion2);//take input:
    //if user enters y/Y:
      if(op_tion2=='y'||op_tion2=='Y'){
        printf(GREEN_COLOR"\nThats Great! Keep doing great things\n______\n"RESET);
        goto jump1;
      }
      //if user enters n/N:
       else if(op_tion2=='n'||op_tion2=='N')
      {
          printf(GREEN_COLOR"\nIts ok if all you did today was hold yourself together.\n That too is an Achievement.\n_____\n"RESET);
          goto jump1;
      }
      //displays invalid message for invalid input.
      else{
          printf(RED_COLOR"Invalid input. Please input Y/y/N/n\n"RESET);
          goto start2;//takes command back to the question
          goto jump1;
      }
    }
    return 0;
}