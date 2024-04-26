/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <bomboclat@bidol.juis>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:19:06 by craimond          #+#    #+#             */
/*   Updated: 2024/04/26 18:58:19 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
	if (grade < 1)
		GradeTooHighException();
	else if (grade > 150)
		GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy._grade;
	return *this;
}

void Bureaucrat::GradeTooHighException(void) const
{
	throw std::runtime_error("Grade is too high");
}

void Bureaucrat::GradeTooLowException(void) const
{
	throw std::runtime_error("Grade is too low");
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::SignForm(AForm &f) const
{
	if (f.isSigned())
		throw std::runtime_error("Form is already signed");
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::CheckEligibility(const AForm &f) const
{
	if (!f.isSigned())
		f.FormNotSignedException();
	if (getGrade() > f.getMinGrateToExecute())
		f.GradeTooLowException();
}

void Bureaucrat::ExecuteForm(const AForm &f) const
{
	try
	{
		CheckEligibility(f);
		std::cout << getName() << " executed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " cannot execute " << f.getName() << ". Reason: " << e.what() << std::endl;
	}
}

std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}