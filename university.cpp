#include "university.hh"
#include <iostream>
#include <algorithm>
#include <memory>

University::University(const std::string& email_suffix):
    running_number_(111111), email_suffix_(email_suffix)
{
}


University::~University()
{
}


void University::new_course(Params params)
{
// Luo uuden kurssin, jos sitä ei ole jo luotu. Jos kurssin koodilla löytyy jo
// kurssi, tulostetaan virheilmoitus.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Merkkijonot:
    std::string code = params.at(0);
    std::string name = params.at(1);


    // Käy läpi map:n, joka sisältää tiedon kaikista kursseista, joita yliopis-
    // tossa on ja tarkistaa löytyykö kurssi yliopistosta laskemalla kurssikoo-
    // din toistuvuuden. Jos kurssikoodien laskettu määrä on eri kuin nolla, tu-
    // lostetaan virheilmoitus. Muussa tapauksessa ilmoitetaan uuden kurssin
    // lisäämisestä ja lisätään uuden kurssin tiedot map:iin courses_.
    if ( courses_.count(code) != 0 )
    {
        std::cout << ALREADY_EXISTS << std::endl;
        return;
    }
    else
    {
        std::cout << NEW_COURSE << std::endl;
    }
    std::shared_ptr<Course> n_course(new Course(code, name));
    courses_.insert({n_course->get_code(), n_course});

}


void University::print_courses(Params)
{
// Käy läpi map:n courses_, joka sisältää tiedot kaikista yliopiston kursseista
// ja tulostaa kurssien tiedot kurssin koodin perusteella kutsumalla metodia
// print_info Course luokassa.

    for ( auto course : courses_ )
    {
        course.second->print_info(true);
    }

}


void University::print_course(Params params)
{
// Käy läpi map:n courses_, joka sisältää tiedot kaikista yliopiston kursseista,
// etsii syötetyn kurssin ja tulostaa annetun kurssin tiedot kurssin koodin pe-
// rusteella kutsumalla metodia print_long_info Course luokassa. Jos kurssia ei
// löydy, tulostetaan virheilmoitus.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Merkkijonot:
    std::string code = params.at(0);

    // Käy läpi map:n, joka sisältää tiedon kaikista kursseista, joita yliopis-
    // tossa on ja tarkistaa löytyykö kurssi yliopistosta. Jos kurssia ei löydy,
    // tulostetaan virheilmoitus ja palataan takaisin kutsufunktioon.
    if ( courses_.find(code) == courses_.end() )
    {
        std::cout << CANT_FIND << code << std::endl;
        return;
    }

    courses_.at(code)->print_long_info();

}


void University::new_account(Params params)
{
// Luo uuden tilin sekä antaa jokaiselle käyttäjälle oman henkilökohtaisen koo-
// din eli opiskelijanumeron/henkilönumeron. Lisää uuden käyttäjän map:n, joka
// sisältää tiedon kaikista yliopiston opiskelijoista.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account_number = running_number_++;
    int num = 0;

//  Merkkijonot:
    std::string full_name = params.at(0);

    for ( std::map<int, std::shared_ptr<Account>>::iterator iter =
          accounts_.begin();

          iter != accounts_.end();
          ++iter )
    {
        if ( iter->second->get_full_name() == full_name )
        {
            std::string email = iter->second->get_email();
            num = Utils::numeric_part(email);
            if(num == 0)
            {
                ++num;
            }
            ++num;
        }
    }

    std::shared_ptr<Account> n_account(new Account(full_name, account_number,
                                                   num, email_suffix_));
    accounts_.insert({account_number, n_account});
    std::cout << NEW_ACCOUNT << std::endl;
    accounts_.at(account_number)->print();

}


void University::print_accounts(Params)
{
// Käy läpi map:n accounts_, joka sisältää tiedot kaikista yliopiston opiskeli-
// joista ja tulostaa opiskelijoiden tiedot opiskelijanumeron/henkilönumeron pe-
// rusteella kutsumalla metodia print Account luokassa.

    for ( auto account : accounts_ )
    {
        account.second->print();
    }

}


void University::print_account(Params params)
{
// Käy läpi map:n account_, joka sisältää tiedot kaikista yliopiston opiskeli-
// joista, etsii map:sta syötetyn opiskelijan ja tulostaa kaikki kyseisen opis-
// kelijan tiedot. Jos syötetyllä opiskelijanumerolla ei löydy opiskelijaa, tu-
// lostetaan virheilmoitus.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = std::stoi(params.at(0));

    std::map<int, std::shared_ptr<Account>>::iterator iter =
            accounts_.find(account);

    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pala-
    // taan takaisin kutsufunktioon.
    if ( iter == accounts_.end() )
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }
    iter->second->print();

}


void University::add_staff(Params params)
{
// Tarkistaa löytyykö käyttäjän syöttämä kurssi ja henkilö yliopistosta. Jos
// jompaa kumpaa tai kumpaakaan, henkilöä tai kurssia, ei löydy, tulostetaan
// virheilmoitus. Muussa tapauksessa ohjelma kutsuu add_staff metodia Course
// luokassa.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = std::stoi(params.at(1));

//  Merkkijonot:
    std::string code = params.at(0);

    // Käy läpi map:n, joka sisältää tiedon kaikista kursseista, joita yliopis-
    // tossa on ja tarkistaa löytyykö kurssi yliopistosta. Jos kurssia ei löydy,
    // tulostetaan virheilmoitus ja palataan takaisin kutsufunktioon.
    if ( courses_.find(code) == courses_.end() )
    {
        std::cout << CANT_FIND << code << std::endl;
        return;
    }

    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pala-
    // taan takaisin kutsufunktioon.
    if ( accounts_.find(account) == accounts_.end() )
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }
    courses_.at(code)->add_staff((accounts_.at(account)).get());

}


void University::sign_up(Params params)
{
// Tarkistaa löytyykö käyttäjän syöttämä kurssi ja opiskelija yliopistosta, onko
// opiskelija jo valmistunut tai onko opiskelija jo suorittanut kyseisen kurs-
// sin. Jos jompaa kumpaa tai kumpaakaan, opiskelijaa tai kurssia, ei löydy,
// opiskelija on jo valmistunut tai käynyt kurssin, tulostetaan virheilmoitus ja
// palataan kutsufunktioon. Muussa tapauksessa ohjelma kutsuu sign_up metodia
// Account luokassa.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = 0;
    int count = 0;

//  Merkkijonot:
    std::string code = params.at(0);
    std::string str_account = params.at(1);

    // Käy läpi map:n, joka sisältää tiedon kaikista kursseista, joita yliopis-
    // tossa on ja tarkistaa löytyykö kurssi yliopistosta. Jos kurssia ei löydy,
    // tulostetaan virheilmoitus ja palataan takaisin kutsufunktioon.
    if ( courses_.find(code) == courses_.end() )
    {
        std::cout << CANT_FIND << code << std::endl;
        return;
    }

    account = std::stoi(params.at(1));

    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pa-
    // lataan takaisin kutsufunktioon.
    if ( accounts_.find(account) == accounts_.end() )
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }

    // Käy läpi vektorin, joka sisältää tiedon kaikista yliopistosta valmistu-
    // neista ja kasvattaa muuttujan count arvoa sitä mukaan, jos kyseisellä
    // opiskelijanumerolla löytyy opiskelija ja palataan takaisin kutsufunk-
    // tioon.
    count = std::count(graduated_.begin(), graduated_.end(), account);

    // Jos muuttujan count arvo on suurempi kuin nolla, on kyseinen opiskelija
    // valmistunut eikä voi ilmoittautua enää kursseille. Tulostetaan virheil-
    // moitus ja palataan takaisin kutsufunktioon.
    if ( count > 0 )
    {
        std::cout << ALREADY_GRADUATED << std::endl;
        return;
    }
    auto it = completed_.find(code);
    if ( it != completed_.end() )
    {
        std::cout << STUDENT_COMPLETED << std::endl;
        return;
    }

    // Kutsuu sign_up metodia Account luokassa.
    accounts_.at(account)->sign_up(courses_.at(code).get());

    // Luo uuden Course -olion, jonka tyyppi on shared_ptr ja vapauttaa muisti-
    // alueen, kun siihen ei osoita enää osoittimia.
    std::shared_ptr<Course> n_course(new Course(code, str_account));

    // Lisää uuden kurssin map:iin, joka sisältää tiedon opiskelijan meneillään
    // olevista kursseista.
    on_going_.insert({n_course->get_code(), n_course});

    // Kutsuu sign_up metodia Course luokassa.
    courses_.at(code)->sign_up(accounts_.at(account).get());

}


void University::complete(Params params)
{
// Tarkistaa löytyykö käyttäjän syöttämä kurssi ja opiskelija yliopistosta, onko
// opiskelija jo valmistunut tai onko opiskelija jo suorittanut kyseisen kurs-
// sin. Jos jompaa kumpaa tai kumpaakaan, opiskelijaa tai kurssia, ei löydy,
// opiskelija on jo valmistunut tai käynyt kurssin, tulostetaan virheilmoitus ja
// palataan kutsufunktioon. Muussa tapauksessa ohjelma kutsuu complete metodia.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = std::stoi(params.at(1));

//  Merkkijonot:
    std::string code = params.at(0);
    std::string str_account = params.at(1);

    // Käy läpi map:n, joka sisältää tiedon kaikista kursseista, joita yliopis-
    // tossa on ja tarkistaa löytyykö kurssi yliopistosta. Jos kurssia ei löydy,
    // tulostetaan virheilmoitus ja palataan takaisin kutsufunktioon.
    if ( courses_.find(code) == courses_.end() )
    {
        std::cout << CANT_FIND << code << std::endl;
        return;
    }

    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pala-
    // taan takaisin kutsufunktioon.
    if ( accounts_.find(account) == accounts_.end() )
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }
    auto it = on_going_.find(code);
    std::shared_ptr<Course>& n_course = it->second;

    // Kutsuu complete metodia Account luokassa.
    accounts_.at(account)->complete(courses_.at(code).get());

    // Jos syötetty kurssi löytyy opiskelijan meneillään olevista kursseista,
    // on opiskelija ilmoittautunut kyseisellä kurssille ja se voidaan merkitä
    // suoritetuksi.
    if ( it != on_going_.end() )
    {
        // Lisää uuden kurssin map:iin, joka sisältää tiedon opiskelijan suori-
        // tetuista kursseista, poistaa saman kurssin meneillään olevista
        // kursseista ja palaa takaisin kutsufunktioon.
        completed_.insert({n_course->get_code(), n_course});
        on_going_.erase(it);
        return;
    }

}


void University::print_signups(Params params)
{
// Tarkistaa löytyykö kurssi yliopistosta, jos ei niin tulostetaan virheilmoi-
// tus. Muuten kutsuu metodia print_sign_ups Course luokassa.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Merkkijonot:
    std::string code = params.at(0);

    auto it = courses_.find(code);

    // Käy läpi map:n, joka sisältää tiedon kaikista kursseista, joita yliopis-
    // tossa on ja tarkistaa löytyykö kurssi yliopistosta. Jos kurssia ei löydy,
    // tulostetaan virheilmoitus ja palataan takaisin kutsufunktioon.
    if ( it == courses_.end() )
    {
        std::cout << CANT_FIND << code << std::endl;
        return;
    }
    std::shared_ptr<Course>& course_ptr = it->second;
    course_ptr->print_sign_ups();

}


void University::print_completed(Params params)
{
// Tarkistaa löytyykö kurssi yliopistosta, jos ei niin tulostetaan virheilmoi-
// tus. Muuten kutsuu metodia print_completed Account luokassa.


// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = std::stoi(params.at(0));

    auto iter = accounts_.find(account);

    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pala-
    // taan takaisin kutsufunktioon.
    if (iter == accounts_.end())
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }
    std::shared_ptr<Account>& account_ptr = iter->second;
    account_ptr->print_completed();

}


void University::print_study_state(Params params)
{
// Tarkistaa löytyykö opiskelijanumerolta opiskelija, jos ei niin tulostetaan
// virheilmoitus. Muuten kutsuu metodia print_study_state Account luokassa.
// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = std::stoi(params.at(0));

    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pala-
    // taan takaisin kutsufunktioon.
    auto iter = accounts_.find(account);
    if ( iter == accounts_.end() )
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }
    iter->second->print_study_state();
}


void University::graduate(Params params)
{
// Tarkistaa löytyykö opiskelijanumerolta opiskelija, jos ei niin tulostetaan
// virheilmoitus. Lisää opiskelijan vektoriin, joka pitää sisällää tiedon kai-
// kista valmistuneista opiskelijoista. Käy läpi opiskelijan meneillään olevat
// kurssit ja, jos opiskelijalta puuttuu suoritusmerkintä meneillään olevasta
// kurssista, kutsuu metodia graduate Account luokassa sekä lisää map:iin
// completed_, joka sisältää tiedon suoritetuista kursseista, uuden kurssin,
// jota ei ole vielä suoritettu sekä poistaa map:sta uncompleted_, joka sisältää
// tiedon meneillään olevista kursseista, kyseisen kurssin.

// MUUTTUJIEN ALUSTUKSET TIETOTYYPEITTÄIN AAKKOSJÄRJESTYKSESSÄ:

//  Kokonaisluvut:
    int account = std::stoi(params.at(0));

//  Merkkijonot:
    std::string code = "";
    std::string str_account = params.at(0);


    auto iter = accounts_.find(account);
    // Käy läpi map:n, joka sisältää tiedon kaikista opiskelijoista joita ylio-
    // pistossa on ja tarkistaa löytyykö opiskelijan opiskelijanumero yliopis-
    // tosta. Jos opiskelijanumeroa ei löydy, tulostetaan virheilmoitus ja pala-
    // taan takaisin kutsufunktioon.
    if ( iter == accounts_.end() )
    {
        std::cout << CANT_FIND << account << std::endl;
        return;
    }

    // Lisää tiedon valmistuneesta opiskelijasta vektoriin graduated_, joka si-
    // sältää tiedon yliopistosta valmistuneista opiskelijoista.
    graduated_.push_back(account);

    std::cout << GRADUATED << std::endl;

    for ( auto& courses : on_going_ )
    {
       std::string code = courses.first;
       auto it = on_going_.find(code);
       if ( it != on_going_.end() )
       {
           // Luo uuden Course -olion, jonka tyyppi on shared_ptr ja vapauttaa
           // muistialueen, kun siihen ei osoita enää osoittimia.
            std::shared_ptr<Course> n_course(new Course(code, str_account));

            iter->second->graduate();

            completed_.insert({n_course->get_code(), n_course});
            on_going_.erase(it);

            return;
        }
    }
}

