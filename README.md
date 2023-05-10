Yliopisto

Ohjelma toteuttaa yliopiston, johon käyttäjä voi suorittaa komentoja joita
ohjelma lukee. Komennosta riippuen ohjelma voi tallentaa tietoja tai tehdä
hakuja tietorakenteeseen. Ohjelmassa on 15 komentoa, joita käyttäjä voi
suorittaa joko syöttämällä isoja tai pieniä kirjaimia tai sekaisin. Jos
käyttäjä syöttää komennon, mutta ei anna kyseiseen komentoon vaadittua määrää
parametreja, tulostetaan virheilmoitus. Myös, jos käyttäjä haluaa hakea 
tietoa ja syöttää oikean komennon, mutta haettavaa ei löydy, tulostuu 
virheilmoitus. Ohjelman ajon voi pysäyttää syöttämällä Q tai QUIT kirjoitettuna
isoilla tai pienillä kirjaimilla tai sekaisin.

Komennot:
NEW_ACCOUNT <koko nimi>: Käyttäjä voi lisätä opiskelijoita tai henkilökuntaa
yliopistoon. Ohjelma luo lisätylle henkilölle henkilönumeron, opiskelijan
kohdalla henkilönumeroa kutsutaan opiskelijanumeroksi. Henkilönumeron luominen 
alkaa 111111, josta seuraavalle luodaan 111112 jne. Koko nimen sisältäessä 
vain etunimen, oletetaan nimen olevan sekä etu- että sukunimi.

PRINT_ACCOUNT <henkilönumero>: Tulostaa henkilön tiedot, jonka henkilönumero
on syötetty.

PRINT_ACCOUNTS: Tulostaa kaikkien henkilöiden tiedot henkilönumeron mukaisessa 
järjestyksessä.

NEW_COURSE <koodi> <nimi>: Luo uuden kurssin, jossa on oletusarvona, että
kurssista saa viisi opintopistettä (5 op). Kahta kurssia ei ole mahdollista
luoda samalla koodilla, vaan tällaisessa tapauksessa tulostetaan virheilmoitus.

ADD_STAFF <koodi> <henkilönumero>: Lisää annetulla kurssille annetun 
opettajan. Jos opettaja kuuluu jo kurssihenkilökuntaan ja hän yritetään lisätä
siihen uudestaan, tulostuu virheilmoitus.

PRINT_COURSE <koodi>: Tulostuu syötetyn kurssin tiedot eli kurssin nimen, sen
koodin sekä opettajat. Opettajat tulostetaan niiden lisäysjärjestyksessä.

PRINT_COURSES: Tulostaa yliopiston kaikki kurssit kurssikoodin mukaisessa
aakkosjärjestyksessä.

HELP: Tulostaa kaikki käytössä olevat komennot lyhenteineen. Tarvittaessa
käyttäjä voi syöttää HELP -komennon perään parametriksi jonkin komennoista
tai niiden alkukirjaimet, jolloin tulostuu, mitä kyseinen komento tekee sekä
mitä parametreja se vaatii.

READ_FROM <tiedosto>: Ohjelma lukee annetusta tiedostosta kaikki tiedot 
virheellisiä komentoja lukuunottamatta, jolloin käyttäjän tarvitse yksitellen
syöttää komentoja. Jos tiedosto on tuntematon, tulostetaan virheilmoitus.

SIGN_UP <koodi> <opiskelijanumero>: Syötetty opiskelija voi ilmoittautua 
syötetylle kurssille. Jos opiskelija on jo ilmoittautunut kyseiselle kurssille,
suorittanut sen tai jo valmistunut, tulostetaan virheilmoitus.

COMPLETE <koodi> <opiskelijanumero>: Annetulle opiskelijalle annetaan 
suoritusmerkintä syötetystä kurssista. Jos suoritusmerkintä yritetään antaa 
uudestaan samalle opiskelijalle samasta kurssista tai opiskelija ei ole lainkaan
ilmoittautunut kurssille, tulostetaan virheilmoitus.

PRINT_STUDY_STATE <opiskelijanumero>: Tulostaa syötetyn opiskelijan 
opiskelutilanteen eli ilmoittautumiset kurssille, suoritetut kurssit sekä 
suoritetuilta kursseilta saatu yhteenlaskettu määrä opintopisteitä. Meneillään 
olevat kurssit tulostuu ilmoittautumisjärjestyksessä ja suoritetut kurssit 
suoritusjärjestyksessä.

PRINT_COMPLETED <opiskelijanumero>: Tulostaa syötetyn opiskelijan 
kurssisuoritukset sekä kokonaisopintopistemäärän. Kurssit tulostetaan 
suoritusjärjestyksessä.

PRINT_SIGNUPS <koodi>: Tulostaa kaikki opiskelijat, jotka ovat ilmoittautuneet 
syötetylle kurssille. Ilmoittautuneissa näkyvät kaikki ilmoittautuneet,
myös ne joilla on jo suoritusmerkintä.

GRADUATE <opiskelijanumero>: Komennolla syötetty opiskelija valmistuu 
yliopistosta, jolloin kaikki kurssit, joihin hän on ilmoittautunut, mutta joista
hän ei ole vielä saanut suoritusmerkintää, merkitään suorituteiksi.

QUIT: Ohjelman suoritus päättyy.
