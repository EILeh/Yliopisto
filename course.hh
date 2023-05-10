/* Luokka: Course
 * -------------
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * -------------
 *
 * Luokka esittää yksittäistä kurssia, jolla on nimi, koodi, henkilökunta sekä
 * opiskelijoita. Ohjelmaa ajaessa käyttäjän syöttämien komentojen pohjalta
 * voidaan ottaa talteen kaikki kurssille ilmoittautuneet opiskelijat sekä tu-
 * lostaa kurssin ilmoittautumistilanne. Luokan avulla kurssille myös lisätään
 * henkilökuntaa.
 *
 * Writer of the program: EILeh
 *
 * */

#ifndef COURSE_HH
#define COURSE_HH

#include "account.hh"
#include <memory>
#include <string>
#include <vector>

const std::string STAFF_ADDED =
        "A new staff member has been added.";
const std::string STAFF_EXISTS =
        "Error: Staff member already added on this course.";
const std::string STUDENT_EXISTS =
        "Error: Student already added on this course.";
const std::string STUDENT_COMPLETED =
        "Error: Student already completed this course.";


class Course
{
public:
    /**
     * @brief Course
     * @param code unique code for the course, used as id
     * @param name
     * @param credits
     */
    Course( const std::string& code, const std::string& name, int credits = 5);

    /**
     * @brief Course destructor
     */
    ~Course();

    /**
     * @brief print_info
     * @param print_new_line
     * Print short course info, if print_new_line, pring also a newline
     * at the end.
     */
    void print_info(bool print_new_line);

    /**
     * @brief print_long_info
     * Print longer course info with staff.
     */
    void print_long_info();

    /**
     * @brief print_staff
     * Print all staff of the course.
     */
    void print_staff();

    /**
     * @brief add staff
     * @param new_staff_member
     * Add a staff member to course.
     */
    void add_staff(Account* new_staff_member);

    /**
     * @brief Tulostaa kaikki kurssille ilmoittautuneet opiskelijat.
     * @return palaa takaisin kutsufunktioon
     */
    void print_sign_ups();

    /**
     * @brief Lisää opiskelijan kurssille ilmoittautuneisiin.
     * @param new_student
     * Lisää vektoriin course_student uuden opiskelijan, kun opiskelija ilmoit-
     * tautuu kurssille.
     */
    void sign_up(Account* new_student);

    /**
     * @brief get_code
     * @return the course code.
     */
    const std::string get_code() const;

    /**
     * @brief get_name
     * @return the course name.
     */
    const std::string get_name() const;
    /**
     * @brief get_credits
     * @return the amount of credits this course is valued.
     */
    int get_credits() const;

private:
    std::string course_code_;
    std::string name_;
    int credits_;
    std::vector<Account*> course_staff_;

    // Vektori, joka sisältää tiedon kaikista opiskelijoista, jotka ovat ilmoit-
    // tautuneet kyseiselle kurssille.
    std::vector<Account*> course_student_;

};

#endif // COURSE_HH


