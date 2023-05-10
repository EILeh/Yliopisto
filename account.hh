/* Luokka: Account
 * --------------
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * -------------
 * Luokka, joka esittää opiskelijaa tai henkilökuntaa yliopistossa. Ohjelmaa
 * ajaessa käyttäjän syöttämien komentojen pohjalta muokataan opiskelijan tai
 * henkilökunnan opintojen tilannetta yliopistossa. Käyttäjä voi lisätätä uusia
 * kurssi-ilmoittautumisia tai suoritettuja kursseja opiskelijan/henkilökunnan
 * tietoihin. Tietoja voi myös tulostaa sekä opiskelijan/henkilökunnan voi lisä-
 * tä valmistuneeksi yliopistosta.
 *
 * Writer of the program: EILeh
 *
 * */
#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <map>
#include <memory>
#include <string>
#include <vector>

class Course;

const std::string NO_SIGNUPS = "No signups found on this course.";
const std::string SIGNED_UP = "Signed up on the course.";
const std::string COMPLETED = "Course completed.";
const std::string GRADUATED = "Graduated, all courses completed.";

class Account
{
public:
    /**
     * @brief Account constructor
     * @param full_name as "firstname lastname"
     * @param account_number
     * @param duplicates tells the number of full namesakes
     * @param university_suffix is the e-mail suffix e.g. "tuni.fi"
     */
    Account(const std::string& full_name, int account_number, int duplicates,
            const std::string& university_suffix);

    /**
     * @brief Account destructor
     */
    ~Account();

    /**
     * @brief print account info on one line
     */
    void print() const;

    /**
     * @brief get_email
     * @return email linked to this account
     */
    std::string get_email() const;

    /**
     * @brief get_full_name
     * @return full name of this account
     */
    std::string get_full_name() const;

    /**
     * @brief get_account_number
     * @return account number linked to this account
     */
    int get_account_number() const;

    /**
     * @brief Lisää kurssin opiskelijan meneillään oleviin kursseihin
     * @param new_sign_up
     * Lisää vektoriin on_going_courses_ uuden kurssin, johon opiskelija on
     * ilmoittautunut.
     * @return palaa takaisin kutsufunktioon
     */
    void sign_up(Course* new_sign_up);

    /**
     * @brief Lisää kurssin opiskelijan suoritettuihin kursseihin
     * @param completed
     * Lisää vektoriin courses_completed uuden kurssin, jonka opiskelija on suo-
     * rittanut. Poistaa vektorista on_going_courses_ saman kurssin, jolloin
     * kurssi ei kuulu enää opiskelijan meneillään oleviin kursseihin.
     * @return palaa takaisin kutsufunktioon
     */
    void complete(Course* completed);

    /**
     * @brief Tulostaa opiskelijan opintojen tilanteen (meneillään olevat kurs-
     * sit, suoritetut kurssit sekä opintopisteet).
     * @return palaa takaisin kutsufunktioon
     */
    void print_study_state();

    /**
     * @brief Tulostaa opiskelijan suoritettujen kurssien tiedot sekä hänen
     * opintopisteiden yhteenlasketun määrän suoritetuista kursseista.
     * @return palaa takaisin kutsufunktioon
     */
    void print_completed();

    /**
     * @brief Tulostaa kaikki kyseiselle kussille ilmoittautuneiden opiskelijoi-
     * den tiedot.
     * @return palaa takaisin kutsufunktioon
     */
    void print_sign_ups();

    /**
     * @brief Siirtää opiskelijan kaikki meneillään olevat kurssit vektorista
     * on_going_courses_ vektoriin courses_completed opiskelijan valmistau-
     * essaan.
     * @return palaa takaisin kutsufunktioon
     */
    void graduate();


private:
    std::string full_name_;
    std::string last_name_;
    std::string first_name_;
    std::string email_;
    const int account_number_;

    // Sisältää tiedon opiskelijan suoritetuista kursseista
    std::vector<Course*> courses_completed_;

    // Sisältää tiedon kursseista, joihin opiskelija on ilmoittautunut, mutta ei
    // ole vielä suorittanut
    std::vector<Course*> on_going_courses_;

};

#endif // ACCOUNT_HH


