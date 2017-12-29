

struct node_s
{
	int data;
	node_s*prev;
};
class Stack 
{

	public:
		void push(int value);
	    int  pop();
	    
	private:
		int data;
		int size;
		node_s *top;
};