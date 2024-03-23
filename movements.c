#include "cube.h"

void readIns(char **str)
{
  Character *set;
  Character *temp;
  Character *temp2;

  char *temp_str;

  int i = 0;

  set = NULL;

  do
  {
    temp = (Character *) malloc(sizeof(Character));
    temp->cur = getchar();
    temp->next = NULL;

    if(set == NULL)
    {
      set = temp;
    }
    else
    {
      temp2 = set;

      while(temp2->next != NULL)
      {
        temp2 = temp2->next;
      }

      temp2->next = temp;
    }

    i++;
  } while(temp->cur != '\n');

  temp_str = (char *) malloc(i * sizeof(char));
  i = 0;

  while(set != NULL)
  {
    temp = set;
    set = temp->next;

    temp_str[i] = temp->cur;

    free(temp);

    i++;
  }

  temp_str[i - 1] = 0;
  *str = temp_str;

  return;
}

void getPairs(char **inst, Parentesis **start)
{
  Stack *opened;
  Stack *temp;
  Stack *sp;

  Parentesis *pair;
  Parentesis *move;
  Parentesis *move2;

  char *new_inst;
  int i = 0;

  opened = NULL;

  for (i = 0; i < strlen(*inst); i++)
  {
    if ((*inst)[i] == '(')
    {
      temp = (Stack *)malloc(sizeof(Stack));
      temp->pos = i;
      temp->next = opened;
      opened = temp;
    }
    else if ((*inst)[i] == ')')
    {
      pair = (Parentesis *)malloc(sizeof(Parentesis));
      pair->end = i;
      pair->next = *start;
      *start = pair;

      if (opened != NULL)
      {
        pair->start = opened->pos;

        sp = opened;
        sp = sp->next;

        free(opened);

        opened = sp;
      }
      else
      {
        new_inst = (char *)malloc(sizeof(char) * (strlen(*inst) + 2));
        sprintf(new_inst, "(%s", *inst);
        free(*inst);
        *inst = new_inst;

        move = *start;

        while (move != NULL)
        {
          move->end++;
          move->start++;

          move = move->next;
        }

        pair->start = 0;
        i++;
      }
    }
  }

  while (opened != NULL)
  {
    temp = opened;
    opened = temp->next;

    (*inst)[temp->pos] = ' ';

    free(temp);
  }

  return;
}

void createSet(Rubik_Cube *cube, int mainS, int spos, int sum)
{
  char *temp;

  int in = 0;
  int rep = 0;
  int sp = 0;
  int ownS = 1;

  char move[3];

  int i = 0;
  int j = 0;

  for (i = 0; i < strlen(cube->str); i++)
  {
    temp = &cube->str[i];

    switch (cube->str[i])
    {
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
        in = i;
        getRep(cube->str, &i, &rep, &ownS, mainS);

        for (j = 0; j < rep; j++)
        {
          sprintf(move, "%c", cube->str[in]);

          if (ownS < 0)
          {
            strcat(move, "'");
          }

          addM(&cube->inst_start, move);
          moveCube(cube->matrix, move);
        }

        break;
      }
      case '(':
      {
        sp = getSpace(cube->par_start, i + spos);

        if (sp)
        {
          temp = (char *)malloc(sizeof(char) * sp);
          in = i + sum;

          for (j = 0; j < sp; j++, i++)
          {
            temp[j] = cube->str[i + 1];
          }
          temp[j - 1] = 0;

          getRep(cube->str, &i, &rep, &ownS, mainS);

          for (j = 0; j < rep; j++)
          {
            createSet(cube, ownS, in, sum + 1);
          }

          free(temp);
        }

        break;
      }
      case '\'':
      case ' ':
      case ')':
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

void getRep(char inst[], int *i, int *rep, int *sgn, int mSgn)
{
  char *temp;

  int val = 0;

  *sgn = 1;
  *rep = 1;

  do
  {
    (*i)++;
    temp = &inst[*i];
    val = 1;

    if (sscanf(temp, "%d", &val) == 1)
    {
      if (val < 0)
      {
        val *= -1;
        (*sgn) *= -1;
      }

      do
      {
        (*i)++;
      } while (((inst[*i] >= '0' && inst[*i] <= '9') || inst[*i] == '-') && inst[*i] != 0);

      (*i)--;
    }
    else if (inst[*i] == '\'' || inst[*i] == '-')
    {
      (*sgn) *= -1;
    }

    (*rep) *= val;
  } while (((inst[*i] >= '0' && inst[*i] <= '9') || inst[*i] == '\'' || inst[*i] == ' ' || inst[*i] == '-') && inst[*i] != 0);

  (*i)--;
  (*sgn) *= mSgn;

  return;
}

int getSpace(Parentesis *start, int pos)
{
  Parentesis *temp;

  temp = start;

  while (temp != NULL && temp->start != pos)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    return 0;
  }

  return temp->end - temp->start;
}