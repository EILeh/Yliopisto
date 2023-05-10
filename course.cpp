#include "course.hh"
#include <iostream>
#include <memory>

Course::Course(const std::string& code, const std::string& name, int credits):
    course_code_(code), name_(name), credits_(credits)
{
}


Course::~Course()
{
}


void Course::print_info(bool print_new_line)
{
    std::cout << course_code_ << " : " << name_;
    if ( print_new_line )
    {
        std::cout << std::endl;
    }
}


void Course::print_long_info()
{
    std::cout << "* Course name: " << name_ << std::endl
              << "* Code: " << course_code_ << std::endl;
    print_staff();
}


void Course::print_staff()
{
    std::cout << "* Staff: " << std::endl;
    for (auto member : course_staff_ )
    {
        member->print();
    }
}


void Course::add_staff(Account* new_staff_member)
{
    for ( unsigned int i = 0; i < course_staff_.size(); ++i )
    {
        if ( course_staff_.at(i) == new_staff_member )
        {
            std::cout << STAFF_EXISTS << std::endl;
            return;
        }
    }

    course_staff_.push_back(new_staff_member);
    std::cout << STAFF_ADDED << std::endl;
}


void Course::sign_up(Account* new_student)
{
// Lisää vektoriin tiedon uudesta opiskelijasta.
    course_student_.push_back(new_student);
}


void Course::print_sign_ups()
{
// Tulostaa tiedon kaikista kurssille ilmoittautuneista opiskelijoista.

    // Käy läpi kaikki kurssille ilmoittautuneet opiskelijat ja tulostaa jokai-
    // sen opiskelijanumeron, koko nimen sekä sähköpostin.
    for ( auto signed_up_student : course_student_ )
    {
        std::cout << signed_up_student->get_account_number() << ": " <<
                     signed_up_student->get_full_name() << ", " <<
                     signed_up_student->get_email() << std::endl;
    }
}


const std::string Course::get_name() const
{
    return name_;
}


const std::string Course::get_code() const
{
    return course_code_;
}


int Course::get_credits() const
{
    return credits_;
}

