    #include "Przeszkoda.hh"

    double Przeszkoda::wez_promien_przeszkody()
    {
        double promien = sqrt(pow(this->zapasowe_lokalne[0][0],2)+pow(this->zapasowe_lokalne[0][1],2)+pow(this->zapasowe_lokalne[0][2],2));
        return promien;
    }

    bool Przeszkoda::czy_kolizja(std::shared_ptr<InterfejsDrona> dronpom)
    {
        double odleglosc;
        odleglosc = (this->srodek - dronpom->wez_srodek_drona()).dlugosc();
        if(dronpom->wez_promien() + this->wez_promien_przeszkody() >= odleglosc)
            return true;
        return false;
    }

    void Przeszkoda::stworz_przeszkode()
    {
        this->skrec();
        this->rysuj();
    }