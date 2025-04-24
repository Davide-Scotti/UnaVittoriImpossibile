// RisorseGlobali.h
#ifndef RISORSE_GLOBALI_H
#define RISORSE_GLOBALI_H

struct RisorseGlobali {
    int fascistiDisponibili = 12;
    int munizioniDisponibili = 6;
    int pozioniDisponibili = 6;
    int civiliDisponibili = 6;
    int avanzamentoFasci = 0; 

    // Metodi per decrementare le risorse
    bool usaFascista() {
        if (fascistiDisponibili > 0) {
            --fascistiDisponibili;
            return true;
        }
        return false;
    }

    bool usaMunizione() {
        if (munizioniDisponibili > 0) {
            --munizioniDisponibili;
            return true;
        }
        return false;
    }

    bool usaPozione() {
        if (pozioniDisponibili > 0) {
            --pozioniDisponibili;
            return true;
        }
        return false;
    }

    bool usaCivile() {
        if (civiliDisponibili > 0) {
            --civiliDisponibili;
            return true;
        }
        return false;
    }
};

#endif // RISORSE_GLOBALI_H
