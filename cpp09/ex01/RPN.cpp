/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:53:03 by craimond          #+#    #+#             */
/*   Updated: 2024/05/11 15:23:01 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack() {}

RPN::RPN(RPN const &other) : _stack(other._stack) {}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return (*this);
}

RPN::~RPN() {}

void RPN::addOperand(const char op)
{
	int n1, n2;

	if (_stack.size() < 2)
		throw stackTooSmallException();
	n2 = _stack.top();
	_stack.pop();
	n1 = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			_stack.push(n1 + n2);
			break;
		case '-':
			_stack.push(n1 - n2);
			break;
		case '/':
			if (n2 == 0)
				throw divisionByZeroException();
			_stack.push(n1 / n2);
			break;
		case '*':
			_stack.push(n1 * n2);
			break;
		default:
			throw invalidOperandException();
			break;
	}
}

void RPN::addNumber(const int n)
{
	_stack.push(n);
}

int	RPN::getResult(void) const
{
	if (_stack.size() > 1)
		throw invalidExpressionException();
	return (_stack.top());
}

const char *RPN::invalidOperandException::what() const throw()
{
	return ("Error: invalid operand");
}

const char *RPN::stackTooSmallException::what() const throw()
{
	return ("Error: stack too small");
}

const char *RPN::divisionByZeroException::what() const throw()
{
	return ("Error: division by zero");
}

const char *RPN::invalidExpressionException::what() const throw()
{
	return ("Error: invalid expression");
}
