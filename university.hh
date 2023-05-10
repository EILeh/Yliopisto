/* Luokka: University
 * -----------------
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * -----------------
 *
 * Luokka esittää yksinkertaista yliopistoa, jossa on opiskelijoita, henkilökun-
 * ta ja kursseja. Ohjelmaa ajaessa käyttäjä syöttämien komentojen pohjalta kut-
 * sutaan metodeja Account luokassa ja Course luokassa. Käyttäjä voi lisätä
 * opiskelijoita ja kursseja sekä kursseille henkilökuntaa ja ilmoittaa opiske-
 * lijoita kursseille. Ohjelma voi tulostaa yksittäisen kurssin tiedot tai
 * tietoja useammasta kurssista sekä yksittäisen opiskelijan tai useamman opis-
 * kelijan tietoja sekä merkitä opiskelijan valmistuneeksi.
 *
 * Writer of the program: EILeh
 *
 * */
#ifndef UNIVERSITY_HH
#define UNIVERSITY_HH

#include "account.hh"
#include "course.hh"
#include "utils.hh"
#include <map>
#include <memory>
#include <string>

const std::string ALREADY_EXISTS =
        "Error: Already exists.";
const std::string ALREADY_GRADUATED =
        "Error: Student already graduated.";
const std::string CANT_FIND =
        "Error: Can't find anything that matches the given string: ";
const std::string NEW_ACCOUNT =
        "A new account has been created.";
const std::string NEW_COURSE =
        "A new course has been created.";


using Params = const std::vector<std::string>&;

// <course_code, shared_ptr<Course>>
using Courses = std::map<std::string, std::shared_ptr<Course>>;

// <account_number, shared_ptr<Account>>
using Accounts = std::map<int, std::shared_ptr<Account>>;

class University
{
public:

    University(const std::string& email_suffix);

    ~University();

    void new_course(Params params);

    /**
     * @brief print_courses
     * Prints short info of all courses in the system.
     */
    void print_courses(Params);

    /**
     * @brief print_course
     * @param params: course code
     * Prints longer info of given course.
     * If no course with given code is found, gives an error.
     */
    void print_course(Params params);

    /**
     * @brief new_account
     * @param params: full name
     * Adds a new account to the system.
     * If there's an account in the system with the same full name,
     * a different e-mail address is generated.
     */
    void new_account(Params params);

    /**
     * @brief print_accounts
     * Print all accounts found in the system.
     */
    void print_accounts(Params);

    /**
     * @brief print_account
     * @param params: account number
     * Print single account's info
     * If account is not found from the system, gives an error.
     */
    void print_account(Params params);

    /**
     * @brief add_staff
     * @param params: course code, account number
     * Add staff to the course.
     * If course or account is not found, gives an error.
     */
    void add_staff(Params params);

    /**
     * @brief sign_up
     * @param params: kurssikoodi, opiskelijanumero
     * signs up to the course.
     * If course or account is not found, gives an error.
     */
    void sign_up(Params params);

    /**
     * @brief complete_course
     * @param params: course code, account number
     * Complete the course student has previously signed up on.
     * If any of the parameters is not found, gives an error.
     */
    void complete(Params params);

    /**
     * @brief print_signups
     * @param params: course code
     * Print current signups on a course.
     * If course is not found, gives an error.
     */
    void print_signups(Params params);

    /**
     * @brief print_completed
     * @param params: account number
     * Prints completed courses and total credits of the student.
     * If no account is found, gives an error.
     */
    void print_completed(Params params);

    /**
     * @brief print_study_state
     * @param params: account number
     * Print student's all signups, completed courses and total credits.
     * If no account is found, gives an error.
     */
    void print_study_state(Params params);

    /**
     * @brief graduate
     * @param params: account number
     * Completes all courses account has signed up.
     * After graduation account cannot sign up for any course.
     * If no account is found, gives an error.
     */
    void graduate(Params params);

private:
    // all courses:  map<course_code, shared_ptr<Course>>
    Courses courses_;

    // all accounts: map<account_number, shared_ptr<Account>>
    Accounts accounts_;

    // Sisältää tiedon kaikista kursseista, jotka opiskelija on suorittanut
    Courses completed_;

    // Sisältää tiedon kursseista, joihin opiskelia on ilmoittautunut, mutta ei
    // ole vielä suorittanut
    Courses on_going_;

    // Vektori, joka sisältää tiedon kaikista yliopistosta valmistuneista opis-
    // kelijoista
    std::vector<int> graduated_;

    int running_number_;

    std::string email_suffix_;
};

#endif // UNIVERSITY_HH


