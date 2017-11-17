void run(int prog[]);

int main()
{
    int prog[4] = { 0x1108, 0x1206, 0x2312, 0x0000 };
	run(prog);
	return 0;
}

void run(int prog[]) 
{
	int regs[4];
	int in = 0; // instruction num
   for (;;)
	{

		int instr = (prog[in] & 0xF000) >> 12;
		int reg1 = (prog[in] & 0x0F00) >> 8;
		int reg2 = (prog[in] & 0x00F0) >> 4;
		int reg3 = prog[in] & 0x000F;
		int value = prog[in] & 0x00FF;

		if (instr == 0x1) // load
			regs[reg1] = value;
		else if (instr == 0x2) //add
			regs[reg1] = regs[reg2] + regs[reg3];
		else if (instr == 0x0)
			break;

		in++;
	}
}