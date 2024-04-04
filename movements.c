#include "cube.h"

/**
 * Creates a string of the exact size of the instructions entered by the user
 * 
 * @param **str the char pointer to the resulting string
*/
void readIns(char **str)
{
  // pointers to struct
  Character *set;
  Character *new;
  Character *temp;

  // counter
  int i = 0;

  // starts the list
  set = NULL;

  // until it finds a \n in stdin
  do
  {
    // creates a new structrure with the char it gets
    new = (Character *) malloc(sizeof(Character));
    new->cur = getchar();
    new->next = NULL;

    // adds the structure to the list
    if(set != NULL)
    {
      temp = set;

      while(temp->next != NULL)
      {
        temp = temp->next;
      }

      temp->next = new;
    }
    else
    {
      set = new;
    }

    // adds to the counter to know the strlen
    i++;
  } while(new->cur != '\n');

  // creates a char[] of the exact size of the inputed chars, including the \n
  *str = (char *) malloc(i * sizeof(char));
  i = 0;

  // Frees the list while adding every char to the string
  while(set != NULL)
  {
    temp = set;
    set = temp->next;

    (*str)[i] = temp->cur;

    free(temp);

    i++;
  }

  // changes the \n to a \0 char
  (*str)[i - 1] = 0;

  return;
}

/**
 * returns a number according to the instruction given
 * 0 for unknown
 * 1 for exit
 * 2 for help
 * 3 for mix
 * 4 for solve
 * 5 for solution
 * 6 for perspective
 * 
 * @param *str the instruction
 * 
 * @return int
*/
int getIns(char *str)
{
  // pointer to the start of the instruction, after the i:
  char *inst;

  // return value and counter
  int rv = 0;
  int i = 2;

  // gets to the first space or end of the string
  while(str[i] != 0 && str[i] != ' ')
  {
    i++;
  }

  // replaces the last value to \0 and gets inst to the start of the instruction
  str[i] = 0;
  inst = &str[2];

  // compares the string with the instructions
  if(!strcmp(inst, "exit"))
  {
    rv = 1;
  }
  else if(!strcmp(inst, "help"))
  {
    rv = 2;
  }
  else if(!strcmp(inst, "mix"))
  {
    rv = 3;
  }
  else if(!strcmp(inst, "solve"))
  {
    rv = 4;
  }
  else if(!strcmp(inst, "solution"))
  {
    rv = 5;
  }
  else if(!strcmp(inst, "perspective"))
  {
    rv = 6;
  }

  // returns the value
  return rv;
}

/**
 * Creates a list of positions of corresponding parenthesis in a set of instructions
 * It also modifies the instruction to give it the best format possible
 * 
 * @param **inst the instruction to take in consideration
 * @param **Start the start of the parenthesis list
*/
void getPairs(char **inst, Parentesis **start)
{
  // LIFO of oppened parenthesis
  Stack *opened;
  Stack *temp;
  Stack *sp;

  // parenthesis items
  Parentesis *pair;
  Parentesis *move;

  // new modified instruction
  char *new_inst;

  // counter
  int i = 0;

  // staerts the stack
  opened = NULL;

  // for every char in the instruction
  for(i = 0; i < strlen(*inst); i++)
  {
    // if char is (
    if((*inst)[i] == '(')
    {
      // adds element to stack
      temp = (Stack *) malloc(sizeof(Stack));
      temp->pos = i;
      temp->next = opened;
      opened = temp;
    }
    // if char is )
    else if((*inst)[i] == ')')
    {
      // creates new pair element with end in current position
      pair = (Parentesis *) malloc(sizeof(Parentesis));
      pair->end = i;
      pair->next = *start;
      *start = pair;

      // if there are elements in stack
      if(opened != NULL)
      {
        // saves oppening position
        pair->start = opened->pos;

        // removes element from stack
        sp = opened;
        sp = sp->next;

        free(opened);

        opened = sp;
      }
      // if stack is empty
      else
      {
        // creates a new string with a length 2 chars longer than the original
        new_inst = (char *) malloc(sizeof(char) * (strlen(*inst) + 2));
        
        // adds a parenthesis to the start of the instruction
        sprintf(new_inst, "(%s", *inst);

        // frees the original string
        free(*inst);

        // sets the new string as the current instruction
        *inst = new_inst;

        // adds 1 to every start and close position in the pairs list
        move = *start;

        while(move != NULL)
        {
          move->end++;
          move->start++;

          move = move->next;
        }

        // sets the start position of the parenthesis
        pair->start = 0;

        // skips the character
        i++;
      }
    }
  }

  // if there are still opening parenthesis
  while(opened != NULL)
  {
    // empties the list and changes the parenthesis to spaces
    temp = opened;
    opened = temp->next;

    (*inst)[temp->pos] = ' ';

    free(temp);
  }

  return;
}

/**
 * Reads an instruction and aplies every movement to the cube
 * this function is recursive
 * 
 * @param *cube the cube to modify
 * @param mainS the main sign over the working part (positive or negative)
 * @param spos the start position of the instruction over the original instruction
 * @param sum the starting position over the original string
 */
void createSet(Rubik_Cube *cube, int mainS, int spos, int sum)
{
  // temp string for the parenthesis
  char *temp;

  int in = 0; // position of the instruction
  int rep = 0; // repetition times
  int sp = 0; // space between oppening and closing parenthesis
  int ownS = 1; // sign of the instruction

  char move[3]; // movement involved

  // counters
  int i = 0;
  int j = 0;

  // for every char in the instruction
  for(i = 0; i < strlen(cube->str); i++)
  {
    // temp starts in the current char
    temp = &cube->str[i];

    // according to the char
    switch(cube->str[i])
    {
      // allowed instructions
      case 'r':
      case 'R':
      case 'l':
      case 'L':
      case 'f':
      case 'F':
      case 'b':
      case 'B':
      case 'u':
      case 'U':
      case 'd':
      case 'D':
      case 'm':
      case 'e':
      case 's':
      case 'x':
      case 'y':
      case 'z':
      {
        // saves the position of the instruction
        in = i;
        // gets the times the instruction is repeated and skips to the next relevant char
        getRep(cube->str, &i, &rep, &ownS, mainS);

        // for every time it needs to be repeated
        for(j = 0; j < rep; j++)
        {
          // inserts the character in move
          sprintf(move, "%c", cube->str[in]);

          // if the resulting sign is negative, it adds a ' to the instruction
          if(ownS < 0)
          {
            strcat(move, "'");
          }

          // adds the char to the move list and executes the move in the cube
          addM(&cube->inst_start, move);
          moveCube(cube->matrix, move);
        }

        break;
      }
      // opening parenthesis
      case '(':
      {
        // gets the space between parenthesis
        sp = getSpace(cube->par_start, i + spos);

        // if there is a space
        if(sp)
        {
          // creates a string for the parenthesis
          temp = (char *) malloc(sizeof(char) * sp);
          
          // gets the current position over the original string
          in = i + sum;

          // copys the original string starting from the current position in temp
          for(j = 0; j < sp; j++, i++)
          {
            temp[j] = cube->str[i + 1];
          }
          temp[j - 1] = 0;

          // gets the reps of the parenthesis
          getRep(cube->str, &i, &rep, &ownS, mainS);

          // inserts the instructions in the parenthesis the amount of times needed
          for(j = 0; j < rep; j++)
          {
            createSet(cube, ownS, in, sum + 1);
          }

          // frees the temp string
          free(temp);
        }

        break;
      }
      // skips this chars (they shouldn't appear because of the way the code operates the string, but just in case)
      case '\'':
      case ' ':
      case ')':
      // unknown chars (i decided to ignore them for simplicity)
      default:
      {
        break;
      }
    }
  }
  
  return;
}

/**
 * Adds the instruction to the array
 *
 * @param **start the beggining of the dynamic array
 * @param move[] an instruction
 */
void addM(Instruction **start, char move[])
{
  // to add and moving pointers
  Instruction *add;
  Instruction *temp;
  Instruction *temp2;

  // prepares the added element
  add = (Instruction *)malloc(sizeof(Instruction));
  strcpy(add->wd, move);
  add->next = NULL;

  // sets temp as NULL
  temp = NULL;

  // if there is an element already
  if (*start != NULL)
  {
    // gets first pointer to start
    temp = *start;

    // moves the pointer to the end of array
    while (temp->next != NULL)
    {
      temp = temp->next;
    }

    // u u will become u2
    if (!strcmp(temp->wd, add->wd) && temp->wd[1] != '2')
    {
      temp->wd[1] = '2';
      temp->wd[2] = '\0';

      free(add);
    }
    else if (strcmp(temp->wd, add->wd) && temp->wd[0] == add->wd[0] && (temp->wd[1] == '2' || add->wd[1] == '2'))
    {
      // u2 u' becomes u
      if (add->wd[1] == '\'' || temp->wd[1] == '\'')
      {
        temp->wd[1] = '\0';
      }
      // u2 u becomes u'
      else
      {
        temp->wd[1] = '\'';
        temp->wd[2] = '\0';
      }

      free(add);
    }
    // u u' or u2 u2 will delete each other
    else if ((temp->wd[0] == add->wd[0] && (temp->wd[1] != add->wd[1])) || !strcmp(temp->wd, add->wd))
    {
      // if temp is not the first element
      if (temp != *start)
      {
        // sets temp2 a element behind temp
        temp2 = *start;

        while (temp2->next != temp)
        {
          temp2 = temp2->next;
        }

        // unlinks temp
        temp2->next = NULL;
      }
      // if temp is the first element of the list
      else
      {
        // unlinks temp
        *start = NULL;
      }

      // frees memory
      free(temp);
      free(add);
    }
    // if new element has no relation with last element
    else
    {
      // adds new element to array
      temp->next = add;
    }
  }
  else
  {
    *start = add;
  }

  return;
}

/**
 * Gets the ammount of times an instruction needs to be executed
 * 
 * @param inst[] the current string
 * @param *i the pointer of the iterator to modify it now
 * @param *rep return value of repetitions
 * @param *sgn return value of sign
 * @param mSgn main sign over the instruction
*/
void getRep(char inst[], int *i, int *rep, int *sgn, int mSgn)
{
  // temporal char
  char *temp;

  // number of repetitions
  int val = 0;

  // default sign is positive as well as repetitions
  *sgn = 1;
  *rep = 1;

  // while there are numbres, spaces, ' or - in the string
  do
  {
    // adds 1 to i
    (*i)++;
    
    // sets temp string to current position over original string
    temp = &inst[*i];
    val = 1;

    // if can read a value
    if(sscanf(temp, "%d", &val) == 1)
    {
      // if value is a negative number
      if(val < 0)
      {
        // sets value as positive
        val *= -1;

        // multiplies by -1 the sign
        (*sgn) *= -1;
      }

      // skips to the next number or char of the string
      do
      {
        (*i)++;
      } while(((inst[*i] >= '0' && inst[*i] <= '9') || inst[*i] == '-') && inst[*i] != 0);

      // removes 1 to the iterator
      (*i)--;
    }
    // if it reads a ' or - it multiplies the sign by -1
    else if(inst[*i] == '\'' || inst[*i] == '-')
    {
      (*sgn) *= -1;
    }

    // multiplies rep by val
    (*rep) *= val;
  } while(((inst[*i] >= '0' && inst[*i] <= '9') || inst[*i] == '\'' || inst[*i] == ' ' || inst[*i] == '-') && inst[*i] != 0);

  // removes 1 to iterator and multiplies sign by main sign
  (*i)--;
  (*sgn) *= mSgn;

  return;
}

/**
 * gets the space between an oppening and clossing parenthesis
 * 
 * @param *start start of the parenthesis list
 * @param pos position of oppening parenthesis
 * 
 * @return int
*/
int getSpace(Parentesis *start, int pos)
{
  // moving pointer
  Parentesis *temp;

  // sets it at start
  temp = start;

  // finds the pair with the opening in the position
  while (temp != NULL && temp->start != pos)
  {
    temp = temp->next;
  }

  // if there is no pair, returns 0
  if (temp == NULL)
  {
    return 0;
  }

  // returns the space between the opening and closing
  return temp->end - temp->start;
}