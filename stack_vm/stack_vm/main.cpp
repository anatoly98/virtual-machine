
#include "stack_class.h"



void run(int prog[]);



int main()

{

	int prog[4] = { 0x1003, 0x1020, 0x1100, 0x0000 };

	run(prog);

	return 0;

}



void run(int prog[])

{
	Stack stack;
	int a, b;
	int regs[4];

	int in = 0; // instruction num

	for (;;)

	{



		int instr = (prog[in] & 0xF000) >> 12;

		int reg1 = (prog[in] & 0xF00) >> 8;

        int value = prog[in] & 0xFF;

		

		if (instr == 0x1) // load

		{
			if(reg1==0)
			stack.push(value);
			else if (reg1 == 1)
			{
				a = stack.pop();

				b = stack.pop();

				stack.push(a + b);
			}
			else if (reg1 == 2)
			{
				a = stack.pop();

				b = stack.pop();

				stack.push(a * b);
			}
			
		}
		     

		

		else if (instr == 0x0)

			break;



		in++;

	}

}