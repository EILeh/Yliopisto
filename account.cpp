#include "account.hh"
#include "utils.hh"
#include "course.hh"
#include <algorithm>
#include <iostream>

Account::Account(const std::string& full_name, int account_number,
                 int duplicates, const std::string& university_suffix):
    full_name_(full_name),
    last_name_(""),
    first_name_(""),
    account_number_(account_number)
{
    std::vector<std::string> name = Utils::split(full_name_, ' ');
    last_name_ = name.back();
    first_name_ = name.front();

    // Constructing e-mail address
    email_ = Utils::to_lower(first_name_);
    email_ += ".";
    if ( duplicates > 0 )
    {
        email_ += std::to_string(duplicates);
        email_ += ".";
    }
    email_ += Utils::to_lower(last_name_);
    email_ += "@";
    email_ += university_suffix;
}


Account::~Account()
{
}


void Account::print() const
{
    std::cout << account_number_ << ": "
              << first_name_ << " "
              << last_name_  << ", "
              << email_ << std::endl;
}


std::string Account::get_email() const
{
    return email_;
}


std::string Account::get_full_name() const
{
    return full_name_;
}


int Account::get_account_number() const
{
    return account_number_;
}


void Account::sign_up(Course* new_sign_up)
{
// Tarkistaa onko opiskelija jo ilmoittutunut kurssille ja tulostaa virheilmoi-
// tuksen, jos on, muuten lisää kurssin opiskelijan meneillään oleviin kurs-
// seihin.

    // Käy läpi kurssit, joihin opiskelija on ilmoittautunut.
    for ( auto on_going_course : on_going_courses_ )
    {
        // Jos syötetty kurssi löytyy kursseista, joihin opiskelija on ilmoit-
        // tautunut, tulostetaan virheilmoitus ja palataan kutsufunktioon.
        if ( on_going_course == new_sign_up )
        {
            std::cout << STUDENT_EXISTS << std::endl;
            return;
        }
    }

    // Jos kurssi-ilmoittautumista ei ole vielä tehty, lisätään syötetty kurs-
    // si meneillään oleviin kursseihin.
    on_going_courses_.push_back(new_sign_up);
    std::cout << SIGNED_UP << std::endl;
}


void Account::complete(Course* completed)
{
// Tarkistaa onko opiskelija ilmoittautunut kurssille ja tulostaa virheilmotuk-
// sen, jos ilmoittautumista ei ole. Muuten lisää opiskelijalle suoritusmerkin-
// nän ja poistaa kurssin meneillään olevista kursseista.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Automaattiset tyypit:
    auto it_signup = find(on_going_courses_.begin(),
                          on_going_courses_.end(), completed);


    // Jos syötetty kurssi ei löydy meneillään olevista kursseista, tulostetaan
    // virheilmoitus ja palataan kutsufunktioon.
    if ( it_signup == on_going_courses_.end() )
    {
        std::cout << NO_SIGNUPS << std::endl;
        return;
    }


    // Poistetaan syötetty kurssi meneillään olevista kursseista.
    on_going_courses_.erase(it_signup);

    // Lisätään suoritettuihin kursseihin syötetty kurssi.
    courses_completed_.push_back(completed);

    std::cout << COMPLETED << std::endl;

}


void Account::print_study_state()
{
// Käy läpi opiskelijan meneillään olevat kurssit sekä suoritetut kurssit ja
// laskee opiskelijan suoritettujen kurssien yhteenlasketun opintopistemäärän.
// Tulostaa tiedot meneillään olevista kursseista, suoritetuista kursseista se-
// kä opintopisteiden määrästä.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int total_credits = 0;

    std::cout << "Current: " << std::endl;

    // Käy läpi kaikki opiskelijan meneillään olevat kurssit ja tulostaa jokai-
    // sen meneillään olevan kurssin koodin sekä nimen.
    for ( auto on_going_course : on_going_courses_ )
    {
        std::cout << on_going_course->get_code() << " : " <<
                     on_going_course->get_name() << std::endl;
    }

    std::cout << "Completed: " << std::endl;

    // Käy läpi kaikki opiskelijan suoritet kurssit, lisää aikaisempaan opinto-
    // pistemäärään kyseisen kurssin opintopistemäärän ja tulostaa jokaisen suo-
    // ritetun kurssin koodin ja nimen.
    for ( auto completed_course : courses_completed_ )
    {

        std::cout << completed_course->get_code() << " : " <<
                     completed_course->get_name() << std::endl;

        total_credits += completed_course->get_credits();
    }

    std::cout << "Total credits: " << total_credits << std::endl;
}


void Account::print_completed()
{
// Käy läpi opiskelijan kaikki suoritetut kurssit ja laskee opiskelijan suori-
// tettujen kurssien yhteenlasketun opintopistemäärän. Tulostaa tiedot suorite-
// tuista kursseista sekä opintopisteiden määrästä.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int total_credits = 0;

    // Käy läpi kaikki opiskelijan suoritet kurssit, lisää aikaisempaan opinto-
    // pistemäärään kyseisen kurssin opintopistemäärän ja tulostaa jokaisen suo-
    // ritetun kurssin koodin ja nimen.
    for ( auto completed_course : courses_completed_ )
    {

        std::cout << completed_course->get_code() << " : " <<
                     completed_course->get_name() << std::endl;

        total_credits += completed_course->get_credits();
    }

    std::cout << "Total credits: " << total_credits << std::endl;
}


void Account::graduate()
{
// Muuttaa kaikki meneillään olevat kurssit suoritetuiksi sekä poistaa kaikki
// meneillään olevat kurssit.

    // Käy läpi kaikki opiskelijan meneillään olevat kurssit ja lisää kaikki me-
    // neillään olevat kurssit suoritettuihin kursseihin.
    for ( auto on_going_course : on_going_courses_ )
    {
        courses_completed_.push_back(on_going_course);
    }

    // Tyhjentää vektorin, joka sisältää tiedon meneillään olevista kursseista.
    on_going_courses_.clear();

}
