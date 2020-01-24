#include <stdio.h>

//wow it does one of the 4 basic operations
float operand(float num1, float num2, char optype){
  if (optype == '*') {
    return num1 * num2;
  } else if (optype == '+'){
    return num1 + num2;
  } else if (optype == '-'){
    return num1 - num2;
  } else if (optype == '/'){
    return num1 / num2;
  }
  return 0;
}



//expression represents one solution
//eg [(rand0 tor0 rand1) tor1 rand2] tor2 rand3
struct expression {
  int   rand0;
  char  tor0;
  int   rand1;
  char  tor1;
  int   rand2;
  char  tor2;
  int   rand3;
};

int isequal(struct expression es1, struct expression es2){
  if (es1.rand0 == es2.rand0 && es1.tor0 == es2.tor0 && es1.rand1 == es2.rand1 && es1.tor1 == es2.tor2 && es1.rand2 == es2.rand2 && es1.tor2 == es2.tor2 && es1.rand3 == es2.rand3){
    return 1;
  }
  return 0;
}

int findmatchsol(struct expression* sols, int len, struct expression sol){
  for(int i = 0; i < len; i++){
    if (isequal(sols[i], sol) == 1){
      return 1;
    }
  }
  return 0;
}


void testchal4(int num1, int num2, int num3, int num4, char opt){
  char operations[] = {'*', '+', '-', '/'};
  int nums[] = {num1, num2, num3, num4};
  struct expression sols[20];
  float round1;
  float round2;
  float round3;
  int solcount = 0;
  struct expression newsol;
  int opseq[7]; //Doesn't have very much use since indices are saved, except to organize them
  for (int i = 0; i < 4; i++){//assigning 1st number
    opseq[0] = i;
    for (int d = 0; d < 4; d++){//assigning 2nd number
      if (d == opseq[0]){
        continue;
      }
      opseq[2] = d;
      for (int r = 0; r < 4; r++){//assigning operation 1 + calculating
        if (nums[opseq[2]] == 0 && r == 3){
          continue;
        }
        round1 = operand(nums[opseq[0]], nums[opseq[2]], operations[r]);
        opseq[1] = r;
        for (int e = 0; e < 4; e++){//assigning 3rd number
          if (e == opseq[0]){
            continue;
          }
          if (e == opseq[2]){
            continue;
          }
          opseq[4] = e;
          for (int x = 0; x < 4; x++){//assigning operation 2 + calculating
            if (nums[opseq[4]] == 0 && x == 3){
              continue;
            }
            round2 = operand(round1, nums[opseq[4]], operations[x]);
            opseq[3] = x;
            for (int y = 0; y < 4; y++){//assigning 4th number
              if (y == opseq[0]){
                continue;
              }
              if (y == opseq[2]){
                continue;
              }
              if (y == opseq[4]){
                continue;
              }
              opseq[6] = y;
              for (int z = 0; z < 4; z++){//last calculation & operation level
                if (nums[opseq[6]] == 0 && operations[z] == '/'){
                  continue;
                }
                round3 = operand(round2, nums[opseq[6]], operations[z]);
                opseq[5] = z;
                //checking for 
                if (round3 >= 23.99 && round3 <=24.01){
                  if (solcount == 0){
                    printf("Challenge completed!\n");
                    if (opt == 'y' || opt == 'Y'){
                      printf("The solution(s) were/was:\n");
                    }
                    solcount = 1;
                  }
                  newsol.rand0 = nums[opseq[0]];
                  newsol.tor0 = operations[opseq[1]];
                  newsol.rand1 = nums[opseq[2]];
                  newsol.tor1 = operations[opseq[3]];
                  newsol.rand2 = nums[opseq[4]];
                  newsol.tor2 = operations[opseq[5]];
                  newsol.rand3 =  nums[opseq[6]];
                  if (findmatchsol(sols, solcount, newsol) == 0 && (opt == 'y'|| opt == 'Y')){
                    printf("[(%d %c %d) %c %d] %c %d\n", nums[opseq[0]], operations[opseq[1]], nums[opseq[2]], operations[opseq[3]], nums[opseq[4]], operations[opseq[5]], nums[opseq[6]]);
                    sols[solcount] = newsol;
                    solcount++;
                  }
                  char operations[] = {'*', '+', '-', '/'};
                }
              }
            }
          }
        }
      }
    }
  }
  if (solcount == 0){
    printf("Challenge failed!\n");
  }
}

int main(int argc, char* argv[]) {
  printf("\n");
  if (argc != 6){
    printf("All 5 elements please!\n");
  } else {
    int num1;
    int num2;
    int num3;
    int num4;
    char opt;
    if (sscanf(argv[1], "%d", &num1) != 1){
      printf("You sure those are correct?\n");
    } else if (sscanf(argv[2], "%d", &num2) != 1){
      printf("You sure those are correct?\n");
    } else if (sscanf(argv[3], "%d", &num3) != 1){
      printf("You sure those are correct?\n");
    } else if (sscanf(argv[4], "%d", &num4) != 1){
      printf("You sure those are correct?\n");
    } else if (sscanf(argv[5], "%c", &opt) != 1){
      printf("You sure those are correct?\n");
    } else {
      testchal4(num1, num2, num3, num4, opt);
    }
  }
  return 0;
}  
