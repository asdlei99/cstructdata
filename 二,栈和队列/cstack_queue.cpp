/***********************************************************************************************
	created: 		2019-11-14
	
	author:			chensong
					
	purpose:		二,栈和队列
************************************************************************************************/
#ifndef _C_STATICK_QUEUE_H_
#define _C_STATICK_QUEUE_H_

namespace chen {
	//运算符总数 
	static const int 	N_OPTR = 9;
	//运算符集合
	enum Operator
	{
		//加
		ADD,
		//减
		SUB,
		//乘法
		MUL,
		//阶乘
		DIV,
		//左括号
		POW,
		//右括号
		FAC,
		//起始符
		L_P,
		R_P,
		EOE
	} Operator;
	//运算符优先级等级 [栈顶][当前]
	static const char pri[N_OPTR][N_OPTR] = {
		//          |----------------当前运算符-----------------|
		//           +    -    *    /    ^    !    (    )    \0
		/* -- +  */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
		/*  | -  */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
		/* 栈 *  */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
		/* 顶 /  */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
		/* 运 ^  */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
		/* 算 !  */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
		/* 符 (  */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
		/* |  )  */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
		/* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '=',
	};
	
	float evaluate(char *S, char *& RPN)
	{
		Stack<float> opnd; // 运算数栈
		Stack<char> optr; //运算符栈
		optr.push('\0');//尾哨兵'\0'也作为哨兵首先入栈
		// 在运算符栈非空之前, 逐个处理表达式中字符
		while (!optr.empty())
		{
			// 若当前字符为操作数,则
			if (isdigit(*S))
			{
				//读取操作数, 并将其接至RPN末尾
				readNumber(S, opnd);
				append(RPN, opnd.top());
			}
			else  //若当前字符为运算符,则
			{
				//
				switch(orderBetween(optr.top(), *S))
				{
					case '<':
						optr.push(*S);
						++S;
						break;
					case '=':
						optr.pop();
						++S;
						break;
					case '>':
					{
						char op = optr.pop();
						append(RPN, op);
						if ('!' == op)
						{
							float pOpnd = opnd.pop();
							opnd.push(calcu(op, pOpnd));
						}
						else 
						{
							float pOpnd2 = opnd.pop();
							float pOpnd1 = opnd.pop();
							opnd.push(calcu(pOpnd1, op, pOpnd2));
						}
						break;
					}
				}
				default:
					exit(-1); //遇到语法错误 不做处理直接退出
			}
		}
		return opnd.pop();
	}
	
} // !namespace chen 
#endif // !#define _C_STATICK_QUEUE_H_
	